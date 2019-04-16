NAME	=	tel

CXX	=	g++

LDFLAGS	=	-lncurses -lglut -lGL -lGLU -lm

SRCS	=	../src/main.cpp              \
			../src/planet.cpp            \
			../src/vect.cpp              \
			../src/color.cpp             \
			../src/earthMoonSystem.cpp   \
			../src/RGBpixmap.cpp         \
			../src/camera.cpp

CXXFLAGS= -ansi -pedantic -I./inc -std=c++11

OBJS	=	$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)

re: fclean all
