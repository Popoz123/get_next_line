/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzavada <pzavada@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:18:59 by pzavada           #+#    #+#             */
/*   Updated: 2025/12/18 17:24:24 by pzavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strjoin(char *s1, const char *s2, size_t s1_len);
char	*gnl_strdup(const char *s1);
char	*gnl_delete(char *s);
int		gnl_iteration(char *s, int c);

char	*gnl_strjoin(char *s1, const char *s2, size_t s1_len)
{
	char	*res;	
	size_t	j;
	size_t	i;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	while (s2[j])
		j++;
	res = malloc(s1_len + j + 1);
	if (!res)
		return (NULL);
	while (s1_len != 0 && i < s1_len)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	free (s1);
	return (res);
}

char	*gnl_strdup(const char *s1)
{
	size_t	i;
	size_t	len;
	char	*s2;

	if (!s1)
		return (NULL);
	i = 0;
	len = 0;
	while (s1[len] && s1[len] != '\n')
		len++;
	if (s1[len])
		len++;
	s2 = malloc(len + 1);
	if (!s2)
		return (NULL);
	while (s1[i] && i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*gnl_delete(char *s)
{
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
		return (NULL);
	i++;
	while (s[j])
		j++;
	res = malloc(j - i + 1);
	if (!res)
		return (NULL);
	j = 0;
	while (s[i])
		res[j++] = s[i++];
	res[j] = '\0';
	free(s);
	return (res);
}

int	gnl_iteration(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}
