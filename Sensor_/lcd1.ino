#include <LiquidCrystal.h>

//LCD 16*2 com um sensor ultra-sônico

//declaração dos pinos do display
#define RS 7
#define E 6
#define D4 5
#define D5 4
#define D6 3
#define D7 2

//declaração das variáveis do sensor e os leds

int pinTrigger = 10;
int pinEcho = 9;
float pulse;
float dist_cm;
int pinVermelho = 11;
int pinAmarelo = 12;
int pinVerde = 13;



LiquidCrystal lcd(RS, E, D4, D5, D6, D7);


void setup()
{
  lcd.begin(16,2);

  pinMode(pinVermelho, OUTPUT);
  pinMode(pinAmarelo, OUTPUT);
  pinMode(pinVerde, OUTPUT);
  
  pinMode(pinTrigger, OUTPUT);
  pinMode(pinEcho, INPUT);
  
  digitalWrite(pinTrigger, LOW);
  Serial.begin(9600);
}

void loop()
{
  trigPulse(); //linha 79
  pulse = pulseIn(pinEcho, HIGH);
  dist_cm = pulse/58.82;
  
 
  if(dist_cm <30.00){
    
  	digitalWrite(pinVermelho, HIGH);
    digitalWrite(pinAmarelo, LOW);
    digitalWrite(pinVerde, LOW);
  }
  
  
  if(dist_cm >=30.00 && dist_cm <50.00){
  	digitalWrite(pinVermelho, LOW);
    digitalWrite(pinAmarelo, HIGH);
    digitalWrite(pinVerde, LOW);
}
  
  if(dist_cm >=50.00){
  	digitalWrite(pinVermelho, LOW);
    digitalWrite(pinAmarelo, LOW);
    digitalWrite(pinVerde, HIGH);
}
  limpar_tela();
  imprime_mensagem(3,0,"Distancia");
  imprime_dist(5,1, dist_cm);
  imprime_cm(8,1,"cm");
  
  Serial.print("Valor do sensor de distância: "); 
  Serial.println(dist_cm);
  
}



void trigPulse(){

digitalWrite(pinTrigger, HIGH);
delayMicroseconds(10);
digitalWrite(pinTrigger, LOW);
}

void limpar_tela(){
	lcd.clear();
}

void imprime_mensagem(int col, int lin, char* msg){
lcd.setCursor(col, lin);
lcd.print(msg);
  
}

void imprime_dist(int col, int lin, int dist){
lcd.setCursor(col, lin);
lcd.print(dist);
  
}

void imprime_cm(int col, int lin, char* cm){
lcd.setCursor(col, lin);
lcd.print(cm);
  
}