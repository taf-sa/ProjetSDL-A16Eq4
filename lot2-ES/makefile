CC  = gcc 
CFLAGS = -std=gnu99 -Og -g
CSDL = `sdl-config --libs --cflags` -lSDL_ttf -lSDL_image -lSDL_mixer
HEADERS = $(wildcard *.h)
SOURCES = $(wildcard *.c) 
OBJECTS = $(SOURCES:.c=.o)
BIN = jeu 

all: dependencies $(BIN) 

$(BIN): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $(BIN) $(CFLAGS) -lm $(CSDL)

clean:
	@rm -f *.o *.a *.so *.debug
	@rm $(BIN)

dependencies: ;@$(value deps)

define deps = 
	pkgs='libsdl1.2-dev libsdl-image1.2-dev libsdl-mixer1.2-dev libsdl-ttf2.0-dev'
	install=false
	for pkg in $pkgs; do
		status="$(dpkg-query -W --showformat='${db:Status-Status}' "$pkg" 2>&1)"
		if [ ! $? = 0 ] || [ ! "$status" = installed ]; then
			install=true
			break
		fi
	done
	if "$install"; then
		sudo apt install --yes $pkgs
	fi
endef

.ONESHELL:
.PHONY: all clean
