//LCD kullanýmý
sbit LCD_RS at RB6_bit;
sbit LCD_EN at RB7_bit;
sbit LCD_D4 at RB2_bit;
sbit LCD_D5 at RB3_bit;
sbit LCD_D6 at RB4_bit;
sbit LCD_D7 at RB5_bit;
sbit LCD_RS_Direction at TRISB6_bit;
sbit LCD_EN_Direction at TRISB7_bit;
sbit LCD_D4_Direction at TRISB2_bit;
sbit LCD_D5_Direction at TRISB3_bit;
sbit LCD_D6_Direction at TRISB4_bit;
sbit LCD_D7_Direction at TRISB5_bit;
void main() {
   TRISA = 0b10110000;
   TRISB = 0b00000011;
   PORTA = 0;
   PORTB = 0;
   Lcd_Init();
   Lcd_Cmd(_LCD_CLEAR);
   Lcd_Cmd(_LCD_CURSOR_OFF);
   Lcd_Out(1, 4, "MITHRANDIR");
   delay_ms(1000);
   Lcd_Cmd(_LCD_CLEAR);
   Lcd_Cmd(_LCD_BLINK_CURSOR_ON);
   while(1){
      PORTA = 0b00000001;
      if(PORTA.B5 == 1){
         while(PORTA.B5 != 0){}
         Lcd_Out_CP("7");
      }
      else if(PORTA.B4 == 1){
         while(PORTA.B4 != 0){}
         Lcd_Out_CP("4");
      }
      else if(PORTB.B0 == 1){
         while(PORTB.B0 != 0){}
         Lcd_Out_CP("1");
      }
      else if(PORTB.B1 == 1){
         while(PORTB.B1 != 0){}
         Lcd_Cmd(_LCD_CLEAR);
      }

      PORTA = 0b00000010;
      if(PORTA.B5 == 1){
         while(PORTA.B5 != 0){}
         Lcd_Out_CP("8");
      }
      else if(PORTA.B4 == 1){
         while(PORTA.B4 != 0){}
         Lcd_Out_CP("5");
      }
      else if(PORTB.B0 == 1){
         while(PORTB.B0 != 0){}
         Lcd_Out_CP("2");
      }
      else if(PORTB.B1 == 1){
         while(PORTB.B1 != 0){}
         Lcd_Out_CP("0");
      }

      PORTA = 0b00000100;
      if(PORTA.B5 == 1){
         while(PORTA.B5 != 0){}
         Lcd_Out_CP("9");
      }
      else if(PORTA.B4 == 1){
         while(PORTA.B4 != 0){}
         Lcd_Out_CP("6");
      }
      else if(PORTB.B0 == 1){
         while(PORTB.B0 != 0){}
         Lcd_Out_CP("3");
      }
      else if(PORTB.B1 == 1){
         while(PORTB.B1 != 0){}
         Lcd_Out_CP("=");
      }

      PORTA = 0b00001000;
      if(PORTA.B5 == 1){
         while(PORTA.B5 != 0){}
         Lcd_Out_Cp("/");
      }
      else if(PORTA.B4 == 1){
         while(PORTA.B4 != 0){}
         Lcd_Out_CP("x");
      }
      else if(PORTB.B0 == 1){
         while(PORTB.B0 != 0){}
         Lcd_Out_CP("-");
      }
      else if(PORTB.B1 == 1){
         while(PORTB.B1 != 0){}
         Lcd_Out_CP("+");
      }
   }
}