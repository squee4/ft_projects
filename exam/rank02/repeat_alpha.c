#include <unistd.h>

void	awebo(char *set, char c)
{
	int z;
	int	times;

	z = 0;
	times = 0;
	while (set[z])
	{
		if (set[z] == c)
		{
			while (times < (z + 1))
			{
				write(1, &c, 1);
				times++;
			}
		}
		z++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	z;
	int	times;
	char	*str;
	char	*alphalow;
	char	*alphaup;

	i = 0;
	alphalow = "abcdefghijklmnopqrstuvwxyz";
	alphaup = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	if (argc == 2)
	{
		str = argv[1];
		while (str[i])
		{
			times = 0;
			z = 0;
			if (str[i] >= 'a' && str[i] <= 'z')
				awebo(alphalow, str[i]);
			else if (str[i] >= 'A' && str[i] <= 'z')
				awebo(alphaup, str[i]);
			else
				write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}