/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:58:41 by dongyoki          #+#    #+#             */
/*   Updated: 2022/12/02 14:35:47 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"

void	*ft_malloc(size_t size)
{
	return (primary(0, size));
}

void	ft_free(void *addr)
{
	primary(addr, 0);
}

void	ft_clear(void)
{
	primary(0, 0);
}
