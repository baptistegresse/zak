/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:06:53 by bgresse           #+#    #+#             */
/*   Updated: 2023/03/09 20:18:43 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../../includes/minishell.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tab;

	tab = b;
	while (len > 0)
	{
		*tab = (unsigned char)c;
		tab++;
		len--;
	}
	return (b);
}
