#include <unistd.h>
int	islower(int c)
{
	return (c >= 'a' && c <= 'z');
}

int	isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}

int	main(int argc, char **argv)
{
	int	i;
	int	z;
	char	c;

	i = 1;
	if(argc > 1)
	{
		while (argv[i])
		{
			z = 0;
			while (argv[i][z])
			{
				c = argv[i][z];
				if (islower(c))
				{
					if (argv[i][z + 1] == ' ' || argv[i][z + 1] == 0)
					{
						c -= 32;
						write(1, &c, 1);
					}
					else
						write(1, &c, 1);
				}
				else if (isupper(c))
				{
					if (argv[i][z + 1] == ' ' || argv[i][z + 1] == 0)
						write(1, &c, 1);
					else
					{
						c += 32;
						write(1, &c, 1);
					}
				}
				else
					write(1, &c, 1);
				z++;
			}
			write(1, "\n", 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}