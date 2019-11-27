//The Pin Numbers of the Hardware
const int Sensor = 5;
const int ElectromagnetPlus = 7;
const int ElectromagnetMinus = 8;

//Variables of the Program
bool flag = false;
bool newData = false;
bool restart = false;
int time1 = 0;
int time2 = 0;
int timefinal = 0;
char serial1 = "";

//Setting up all the things
void setup() {
        Serial.begin(9600);                     //Start Serial Interface
        pinMode(Sensor, INPUT);                 //Set Sensor as input
        pinMode(ElectromagnetPlus, OUTPUT);     //Set the wires to the H Bridge up as Inputs
        pinMode(ElectromagnetMinus, OUTPUT);    
        Serial.print("I have Started Good\n");  //An Indicator to the user that the Setup is Complete
}

void loop() {
        ArmElectromagnet();           //Arms Electromagnet
        while (Serial.available())    //Checks for a input from the Serial interface (from the lapatop)
        {
        Serial.print("Launching\n");
        time1 = millis();             //Takes a reading of the time since the program has started
        digitalWrite(ElectromagnetPlus,LOW);  //Disenguages Electromagnet
        Serial.print("Electromagnet Disengaged\n");
        while (true)                 //Runs consistantly until the loop is broken out of
        {
          if (digitalRead(Sensor) == HIGH)   //If the Sensor is closed
          {
            time2 = millis();                //takes a second reading of the time
            Serial.print("Sensor has been read as HIGH\n");
            break;                           //Loop broken out of
          }
        }
        timefinal = time2 - time1;           //Works out the time the ball was in the air
        Serial.print("The time taken was :");
        Serial.println(timefinal);
        }
}

void ArmElectromagnet(){
        digitalWrite(ElectromagnetPlus,HIGH);   //Setting one of the wires to positive             
        digitalWrite(ElectromagnetMinus,LOW);   //Setting the other to negative
        }
