/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-pra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:09:45 by avan-pra          #+#    #+#             */
/*   Updated: 2019/10/14 11:09:47 by avan-pra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 9999
#include <string.h>

void	ft_save(char *s, char *save)
{
	int i;
	int j;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	s[i] = '\0';
	j = 0;
	i++;
	while (s[i] != '\0')
	{
		save[j] = s[i];
		i++;
		j++;
	}
	save[j] = '\0';
}

int		read_line(int fd, char **gnl, char *save)
{
	int		ret;
	char	*tmp;
	char	buf[BUFFER_SIZE + 1];
	int		i;

	tmp = *gnl;
	*gnl = ft_strjoin(*gnl, save);
	free(tmp);
	ret = 1;
	i = 0;
	while (!(ft_strchr(*gnl, '\n')) && ret)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret > 0)
		{
			buf[ret] = '\0';
			tmp = *gnl;
			*gnl = ft_strjoin(*gnl, buf);
			free(tmp);
			i = 1;
		}
	}
	//printf("		gnl = %s\n", *gnl);
	//printf("		sav = %s\n", save);
	ft_save(*gnl, save);
	printf("		gnl = %s\n", *gnl);
	printf("		sav = %s\n", save);
	if (i == 1)
		return (1);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char *gnl;
	char *tmp;
	int ret;
	static char save[BUFFER_SIZE + 1];

	//printf("save = %s\n", save);
	if (!(gnl = ft_strnew((BUFFER_SIZE + 1) * sizeof(char))))
		return (-1);
	ret = read_line(fd, &gnl, save);
	*line = gnl;
	printf("		ret = %d\n", ret);
	//printf("		%s\n", gnl);
	//printf("		%s\n", save);
	if (ret > 0)
		return (1);
	return (0);
}

int	main(void)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open("test.txt", O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}