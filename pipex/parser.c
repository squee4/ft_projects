#include <unistd.h>
#include <stdio.h>

char	**ft_get_args(char *str)
{
	int		i;
	int		wc;
	char	**ret;

	i = 0;
	wc = words(str);
	ret = malloc((wc + 1) * sizeof(char *));
	
	while (str[i])
	{
		if (ft_isalnum(str[i]))
	}
	
}

int	main(int argc, char **argv, char **envp)
{
	if (argc == 2)
	{

	}
	else
		printf("No arg");
	return (0);
}
