#include <stdio.h>
#include <stdlib.h>
char	*ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

int	main()
{
	char *src = "HOLA hola";
	char *dst = malloc(2);

	ft_strcpy(dst, src);
	printf("%s", dst);
}