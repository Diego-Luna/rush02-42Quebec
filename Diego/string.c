/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:18:53 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/03/13 21:41:58 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int		ft_get_num(char *str);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_get_file(int fildes, int i, char *name_file)
{
	int		total;
	char	tempbuf[64];
	int		readsz;
	char	*out;

	total = 0;
	readsz = -1;
	while (readsz != 0)
	{
		readsz = read(fildes, tempbuf, 64);
		total += readsz;
	}
	out = malloc(total + 1);
	close(fildes);
	if (i == 1)
		open(name_file, O_RDONLY);
	else
	{
		open("numbers.dict", O_RDONLY);
	}
	read(fildes, out, total + 1);
	out[total + 2] = 0;
	return (out);
}

char	*ft_na_nu(char *dict, int nb)
{
	int	i;

	i = 0;
	while (dict[i])
	{
		if (i == 0 || dict[i - 1] == '\n')
		{
			if (ft_get_num(&dict[i]) == nb)
			{
				while (dict[i] && dict[i] != ':')
				{
					i++;
				}
				return (&dict[i + 2]);
			}
		}
		i++;
	}
	return (NULL);
}

int	ft_cheak(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			return (0);
		}
	i++;
	}
	return (1);
}
