/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 00:53:31 by bgresse           #+#    #+#             */
/*   Updated: 2023/03/10 19:59:25 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_built_in_exit(t_minishell *data)
{
	int		i;
	int		exit_code;

	i = -1;
	printf("exit\n");
	if (!data->cmds->full_cmd[1] || !*data->cmds->full_cmd[1])
		return (ft_free(global.m_free), exit(global.g_status));
	while (data->cmds->full_cmd[1][++i])
	{
		if (data->cmds->full_cmd[1][i] < '0'
		|| data->cmds->full_cmd[1][i] > '9')
		{
			ft_putstr_fd("exit: ", 2);
			ft_putstr_fd(data->cmds->full_cmd[1], 2);
			ft_putstr_fd(": numeric argument required\n", 2);
			return (ft_free(global.m_free), exit(2));
		}
	}
	if (data->cmds->full_cmd[2])
	{
		ft_putstr_fd("exit: ", 2);
		ft_putstr_fd(": too many arguments\n", 2);
		data->cmds = 0;
	}
	else
	{
		exit_code = ft_atoi(data->cmds->full_cmd[1]);
		return (ft_free(global.m_free), exit(exit_code));
	}
}
