/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:02:38 by dongyoki          #+#    #+#             */
/*   Updated: 2022/12/02 14:47:42 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"

void	mem_clear(t_mem **mem)
{
	t_mem	*cur;

	if (!(*mem))
		return ;
	while (*mem)
	{
		cur = *mem;
		*mem = (*mem)->next;
		free(cur->addr);
		free(cur);
	}
}
