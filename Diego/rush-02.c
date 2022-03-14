/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:31:10 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/03/13 21:09:18 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

char	*ft_get_file(int fildes, int i, char *name_file);
void	ft_main_logic(char *num, char *dict);
int    ft_cheak(char *str);

int	main(int argc, char **argv)
{
	int		archive;
	char	*p;

	if ((argc >= 2 && argc <= 3)&& ft_cheak(argv[1]))
	{
		if (argc == 3)
		{
			archive = open(argv[2], O_RDONLY);
			p = ft_get_file(archive, 1, argv[2]);
		}
		else
		{
			archive = open("numbers.dict", O_RDONLY);
			p = ft_get_file(archive, 0, argv[1]);
		}
		ft_main_logic(argv[1], p);
	}
	else
	{
		write(1, "Dict Error", 10);
	}
	write(1, "\n", 1);
}
