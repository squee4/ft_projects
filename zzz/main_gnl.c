#include "get_next_line.h"
#include "get_next_line_bonus.h"

int	ft_atoi(const char *str);

int	main(int argc, char **argv)
{
	int fd;
	int	iters;
	
	fd = open("prueba.txt", O_RDONLY);
	iters = 0;
	if (argc == 1)
		printf("Introdusí un valor we");
	else
	{
		while (iters < ft_atoi(argv[1]))
		{
			printf("%s", get_next_line(fd));
			printf("%s", get_next_line(fd));
			iters++;
		}
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	num;
	int	sign;
	int	i;

	num = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - 48);
		i++;
	}
	return (num * sign);
}