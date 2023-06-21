//Keypad kütüphanesi kullanımı
   char keypadPort at PORTB;
   Keypad_Init();
   int i, kp;
void main() {
   TRISA = 0b00100000;
   TRISB = 0b00001111;
   PORTA = 0;
   PORTB = 0;
   while(1){
      //i = 0;
      kp = 0;
      //while(!kp){
      //   kp = Keypad_Key_Click();
      //   delay_ms(50);
      //}
      //while(i == 0){
      //   kp = Keypad_Key_Click();
      //   delay_ms(50);
      //   if(kp != 0){i = 1;}
      //}
      while(kp == 0){
         kp = Keypad_Key_Click();
         delay_ms(50);
      }
      switch(kp){
         case  1: PORTA = 0; break; // On/C
         case  2: PORTA = 0; break; // 0
         case  3: PORTA = 0; break; // =
         case  4: PORTA = 0; break; // +
         case  5: PORTA = 1; break; // 1
         case  6: PORTA = 2; break; // 2
         case  7: PORTA = 3; break; // 3
         case  8: PORTA = 0; break; // -
         case  9: PORTA = 4; break; // 4
         case 10: PORTA = 5; break; // 5
         case 11: PORTA = 6; break; // 6
         case 12: PORTA = 0; break; // *
         case 13: PORTA = 7; break; // 7
         case 14: PORTA = 8; break; // 8
         case 15: PORTA = 9; break; // 9
         case 16: PORTA = 0; break; // /
      }
   }
}
/*
*/
