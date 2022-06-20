/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <nspeedy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:51:14 by nspeedy           #+#    #+#             */
/*   Updated: 2022/06/20 13:44:53 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	t_data	d;	
	int		new_p[2];
	int		old_p[2];

	d.cmdline = readline("> ");
	while (d.cmdline != NULL)
	{
		d.arglist = ft_split(d.cmdline, '|');
		exsit(d.cmdline, d.arglist);
		if (d.arglist != NULL)
		{
			add_history(d.cmdline);
			if (manage(&d, old_p, new_p) == 1)
				return (1);
			free_strarray(d.arglist);
		}
		free(d.cmdline);
		d.cmdline = readline("> ");
	}
	return (0);
}
