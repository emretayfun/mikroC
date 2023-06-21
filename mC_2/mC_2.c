
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
#define B PORTA.RB4 //Buton tanýmlandý
main(){
   int i, j = 0, k = 0; //for döngüsü için i, sayýnýn kaöta olduðunu belirlemek için j, 6s basýldýktan sonra butona hala basýlýp basýlmadýðýný kontrol etmek için k deðiþkenleri tanýmlandý.
   int s[10] = {0b00000000, 0b00000001, 0b00000010, 0b00000011, 0b00000100, 0b00000101, 0b00000110, 0b00000111, 0b00001000, 0b00001001};
   TRISA = 0b00110000; //Button giriþ, 74LS48 entegresine giden uçlar çýkýþ seçildi. Diðerlerinin giriþ veya çýkýþ seçilmesinin bir önemi yoktur.
   PORTA = 0; //Önceki kodlardan kalma hareketleri engellemek için sýfýrlama iþlemi yapýlýypr.
   while(1){ //sonsuz döngüde enerji kesilene kadar programýn devam etmesi saðlandý
      if(B == 0){ //Butona basýldýysa
         if(k == 0){j = j + 1;} //ve daha önce basýlý tutlmamýþsa j deðiþkenini bir arttýr
         for(i = 0; i < 6000; i++){ //6s kontrol et
            delay_ms(1);
            if(B != 0){ //Butona basma iþlemi yarýda kalýrsa
               break; //for döngüsünden çýk
            }
         }
         if(i == 6000){ //for döngüsü sonuna kadar tamamlandýysa 6s basýlmýþ demektir
            PORTA = s[0]; //o zaman 7 segment LED 0 yazsýn
            j = 0; //sayaç görevi gören j deðiþkenimizi de sýfýrla
            k = 1; //6s'lik basýlma iþleminden sonra butona basma iþlemi devam ediyor olabilir. o yüzden buton býrakýlana kadar j'yi bir arttýrma ve for döngüsüne girme
         }
         else if(i < 6000){ //for döngüsü tamamlanmadan çýktýysa
            if(j == 10){j = 0;} //ve eðer j = 10 ise j'yi sýfýrla
            PORTA = s[j]; //o an yazýlmasý gereken sayýyý 7 segment diplayda göster
            k = 0; //butona basýlma iþlemi son bulduðuna göre j'nin arýþýna izin ver
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