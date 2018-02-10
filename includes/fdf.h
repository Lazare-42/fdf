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
# define CAMERA_SETBACK 10932

typedef struct 		s_mlx
{
	void			*mlx;
	void			*win;
	void			*image;
	int				*screen_data;
}					t_mlx;

double				***ft_parsing(char *arg);
void				print_tab_debug(double ***TABTAB);
double				***camera_move(double ***tab, int input_operation,
		double **cos_sinus);
double				***create_rotation_matrix(double ***g_rotate_matrix);
double				***table_transform_handler(double ***tab,
		int input_operation, int *camera_setback);
double				***first_camera_move(double ***tab, double **cos_sinus, int *camera_setback);
void				print_handler(double ***tab, int print, int **screen);
void				draw_line(double *from, double *to, int **screen);
double				***scale(double ***tab, int max_x, int max_y, int max_z);

#endif
