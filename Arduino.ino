float alh=0.0;
float alm=1000.0;
float avgl;
float avgh;
float avg;
boolean stringComplete = false;
String inputString = "";
void setup()

{
  inputString.reserve(2);
  Serial.begin(115200);
  Serial.println("The system will now calibrate the alpha wave amplitudes of your brain. The global maxima and the global minima will be"); 
  Serial.println("taken as equivalent to a YES or NO respectively.");
  delay(5000);
  Serial.println("To assert a positive response for any of the following questions, relax your mind by trying to free yourself of all");
   Serial.println("thoughts.");
   delay(5000);
  Serial.println("To assert a negative response, focus your mind on any simple idea. A good example would be to try and solve");
  Serial.println("a simple math problem, like the value of 25*5-35.");
   Serial.println("Relax your mind for calibration.");
 delay(2000);
 for (int i=0;i<100;i++){
   if (alh<analogRead(A0)){
     alh=analogRead(A0);}
     delay(50);
 }
 
 Serial.println(alh);
 Serial.println("Focus your mind for calibration");
 delay(2000);
 for (int j=0;j<100;j++){
 if (alm>analogRead(A0)){
  alm=analogRead(A0);}
 delay(50);

 }
avg=(alm+alh)/2;
Serial.println(avg);
avgl=alm+(avg/2);
avgh=alh-(avg/2);
delay(50);
Serial.println("ready");

}


 void loop()
 
 
{ 
 delay(100);
if (stringComplete) {
   
    {
      if (analogRead(A0)>avgh)
            {
              Serial.println("NO.");
             
            }
      
       else if (analogRead(A0)<avgl)
            {
              Serial.println("YES.");
             
            }
     
      else 
            {
              Serial.print("Waiting for response.");
            }
            
            stringComplete = false;
   } 
  
}

}

void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
        if (inChar == '\n') {
      stringComplete = true;
    }
  }
}