#ifndef FDF_H
# define FDF_H

# define X_SIZE 1680
# define Y_SIZE 1050  
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126 
# define X_ROTATE_UP 109
# define X_ROTATE_DOWN 122
# define Y_ROTATE_UP 122
# define Y_ROTATE_DOWN 1212
# define Z_ROTATE_UP 1212
# define Z_ROTATE_DOWN 1212

typedef struct 		s_mlx
{
	void			*mlx;
	void			*win;
	void			*image;
	int				*screen_data;
}					t_mlx;

double				***ft_parsing(char *arg);
void				print_tab_debug(double ***TABTAB);
double				***camera_move(double ***tab, int input_operation);
double				***create_rotation_matrix(double ***g_rotate_matrix);
double				***table_transform_handler(double ***tab,
		int input_operation);
double				***first_camera_move(double ***tab, int max_x, int max_z, int max_y);
void				put_to_screen_string(double *tab, int **screen);
void				draw_line(double *from, double *to, int **screen);
double				***scale(double ***tab, int max_x, int max_y, int max_z);

#endif
