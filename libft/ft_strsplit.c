/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/03 22:22:45 by eovertoo      #+#    #+#                 */
/*   Updated: 2019/04/10 20:49:37 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		count_word(char const *s, char c)
{
	int					i;
	int					cnt;

	i = 0;
	cnt = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			cnt++;
		i++;
	}
	if (s[0] != '\0' && s[0] != c)
		cnt++;
	return (cnt);
}

static void		make_free(char **d)
{
	int			i;

	i = 0;
	while (d[i] != NULL)
	{
		free(d[i]);
		i++;
	}
	free(d);
}

static char		*ft_make_space(char **d, int i)
{
	char		*x;

	x = (char*)malloc(sizeof(char) * (i + 1));
	if (!x)
	{
		make_free(d);
		return (NULL);
	}
	return (x);
}

static char		*put_word(const char *s, char c, int *i, char **d)
{
	int					k;
	int					l;
	char				*ret;
	int					j;

	j = 0;
	k = *i;
	l = *i;
	while (s[k] != c && s[k] != '\0')
		k++;
	ret = ft_make_space(d, (k - l));
	if (ret == NULL)
		return (NULL);
	while (j < (k - l))
	{
		ret[j] = s[*i];
		j++;
		*i = *i + 1;
	}
	ret[j] = '\0';
	while (s[*i] == c)
		*i = *i + 1;
	return (ret);
}

char			**ft_strsplit(char const *s, char c)
{
	int					i;
	char				**d;
	int					k;
	int					words;

	if (!s)
		return (NULL);
	words = count_word(s, c);
	i = 0;
	k = 0;
	d = (char**)malloc(sizeof(char*) * (words + 1));
	if (!d)
		return (NULL);
	while (s[i] == c)
		i++;
	while (k < words && s[i] != '\0')
	{
		d[k] = put_word(s, c, &i, d);
		k++;
	}
	d[k] = NULL;
	return (d);
}
