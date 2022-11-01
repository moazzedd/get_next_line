/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:19:17 by moazzedd          #+#    #+#             */
/*   Updated: 2022/11/01 23:06:08 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//check if tthr line contain \n whille he dosen't arrive to \0
int	check_new_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

//read the line every time the previous dosen't containa new line and return it
char	*read_line(int fd, char *str)
{
	char	*stock;
	int		lenght_line;

	lenght_line = 1;
	stock = malloc(BUFFER_SIZE + 1);
	while (check_new_line(str) == 0 && lenght_line)
	{
		lenght_line = read(fd, stock, BUFFER_SIZE);
		if (lenght_line == -1)
		{
			free (stock);
			return (NULL);
		}
		stock[lenght_line] = '\0';
		str = ft_strjoin(str, stock);
	}
	free (stock);
	return (str);
}

/*our line may have tow line for that 
we cut it till new line from 0 till new line*/
char	*before_new_line(char *str)
{
	int		i;
	char	*temp;

	i = 0;
	if (!str[0])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	temp = ft_substr(str, 0, i + 1);
	return (temp);
}

/*our line can contain two line the first will cut it 
with before function and th second line 
or that part of it we wil cut it by iterer on the line ,
we found new line we will cut it from new
line till end and return it*/
char	*after_new_line(char *str)
{
	int		i;
	char	*temp;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\n')
		{
			temp = ft_substr(str, i + 1, ft_strlen(str));
			free (str);
			return (temp);
		}
		i++;
	}
	free (str);
	return (NULL);
}

/*read untill the previous line dosen't contain new 
line cut the first line and return it
 and put the second or the part of the second in 
 static str that we will use it again*/
char	*get_next_line(int fd)
{
	static char	*str;
	char		*before;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = read_line(fd, str);
	if (!str)
		return (NULL);
	before = before_new_line(str);
	str = after_new_line(str);
	return (before);
}

int main(int ac, char **av)
{
	get_next_line(av[1]);
}