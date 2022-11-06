/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 03:06:05 by moazzedd          #+#    #+#             */
/*   Updated: 2022/11/06 03:06:32 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	int		i;
	int		j;
	int		s1_lenght;
	int		s2_lenght;

	i = -1;
	j = -1;
	s1_lenght = ft_strlen(s1);
	s2_lenght = ft_strlen(s2);
	ptr = malloc(sizeof(char) * (s1_lenght + s2_lenght + 1));
	if (!ptr)
		return (NULL);
	while (++i < s1_lenght)
		ptr[i] = s1[i];
	while (++j < s2_lenght)
		ptr[i++] = s2[j];
	ptr[i] = '\0';
	free(s1);
	return (ptr);
}

char	*ft_strdup(char *s1)
{
	int		s1_lenght;
	char	*ptr;
	int		i;

	s1_lenght = ft_strlen(s1);
	ptr = (char *)malloc(s1_lenght * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	while (i < len && s[start + i])
		i++;
	ptr = (char *)malloc(sizeof(char) * i + 1);
	if (!ptr)
		return (NULL);
	while (j < i)
	{
		ptr[j] = s[start + j];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}
