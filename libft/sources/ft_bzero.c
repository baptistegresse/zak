/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:01:03 by bgresse           #+#    #+#             */
/*   Updated: 2023/03/09 20:16:55 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../../includes/minishell.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*tab;

	tab = s;
	while (n--)
		*(tab++) = 0;
}
