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
#define BUFFER_SIZE 3

void	ft_save(char *s, char *save)
{
	int i;
	int j;
	int k;

	i = 0;
	k = ft_strlen(s);
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	s[i] = '\0';
	j = 0;
	i++;
	while (i < k && s[i] != '\0')
	{
		save[j] = s[i];
		i++;
		j++;
	}
	save[j] = '\0';
}

int		read_line(int fd, char **gnl, char *save, int ret)
{
	char	*tmp;
	char	buf[BUFFER_SIZE + 1];
	//int		i;

	//i = 0;
	while (!(ft_strchr(*gnl, '\n')) && ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
			return (-1);
		if (ret > 0)
		{
			buf[ret] = '\0';
			tmp = *gnl;
			*gnl = ft_strjoin(*gnl, buf);
			free(tmp);
			//i = 1;
		}
	}
	ft_save(*gnl, save);
	//if (ret == 0)
	//	save[0] = '\0';
	//if (i == 1)
	//	return (1);
	if (ret > 0)
		return (1);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char		*gnl;
	char		*tmp;
	int			ret;
	static char	save[BUFFER_SIZE + 1];
	//int			i;

	if (fd < 0 || BUFFER_SIZE < 0 || !line)
		return (-1);
	//i = 0;
	if (!(gnl = ft_strnew((BUFFER_SIZE + 1) * sizeof(char))))
		return (-1);
	tmp = gnl;
	//if (ft_strlen(save) > 0)
	//	i = 1;
	gnl = ft_strjoin(gnl, save);
	free(tmp);
	ret = read_line(fd, &gnl, save, 1);
	if (ret < 0)
		return (-1);
	*line = gnl;
	if (ret > 0) // || i == 1)
		return (1);
	return (0);
}

int		main(void)
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
	//printf("derniere ligne = %s\n", line);
	//printf("%d\n", get_next_line(fd, NULL));
	close(fd);
	return (0);
}
