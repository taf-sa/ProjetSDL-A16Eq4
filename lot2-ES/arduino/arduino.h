#ifndef ARDUINO_H_
#define ARDUINO_H_

#include <stdint.h>

int port_init(const char* serialport, int baud);
int port_close(int fd);
int port_writeByte(int fd, uint8_t byte);
int port_write(int fd, const char* str);
int port_read(int fd, char* buffer, char until, int buf_max, int timeout);
int port_flush(int fd);

#endif

