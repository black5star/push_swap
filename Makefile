NAME = push_swap
NAME_B = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror 
SRCS = ./mandatory/push_swap.c ./mandatory/parsing.c ./mandatory/rules.c ./mandatory/ft_error.c ./mandatory/ft_split.c ./mandatory/libft.c ./mandatory/list.c ./mandatory/sorting.c ./mandatory/utils.c ./mandatory/utils2.c
SRCS_B = ./bonus/checker.c ./bonus/error_bonus.c ./bonus/libft_bonus.c ./bonus/list_bonus.c ./bonus/parsing_bonus.c ./bonus/get_next_line.c ./bonus/utils2_bonus.c ./bonus/rules_bonus.c ./bonus/split_bonus.c ./bonus/utils_bonus.c
OBJC = $(SRCS:.c=.o)
OBJC_B = $(SRCS_B:.c=.o)

all: $(NAME)

bonus: $(NAME_B)

$(NAME): $(OBJC)
	@$(CC) $(CFLAGS) $(SRCS) -o push_swap
	@echo "executable file is ready"

$(NAME_B): $(OBJC_B)
	@$(CC) $(CFLAGS) $(SRCS_B) -o checker
	@echo "checker is ready"

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	@rm -f $(OBJC) $(OBJC_B)
	@echo "objects removed"

fclean:clean
	@rm  -f $(NAME) $(NAME_B)
	@echo "executable removed"

re: fclean all
