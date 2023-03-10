/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_export2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 00:40:36 by bgresse           #+#    #+#             */
/*   Updated: 2023/03/10 16:57:01 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_env_variable(t_env *env)
{
	if (ft_strcmp(env->value, ""))
	{
		printf("declare -x %s", env->key);
		if (env->equal)
			printf("=");
		printf("\"%s\"\n", env->value);
	}
	else
	{
		printf("declare -x %s", env->key);
		if (env->equal)
			printf("=\"\"\n");
		else
			printf("\n");
	}
}

void	print_sorted_env_array(t_env **array, int count)
{
	int		i;

	i = 0;
	while (i < count)
	{
		print_env_variable(array[i]);
		i++;
	}
}

void	sort_env_array(t_env **array, int count)
{
	int		i;
	int		j;
	t_env	*temp;

	i = 0;
	while (i < count - 1)
	{
		j = 0;
		while (j < count - i - 1)
		{
			if (ft_strcmp(array[j]->key, array[j + 1]->key) > 0)
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	copy_env_to_array(t_env *env, t_env **array, int count)
{
	t_env	*copy;
	int		i;

	i = 0;
	copy = env;
	while (i < count)
	{
		array[i] = copy;
		copy = copy->next;
		i++;
	}
}

void	ft_print_env_sorted(t_env *env)
{
	t_env	**array;
	int		count;

	count = ft_list_size(env);
	array = ft_free_malloc(global.m_free, (count * sizeof(t_env *)));
	if (!array)
		return ;
	copy_env_to_array(env, array, count);
	sort_env_array(array, count);
	print_sorted_env_array(array, count);
	ft_free_remove(FREE, array);
}
