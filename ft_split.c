/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aducas <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/16 17:34:05 by aducas       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/14 10:57:19 by aducas      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	**splitfree(char **ptr)
{
	int i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (NULL);
}

static int	splitproc(char **ptr, char const *s, char c)
{
	int	i;
	int	row;
	int	start;
	int	end;

	i = -1;
	row = 0;
	start = -1;
	end = 1;
	while (s[++i])
	{
		if (s[i] != c)
		{
			(start == -1) ? start = i : 0;
			if (s[i + 1] == c || s[i + 1] == '\0')
			{
				if (!(ptr[row++] = ft_substr(s, start, end)))
					return (0);
				start = -1;
				end = 0;
			}
			end++;
		}
	}
	return (1);
}

char		**ft_split(char const *s, char c)
{
	char	**ptr;
	int		rows;
	int		i;

	if (!s)
		return (0);
	i = 0;
	rows = 0;
	while (s[i])
	{
		(s[i] != c && (s[i + 1] == c || s[i + 1] == '\0')) ? rows++ : 0;
		i++;
	}
	if (!(ptr = malloc((rows + 1) * sizeof(char *))))
		return (0);
	ptr[rows] = 0;
	if (!(splitproc(ptr, s, c)))
		return (splitfree(ptr));
	return (ptr);
}
