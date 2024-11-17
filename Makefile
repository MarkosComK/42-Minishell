# COLORS
RED    = $(shell printf "\33[31m")
GREEN  = $(shell printf "\33[32m")
WHITE  = $(shell printf "\33[37m")
YELLOW = $(shell printf "\33[33m")
RESET  = $(shell printf "\33[0m")
BLUE   = $(shell printf "\33[34m")
PURPLE = $(shell printf "\33[35m")
TITLE  = $(shell printf "\33[32;40m")

LIBFTDIR = libft
NAME     = minishell
NAME_BONUS     = minishell_bonus
FLAGS    = -Wall -Wextra -Werror -g -Iincludes
IFLAGS   = -Iincludes/ -I${LIBFTDIR}/src
CC       = cc
SRC_DIR = srcs
SRCS = \
	$(SRC_DIR)/binary_tree/bst_free.c \
	$(SRC_DIR)/binary_tree/bst_print.c \
	$(SRC_DIR)/binary_tree/bst_print_utils.c \
	$(SRC_DIR)/binary_tree/build_tree.c \
	$(SRC_DIR)/binary_tree/build_tree_utils2.c \
	$(SRC_DIR)/binary_tree/build_tree_utils.c \
	$(SRC_DIR)/built-ins/builtins_utils.c \
	$(SRC_DIR)/built-ins/cd.c \
	$(SRC_DIR)/built-ins/cd_utils.c \
	$(SRC_DIR)/built-ins/echo.c \
	$(SRC_DIR)/built-ins/env.c \
	$(SRC_DIR)/built-ins/env_utils.c \
	$(SRC_DIR)/built-ins/env_utils_sizes.c \
	$(SRC_DIR)/built-ins/exit.c \
	$(SRC_DIR)/built-ins/export.c \
	$(SRC_DIR)/built-ins/export_utils2.c \
	$(SRC_DIR)/built-ins/export_utils.c \
	$(SRC_DIR)/built-ins/pwd.c \
	$(SRC_DIR)/built-ins/unset.c \
	$(SRC_DIR)/built-ins/unset_utils.c \
	$(SRC_DIR)/check_args.c \
	$(SRC_DIR)/error/exit_code.c \
	$(SRC_DIR)/error/exit_messages.c \
	$(SRC_DIR)/error/printers2.c \
	$(SRC_DIR)/error/printers.c \
	$(SRC_DIR)/exec/exec_expand.c \
	$(SRC_DIR)/exec/exec_tree.c \
	$(SRC_DIR)/exec/exec_utils.c \
	$(SRC_DIR)/exec/pids_utils.c \
	$(SRC_DIR)/exec/redirects.c \
	$(SRC_DIR)/exec/redirects_utils.c \
	$(SRC_DIR)/heredoc/heredoc.c \
	$(SRC_DIR)/heredoc/heredoc_expand.c \
	$(SRC_DIR)/heredoc/heredoc_process.c \
	$(SRC_DIR)/input/check_len.c \
	$(SRC_DIR)/input/input_parenthesis.c \
	$(SRC_DIR)/input/input_validation.c \
	$(SRC_DIR)/input/input_validation_utils.c \
	$(SRC_DIR)/logic_tree/build_ltree.c \
	$(SRC_DIR)/logic_tree/build_ltree_utils.c \
	$(SRC_DIR)/logic_tree/ltree_parenthesis2.c \
	$(SRC_DIR)/logic_tree/ltree_parenthesis.c \
	$(SRC_DIR)/logic_tree/ltree_print.c \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/signals/signals.c \
	$(SRC_DIR)/signals/signals_heredoc.c \
	$(SRC_DIR)/terminal/terminal.c \
	$(SRC_DIR)/terminal/terminal_utils.c \
	$(SRC_DIR)/tokenization/check_token_type.c \
	$(SRC_DIR)/tokenization/create_token_lst.c \
	$(SRC_DIR)/tokenization/del_token.c \
	$(SRC_DIR)/tokenization/ft_joinstrs.c \
	$(SRC_DIR)/tokenization/handle_andif.c \
	$(SRC_DIR)/tokenization/handle_expand.c \
	$(SRC_DIR)/tokenization/handle_expand_utils.c \
	$(SRC_DIR)/tokenization/handle_or.c \
	$(SRC_DIR)/tokenization/handle_parenthesis.c \
	$(SRC_DIR)/tokenization/lexer.c \
	$(SRC_DIR)/tokenization/set_token_pos.c \
	$(SRC_DIR)/tokenization/tokenize_utils2.c \
	$(SRC_DIR)/tokenization/tokenize_utils.c \
	$(SRC_DIR)/utils/printers.c \
	$(SRC_DIR)/wildcard/wildcard.c \
	$(SRC_DIR)/wildcard/wildcards_utils2.c \
	$(SRC_DIR)/wildcard/wildcard_utils.c \
	$(SRC_DIR)/wildcard/wildcard_validations.c

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

all: ${LIBFTDIR} ${NAME} ${OBJS}

bonus: ${LIBFTDIR} ${NAME_BONUS} ${OBJS}

${NAME_BONUS}: ${LIBFTDIR} ${OBJS} ${NAME}
	@make --silent -C ${LIBFTDIR}/src
	@${CC} ${FLAGS} ${OBJS} ${READLINE} ${INCLUDE} -o ${NAME_BONUS}
	@echo "\n minishell_bonus created"

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
	@${RM} ${OBJS}
	@cd ${LIBFTDIR}/src && $(MAKE) --silent clean
	@clear
	@echo
	@echo "$(RED)┏┓┓ ┏┓┏┓┳┓┏┓┳┓"
	@echo "┃ ┃ ┣ ┣┫┃┃┣ ┃┃"
	@echo "┗┛┗┛┗┛┛┗┛┗┗┛┻┛"
	@echo

fclean: clean
	rm -f ${NAME}
	@rm -f ${NAME_BONUS}
	@cd ${LIBFTDIR}/src && $(MAKE) --silent fclean
	@clear
	@echo
	@echo "$(RED)┏┓┓ ┏┓┏┓┳┓┏┓┳┓"
	@echo "┃ ┃ ┣ ┣┫┃┃┣ ┃┃"
	@echo "┗┛┗┛┗┛┛┗┛┗┗┛┻┛"
	@echo

test: ${NAME} readline.supp
	${VALGRIND} ./${NAME}

readline.supp:
	@echo "$(RED)"
	@echo "{" > readline.supp
	@echo "    leak readline" >> readline.supp
	@echo "    Memcheck:Leak" >> readline.supp
	@echo "    ..." >> readline.supp
	@echo "    fun:readline" >> readline.supp
	@echo "}" >> readline.supp
	@echo "{" >> readline.supp
	@echo "    leak add_history" >> readline.supp
	@echo "    Memcheck:Leak" >> readline.supp
	@echo "    ..." >> readline.supp
	@echo "    fun:add_history" >> readline.supp
	@echo "}" >> readline.supp
	@echo "{" >> readline.supp
	@echo "    leak rl_parse_and_bind" >> readline.supp
	@echo "    Memcheck:Leak" >> readline.supp
	@echo "    ..." >> readline.supp
	@echo "    fun:add_history" >> readline.supp
	@echo "}" >> readline.supp
	@echo "$(RESET)"

env: ${NAME}
	${ENV} ./${NAME}

re: fclean all

.PHONY: all bonus clean fclean re test
