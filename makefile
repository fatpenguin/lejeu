LIBS=-lsfml-graphics -lsfml-window -lsfml-system
TARGET=sfml-app

all: thegame

clean:
		rm -f sfml-app
		rm -f *.o

main.o: main.cpp
		g++ -c "main.cpp" -o main.o
	
thegame: main.o
		g++ main.o -o $(TARGET) $(LIBS)
		chmod +x $(TARGET)