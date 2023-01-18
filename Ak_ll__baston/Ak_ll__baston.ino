int durum_led=3;
int durum_ses=3;
int veri;
int i;
//1
int tringpin1=2;
int echopin1=3;
long sure1;
long uzaklik1;
//2
int tringpin2=4;
int echopin2=5;
long sure2;
long uzaklik2;
//3
int tringpin3=11;
int echopin3=12;
long sure3;
long uzaklik3;
//4
int tringpin4=8;
int echopin4=9;
long sure4;
long uzaklik4;

#define led A0 //ışıklar Analog 0 da A0
#define buzzer A1 // buzzzer Analog 1 de A1
int button_ses=7; // sesi açıp kapatan button dijital 7 de 
int button_isik=13; // ışıkları açıp kapatan button dijital 13 de
void setup() {
  analogReference(INTERNAL);
  //1
  pinMode(tringpin1,OUTPUT);
  pinMode(echopin1,INPUT);
  //2
 
  pinMode(tringpin2,OUTPUT);
  pinMode(echopin2,INPUT);
  //3
  
  pinMode(tringpin3,OUTPUT);
  pinMode(echopin3,INPUT);
  //4
  
  pinMode(tringpin4,OUTPUT);
  pinMode(echopin4,INPUT);

  pinMode(led,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(button_ses,INPUT);
  pinMode(button_isik,INPUT);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()>0)
  {
    veri=Serial.read();
  }
  
  if(veri=='1')
  {
    digitalWrite(buzzer,1);
  }

  if(durum_led % 2==0)
  {
    durum_led=digitalRead(button_isik)+4;
    analogWrite(led,1024);
    delay(1000);
    analogWrite(led,0);
    delay(300);
  }
  else
  {
    durum_led=digitalRead(button_isik)+5;
    analogWrite(led,0);
    delay(300);
  }
  if(durum_ses %2==0)
  {
    durum_ses=digitalRead(button_ses)+4;
    noTone(buzzer);
  }
  else
  {
    durum_ses=digitalRead(button_ses)+5;
    noTone(buzzer);
  }

  digitalWrite(tringpin1,0);
  delayMicroseconds(5);
  digitalWrite(tringpin1,1);
  delayMicroseconds(10);
  digitalWrite(tringpin1,0);
  sure1=pulseIn(echopin1,1);
  uzaklik1=sure1/29.1/2;
  delay(50);
  digitalWrite(tringpin2,0);
  delayMicroseconds(5);
  digitalWrite(tringpin2,1);
  delayMicroseconds(10);
  digitalWrite(tringpin2,0);
  sure2=pulseIn(echopin2,1);
  uzaklik2=sure2/29.1/2;
  delay(50);
  digitalWrite(tringpin3,0);
  delayMicroseconds(5);
  digitalWrite(tringpin3,1);
  delayMicroseconds(10);
  digitalWrite(tringpin3,0);
  sure3=pulseIn(echopin3,1);
  uzaklik3=sure3/29.1/2;
  delay(50);
  digitalWrite(tringpin4,0);
  delayMicroseconds(5);
  digitalWrite(tringpin4,1);
  delayMicroseconds(10);
  digitalWrite(tringpin4,0);
  sure4=pulseIn(echopin4,1);
  uzaklik4=sure4/29.1/2;
  
 //1
 if(uzaklik1<60)
 {
  if(durum_ses %2==0)
  {
   tone(buzzer,100);
   delay(300);
   noTone(buzzer);
   delay(300);
  }
 }
  if(uzaklik1<40)
 {
  if(durum_ses %2==0)
  {
   tone(buzzer,100);
   delay(100);
   noTone(buzzer);
   delay(100);
  }
 }
  if(uzaklik1<20)
 {
  if(durum_ses %2==0)
  {
   tone(buzzer,100);
   delay(50);
   noTone(buzzer);
   delay(50);
  }
}

//2
 if(uzaklik2<60)
 {
  if(durum_ses %2==0)
  {
   tone(buzzer,500);
   delay(300);
   noTone(buzzer);
   delay(300);
  }
 }
  if(uzaklik2<40)
 {
  if(durum_ses %2==0)
  {
   tone(buzzer,500);
   delay(100);
   noTone(buzzer);
   delay(100);
  }
 }
  if(uzaklik2<20)
 {
  if(durum_ses %2==0)
  {
   tone(buzzer,500);
   delay(50);
   noTone(buzzer);
   delay(50);
  }
 }

 //3
 if(uzaklik3<60)
 {
  if(durum_ses %2==0)
  {
   tone(buzzer,100);
   delay(300);
   noTone(buzzer);
   delay(300);
  }
 }
  if(uzaklik3<40)
 {
  if(durum_ses %2==0)
  {
   tone(buzzer,100);
   delay(100);
   noTone(buzzer);
   delay(100);
  }
 }
  if(uzaklik3<20)
 {
  if(durum_ses %2==0)
  {
   tone(buzzer,100);
   delay(50);
   noTone(buzzer);
   delay(50);
  }
 }

 //4
 if(uzaklik4<60)
 {
  if(durum_ses %2==0)
  {
   tone(buzzer,800);
   delay(300);
   noTone(buzzer);
   delay(300);
  }
 }
  if(uzaklik4<40)
 {
  if(durum_ses %2==0)
  {
   tone(buzzer,800);
   delay(100);
   noTone(buzzer);
   delay(100);
  }
 }
  if(uzaklik4<20)
 {
  if(durum_ses %2==0)
  {
   tone(buzzer,800);
   delay(50);
   noTone(buzzer);
   delay(50);
  }
 }
}



 
