/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 09:39:12 by julberna          #+#    #+#             */
/*   Updated: 2023/10/27 01:59:23 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_read_file(int fd, char *rest);
static char	*ft_get_line(char *str);
static char	*ft_get_leftover(char *str);

char	*get_next_line(int fd)
{
	char		*line_return;
	char		*str;
	static char	*rest[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read_file(fd, rest[fd]);
	if (!str)
	{
		free(str);
		rest[fd] = NULL;
		return (NULL);
	}
	line_return = ft_get_line(str);
	if (line_return[0] == '\0')
	{
		free(line_return);
		free(str);
		rest[fd] = NULL;
		return (NULL);
	}
	rest[fd] = ft_get_leftover(str);
	free(str);
	return (line_return);
}

static char	*ft_check_read_validity(int nb_read, char *temp_buffer)
{
	if (nb_read < 0)
	{
		free(temp_buffer);
		return (NULL);
	}
	else
		return (temp_buffer);
}

static char	*ft_read_file(int fd, char *rest)
{
	char	*buffer;
	char	*temp_buffer;
	char	*free_temp;
	int		nb_read;

	nb_read = 1;
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	temp_buffer = NULL;
	free_temp = NULL;
	temp_buffer = ft_strjoin(temp_buffer, rest);
	free(rest);
	while (nb_read)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read <= 0)
			break ;
		free_temp = temp_buffer;
		buffer[nb_read] = '\0';
		temp_buffer = ft_strjoin(temp_buffer, buffer);
		free(free_temp);
		if (ft_strchr(temp_buffer, '\n') || nb_read <= 0)
			break ;
	}
	free(buffer);
	return (ft_check_read_validity(nb_read, temp_buffer));
}

static char	*ft_get_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		i++;
	}
	line = ft_calloc((i + 2), sizeof(char));
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = '\n';
		line[i + 1] = '\0';
	}
	else
		line[i] = '\0';
	return (line);
}

static char	*ft_get_leftover(char *str)
{
	char	*rest;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	rest = NULL;
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	j = i;
	while (str[j] != '\0')
		j++;
	if (j != i)
		rest = ft_substr(str, i, j);
	return (rest);
}
