#include "libftprintf.h"

int	ft_numlen(long num)
{
	int	len;

	len = 0;
	if (num <= 0)
		len = 1;
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}
