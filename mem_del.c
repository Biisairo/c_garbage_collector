/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:52:06 by dongyoki          #+#    #+#             */
/*   Updated: 2022/12/02 15:15:47 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"

void	mem_del(t_mem **mem, void *addr)
{
	t_mem	*cur;
	t_mem	*pre;

	cur = *mem;
	pre = 0;
	while (cur && (cur->addr) != addr)
	{
		pre = cur;
		cur = cur->next;
	}
	if (!cur)
		return ;
	if (pre && cur)
		pre->next = cur->next;
	else if (!pre && cur)
		*mem = cur->next;
	free(cur->addr);
	free(cur);
}
