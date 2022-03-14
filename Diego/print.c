/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 18:25:40 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/03/13 22:19:43 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_na_nu(char *dict, int nb);
void	ft_print_more_1(char *num, int *number, int *retval);
void	ft_print_more_2(char *num, int *number, char *printnum, char *dict);

void	ft_pri_n(char *number, int highest)
{
	int	i;

	i = 0;
	while (number[i] && number[i] != '\n')
	{
		write(1, &number[i], 1);
		i++;
	}
	if (highest != 1)
		write(1, " ", 1);
}

void	ft_print_more(char *dict, int multi)
{
	char	*number;

	number = ft_na_nu(dict, multi);
	ft_pri_n(number, multi);
}

void	ft_print_int(char c, char *number, char *dict, int highest)
{
	int		i;
	char	*unit;

	i = 0;
	if (c >= 48 && c <= 57)
	{
		if (c != 48)
		{
			unit = ft_na_nu(dict, c - 48);
			ft_pri_n(unit, highest);
			if (highest != 1)
			i = 0;
		}
		if (highest != 1)
			ft_pri_n(number, highest);
	}
}

int	ft_print_set(int offset, char *dict, char *num, int highest)
{
	int		number;
	char	*printnum;
	int		retval;

	number = (num[0] - 48);
	retval = 0;
	printnum = NULL;
	if (offset == 1 && num[0] != '0')
	{
		if (num[0] == '1')
			ft_print_more_1(num, &number, &retval);
		else
			ft_print_more_2(num, &number, printnum, dict);
	}
	else if (offset == 2 && num[0] != '0')
	{
		printnum = ft_na_nu(dict, number);
		ft_pri_n(printnum, highest);
		printnum = ft_na_nu(dict, 100);
	}
	else if (num[0] != '0')
		printnum = ft_na_nu(dict, number);
	if (num[0] != '0')
		ft_pri_n(printnum, highest);
	return (retval);
}
