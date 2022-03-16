/*
 * Menu.c
 *
 *  Created on: 25 Şub 2022
 *      Author: ahmet
 */

#include "Menu.h"
#include "stm32f0xx_hal.h"
#include "string.h"

#include "stdbool.h"
#define BT GPIO_PIN_7
#define PORTS GPIOA

extern char Menu0[];
extern char Menu1[];
extern char Menu2[];
extern char Menu3[];



uint8_t btn;
uint8_t btn1;
uint8_t x;
TIM_HandleTypeDef htim1;
uint8_t ad;
uint8_t add;
uint8_t pot;




void anaMenu() {



	   if (HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_7)){
	   	   btn=true;
	   	   lcd_clear();
	   	   HAL_Delay(500);
	   	   bose();
	      	 }
	      else {
	   	btn=false;
	        }


	   	   while(btn){

	   	    add=ad;
	   	    ad=__HAL_TIM_GET_COUNTER(&htim1)/5;


	   	     if (ad==add) {
	   		}
	   	   else{
	   		lcd_clear();
	   		updateMenu(ad);

	   	    }


	   	   if (HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_7)){
	   		   executeAction(ad);

	   		   if (ad==1) {
	   			   lcd_clear();
	   			   lcd_send_string("Bekleyiniz:");
	   			   HAL_Delay(1000);
	   			   break;
	   		}

	    	   }

	   		}






	  }

void bose(){

			  lcd_gotoxy(1, 0);
			  lcd_send_string(Menu0);
			  lcd_gotoxy(1, 1);
			  lcd_send_string(Menu1);
			  lcd_gotoxy(1, 2);
			  lcd_send_string(Menu2);
			  lcd_gotoxy(1, 3);
			  lcd_send_string(Menu3);
}




void updateMenu(uint8_t menu) {

  switch (menu) {
    case 0:
      bose();
      menu = 5;

       break;
    case 1:

    	  lcd_gotoxy(0, 0);
          lcd_send_string(Menu);
		  lcd_gotoxy(1, 0);
		  lcd_send_string(Menu0);
		  lcd_gotoxy(1, 1);
		  lcd_send_string(Menu1);
		  lcd_gotoxy(1, 2);
		  lcd_send_string(Menu2);
		  lcd_gotoxy(1, 3);
		  lcd_send_string(Menu3);
      break;
    case 2:
    	  lcd_gotoxy(1, 0);
          lcd_send_string(Menu0);
		  lcd_gotoxy(0, 1);
		  lcd_send_string(Menu);
		  lcd_gotoxy(1, 1);
		  lcd_send_string(Menu1);
		  lcd_gotoxy(1, 2);
		  lcd_send_string(Menu2);
		  lcd_gotoxy(1, 3);
		  lcd_send_string(Menu3);
   	 break;
    case 3:
    	  lcd_gotoxy(1, 0);
          lcd_send_string(Menu0);
		  lcd_gotoxy(1, 1);
		  lcd_send_string(Menu1);
		  lcd_gotoxy(0, 2);
		  lcd_send_string(Menu);
		  lcd_gotoxy(1, 2);
		  lcd_send_string(Menu2);
		  lcd_gotoxy(1, 3);
		  lcd_send_string(Menu3);
   	 break;

    case 4:
    	  lcd_gotoxy(1, 0);
          lcd_send_string(Menu0);
		  lcd_gotoxy(1, 1);
		  lcd_send_string(Menu1);
		  lcd_gotoxy(1, 2);
		  lcd_send_string(Menu2);
		  lcd_gotoxy(0, 3);
		  lcd_send_string(Menu);
		  lcd_gotoxy(1, 3);
		  lcd_send_string(Menu3);
   	 break;
    case 5:
      bose();
      menu = 0;
      break;
  }
}

void executeAction(uint8_t menu) {
  switch (menu) {
    case 1:
      action1();
      break;
    case 2:
      action2();
      break;
    case 3:
      action3();
      break;
    case 4:
      action4();
      menu=1;
      break;

  }
}

void action1() {
	lcd_clear();
}



void action2() {
	lcd_clear();

     while(bnt()){

    	 lcd_gotoxy(0, 0);
    	 lcd_send_string("aksiyon2:");

    	        add=ad;
    		   ad=__HAL_TIM_GET_COUNTER(&htim1);
    		   if (add==ad) {
    			pot=pot;
			   }
    		   else{

    		    pot=ad;}
    		   lcd_send_int(pot);






     }
    //menüden çıkınca set edilen değer.
   lcd_clear();
   bose();

}



void  action3() {
	lcd_clear();
     while(bnt()){

    	 lcd_gotoxy(0, 0);
    	 lcd_send_string("aksiyon3");



     }

     lcd_clear();
     bose();

}


void action4() {
	lcd_clear();
    while(bnt()){

    	 lcd_gotoxy(0, 0);
    	 lcd_send_string("Senior Ahmet Sahin!");
           }
    lcd_clear();
    bose();

}



 uint8_t bnt(){




	 if ( HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_7) && btn1==1) {
			 btn1=0;
			 HAL_Delay(500);

		}
	 if ( HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_7) && btn1==0) {
			 btn1=1;
			 HAL_Delay(500); // buton geçikmesi koymamak işlemi bozuyor.

		}
  return btn1;


}



