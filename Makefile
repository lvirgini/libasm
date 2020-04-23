# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/30 11:10:11 by lvirgini          #+#    #+#              #
#    Updated: 2020/04/23 16:18:08 by lvirgini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----------------- #
#	 VARIABLES		#
# ----------------- #

NAME =		libasm.a

HEADERS = 	incs/libasm.h

OBJ_DIR =	obj/
SRC_DIR = 	srcs/

vpath %.s $(foreach dir, $(SRC_DIR), $(dir):)

SRCS =		ft_strlen.s \
			ft_strcmp.s \
			ft_strcpy.s \
			ft_strdup.s \
			ft_write.s	\
			ft_read.s	\
			ft_atoi_base.s \
			ft_list_size.s \
			ft_list_sort.s \
			ft_list_remove_if.s \
			ft_list_push_front.s 


SRC		= 	$(foreach dir, $(SRC_DIR), $(foreach file, $(wildcard $(dir)/*.s), $(notdir $(file))))
OBJ 	=	$(addprefix $(OBJ_DIR), $(SRC:%.s=%.o))


# ----------------- #
#	 COMPILATION	#
# ----------------- #


CC = 		gcc

CFLAG =		-Wall -Werror -Wextra -g
 

# ----------------- #
#	  FONCTIONS		#
# ----------------- #

$(OBJ_DIR)%.o: %.s $(HEADERS)
			@mkdir -p $(OBJ_DIR)
			@echo "\033[32mCompilation de ... $(foreach file, $< , $(notdir $<))\033[0m"
			@nasm -f elf64 -o $@ $<
			
$(NAME):	$(OBJ) 		
			@ar rcs ${NAME} ${OBJ}
			@echo "\n\33[32mlibasm.a ... Done\33[0m"
	
all:		${NAME}

debug :		$(NAME)
			$(CC)  main.c -I . -l asm -L .
			@echo "debug with main.c Done !"

show	:
			@echo "SRC_DIR : $(SRC_DIR)\n"
			@echo "LIB_DIR : $(LIB_DIR)\n"
			@echo "INC_DIR : $(INC_DIR)\n"
			@echo "CFLAG : $(CFLAG)\n"
			@echo "IFLAG : $(IFLAG)\n"
			@echo "LFLAG : $(LFLAG)\n"
			@echo "HEADERS : $(foreach file, $(HEADERS),\n\t$(file))\n"
			@echo "SRC :$(foreach file, $(SRC),\n\t$(file))\n"
			@echo "OBJ :$(foreach file, $(OBJ),\n\t$(file))\n"


bonus	:	all

# ----------------- #
# 		CLEAN		#
# ----------------- #

clean:
			@rm -rf $(OBJ_DIR)
			@echo "\033[36;1m ------>>  clean\033[0m\n"

fclean:		clean
			@rm -f $(NAME)
			@echo "\033[36;1m ------>> fclean\033[0m\n"

re:			fclean all

.PHONY: 	all clean fclean re debug