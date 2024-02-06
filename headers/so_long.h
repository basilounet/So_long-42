/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvasseur <bvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:25:55 by bvasseur          #+#    #+#             */
/*   Updated: 2024/01/23 10:14:57 by bvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# define CELL_SIZE 64
# define GROUND_TEXTURES_PATH "textures/ground/"
# define WALL_TEXTURES_PATH "textures/walls/"
# define COLL_TEXTURES_PATH "textures/collectibles/"
# define PLAYER_TEXTURES_PATH "textures/player/"
# define ENEMY_TEXTURES_PATH "textures/enemies/"
# define FONTS_TEXTURES_PATH "textures/fonts/"

enum				e_errors
{
	INVALID_FD = 1,
	INVALID_FORMAT = 2,
	EMPTY_MAP = 3,
	INVALID_CHARACTER = 4,
	INVALID_WALLS = 5,
	INVALID_SHAPE = 6,
	INVALID_NUMBER_P = 7,
	INVALID_NUMBER_E = 8,
	INVALID_NUMBER_C = 9,
	UNREACHABLE_E = 10,
	UNREACHABLE_C = 11,
	MALLOC_ERROR = 12,
	INVALID_AC_AMOUNT = 13,
	MISSING_FORMAT = 14,
	MLX_ERROR = 15
};

enum				e_nb_textures
{
	NB_TEXTURES_WALLS = 47,
	NB_TEXTURES_COLL = 15,
	NB_TEXTURES_GROUND = 11,
	NB_TEXTURES_EXIT = 5,
	NB_TEXTURES_P_IDLE = 6,
	NB_TEXTURES_ENEMY_IDLE = 18,
	NB_TEXTURES_P_WALK_SIDE = 6,
	NB_TEXTURES_FONTS = 11
};

typedef struct s_recu
{
	char			**map;
	size_t			p_total;
	size_t			e_total;
	size_t			c_total;
	size_t			c_seen;
	size_t			e_seen;
	size_t			p_xpos;
	size_t			p_ypos;
}					t_recu;

typedef struct s_tile
{
	int				should_rotate;
	char			middle;
	char			left;
	char			right;
	char			top;
	char			bottom;
	char			top_left;
	char			top_right;
	char			bottom_left;
	char			bottom_right;
}					t_tile;

typedef struct s_textures
{
	char			**textures_name;
	mlx_texture_t	**textures;
	mlx_image_t		**image;
	size_t			nb_textures;
}					t_textures;

typedef struct s_entity
{
	int				x;
	int				y;
	int				facing;
	int				animation_frame;
	t_textures		*current_animation;
	t_list			*animations;
}					t_entity;

typedef struct s_so_long
{
	mlx_t			*mlx;
	char			**map;
	size_t			height;
	size_t			width;
	t_recu			*recu_data;
	t_list			*w_rules;
	t_textures		*fonts_txtr;
	t_textures		*wall_txtr;
	t_textures		*ground_txtr;
	t_textures		*coll_txtr;
	t_entity		*exit;
	t_entity		*player;
	t_entity		*enemies;
	t_list			*steps_images;
	t_list			*current_coll_images;
	size_t			frame;
	size_t			nb_coll;
	size_t			steps;
}					t_so_long;

/*========== MAP_HANDLER ==========*/

int					is_component(char c);
void				map_analyser(int ac, char **av, t_so_long *gm);
t_recu				*innit_data(t_so_long *gm);
void				check_lines(t_so_long *gm);

/*========== STRUCT_INNIT ==========*/

void				init_gm(t_so_long *gm);
t_tile				init_tile(t_so_long *gm, size_t i, size_t j);
t_textures			*init_txtr(t_so_long *gm, t_textures *txtr,
						size_t nb_textures);
void				set_textures(t_so_long *gm, t_textures *txtr, char *path,
						void (*set_texture_name)(t_so_long *gm,
							char ***t_names));
void				set_textures_terrain(t_so_long *gm);
void				set_player_textures_names(t_so_long *gm, char ***t_names);
void				set_enemies_textures_names(t_so_long *gm, char ***t_names);
void				set_textures_exit(t_so_long *gm);
void				set_fonts_names(t_so_long *gm, char ***t_names);
void				set_textures_player(t_so_long *gm);
void				set_textures_ennemies(t_so_long *gm);

/*========== UNLEAK ==========*/

void				unleak(t_so_long *gm);
void				free_gnl(int fd, t_so_long *gm, char *str);
void				free_textures(mlx_texture_t **textures, size_t nb_textures);
void				free_images(mlx_t *mlx, mlx_image_t **images,
						size_t nb_textures);
void				free_txtr(mlx_t *mlx, t_textures *txtr);
void				free_entity(t_entity *entity, mlx_t *mlx);

/*========== RULE_TILE ==========*/

t_tile				*create_rule(const char *rules, int should_rotate);
int					check_all_rotations(t_tile tile, t_tile rule);
int					is_tile_matching_rule(t_tile tile, t_tile rule);

/*========== WALLS ==========*/

void				print_wall(t_so_long *gm, size_t y, size_t x);
void				create_wall_rules(t_so_long *gm);
int					get_index_texture(t_list *rules, t_tile tile);
int					is_wall(t_so_long *gm, int y, int x);

/*========== COLL ==========*/

void				remove_coll(t_so_long *gm, int y, int x);
void				change_exit(t_so_long *gm);

/*========== GROUND ==========*/

void				print_grass(t_so_long *gm, int y, int x);

/*========== ENTITY ==========*/

void				create_images(t_so_long *gm, t_entity *entity, char *name);
void				set_animation(t_entity *entity, char *name);
void				next_animation_frame(t_entity *entity);
void				update_animation_pos(t_entity *entity);
void				set_frame(t_entity *entity, int index);

/*========== PLAYER ==========*/

int					is_movment_key(mlx_key_data_t keydata);
void				move(mlx_key_data_t keydata, t_so_long *gm);

/*========== ENEMIES ==========*/

void				play_enemies(t_so_long *gm, t_entity *entity);
void				place_enemies(t_so_long *gm);

/*========== UPDATE ==========*/

void				check_victory(t_so_long *gm);
void				print_steps(t_so_long *gm);
void				print_total_coll(t_so_long *gm);
void				print_current_coll(t_so_long *gm);
void				check_lost(t_so_long *gm);
void				play_sound(char *path);
void				kill_sounds(void);

/*========== ERRORS ==========*/

void				error(t_so_long *gm, enum e_errors name);
void				check_errors_textures_names(t_so_long *gm,
						t_textures *txtr);

#endif
