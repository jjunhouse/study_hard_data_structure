NAME := test

CC := gcc
#CFLAGS := -Wall -Wextra -Werror
#CFLAGS := -fsanitize=address -g

SRCS := dfs_graph.c \
	./array_graph/addEdgeAG.c \
	./array_graph/addVertexAG.c \
	./array_graph/checkVertexValid.c \
	./array_graph/createArrayGraph.c \
	./array_graph/deleteArrayGraph.c \
	./array_graph/displayArrayGraph.c \
	./array_graph/isEmptyAG.c \
	./array_graph/removeEdgeAG.c \
	./array_graph/removeVertexAG.c

OBJS := $(SRCS:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS)  -I./ -I./array_graph -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all clean fclean re
