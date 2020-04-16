/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 15:12:38 by lvirgini          #+#    #+#             */
/*   Updated: 2020/04/16 14:15:16 by lvirgini         ###   ########.fr       */
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

/*
** Fonctions principales
*/

size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s);
char		*ft_strcpy(char *dest, const char *src);
int			ft_strcmp(const char *s1, const char *s2);
ssize_t		ft_write(int fd, const void *buf, size_t count);
ssize_t		ft_read(int fd, void *buf, size_t count);

/*
** Fonctions Bonus
*/

typedef		struct s_list t_list;

struct 		s_list
{
	void			*data;
	struct s_list	*next;
};

int			ft_atoi_base(char *str,char *base);
void		ft_list_push_front(t_list **begin_list,void*data);
int			ft_list_size(t_list *begin_list);
int			ft_list_sort(t_list **begin_list,int(*cmp)());
#endif