#include <stdio.h>
#include <unistd.h>

int	isnumber(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	miniatoi(char *str)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (str[i])
		num = (num * 10) + (str[i++] - 48);
	return (num);
}

int	isprime(int	num)
{
	int div;

	div = num/2;
	if (num == 2)
		return (1);
	if (num == 1 || num % 2 == 0)
		return (0);
	while (div > 1)
	{
		if(num % div == 0)
			return (0);
		div--;
	}
	return (1);
}

void	putnbr(int num)
{
	char	list[999];
	int	i;

	i = 0;
	while (num > 9)
	{
		list[i] = (num % 10) + 48;
		num = num / 10;
		i++;
	}
	list[i] = num + 48;
	while (i >= 0)
		write(1, &list[i--], 1);
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int	num;
	int	sum;
	char	*print;

	sum = 0;
	if (argc == 2 && isnumber(argv[1]))
	{
		num = miniatoi(argv[1]);
		while (num > 1)
		{
			if (isprime(num))
				sum += num;
			num--;
		}
		putnbr(sum);
	}
	else
		write(1, "0\n", 2);
	return (0);
}
