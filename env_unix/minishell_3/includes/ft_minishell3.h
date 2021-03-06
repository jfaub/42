/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell3.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 18:08:25 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/09 18:31:24 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		MINISHELL3_H
# define	MINISHELL3_H

# define	MAX_KEY_LEN					6
# define	P_LEN						4

# define	KEY_ENTER(buf)				ft_is_key_enter(buf)
# define	KEY_DEL_LEFT(buf)			ft_is_key_del_left(buf)
# define	KEY_DEL_RIGHT(buf)			ft_is_key_del_right(buf)
# define	KEY_ARROW_UP(buf)			ft_is_key_arrow_up(buf)
# define	KEY_ARROW_DOWN(buf)			ft_is_key_arrow_down(buf)
# define	KEY_ARROW_LEFT(buf)			ft_is_key_arrow_left(buf)
# define	KEY_ARROW_RIGHT(buf)		ft_is_key_arrow_right(buf)
# define	KEY_OPT_ARROW_UP(buf)		ft_is_key_opt_arrow_up(buf)
# define	KEY_OPT_ARROW_DOWN(buf)		ft_is_key_opt_arrow_down(buf)
# define	KEY_OPT_ARROW_LEFT(buf)		ft_is_key_opt_arrow_left(buf)
# define	KEY_OPT_ARROW_RIGHT(buf)	ft_is_key_opt_arrow_right(buf)
# define	KEY_CTRL_A(buf)				ft_is_key_ctrl_a(buf)
# define	KEY_CTRL_E(buf)				ft_is_key_ctrl_e(buf)
# define	KEY_CTRL_U(buf)				ft_is_key_ctrl_u(buf)
# define	KEY_CTRL_I(buf)				ft_is_key_ctrl_i(buf)
# define	KEY_CTRL_H(buf)				ft_is_key_ctrl_h(buf)
# define	KEY_CTRL_R(buf)				ft_is_key_ctrl_r(buf)
# define	KEY_CTRL_T(buf)				ft_is_key_ctrl_t(buf)
# define	KEY_CTRL_F(buf)				ft_is_key_ctrl_f(buf)
# define	KEY_CTRL_G(buf)				ft_is_key_ctrl_g(buf)

typedef struct		s_sl
{
	char			c;
	struct s_sl		*next;
	struct s_sl		*prev;
}					t_sl;

typedef struct		s_hl
{
	t_sl			*hist;
	struct s_hl		*next;
	struct s_hl		*prev;
}					t_hl;

typedef struct		s_save
{
	int				cursor;
	int				co;
	int				hist_nb;
	t_sl			*copy;
}					t_save;

/*
** EDIT COMMAND LINE
*/

/*
** Basics
*/

int			ft_putc(int c);
int			ft_slist_len(t_sl *sl);
int			ft_hlist_len(t_hl *sl);
int			ft_list_put_elem(char c, t_sl **sl, int cursor);
int			ft_slist_to_ts(char **line, t_sl **sl);
t_sl		*ft_listdup(t_sl *sl);
t_sl		*ft_list_new_elem(char c);
void		ft_list_del_elem(t_sl **sl, int cursor);

/*
** Main fonctions
*/

int			ft_print(t_sl *sl, t_save *save, int old_line);
int			ft_cut_copy_or_paste(char *buf, t_sl **sl, t_save *save);
int			ft_fast_move(char *buf, t_sl **sl, int *cursor);
int			ft_put_or_del_char(char *buf, t_sl **sl, t_save *save, t_hl **hl);
int			ft_little_move(char *buf, t_sl **l, int *cursor, int co);
int			ft_save_cmd_line(t_hl **hl, char **line);

/*
** What key
*/

int			ft_is_key_opt_arrow_up(char *buf);
int			ft_is_key_opt_arrow_down(char *buf);
int			ft_is_key_opt_arrow_left(char *buf);
int			ft_is_key_opt_arrow_right(char *buf);
int			ft_is_key_arrow_up(char *buf);
int			ft_is_key_arrow_down(char *buf);
int			ft_is_key_arrow_left(char *buf);
int			ft_is_key_arrow_right(char *buf);
int			ft_is_key_del_left(char *buf);
int			ft_is_key_del_right(char *buf);
int			ft_is_key_enter(char *buf);
int			ft_is_key_ctrl_u(char *buf);
int			ft_is_key_ctrl_i(char *buf);
int			ft_is_key_ctrl_h(char *buf);
int			ft_is_key_ctrl_a(char *buf);
int			ft_is_key_ctrl_e(char *buf);
int			ft_is_key_ctrl_r(char *buf);
int			ft_is_key_ctrl_t(char *buf);
int			ft_is_key_ctrl_f(char *buf);
int			ft_is_key_ctrl_g(char *buf);

/*
** Historic
*/

int			ft_update_history(t_hl **hl, t_sl *sl);
int			ft_move_in_history(char *buf, t_sl **sl, t_save *save, t_hl **hl);

/*
** TREAT THE COMMAND LINE
*/

void		ft_my_bin_1(char **all, char **env);
char		**ft_my_bin_2(char **all, char **env);
char		**ft_syst_bin(char **all, char **env);
char		**ft_run_small_part(char *line, char **env);
char		**ft_simple_left_redir(char **cmd, char *file, char **env);
char		**ft_simple_right_redir(char **cmd, char *file, char **env);
char		**ft_double_right_redir(char **cmd, char *file, char **env);
char		**ft_run_middle_part_2(char **all, char **env);
char		**ft_run_middle_part_1(char *line, char **env);
char		**ft_run_big_part(char *line, char **env);
char		**ft_treat_cmd_line(char *line, char **env, int *exit);

/*
** My built-in
*/

int			ft_my_sh_exit(char *line);
void		ft_pwd(char **all);
void		ft_env(char **all, char **env);
char		**ft_change_env(char *my_key, char *my_val, char **env);
char		**ft_cd(char **all, char **env);
char		**ft_setenv(char **all, char **env);
char		**ft_unsetenv(char **all, char **env);

#endif	/* !MINISHELL3_H */
