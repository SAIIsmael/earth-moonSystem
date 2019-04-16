NAME	=	Ex

CXX	=	gcc

LDFLAGS	=	-lglut -lGL -lGLU -lm

SRCS	=	main.c  \

CXXFLAGS=	-W -Wall -ansi -pedantic -I./inc

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)

re: fclean all
