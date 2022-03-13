/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:31:10 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/03/13 14:57:12 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str);

int	max_lenght;
char *words;

int	main(int arg, char **strs)
{
	int dict;
	char *all_dict;
	if (arg == 2)
	{
		dict = open("numbers.dict", O_RDONLY);
	}
	else
	{
		write(1, "error", 5);
	}
	write(1, "\n", 1);
}
