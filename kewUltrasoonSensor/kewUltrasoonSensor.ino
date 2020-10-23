
#define baudrate 9600
#define pulseTimeout 50000 //50.000µs of 50ms

//Variabelen
bool UNO = true; 
int amountSensors = 4;

void setup() {
  Serial.begin(baudrate); 
  //Geef initializatie door aan monitor
  Serial.print("Serial started at "); 
  Serial.print(baudrate);
  Serial.print(" bauds\r\n");

  
  if(UNO == true){ 
    for(int i = 2; i <= amountSensors+2; i++){
      pinMode(i, INPUT);
    }

    for(int j = 7; j <= 7 + amountSensors; j++){
      pinMode(j, OUTPUT);
    }
  }
  else if(UNO == false){ 
    for(int i = 2; i <= 2 + amountSensors; i++){
      pinMode(i, INPUT);
    }

    for(int j = 22; j <= 22 + amountSensors; j++){
      pinMode(j, OUTPUT);
    }
  }
}

void loop() {
  for (int k = 0; k < amountSensors; k++){
  
    Serial.print("\r\nSensor ");
    Serial.print(k);
    Serial.print(" ");
    if(UNO == true){
      Serial.print(GetDistance(7+k, 2+k)); 
    }
    else if(UNO == false){
      Serial.print(GetDistance(22+k, 2+k)); 
    }
    Serial.print("CM\r\n");
  }
  delay(1000);
}


double GetDistance(int trigpin, int echopin){
  long duration;
  double distance;
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  duration = pulseIn(echopin, HIGH, pulseTimeout);
  distance = (duration/2)/29.1;
  return distance;
}
