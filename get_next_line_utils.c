/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-pra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:14:20 by avan-pra          #+#    #+#             */
/*   Updated: 2019/10/14 11:14:21 by avan-pra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strnew(size_t size)
{
	char *str;
	int i;

	if (!(str = malloc(size)))
		return (NULL);
	i = 0;
	while (i < size)
		str[i++] = '\0';
	return (str); 
}

size_t 	ft_strlen(const char *s)
{
        size_t i;

        if (!s)
                return (0);
        i = 0;
        while (s[i] != '\0')
                i++;
        return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
        char    *str;
        int             i;
        int             j;

        if (!(s1) || !(s2))
                return (NULL);
        if (!(str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char))))
                return (NULL);
        i = 0;
        j = 0;
        while (s1[i] != '\0')
        {
                str[i] = s1[i];
                i++;
        }
        while (s2[j] != '\0')
        {
                str[i] = s2[j];
                i++;
                j++;
        }
        str[i] = '\0';
        return (str);
}

char	*ft_strchr(const char *s, int c)
{
        int i;

        i = 0;
        if (!s)
                return (NULL);
        while (s[i] != c && s[i] != '\0')
                i++;
        if (s[i] == c)
                return ((char*)&s[i]);
        return (NULL);
}
