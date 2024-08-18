/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:59:41 by keishii           #+#    #+#             */
/*   Updated: 2024/08/18 15:36:04 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*fill_stash(int fd, char *stash);
static char	*extract_line(char *stash);
static char	*extract_new_stash(char *stash);
static char	*free_and_null(void *ptr);

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	line = NULL;
	if (fd == -1 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(stash);
		return (stash = NULL);
	}
	stash = fill_stash(fd, stash);
	if (!stash || *stash == '\0')
	{
		free(stash);
		return (stash = NULL);
	}
	line = extract_line(stash);
	if (!line)
	{
		free(line);
		return (free_and_null(stash));
	}
	stash = extract_new_stash(stash);
	if (!stash)
		return (free_and_null(line));
	return (line);
}

static char	*fill_stash(int fd, char *stash)
{
	ssize_t	bytes_read;
	char	buffer[BUFFER_SIZE + 1];

	bytes_read = 1;
	if (!stash)
		stash = ft_strdup("");
	if (!stash)
		return (NULL);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (stash);
}

static char	*extract_line(char *stash)
{
	int		len;
	char	*ret_line;

	if (!stash)
		return (NULL);
	len = 0;
	while (stash[len] && stash[len] != '\n')
		len++;
	if (stash[len] == '\n')
		len++;
	ret_line = (char *)malloc((len + 1) * sizeof(char));
	if (!ret_line)
		return (NULL);
	ret_line[len] = '\0';
	while (len--)
		ret_line[len] = stash[len];
	return (ret_line);
}

static char	*extract_new_stash(char *stash)
{
	char	*new_stash;
	size_t	len;
	size_t	i;

	if (!stash)
		return (NULL);
	len = 0;
	while (stash[len] && stash[len] != '\n')
		len++;
	if (stash[len] == '\n')
		len++;
	new_stash = (char *)malloc((ft_strlen(stash) - len + 1) * sizeof(char));
	if (!new_stash)
		return (free_and_null(stash));
	i = 0;
	while (stash[len + i])
	{
		new_stash[i] = stash[len + i];
		i++;
	}
	new_stash[i] = '\0';
	free(stash);
	return (new_stash);
}

static char	*free_and_null(void *ptr)
{
	free(ptr);
	return (NULL);
}
