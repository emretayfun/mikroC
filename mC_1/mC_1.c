
//Mazeret sýnavý 1. soru
#define Y PORTA.RA4
#define A PORTB.RB0
main(){
   int s[10] = {0b00000000, 0b00000001, 0b00000010, 0b00000011, 0b00000100, 0b00000101, 0b00000110, 0b00000111, 0b00001000, 0b00001001}; //7 segment display
   int i = 0, a = 27, j, g; //i = 0 çünkü 0'dan baþlayýp arta arta gidecek, a = 27 çünkü 9'dan baþlayýð azala azla gidecek
   TRISA = 0b00110000; //A portunun giriþ ve çýkýþlarý belirlendi
   TRISB = 0b00000001; //B portunun giriþ ve çýkýþlarý belirlendi
   PORTA = 0; //Ýþimizi garantilemek için A portu sýfýrlandý
   PORTB = 0; //Ýþimizi garantilemek için B portu sýfýrlandý
   while(1){ //Program, enerji kesilene kadar program çalýþsýn diye while(1) döngüsünün içerisine yazýlacak
      while(Y == 0 && A == 1){ //iki butona da ayný anda basýlmasý engelleniyor
         if(Y == 0 && A == 1 && i < 18){ //Döngü içinde diðer butona basýlmasýný engellemek için burada da iki butona basýlmasý engelleniyor ve sayýcýnýn 9'dan yukarý çýkmamasý için i deðeri kýsýtlanýyor
            while(Y != 1){} //Butona basýlýnca oluþan dalgalanmanýn neticesinde sanki birden fazla kes basmýþ gibi algýlamasýnýn önlenmesi için bir sonsuz döngü oluþturuluyor
            i = i + 1; //RA4 Butonuna basma sayýmýzý hafýzaya alýyor
         }
         if(i % 2 == 0){ //Eðer i 2'ye tam bölünüyorsa o zaman i'ye hiç basýlmamýþ (0) veya iki kere basýlmýþ diyebiliriz
            g = i / 2; //Her 2i'de 1 sayý artacaðý için g deðiþkenine gösterilmesi gereken sayý deðeri atanýyor
            PORTA = s[g]; //7 segment display ile hangi sayýda olunduðu gösteriliyor
            a = 3 * i / 2; //artma ve azaltma iþlemlerinin uyumlu olmasý için o anki i sayýsýnýn deðerinin 3/2'si a deðiþkenine aktarýlýyor
         }
      }
      while(A == 0 && Y == 1){ //Bu sefer de azaltma iþlemi için her iki butona da basýlmadýðýný sadece RB0'a basýlýp basýlmadýðýný kontrol ediyor
         if(A == 0 && Y == 1 && i > 0){ //Döngü içerisinde her iki butona da basýlmadýðýný kotrol dediyor ve azaltma iþleminin 0'da son bulmasý için i deðiþkenimizi ve dolayýsýyla da a deðiþkenimizi sýnýrlýyor
            while(A != 1){} //Dalgalanmanýn yüzünden butona bir defa basýnca birden fazla kez basýlmýþ gibi algýlanmasýný önlesin diye konmuþtur
            a = a - 1; //RB0 butonuna basma sayýmýzý hafýzaya alýyor
         }
         if(a % 3 == 0){ //Eðer RB0 butonuna 3 defa basýldýysa
            g = a / 3; //g deðiþkenine a'nýn 1/3'ünü ata
            PORTA = s[g]; //7 segment display ile azaltma neticesinde ekrana gelen sayýyý yazdýr
            i = 2 * a / 3; //attýrma ve azaltma iþlemlerinin uyum saðlamasý için a'nýn 2/3'ünü i deðiþkenine ata
         }
      }
   }
}

/*
//Mazeret sýnavý 3. soru
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
         while(Y != 1){} //Butona bir defa basýlma iþlemini algýlanmasý için gerekli olan döngü
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


//Bir butona 1 kere basýnca L1 yansýn ... 7 kere basýnca L7 yansýn 7 kereden fazla basýnca hepsi yansýn
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


//Bir butona 5 defa basýnca LED'leri 1s yakýp sonra söndüren kod
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


//iki farklý butona 5s basýlý tutulduðunda 5 defa yanýp sönen LED'ler
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


//Yukarý ve Aþaðý sayyýcý kodu
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


//Tuþlu muþlu karaþimþek kodu
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
