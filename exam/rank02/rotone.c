#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int i;
	char	*str;
	char	c;
	char	*lowset;
	char	*upset;

	i = 0;
	lowset = "bcdefghijklmnopqrstuvwxyza";
	upset = "BCDEFGHIJKLMNOPQRSTUVWXYZA";
	if (argc == 2)
	{
		str = argv[1];
		while (str[i])
		{
			if(str[i] >= 'a' && str[i] <= 'z')
			{
				c = lowset[str[i] - 97];
				write(1, &c, 1);
			}
			else if(str[i] >= 'A' && str[i] <= 'Z')
			{
				c = upset[str[i] - 65];
				write(1, &c, 1);
			}
			else
			{
				write(1, &str[i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}