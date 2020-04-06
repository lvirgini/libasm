/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 15:12:38 by lvirgini          #+#    #+#             */
/*   Updated: 2020/04/06 17:30:04 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_ASM_H
# define LIB_ASM_H

// Penser a refaire les globals avec '_'  :: strlen = _strlen sur mac
//
//
# include <sys/types.h> // a verif sur MAC
# include <stddef.h>
# include <stdint.h>

size_t		ft_strlen(const char *s);
char		*ft_strcpy(char *dest, const char *src);
int			ft_strcmp(const char *s1, const char *s2);
ssize_t		ft_write(int fd, const void *buf, size_t count);
ssize_t		ft_read(int fd, void *buf, size_t count);
#endif