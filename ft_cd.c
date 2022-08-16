/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:16:59 by jinkim2           #+#    #+#             */
/*   Updated: 2022/08/16 12:46:57 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include <sys/stat.h>

void	print_cd_err(struct stat *buf, char *str)
{
	lstat(str, buf);
	printf ("%hu\n", buf->st_mode);
	if (buf->st_mode == 0)
		printf ("shellname: cd: %s: No such file or directory\n", str);
	if (buf->st_mode == 16384)
		printf ("shellname: cd: %s: Permission denied\n", str);
	if (buf->st_mode == 33261)
		printf("shellname: cd: %s: Not a directory\n", str);
}

int	main(int ac, char **av)
{
	struct stat	*buf;
	int			ret;

	ret = 1;
	buf = malloc(sizeof(stat));
	if (ac == 1 || ft_strncmp(av[1], "~", ft_strlen(av[1])) == 0)
		ret = chdir(getenv("HOME"));
	// ret = chdir("../pipex");
	else
		ret = chdir(av[1]);
	printf("%d\n", ret);
	if (ret == -1)
		print_cd_err(buf, av[1]);
	free (buf);
	system("pwd");
}
