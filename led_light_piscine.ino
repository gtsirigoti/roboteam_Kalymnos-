int light = 0; // store the current light value

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600); //configure serial to talk to computer
    pinMode(11, OUTPUT); // configure digital pin 11 as an output
}
    
void loop() {
    // put your main code here, to run repeatedly:
 light = analogRead(A0);//read and save value from PR
    Serial.println(light); // print current light value
 
    if(light > 600) { // If it is bright...
        Serial.println("It is quite light!");
        digitalWrite(11,LOW); //turn left LED off
    }
      else { // If it's dark...
        Serial.println("It is pretty dark!");
        digitalWrite(11,HIGH); // Turn left LED on
        
    }
    delay(1000); // don't spam the computer!
}
