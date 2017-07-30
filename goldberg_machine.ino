#include <Servo.h>

 #define TriggerPin 2        //Trig Pin
 #define EchoPin 3          //Echo Pin
 #define SERVOPIN 9   //servo pin
 #define CDS A0
 #define LED 13

 #define CLOSE 180  
 #define OPEN 90

 #define CDS_THRESHOLD 450    //조도값 범위
 #define ULTRA_THRESHOLD 4  //거리 범위
 
int cnt = 0;
int angle=0;
boolean chk = true;
boolean servo_chk = true;
Servo servo;

void setup() {
 Serial.begin(9600);
  pinMode(TriggerPin,OUTPUT); // 센서 Trig 핀
  pinMode(EchoPin,INPUT); // 센서 Echo 핀 
  pinMode(LED,OUTPUT); //LED

  digitalWrite(LED, LOW);  //led on
  
  servo.attach(9, 500, 2500); 
  servo.write(CLOSE);
  Serial.println("RUN!!");
}

void loop() {
 if(ultra() && cnt > 5){   //5cm미만으로 가까워지면
   digitalWrite(LED, HIGH);  //led on
 }
 if(cdsSensor() && cnt > 5){   //조도 300
    //모터 돌리기
    if(servo_chk){
      servo.write(OPEN);
      delay(200);
      servo_chk=false;
    }
 }
 cnt++;
 if(cnt == 1000){
    cnt = 11;
 }
 delay(300);
}

boolean cdsSensor(){
   int cdsValue = analogRead(CDS);

  // 측정된 밝기 값를 시리얼 모니터에 출력합니다.
  Serial.print("cds =  ");
  Serial.println(cdsValue);
  if (cdsValue > CDS_THRESHOLD) {
    return true;
  }else{
    return false;
  }
  // 0.2초 동안 대기합니다.
  delay(200);
}

boolean ultra(){
  long duration, cm;

  digitalWrite(TriggerPin,HIGH); // 센서에 Trig 신호 입력
  delayMicroseconds(10); // 10us 정도 유지
  digitalWrite(TriggerPin,LOW); // Trig 신호 off

  duration = pulseIn(EchoPin,HIGH); // Echo pin: HIGH->Low 간격을 측정
  cm = microsecondsToCentimeters(duration); // 거리(cm)로 변환
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  if(cm >= ULTRA_THRESHOLD){
    return true;
  }else{
    return false;
  }
  delay(300); // 0.3초 대기 후 다시 측정
}

long microsecondsToInches(long microseconds)
{
  return microseconds / 74 / 2;
}

 

long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}
