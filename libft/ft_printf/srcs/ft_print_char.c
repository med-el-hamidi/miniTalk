/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:57:16 by mel-hami          #+#    #+#             */
/*   Updated: 2025/03/06 20:57:17 by mel-hami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs.h"

void	ft_print_char(t_flags *flag, char c)
{
	ft_output_length_cntl(1);
	if (flag->field_min_width > 1)
	{
		ft_output_length_cntl(--flag->field_min_width);
		if (flag->left_justify)
			ft_putchar_fd(c, FD);
		ft_putl_zero_or_space(flag->zero, flag->field_min_width);
		if (!flag->left_justify)
			ft_putchar_fd(c, FD);
	}
	else
		ft_putchar_fd(c, FD);
}
