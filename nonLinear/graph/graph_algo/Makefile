NAME := test

CC := gcc
#CFLAGS := -Wall -Wextra -Werror
#CFLAGS := -fsanitize=address -g

INCS = -I./heap/MINHEAP/ -I./graph/array_graph/ -I./graph/DFS/

DIR_HEAP = ./heap/MINHEAP
DIR_GRAPH = ./graph/array_graph

SRCS := main.c \
		kruskal.c \
		prim.c \
		dijkstra.c \
		$(DIR_GRAPH)/addEdgeAG.c \
		$(DIR_GRAPH)/addVertexAG.c \
		$(DIR_GRAPH)/checkVertexValid.c \
		$(DIR_GRAPH)/createArrayGraph.c \
		$(DIR_GRAPH)/deleteArrayGraph.c \
		$(DIR_GRAPH)/displayArrayGraph.c \
		$(DIR_GRAPH)/isEmptyAG.c \
		$(DIR_GRAPH)/removeEdgeAG.c \
		$(DIR_GRAPH)/removeVertexAG.c \
		$(DIR_HEAP)/createminHeap.c \
		$(DIR_HEAP)/deleteminHeap.c \
		$(DIR_HEAP)/insertminHeap.c \
		$(DIR_HEAP)/isHeapEmpty.c \
		$(DIR_HEAP)/isHeapFull.c

OBJS := $(SRCS:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all clean fclean re
