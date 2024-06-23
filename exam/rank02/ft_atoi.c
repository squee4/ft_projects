#include <stdio.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int sign;

	i = 0;
	num = 0;
	sign = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		num = (num * 10) + (str[i++] - 48);
	return (num * sign);
}
