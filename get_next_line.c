/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzavada <pzavada@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:22:01 by pzavada           #+#    #+#             */
/*   Updated: 2026/03/10 16:25:51 by pzavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#include "get_next_line.h"

static char	*gnl_read(char **stash, char *temp, int fd);
static char	*gnl_nfound(char **stash);
static char	*gnl_clean(char **stash);
char		*get_next_line(int fd);

static char	*gnl_read(char **stash, char *temp, int fd)
{
	size_t	bytes;
	ssize_t	i;

	bytes = 0;
	while (*stash && stash[0][bytes])
		bytes++;
	while (1)
	{
		i = read(fd, temp, BUFFER_SIZE);
		if (i == -1)
			return (NULL);
		if (i == 0)
			return (gnl_clean(stash));
		temp[i] = '\0';
		*stash = gnl_strjoin(*stash, temp, bytes);
		if (!*stash)
			return (NULL);
		bytes += i;
		if (bytes > 1000000)
			return (NULL);
		if (gnl_iteration(temp, '\n'))
			return (gnl_nfound(stash));
	}
}

static char	*gnl_clean(char **stash)
{
	char	*res;

	res = NULL;
	if (*stash && **stash)
		res = gnl_strdup(*stash);
	free (*stash);
	*stash = NULL;
	return (res);
}

static char	*gnl_nfound(char **stash)
{
	char	*res;

	res = gnl_strdup(*stash);
	*stash = gnl_delete(*stash);
	return (res);
}

char	*get_next_line(int fd)
{
	char		*temp;
	static char	*stash;
	char		*result;

	if (BUFFER_SIZE <= 0 || BUFFER_SIZE > SIZE_MAX - 1 || fd < 0)
		return (NULL);
	if (stash && gnl_iteration(stash, '\n'))
		return (gnl_nfound(&stash));
	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	if (!stash)
	{
		stash = malloc(BUFFER_SIZE);
		if (!stash)
		{
			free (temp);
			return (NULL);
		}
		stash[0] = '\0';
	}
	result = gnl_read(&stash, temp, fd);
	free (temp);
	return (result);
}
