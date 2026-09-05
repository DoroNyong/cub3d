/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjang <hjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:52:43 by hjang             #+#    #+#             */
/*   Updated: 2024/10/25 15:16:50 by hjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}

static int	isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}

int	ft_isalpha(int c)
{
	if (islower(c) || isupper(c))
		return (1);
	else
		return (0);
}
