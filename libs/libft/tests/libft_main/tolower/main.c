#include <stdio.h>
#include <ctype.h>
#include "../libft.h"

int main()
{
int i = 0;
char c;
char str[] = "TUTORIALS POINT";
while( str[i] )
{
putchar(ft_tolower(str[i]));
i++;
}
return(0);
}