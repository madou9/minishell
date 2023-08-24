/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:22:23 by ihama             #+#    #+#             */
/*   Updated: 2023/08/22 16:12:10 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

char	**dup_env(char **env)
{
	char	**new_env;
	int		i;

	i = 0;
	while (env[i])
		i++;
	new_env = ft_calloc(sizeof(char *), (i + 1));
	if (!new_env)
		return (NULL);
	i = 0;
	while (env[i])
	{
		new_env[i] = ft_strdup(env[i]);
		if (new_env[i] == NULL)
		{
			free(new_env);
			return (new_env);
		}
		i++;
	}
	new_env[i] = NULL;
	return (new_env);
}

char	*ft_getenv(char **env, const char *name)
{
	size_t	len;
	char	**p;

	len = ft_strlen(name);
	p = env;
	if (name == NULL || *name == '\0')
		return (NULL);
	while (*p != NULL)
	{
		if (strncmp(*p, name, len) == 0 && (*p)[len] == '=')
			return (strdup(*p + len + 1));
		p++;
	}
	return (NULL);
}
