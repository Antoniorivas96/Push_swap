/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrivas- <anrivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:53:22 by anrivas-          #+#    #+#             */
/*   Updated: 2023/12/28 16:54:39 by anrivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printchar(char c);
int	ft_printf(char const *content, ...);
int	ft_printstr(char *str);
int	ft_printhexa(unsigned long long n, char c);
int	ft_printptr(unsigned long long ptr);
int	ft_putchar(char c);
int	ft_printdec(int n);
int	ft_printunsigned(unsigned int uns);

#endif