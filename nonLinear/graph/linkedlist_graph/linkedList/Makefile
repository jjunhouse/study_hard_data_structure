NAME := linkedlist.a

SRCS := createLinkedList.c \
		addLLElement.c \
		removeLLElement.c \
    	getLLElement.c \
		clearLinkedList.c \
		getLinkedListLength.c \
		deleteLinkedList.c \

OBJS := $(SRCS:%.c=%.o)

CC := gcc
CFLAGS := -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -c $(SRCS) -I./
	ar rc $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all clean fclean re
