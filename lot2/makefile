CC  = gcc 
CFLAGS = -Og -g
CSDL = `sdl-config --libs --cflags` -lSDL_ttf -lSDL_image -lSDL_mixer
HEADERS = $(wildcard *.h)
SOURCES = $(wildcard *.c) 
OBJECTS = $(SOURCES:.c=.o)
BIN = savior 

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

#%.debug: % makefile
#	objcopy --only-keep-debug $< $@

#%.o : %.c
#	$(CC) -c $(CFLAGS) $< -o $@

#$(OBJECTS): %.o: %.c makefile
#	$(CC) $(CFLAGS) -c $<

#object: $(SOURCES)

##	$(CC) $(CFLAGS) $(CSDL) $^

