LIBS=-lsfml-graphics -lsfml-window -lsfml-system

all: thegame

clean:
		@echo "** Removing object files and executable..."
		rm -f sfml-app
		rm -f *.o

main.o: main.cpp
		g++ -c "main.cpp" -o main.o
	
thegame: main.o
		g++ main.o -o sfml-app $(LIBS)