/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 18:25:40 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/03/13 20:03:36 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_get_name_num(char *dict, int nb);

void	ft_print_num(char *number, int highest)
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

	number = ft_get_name_num(dict, multi);
	ft_print_num(number, multi);
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
			unit = ft_get_name_num(dict, c - 48);
			ft_print_num(unit, highest);
			if (highest != 1)
			i = 0;
		}
		if (highest != 1)
			ft_print_num(number, highest);
	}
}

int	ft_print_set(int offset, char *dict, char *num, int highest)
{
	int		number;
	char	*printnum;
	int		retval;

	number = (num[0] - 48);
	retval = 0;
	if (offset == 1 && num[0] != '0')
	{
		if (num[0] == '1')
		{
			number = ((num[0] - 48) * 10) + (num[1] - 48);
			retval = 1;
		}
		else
			number = (num[0] - 48) * 10;
		printnum = ft_get_name_num(dict, number);
	}
	else if (offset == 2 && num[0] != '0')
	{
		printnum = ft_get_name_num(dict, number);
		ft_print_num(printnum, highest);
		printnum = ft_get_name_num(dict, 100);
	}
	else if (num[0] != '0')
		printnum = ft_get_name_num(dict, number);
	if (num[0] != '0')
		ft_print_num(printnum, highest);
	return (retval);
}