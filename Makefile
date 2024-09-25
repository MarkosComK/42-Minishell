# COLORS
RED    = $(shell printf "\33[31m")
GREEN  = $(shell printf "\33[32m")
WHITE  = $(shell printf "\33[37m")
YELLOW = $(shell printf "\33[33m")
RESET  = $(shell printf "\33[0m")
BLUE = $(shell printf "\33[34m")
PURPLE = $(shell printf "\33[35m")
TITLE = $(shell printf "\33[32;40m")

LIBFTDIR = 42-Libft
NAME = minishell
FLAGS = -Wall -Wextra -Werror -g -Iincludes
IFLAGS = -Iincludes/ -I${LIBFTDIR}/src
CC = cc
SRCS = $(wildcard srcs/*.c) $(wildcard srcs/*/*.c)
OBJS = ${SRCS:.c=.o}
INCLUDE = -L${LIBFTDIR}/src -lft -lreadline
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --suppressions=readline.supp

all: ${NAME}

.c.o:
	@${CC} ${FLAGS} ${IFLAGS} -c $< -o ${<:.c=.o}
	@echo "$(RESET)[$(GREEN)OK$(RESET)]$(BLUE) Compiling $<$(YELLOW)"

${NAME}: ${OBJS}
	@make --silent -C $(LIBFTDIR)/src
	@${CC} ${FLAGS} ${OBJS} ${INCLUDE} -o ${NAME}
	@echo "$(TITLE)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
	@echo "$(PURPLE)  ██╗  ██╗███████╗██╗     ██╗     ███████╗██╗  ██╗  "
	@echo "  ██║  ██║██╔════╝██║     ██║     ██╔════╝██║  ██║  "
	@echo "  ███████║█████╗  ██║     ██║     ███████╗███████║  "
	@echo "  ██╔══██║██╔══╝  ██║     ██║     ╚════██║██╔══██║  "
	@echo "  ██║  ██║███████╗███████╗███████╗███████║██║  ██║  "
	@echo "  ╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝╚══════╝╚═╝  ╚═╝  "
	@echo "$(GREEN)━━━━━━[$(RESET)Made with $(RED)♥ $(RESET)by $(PURPLE)@marsoare$(RESET) and $(PURPLE)@hluiz-ma$(TITLE)]━━━━━━"
	@echo
	@echo "$(GREEN) Successfully compiled minishell.$(RESET)"
	@echo


clean:
	@${RM} ${OBJS} ${NAME}
	@cd $(LIBFTDIR)/src && $(MAKE) --silent clean
	@clear
	@echo
	@echo "$(RED)┏┓┓ ┏┓┏┓┳┓┏┓┳┓"
	@echo "┃ ┃ ┣ ┣┫┃┃┣ ┃┃"
	@echo "┗┛┗┛┗┛┛┗┛┗┗┛┻┛"
	@echo

fclean: clean
	rm -f ${NAME}
	@clear
	@echo
	@echo "$(RED)┏┓┓ ┏┓┏┓┳┓┏┓┳┓"
	@echo "┃ ┃ ┣ ┣┫┃┃┣ ┃┃"
	@echo "┗┛┗┛┗┛┛┗┛┗┗┛┻┛"
	@echo

test: ${NAME}
	${VALGRIND} ./${NAME}

re: fclean all

.PHONY: all bonus clean fclean re test
