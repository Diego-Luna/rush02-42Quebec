/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:31:10 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/03/13 19:49:16 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

// string.c
char	*ft_get_file(int fildes);

// main_logic.
void	ft_main_logic(char *num, char *dict);

int	main(int argc, char **argv)
{
	int		fildes;
	char	*k;
	char	*name;
	int		i;

	i = 0;
	if (argc >= 2 && argc <= 3)
	{
		if (argc == 3)
		{
			fildes = open(argv[2], O_RDONLY);
		}
		else
		{
			fildes = open("numbers.dict", O_RDONLY);
		}
		k = ft_get_file(fildes);
		ft_main_logic(argv[1], k);
	}
	write(1, "\n", 1);
}
