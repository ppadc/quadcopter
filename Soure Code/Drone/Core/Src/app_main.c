/*
 * app_main.c
 *
 *  Created on: Mar 14, 2023
 *      Author: nguye
 */


#ifndef USERCODE_APP_MAIN_C_
#define USERCODE_APP_MAIN_C_

#include <buzzer.h>
#include <mav.h>
#include <params.h>
#include "app_main.h"


typedef void (*func_t)(void);
typedef struct{
	func_t 		 	init;
	func_t 		 	deinit;
	on_mav_recv_t 	on_mode_mav_recv;
}app_t;

void app_reset(app_t *app, func_t init, func_t deinit, on_mav_recv_t on_mav_recv){
	app->init = init;
	app->deinit = deinit;
	app->on_mode_mav_recv = on_mav_recv;
}
void app_run_init(app_t *app){
	app->init();
}
void app_run_deinit(app_t *app){
	app->deinit();
}
void app_run_on_msg_recv(app_t *app, mavlink_message_t *msg){
	app->on_mode_mav_recv(msg);
}


#endif /* USERCODE_APP_MAIN_C_ */
