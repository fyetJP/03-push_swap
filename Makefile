# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpires-p <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/15 01:35:16 by jpires-p          #+#    #+#              #
#    Updated: 2022/09/20 00:17:05 by jpires-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap
STATIC_PS		= $(NAME).a
PUSHSWAP_PATH	= ./
OBJS_PATH		= $(PUSHSWAP_PATH)obj/
LIB_NAME		= libft
LIB_PATH		= $(PUSHSWAP_PATH)$(LIB_NAME)/
LIB_FILE		= $(LIB_PATH)$(LIB_NAME).a
PS_SRCS_PATH	= $(PUSHSWAP_PATH)src/
HEADERS_PATH	= $(PUSHSWAP_PATH)includes/
PS_SRCS			= $(wildcard $(PS_SRCS_PATH)*.c)
PS_OBJS			= $(patsubst $(PS_SRCS_PATH)%.c, $(OBJS_PATH)%.o, $(PS_SRCS))
LIBFT_SRCS		= $(wildcard $(LIB_PATH)src/*.c)
LIBFT_OBJS		= $(patsubst $(LIB_PATH)src/%.c, $(LIB_PATH)objs/%.o, $(LIBFT_SRCS))
PROG_OBJ		= $(OBJS_PATH)$(NAME).o
HEADERS			= $(wildcard $(HEADERS_PATH)*.h)

CHECKER			= checker
STATIC_CHECKER	= $(CHECKER).a
CHEKR_PATH		= ${PUSHSWAP_PATH}$(CHECKER)/
CHEKR_OBJS_PATH	= $(CHEKR_PATH)obj/
CHEKR_PROG		= ${CHEKR_PATH}$(CHECKER)_linux
BONUS_CHECKER	= ${CHEKR_PATH}$(CHECKER)
CHECKER_SRCS	= $(wildcard $(CHEKR_PATH)*.c)
CHECKER_OBJS	= $(patsubst $(CHEKR_PATH)%.c, $(CHEKR_OBJS_PATH)%.o, $(CHECKER_SRCS))
CHECKER_OBJ		= $(CHEKR_OBJS_PATH)$(CHECKER)_bonus.o
MY_PATH			= ${shell pwd}

CC				= gcc
CCDB            = lldb
CFLAGS          = -Wall -Wextra -Werror -fsanitize=address
NORMFSH			= norminette -R CheckForbiddenSourceHeader
NORMDEF			= norminette -R CheckDefine
CREALIB			= ar -crs
GENILIB			= ranlib
MAX_SPAN_NUM	= 5000
MAX_STACK_SIZE	= 500
GENNUMS			= `ruby -e "puts (-$(MAX_SPAN_NUM)..$(MAX_SPAN_NUM)).to_a.shuffle.first($(MAX_STACK_SIZE)).join(' ')"`
VALG			= valgrind -q --leak-check=full -s ${PUSHSWAP_PATH}$(NAME) $(GENNUMS) | cat -e
RM				= rm -f
RM_DIR			= rm -Rf

_ECHO			= echo -e
_AND			= ;
_E				= \e[
_M				= m
_BLACK			= 30
_RED			= 31
_GREEN			= 32
_BROWN			= 33
_BLUE			= 34
_PURPLE			= 35
_CYAN			= 36
_LGRAY			= 37
_DGRAY			= 1;30
_LRED			= 1;31
_LGREEN			= 1;32
_YELLOW			= 1;33
_LBLUE			= 1;34
_LPURPLE		= 1;35
_LCYAN			= 1;36
_WHITE			= 1;37
_BLACK_B		= 40
_RED_B			= 41
_GREEN_B		= 42
_BROWN_B		= 43
_BLUE_B			= 44
_PURPLE_B		= 45
_CYAN_B			= 46
_LGRAY_B		= 47
_END			= 0
_BOLD			= 1
_UDERC			= 4
_BLINKC			= 5
_RST_AA			= $(_E)$(_END)$(_M)
_RST_BOLD		= $(_E)21$(_M)
_RST_ULN		= $(_E)24$(_M)
_RST_BLNK		= $(_E)25$(_M)


all:			$(NAME)

$(LIB_FILE):
				@#$(_ECHO) "$(_E)$(_YELLOW)$(_AND)$(_UDERC)$(_M)Compiling $(LIB_FILE) $(_E)$(_BLINKC)$(_M)... $(_RST_BLNK)"
				@$(MAKE) -C $(LIB_PATH)
				@#$(_ECHO) "$(_RST_AA)[$(_E)$(_GREEN)$(_M)✓$(_RST_AA)]\n"

$(OBJS_PATH):
				mkdir $(OBJS_PATH)
				
$(CHEKR_OBJS_PATH):
				mkdir $(CHEKR_OBJS_PATH)

$(OBJS_PATH)%.o: $(PS_SRCS_PATH)%.c 
				@#$(_ECHO) "$(_E)$(_LBLUE)$(_AND)$(_BOLD)$(_M)Sources: $(_RST_AA)"
				$(CC) ${CFLAGS} -c $< -o $@ -I$(HEADERS_PATH)
				@#$(_ECHO) "$(_E)$(_CYAN)$(_M)$(PS_SRCS)\n$(_RST_AA)"

$(CHEKR_OBJS_PATH)%.o: $(CHEKR_PATH)%.c 
				@#$(_ECHO) "$(_E)$(_LBLUE)$(_AND)$(_BOLD)$(_M)Sources: $(_RST_AA)"
				$(CC) ${CFLAGS} -c $< -o $@ -I$(HEADERS_PATH)
				@#$(_ECHO) "$(_E)$(_CYAN)$(_M)$(PS_SRCS)\n$(_RST_AA)"

$(STATIC_PS):	$(OBJS_PATH) $(LIB_FILE) $(LIBFT_OBJS) $(PS_OBJS)
				$(CREALIB) $(STATIC_PS) $(LIBFT_OBJS) $(PS_OBJS)
				$(GENILIB) $(STATIC_PS)

$(CHEKR_PATH)$(STATIC_CHECKER):	$(CHEKR_OBJS_PATH) $(OBJS_PATH) $(LIB_FILE) $(LIBFT_OBJS) $(PS_OBJS) $(CHECKER_OBJS)
				$(CREALIB) $(CHEKR_PATH)$(STATIC_CHECKER) $(LIBFT_OBJS) $(PS_OBJS) $(CHECKER_OBJS)
				$(GENILIB) $(CHEKR_PATH)$(STATIC_CHECKER)

${NAME}:		$(STATIC_PS)
				@#$(_ECHO) "$(_E)$(_LBLUE)$(_AND)$(_BOLD)$(_M)Compiling $(NAME) 	$(_RST_AA)"
				${CC} ${CFLAGS} -g ${PROG_OBJ} -L $(PUSHSWAP_PATH) -l:$(STATIC_PS) -o ${NAME}
				@#$(_ECHO) "[$(_E)$(_GREEN)$(_M)✓$(_RST_AA)]\n"

$(CHEKR_PATH)$(CHECKER):		$(CHEKR_PATH)$(STATIC_CHECKER)
				@#$(_ECHO) "$(_E)$(_LBLUE)$(_AND)$(_BOLD)$(_M)Compiling $(CHECKER) 	$(_RST_AA)"
				${CC} ${CFLAGS} -g ${CHECKER_OBJ} -L $(CHEKR_PATH) -l:$(STATIC_CHECKER) -o $(CHEKR_PATH)${CHECKER}
				@#$(_ECHO) "[$(_E)$(_GREEN)$(_M)✓$(_RST_AA)]\n"

bonus:			$(CHEKR_PATH)$(CHECKER) ${NAME}

bonus_check:	${NAME} $(CHEKR_PATH)$(CHECKER)
				@#$(_ECHO) "$(_E)$(_PURPLE)$(_AND)$(_BOLD)$(_M)Checking $(NAME) $(_E)$(_BLINKC)$(_M)... \n$(_RST_AA)"
				ARG=$(GENNUMS); ${PUSHSWAP_PATH}$(NAME) $$ARG | $(BONUS_CHECKER) $$ARG
				@#$(_ECHO) "$(_E)$(_PURPLE)$(_M)Finished Checking\n$(_RST_AA)"

cnorm:
				@#$(_ECHO) "$(_E)$(_YELLOW)$(_M)Checking Norm $(_E)$(_BLINKC)$(_M) ... $(_RST_BLNK)\n"
				$(NORMFSH) $(PS_SRCS) $(CHECKER_SRCS)
				$(NORMDEF) $(HEADERS)
				@#$(_ECHO) "Norm Check Finished! $(_RST_AA)"

valgd:			${NAME}
				@#$(_ECHO) "$(_E)$(_YELLOW)$(_AND)$(_BOLD)$(_M)Checking for leaks $(_E)$(_BLINKC)$(_M)... \n$(_RST_AA)"
				$(VALG)
				@#$(_ECHO) "$(_E)$(_YELLOW)$(_M)Finished checking leaks!\n$(_RST_AA)"

run:			${NAME}
				@#$(_ECHO) "$(_E)$(_PURPLE)$(_AND)$(_BOLD)$(_M)Running $(NAME) $(_E)$(_BLINKC)$(_M)... \n$(_RST_AA)"
				${PUSHSWAP_PATH}$(NAME) $(GENNUMS)
				@#$(_ECHO) "$(_E)$(_PURPLE)$(_M)Finished\n$(_RST_AA)"

count_l:		${NAME}
				@#$(_ECHO) "$(_E)$(_PURPLE)$(_AND)$(_BOLD)$(_M)Running $(NAME) $(_E)$(_BLINKC)$(_M)... \n$(_RST_AA)"
				${PUSHSWAP_PATH}$(NAME) $(GENNUMS) | wc -l
				@#$(_ECHO) "$(_E)$(_PURPLE)$(_M)Finished\n$(_RST_AA)"

check:			
				@#$(_ECHO) "$(_E)$(_PURPLE)$(_AND)$(_BOLD)$(_M)Checking $(NAME) $(_E)$(_BLINKC)$(_M)... \n$(_RST_AA)"
				ARG=$(GENNUMS); ${PUSHSWAP_PATH}$(NAME) $$ARG | $(CHEKR_PROG) $$ARG
				@#$(_ECHO) "$(_E)$(_PURPLE)$(_M)Finished Checking\n$(_RST_AA)"

dbug:			${NAME}
				@#$(_ECHO) "$(_E)$(_LRED)$(_AND)$(_UDERC)$(_M)Starting Debug Mode $(_E)$(_BLINKC)$(_M)... \n$(_RST_BLNK)$(_RST_ULN)"
				${CCDB} ${NAME}
				@#$(_ECHO) "$(_E)$(_LRED)$(_M)Debug Finished\n$(_RST_AA)"

cleanlib:
				$(MAKE) -C $(LIB_PATH) fclean

cleanbonus:
				@#$(_ECHO) "$(_E)$(_LGREEN)$(_AND)$(_UDERC)$(_M)Cleaning {$(CHEKR_OBJS_PATH)} $(_E)$(_BLINKC)$(_M)... \n$(_RST_BLNK)$(_RST_ULN)"
				$(RM_DIR) $(CHEKR_OBJS_PATH) 
				@#$(_ECHO) "cleaning Finished\n$(_RST_AA)"

fcleanbonus:	cleanbonus
				@#$(_ECHO) "$(_E)$(_LGREEN)$(_AND)$(_UDERC)$(_M)Cleaning {$(CHECKER)}	 $(_E)$(_BLINKC)$(_M)... \n$(_RST_BLNK)$(_RST_ULN)"
				$(RM) $(CHEKR_PATH)$(STATIC_CHECKER) $(CHEKR_PATH)${CHECKER} 
				@#$(_ECHO) "cleaning Finished\n$(_RST_AA)"

clean:			cleanlib
				@#$(_ECHO) "$(_E)$(_LGREEN)$(_AND)$(_UDERC)$(_M)Cleaning {$(PUSHSWAP_PATH)} and {$(LIB_PATH)} $(_E)$(_BLINKC)$(_M)... \n$(_RST_BLNK)$(_RST_ULN)"
				$(RM_DIR) $(OBJS_PATH) 
				@#$(_ECHO) "cleaning Finished\n$(_RST_AA)"

fclean:			clean fcleanbonus
				@#$(_ECHO) "$(_E)$(_LGREEN)$(_AND)$(_UDERC)$(_M)Cleaning {$(NAME)}	 $(_E)$(_BLINKC)$(_M)... \n$(_RST_BLNK)$(_RST_ULN)"
				$(RM) $(STATIC_PS) ${NAME} 
				@#$(_ECHO) "cleaning Finished\n$(_RST_AA)"

re:				fclean all

.PHONY:			all clean fclean re
