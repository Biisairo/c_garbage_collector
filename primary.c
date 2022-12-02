/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primary.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:58:41 by dongyoki          #+#    #+#             */
/*   Updated: 2022/12/02 15:21:15 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"

void	*primary(void *addr, size_t size)
{
	static t_mem	*mem;
	size_t			i;
	void			*res;

	// static t_mem	**mem;
	// if (!mem)
	// {
	// 	mem = malloc(sizeof(t_mem *) * 100);
	// 	if (!mem)
	// 		return (0);
	// 	i = 0;
	// 	while (i < 100)
	// 	{
	// 		mem[i] = 0;
	// 		i++;
	// 	}
	// }
	if (addr == 0 && size == 0)
	{
		// i = 0;
		// while (i < 100)
		// {
		// 	mem_clear(&(mem[i]));
		// 	i++;
		// }
		// free(mem);
		mem_clear(&mem);
		free(mem);
	}
	else if (addr == 0)
	{
		// res = gc_malloc(&(mem[(unsigned long long)addr % 100]), size);
		res = gc_malloc(&mem, size);
		if (!res)
			return (primary(0, 0));
		return (res);
	}
	else if (size == 0)
	{
		// gc_free(&(mem[(unsigned long long)addr % 100]), addr);
		gc_free(&mem, addr);
	}
	return (0);
}

void	*gc_malloc(t_mem **mem, size_t size)
{
	void	*res;
	t_mem	*cur;

	res = malloc(size);
	if (!res)
		return (0);
	cur = new_mem(res);
	if (!cur)
	{
		free(res);
		return (0);
	}
	mem_add_front(mem, cur);
	return (res);
}

void	gc_free(t_mem **mem, void *addr)
{
	mem_del(mem, addr);
}
