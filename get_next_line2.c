#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

/*char *readfile(char *str, int fd)
{
    int BUFFER_SIZE;
    char buf[BUFFER_SIZE + 1];
    int red;
    while (red = read(fd,  buf, BUFFER_SIZE) == 0)
    {
        buf[red] = '\0';

    }
}*/
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
	if (!s1 || !s2)
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
	dest[i + j] = '\0';
	return (dest);
}

int main()
{
int fd;
char *str;
str = malloc (sizeof(char));
//*str = 0;
char buf[10];
int rd;
//char *tmp;
fd = open ("file.txt", O_RDWR | O_CREAT);
/*rd = read(fd, buf, 3);
buf[rd] = '\0';
printf ("%s\n", buf);
rd = read(fd, buf, 3);
buf[rd] = '\0';
printf ("%s\n", buf);
rd = read(fd, buf, 3);
//buf[rd] = '\0';
printf ("%s\n", buf);*/
while (rd = read (fd, buf, 3))
{
    buf[rd] = 0;
    //tmp = str;
    str = ft_strjoin (str, buf);
    //free (tmp);
}
printf ("%s\n", str);
system ("leaks a.out");
}
 //system ("leaks a.out");