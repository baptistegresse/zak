/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 23:19:09 by bgresse           #+#    #+#             */
/*   Updated: 2023/03/09 20:14:09 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	ft_is_nflag(char *string)
{
	int		i;

	i = 0;
	if (string[i] != '-' || !string[1])
		return (0);
	else
		i++;
	while (string[i] && string[i] == 'n')
		i++;
	if (string[i])
		return (0);
	else
		return (1);
}

void	ft_built_in_echo(char **cmd)
{
	bool	n_flag;
	int		i;

	i = 1;
	n_flag = false;
	if (cmd[1] && ft_is_nflag(cmd[1]))
	{
		n_flag = true;
		i = 2;
	}
	while (cmd && cmd[i])
	{
		printf("%s ", cmd[i]);
		i++;
	}
	if (n_flag == false)
		printf("\n");
	global.g_status = 0;
}
