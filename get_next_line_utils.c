#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*dest;
	size_t		len;
	int			i;
	int			j;

	j = 0;
	i = 0;
	if (!s1 && s2)
		return(ft_strdup(s2));
	if ((!s1 && !s2) || (!s1[0] && !s2[0]))
		return (0);
	
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	dest = (char *) malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (0);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	return (dest);
}
char	*ft_strchr(const char *s, int c)
{
	char	*k;
	int		i;

	if (!s)
		return(NULL);
	i = 0;
	k = (char *)s;
	c = (char)c;
	if (c == '\0')
		return (k + ft_strlen(k));
	while (k[i] != '\0')
	{
		if (k[i] == c)
			return (k + i);
		i++;
	}
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char	*s;
	size_t	i;
	int		dlen;
	int		slen;

	i = 0;
	s = (char *)src;
	dlen = ft_strlen(dst);
	slen = ft_strlen(s);
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = s[i];
			i++;
		}
	dst[i] = '\0';
	}
	return (slen);
}
char	*ft_strdup(const char *s1)
{
	char	*s;
	char	*str;
	int		i;

	i = 0;
	s = (char *)s1;
	str = malloc (sizeof(char) * ft_strlen(s) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *src, unsigned int start, size_t len)
{
	char		*dest;
	size_t		i;

	i = 0;
	if (!src)
		return (0);
	if (!*src || len == 0 || ft_strlen((char *) src) <= start)
		return (ft_strdup(""));                   
	if (len > ft_strlen((char *)src))
		len = ft_strlen((char *)src) - start;
	dest = malloc(sizeof(char) * len + 1);
	if (dest == 0)
		return (0);
	while (src[i + start] && i < len)
	{
		dest[i] = src[i + start];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
