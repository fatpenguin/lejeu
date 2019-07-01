CXX = g++
SRC_EXT = cpp

BUILD_DIR = build
SOURCES_DIR = src
TARGET = $(BUILD_DIR)/lejeu

# List libs
LIBS += -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# List sources and include directories
SOURCES += $(SOURCES_DIR)/main.cpp
INCLUDE_PATHS += $(SOURCES_DIR)

INCLUDE_PATHS += $(SOURCES_DIR)/engine/components

SOURCES += $(SOURCES_DIR)/engine/entities/entities.cpp
INCLUDE_PATHS += $(SOURCES_DIR)/engine/entities

SOURCES += $(SOURCES_DIR)/engine/user_controls/user_controls.cpp
INCLUDE_PATHS += $(SOURCES_DIR)/engine/user_controls

SOURCES += $(SOURCES_DIR)/engine/renderer/renderer.cpp
INCLUDE_PATHS += $(SOURCES_DIR)/engine/renderer/

# Generate include options
INCLUDES = $(addprefix -I, $(INCLUDE_PATHS))

# Generate compiled file names
OBJECTS = $(SOURCES:%.cpp=$(BUILD_DIR)/%.o)

# Generate directory architecture
OBJECT_PATHS = $(dir $(OBJECTS))

# Compile flags
COMPILE_FLAGS = -std=c++11 -Wall -Wextra -g


all: thegame

clean:
	rm -r $(BUILD_DIR)

thegame: prepare $(TARGET)
	chmod +x $(TARGET)

prepare:
	mkdir -p $(BUILD_DIR)
	mkdir -p $(OBJECT_PATHS)

$(TARGET): $(OBJECTS)
	@echo "Linking: $@"
	$(CXX) $(OBJECTS) -o $@ $(LIBS)

$(BUILD_DIR)/%.o: %.$(SRC_EXT)
	@echo "Compiling: $< -> $@"
	$(CXX) $(COMPILE_FLAGS) $(INCLUDES) -c $< -o $@
