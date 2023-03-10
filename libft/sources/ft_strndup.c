/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:21:49 by bgresse           #+#    #+#             */
/*   Updated: 2023/03/09 20:21:20 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../../includes/minishell.h"

char	*ft_strndup(char *s, size_t n)
{
	char	*new;

	new = ft_free_malloc(global.m_free, (n + 1));
	if (new)
	{
		ft_strncpy(new, s, n);
		new[n] = '\0';
	}
	return (new);
}
