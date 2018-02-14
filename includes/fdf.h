#ifndef FDF_H
# define FDF_H

# define X tab[0]
# define Y tab[1]
# define Z tab[2]
# define cx g_cos_sinus[0]
# define sx g_cos_sinus[1]
# define cy g_cos_sinus[2]
# define sy g_cos_sinus[3]
# define cz g_cos_sinus[4]
# define sz g_cos_sinus[5]
# define X_SIZE 1920
# define Y_SIZE 1200  
# define KEY_LEFT 12
# define KEY_RIGHT 13
# define KEY_DOWN 14
# define KEY_UP 15
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
double				***table_transform_handler(double ***tab,
		int input_operation, int *camera_setback);
double				***first_camera_move(double ***tab, double **cos_sinus, int *camera_setback);
void				print_handler(double ***tab, int print, int **screen, int *dimensions);
void				draw_line(double *from, double *to, int **screen);
double				***scale(double ***tab, int max_x, int max_y, int max_z);
double				*matrix_multiplication(double *tab);

#endif
