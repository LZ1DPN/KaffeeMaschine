// KafeMashina, rev 2.0/2018

#define LED1 (2)
#define LED2 (3)
#define LED3 (4)
#define LED4 (5)
#define LED5 (6)
#define SUGARBTN (7)
#define STARTBTN (8)
#define STARTDRINK (9)
#define pulseHigh(pin) {digitalWrite(pin, HIGH); digitalWrite(pin, LOW); }

// buttons temp var
int BTNON = 0;   
int BTNlaststate = 0;
int BTNcheck = 0;
int BTNcheck2 = 0;
int BTNinc = 0;
int SUGARtime = 1; // in seconds !!! if need calculate another time

void setup() {
pinMode(LED1, OUTPUT);
digitalWrite(LED1, LOW);  

pinMode(LED2, OUTPUT);
digitalWrite(LED2, LOW); 

pinMode(LED3, OUTPUT);
digitalWrite(LED3, LOW);
 
pinMode(LED4, OUTPUT);
digitalWrite(LED4, LOW); 

pinMode(LED5, OUTPUT);
digitalWrite(LED5, LOW); 

pinMode(SUGARBTN, INPUT);
digitalWrite(SUGARBTN, HIGH);

pinMode(STARTBTN, INPUT);
digitalWrite(STARTBTN, LOW);

pinMode(STARTDRINK, OUTPUT);
digitalWrite(STARTDRINK, LOW); 

//default LED and time
digitalWrite(LED1, HIGH);
digitalWrite(LED2, LOW);  
digitalWrite(LED3, LOW);  
digitalWrite(LED4, LOW);  
digitalWrite(LED5, LOW);
SUGARtime = 1;    
}

void loop() {
  checkSUGARBTN();      // check for press button 
  checkSTART();         // check for start to make drink
}

//external functions

// START
void checkSTART(){
  BTNON = digitalRead(STARTBTN);
  if(BTNON == HIGH){
      digitalWrite(STARTDRINK, HIGH);
      delay(SUGARtime * 1000);  // in seconds !!! if need calculate another time
      digitalWrite(STARTDRINK, LOW);
      }
}

// SUGARBTN
void checkSUGARBTN(){
BTNON = digitalRead(SUGARBTN);    
    if(BTNON == LOW){
         BTNinc = BTNinc + 1;
         
         if(BTNinc > 6){
              BTNinc = 1;
            }
    
		 BTNlaststate = BTNcheck2;
 // next will be rewriten if need another way to put sugar    
    switch (BTNinc) {
          case 1:
            digitalWrite(LED1, LOW);
            digitalWrite(LED2, LOW);  
            digitalWrite(LED3, LOW);  
            digitalWrite(LED4, LOW);  
            digitalWrite(LED5, LOW);
            SUGARtime = 0;              // in seconds !!! if need calculate another time     
            break;
          case 2:
            digitalWrite(LED1, HIGH);
			SUGARtime = 1;				// in seconds !!! if need calculate another time    
            break;
          case 3:
            digitalWrite(LED1, HIGH);
            digitalWrite(LED2, HIGH);
			SUGARtime = 2;				// in seconds !!! if need calculate another time    
            break;
          case 4:
            digitalWrite(LED1, HIGH);
            digitalWrite(LED2, HIGH);
            digitalWrite(LED3, HIGH);
			SUGARtime = 3;				// in seconds !!! if need calculate another time    
            break;
          case 5:
            digitalWrite(LED1, HIGH);
            digitalWrite(LED2, HIGH);
            digitalWrite(LED3, HIGH);
            digitalWrite(LED4, HIGH);
			SUGARtime = 4;				// in seconds !!! if need calculate another time    
            break;
          case 6:
            digitalWrite(LED1, HIGH);
            digitalWrite(LED2, HIGH);
            digitalWrite(LED3, HIGH);
            digitalWrite(LED4, HIGH);
            digitalWrite(LED5, HIGH);
			SUGARtime = 5;				// in seconds !!! if need calculate another time    
            break;    
          default:
            digitalWrite(LED1, HIGH);
            digitalWrite(LED2, LOW);  
            digitalWrite(LED3, LOW);  
            digitalWrite(LED4, LOW);  
            digitalWrite(LED5, LOW);
            SUGARtime = 1;              // in seconds !!! if need calculate another time    
            break;
        }         
        delay(150);     
    }
}

// EOF
