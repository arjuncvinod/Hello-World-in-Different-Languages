//MQ - 9 Calibration
int input = A0;
 void setup() { 
  pinMode(input,INPUT);
  Serial.begin(9600); 
}   
void loop() { 
  float sensor_volt;  
  float RS_air; 
  float R0; 
  float sensorValue = 0.0; 
 
  
    for(int x = 0 ; x < 100 ; x++) 
  { 
    sensorValue = sensorValue + analogRead(input); 
  } 
  sensorValue = sensorValue/100.0; 

 
  sensor_volt = (sensorValue/1024)*5.0; 
  RS_air = (5.0-sensor_volt)/sensor_volt; 
  R0 = RS_air/9.9; 
   
  Serial.print("sensor_volt = "); 
  Serial.print(sensor_volt); 
  Serial.println("V");
  
  Serial.print("R0 = "); 
  Serial.println(R0); 
  delay(1000); 
}
