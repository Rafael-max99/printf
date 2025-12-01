/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prefix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:59:24 by marvin            #+#    #+#             */
/*   Updated: 2025/12/01 13:59:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_prefix(char type, char *num_char)
{
	char	*str;

	str = malloc(3);
	if (!str)
		return (NULL);
	str[0] = '0';
	if (type == 'x')
		str[1] = 'x';
	else if (type == 'X')
	{
		str[1] = 'X';
		ft_toupper(num_char);
	}
	str[2] = '\0';
	return (str);
}
