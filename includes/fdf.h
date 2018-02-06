#ifndef FDF_H
# define FDF_H

# define X_SIZE 1680
# define Y_SIZE 1050  
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126 
# define X_ROTATE_UP 1
# define X_ROTATE_DOWN 2
# define Y_ROTATE_UP 3
# define Y_ROTATE_DOWN 4
# define Z_ROTATE_UP 5
# define Z_ROTATE_DOWN 6

typedef struct 		s_mlx
{
	void	*mlx;
	void	*win;
	void	*image;
}					t_mlx;

float				***ft_parsing(char *arg);
void				print_tab_debug(float ***TABTAB);
float				***camera_move(float ***tab, int input_operation);
float				***create_rotation_matrix(float ***g_rotate_matrix);
float				***table_transform_handler(float ***tab,
		int input_operation);
float				***first_camera_move(float ***tab);

#endif
