/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chartablength.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwagner <cwagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 16:19:19 by cwagner           #+#    #+#             */
/*   Updated: 2014/01/21 16:20:27 by cwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_chartablength(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}