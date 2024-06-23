#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	char	*str;

	i = 0;
	if (argc == 2)
	{
		str = argv[1];
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		while (str[i])
		{
			if (str[i] != ' ' && str[i] != '\t')
				write(1, &str[i], 1);
			else
				break;
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}