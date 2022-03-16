/*
 * Menu.h
 *
 *  Created on: 25 Şub 2022
 *      Author: ahmet
 */



#ifndef INC_MENU_H_
#define INC_MENU_H_

#include "stm32f0xx_hal.h";
#include "stdbool.h"





char Menu[]=">";  //Menü işaret belirteci

//Menu başlıkları belirleniyor.....
char Menu0[]="Ana Menu";
char Menu1[]="Uyku ayarlari";
char Menu2[]="Buzzer ayarlari";
char Menu3[]="Gelistirici";










void anaMenu();
uint8_t bnt();

void sanaMenu(void);

void updateMenu(uint8_t menu);
void excuteAction(int menu);

void supdateMenu(int  menu);
void sexecuteAction(int menu);

void action1(void);
void action2(void);
void action3(void);
void action4(void);

void saction1(void);
void saction2(void);
void saction3(void);
void saction4(void);











#endif /* INC_MENU_H_ */
