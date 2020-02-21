/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aducas <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/24 12:53:17 by aducas       #+#   ##    ##    #+#       */
/*   Updated: 2019/10/30 13:18:43 by aducas      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	char	*ft_swap(char *str)
{
	char	tmp;
	int		i;
	int		a;

	i = 0;
	a = 0;
	while (str[i])
		i++;
	while (a < i)
	{
		tmp = str[a];
		str[a] = str[i - 1];
		str[i - 1] = tmp;
		a++;
		i--;
	}
	return (str);
}

static	int		cpt_n(int n)
{
	int cpt;

	cpt = 0;
	if (n <= 0)
		cpt++;
	while (n)
	{
		n = n / 10;
		cpt++;
	}
	return (cpt);
}

char			*ft_itoa(int n)
{
	int			i;
	int			neg;
	char		*str;
	long int	nb;

	if (!(str = malloc(sizeof(char) * (cpt_n(n) + 1))))
		return (0);
	i = 0;
	nb = n;
	if (n == 0)
		str[i++] = '0';
	if (n < 0)
		nb = -nb;
	neg = (n < 0) ? 1 : 0;
	while (nb != 0)
	{
		str[i++] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (neg)
		str[i++] = '-';
	str[i++] = '\0';
	return (ft_swap(str));
}
