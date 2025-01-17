/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:08:16 by ekashirs          #+#    #+#             */
/*   Updated: 2025/01/17 11:45:28 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	size_t		len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = ft_calloc(1, sizeof (char));
	if (!buffer)
		return (NULL);
	if (!ft_strchr(buffer, '\n'))
		ft_read_line(&buffer, fd);
	if (!buffer || !*buffer)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	len = 0;
	while (buffer[len] != '\n' && buffer[len] != '\0')
		len++;
	line = NULL;
	ft_extract_line(&buffer, &line, len);
	return (line);
}
