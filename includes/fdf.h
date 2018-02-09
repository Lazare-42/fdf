#ifndef FDF_H
# define FDF_H

# define X_SIZE 1680
# define Y_SIZE 1050  
# define KEY_LEFT 1222
# define KEY_RIGHT 12422
# define KEY_DOWN 12522
# define KEY_UP 12633
# define X_ROTATE_UP 123
# define X_ROTATE_DOWN 124
# define Y_ROTATE_UP 125
# define Y_ROTATE_DOWN 126
# define Z_ROTATE_UP 1212
# define Z_ROTATE_DOWN 1212

typedef struct 		s_mlx
{
	void			*mlx;
	void			*win;
	void			*image;
	int				*screen_data;
}					t_mlx;

float				***ft_parsing(char *arg);
void				print_tab_debug(float ***TABTAB);
float				***camera_move(float ***tab, int input_operation);
float				***create_rotation_matrix(float ***g_rotate_matrix);
float				***table_transform_handler(float ***tab,
		int input_operation);
float				***first_camera_move(float ***tab);
void				print_handler(float ***tab, int print, int **screen);
void				draw_line(float *from, float *to, int **screen);
float				***scale(float ***tab, int max_x, int max_y, int max_z);

#endif
