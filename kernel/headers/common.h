#ifndef COMMON_H
#define COMMON_H


// some typedefs to standardize sizes accross platforms
// these typedefs are written for 32-bit x86
typedef unsigned int        u32int;
typedef int                 s32int;
typedef unsigned short      u16int;
typedef short               s16int;
typedef unsigned char       u8int;
typedef char                s8int;



u8int   port_byte_in(u16int port);
void    port_byte_out(u16int port, u8int data);
u16int  port_word_in(u16int port);
void    port_word_out(u16int port, u16int data);

#endif