#include <stdio.h>
#include <string.h>
#include "Libft/libft.h"

int	main() // tester si le malloc a l'interieur de struct est quand meme transfere dans le parametre struct
{
	char	*str;
	int	a;

	str = ft_strdup("     00  0 01 0 1 00    ");
	//vscode printf("str = %s\n", str);
	str = ft_strtrim(str, " ");
	//vscode printf("str = %s\n", str);
	a = 1;
	if (!a)
		//vscode printf("vrai");
	else
		//vscode printf("faux");
}
