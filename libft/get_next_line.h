/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:56:57 by yodahani          #+#    #+#             */
/*   Updated: 2023/07/16 15:22:46 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <stdlib.h>
# include<unistd.h>
# include<stdio.h>

char	*get_next_line(int fd);
char	*ft_substring(char **str);
char	*ft_strjoin_nl(char **str, char *s);
size_t	ft_strlen(const char *str);
void	ft_fill(char *dst, char *src, int start, size_t len);
int		ft_nl(char *s);
char	*ft_free(char **str, char *s);
char	*ft_end(char **str, char *s);
char	*ft_read(int fd, char **str);
char	*get_next_line(int fd);
#endif