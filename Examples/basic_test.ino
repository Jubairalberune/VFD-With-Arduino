/*
 * ============================================================
 * Basic Test Code for VFD
 * ============================================================
 * 
 * Tests Phase A output - should produce 50Hz square wave
 * ============================================================
 */

int AA1 = 9;   // Phase A High-Side
int AA2 = 3;   // Phase A Low-Side

void setup() {
  pinMode(AA1, OUTPUT);
  pinMode(AA2, OUTPUT);
  digitalWrite(AA1, LOW);
  digitalWrite(AA2, LOW);
}

void loop() {
  // High-Side ON
  digitalWrite(AA1, HIGH);
  digitalWrite(AA2, LOW);
  delay(10);
  
  // Both OFF
  digitalWrite(AA1, LOW);
  digitalWrite(AA2, LOW);
  delay(10);
  
  // Low-Side ON
  digitalWrite(AA1, LOW);
  digitalWrite(AA2, HIGH);
  delay(10);
  
  // Both OFF
  digitalWrite(AA1, LOW);
  digitalWrite(AA2, LOW);
  delay(10);
}