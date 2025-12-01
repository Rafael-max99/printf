/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:58:05 by rlauren           #+#    #+#             */
/*   Updated: 2025/11/30 14:50:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_resetflags(void)
{
	t_flags	flag;

	flag.minus = 0;
	flag.zero = 0;
	flag.plus = 0;
	flag.space = 0;
	flag.hashtag = 0;
	return (flag);
}

t_logic	ft_resetlogic(void)
{
	t_logic	logic;

	logic.width = 0;
	logic.precision = -1;
	logic.point = 0;
	logic.ct = 0;
	logic.printed = 0;
	return (logic);
}
