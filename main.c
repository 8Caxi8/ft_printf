#include "ft_printf.h"
#include <stdio.h>

int main()
{
	size_t	i;
	size_t	j;

	j = printf("Ola tudo |%05.5d| bem?\n", -42);
	//i = ft_printf("Ola tudo |%-15p| bem?\n", "Olaa");
	printf("i:%lu, j:%lu", i, j);
	return (0);
}
