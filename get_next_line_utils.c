#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strchr(const char *str, int ch)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)ch)
			return ((char *)str + i);
		i++;
	}
	if (ch == '\0')
		return ((char *)str + i);
	return (NULL);
}

char	*ft_strdup(const char *src)
{
	int		s;
	char	*dup;
	int		i;

	i = 0;
	s = 0;
	while (src[s] != '\0')
		s++;
	dup = (char *)malloc(sizeof(char) * (s + 1));
	if (dup == NULL)
		return (NULL);
	while (i < s)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*join;

	i = 0;
	j = 0;
	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (join == NULL)
		return (NULL);
	while (s1 != NULL && s1[i] != '\0')
	{
		join[i] = s1[i];
		i++;
	}
	while (s2 != NULL && s2[j] != '\0')
	{
		join[i + j] = s2[j];
		j++;
	}
	join[i + j] = '\0';
	return (join);
}
