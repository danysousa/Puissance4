/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 10:51:09 by emcoutel          #+#    #+#             */
/*   Updated: 2014/03/09 16:45:41 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

int			ft_strlen(char *s)
{
	int		len;

	len = 0;
	if (s)
		while (s[len])
			len++;
	return (len);
}

int			ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int			ft_putstr(char *s)
{
	if (s)
		write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}

int			ft_putsstr(char **ss)
{
	int		i;

	i = 0;
	if (ss[i])
	{
		while (ss[i])
		{
			ft_putstr(ss[i]);
			i++;
		}
	}
	return ((i - 1) * ft_strlen(ss[i - 1]));
}

int			ft_puterror(char *s)
{
	if (s)
		write(2, s, ft_strlen(s));
	return (-1);
}
