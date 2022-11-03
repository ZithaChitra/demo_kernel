#include "headers/common.h"

/*
    mov dx, 0x3f3       ; must use dx to store the port address
    in  al, dx          ; read contents of port to al
    or  al, 00001000b   ; switch on something
    out dx, al          ; update something
*/


// write byte to specified port
void
outb(u16int port, u8int value)
{
    // asm volatile (""::"");
}

u8int 
port_byte_in(u16int port)
{

    // read byte from port
    // "=a" (result) means: put al register in var result when finished
    // "d" (port) means: load edx with port
    u8int result;
    __asm__("in %%dx, %%al": "=a" (result) : "d"(port));
    return result;

}


void
port_byte_out(u16int port, u8int data)
{

    // "a" (data) means: load eax with data
    // "d" (port) means: load edx eith data
    __asm__("out %%al, %%dx": : "a"(data), "d"(port));
    return;

}

u16int
port_word_in(u16int port)
{

    u16int result;
    __asm__("in %%dx, %%ax": "=a"(result) : "d"(port));
    return result;

}


void
port_word_out(u16int port, u16int data)
{

    __asm__("out %%ax, %%dx" : : "a"(data), "d"(port));
    return;

}












