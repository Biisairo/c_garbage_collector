#include "garbage_collector.h"
#include <stdio.h>

int main()
{
	// char *a = ft_malloc(sizeof(char));
	char *b = ft_malloc(sizeof(char) * 2);
	// char *c = ft_malloc(sizeof(char));
	// a = 0;
	b[0] = 'a';
	b[1] = 0;
	printf("0. %p\n", b);
	ft_free(b);
	free(b);
	// c = 0;
	// ft_clear();
	// system("leaks a.out");
}
