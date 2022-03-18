/*
 * uart.h
 *
 *  Created on: 8 de set de 2020
 *      Author: lgili
 */

#ifndef UART_H_
#define UART_H_



void uart_init();
void scia_init();
void scia_fifo_init();
void scia_xmit(unsigned char msg);

void scia_send_msg(unsigned char msg);
void uart_receive(unsigned char * msg);

//Uint8 uart_fpga_frame_receive( Uint8 * msg);
//void send_frame(Uint8 frame_type );
//Uint16 frame_parse(Uint8 *msg);

void uartb_init();
void scib_init();
void scib_fifo_init();
void scib_xmit(unsigned char msg);

#endif /* UART_H_ */
