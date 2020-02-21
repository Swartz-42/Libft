/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_substr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aducas <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/14 14:21:57 by aducas       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/20 15:28:51 by aducas      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*n_str;

	if (!(n_str = malloc(len + 1 * sizeof(char))))
		return (0);
	if (!s || ft_strlen(s) < start)
	{
		n_str[0] = 0;
		return (n_str);
	}
	ft_memcpy(n_str, s + start, len);
	n_str[len] = '\0';
	return (n_str);
}
