/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:56:09 by mel-hami          #+#    #+#             */
/*   Updated: 2025/03/06 20:56:20 by mel-hami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putptr_fd(uintptr_t nbr, int fd)
{
	const char	*base;

	base = LOW_HEX_BASE;
	if (nbr < 16)
		ft_putchar_fd(base[nbr], fd);
	else
	{
		ft_putptr_fd(nbr / 16, fd);
		ft_putchar_fd(base[nbr % 16], fd);
	}
}
