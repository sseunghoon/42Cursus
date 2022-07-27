/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 21:51:20 by seunghso          #+#    #+#             */
/*   Updated: 2022/06/07 16:53:07 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# define TRUE 1
# define FALSE 0

# define ERROR_MSG "map error\n"

# define BUFFER_MAX 512

# define EMPTY 0
# define OBSTACLE 1
# define FULL 2
# define CHAR_NO 3

typedef enum e_chain_cmd
{
	INSERT,
	REMOVE_ALL,
}	t_chain_cmd;

typedef struct s_string_chain
{
	char					*str;
	unsigned int			length;
	unsigned int			offset;
	struct s_string_chain	*next;
}	t_string_chain;

typedef struct s_file_lines
{
	t_string_chain	*head;
	t_string_chain	*tail;
}	t_file_lines;

typedef struct s_bsq_map
{
	char	*box;
	int		width;
	int		height;
	char	chars[CHAR_NO];
}	t_bsq_map;

typedef struct s_resolve
{
	int	x;
	int	y;
	int	r;
}	t_resolve;

/*
** Forty-Two Util class (ft_util.c)
*/
void			*ft_copy(void *dest, void *src, int n);
int				ft_strlen(char *str);
int				ft_isprintable(char c);
char			*ft_insert_char(char *dest, char src);
void			ft_putstr(int fd, char *str);

/*
** Alloc Util (ctor.c)
*/
void			*ft_malloc(unsigned int size);

/*
** File Lines Reader class Constructor, Destructor (ctor.c, dtor.c)
*/
t_file_lines	*malloc_lines(void);
void			free_lines(t_file_lines *self);

/*
** File Lines Reader class member methods (lines.c)
*/
int				read_lines(t_file_lines *self, int fd);
t_string_chain	*chain_command(t_file_lines *self, t_chain_cmd cmd);
int				split_chain(t_file_lines *self, t_string_chain *temp);
int				create_chain(t_file_lines *self, unsigned int length);
int				numbering_temp(t_file_lines *self, t_string_chain *temp);

/*
** File Lines Reader class member methods (lines2.c)
*/
int				read_lines2(t_file_lines *self, char *str);

/*
** the Biggest SQuare Map class Constructor, Destructor (ctor.c, dtor.c)
*/
t_bsq_map		*bsq_map_malloc(void);
void			bsq_map_free(t_bsq_map *self);

/*
** the Biggest SQuare Map class member methods (map.c)
*/
int				init_map(t_bsq_map *self, t_file_lines *lines);
int				read_first_line(t_bsq_map *self, char *str);
int				check_double(t_bsq_map *self);
int				cast_line(t_bsq_map *self, char *str, int y);
char			*get_at(t_bsq_map *self, int x, int y);

/*
** Extension methods (exts.c)
*/
int				read_lines_from_path(t_file_lines *self, char *pathname);
char			min(char a, char b);
t_bsq_map		*calc_map(t_bsq_map *self);
t_resolve		find_max(t_bsq_map *self);
int				ft_boundary(t_resolve *sol, int x, int y);

#endif
