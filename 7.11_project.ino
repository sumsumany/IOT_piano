//OLED, 온습도, 초음파, 조도 , 부저, 스위치, LED, 가스, 빗물감지 
//피아노 //날씨알리미
//초음파 거리에 따라 -> 도레미 파솔라 시도레 
//녹음 -> 빈 배열에 저장. 조도센서 가릴 때 누르는 값을 
//
 
const int SDA_pin =12;
const int SCL_pin =13;
const int buzzer =6;
const int SW1 = 3;
const int SW2 = 4;
const int SW3 = 5;
const int trig_pin =15;
const int echo_pin =14;
#define SOUND_SPEED 340 
#define TRIG_PULSE_DURATION_US 10
long ultrason_duration;
float distance_cm;

//cds
#define PIN_CDS 26 

int note1[3]={262,294,330};
int note2[3]={349,392,440};
int note3[3]={494,523,587};

void setup() {
  // put your setup code here, to run once:
 
Serial.begin(9600);
pinMode(trig_pin, OUTPUT);
pinMode(echo_pin, INPUT);
pinMode(buzzer,OUTPUT);
pinMode(SW1,INPUT);
pinMode(SW2,INPUT);
pinMode(SW3,INPUT);
pinMode(PIN_CDS,INPUT);  
 
}

void loop() {
  int sw1= digitalRead(3);
  int sw2= digitalRead(4);
  int sw3= digitalRead(5);
  // put your main code here, to run repeatedly:
int CDS_sensor = analogRead(26);
digitalWrite(trig_pin,LOW);
delayMicroseconds(2);
digitalWrite(trig_pin,1);
delayMicroseconds(TRIG_PULSE_DURATION_US);
digitalWrite(trig_pin,0);
ultrason_duration=pulseIn(echo_pin,1);
distance_cm=ultrason_duration *SOUND_SPEED/2*0.0001; 
Serial.print("Distance (cm) : ");
Serial.println(distance_cm);
Serial.print("CDS  : ");
Serial.println(CDS_sensor );

if(distance_cm>50){
  if(sw1==0){
    if(CDS_sensor<300){
      tone(buzzer,note1[0]);
      delay(100);
 
    }
    else{tone(buzzer,277 );delay(100);}
   }

  if(sw2==0){
    if(CDS_sensor<300){
      tone(buzzer,note1[1]);
      delay(100);
   
    }
    else{tone(buzzer,311 );
     delay(100);
     }
  }
 if(sw3==0){ 
  tone(buzzer,note1[2]);
   delay(100);
   
      }
  }


 else if(distance_cm<=50 & distance_cm>20){
  
  if(sw1==0){
    if(CDS_sensor<300){
  tone(buzzer,note2[0]);
  delay(100);
    
    }
    else{tone(buzzer,370 );
     delay(100);
      }
  }

  if(sw2==0){
    if(CDS_sensor<300){
  tone(buzzer,note2[1]);
   delay(100);
   
    }
    else{tone(buzzer,415 );
     delay(100);
     }
  }
 if(sw3==0){ 
  if(CDS_sensor<300){
  tone(buzzer,note2[2]);
  delay(100);
    }
    else{tone(buzzer,466 );
     delay(100);
      } }
    }


 else{
  if(sw1==0){
    if(CDS_sensor<300){
   tone(buzzer,note3[0]);
   delay(100);
    
    }
     }
  

  if(sw2==0){
    if(CDS_sensor<300){
  tone(buzzer,note3[1]);
   delay(100);
   
    }
    else{tone(buzzer,523);
     delay(100);
     }
  }
 if(sw3==0){ 
  if(CDS_sensor<300){
  tone(buzzer,note3[2]);
   delay(100);
  
    }
    else{tone(buzzer,622 );
     delay(100);
      } }
    }  
    }

 