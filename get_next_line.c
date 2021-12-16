#include <stdio.h>
#include "get_next_line.h"

char *print_line(char *str)
{
	char *line;
	int i = 0;
	if (str[0] == '\0')
		return (0);
	while(str[i] != '\n' && str[i])
		i++;
	line = malloc((i + 2) * sizeof(char));
	ft_strlcpy(line, str, i + 2);
	line[i + 2] = '\0';
	return(line);
}

char *readfile(int fd)
{
	int j = 0;
	static char *str = 0;
	char *line;
    char buf[BUFFER_SIZE + 1];
    int read_size = 1;
	char *l;
    while (read_size && !(ft_strchr(str, '\n')))
    {
		read_size = read(fd,  buf, BUFFER_SIZE);
		if (read_size == -1)
			return (0);
        buf[read_size] = '\0';
		l = str;
        str = ft_strjoin(str, buf);
		free (l);
    }
	if (read_size == 0 && (!str || !str[0]))
		return(0);
	line = print_line(str);
	while(str[j] != '\n' && str[j] != '\0')
		j++;
	char *p;
	p = str;
	str = ft_substr(str,j+1,ft_strlen(str) - j);
	free (p);
	
    return(line);
}
char *get_next_line(int fd)
{
	if (fd < 0 || BUFFER_SIZE < 1)
		return(NULL);
	return (readfile(fd));
} 

int	main()
{
	int fd =  open ("file", O_RDONLY);
	printf ("%s", readfile(fd));
	printf ("%s", readfile(fd));
	printf ("%s", readfile(fd));
	printf ("%s", readfile(fd));
	printf ("%s", readfile(fd));
	printf ("%s", readfile(fd));
}