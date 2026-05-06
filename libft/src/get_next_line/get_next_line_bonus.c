/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <stelim@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:50:41 by stelim            #+#    #+#             */
/*   Updated: 2026/02/18 22:46:40 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1. Read BUFFER_SIZE byte into &string.
// 2. Check for "\n". Copy up to and include \n to string.
// 3. if still contains "\n", stops and return new string.

#include "../../includes/get_next_line_bonus.h"

static char	*ft_terminate(char **stash)
{
	char	*ret;

	if (*stash != NULL && **stash != 0)
	{
		ret = ft_strdup(*stash);
		free(*stash);
		*stash = NULL;
	}
	else
		ret = NULL;
	return (ret);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	pos;

	ptr = NULL;
	if ((nmemb == 0) || (size == 0))
	{
		ptr = (void *) malloc(1);
		return (ptr);
	}
	else if ((size != 0) && (nmemb < (size_t) -1 / size))
	{
		ptr = (void *)malloc(nmemb * size);
		if (!ptr)
			return (NULL);
		pos = nmemb * size;
		while (pos-- > 0)
			((unsigned char *)ptr)[pos] = 0;
		return (ptr);
	}
	return (NULL);
}

static int	ft_read_newline(int fd, char **stash)
{
	int		nbytes;
	char	*string;
	char	*temp;

	string = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	nbytes = BUFFER_SIZE;
	while (ft_strchr(*stash, 10) == NULL && nbytes > 0)
	{
		nbytes = read(fd, string, BUFFER_SIZE);
		if (nbytes > 0)
		{
			temp = ft_strjoin(*stash, string);
			free(*stash);
			free(string);
			*stash = temp;
			string = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		}
	}
	free(string);
	return (nbytes);
}

static char	*ft_read_stash(int fd, char **stash)
{
	char	*newline;
	char	*nextline;
	char	*ret;
	int		nbytes;

	newline = ft_strchr(*stash, 10);
	if (newline != NULL)
	{
		ret = ft_substr(*stash, 0, newline + 1 - *stash);
		nextline = ft_strdup(newline + 1);
		free(*stash);
		*stash = nextline;
	}
	else
	{
		nbytes = ft_read_newline(fd, stash);
		if (nbytes <= 0)
			ret = ft_terminate(stash);
		else
			ret = ft_read_stash(fd, stash);
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*newstring;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE < 0)
		return (NULL);
	if (stash[fd] == NULL)
		stash[fd] = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	newstring = ft_read_stash(fd, &stash[fd]);
	if (newstring == NULL)
	{
		free(stash[fd]);
		stash[fd] = NULL;
	}
	return (newstring);
}
