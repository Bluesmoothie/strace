.PHONY				:	clean fclean re all

NAME				=   ft_strace
MODE 				?= 	release

#			GCC

CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror -MMD -MP $(INCLUDE)

ifeq ($(MODE), debug)
	CXXFLAGS		= 	-Wall -Wextra -MMD -MP $(INCLUDE) -g3 -DDEBUG
endif

#			COMMON

BUILD_DIR			=	.build/
SRC_DIR				=	./src/
INCLUDE 			=	-Iinclude/

#			SRC

VPATH				=

SRC_FILES			=	main			\
						ft_strace		\

SRC 				= 	$(addprefix $(SRC_DIR), $(addsuffix .cpp, $(SRC_FILES)))
OBJ 				= 	$(addprefix $(BUILD_DIR), $(addsuffix .o, $(SRC_FILES)))
DEPS 				= 	$(addprefix $(BUILD_DIR), $(addsuffix .d, $(SRC_FILES)))

#			RULES

all					:	$(NAME)

$(NAME)				:	$(BUILD_DIR) $(OBJ)
					$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(BUILD_DIR)		:
					mkdir -p $(BUILD_DIR)

$(BUILD_DIR)%.o		: 	$(SRC_DIR)%.c
					$(CC) $(CFLAGS) -c $< -o $@

-include $(DEPS)

clean				:
					rm -rf $(BUILD_DIR)

fclean				:	clean
					rm -f $(NAME)

re					:	fclean all