// Distributed with a free-will license.
// Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
// PCA9533

#include <Arduino.h>
#include <Wire.h>
#include <PCA9533.h>

PCA9533 pca9533;                              // construct a new PCA9533 instance

void setup()
{
  // Initialise I2C communication
  Wire.begin();
  // Initialise serial communication
  Serial.begin(115200);
  delay(300);
  Serial.println("Starting device");
  // Setup PCA9533 and do some initial tests
  Serial.println("Setup LED Controller");
  // make sure device testing starts with default settings
  pca9533.init();
  Serial.println("Running init tests");
  Serial.print("Checking I2C Bus: ");
  Serial.println(pca9533.ping());
  pca9533.setPSC(REG_PSC0, 0);
  pca9533.setPSC(REG_PSC1, 29);
  pca9533.setMODE(IO0, LED_MODE_OFF);
  pca9533.setMODE(IO1, LED_MODE_OFF);
  pca9533.setMODE(IO2, LED_MODE_OFF);
  pca9533.setMODE(IO3, LED_MODE_OFF);
}

void loop()
{
  
  pca9533.setMODE(IO0, LED_MODE_OFF);
  pca9533.setMODE(IO1, LED_MODE_OFF);
  pca9533.setMODE(IO2, LED_MODE_OFF);
  delay(50);
  
  // Test LED1
  Serial.println("Blinking LED1 at 5Hz");
  pca9533.setMODE(IO0, LED_MODE_PWM1);
  pca9533.setPWM(REG_PWM1, 64);
  delay(2000);  
  pca9533.setMODE(IO0, LED_MODE_OFF);
  delay(50);
  
  // Test LED2
  Serial.println("Dimming LED2 from 0% to 100%");
  pca9533.setMODE(IO1, LED_MODE_PWM0);
  for (int i = 0; i < 50; i++) {
    pca9533.setPWM(REG_PWM0, i*5);
    delay(40);  
  }
  pca9533.setMODE(IO1, LED_MODE_OFF);
  delay(50);
  
  // Test LED3
  Serial.println("Testing LED3 from 100% to 0%");
  pca9533.setMODE(IO2, LED_MODE_PWM0);
  for (int i = 0; i < 50; i++) {
    pca9533.setPWM(REG_PWM0, 250-i*5);
    delay(40);  
  }
  pca9533.setMODE(IO2, LED_MODE_OFF);
  delay(50);
  
  Serial.print("IO0 is : ");
  Serial.print(pca9533.getINPUT(IO0));
  Serial.println("");
  Serial.print("IO1 is : ");
  Serial.print(pca9533.getINPUT(IO1));
  Serial.println("");
  Serial.print("IO2 is : ");
  Serial.print(pca9533.getINPUT(IO2));
  Serial.println("");
  Serial.print("IO3 is : ");
  Serial.print(pca9533.getINPUT(IO3));
  Serial.println("");

} 


