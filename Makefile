# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcatini <rcatini@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/30 09:01:22 by tda-silv          #+#    #+#              #
#    Updated: 2023/02/28 13:59:42 by rcatini          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= miniRT

SRC_DIR		= source/
OBJ_DIR		= object/
INC_DIR		= include/
CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -Wshadow -g
# -Werror -Wconversion -Wno-error=conversion
# **************************************************************************** #
#                                                                              #
#   -I   | Chemin du dossier où trouver un .h								   #
#   -L   | Chemin du dossier où trouver un .a								   #
#   -l   | Nom du .a sans le préfixe "lib"									   #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#   Linux                                                                      #
# **************************************************************************** #
#
I_HEADERS	= -I $(INC_DIR) -I libmlx -I libft
L_LIB		= -Llibmlx -Llibft -lmlx -lft -lXext -lX11 -lm -lz 
#
# **************************************************************************** #
#   MacOs                                                                      #
# **************************************************************************** #

# L_LIB		= -Lmlx_macos -lmlx -framework OpenGL -framework AppKit
# I_HEADERS	= -I $(INC_DIR) -I mlx_macos

# **************************************************************************** #

HEADERS		= $(shell find include/ -type f)

NAME_FILE	= $(addprefix tuple/,												\
							    init_point										\
							    init_vector										\
							    t_tuple_plus									\
							    t_tuple_minus									\
							    t_tuple_nega									\
							    t_tuple_multi_scal								\
							    t_tuple_div_scal								\
								t_tuple_multi									\
							    magnitude_vector								\
							    normalization_vector							\
							    scalar_product_vector							\
								cross_product_vector							\
			   )																\
			  $(addprefix matrix/,												\
			 					new_matrix										\
								new_identity_matrix								\
								init_matrix										\
							    free_matrix										\
								copy_matrix										\
								equal_matrix									\
								multiply_matrix									\
								multiply_matrix_tuple							\
								transposing_matrix								\
								determinant_matrix								\
								sub_matrix										\
								minor_matrix									\
								cofactor_matrix									\
								is_invertible_matrix							\
								inverse_matrix									\
								inverse_matrix_free								\
			   )																\
			  $(addprefix transformation/,										\
										 transform								\
										 translation							\
										 scaling								\
										 rotation_xyz							\
										 deg_to_rad								\
										 shearing								\
										 transform_ray							\
			   )																\
			  $(addprefix intersection/,										\
									   position									\
									   give_sphere								\
									   intersect								\
									   intersection								\
									   hit										\
									   set_transform							\
						   $(addprefix s_intersection_/,						\
								   					   si_add_back				\
													   si_size					\
													   si_new					\
													   si_last					\
													   si_find_content			\
													   si_clear					\
													   si_clear_one				\
						    )													\
			   )																\
			  $(addprefix light_shading/,										\
										normal_at								\
										reflect									\
										lighting								\
			   )																\
			  $(addprefix world/,												\
								intersect_world									\
					$(addprefix s_object_/,										\
								   		  so_add_back							\
										  so_size								\
										  so_new								\
										  so_last								\
										  so_clear								\
					 )															\
					$(addprefix s_t_and_object_/,								\
								   			    sto_add_back					\
											    sto_size						\
											    sto_new							\
											    sto_last						\
											    sto_clear						\
											    sto_sort						\
					 )															\
			   )																\
			   main																\
			   my_mlx_pixel_put													\
			   equal_float														\
			   print_canvas														\
			   convert_to_255													\
			   parser/parse_file												\
			   parser/parse_objects												\
			   parser/parse_globals												\

SRC			= $(addsuffix .c, $(addprefix $(SRC_DIR), $(NAME_FILE)))
OBJ			= $(addsuffix .o, $(addprefix $(OBJ_DIR), $(NAME_FILE)))
DEPENDS		= $(addsuffix .d, $(addprefix $(OBJ_DIR), $(NAME_FILE)))

# **************************************************************************** #
#                                                                              #
#   $@   | Le nom de la cible												   #
#   $<   | Le nom de la première dépendance									   #
#   $^   | La liste des dépendances											   #
#   $?   | La liste des dépendances plus récentes que la cible				   #
#   $*   | Le nom du fichier sans suffixe									   #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#   Relink si les headers ou le Makfile sont changés                           #
#                                                                              #
# **********************************vvvvvvvvvvvvvvvvvvv*********************** #

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS) Makefile
#	make -C libmlx
#	@cd mlx_macos; make >> /dev/null 2>> /dev/null; cd ..
	@ mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(I_HEADERS) -MMD -MP -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(I_HEADERS) $(L_LIB) -o $(NAME)

clean:
#	make -C libmlx clean
#	cd mlx_macos; make clean
	rm -rf $(OBJ_DIR)

fclean: clean
#	rm -f $(LIBFT)
	rm -f $(NAME)

re: fclean
	$(MAKE) all

leaks: $(NAME)
	@leaks --atExit -- ./$(NAME)

.PHONY: all clean fclean re leaks

-include $(DEPENDS)
