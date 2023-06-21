//Tuþ takýmýndan basýlan sayýyý 7 segment LED ile gösteren kod
#define B0 PORTB.B0
#define B1 PORTB.B1
#define B2 PORTB.B2
#define B3 PORTB.B3
#define A0 PORTA.RA0
#define A1 PORTA.RA1
#define A2 PORTA.RA2
#define A3 PORTA.RA3
void main() {
   int i = 0;
   int s[10] = {0b00000000, 0b00010000, 0b00100000, 0b00110000, 0b01000000, 0b01010000, 0b01100000, 0b01110000, 0b10000000, 0b10010000};
   TRISA = 0b00100000;
   TRISB = 0b00001111;
   PORTA = 0;
   PORTB = 0;
   while(1){
      PORTB = s[i];
      
      A0 = 1;
      A1 = 0;
      A2 = 0;
      A3 = 0;
      if(B0 == 1){i = 3;}
      else if(B1 == 1){i = 2;}
      else if(B2 == 1){i = 1;}

      A0 = 0;
      A1 = 1;
      A2 = 0;
      A3 = 0;
      if(B0 == 1){i = 6;}
      else if(B1 == 1){i = 5;}
      else if(B2 == 1){i = 4;}

      A0 = 0;
      A1 = 0;
      A2 = 1;
      A3 = 0;
      if(B0 == 1){i = 9;}
      else if(B1 == 1){i = 8;}
      else if(B2 == 1){i = 7;}
      
      A0 = 0;
      A1 = 0;
      A2 = 0;
      A3 = 1;
      if(B1 == 1){i = 0;}
   }
}

/*
//Tuþ takýmýndan basýlan sayýyý 7 segment LED ile gösteren kod (gereksiz karmaþýk ama önemli uygulamalar için hýzlandýrýcý etkisi vardýr)
#define B0 PORTB.B0
#define B1 PORTB.B1
#define B2 PORTB.B2
#define B3 PORTB.B3
#define A0 PORTA.RA0
#define A1 PORTA.RA1
#define A2 PORTA.RA2
#define A3 PORTA.RA3
void main() {
   int i = 0, k;
   int s[10] = {0b00000000, 0b00010000, 0b00100000, 0b00110000, 0b01000000, 0b01010000, 0b01100000, 0b01110000, 0b10000000, 0b10010000};
   TRISA = 0b00100000;
   TRISB = 0b00001111;
   PORTA = 0;
   PORTB = 0;
   while(1){
      k = 0;
      PORTB = s[i];
      while(k == 0){
         A0 = 1;
         A1 = 0;
         A2 = 0;
         A3 = 0;
         if(B0 == 1){
            while(B0 != 1){}
            i = 3;
            k = 1;
            break;
         }
         else if(B1 == 1){
            while(B1 != 1){}
            i = 2;
            k = 1;
            break;
         }
         else if(B2 == 1){
            while(B2 != 1){}
            i = 1;
            k = 1;
            break;
         }
         else{break;}
      }
      while(k == 0){
         A0 = 0;
         A1 = 1;
         A2 = 0;
         A3 = 0;
         if(B0 == 1){
            while(B0 != 1){}
            i = 6;
            k = 1;
            break;
         }
         else if(B1 == 1){
            while(B1 != 1){}
            i = 5;
            k = 1;
            break;
         }
         else if(B2 == 1){
            while(B2 != 1){}
            i = 4;
            k = 1;
            break;
         }
         else{break;}
      }
      while(k == 0){
         A0 = 0;
         A1 = 0;
         A2 = 1;
         A3 = 0;
         if(B0 == 1){
            while(B0 != 1){}
            i = 9;
            k = 1;
            break;
         }
         else if(B1 == 1){
            while(B1 != 1){}
            i = 8;
            k = 1;
            break;
         }
         else if(B2 == 1){
            while(B2 != 1){}
            i = 7;
            k = 1;
            break;
         }
         else{break;}
      }
      while(k == 0){
         A0 = 0;
         A1 = 0;
         A2 = 0;
         A3 = 1;
         if(B1 == 1){
            while(B1 != 1){}
            i = 0;
            k = 1;
            break;
         }
         else{break;}
      }
   }
}
*/