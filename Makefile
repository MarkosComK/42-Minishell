# COLORS
RED    = $(shell printf "\33[31m")
GREEN  = $(shell printf "\33[32m")
WHITE  = $(shell printf "\33[37m")
YELLOW = $(shell printf "\33[33m")
RESET  = $(shell printf "\33[0m")
BLUE   = $(shell printf "\33[34m")
PURPLE = $(shell printf "\33[35m")
TITLE  = $(shell printf "\33[32;40m")

LIBFTDIR = 42-Libft
NAME     = minishell
FLAGS    = -Wall -Wextra -Werror -g -Iincludes
IFLAGS   = -Iincludes/ -I${LIBFTDIR}/src
CC       = cc
SRCS     = $(wildcard srcs/*.c) $(wildcard srcs/*/*.c)
OBJS     = ${SRCS:.c=.o}
INCLUDE  = -L${LIBFTDIR}/src -lft -lreadline
VALGRIND = valgrind  --track-fds=yes --leak-check=full --show-leak-kinds=all --suppressions=readline.supp
ENV      = env -i ${VALGRIND}

#set readline for MacOs and Linux
UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
    INCLUDE = -L${LIBFTDIR}/src -lft -lreadline -lhistory
    READLINE =
else ifeq ($(UNAME), Darwin)
    INCLUDE = -L${LIBFTDIR}/src -lft -L/opt/homebrew/opt/readline/lib -lreadline
    READLINE = -I/opt/homebrew/opt/readline/include
endif

all: submodule ${LIBFTDIR} ${NAME} ${OBJS}

submodule:
	@git submodule update --init --recursive

${NAME}: ${OBJS}
	@make --silent -C ${LIBFTDIR}/src
	@${CC} ${FLAGS} ${READLINE} ${OBJS} ${INCLUDE} -o ${NAME}
	@echo "$(TITLE)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
	@echo "$(PURPLE)  ███╗   ███╗██╗███╗   ██╗██╗██╗  ██╗███████╗██╗     ██╗       "
	@echo "  ████╗ ████║██║████╗  ██║██║██║  ██║██╔════╝██║     ██║       "
	@echo "  ██╔████╔██║██║██╔██╗ ██║██║███████║█████╗  ██║     ██║       "
	@echo "  ██║╚██╔╝██║██║██║╚██╗██║██║██╔══██║██╔══╝  ██║     ██║       "
	@echo "  ██║ ╚═╝ ██║██║██║ ╚████║██║██║  ██║███████╗███████╗███████╗  "
	@echo "  ╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝  "
	@echo "$(GREEN)━━━━━━━━━━━━━━━━━[$(RESET)Made with $(RED)♥ $(RESET)by $(PURPLE)@marsoare$(RESET) and $(PURPLE)@hluiz-ma$(TITLE)]━━━━━━"
	@echo
	@echo "$(GREEN) Successfully compiled minishell.$(RESET)"
	@echo

.c.o:
	@${CC} ${FLAGS} ${READLINE} ${IFLAGS} -c $< -o ${<:.c=.o}
	@clear
	@echo "$(RESET)[$(GREEN)OK$(RESET)]$(BLUE) Compiling $<$(YELLOW)"

clean:
	@${RM} ${OBJS} ${NAME}
	@cd ${LIBFTDIR}/src && $(MAKE) --silent clean
	@clear
	@echo
	@echo "$(RED)┏┓┓ ┏┓┏┓┳┓┏┓┳┓"
	@echo "┃ ┃ ┣ ┣┫┃┃┣ ┃┃"
	@echo "┗┛┗┛┗┛┛┗┛┗┗┛┻┛"
	@echo

fclean: clean
	rm -rf ${LIBFTDIR}
	rm -f ${NAME}
	@clear
	@echo
	@echo "$(RED)┏┓┓ ┏┓┏┓┳┓┏┓┳┓"
	@echo "┃ ┃ ┣ ┣┫┃┃┣ ┃┃"
	@echo "┗┛┗┛┗┛┛┗┛┗┗┛┻┛"
	@echo

test: ${NAME} readline.supp
	${VALGRIND} ./${NAME}

readline.supp:
	echo "{" > readline.supp
	echo "    leak readline" >> readline.supp
	echo "    Memcheck:Leak" >> readline.supp
	echo "    ..." >> readline.supp
	echo "    fun:readline" >> readline.supp
	echo "}" >> readline.supp
	echo "{" >> readline.supp
	echo "    leak add_history" >> readline.supp
	echo "    Memcheck:Leak" >> readline.supp
	echo "    ..." >> readline.supp
	echo "    fun:add_history" >> readline.supp
	echo "}" >> readline.supp
	echo "{" >> readline.supp
	echo "    leak rl_parse_and_bind" >> readline.supp
	echo "    Memcheck:Leak" >> readline.supp
	echo "    ..." >> readline.supp
	echo "    fun:add_history" >> readline.supp
	echo "}" >> readline.supp

env: ${NAME}
	${ENV} ./${NAME}

re: fclean all

.PHONY: all bonus clean fclean re test
