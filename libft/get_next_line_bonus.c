/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abimkhio <abimkhio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:53:31 by abimkhio          #+#    #+#             */
/*   Updated: 2023/10/05 15:53:34 by abimkhio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read(int fd, char *str)
{
	char	*array;
	int		bytes;

	array = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!array)
		return (NULL);
	bytes = -1;
	while (!ft_strchr(str, '\n') && bytes != 0)
	{
		bytes = read(fd, array, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(array);
			return (NULL);
		}
		array[bytes] = '\0';
		str = ft_free_join(str, array);
	}
	free(array);
	return (str);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*s[FOPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s[fd] = ft_read(fd, s[fd]);
	if (!s[fd])
		return (NULL);
	line = ft_get_line(s[fd]);
	s[fd] = ft_new_line(s[fd]);
	return (line);
}

/* int main()
{
	int fd = open("a.txt", OPEN_MAX);
    int fd2 = open("b.txt", OPEN_MAX);
    int fd3 = open("c.txt", OPEN_MAX);

	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd3));
	printf("%s", get_next_line(fd));

	return 0;
}  */ 