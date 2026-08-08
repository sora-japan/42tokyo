/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 08:38:35 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/09 10:44:13 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	int len;
	if (argc != 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	len = 0;
	while(argv[1][len])
		len++;
	len - 1;
	while (len >= 0 && (argv[1][len] == ' '|| argv[1][len] == '\t'))
		len--;
	end = len; //この時点で最後の単語の最後の文字を指している
	while (len > 0 && argv[1][len] != ' ' && argv[1][len] != '\t')
		len--;
	start = len + 1; //lenは最後の単語の直前のスペースをさしている
	while(start <= end) //条件式として使う
	{
		write(1, &argv[1][start], 1);
		start++;
	}
	write(1, "\n", 1);
	return 0;
}
