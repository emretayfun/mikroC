
//RA0'a absılınca 75 derece sağa, RA1'e basılınca 30 derece sola, RA2'ye basılınca 420 derece sağa dönsün (ufak algo sorunları)
#define B0 PORTA.RA0
#define B1 PORTA.RA1
#define B2 PORTA.RA2
main(){
   int a = 0, i, ka = 0, ki = 0;
   int t[4] = {0b01100000, 0b11000000, 0b10010000, 0b00110000};   //tam adým
   const int d = 50;
   TRISA = 0b00100111;
   TRISB = 0;
   PORTA = 0;
   PORTB = 0;
   while(1){
      switch(a){
         case 4: a = 0; break;
         case -1: a = 3; break;
      }
      if(B0 == 0){
         while(B0 != 1){}
         if(ka == 1){a = a + 1;}
         for(i = 0; i < 5; i++){
            PORTB = t[a];
            delay_ms(d);
            a = a + 1;
            if(a == 4){a = 0;}
         }
         ki = 1;
         ka = 0;
      }
      else if(B1 == 0){
         while(B1 != 1){}
         if(ki == 1){a = a - 1;}
         //else if(a == 0){a = 3;}
         for(i = 0; i < 2; i++){
            PORTB = t[a];
            delay_ms(d);
            a = a - 1;
            if(a == -1){a = 3;}
         }
         ka = 1;
         ki = 0;
      }
      else if(B2 == 0){
         while(B2 != 1){}
         if(ka == 1){a = a + 1;}
         for(i = 0; i < 28; i++){
            PORTB = t[a];
            delay_ms(d);
            a = a + 1;
            if(a == 4){a = 0;}
         }
         ki = 1;
         ka = 0;
      }
   }
}

/*
//Step motoru sağa ve sola döndürmek
#define B0 PORTA.B0
#define B1 PORTA.B1
main(){
   int i = 0;
   int y[8] = {0b00100000, 0b01100000, 0b01000000, 0b11000000, 0b10000000, 0b10010000, 0b00010000, 0b00110000};   //yarým adým
   int t[4] = {0b01100000, 0b11000000, 0b10010000, 0b00110000};   //tam adým
   const int d = 500;
   TRISA = 0b00100111;
   TRISB = 0;
   PORTA = 0;
   PORTB = 0;
   while(1){
      //switch(i){   //yarým adým için
         //case 8: i = 0; break;
         //case -1: i = 7; break;
      //}
      switch(i){   //tam adým için
         case 4: i = 0; break;
         case -1: i = 3; break;
      }
      if(B0 == 0){
         PORTB = t[i];
         i = i + 1;
         delay_ms(d);
      }
      else if(B1 == 0){
         PORTB = t[i];
         i = i - 1;
         delay_ms(d);
      }
   }
}


//Step (adım) motor sürmek
#define A PORTB.B4
#define B PORTB.B5
#define C PORTB.B6
#define D PORTB.B7
main(){
   int i;
   TRISA = 0b00100111;
   TRISB = 0;
   PORTA = 0;
   PORTB = 0;
   while(1){
      //2 Fazlý yarým adým
      //B = 1;            //B
      //delay_ms(500);
      //C = 1;            //BC
      //delay_ms(500);
      //B = 0;            //C
      //delay_ms(500);
      //D = 1;            //CD
      //delay_ms(500);
      //C = 0;            //D
      //delay_ms(500);
      //A = 1;            //DA
      //delay_ms(500);
      //D = 0;            //A
      //delay_ms(500);
      //B = 1;            //AB
      //delay_ms(500);
      //A = 0;            //B
      //2 Fazlý tam adým
      B = 1;            //BC
      C = 1;
      delay_ms(500);
      B = 0;            //CD
      D = 1;
      delay_ms(500);
      C = 0;            //DA
      A = 1;
      delay_ms(500);
      D = 0;            //AB
      B = 1;
      delay_ms(500);
      A = 0;            //BC
   }
}


//L293D ile DC motor yönlendirme
#define S PORTA.B0
#define L PORTA.B1
#define R PORTA.B2
#define EN1 PORTB.B3
#define IN1 PORTB.B1
#define IN2 PORTB.B2
void main() {
   int i;
   TRISA = 0b00100111;
   TRISB = 0;
   PORTA = 0;
   PORTB = 0b00001000;
   while(1){
      if(L == 0 && R== 1 && S == 1){
         IN1 = 1;
         IN2 = 0;
      }
      else if(R == 0 && L == 1 && S == 1){
         IN1 = 0;
         IN2 = 1;
      }
      else if(S == 0 || R == 0 && L == 0){
         IN1 = 0;
         IN2 = 0;
      }
   }
   
}
*/
