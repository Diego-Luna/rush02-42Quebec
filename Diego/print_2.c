/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 22:20:01 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/03/13 22:24:51 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_na_nu(char *dict, int nb);

void	ft_print_more_1(char *num, int *number, int *retval)
{
		*number = ((num[0] - 48) * 10) + (num[1] - 48);
		*retval = 1;
}

void	ft_print_more_2(char *num, int *number, char *printnum, char *dict)
{
	*number = (num[0] - 48) * 10;
	printnum = ft_na_nu(dict, *number);
}
