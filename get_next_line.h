/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzavada <pzavada@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:17:00 by pzavada           #+#    #+#             */
/*   Updated: 2025/12/17 13:48:53 by pzavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>

char	*gnl_strjoin(char *s1, const char *s2, size_t s1_len);
char	*gnl_strdup(const char *s1);
char	*gnl_delete(char *s);
char	*get_next_line(int fd);
int		gnl_iteration(char *s, int c);

#endif