NAME = libgarbage.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAG = ruc
RM = rm -f

sources1 :=

sources1 += garbage_collector.c
sources1 += primary.c
sources1 += mem_list.c

objects1 = $(sources1:.c=.o)

# ---- escape ---- #

DELINE = \033[K
CURSUP = \033[A

RESET = \033[0m
RESTINT = \033[22m

BOLD = \033[1m

MAGENTA = \033[35m
GREEN = \033[32m
RED = \033[31m

# ---- Command ---- #

.PHONY : clean fclean re all

all : $(NAME)

$(NAME) : $(objects1)
	@$(AR) $(ARFLAG) $(NAME) $(objects1)
	@echo "$(DELINE) $(MAGENTA)$@ $(RESET) is compiled $(GREEN)$(BOLD) OK ✅ $(RESET)"

%.o : %.c
	@$(CC) $(CCFLAGS) -c $^ -o $@
	@echo " $(MAGENTA)$(NAME) $(RESET)objects file compiling... $(DELINE)$(GREEN) $^ $(RESET)$(CURSUP)"

clean :
	@$(RM) $(objects1)
	@echo "$(RED) Delete$(BOLD) objects $(RESTINT)file $(RESET)"

fclean : clean
	@$(RM) $(NAME)
	@echo "$(RED) Delete$(BOLD) $(NAME) $(RESTINT)file $(RESET)"

re : fclean
	@make
