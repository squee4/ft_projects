#include <unistd.h>

int	main(void)
{
	int num;
	char	aux;

	num = 1;
	while (num <= 100)
	{
		if (num % 15 == 0)
		{
			write(1, "fizzbuzz", 8);
		}
		else if (num % 5 == 0)
		{
			write(1, "buzz", 4);
		}
		else if (num % 3 == 0)
		{
			write(1, "fizz", 4);
		}
		else
		{
			if (num < 10)
			{
				aux = num + '0';
				write(1, &aux, 1);
			}
			else
			{
				aux = (num / 10) + '0';
				write(1, &aux, 1);
				aux = (num % 10) + '0';
				write(1, &aux, 1);
			}
		}
		write(1, "\n", 1);
		num++;
	}
	return (0);
}