/*
 * Serial.h
 *
 *  Created on: Oct 10, 2019
 *      Author: 16138
 */

#ifndef USERCODE_SERIAL_SERIAL_H_
#define USERCODE_SERIAL_SERIAL_H_

#include <circular_buffer.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <timer.h>

#include "usart.h"

#include "user_define.h"

typedef struct{
	// Public elements. Should be changed by user
	UART_HandleTypeDef* huart;
	uint32_t	cb_period;

	// Private elements. Should not be changed by user. User to store internal data
	uint8_t tx_dma_buffer[TX_DMA_BUF_SIZE];
	uint8_t rx_dma_buffer[RX_DMA_BUF_SIZE];

	circular_buf_t tx_cbuf_handle;
	uint8_t tx_buf[TX_CIR_BUF_SIZE];

	circular_buf_t rx_cbuf_handle;
	uint8_t rx_buf[RX_CIR_BUF_SIZE];

	timer_id_t cbid;
	bool tx_completed;
}uart_drv_t;

int uart_init(uart_drv_t* uart_drv);

int uart_send_chr(uart_drv_t* uart_drv, char chr);
int uart_recv_chr(uart_drv_t* uart_drv, char *chr);

int uart_send(uart_drv_t *uart_drv, char *data, uint16_t len);
int uart_recv(uart_drv_t *uart_drv, char *data, uint16_t *len);
int uart_readline(uart_drv_t* uart_drv, char *data, int timeout);

void uart_tx_reset(uart_drv_t* uart_drv);
void uart_rx_reset(uart_drv_t* uart_drv);
void uart_reset(uart_drv_t* uart_drv);

#endif /* USERCODE_SERIAL_SERIAL_H_ */
