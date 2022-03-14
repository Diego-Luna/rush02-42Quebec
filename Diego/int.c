/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 18:16:38 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/03/13 20:04:49 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_num_len(int nb)
{
	int	i;
	int	total;

	total = 1;
	i = 0;
	if (nb == 0)
		return (0);
	while (i < nb - 1)
	{
		total *= 10;
		i++;
	}
	return (total);
}

int	ft_get_offset(int number, char *dict)
{
	int	count;
	int	last;
	int	i;

	i = -1;
	last = 0;
	count = 0;
	while (dict[++i])
	{
		if (i == 0 || dict[i] == '\n')
		{
			if (i != 0)
				i++;
			while (dict[i] && dict[i] != ':')
			{
				count++;
				i++;
			}
			i--;
			if (count < number && count >= last)
				last = count;
			count = 0;
		}
	}
	return (number - last);
}

int	ft_get_num(char *str)
{
	int	i;
	int	total;
	int	pow;

	i = 0;
	pow = 1;
	total = 0;
	while (str[i] && str[i] != ':')
		i++;
	i--;
	while (i > -1)
	{
		total += (str[i] - 48) * pow;
		pow *= 10;
		i--;
	}
	return (total);
}