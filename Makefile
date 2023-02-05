SRC_DIR = ./ft_series

SRC_DIR1 = ./mains

SRC_DIR2 = ./mains_bonus

SRC_DIR3 = ./ft_series_bonus

OBJS_DIR = ./objs

OBJS_DIR_BONUS = ./objs_bonus

SRC_A = $(notdir $(wildcard $(SRC_DIR1)/*.c) $(wildcard $(SRC_DIR)/*.c))

SRC_B = $(notdir $(wildcard $(SRC_DIR2)/*.c) $(wildcard $(SRC_DIR3)/*.c))

OBJ_A = $(SRC_A:.c=.o)

OBJ_B = $(SRC_B:.c=.o)

NAME = pipex

ifdef WITH_BONUS
    OBJECTS = $(patsubst %.o,$(OBJS_DIR_BONUS)/%.o,$(OBJ_B))
else
    OBJECTS = $(patsubst %.o,$(OBJS_DIR)/%.o,$(OBJ_A))
endif

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

all : $(NAME)

bonus :
	@make WITH_BONUS=1 all

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

$(OBJS_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ 

$(OBJS_DIR)/%.o : $(SRC_DIR1)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ 

$(OBJS_DIR_BONUS)/%.o : $(SRC_DIR2)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ 

$(OBJS_DIR_BONUS)/%.o : $(SRC_DIR3)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean :
	rm -f $(OBJS_DIR)/*.o
	rm -f $(OBJS_DIR_BONUS)/*.o
	
fclean : clean
	rm -f pipex

re : 
	make fclean
	make all

.PHONY : all clean fclean re bonus
