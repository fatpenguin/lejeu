CXX=g++ -std=c++11
CXXFLAGS=-W -Wall -ansi -pedantic
LIBS=-lsfml-graphics -lsfml-window -lsfml-system
TARGET=controls

all: thegame

clean:
		rm -f *.o
mrproper: clean
		rm -rf $(TARGET)

main.o: main.cpp
		$(CXX) -c main.cpp -o main.o $(CXXFLAGS)

controls.o: controls.cpp controls.hpp player.hpp
		$(CXX) -c controls.cpp -o controls.o $(CXXFLAGS)
	
%.o: %.cpp %.hpp
		$(CXX) -c $< -o $@ $(CXXFLAGS)
	
thegame: main.o controls.o player.o
		$(CXX) main.o controls.o player.o -o $(TARGET) $(LIBS)
		chmod +x $(TARGET)