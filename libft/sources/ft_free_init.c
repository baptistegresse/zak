/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:29:01 by bgresse           #+#    #+#             */
/*   Updated: 2023/03/09 20:17:05 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../../includes/minishell.h"

t_m_free	*ft_free_init(void)
{
	t_m_free	*m_free;

	m_free = (t_m_free *)malloc(sizeof(t_m_free));
	if (!m_free)
		return (NULL);
	m_free->list = NULL;
	return (m_free);
}
