/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemoreir <jemoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 20:30:22 by jemoreir          #+#    #+#             */
/*   Updated: 2025/10/16 17:05:21 by jemoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_printarg(va_list lista, char arg)
{
	int	count;

	count = 0;
	if (arg == 'c')
		count += ft_putchar(va_arg(lista, int));
	else if (arg == 's')
		count += ft_putstr(va_arg(lista, char *));
	else if (arg == 'p')
		count += ft_print_pointer(va_arg(lista, unsigned long));
	else if (arg == 'd' || arg == 'i')
		count += ft_printnbr(va_arg(lista, int));
	else if (arg == 'u')
		count += ft_print_u(va_arg(lista, unsigned int));
	else if (arg == 'x' || arg == 'X')
		count += ft_print_hex(va_arg(lista, unsigned int), arg);
	else if (arg == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	lista;
	int		i;
	int		r;

	i = 0;
	r = 0;
	if (!str || write(1, 0, 0) == -1)
		return (-1);
	va_start (lista, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '\0')
				return (va_end(lista), -1);
			r += ft_printarg (lista, str[i]);
			i += 1;
		}
		else
			r += ft_putchar (str[i++]);
	}
	va_end (lista);
	return (r);
}
// int main()
// {
// 	ft_printf("--TESTE %%c--\n");
// 	int a = ft_printf("Impressao ft_printf = (%c)\n", 'c');
// 	printf("Impressao printf = (%c)\n", 'c');
// 	printf("Retorno printf = (%d)\n", a);
// 	ft_printf("Retorno ft_printf = (%d)\n", a);

// 	ft_printf("\n--TESTE %%s--\n");
// 	int b = ft_printf("Impressao ft_printf = (%s)\n", "ola");
// 	printf("Impressao printf = (%s)\n", "ola");
// 	printf("Retorno printf = (%d)\n", b);
// 	ft_printf("Retorno ft_printf = (%d)\n", b);

// 	ft_printf("\n--TESTE %%p--\n");
// 	int c = ft_printf("Impressao ft_printf = (%p)\n", &c);
// 	printf("Impressao printf = (%p)\n", &c);
// 	printf("Retorno printf = (%d)\n", c);
// 	ft_printf("Retorno ft_printf = (%d)\n", c);

// 	ft_printf("\n--TESTE %%d || %%i--\n");
// 	int d = ft_printf("Impressao ft_printf = (%%d = %d)\n", 10);
// 	int d2 = ft_printf("Impressao ft_printf = (%%i = %i)\n", 10);
// 	printf("Impressao printf = (%%d = %d)\n", 10);
// 	printf("Impressao printf = (%%i = %i)\n", 10);
// 	printf("Retorno printf = (%%d = %d)\n", d);
// 	ft_printf("Retorno ft_printf = (%%d = %d)\n", d);
// 	printf("Retorno printf = (%%i = %i)\n", d2);
// 	ft_printf("Retorno ft_printf = (%%i = %i)\n", d2);

// 	ft_printf("\n--TESTE %%u--\n");
// 	int e = ft_printf("Impressao ft_printf = (%u)\n", -10);
// 	printf("Impressao printf = (%u)\n", -10);
// 	printf("Retorno printf = (%d)\n", e);
// 	ft_printf("Retorno ft_printf = (%d)\n", e);

// 	ft_printf("\n--TESTE %%x || %%X--\n");
// 	int f = ft_printf("Impressao ft_printf = (%%x = %x)\n", 10);
// 	int f2 = ft_printf("Impressao ft_printf = (%%X = %X)\n", 10);
// 	printf("Impressao printf = (%%x = %x)\n", 10);
// 	printf("Impressao printf = (%%X = %X)\n", 10);
// 	printf("Retorno printf = (%%x = %d)\n", f);
// 	printf("Retorno printf = (%%X = %d)\n", f2);
// 	ft_printf("Retorno ft_printf = (%%x = %d)\n", f);
// 	ft_printf("Retorno ft_printf = (%%X = %d)\n", f2);
// }
