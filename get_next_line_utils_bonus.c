/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncouton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:22:44 by ncouton           #+#    #+#             */
/*   Updated: 2024/03/20 16:11:01 by ncouton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int searchedChar)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == (char)searchedChar)
			return (&((char *)str)[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*chain;
	size_t	i;
	size_t	j;

	i = ft_strlen(s1) + ft_strlen(s2);
	chain = malloc(sizeof(char) * i + 1);
	if (chain == 0)
		return (0);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		chain[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
		chain[i++] = s2[j++];
	chain[i] = '\0';
	free((void *)s1);
	return (chain);
}

char	*ft_read_new_line(char *line)
{
	int		j;
	int		i;
	char	*s;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free (line);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(line) - i + 1));
	if (s == 0)
		return (NULL);
	i++;
	j = 0;
	while (line[i])
		s[j++] = line[i++];
	s[j] = '\0';
	free(line);
	return (s);
}

char	*ft_buffer(char *line)
{
	int		i;
	char	*s;

	i = 0;
	if (!line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		s[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		s[i] = line[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
