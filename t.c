#include <stdio.h>
#include "Libft/libft.h"

int	main(int ac, char **av)
{
	printf("atol_base de av[1] = %ld\n", ft_atol_base(av[1], "0123456789abcdef"));
	//printf("ft_atoi de av[1] = %d\n", ft_atoi(av[1]));
}
