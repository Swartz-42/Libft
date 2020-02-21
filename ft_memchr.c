/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aducas <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/14 12:29:12 by aducas       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/28 13:46:52 by aducas      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*chr;
	unsigned int	a;

	chr = (unsigned char *)str;
	a = 0;
	while (a < n)
	{
		if (chr[a] == (unsigned char)c)
			return ((void *)&chr[a]);
		a++;
	}
	return (0);
}
