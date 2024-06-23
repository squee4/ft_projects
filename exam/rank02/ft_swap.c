#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int main ()
{
	int uno = 1;
	int	nueve = 9;
	ft_swap(&uno, &nueve);
	printf("%d-", uno);
	printf("%d-", nueve);
	return (0);
}