# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/30 09:01:22 by tda-silv          #+#    #+#              #
#    Updated: 2023/02/19 23:48:05 by tda-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= miniRT

SRC_DIR		= source/
OBJ_DIR		= object/
INC_DIR		= include/

CC			= gcc

CFLAGS		= -Wall -Wextra  -Wshadow -Wconversion -Wno-error=conversion
# -Werror
# **************************************************************************** #
#                                                                              #
#   -I   | Chemin du dossier où trouver un .h								   #
#   -L   | Chemin du dossier où trouver un .a								   #
#   -l   | Nom du .a sans le préfixe "lib"									   #
#                                                                              #
# **************************************************************************** #

I_HEADERS	= -I $(INC_DIR) -I mlx

#L_LIB		= -Lmlx -lmlx -lXext -lX11 -lm -lz
L_LIB		= -L mlx -l mlx -framework OpenGL -framework AppKit

HEADERS		= $(shell find include/ -type f)

NAME_FILE	= $(addprefix tuple/,												\
							    init_point										\
							    init_vector										\
							    t_tuple_plus									\
							    t_tuple_minus									\
							    t_tuple_nega									\
							    t_tuple_multi_scal								\
							    t_tuple_div_scal								\
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
			   )																\
			   main																\
			   my_mlx_pixel_put													\
			   equal_float														\

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
	@cd mlx; make >> /dev/null 2>> /dev/null; cd ..
	@ mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(I_HEADERS) -MMD -MP -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(I_HEADERS) $(L_LIB) -o $(NAME)

clean:
	cd mlx; make clean
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPENDS)
