#include <Servo.h>
#include <Arduino.h>

const int NUM_SWITCHES = 3;
const int servoPins[NUM_SWITCHES] = { 10, 11, 12 };
const int switchPins[NUM_SWITCHES] = { 2, 3, 4 };

const int ledPin = 5; 
const int servolidPin = 9;

Servo servos[NUM_SWITCHES];
Servo servolid;

int currentStates[NUM_SWITCHES] = { HIGH, HIGH, HIGH };
int lastStates[NUM_SWITCHES] = { HIGH, HIGH, HIGH };

int shyPhaseCounter = 0;
int ngryPhaseCounter = 0;
int caseID = 0;

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < NUM_SWITCHES; i++) {
    servos[i].attach(servoPins[i]);
    pinMode(switchPins[i], INPUT_PULLUP);
    servos[i].write(80);
    delay(10);
  }

  servolid.attach(servolidPin);
  servolid.write(50);

  pinMode(ledPin, OUTPUT);
  analogWrite(ledPin, 0);
}

void scaredMode(int i) {

  if (i == 2) {
    Serial.println("scared variant 2...");
      delay(100);
      analogWrite(ledPin, 255);
      delay(500);
      analogWrite(ledPin, 0);
      delay(500);
      analogWrite(ledPin, 255);
      delay(300);
      analogWrite(ledPin, 100);
      delay(20);

      servolid.write(110);
      delay(1500);
      servolid.write(40);
      delay(3000);
      servolid.write(110);
      delay(100);
      

      for (int pos = 30; pos < 100; pos++) {
        servos[i].write(pos);
        delay(100);
      }
      delay(200);

      servos[i].write(30);
      delay(100);

      for (int poslid = 110; poslid > 50; poslid--) {
          servolid.write(poslid);
          delay(10);
      }
    analogWrite(ledPin, 0);
  }
      
  else {
      Serial.println("scared Normal variant...");
      delay(100);
      analogWrite(ledPin, 255);
      delay(500);
      analogWrite(ledPin, 0);
      delay(500);
      analogWrite(ledPin, 255);
      delay(300);
      analogWrite(ledPin, 100);
      delay(20);

      servolid.write(110);
      delay(1500);
      servolid.write(50);
      delay(3000);
      servolid.write(110);
      delay(100);
      

      for (int pos = 80; pos > 10; pos--) {
        servos[i].write(pos);
        delay(100);
      }
      delay(200);
      servos[i].write(80);
      delay(10);

      for (int poslid = 110; poslid > 50; poslid--) {
          servolid.write(poslid);
          delay(10);
      }

      analogWrite(ledPin, 0);
    }
}

void PeekingOutMode(int i){
  if (i == 2) {
        Serial.print("Peeking out varinat 2...");
        analogWrite(ledPin, 255);
        delay(500);
        analogWrite(ledPin, 0);
        delay(500);
        analogWrite(ledPin, 255);
        delay(500);
        analogWrite(ledPin, 100);
        servos[i].write(30);
        delay(100);
    
        for (int poslid = 50; poslid < 110; poslid++) {
          servolid.write(poslid);
          delay(10);
        }

        delay(500);

        for (int pos = 30; pos < 100; pos++) {
          servos[i].write(pos);
          delay(10);
        }

        delay(300);
        servos[i].write(30);
        servolid.write(50);
        delay(100);
        analogWrite(ledPin, 0);
      } 
      else {
        Serial.print("Peeking out normal varinat...");

        analogWrite(ledPin, 255);
        delay(500);
        analogWrite(ledPin, 0);
        delay(500);
        analogWrite(ledPin, 255);
        delay(500);
        analogWrite(ledPin, 100);

        for (int poslid = 50; poslid < 110; poslid++) {
          servolid.write(poslid);
          delay(10);
        }

        delay(100);

        for (int pos = 70; pos > 10; pos--) {
          servos[i].write(pos);
          delay(10);
        }

        delay(300);
        servos[i].write(80);
        servolid.write(50);
        delay(100);
        analogWrite(ledPin, 0);
      }
}

void CuriousMode(int i) {
  if (i == 2) {
        Serial.print("Curious variant 2...");
        analogWrite(ledPin, 255);
        delay(0);
        analogWrite(ledPin, 30);
        delay(0);
        analogWrite(ledPin, 255);
        delay(100);
        servolid.write(110);
        delay(100);

        for (int pos = 30; pos < 70; pos++) {
          servos[i].write(pos);
          delay(10);
        }
        delay(1000);

        for (int pos = 30; pos < 100; pos++) {
          servos[i].write(pos);
          delay(5);
        }
        delay(1000);

        for (int pos = 100; pos > 30; pos--) {
          servos[i].write(pos);
          delay(100);
        }

        analogWrite(ledPin, 255);
        delay(200);
        analogWrite(ledPin, 0);
        delay(200);
        analogWrite(ledPin, 255);
        delay(200);
        analogWrite(ledPin, 0);
        delay(200);
        analogWrite(ledPin, 255);
        delay(200);
        analogWrite(ledPin, 100);
        delay(1000);

        for (int poslid = 110; poslid > 50; poslid--) {
          servolid.write(poslid);
          delay(10);
        }
        delay(100);
        analogWrite(ledPin, 0);

      } else {
        Serial.print("Curious normal varinat...");
        analogWrite(ledPin, 255);
        delay(0);
        analogWrite(ledPin, 30);
        delay(0);
        analogWrite(ledPin, 255);
        delay(100);
        servolid.write(110);
        delay(100);

        for (int pos = 30; pos < 50; pos++) {
          servos[i].write(pos);
          delay(5);
        }
        delay(1000);

        for (int pos = 80; pos > 0; pos--) {
          servos[i].write(pos);
          delay(5);
        }
        delay(100);

        for (int pos = 0; pos < 80; pos++) {
          servos[i].write(pos);
          delay(5);
        }

        analogWrite(ledPin, 255);
        delay(200);
        analogWrite(ledPin, 0);
        delay(200);
        analogWrite(ledPin, 255);
        delay(200);
        analogWrite(ledPin, 0);
        delay(200);
        analogWrite(ledPin, 255);
        delay(200);
        analogWrite(ledPin, 100);
        delay(1000);

        for (int poslid = 110; poslid > 50; poslid--) {
          servolid.write(poslid);
          delay(5);
        }
        delay(100);
        analogWrite(ledPin, 0);
      }
}

void ImpatientMode(int i) {
   if (i == 2) {
        Serial.println("Impatient varinat 2...");
        analogWrite(ledPin, 255);
        delay(600);
        analogWrite(ledPin, 30);
        delay(0);
        analogWrite(ledPin, 255);
        delay(30);
        analogWrite(ledPin, 30);
        delay(0);
        analogWrite(ledPin, 255);
        delay(0);

        servolid.write(110);
        delay(100);

        servos[i].write(100);
        delay(1000);

        servos[i].write(30);
        delay(1000);

        for (int poslid = 110; poslid > 50; poslid--) {
          servolid.write(poslid);
          delay(5);
        }
        delay(100);
        analogWrite(ledPin, 0);

      } else {
        Serial.println("Impatient normal varinat...");
        analogWrite(ledPin, 255);
        delay(600);
        analogWrite(ledPin, 30);
        delay(0);
        analogWrite(ledPin, 255);
        delay(30);
        analogWrite(ledPin, 30);
        delay(0);
        analogWrite(ledPin, 255);
        delay(0);

        servolid.write(110);
        delay(100);

        for (int pos = 70; pos > 10; pos--) {
          servos[i].write(pos);
        }
        delay(1000);

        servos[i].write(80);
        delay(100);

        for (int poslid = 110; poslid > 50; poslid--) {
          servolid.write(poslid);
          delay(5);
        }
        delay(100);
        analogWrite(ledPin, 0);
      }
}
void RebelMode(int i) {

  if (i == 2) {
    Serial.println("rebel variant 2...");
      delay(100);
      analogWrite(ledPin, 255);
      delay(500);
      analogWrite(ledPin, 0);
      delay(500);
      analogWrite(ledPin, 255);
      delay(300);
      analogWrite(ledPin, 100);
      delay(20);

      servolid.write(110);
      delay(1000);

     servos[i].write(100);
     delay(100);
     servos[i].write(50);

     analogWrite(ledPin, 255);
     delay(200);
     analogWrite(ledPin, 0);
     delay(200);
     analogWrite(ledPin, 255);
     delay(200);
     analogWrite(ledPin, 0);
     delay(200);
     analogWrite(ledPin, 255);
     delay(200);
     analogWrite(ledPin, 100);
     delay(1500);

     servos[i].write(100);
     delay(100);
     servos[i].write(40);
     delay(10);

      for (int poslid = 110; poslid > 50; poslid--) {
          servolid.write(poslid);
          delay(10);
      }
    analogWrite(ledPin, 0);
  }
      
  else {
      Serial.println("rebel Normal variant...");
      delay(100);
      analogWrite(ledPin, 255);
      delay(500);
      analogWrite(ledPin, 0);
      delay(500);
      analogWrite(ledPin, 255);
      delay(300);
      analogWrite(ledPin, 100);
      delay(20);

      servolid.write(110);
      delay(1000);

     servos[i].write(5);
     delay(300);
     servos[i].write(40);

     analogWrite(ledPin, 255);
     delay(200);
     analogWrite(ledPin, 0);
     delay(200);
     analogWrite(ledPin, 255);
     delay(200);
     analogWrite(ledPin, 0);
     delay(200);
     analogWrite(ledPin, 255);
     delay(200);
     analogWrite(ledPin, 100);
     delay(1500);

     servos[i].write(5);
     delay(200);
     servos[i].write(80);
     delay(10);

      for (int poslid = 110; poslid > 50; poslid--) {
          servolid.write(poslid);
          delay(10);

      
      }

      analogWrite(ledPin, 0);
    }

}

void AngryMode(int i) {
  if (i == 2) {
        Serial.println("Angry variant 2...");
      analogWrite(ledPin, 255);
      delay(500);
      analogWrite(ledPin, 0);
      delay(200);
      analogWrite(ledPin, 255);
      delay(500);
      analogWrite(ledPin, 0);
      delay(200);
      analogWrite(ledPin, 255);
      delay(500);
      analogWrite(ledPin, 0);
      delay(200);
      analogWrite(ledPin, 100);
      delay(20);

      servolid.write(110);

      delay(100);
      servos[i].write(70);
      delay(200);
      servos[i].write(30);
      delay(500);
      servos[i].write(70);
      delay(200);
      servos[i].write(30);
      delay(500);
      servos[i].write(120);
      delay(100);
      servos[i].write(30);
      delay(100);

      analogWrite(ledPin, 255);
      delay(500);
      analogWrite(ledPin, 0);
      delay(500);
      analogWrite(ledPin, 255);
      delay(300);
      analogWrite(ledPin, 100);
      delay(10);

      for (int poslid = 110; poslid > 50; poslid--) {
          delay(300);
          servolid.write(poslid);
          delay(10);
        }
      }
      else {
      Serial.println("Angry normal variant...");
      analogWrite(ledPin, 100);
      delay(500);
      analogWrite(ledPin, 0);
      delay(200);
      analogWrite(ledPin, 255);
      delay(500);
      analogWrite(ledPin, 0);
      delay(200);
      analogWrite(ledPin, 255);
      delay(500);
      analogWrite(ledPin, 0);
      delay(200);
      analogWrite(ledPin, 100);
      delay(20);

      servolid.write(100);
      delay(1300);

      servos[i].write(70);
      delay(100);
      servos[i].write(30);
      delay(500);
      servos[i].write(70);
      delay(200);
      servos[i].write(30);
      delay(1000);
      servos[i].write(0);
      delay(100);
      servos[i].write(80);
      delay(100);

      analogWrite(ledPin, 255);
      delay(500);
      analogWrite(ledPin, 0);
      delay(500);
      analogWrite(ledPin, 255);
      delay(300);
      analogWrite(ledPin, 100);
      delay(10);

      for (int poslid = 110; poslid > 50; poslid--) {
          delay(10);
          servolid.write(poslid);
          delay(10);
        }
      }
}

void AnnoyedMode(int i) {
  if ( i == 2){
      Serial.println("Annoyed variant 2...");
      delay(1300);
      analogWrite(ledPin, 0);
      delay(100);
      analogWrite(ledPin, 255);
      delay(30);
      analogWrite(ledPin, 0);
      delay(300);
      analogWrite(ledPin, 255);
      delay(20);

      servolid.write(110);
      delay(100);
      for (int pos = 30; pos < 80; pos++) {
        servos[i].write(pos);
        delay(100);
      }
      servos[i].write(30);
      delay(300);
      servos[i].write(100);
      delay(200);
      servos[i].write(30);
      delay(100);
      for (int poslid = 110; poslid > 50; poslid--) {
          delay(10);
          servolid.write(poslid);
          delay(10);
        }
      }
      else {
      Serial.println("Annoyed normal varinat...");
      delay(1300);
      analogWrite(ledPin, 0);
      delay(100);
      analogWrite(ledPin, 255);
      delay(10);
      analogWrite(ledPin, 0);
      delay(300);
      analogWrite(ledPin, 255);
      delay(20);

      servolid.write(110);
      delay(100);
      for (int pos = 80; pos > 20; pos--) {
        servos[i].write(pos);
        delay(10);
      }
      servos[i].write(60);
      delay(300);
      servos[i].write(10);
      delay(200);
      servos[i].write(80);
      delay(100);
      for (int poslid = 110; poslid > 50; poslid--) {
          delay(10);
          servolid.write(poslid);
          delay(10);
        }
      }
     delay(100);
     analogWrite(ledPin, 0);  
  }

void runShy(int i, int shyPhaseCounter) {
  Serial.println("Shy behaviour running...");
  delay(0);

  switch (shyPhaseCounter) {
    case 0:
    scaredMode(i);
    break;

    case 1:
    PeekingOutMode(i);
    break;

    case 2:
    CuriousMode(i);
    break;

    case 3:
    ImpatientMode(i);
    break;
     
    case 4: 
    RebelMode(i);
    break;
  }

}

void runAngry(int i, int caseID) {
  Serial.println("ANGRY MODE ACTIVATED!");
  analogWrite(ledPin, 255);
  delay(100);

  switch (caseID) {
    case 0:
    AngryMode(i);
    break;
      
    case 1:
    AnnoyedMode(i);
    break;
}
      

}
void loop() {
  for (int i = 0; i < NUM_SWITCHES; i++) {
    currentStates[i] = digitalRead(switchPins[i]);

    // Rilevamento fronte di discesa
    if (lastStates[i] == HIGH && currentStates[i] == LOW) {
      Serial.print("Switch premuto: ");
      Serial.println(i);

      if (shyPhaseCounter < 5) {
        Serial.print("in loop, ");
        runShy(i, shyPhaseCounter);
        shyPhaseCounter++;
        Serial.println(shyPhaseCounter);
      } else {
        runAngry(i, random(0, 2));
        shyPhaseCounter = 0;
        Serial.print("shyphase restarted");
      }
    }

    lastStates[i] = currentStates[i];
  }

}
