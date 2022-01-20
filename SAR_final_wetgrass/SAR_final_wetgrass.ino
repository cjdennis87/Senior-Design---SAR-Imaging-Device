int RelaySAR = 11;
int count; 
int RelayWheel = 10;
void setup() {
  Serial.begin(9600);
  //setting outputs
  //Relay Wheel controls the electric motors
  //Relay SAR controls the Sync Pulse on the modulator
  pinMode(RelayWheel, OUTPUT);
  pinMode(RelaySAR, OUTPUT);
  
}
void loop() {
  //"Homing" the relays so that the Mobile Sar doesn't move
  digitalWrite(RelayWheel, HIGH);
  digitalWrite(RelaySAR, HIGH);
  //This command allows users to remotely type in the serial monitor 
  // to start whenever the command is given
  Serial.println(F("Starting the SAR, is the system hot?"));
  //In accordance with our safety constraints, the system asks the user if the system is hot, 
  //so that nothing moves if someone is in the way
  //and acts as a warning to not touch the electrical components
  
  while (!Serial.available()) {
    // wait for user input
  }
  Serial.println("Hold onto your butts");
  //Classic Jurassic Park reference
  digitalWrite(RelayWheel, LOW);
  Serial.println("running");
  //normal grass 11250
  delay(13250);
  //run for 11.25 seconds
  Serial.println("stopping");
  //SAR loop that toggles the sync pulse for 45 times to get the enough information
  //on the environment 
  for (int i = 1; i <= 45; i++) {
    count = count + 1;
    digitalWrite(RelayWheel, HIGH);
    delay(750);
    //stabilizing
    digitalWrite(RelaySAR, LOW);
    Serial.println("taking the picture");
    delay(1500);
    //move car to next position
    digitalWrite(RelaySAR, HIGH); 
    digitalWrite(RelayWheel, LOW);
    Serial.println(count);
    //1120 for normal grass
    delay(1708);
  }
  
  digitalWrite(RelayWheel, LOW);
  digitalWrite(RelaySAR, HIGH);
  Serial.println("Going after the delay");
  delay(11000);
  digitalWrite(RelayWheel, HIGH);
  while (1) {} // hold in infinite loop
  //mobile SAR gets put in an infinite loop so that the team can 
  //recover the radar from it's end position with the robot continuing
  //to move. 
}
