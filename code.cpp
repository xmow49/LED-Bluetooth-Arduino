//-------------------------------------
//         LEDs Control Bluetooth
//          GammaTroniques.fr
//               By Xmow
//               06/2017
//-------------------------------------
#include <SoftwareSerial.h>

SoftwareSerial HC06(11, 10); //HC06 Pins

String messageRecu; //msg
void setup() {
  Serial.begin(9600);
  HC06.begin(9600);

  //--------Pins LEDs--------
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);

  //-------Turn OFF LEDs-----
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  digitalWrite(7, LOW);
}

void loop() {
  //get msg from bluetooth
  while (HC06.available()) {
    delay(3);
    char c = HC06.read();
    messageRecu += c;
  }
  //check the msg and switch leds
  if (messageRecu.length() > 0) {
    Serial.println(messageRecu);
    if (messageRecu == "LEDb : 1") {
      digitalWrite(9, HIGH);
    }
    else if (messageRecu == "LEDb : 0") {
      digitalWrite(9, LOW);
    }
    else if (messageRecu == "LEDbl : 1") {
      digitalWrite(8, HIGH);
    }
    else if (messageRecu == "LEDbl : 0") {
      digitalWrite(8, LOW);
    }
    else if (messageRecu == "LEDr : 1") {
      digitalWrite(7, HIGH);
    }
    else if (messageRecu == "LEDr : 0") {
      digitalWrite(7, LOW);
    }
    else if (messageRecu == "TOUT : 1") {
      digitalWrite(9, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(7, HIGH);
    }
    else if (messageRecu == "TOUT : 0") {
      digitalWrite(9, LOW);
      digitalWrite(8, LOW);
      digitalWrite(7, LOW);
    }
    messageRecu = "";
  }
}
