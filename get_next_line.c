#include "get_next_line.h"

static char	*break_line(char **nextline, char **tail)
{
	char	*line_end;
	char	*tmp;

	line_end = NULL;
	if (*tail)
	{
		line_end = ft_strchr(*tail, '\n');
		if (line_end == NULL)
		{
			tmp = *nextline;
			*nextline = ft_strdup(*tail);
			free(tmp);
			free(*tail);
			*tail = NULL;
		}
		else
		{
			*line_end = '\0';
			tmp = *nextline;
			*nextline = ft_strdup(*tail);
			free(tmp);
			ft_strcpy(*tail, ++line_end);
		}
	}
	return (line_end);
}

static char	*find_n(char	**line, char *buff, char *line_end, char *tail)
{
	char		*tmp;

	*line_end = '\0';
	tmp = tail;
	tail = ft_strdup(++line_end);
	free(tmp);
	tmp = *line;
	*line = ft_strjoin(*line, buff);
	free(tmp);
	return (tail);
}

static int	fill_from_buff(char	**line, char *buff, int fd)
{
	static char	*tail;
	char		*line_end;
	char		*tmp;
	int			read_bytes;

	line_end = break_line(line, &tail);
	if (line_end)
		return (1);
	read_bytes = read(fd, buff, BUFFER_SIZE);
	while (!line_end && read_bytes > 0)
	{
		buff[read_bytes] = '\0';
		line_end = ft_strchr(buff, '\n');
		if (line_end)
			tail = find_n(line, buff, line_end, tail);
		else
		{
			tmp = *line;
			*line = ft_strjoin(*line, buff);
			free(tmp);
			read_bytes = read(fd, buff, BUFFER_SIZE);
		}
	}
	return (read_bytes);
}

int	get_next_line(int fd, char **line)
{
	static char	*tail;
	int			read_bytes;
	char		*buff;

	if (read(fd, 0, 0) < 0 || line == NULL || BUFFER_SIZE < 1)
		return (-1);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (-1);
	*line = ft_strdup("");
	read_bytes = fill_from_buff(line, buff, fd);
	free(buff);
	if (read_bytes > 0 || ft_strlen(tail))
		return (1);
	if (read_bytes < 0 || !(*line))
		return (-1);
	return (0);
}
