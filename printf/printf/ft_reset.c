/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlauren <rlauren@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:58:05 by rlauren           #+#    #+#             */
/*   Updated: 2025/11/27 19:28:23 by rlauren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
