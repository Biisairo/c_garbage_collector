/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primary.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:58:41 by dongyoki          #+#    #+#             */
/*   Updated: 2022/12/02 17:04:07 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"

void	*primary(void *addr, size_t size)
{
	void			*res;
	static t_mem	**mem;

	if (!mem)
		if (init_mems(&mem))
			return (0);
	if (addr == 0 && size == 0)
		return (clear_mem(&mem));
	else if (addr == 0)
	{
		res = malloc(size);
		res = gc_malloc(&(mem[(unsigned long long)res % 100]), res);
		if (!res)
			return (primary(0, 0));
		return (res);
	}
	else if (size == 0)
	{
		gc_free(&(mem[(unsigned long long)addr % 100]), addr);
	}
	return (0);
}

void	*gc_malloc(t_mem **mem, void *res)
{
	t_mem	*cur;

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

int	init_mems(t_mem ***mem)
{
	size_t	i;

	*mem = malloc(sizeof(t_mem *) * 100);
	if (!(*mem))
		return (1);
	i = 0;
	while (i < 100)
	{
		(*mem)[i] = 0;
		i++;
	}
	return (0);
}

void	*clear_mem(t_mem ***mem)
{
	size_t	i;

	i = 0;
	while (i < 100)
	{
		mem_clear(&((*mem)[i]));
		i++;
	}
	free(*mem);
	*mem = 0;
	return (0);
}
