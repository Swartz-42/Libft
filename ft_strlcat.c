/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aducas <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 11:04:14 by aducas       #+#   ##    ##    #+#       */
/*   Updated: 2019/10/30 12:38:57 by aducas      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	size_t	dstsize;
	size_t	srcsize;
	size_t	i;

	i = 0;
	dstsize = ft_strlen(dst);
	srcsize = ft_strlen(src);
	if (size == 0)
		return (srcsize);
	if (size < dstsize)
		return (size + srcsize);
	if (dstsize < size)
	{
		while (i < srcsize && dstsize + i < size)
		{
			dst[dstsize + i] = src[i];
			i++;
		}
		if (dstsize + i < size)
			dst[dstsize + i] = '\0';
		else
			dst[size - 1] = '\0';
	}
	return (dstsize + srcsize);
}
