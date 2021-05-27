/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 21:32:39 by najlee            #+#    #+#             */
/*   Updated: 2021/05/26 21:32:40 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_a(t_info *info, int r)
{
	int a;
	int b;
	int c;

	if (r == 2)
	{
		if (info->stack[A]->head->next->data >
			info->stack[A]->head->next->next->data)
			sab(info, A, 1);
	}
	if (r == 3)
	{
		a = info->stack[A]->head->next->data;
		b = info->stack[A]->head->next->next->data;
		c = info->stack[A]->head->next->next->next->data;
		if (a < c && c < b)
		{
			rab(info, A, 1);
			sab(info, A, 1);
			rrab(info, A, 1);
		}
		else if (b < c && c < a)
		{
			sab(info, A, 1);
			rab(info, A, 1);
			sab(info, A, 1);
			rrab(info, A, 1);
		}
		else
			sort_aa(a, b, c, info);
	}
}

void	sort_aa(int a, int b, int c, t_info *info)
{
	if (b < a && a < c)
		sab(info, A, 1);
	else if (c < a && a < b)
	{
		rab(info, A, 1);
		sab(info, A, 1);
		rrab(info, A, 1);
		sab(info, A, 1);
	}
	else if (c < b && b < a)
	{
		sab(info, A, 1);
		rab(info, A, 1);
		sab(info, A, 1);
		rrab(info, A, 1);
		sab(info, A, 1);
	}
}

void	sort_b(t_info *info, int r)
{
	int a;
	int b;
	int c;

	if (r == 1)
		pab(info, A);
	if (r == 2)
	{
		if (info->stack[B]->head->next->data <
			info->stack[B]->head->next->next->data)
		{
			sab(info, B, 1);
		}
		pab(info, A);
		pab(info, A);
	}
	if (r == 3)
	{
		a = info->stack[B]->head->next->data;
		b = info->stack[B]->head->next->next->data;
		c = info->stack[B]->head->next->next->next->data;
		if (b < a && a < c)
		{
			rab(info, B, 1);
			sab(info, B, 1);
			rrab(info, B, 1);
			sab(info, B, 1);
		}
		else if (c < a && a < b)
		{
			sab(info, B, 1);
		}
		else
		{
			sort_bb(a, b, c, info);
		}
		pab(info, A);
		pab(info, A);
		pab(info, A);
	}
}

void	sort_bb(int a, int b, int c, t_info *info)
{
	if (a < b && b < c)
	{
		sab(info, B, 1);
		rab(info, B, 1);
		sab(info, B, 1);
		rrab(info, B, 1);
		sab(info, B, 1);
	}
	else if (a < c && c < b)
	{
		sab(info, B, 1);
		rab(info, B, 1);
		sab(info, B, 1);
		rrab(info, B, 1);
	}
	else if (b < c && c < a)
	{
		rab(info, B, 1);
		sab(info, B, 1);
		rrab(info, B, 1);
	}
}
