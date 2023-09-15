/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 20:28:48 by voszadcs          #+#    #+#             */
/*   Updated: 2023/09/14 19:01:34 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

char	**dup_env(char **env)
{
	char	**env_cpy;
	int		i;
	int		len;

	i = 0;
	while (env[i] != NULL)
		i++;
	env_cpy = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (env[i] != NULL)
	{
		len = ft_strlen(env[i]);
		env_cpy[i] = ft_substr(env[i], 0, len);
		i++;
	}
	env_cpy[i] = NULL;
	return (env_cpy);
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