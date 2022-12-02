/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:41:34 by dongyoki          #+#    #+#             */
/*   Updated: 2022/12/02 15:55:46 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_COLLECTOR_H
# define GARBAGE_COLLECTOR_H
# include <stdio.h>
# include <stdlib.h>

typedef struct s_mem
{
	void			*addr;
	struct s_mem	*next;
}					t_mem;

void				*ft_malloc(size_t size);
void				ft_free(void *addr);
void				ft_clear(void);

void				*primary(void *addr, size_t size);
void				*gc_malloc(t_mem **mem, void *res);
void				gc_free(t_mem **mem, void *addr);
int					init_mems(t_mem ***mem);
void				*clear_mem(t_mem ***mem);

void				mem_add_front(t_mem **mem, t_mem *new);
void				mem_clear(t_mem **mem);
void				mem_del(t_mem **mem, void *addr);
t_mem				*new_mem(void *addr);

#endif
