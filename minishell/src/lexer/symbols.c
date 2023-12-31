/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbols.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <aabajyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 00:58:31 by aabajyan          #+#    #+#             */
/*   Updated: 2022/03/03 01:47:47 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*char_to_string(char c)
{
	char	buffer[2];

	buffer[0] = c;
	buffer[1] = '\0';
	return (ft_strdup(buffer));
}

/**
 * @brief Lex binaries.
 * 
 * @param self 
 * @param peek 
 * @return t_token* 
 */
static t_token	*lexer_binary(t_lexer *self, char peek)
{
	if (peek == '>')
	{
		if (lexer_peek(self, 1) == '>')
			return (token_create(T_DOUBLE_GREAT, ft_strdup(">>")));
		return (token_create(T_GREAT, ft_strdup(">")));
	}
	if (peek == '<')
	{
		if (lexer_peek(self, 1) == '<')
			return (token_create(T_DOUBLE_LESS, ft_strdup("<<")));
		return (token_create(T_LESS, ft_strdup("<")));
	}
	return (NULL);
}

/**
 * @brief Lex symbols.
 * 
 * @param self 
 * @param peek 
 * @return t_token* 
 */
t_token	*lexer_symbols(t_lexer *self, char peek)
{
	char	buffer[2];

	if (peek == '$')
		return (token_create(T_DOLLAR_SIGN, ft_strdup("$")));
	if (peek == '|')
		return (token_create(T_VERTICAL_BAR, ft_strdup("|")));
	if (peek == ';')
		return (token_create(T_SEMICOLON, ft_strdup(";")));
	if (peek == '\\')
	{
		self->cursor++;
		buffer[0] = lexer_peek(self, 0);
		buffer[1] = '\0';
		return (token_create(T_WORD, ft_strdup(buffer)));
	}
	return (lexer_binary(self, peek));
}
