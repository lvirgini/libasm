/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 15:12:38 by lvirgini          #+#    #+#             */
/*   Updated: 2020/04/03 14:49:31 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_ASM_H
# define LIB_ASM_H

# include <stddef.h>

int		arg_int_ret(void);
int		ft_addition(int a, int b);

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dest, const char *src);

#endif