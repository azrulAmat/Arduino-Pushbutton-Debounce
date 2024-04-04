#define SW1 8
#define dbounceDelay 40

unsigned long lowtrigtime;
unsigned char sw1_stat;

void setup() {
  pinMode(SW1,INPUT_PULLUP);
  Serial.begin(38400);
  sw1_stat=0;
}

void loop() {

  int sw1 = digitalRead(SW1);

  if(sw1==0){
    if(sw1_stat==0){
      lowtrigtime=millis();
      sw1_stat=1;
    }
    else if(millis()-lowtrigtime > dbounceDelay && sw1_stat != 2){
      Serial.println("SW-Pressed");
      sw1_stat=2;
    }
  }
  else{
    sw1_stat=0;
  }
  
}
