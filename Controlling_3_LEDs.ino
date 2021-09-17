#include <TimerOne.h> // TimeOne라이브러리 사용

int led1_count = 0;
int led2_count = 0;
int led3_count = 0;


void setup(){
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  
  Timer1.initialize(10000); //1000000μs = 1s, 10000us = 0.01s, 1000us = 1ms
  Timer1.attachInterrupt(timerIsr);
}

void loop(){
    //0.25s마다 LED1함수 호출
    if(led1_count == 25){
      LED1(); //LED1 호출
      led1_count = 0; //led1_count를 초기화하여 반복 구문 형성
    }
    //0.5s마다 LED1함수 호출
    if(led2_count == 50){
      LED2(); //LED2 호출
      led2_count = 0; //led2_count를 초기화하여 반복 구문 형성
    }
    //1s마다 LED1함수 호출
    if(led3_count == 100){
      LED3(); //LED3 호출
      led3_count = 0; //led3_count를 초기화하여 반복 구문 형성
    }
}

//------------인터럽트를 위한 카운터 호출 함수----------------------
void timerIsr(){
  led1_count += 1; //0.01s 마다 1씩 증가
  led2_count += 1; //0.01s 마다 1씩 증가
  led3_count += 1; //0.01s 마다 1씩 증가
}

void LED1(){
  digitalWrite(13, digitalRead(13)^1);
}

void LED2(){
  digitalWrite(12, digitalRead(12)^1);
}

void LED3(){
  digitalWrite(11, digitalRead(11)^1);
}
