/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:02:59 by zrebhi            #+#    #+#             */
/*   Updated: 2023/03/10 20:07:55 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_special_builtins(t_minishell *data);
void	set_interactive_signals(void);

void	data_init(int argc, char **argv, char **envp, t_minishell *data)
{
	data->argc = argc;
	data->argv = argv;
	data->envp = envp;
	ft_parse_env(&data->head_env, data->envp);
	data->paths = ft_pathfinder(&data->head_env);
	global.g_status = 0;
}

char	**ft_refresh_envp(t_env *head)
{
	size_t	env_len;
	char	**env;
	size_t	i;

	if (!head)
		return (NULL);
	env_len = ft_list_size(head);
	env = ft_calloc(sizeof(char *), (env_len + 1));
	i = 0;
	while (head)
	{
		if (head->equal)
			env[i] = ft_strjoin(head->key, ft_strjoin("=", head->value));
		else
			env[i] = head->key;
		i++;
		head = head->next;
	}
	env[i] = NULL;
	return (env);
}

static char	*get_prompt(t_env *head, char *key)
{
	t_env	*temp;

	temp = head;
	while (temp)
	{
		if (ft_strcmp(temp->key, key) == 0)
			return (ft_strjoin(ft_strjoin(""GREEN"➜  "CYAN"", temp->value),
					""PURPLE"@minishell > "RESET""));
		temp = temp->next;
	}
	return (""GREEN"➜  "CYAN"guest"PURPLE"@minishell > "RESET"");
}

void	ft_prompt(t_minishell *data)
{
	char		*buffer;
	int			pid;
	char		*prompt;

	while (1)
	{
		data->envp = ft_refresh_envp(data->head_env);
		prompt = get_prompt(data->head_env, "USER");
		set_interactive_signals();
		buffer = readline(prompt);
		if (!buffer)
			break ;
		if (!*buffer)
			continue ;
		add_history(buffer);
		data->cmds = ft_cmdlist(buffer, data);
		// ft_print_cmdlist(data->cmds);
		free(buffer);
		if (data->cmds)
		{
			unplug_signals();
			ft_special_builtins(data);
			pid = fork();
			if (pid == 0)
				pipex(data);
			waitpid(pid, &data->status, 0);
			global.g_status = WEXITSTATUS(data->status);
			while (data->cmds)
			{
				if (data->cmds->here_doc && !data->cmds->error \
				&& close(data->cmds->here_doc_pipe[0]) == -1)
					perror("close pipe main");
				if (data->cmds->outfile > 1 && close(data->cmds->outfile) == -1)
					perror("close outfile");
				if (data->cmds->infile > 1 && close(data->cmds->infile) == -1)
					perror("close infile");
				data->cmds = data->cmds->next;
			}
		}
	}	
	printf("exit\n");
}

int	main(int argc, char **argv, char **envp)
{
	t_minishell	*data;

	global.m_free = ft_free_init();
	data = ft_calloc(sizeof(t_minishell), 1);
	if (!data)
		return (1);
	data_init(argc, argv, envp, data);
	ft_prompt(data);
	return (ft_free(global.m_free), global.g_status);
}
