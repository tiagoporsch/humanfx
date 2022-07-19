TARGET:=humanfx
SOURCE:=$(wildcard *.c)

all: $(TARGET)

$(TARGET): $(SOURCE)
	gcc -Wall -Wextra -o $@ $^ -lusb-1.0

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)