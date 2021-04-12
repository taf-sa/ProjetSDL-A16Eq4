#include "arduino.h"
#include <SDL/SDL.h>
#include <stdbool.h>

int main(int argc, char* argv[])
{
    bool done = false;
    int collision = 0;

    const int buf_max = 256;
    int timeout = 5000;
    int baudrate = 9600;

    SDL_Init(SDL_INIT_EVERYTHING);
    atexit(SDL_Quit);

    SDL_Surface* fenetre = SDL_SetVideoMode(300, 200, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

    char str_to_send[] = "Up";
    char a = 'x';
    uint8_t byte = 'a';
    int fd = port_init("/dev/ttyACM0", 9600);

    while (!done) {
        port_read(fd, &a, a, 250, 100);
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    done = true;
                } else if (event.key.keysym.sym == SDLK_y) {
                    printf("%c\n", a);
                    collision = 1;
                    byte = 'a';
                    /** port_write(fd, str_to_send); */
                    port_writeByte(fd, byte);
                    printf("\n COLLISION RIGHT SENDING 1 TO SERIAL");
                } else if (event.key.keysym.sym == SDLK_n) {
                    byte = 'b';
                    collision = 2;
                    /** port_write(fd, str_to_send); */
                    port_writeByte(fd, byte);
                    printf("\n COLLISION LEFT SENDING 2 TO SERIAL");
                } else {
                    collision = 0;
                    byte = 'c';
                    printf("\n COLLISION LEFT SENDING 0 TO SERIAL");
                    port_writeByte(fd, byte);
                }
                break;
            case SDL_QUIT:
                done = true;
                break;
            deflaut:
                break;
            }
        }
    }

    port_close(fd);
    SDL_FreeSurface(fenetre);
    return EXIT_SUCCESS;
}
