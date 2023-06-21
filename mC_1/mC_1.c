
//Mazeret s�nav� 1. soru
#define Y PORTA.RA4
#define A PORTB.RB0
main(){
   int s[10] = {0b00000000, 0b00000001, 0b00000010, 0b00000011, 0b00000100, 0b00000101, 0b00000110, 0b00000111, 0b00001000, 0b00001001}; //7 segment display
   int i = 0, a = 27, j, g; //i = 0 ��nk� 0'dan ba�lay�p arta arta gidecek, a = 27 ��nk� 9'dan ba�lay�� azala azla gidecek
   TRISA = 0b00110000; //A portunun giri� ve ��k��lar� belirlendi
   TRISB = 0b00000001; //B portunun giri� ve ��k��lar� belirlendi
   PORTA = 0; //��imizi garantilemek i�in A portu s�f�rland�
   PORTB = 0; //��imizi garantilemek i�in B portu s�f�rland�
   while(1){ //Program, enerji kesilene kadar program �al��s�n diye while(1) d�ng�s�n�n i�erisine yaz�lacak
      while(Y == 0 && A == 1){ //iki butona da ayn� anda bas�lmas� engelleniyor
         if(Y == 0 && A == 1 && i < 18){ //D�ng� i�inde di�er butona bas�lmas�n� engellemek i�in burada da iki butona bas�lmas� engelleniyor ve say�c�n�n 9'dan yukar� ��kmamas� i�in i de�eri k�s�tlan�yor
            while(Y != 1){} //Butona bas�l�nca olu�an dalgalanman�n neticesinde sanki birden fazla kes basm�� gibi alg�lamas�n�n �nlenmesi i�in bir sonsuz d�ng� olu�turuluyor
            i = i + 1; //RA4 Butonuna basma say�m�z� haf�zaya al�yor
         }
         if(i % 2 == 0){ //E�er i 2'ye tam b�l�n�yorsa o zaman i'ye hi� bas�lmam�� (0) veya iki kere bas�lm�� diyebiliriz
            g = i / 2; //Her 2i'de 1 say� artaca�� i�in g de�i�kenine g�sterilmesi gereken say� de�eri atan�yor
            PORTA = s[g]; //7 segment display ile hangi say�da olundu�u g�steriliyor
            a = 3 * i / 2; //artma ve azaltma i�lemlerinin uyumlu olmas� i�in o anki i say�s�n�n de�erinin 3/2'si a de�i�kenine aktar�l�yor
         }
      }
      while(A == 0 && Y == 1){ //Bu sefer de azaltma i�lemi i�in her iki butona da bas�lmad���n� sadece RB0'a bas�l�p bas�lmad���n� kontrol ediyor
         if(A == 0 && Y == 1 && i > 0){ //D�ng� i�erisinde her iki butona da bas�lmad���n� kotrol dediyor ve azaltma i�leminin 0'da son bulmas� i�in i de�i�kenimizi ve dolay�s�yla da a de�i�kenimizi s�n�rl�yor
            while(A != 1){} //Dalgalanman�n y�z�nden butona bir defa bas�nca birden fazla kez bas�lm�� gibi alg�lanmas�n� �nlesin diye konmu�tur
            a = a - 1; //RB0 butonuna basma say�m�z� haf�zaya al�yor
         }
         if(a % 3 == 0){ //E�er RB0 butonuna 3 defa bas�ld�ysa
            g = a / 3; //g de�i�kenine a'n�n 1/3'�n� ata
            PORTA = s[g]; //7 segment display ile azaltma neticesinde ekrana gelen say�y� yazd�r
            i = 2 * a / 3; //att�rma ve azaltma i�lemlerinin uyum sa�lamas� i�in a'n�n 2/3'�n� i de�i�kenine ata
         }
      }
   }
}

/*
//Mazeret s�nav� 3. soru
#define Y PORTB.RB0
#define A PORTA.RA4
main(){
   int s[3] = {0b00000001, 0b00000010, 0b00000011};
   int k = 0; //kademe bilgisi
   TRISA = 0b00110000;
   TRISB = 0b00000001;
   PORTA = 0;
   PORTB = 0;
   while(1){
      if(Y == 0 && A == 1 && k < 2){
         while(Y != 1){} //Butona bir defa bas�lma i�lemini alg�lanmas� i�in gerekli olan d�ng�
         k = k + 1;
      }
      else if(A == 0 && Y == 1 && k > 0){
         while(A != 1){}
         k = k - 1;
      }
      PORTA = s[0 + k];
      if(k == 0){
         PORTB = 0b11111110;
         delay_ms(50);
         PORTB = 0;
         delay_ms(50);
      }
      else if(k == 1){
         PORTB = 0b11111110;
         delay_ms(100);
         PORTB = 0;
         delay_ms(100);
      }
      else{
         PORTB = 0b11111110;
         delay_ms(250);
         PORTB = 0;
         delay_ms(250);
      }
   }
}


//Bir butona 1 kere bas�nca L1 yans�n ... 7 kere bas�nca L7 yans�n 7 kereden fazla bas�nca hepsi yans�n
#define RA4 PORTA.RA4
#define L1 PORTB.RB7
#define L2 PORTB.RB6
#define L3 PORTB.RB5
#define L4 PORTB.RB4
#define L5 PORTB.RB3
#define L6 PORTB.RB2
#define L7 PORTB.RB1
main(){
   int i, j, k;
   TRISA = 0b00110000;
   TRISB = 0b00000001;
   PORTA = 0;
   PORTB = 0;
   while(1){
      i = 0;
      j = 0;
      while(j == 0){
         if(RA4 == 0){
            while(RA4 != 1){}
            i = i + 1;
            for(k = 0; k < 250; k++){
               delay_ms(1);
               if(RA4 == 0){break;}
            }
            if(k == 250){j = 1;}
         }
      }
      switch(i){
         case 1: L1 = 1; delay_ms(500); L1 = 0; break;
         case 2: L2 = 1; delay_ms(500); L2 = 0; break;
         case 3: L3 = 1; delay_ms(500); L3 = 0; break;
         case 4: L4 = 1; delay_ms(500); L4 = 0; break;
         case 5: L5 = 1; delay_ms(500); L5 = 0; break;
         case 6: L6 = 1; delay_ms(500); L6 = 0; break;
         case 7: L7 = 1; delay_ms(500); L7 = 0; break;
         default: PORTB = 0b11111110; delay_ms(500); PORTB = 0;
      }
   }
}


//Bir butona 5 defa bas�nca LED'leri 1s yak�p sonra s�nd�ren kod
#define RA4 PORTA.RA4
main(){
   int i = 0;
   TRISA = 0b00110000;
   TRISB = 0b00000001;
   PORTB = 0;
   while(1){
      if(RA4 == 0){
         while(RA4 != 1){}
         i = i + 1;
      }
      if(i == 5){
         PORTB = 0b11111110;
         delay_ms(1000);
         PORTB = 0b00000000;
         i = 0;
      }
   }
}


//iki farkl� butona 5s bas�l� tutuldu�unda 5 defa yan�p s�nen LED'ler
#define RB0 PORTB.RB0
#define RA4 PORTA.RA4
main(){
   int i;
   TRISA = 0b00110000;
   TRISB = 0b00000001;
   PORTA = 0;
   PORTB = 0;
   while(1){
      i = 0;
      while(i < 100 && RA4 == 0 && RB0 == 0){
         i = i + 1;
         delay_ms(50);
         if(i == 100 && RA4 == 0 && RB0 == 0){
            for(i = 0; i < 5; i++){
               PORTB = 0b11111110;
               delay_ms(50);
               PORTB = 0b00000000;
               delay_ms(50);
            }
         }
      }
   }
}


//Yukar� ve A�a�� sayy�c� kodu
#define Y9 PORTB.RB0
#define A0 PORTA.RA4
#define A PORTA.RA0
#define B PORTA.RA1
#define C PORTA.RA2
#define D PORTA.RA3
main(){
   int i, j, k ,l, s, d;
   TRISA = 0b00110000;
   TRISB = 0b00000001;
   PORTA = 0;
   PORTB = 0;
   while(1){
      while(Y9 == 0 && A0 == 1){
         s = -1;
         for(i = 0; i < 2; i++){
            if(s == 9){break;}
            if(i < 1){
               D = 0;
            }
            else{
               D = 1;
            }
            for(j = 0; j < 2; j++){
               if(s == 9){break;}
               if(j < 1){
                  C = 0;
               }
               else{
                  C = 1;
               }
               for(k = 0; k < 2; k++){
                  if(s == 9){break;}
                  if(k < 1){
                     B = 0;
                  }
                  else{
                     B = 1;
                  }
                  for(l = 0; l < 2; l++){
                     if(s == 9){break;}
                     if(l < 1){
                        A = 0;
                     }
                     else{
                        A = 1;
                     }
                     s = s + 1;
                     delay_ms(500);
                  }
               }
            }
         }
      }
      while(A0 == 0 && Y9 == 1){
         s = 10;
         for(i = 0; i < 2; i++){
            d = 0;
            if(s == -1){break;}
            if(i < 1){
               D = 1;
            }
            else{
               D = 0;
            }
            for(j = 0; j < 2; j++){
               if(s == -1 || d == 2){break;}
               if(j < 1 && D == 0){
                  C = 1;
               }
               else{
                  C = 0;
               }
               for(k = 0; k < 2; k++){
                  if(s == -1 || d == 2){break;}
                  if(k < 1 && D == 0){
                     B = 1;
                  }
                  else{
                     B = 0;
                  }
                  for(l = 0; l < 2; l++){
                     if(s == -1){break;}
                     if(l < 1){
                        A = 1;
                     }
                     else{
                        A = 0;
                     }
                     s = s - 1;
                     if(s > 7){
                        d = d + 1;
                     }
                     delay_ms(500);
                  }
               }
            }
         }
      }
   }
}


//Tu�lu mu�lu kara�im�ek kodu
#define L1 PORTB.RB7
#define L2 PORTB.RB6
#define L3 PORTB.RB5
#define L4 PORTB.RB4
#define L5 PORTB.RB3
#define L6 PORTB.RB2
#define L7 PORTB.RB1
#define RB0 PORTB.RB0
#define RA4 PORTA.RA4
void main() {
   TRISA = 0b00110000;
   TRISB = 0b00000001;
   PORTA = 0;
   PORTB = 0;
   while(1){
      while(RA4 == 1){
         while(RB0 == 1 && RA4 == 1){
            L1 = 1;
            delay_ms(50);
            L1 = 0;
            L2 = 1;
            delay_ms(50);
            L2 = 0;
            L3 = 1;
            delay_ms(50);
            L3 = 0;
            L4 = 1;
            delay_ms(50);
            L4 = 0;
            L5 = 1;
            delay_ms(50);
            L5 = 0;
            L6 = 1;
            delay_ms(50);
            L6 = 0;
            L7 = 1;
            delay_ms(50);
            L7 = 0;
         }
         while(RB0 == 0 && RA4 == 1){
            L7 = 1;
            delay_ms(50);
            L7 = 0;
            L6 = 1;
            delay_ms(50);
            L6 = 0;
            L5 = 1;
            delay_ms(50);
            L5 = 0;
            L4 = 1;
            delay_ms(50);
            L4 = 0;
            L3 = 1;
            delay_ms(50);
            L3 = 0;
            L2 = 1;
            delay_ms(50);
            L2 = 0;
            L1 = 1;
            delay_ms(50);
            L1 = 0;
         }
      }
   }
}

*/
