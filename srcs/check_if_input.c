/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:17:42 by lazrossi          #+#    #+#             */
/*   Updated: 2018/02/21 16:19:08 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		check_if_input(int input_operation)
{
	if (input_operation == X_ROTATE_DOWN || input_operation == X_ROTATE_UP ||
		input_operation == Y_ROTATE_DOWN || input_operation == Y_ROTATE_UP ||
		input_operation == Z_ROTATE_DOWN || input_operation == Z_ROTATE_UP ||
		input_operation == KEY_LEFT || input_operation == KEY_RIGHT ||
		input_operation == KEY_DOWN || input_operation == KEY_UP ||
		input_operation == CAMERA_SETBACK)
		return (1);
	else
		return (0);
}
