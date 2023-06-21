
//Mazeret sınavı 1. soru
#define Y PORTA.RA4
#define A PORTB.RB0
main(){
   int s[10] = {0b00000000, 0b00000001, 0b00000010, 0b00000011, 0b00000100, 0b00000101, 0b00000110, 0b00000111, 0b00001000, 0b00001001};
   int i = 0, a = 27, j, g;                //i = 0 çünkü 0'dan başlayıp arta arta gidecek, a = 27 çünkü 9'dan başlayığ azala azla gidecek
   TRISA = 0b00110000;                     //A portunun giriş ve çıkışları belirlendi
   TRISB = 0b00000001;                     //B portunun giriş ve çıkışları belirlendi
   PORTA = 0;                              //İşimizi garantilemek için A portu sıfırlandı
   PORTB = 0;                              //İşimizi garantilemek için B portu sıfırlandı
   while(1){                               //Program, enerji kesilene kadar program çalışsın diye while(1) döngüsünün içerisine yazılacak
      while(Y == 0 && A == 1){             //iki butona da aynı anda basılması engelleniyor
         if(Y == 0 && A == 1 && i < 18){   //Döngü içinde diğer butona basılmasını engellemek için burada da iki butona basılması engelleniyor ve sayıcının 9'dan yukarı çıkmaması için i değeri kısıtlanıyor
            while(Y != 1){}                //Butona basılınca oluşan dalgalanmanın neticesinde sanki birden fazla kes basmış gibi algılamasının önlenmesi için bir sonsuz döngü oluşturuluyor
            i = i + 1;                     //RA4 Butonuna basma sayımızı hafızaya alıyor
         }
         if(i % 2 == 0){                   //Eğer i 2'ye tam bölünüyorsa o zaman i'ye hiç basılmamış (0) veya iki kere basılmış diyebiliriz
            g = i / 2;                     //Her 2i'de 1 sayı artacağı için g değişkenine gösterilmesi gereken sayı değeri atanıyor
            PORTA = s[g];                  //7 segment display ile hangi sayıda olunduğu gösteriliyor
            a = 3 * i / 2;                 //artma ve azaltma işlemlerinin uyumlu olması için o anki i sayısının değerinin 3/2'si a değişkenine aktarılıyor
         }
      }
      while(A == 0 && Y == 1){             //Bu sefer de azaltma işlemi için her iki butona da basılmadığını sadece RB0'a basılıp basılmadığını kontrol ediyor
         if(A == 0 && Y == 1 && i > 0){    //Döngü içerisinde her iki butona da basılmadığını kotrol dediyor ve azaltma işleminin 0'da son bulması için i değişkenimizi ve dolayısıyla da a değişkenimizi sınırlıyor
            while(A != 1){}                //Dalgalanmanın yüzünden butona bir defa basınca birden fazla kez basılmış gibi algılanmasını önlesin diye konmuştur
            a = a - 1;                     //RB0 butonuna basma sayımızı hafızaya alıyor
         }
         if(a % 3 == 0){                   //Eğer RB0 butonuna 3 defa basıldıysa
            g = a / 3;                     //g değişkenine a'nın 1/3'ünü ata
            PORTA = s[g];                  //7 segment display ile azaltma neticesinde ekrana gelen sayıyı yazdır
            i = 2 * a / 3;                 //attırma ve azaltma işlemlerinin uyum sağlaması için a'nın 2/3'ünü i değişkenine ata
         }
      }
   }
}

/*
//Mazeret sınavı 3. soru
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
         while(Y != 1){} //Butona bir defa basılma işlemini algılanması için gerekli olan döngü
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


//Bir butona 1 kere basınca L1 yansın ... 7 kere basınca L7 yansın 7 kereden fazla basınca hepsi yansın
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


//Bir butona 5 defa basınca LED'leri 1s yakıp sonra söndüren kod
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


//iki farklı butona 5s basılı tutulduğunda 5 defa yanıp sönen LED'ler
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


//Yukarı ve Aşağı sayyıcı kodu
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


//Tuşlu muşlu karaşimşek kodu
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
