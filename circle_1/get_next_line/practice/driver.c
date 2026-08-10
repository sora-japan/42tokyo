#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
char	*get_next_line(int fd);

int	main(int ac, char **av)
{
	int		fd;
	char	*line;
	int		i;

	fd = (ac > 1) ? open(av[1], O_RDONLY) : 0;
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("[%d] \"%s\"\n", i++, line);
		free(line);
	}
	printf("--- %d 行で終了 ---\n", i);
	if (fd > 0)
		close(fd);
	return (0);
}
