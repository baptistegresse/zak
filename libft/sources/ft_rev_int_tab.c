/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 13:43:43 by bgresse           #+#    #+#             */
/*   Updated: 2023/03/09 20:18:58 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_rev_int_tab(int *tab, int size)
{
	int		x;
	int		i;
	int		temp;

	i = 0;
	x = size - 1;
	while (i < x)
	{
		temp = tab[i];
		tab[i] = tab[x];
		tab[x] = temp;
		i++;
		x--;
	}
}
