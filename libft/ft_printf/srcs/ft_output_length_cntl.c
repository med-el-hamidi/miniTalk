/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_length_cntl.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:57:10 by mel-hami          #+#    #+#             */
/*   Updated: 2025/03/06 20:57:11 by mel-hami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs.h"

int	ft_output_length_cntl(int flag)
{
	static int	output_length;

	if (!flag)
		output_length = 0;
	else if (flag > 0)
		output_length += flag;
	else if (flag == -1)
		output_length = -1;
	return (output_length);
}
