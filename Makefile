# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/30 11:10:11 by lvirgini          #+#    #+#              #
#    Updated: 2020/04/02 11:30:35 by lvirgini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----------------- #
#	 VARIABLES		#
# ----------------- #

NAME =		libasm.a

#HEADERS = 	./includes/libft.h  ./includes/ft_printf.h
HEADERS = 	libasm.h
OBJ_DIR =	obj/
#INC_DIR = 	$(shell find includes -type d)
#SRC_DIR = 	$(shell find srcs -type d)

#vpath %.s $(foreach dir, $(SRC_DIR), $(dir):)

SRC =		ft_strcpy.s

#SRC		= 	$(foreach dir, $(SRC_DIR), $(foreach file, $(wildcard $(dir)/*.s), $(notdir $(file))))
OBJ 	=	$(addprefix $(OBJ_DIR), $(SRC:%.s=%.o))


# ----------------- #
#	 COMPILATION	#
# ----------------- #


CC = 		gcc

CFLAG =		
#-Wall -Werror -Wextra
 

# ----------------- #
#	  FONCTIONS		#
# ----------------- #

$(OBJ_DIR)%.o: %.s $(HEADERS)
			mkdir -p $(OBJ_DIR)
			@echo "\033[32mCompilation de ... $(foreach file, $< , $(notdir $<))\033[0m"
			nasm -f elf64 -o $@ $<
			
			
#nasm -f elf64 -o $@ $<
			
$(NAME):	$(OBJ) 		
			ar rcs ${NAME} ${OBJ}
	
all:		${NAME}

debug :		$(NAME)
			$(CC) $(CFLAG) $(NAME) main.c -I .

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


# ----------------- #
# 		CLEAN		#
# ----------------- #

clean:
			@rm -rf $(OBJ_DIR)
			@echo "\033[36;1m ------>>  clean\033[0m"

fclean:		clean
			@rm -f $(NAME)
			@echo "\033[36;1m ------>> fclean\033[0m"

re:			fclean all

.PHONY: 	all clean fclean re