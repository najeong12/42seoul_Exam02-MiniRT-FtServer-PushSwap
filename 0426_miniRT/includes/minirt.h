/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 19:20:32 by najlee            #+#    #+#             */
/*   Updated: 2021/04/09 20:04:31 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "key_codes.h"
# include "structures.h"

# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
// # include <pthread.h>
// # include <fcntl.h>

//ray.c
t_ray   ray(t_point origin, t_vec dir);
t_vec       ray_at(t_ray *ray, double t);
t_ray		ray_primary(t_camera *cam, double u, double v);
t_vec		ray_color(t_scene *scene);

//vec.c
t_vec       vec(double x, double y, double z);
double      vec_length(t_vec vector);
t_vec       vec_add(t_vec vector1, t_vec vector2);
t_vec       vec_minus(t_vec vector1, t_vec vector2);
t_vec       vec_mul(t_vec vector1, t_vec vector2);
t_vec       vec_mul_num(double t, t_vec vector1);
t_vec       vec_div(double t, t_vec vector1);
double      vec_dot(t_vec vector1, t_vec vector2);
t_vec	    vec_cross(t_vec vec, t_vec vec2);
t_vec       vec_unit(t_vec vector1);
t_vec vec_min(t_vec vec1, t_vec vec2);
t_vec		vsymmetric(t_point p1, t_point stan);

//color.c
t_color     color(double r, double g, double b);
int         write_color(int t, t_color pixel_color);



//point.c
t_vec       point3(double x, double y, double z);

//object.c
t_object	*object(t_object_type type, void *element, t_color albedo);
void		oadd(t_object **list, t_object *new);
t_object	*olast(t_object *list);

//light.c
t_light		*light_point(t_point light_origin, t_color light_color, double bright_ratio);
t_color		phong_lighting(t_scene *scene);
t_color		point_light_get(t_scene *scene, t_light *light);
t_vec			reflect(t_vec v, t_vec n);

//scene.c
t_camera	camera(t_canvas *canvas, t_point origin);
t_canvas	canvas(int	width, int height);
t_scene     *scene_init(void);

//shadow.h
t_bool			in_shadow(t_object *objs, t_ray light_ray, double light_len);

//hit.c
t_bool		hit(t_object *world, t_ray *ray, t_hit_record *rec);
t_bool		hit_obj(t_object *world, t_ray *ray, t_hit_record *rec);
void        set_face_normal(t_ray *ray, t_hit_record *rec);

// sphere.c
t_sphere	*sphere(t_point center, double radius);
t_bool      hit_sphere(t_object *world, t_ray *ray, t_hit_record *rec);
t_bool      sphere_discriminant(t_sphere* sp, t_ray *ray, t_hit_record *rec);

//plane.c
t_plane	*plane(t_point point, t_vec normal);
t_bool hit_plane(t_object *world, t_ray *ray, t_hit_record *rec);

//triangle.c
t_triangle	*triangle(t_vec p1, t_vec p2, t_vec p3);
t_bool hit_triangle(t_object *world, t_ray *ray, t_hit_record *rec);
t_bool check_tri(t_vec a, t_vec b, t_vec c, t_vec point);

//square.c
t_square	*square(t_point point, t_vec normal, double length);
t_bool hit_square(t_object *world, t_ray *ray, t_hit_record *rec);

//cylider.c
t_cylinder  *cylinder(t_point point, t_vec normal, double radius, double height);
t_bool      hit_cylinder(t_object *world, t_ray *ray, t_hit_record *rec);
t_bool      cylinder_discriminant(t_cylinder *cylinder, t_ray *ray, t_hit_record *rec);
#endif
