const float pi=3.14159;
int pin[]={22,23,24,25,26,27,28,29};
const float f=100.0;
unsigned long suankizaman=0 ;
unsigned long eskizaman=0 ;



void setup() {
  for(int i=22 ;i<=29;i++){
    pinMode(i,OUTPUT);
  }

}

void loop() {
 suankizaman=millis();
if(suankizaman-eskizaman>=1){
  eskizaman=suankizaman;
float t=suankizaman/1000.0;
if(suankizaman%1000<500){
  float sinyal=127.5+127.5*sin(2*pi* f * t);
  byte dac_cikis =byte(sinyal);
  for (int i = 0; i < 8; i++) {
  
      digitalWrite(22 + i, bitRead(dac_cikis, i));
     
}
}
 else {
  byte deger = 127; // Çıkışa göndermek istediğin 8-bitlik sayı

for (int i = 0; i < 8; i++) {

  digitalWrite(22 + i,bitRead(deger, i)); 
}

}
}
}



