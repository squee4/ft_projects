#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	size;
	int	aux;
	int	i;
	int	*ret;

	size = 0;
	aux = start;
	i = 0;
	while (aux <= end)
	{
		aux++;
		size++;
	}
	ret = malloc(sizeof(int) * (size + 1));
	if (!ret)
		return (0);
	aux = start;
	while (i < size)
	{
		ret[i] = aux;
		aux++;
		i++;
	}
	ret[i] = 0;
	return (ret);
}

int	main()
{
	int	*list;
	int	i;

	i = 0;
	list = ft_range(-2,10);
	while (list[i] != 0)
		printf("%d-", list[i++]);
	i++;
	while (list[i] != 0)
		printf("%d-", list[i++]);
	return (0);
}