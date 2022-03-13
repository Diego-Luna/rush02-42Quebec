/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:18:53 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/03/13 13:18:57 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	counter;
	int	index;

	counter = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[counter] != '\0')
	{
		index = 0;
		while (str[counter + index] == to_find[index])
		{
			if (to_find[index + 1] == '\0')
				return (str + counter);
			index++;
		}
		counter++;
	}
	return (0);
}
