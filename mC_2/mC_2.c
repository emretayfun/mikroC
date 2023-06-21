
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
#define B PORTA.RB4                 //Buton tanımlandı
main(){
   int i, j = 0, k = 0;             //for döngüsü için i, sayının kaöta olduğunu belirlemek için j, 6s basıldıktan sonra butona hala basılıp basılmadığını kontrol etmek için k değişkenleri tanımlandı.
   int s[10] = {0b00000000, 0b00000001, 0b00000010, 0b00000011, 0b00000100, 0b00000101, 0b00000110, 0b00000111, 0b00001000, 0b00001001};
   TRISA = 0b00110000;              //Button giriş, 74LS48 entegresine giden uçlar çıkış seçildi. Diğerlerinin giriş veya çıkış seçilmesinin bir önemi yoktur.
   PORTA = 0;                       //Önceki kodlardan kalma hareketleri engellemek için sıfırlama işlemi yapılıypr.
   while(1){                        //sonsuz döngüde enerji kesilene kadar programın devam etmesi sağlandı
      if(B == 0){                   //Butona basıldıysa
         if(k == 0){j = j + 1;}     //ve daha önce basılı tutlmamışsa j değişkenini bir arttır
         for(i = 0; i < 6000; i++){ //6s kontrol et
            delay_ms(1);
            if(B != 0){             //Butona basma işlemi yarıda kalırsa
               break;               //for döngüsünden çık
            }
         }
         if(i == 6000){             //for döngüsü sonuna kadar tamamlandıysa 6s basılmış demektir
            PORTA = s[0];           //o zaman 7 segment LED 0 yazsın
            j = 0;                  //sayaç görevi gören j değişkenimizi de sıfırla
            k = 1;                  //6s'lik basılma işleminden sonra butona basma işlemi devam ediyor olabilir. o yüzden buton bırakılana kadar j'yi bir arttırma ve for döngüsüne girme
         }
         else if(i < 6000){         //for döngüsü tamamlanmadan çıktıysa
            if(j == 10){j = 0;}     //ve eğer j = 10 ise j'yi sıfırla
            PORTA = s[j];           //o an yazılması gereken sayıyı 7 segment diplayda göster
            k = 0;                  //butona basılma işlemi son bulduğuna göre j'nin arışına izin ver
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
