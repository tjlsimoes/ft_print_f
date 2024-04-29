#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	// ft_printf("Hello World!");
	// ft_printf("Hello %!");
	// ft_printf("Hello %%!");
	// ft_printf("Hello %%%!");
	// ft_printf("%%%%");
	// ft_printf("%%%%%%");
	// ft_printf("%%%%%%%");
	// ft_printf("%%%%%%%%");
	// ft_printf("%%%%%%%%%");
	// ft_printf("%%%%%%%%%%");
	// ft_printf("%%%%%%%%%%c");
	// ft_printf("%%%%%%%%%%d");
	// ft_printf("%%%%%%%%%%%");

	// ft_printf("Hello %s!\n", "42");
	// ft_printf("Hello %s! %s\n", "42", "Bye!");
	// ft_printf("Hello %s! This is char %c!\n", "42", 'c');
	// ft_printf("Hello %s! This is char %c! And this is number %d!\n", "42", 'c', 42);
	// ft_printf("Hello %s! This is char %c! And this is number %d!\n", "42", 'c', -42);
	// ft_printf("Int: %d!\n", INT_MIN);
	// ft_printf("Hello %s! Int: %d! Percent sign: %%\n", "42", -42);
	//  ft_printf("Hello %s! Hex lowercase: %x!\n", "42", 42);
	//  ft_printf("Hello %s! Hex lowercase: %x!\n", "42", 32); // 20
	//  ft_printf("Hello %s! Hex lowercase: %x!\n", "42", 0); // 2a
	// 	ft_printf("Hello %s! Hex uppercase: %X!\n", "42", 42);
	// ft_printf("%s! %d! Unsigned int: %u\n", "42", -42, -42); // 4294967254
	// int i = 4;
	// printf("%p %p %p %p\n", "hello", &i, NULL, (void *)0);
	// ft_printf("%p %p %p %p\n", "hello", &i, NULL, (void *)0);
	
	// printf("%d\n", ft_printf("Hello %s! Hex uppercase: %X!\n", "42", 42));
	// printf("%d\n", printf("Hello %s! Hex uppercase: %X!\n", "42", 42));

	// printf("%d\n", ft_printf("Hello World!\n"));
	// printf("%d\n", printf("Hello World!\n"));

	// printf("%d\n", ft_printf("%%%%%%\n"));
	// printf("%d\n", ft_printf("%%%%%%\n"));

	// printf("%d\n", ft_printf("Hello %s! %s\n", "42", "Bye!"));
	// printf("%d\n", printf("Hello %s! %s\n", "42", "Bye!"));
	
	// printf("%d\n", ft_printf("Hello %s! Hex lowercase: %x!\n", "42", 32));
	// printf("%d\n", printf("Hello %s! Hex lowercase: %x!\n", "42", 32));

	// printf("%d\n", ft_printf("Hello %s! %c! %d!\n", "42", 'c', -42));
	// printf("%d\n", printf("Hello %s! %c! %d!\n", "42", 'c', -42));

	// printf("%d\n", ft_printf("Hello %s! %d! %u\n", "42", -42, -42));
	// printf("%d\n", printf("Hello %s! Int: %d! %u\n", "42", -42, -42));

	// printf("%d\n", ft_printf("%p %p %p %p\n", NULL, NULL, NULL, NULL));
	// printf("%d\n", printf("%p %p %p %p\n", NULL, NULL, NULL, NULL));

	// long long i;
	// i = 0;
	// i = 1;
	// i = LONG_MIN;
	// i = LONG_MAX;
	// i = ULONG_MAX;
	// i = -ULONG_MAX;
	// i = -1;
	// i = ULLONG_MAX;
	// i = -ULLONG_MAX;
	// i = LLONG_MIN;

	// printf("%p\n", &i);
	// ft_printf("%p\n", &i);

	// printf("%p\n", (void *)i);
	// ft_printf("%p\n", (void *)i);


	// printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	// printf("\n");
	// ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);


	// ft_printf("Hello!\n");

	ft_printf("%c small string", 'a');


	return (0);
}
