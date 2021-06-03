#include "../../include/structure.h"
#include "../../include/rendering.h"
#include "../../include/parsing.h"

t_ray	set_ray(t_camera cam, double u, double v)
{
	t_ray	ray;

	ray.orig = cam.orig;
	ray.dir = vunit(vminus(vplus(vplus(cam.left_bottom, vmult(cam.horizontal, u)), vmult(cam.vertical, v)), cam.orig));		

	//ray orig만 좀 옮기기.. uv 기준으로 어떻게 저떻게..
	
	//ray.dir = vplus(vmult(cam.horizontal, u), vmult(cam.vertical, v));
	//ray.dir = vplus(ray.dir, cam.left_bottom);
	//ray.dir = vnorm(vminus(ray.dir, ray.orig));

	return (ray);
}


int	is_object(t_rt_info data)
{
	if (ft_strcmp(data.id, "pl") == 0 || ft_strcmp(data.id, "sp") == 0 || ft_strcmp(data.id,"cy") == 0)
		return (1);
	else
		return (0);
}

double	intersect_pl(t_rt_info data, t_ray ray)
{
	t_plane pl;
	pl = plane(data.coor1, data.normal_vector);

	double d = vlength(vminus(ray.orig, pl.center));
	double t = (vdot(pl.normal_vector, ray.orig) + d)/ vdot(pl.normal_vector, ray.dir);

	return (t);
}


double	intersect_sp(t_rt_info data, t_ray ray)
{
	t_sphere sp;
	t_vec oc;

	sp = sphere(data.coor1, data.diameter);
	
	oc = vminus(ray.orig, sp.center);
	double a = vlength2(ray.dir);
	double b = vdot(oc, ray.dir);
	double c = vlength2(oc) - sp.radius2;
	double d = b * b - a * c;

	if (d < 0)
		return (-1);
	else
		return (-b - sqrt(d) / a);
}

double intersect_cy(t_rt_info data, t_ray ray)
{
	t_cylinder cy = cylinder(data.coor1, data.normal_vector, data.diameter, data.side_size);

	double a = (ray.dir.x * ray.dir.x) + (ray.dir.z * ray.dir.z);
	double b = 2 * (ray.dir.x * (ray.orig.x - cy.center.x) + ray.dir.z * (ray.orig.z - cy.center.z));
	double c = (ray.orig.x - cy.center.x) * (ray.orig.x - cy.center.x) + (ray.orig.z - cy.center.z) * (ray.orig.z - cy.center.z) - ((cy.diameter/2) * (cy.diameter/2));

	double delta = b * b - 4 * (a * c);
	if (fabs(delta) < 0.001)
		return (-1.0);
	if (delta < 0.0)
		return (-1.0);
	double t1 = (-b - sqrt(delta)) / (2 * a);
	double t2 = (-b + sqrt(delta)) / (2 * a);
	double t;
	if (t1 > t2)
		t = t2;
	else
		t = t1;
	
	t_point inter = vplus(ray.orig, vmult(ray.dir, t));
	double ca = vlength(vminus(cy.center, inter));
	double ct = sqrt(((cy.diameter/2) * (cy.diameter/2)) + (cy.height/2) * (cy.height/2));
		
	if (t > 0 && ca < ct)
		return (t);
	else
		return (-1);

}



double	find_intersect_len(t_rt_info data, t_ray ray)
{
	double rst = INFINITY;

	if (ft_strcmp(data.id, "pl") == 0)
		rst = intersect_pl(data, ray);
	else if (ft_strcmp(data.id, "sp") == 0)
		rst = intersect_sp(data, ray);
	else if (ft_strcmp(data.id, "cy") == 0)
		rst = intersect_cy(data, ray);
	return (rst);
}

t_node *set_object(t_ray ray, t_list *list)
{
	t_node *rtn = 0;
	double min_inter = INFINITY;
	double len_inter = INFINITY;

	list->cur = list->head;
	while (list->cur != 0)
	{
		if (is_object(list->cur->data) == 1)
		{
			len_inter =	find_intersect_len(list->cur->data, ray);
			if(len_inter > 0 && len_inter < min_inter)
			{
				rtn = list->cur;
				min_inter = len_inter;
			}
		}
		list->cur = list->cur->next;
	}
	return (rtn);
}
