/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_mem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:18:47 by dongyoki          #+#    #+#             */
/*   Updated: 2022/12/02 14:55:57 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"

t_mem	*new_mem(void *addr)
{
	t_mem	*mem;

	mem = malloc(sizeof(t_mem));
	if (!mem)
		return (0);
	mem->addr = addr;
	mem->next = 0;
	return (mem);
}
