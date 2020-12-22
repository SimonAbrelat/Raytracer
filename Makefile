CC := g++
CPPFLAGS := -std=c++17 $(shell pkg-config --cflags sdl2)
CXXFLAGS := $(shell pkg-config --libs sdl2)
TARGET := general

SRCS := $(wildcard src/*.cpp)
OBJS := $(patsubst src/%.cpp,obj/%.o,$(SRCS))

#all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(CXXFLAGS)
obj/%.o: src/%.cpp
	$(CC) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<
clean:
	rm -rf $(TARGET) *.o

.PHONY: all clean
