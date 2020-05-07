#include <stdio.h>
#include "Libft/libft.h"

int	main()
{
	char	*str;

	str = ft_strdup("     00  0 01 0 1 00    ");
	printf("str = %s\n", str);
	str = ft_strtrim(str, " ");
	printf("str = %s\n", str);
}
