
//Vize 3
#define B PORTA.B4
#define M PORTB.B0
main(){
   int i, k = 0;
   int s[10] = {0b00000000, 0b00000001, 0b00000010, 0b00000011, 0b00000100, 0b00000101, 0b00000110, 0b00000111, 0b00001000, 0b00001001};
   TRISA = 0b00110000;
   TRISB = 0x00;
   PORTA = 0;
   PORTB = 0;
   while(1){
      if(B == 0){
         while(B != 1){}
         if(k < 3){k = k + 1;}
         else{k = 1;}
      }
      switch(k){
         case 1:{
            M = 1;
            delay_ms(90);
            M = 0;
            delay_ms(10);
            PORTA = s[k];
            break;
         }
         case 2:{
            M = 1;
            delay_ms(50);
            M = 0;
            delay_ms(50);
            PORTA = s[k];
            break;
         }
         case 3:{
            M = 1;
            delay_ms(10);
            M = 0;
            delay_ms(90);
            PORTA = s[k];
            break;
         }
      }
   }
}

/*
//Vize 2
#define B PORTA.RB4 //Buton tan�mland�
main(){
   int i, j = 0, k = 0; //for d�ng�s� i�in i, say�n�n ka�ta oldu�unu belirlemek i�in j, 6s bas�ld�ktan sonra butona hala bas�l�p bas�lmad���n� kontrol etmek i�in k de�i�kenleri tan�mland�.
   int s[10] = {0b00000000, 0b00000001, 0b00000010, 0b00000011, 0b00000100, 0b00000101, 0b00000110, 0b00000111, 0b00001000, 0b00001001};
   TRISA = 0b00110000; //Button giri�, 74LS48 entegresine giden u�lar ��k�� se�ildi. Di�erlerinin giri� veya ��k�� se�ilmesinin bir �nemi yoktur.
   PORTA = 0; //�nceki kodlardan kalma hareketleri engellemek i�in s�f�rlama i�lemi yap�l�ypr.
   while(1){ //sonsuz d�ng�de enerji kesilene kadar program�n devam etmesi sa�land�
      if(B == 0){ //Butona bas�ld�ysa
         if(k == 0){j = j + 1;} //ve daha �nce bas�l� tutlmam��sa j de�i�kenini bir artt�r
         for(i = 0; i < 6000; i++){ //6s kontrol et
            delay_ms(1);
            if(B != 0){ //Butona basma i�lemi yar�da kal�rsa
               break; //for d�ng�s�nden ��k
            }
         }
         if(i == 6000){ //for d�ng�s� sonuna kadar tamamland�ysa 6s bas�lm�� demektir
            PORTA = s[0]; //o zaman 7 segment LED 0 yazs�n
            j = 0; //saya� g�revi g�ren j de�i�kenimizi de s�f�rla
            k = 1; //6s'lik bas�lma i�leminden sonra butona basma i�lemi devam ediyor olabilir. o y�zden buton b�rak�lana kadar j'yi bir artt�rma ve for d�ng�s�ne girme
         }
         else if(i < 6000){ //for d�ng�s� tamamlanmadan ��kt�ysa
            if(j == 10){j = 0;} //ve e�er j = 10 ise j'yi s�f�rla
            PORTA = s[j]; //o an yaz�lmas� gereken say�y� 7 segment diplayda g�ster
            k = 0; //butona bas�lma i�lemi son buldu�una g�re j'nin ar���na izin ver
         }
      }
   }
}


//Vize 1
#define L1 PORTB.RB1
#define L2 PORTB.RB2
#define L3 PORTB.RB3
#define L4 PORTB.RB4
#define L5 PORTB.RB5
#define L6 PORTB.RB6
#define L7 PORTB.RB7
void main() {
   int i = 1;
   TRISA = 0b00110000;
   TRISB = 0;
   PORTA = 0;
   PORTB = 0;
   while(1){
      switch(i){
         case 1: L1 = 1; delay_ms(200); L1 = 0; i = 2; break;
         case 2: L2 = 1; delay_ms(200); L2 = 0; i = 3; break;
         case 3: L3 = 1; delay_ms(200); L3 = 0; i = 4; break;
         case 4: L4 = 1; delay_ms(200); L4 = 0; i = 5; break;
         case 5: L5 = 1; delay_ms(200); L5 = 0; i = 6; break;
         case 6: L6 = 1; delay_ms(200); L6 = 0; i = 7; break;
         case 7: L7 = 1; delay_ms(200); L7 = 0; i = 1; break;
      }
   }
}
*/