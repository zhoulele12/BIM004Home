#include <Servo.h>
#include <Adafruit_Fingerprint.h>
SoftwareSerial mySerial(2, 3);
Servo myServo;
int servoPin = 9;
int buttonPin = 4; 
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);
int prevButton = 0;
int buttonState = 0;
int lockState = 0;
int prevLock = 0;
void setup()
{
  Serial.begin(9600);
  finger.begin(57600);
  delay(5);
  if (finger.verifyPassword()){
    Serial.println("Found fingerprint sensor!");
  }
  pinMode(buttonPin,INPUT_PULLUP);
  //0 is open, 1 is closed
  
}

void loop()                     // run over and over again
{
  getFingerprintID();
  button();
  checkLockState();
  delay(50);
}

void button() {
  buttonState = digitalRead(buttonPin);
  if(buttonState!=prevButton){
    myServo.attach(9);
    if(buttonState==1){
      myServo.write(0);
    } else{
      myServo.write(60);
     }
    delay(500);
    myServo.detach();
    prevButton = buttonState;
    lockState = prevButton;
    }
  }
void checkLockState(){
  if(lockState==1){
    finger.LEDcontrol(FINGERPRINT_LED_ON, 0, FINGERPRINT_LED_PURPLE);
  }
  if(lockState==0){
    finger.LEDcontrol(FINGERPRINT_LED_OFF, 0, FINGERPRINT_LED_PURPLE);  
  } 
  
  }

uint8_t getFingerprintID() {
  uint8_t p = finger.getImage();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.println("No finger detected");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }

  // OK success!

  p = finger.image2Tz();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }

  // OK converted!
  p = finger.fingerSearch();
  if (p == FINGERPRINT_OK) {
    Serial.println("Found a print match!");
    
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_NOTFOUND) {
    finger.LEDcontrol(FINGERPRINT_LED_ON, 0, FINGERPRINT_LED_RED);
    delay(1000);
//    finger.LEDcontrol(FINGERPRINT_LED_OFF, 0, FINGERPRINT_LED_RED);
    Serial.println("Did not find a match");
    return p;
  } else {
    Serial.println("Unknown error");
    return p;
  }
  
  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID);
  Serial.print(" with confidence of "); Serial.println(finger.confidence);
  
  myServo.attach(9);
  if(lockState==0){
    myServo.write(0);
    lockState=1;  
  } else {
    myServo.write(60);
    lockState=0;
  }
  
  finger.LEDcontrol(FINGERPRINT_LED_BREATHING, 100, FINGERPRINT_LED_BLUE);
  delay(2000);
//  finger.LEDcontrol(FINGERPRINT_LED_OFF, 0, FINGERPRINT_LED_BLUE);
  myServo.detach();
  
  return finger.fingerID;
}
