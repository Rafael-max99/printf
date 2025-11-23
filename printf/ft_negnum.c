#include "libftprintf.h"

int	ft_negnum(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}
