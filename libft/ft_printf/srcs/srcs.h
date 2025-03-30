/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:57:51 by mel-hami          #+#    #+#             */
/*   Updated: 2025/03/06 20:57:51 by mel-hami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRCS_H
# define SRCS_H
# include "../utils/utils.h"
# include <stdarg.h>

int		ft_output_length_cntl(int flag);
void	ft_handle_flags_and_digits(char **str, t_flags *flag);
void	ft_print_char(t_flags *flag, char c);
void	ft_print_decimal(t_flags *flag, ssize_t nbr);
void	ft_print_hex(t_flags *flag, char x, ssize_t nbr);
void	ft_print_ptr(t_flags *flag, uintptr_t format_address);
void	ft_print_string(t_flags *flag, char *str);
#endif
