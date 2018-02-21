#ifndef FDF_H
# define FDF_H

# define X_SIZE 2560
# define Y_SIZE 1440
# define KEY_LEFT 12
# define KEY_RIGHT 13
# define KEY_LEFT 12
# define KEY_RIGHT 13
# define KEY_DOWN 14
# define KEY_UP 15


# define ZOOM_IN 69
# define ZOOM_OUT 75

# define X_ROTATE_UP 126
# define X_ROTATE_DOWN 125
# define Y_ROTATE_UP 124
# define Y_ROTATE_DOWN 123
# define Z_ROTATE_UP 6
# define Z_ROTATE_DOWN 7
# define CAMERA_SETBACK 10932

typedef struct 		s_mlx
{
	void			*mlx;
	void			*win;
	void			*image;
	int				*screen_data;
}					t_mlx;

double				***ft_parsing(char *arg, int **dimensions);
void				print_tab_debug(double ***TABTAB);
double				***camera_move(double ***tab, int input_operation,
		double **cos_sinus);
double				***create_rotation_matrix(double ***g_rotate_matrix);
double				***table_transform_handler(double ***tab,int input_op);
double				***first_camera_move(double ***tab, double **cos_sinus, int *camera_setback);
void				print_handler(double ***tab, int print, int **screen, int *dimensions);
double				***scale(double ***tab, int max_x, int max_y, int max_z);
double				***matrix_multiplication(double ***tab, int *dimensions);
double				***center_matrix(double ***tab, int *field_size);
double				***create_temp_tab(int	*dimensions, double ***tocopy);
int					redraw(int keycode, int *dimensions);
double				*set_get_cos_sinus(double *new_cos_sinus);
double				*set_get_radiuses(double *new_radiuses);
double				*set_get_pixel(double *new_point);
double				***store_tab(double ***tabtab);
int					check_if_input(int input_operation);

#endif
