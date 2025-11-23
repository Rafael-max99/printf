#include "libftprintf.h"

void	ft_toupper(char *str)
{
	int	pos;

	pos = 0;
	while (str[pos])
	{
		if (str[pos] >= 'a' && str[pos] <= 'z')
			str[pos] -= 32;
		pos++;
	}
}
