CC  = gcc 
CFLAGS = -Og -g
CSDL = `sdl-config --libs --cflags` -lSDL_ttf -lSDL_image -lSDL_mixer
HEADERS = $(wildcard *.h)
SOURCES = $(wildcard *.c) 
OBJECTS = $(SOURCES:.c=.o)
BIN = savior 

all: $(BIN)

$(BIN): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $(BIN) $(CFLAGS) -lm $(CSDL)

#%.debug: % makefile
#	objcopy --only-keep-debug $< $@

#%.o : %.c
#	$(CC) -c $(CFLAGS) $< -o $@

#$(OBJECTS): %.o: %.c makefile
#	$(CC) $(CFLAGS) -c $<

#object: $(SOURCES)
#	$(CC) $(CFLAGS) $(CSDL) $^

clean:
	@rm -f *.o *.a *.so *.debug
	@rm $(BIN)

.PHONY: all clean
