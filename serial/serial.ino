void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop()
{
  if(Serial.available()) {
    String inputString = "";
    while(Serial.available()) {
        char inChar = (char) Serial.read();
        inputString += inChar;
    }
    
    Serial.println(inputString);
    
    while (Serial.available() > 0) { 
      char junk = Serial.read(); // clear the serial buffer
    } 
    
    if(inputString == "a") {
      digitalWrite(13, HIGH);  
    } else if(inputString == "b") {
      digitalWrite(13, LOW);
    }
    
    inputString = "";
  }
}
