# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 23:28:51 by ale-boud          #+#    #+#              #
#    Updated: 2023/06/07 12:56:35 by ale-boud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---
# Tools
# ---

MKDIR := mkdir
RM := rm -f

# ---
# Build variables
# ---

# Compiler

CC := gcc

CWARN := all extra error
CWARN := $(CWARN:%=-W%)

CFLAGS := -c $(CWARN) -Ilibft

# Linker

LD := gcc

# ---
# Lib information
# ---

NAME := push_swap
BONUS := checker
LIBFT := libft.a

SRCS := push_swap.c push_swap_utils1.c push_swap_ctx.c push_swap_func1.c \
		push_swap_func2.c push_swap_func3.c push_swap_sort.c \
		push_swap_utils2.c push_swap_sort_func.c push_swap_issort.c \
		push_swap_sort_small.c push_swap_sort_five.c
OBJS := $(SRCS:%.c=%.o)
SRCS_BONUS := push_swap_ctx.c push_swap_utils1.c checker_bonus.c \
		checker_func1_bonus.c checker_func2_bonus.c checker_func3_bonus.c \
		checker_execute_bonus.c push_swap_issort.c
OBJS_BONUS := $(SRCS_BONUS:%.c=%.o)

# ---
#  General targets
# ---

# Build everything

all: $(NAME)

# Mostly clean (clean everything without the end result)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS) $(LIBFT)
	$(MAKE) clean -C libft

# Clean everything

fclean: clean
	$(RM) $(NAME) $(BONUS)
	$(MAKE) fclean -C libft

# Rebuild

re: fclean all

# Bonus

bonus: all $(BONUS)
	
.PHONY: all clean fclean re bonus

# ---
# Build targets
# ---

libft/libft.a:
	$(MAKE) -C libft

$(LIBFT): libft/libft.a
	cp libft/libft.a $(LIBFT)

$(NAME): $(OBJS) $(LIBFT)
	$(LD) -o $@ $^

$(BONUS): $(OBJS_BONUS) $(LIBFT)
	$(LD) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -I. -o $@ $<
