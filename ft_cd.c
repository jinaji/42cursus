/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:16:59 by jinkim2           #+#    #+#             */
/*   Updated: 2022/08/18 01:10:57 by jinkim2          ###   ########seoul.kr  */
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
	if (ac == 1 || ft_strncmp(av[1], "~", ft_strlen(av[1])) == 0 && getenv("HOME"))
		ret = chdir(getenv("HOME"));
	else if (!getenv("HOME"))
		printf("어케하드라");
	else if (ft_strcmp(av[1], "-"))
		ret = chdir(getenv("OLDPWD")); // 이거 없으면 어케되는지 확인 
	else
		ret = chdir(av[1]);
	printf("%d\n", ret);
	if (ret == -1)
		print_cd_err(buf, av[1]);
	free (buf);
	system("pwd");
}
