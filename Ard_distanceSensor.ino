// Distance sensor port initialization
const int trig = 11;
const int echo = 12;

//LED port port initialzation 
const int LED1 = 2;
const int LED2 = 3;
const int LED3 = 4;
const int LED4 = 5;
const int LED5 = 6;
const int LED6 = 7;
const int LED7 = 8;

int duration = 0;
int distance = 0;

void setup() {

//Distance sensor port initialzation 
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

//LED port initialzation 
  pinMode(LED1, OUTPUT); 
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);

  Serial.begin(9600);
}

void loop() {
//Calibrate sensor 
  digitalWrite(trig, HIGH);
  delayMicroseconds(1000); 
  digitalWrite(trig, LOW);
 
  duration = pulseIn(echo, HIGH); //Distancing reading via pulses   
  distance = (duration/2) / 28.5; //Grabs pulse distance for LED 

  Serial.println(distance);

  //Last LED to turn on within distance
  if ( distance <= 5)
  {
    digitalWrite(LED1, HIGH);
  }
  else 
  {
    digitalWrite(LED1, LOW);
  }

  //Sixth LED to turn on within distance
  if ( distance <= 7 )
  {
    digitalWrite(LED2, HIGH);
  }
  else
  {
    digitalWrite(LED2, LOW);
  }

  //Fifth LED to turn on within distance
  if ( distance <= 10 )
  {
    digitalWrite(LED3, HIGH);
  }
  
  else 
  {
    digitalWrite(LED3, LOW);
  }


  //Fourth LED to turn on within distance
  if ( distance <= 15 )
  {
    digitalWrite(LED4, HIGH);
  }
  else 
  {
    digitalWrite(LED4, LOW);
  }

  //Third LED to turn on within distance
  if ( distance <= 17 )
  {
    digitalWrite(LED5, HIGH);
  }
  else 
  {
    digitalWrite(LED5, LOW);
  }

  //Second LED to turn on within distance
  if ( distance <= 20 )
  {
    digitalWrite(LED6, HIGH);
  }
  else 
  {
    digitalWrite(LED6, LOW);
  }

  //First LED to turn on within distance
  if ( distance <= 25 ) 
  {
    digitalWrite(LED7, HIGH);
  }
  else 
  {
    digitalWrite(LED7, LOW);
  }

}
