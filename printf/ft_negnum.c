#include "libftprintf.h"

long	ft_negnum(long n)
{
	if (n < 0)
		return (-n);
	return (n);
}
