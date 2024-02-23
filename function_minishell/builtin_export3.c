/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarie <tmarie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 05:37:32 by abrin             #+#    #+#             */
/*   Updated: 2023/08/18 22:14:48 by tmarie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strdup_special(const char *src, t_data *data)
{
	char	*new;
	int		i;

	i = 0;
	while (src[i])
		i++;
	new = gc_malloc(&data->gc, sizeof(char) * (i + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (src[i] && src[i] != ' ')
	{
		new[i] = src[i];
		i++;
	}
	while (src[i])
	{
		new[i] = '\0';
		i++;
	}
	new[i] = '\0';
	return (new);
}

void	clean_result_export_var2(t_data *data, int i, int y)
{
	data->export_var[i][y] = '=';
	data->export_var[i][y + 1] = '\'';
	data->export_var[i][y + 2] = '\'';
	data->export_var[i][y + 3] = '\0';
}

void	tri_export_var_env(t_data *data)
{
	int		i;
	int		y;
	char	*temp;

	i = 0;
	y = 0;
	temp = gc_malloc(&data->gc, sizeof(char) * 1000);
	while (data->export_var[i])
	{
		if (data->export_var[i][0] == '\0')
			i++;
		else
		{
			data->export_var[y] = data->export_var[i];
			i++;
			y++;
		}
	}
	data->export_var[y] = NULL;
	temp = NULL;
}
