/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncouton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:24:15 by ncouton           #+#    #+#             */
/*   Updated: 2024/03/20 16:09:43 by ncouton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include<stdlib.h>
# include<stdio.h>
# include<stdarg.h>
# include<unistd.h>

char	*get_next_line(int fd);
char	*ft_read_new_line(char *line);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int searchedChar);
size_t	ft_strlen(const char *str);
char	*ft_read_line(int fd, char *line);
char	*ft_buffer(char *line);

#endif
