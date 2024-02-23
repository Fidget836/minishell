/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarie <tmarie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 05:59:08 by abrin             #+#    #+#             */
/*   Updated: 2023/08/15 20:15:42 by tmarie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	clean_token(t_data *data)
{
	int	i;

	data->token_y = 0;
	i = 0;
	while (i < 100)
	{
		data->token[i++][0] = '\0';
	}
}

int	fill_token_quote_condition1(t_data *data, int i)
{
	while (data->buffer[i] != '\'')
		data->token[data->token_y][data->token_x++] = data->buffer[i++];
	data->token[data->token_y][data->token_x] = '\0';
	i++;
	return (i);
}

int	token_quote_empty(t_data *data, int i)
{
	while (data->buffer[i] != '\"')
	{
		if (ft_iswhitespace(data->buffer[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
