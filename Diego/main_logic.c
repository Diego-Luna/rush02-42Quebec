/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 18:20:51 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/03/13 20:03:36 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// string.c
int	ft_strlen(char *str);
char	*ft_get_name_num(char *dict, int nb);

// int.c
int	ft_num_len(int nb);
int	ft_get_offset(int number, char *dict);

// print.c
void	ft_print_num(char *number, int highest);
void	ft_print_int(char c, char *number, char *dict, int highest);
int	ft_print_set(int offset, char *dict, char *num, int highest);
void	ft_print_more(char *dict, int multi);

void	ft_main_logic(char *num, char *dict)
{
	int		i;
	int		offset;
	int		highest;
	char	*number;

	highest = ft_num_len(ft_strlen(num));
	i = 0;
	if (highest == 1 && num[i] == '0')
	{
		ft_print_num(ft_get_name_num(dict, 0), highest);
		return ;
	}
	while (i < ft_strlen(num))
	{
		if (highest == 10)
		{
			if (num[i] == '1')
			{
				ft_print_num(ft_get_name_num(dict, 10 + (num[i + 1] - 48)), highest);
				i++;
			}
			else if (num[i] >= '2')
				ft_print_num(ft_get_name_num(dict, highest * (num[i] - 48)), highest);
			i++;
			highest = ft_num_len(ft_strlen(&num[i]));
		}
		if (highest == 1)
			number = ft_get_name_num(dict, highest * (num[i] - 48));
		else
			number = ft_get_name_num(dict, highest);
		if (number != NULL)
		{
			if (num[i] != '0')
			{
				ft_print_int(num[i], number, dict, highest);
			}
			i++;
			highest = ft_num_len(ft_strlen(&num[i]));
		}
		else
		{
			offset = ft_get_offset(ft_strlen(&num[i]), dict);
			while (offset != -1)
			{
				if (ft_print_set(offset, dict, &num[i], highest))
				{
					i++;
					offset--;
				}
				i++;
				offset--;
			}
			i--;
			highest = ft_num_len(ft_strlen(&num[i]));
			number = ft_get_name_num(dict, highest);
			if (num[i] != '0' || num[i - 1] != '0' || num[i - 2] != '0')
				ft_print_more(dict, highest);
			i++;
			highest = ft_num_len(ft_strlen(&num[i]));
		}
	}
}