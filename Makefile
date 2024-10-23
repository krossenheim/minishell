SOURCES_DIR = src/

SOURCES_FLS	=	main.c \
				minishell/ft_itoa.c \
				minishell/wildcard.c \
				minishell/wildcard1.c \
				minishell/wildcard2.c \
				minishell/wildcard2_a.c \
				minishell/ft_clean_exit.c \
				minishell/heredoc.c \
				minishell/heredoc2.c \
				minishell/quotes.c \
				minishell/utils.c \
				minishell/utils1.c \
				minishell/utils2.c \
				minishell/signal_handlers.c \
				minishell/builtin_programs.c \
				minishell/builtin_programs1.c \
				minishell/builtin_programs2.c \
				minishell/builtin_programs3.c \
				minishell/builtin_programs3b.c \
				minishell/builtin_programs4.c \
				minishell/env_vars.c \
				minishell/teardown.c \
				minishell/ft_memcpy.c \
				minishell/tokenization.c \
				minishell/tokenization1.c \
				minishell/tokenization2.c \
				minishell/tokenization3.c \
				minishell/tokenization_write.c \
				minishell/tokenization_calc.c \
				minishell/initialization.c \
				minishell/execution.c \
				minishell/execution1.c \
				minishell/execution2.c \
				minishell/execution3.c \
				minishell/execution4.c \
				minishell/parsing1.c \
				minishell/parsing2.c \
				minishell/parsing3.c \
				minishell/set_infile_n_outfile.c \
				minishell/linked_list/ft_lstnew.c	\
				minishell/linked_list/ft_lstsize.c	\
				minishell/linked_list/ft_lstadd_back.c	\
				minishell/linked_list/ft_lstlast.c	\


SOURCES = $(addprefix $(SOURCES_DIR), $(SOURCES_FLS))
OBJS	=	$(SOURCES:%.c=%.o)
NAME = minishell

CFLAGS	= -Wall -Wextra	-Werror -g0 -I ./includes/ -D_DEFAULT_SOURCE -std=c99

%.o:%.c
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	cc $(OBJS) $(CFLAGS) -l readline  -o $(NAME)

all:	$(NAME)
	

re: clean all

clean:
	rm	-f	$(OBJS) $(NAME)

fclean:
	rm	-f	$(OBJS) $(NAME)

fcleanobj:
	rm	-f	$(OBJS)

.phony: make re clean run fclean



