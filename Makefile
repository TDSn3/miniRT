NAME		= miniRT
CFLAGS		= -g -Werror -Wall -Wextra -Wshadow -MMD -D_REENTRANT -DLinux -I include -I libmlx -I libft
LDFLAGS		= -Llibmlx -Llibft
LDLIBS		= -lpthread -pthread -lmlx -lXext -lX11 -lm

FILENAMES	=							\
	$(addprefix tuple/,					\
		init_point						\
		init_vector						\
		t_tuple_plus					\
		t_tuple_minus					\
		t_tuple_nega					\
		t_tuple_multi_scal				\
		t_tuple_div_scal				\
		t_tuple_multi					\
		magnitude_vector				\
		normalization_vector			\
		scalar_product_vector			\
		cross_product_vector			\
	)									\
	$(addprefix matrix/,				\
		equal_matrix					\
		multiply_matrix4				\
		multiply_matrix4_tuple			\
		give_identity_matrix4			\
		transpose_matrix4				\
		determinant_matrix				\
		sub_matrix						\
		minor_matrix					\
		cofactor_matrix					\
		is_invertible_matrix4			\
		inverse_matrix4					\
	)									\
	$(addprefix transformation/,		\
		transform						\
		translation						\
		scaling							\
		rotation_xyz					\
		deg_to_rad						\
		shearing						\
		transform_ray					\
	)									\
	$(addprefix intersection/,			\
		position						\
		intersect						\
		intersection					\
		set_transform					\
		intersect_caps					\
		$(addprefix s_intersection_/,	\
			si_add_back					\
			si_size						\
			si_new						\
			si_last						\
			si_clear					\
		)								\
	)									\
	$(addprefix light_shading/,			\
		normal_at						\
		reflect							\
		lighting						\
	)									\
	$(addprefix world/,					\
		intersect_world					\
		prepare_computations			\
		shade_hit						\
		color_at						\
		view_transform					\
		give_camera						\
		ray_for_pixel					\
		render							\
		is_shadowed						\
		$(addprefix s_object_/,			\
			so_add_back					\
			so_size						\
			so_new						\
			so_last						\
			so_clear					\
		)								\
		$(addprefix s_t_and_object_/,	\
			sto_add_back				\
			sto_size					\
			sto_new						\
			sto_last					\
			sto_clear					\
			sto_sort					\
		)								\
	)									\
	$(addprefix util/,					\
		init_all 						\
		my_mlx_pixel_put				\
		equal_float						\
		convert_to_255					\
		key_press_hook					\
		key_release_hook				\
		mouse_hook						\
		red_button						\
		gen_new_img						\
	)									\
	$(addprefix thread/,				\
		main_exec_thread				\
		exec_thread_1_4					\
		exec_thread_5_8					\
		exec_thread_9_12				\
	)									\
	$(addprefix parser/,				\
		parser							\
		parse_file						\
		parse_globals					\
		parse_objects					\
		parse_utils						\
	)									\
	miniRT

SRC		= $(addsuffix .c, $(FILENAMES))
OBJ		= $(SRC:.c=.o)
DEPENDS	= $(SRC:.c=.d)

all: $(NAME)

$(NAME): $(OBJ) libmlx/libmlx.a libft/libft.a

libft/libft.a:
	$(MAKE) -C libft

libmlx/libmlx.a:
	$(MAKE) -C libmlx

clean:
	$(MAKE) -C libft clean
	rm -f $(OBJ)
	rm -f $(DEPENDS)

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean
	$(MAKE) -C libmlx clean

re: fclean
	$(MAKE)

-include $(DEPENDS)