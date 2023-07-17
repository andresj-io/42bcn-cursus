/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:12:26 by ajacome-          #+#    #+#             */
/*   Updated: 2023/07/17 15:29:39 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef enum e_printf_formats
{
	character,
	string,
	pointer,
	decimal,
	integer,
	unsigned_i,
	hex_lower,
	hex_upper,
	percent,
}	t_printf_formats;

typedef struct s_printf
{
	t_printf_formats format;
	void	*content;
}	t_printf;

#endif