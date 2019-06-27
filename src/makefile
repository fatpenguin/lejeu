CXX = g++

BUILD_DIR = build
TARGET = $(BUILD_DIR)/lejeu

# List libs
LIBS += -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# List sources
SOURCES += main.cpp

# List includes dirs
# INCLUDES +=

# Generate compiled file names
OBJECTS = $(SOURCES:%.cpp=$(BUILD_DIR)/%.o)

# Compile flags
COMPILE_FLAGS = -std=c++11 -Wall -Wextra -g


all: thegame

clean:
		rm -r $(BUILD_DIR)

thegame: prepare $(TARGET)
		chmod +x $(TARGET)

prepare:
	mkdir -p $(BUILD_DIR)

$(TARGET): $(OBJECTS)
	@echo "Linking: $@"
	$(CXX) $(OBJECTS) -o $@ $(LIBS)

$(BUILD_DIR)/%.o: $(SOURCES)
	@echo "Compiling: $< -> $@"
	$(CXX) $(COMPILE_FLAGS) $(INCLUDES) -c $< -o $@