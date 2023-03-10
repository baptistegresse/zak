/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 12:07:47 by bgresse           #+#    #+#             */
/*   Updated: 2023/03/09 20:19:03 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_sort_int_tab(int *tab, int size)
{
	int		x;
	int		i;
	int		temp;

	i = 0;
	x = size - 1;
	while (i < x)
	{
		if (*(tab + i) > *(tab + i + 1))
		{
			temp = *(tab + i);
			*(tab + i) = *(tab + i + 1);
			*(tab + i + 1) = temp;
			i = 0;
		}
		else
		{
			i++;
		}
	}
}
