/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   util_atoi.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 17:00:50 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/09 15:30:10 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	util_atoi(const char *str)
{
	int				i;
	unsigned long	result;
	int				sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	sign = (str[i] == '+') - (str[i] == '-');
	i += !!sign;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (sign == 1 && result >= 9223372036854775807)
		return (-1);
	if (sign == -1 && result > 9223372036854775807)
		return (0);
	return ((int)(result * (sign + !sign)));
}
