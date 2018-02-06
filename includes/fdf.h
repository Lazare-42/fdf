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
	void	*mlx;
	void	*win;
	void	*image;
	int		*screen_data;
	int		bpp;
	int		endian;
	int		size_line;
}					t_mlx;

float				***ft_parsing(char *arg);
void				print_tab_debug(float ***TABTAB);
float				***camera_move(float ***tab, int input_operation);
float				***create_rotation_matrix(float ***g_rotate_matrix);
float				***table_transform_handler(float ***tab,
		int input_operation);
float				***first_camera_move(float ***tab);
int					put_to_screen_string(float *tab, int **screen);

#endif
