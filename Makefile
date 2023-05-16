# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 23:28:51 by ale-boud          #+#    #+#              #
#    Updated: 2023/05/16 10:54:01 by ale-boud         ###   ########.fr        #
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

CFLAGS := -c -g $(CWARN) -Ilibft

# Linker

LD := gcc

# ---
# Lib information
# ---

NAME := push_swap
LIBFT := libft.a

SRCS := push_swap.c push_swap_utils.c push_swap_ctx.c
OBJS := $(SRCS:%.c=%.o)
SRCS_BONUS := 
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
	$(RM) $(NAME)
	$(MAKE) fclean -C libft

# Rebuild

re: fclean all

# Bonus

bonus: all
	
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

%.o: %.c
	$(CC) $(CFLAGS) -I. -o $@ $<
