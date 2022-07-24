TARGET:=humanfx
SOURCE:=$(wildcard *.c)

all: $(TARGET)

$(TARGET): $(SOURCE)
	gcc -Wall -Wextra -o $@ $^ -lusb-1.0

run: $(TARGET)
	./$(TARGET)

install: $(TARGET)
	mkdir --parents "$(HOME)/.local/bin"
	cp "$(TARGET)" "$(HOME)/.local/bin"

uninstall:
	rm --force "$(HOME)/.local/bin/$(TARGET)"
	rmdir --ignore-fail-on-empty "$(HOME)/.local/bin"
	rmdir --ignore-fail-on-empty "$(HOME)/.local"

clean:
	rm --force "$(TARGET)"