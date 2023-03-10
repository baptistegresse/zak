/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:29:43 by bgresse           #+#    #+#             */
/*   Updated: 2023/03/09 20:20:50 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../../includes/minishell.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	len;
	char	*string;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = ft_free_malloc(global.m_free, (1));
		if (!s1)
			return (0);
		*s1 = 0;
	}
	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	string = (char *)ft_free_malloc(global.m_free, ((sizeof(char) * len) + 1));
	if (!string)
		return (NULL);
	while (s1[i])
		string[j++] = s1[i++];
	i = 0;
	while (s2[i])
		string[j++] = s2[i++];
	string[j] = '\0';
	return (string);
}
