/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 23:33:48 by bgresse           #+#    #+#             */
/*   Updated: 2023/03/10 19:11:29 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_env_variable(t_env *env);
void	print_sorted_env_array(t_env **array, int count);
void	sort_env_array(t_env **array, int count);
void	copy_env_to_array(t_env *env, t_env **array, int count);
void	ft_print_env_sorted(t_env *env);

t_env	*ft_get_env_node(t_env **head, char *key)
{
	t_env	*temp;

	temp = *head;
	while (temp != NULL)
	{
		if (ft_strcmp(temp->key, key) == 0)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

void	ft_modify_env_with_equal_sign(t_env **head, char *cmd_arg)
{
	t_env	*env_var;
	char	*key;
	char	*value;

	key = ft_strndup(cmd_arg,
			ft_strlen(cmd_arg)- ft_strlen(ft_strchr(cmd_arg, '=')));
	value = ft_strdup(ft_strchr(cmd_arg, '=') + 1);
	env_var = ft_get_env_node(head, key);
	if (env_var)
	{
		env_var->value = value;
		env_var->equal = true;
	}
	else
		*head = add_node(*head, key, value, true);
}

void	ft_modify_env_without_equal_sign(t_env **head, char *cmd_arg)
{
	if (!ft_get_env_node(head, cmd_arg))
		*head = add_node(*head, cmd_arg, "", false);
}

int	ft_check_env_var_name(char *str)
{
	int	i;

	i = 0;
	if (ft_isdigit(str[i]) || !ft_isalnum(str[i]))
	{
		ft_putstr_fd("minishell: export: `", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		return (0);
	}
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
		{
			ft_putstr_fd("minishell: export: `", 2);
			ft_putstr_fd(str, 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_built_in_export(t_env **head, char **full_cmd)
{
	size_t	i;

	if (!full_cmd[1])
		return (ft_print_env_sorted(*head));
	i = 1;
	while (full_cmd[i])
	{
		if (ft_check_env_var_name(full_cmd[i]) == 0)
			break ;
		if (ft_strchr(full_cmd[i], '='))
			ft_modify_env_with_equal_sign(head, full_cmd[i]);
		else
			ft_modify_env_without_equal_sign(head, full_cmd[i]);
		i++;
	}
}
