# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/11 17:55:08 by kefujiwa          #+#    #+#              #
#    Updated: 2021/07/16 23:19:01 by kefujiwa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### MAKEFILE ###

## COLORS ##

# Formats #
_RESET				= \x1b[0m
_BOLD				= \x1b[1m
_DIM				= \x1b[2m
_UNDER				= \x1b[4m
_BLINK				= \x1b[5m
_REV				= \x1b[7m
_HIDDEN				= \x1b[8m

# Foreground Colors #
_GREY				= \x1b[30m
_RED				= \x1b[31m
_GREEN				= \x1b[32m
_YELLOW				= \x1b[33m
_BLUE				= \x1b[34m
_PURPLE				= \x1b[35m
_CYAN				= \x1b[36m
_WHITE				= \x1b[37m

# Background Colors #
_BGREY				= \x1b[40m
_BRED				= \x1b[41m
_BGREEN				= \x1b[42m
_BYELLOW			= \x1b[43m
_BBLUE				= \x1b[44m
_BPURPLE			= \x1b[45m
_BCYAN				= \x1b[46m
_BWHITE				= \x1b[47m


# **************************************************************************** #

## VARIABLES ##

# Compilation #
CC					= gcc
CFLAGS				= -Wall -Wextra -Werror
AR					= ar rcs

# Delete #
RM					= rm -rf

# Directories #
HEADER_DIR			= includes/
SRCS_DIR			= srcs/
OBJS_DIR			= objs/
INIT_DIR			= init/
UTILS_DIR			= utils/

# Files #
INIT				= init_data.c \
					  init_mutex.c \
					  init_philo.c
INIT_SRCS			= $(addprefix $(INIT_DIR), $(INIT))

UTILS				= ft_atoi.c \
					  ft_isdigit.c \
					  ft_isspace.c \
					  ft_putchar_fd.c \
					  ft_putendl_fd.c \
					  ft_putnbr_fd.c \
					  ft_putstr_fd.c \
					  ft_strlcat.c \
					  ft_strlcpy.c \
					  ft_strlen.c
UTILS_SRCS			= $(addprefix $(UTILS_DIR), $(UTILS))

SRCS				= main.c \
					  clear_data.c \
					  get_timestamp.c \
					  puterr_and_return.c \
					  $(INIT_SRCS) \
					  $(UTILS_SRCS)

# Compiled Files #
OBJS				= $(SRCS:%.c=$(OBJS_DIR)%.o)

# Executable #
NAME				= philo


# **************************************************************************** #

## RULES ##

# Main Rules #
all:				$(NAME)

clean:
					@echo "$(_RED)Cleaning Philosophers objects...\n$(_RESET)"
					@$(RM) objs/

fclean:
					@echo "$(_RED)Cleaning Philosophers objects...\n$(_RESET)"
					@$(RM) objs/
					@echo "$(_RED)Deleting executable '$(NAME)'...\n$(_RESET)"
					@$(RM) $(NAME)

re:					fclean all

# Variable Rules #
$(NAME):			$(OBJS_DIR) $(OBJS)
						@$(CC) $(CFLAGS) -I $(HEADER_DIR) $(OBJS) $(LIBFT_NAME) -o $(NAME)
						@echo "\n\n$(_GREEN)Executable '$(NAME)' created.\n$(_RESET)"
						@echo "$(_BLUE)Try \"./philo\".$(END)"

# Compiled Source Files #
$(OBJS_DIR)%.o: 	$(SRCS_DIR)%.c
						@printf "$(_YELLOW)Generating Philosophers objects... %-33.33s\r$(_RESET)" $@
						@$(CC) $(CFLAGS) -I $(HEADER_DIR) -c $< -o $@

$(OBJS_DIR):
					@mkdir -p $(OBJS_DIR)
					@mkdir -p $(OBJS_DIR)$(INIT_DIR)
					@mkdir -p $(OBJS_DIR)$(UTILS_DIR)

# Phony #
.PHONY:				all clean fclean re
