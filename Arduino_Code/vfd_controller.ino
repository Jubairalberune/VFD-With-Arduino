/*
 * ============================================================
 * Three-Phase VFD Controller
 * Six-Step Commutation with Potentiometer Speed Control
 * ============================================================
 * 
 * Simulation Verified ✅ Perfectly Working ✅
 * 
 * Pin Mapping:
 *   Phase A: D9 (High) - AA1, D3 (Low) - AA2
 *   Phase B: D10 (High) - BB1, D5 (Low) - BB2
 *   Phase C: D11 (High) - CC1, D6 (Low) - CC2
 *   Speed Control: A0 - Potentiometer
 * 
 * ============================================================
 */

// ===== Pin Definitions =====
int AA1 = 9;   // Phase A High-Side
int AA2 = 3;   // Phase A Low-Side
int BB1 = 10;  // Phase B High-Side
int BB2 = 5;   // Phase B Low-Side
int CC1 = 11;  // Phase C High-Side
int CC2 = 6;   // Phase C Low-Side

// ===== State Variables =====
int fase = 1;                   // Current step (1-6)
int tiempo = 100;               // Delay between steps (microseconds)
unsigned long previousMillis = 0; // Last step timestamp
int Stop = 0;                   // Safety flag (0=stop, 1=run)
int val = A0;                   // Potentiometer pin

// ============================================================
// Setup Function
// ============================================================
void setup() {
  // Enable serial debugging (optional)
  Serial.begin(9600);
  
  // Configure all MOSFET pins as outputs
  pinMode(AA1, OUTPUT);
  pinMode(AA2, OUTPUT);
  pinMode(BB1, OUTPUT);
  pinMode(BB2, OUTPUT);
  pinMode(CC1, OUTPUT);
  pinMode(CC2, OUTPUT);
  
  // Configure potentiometer as input
  pinMode(val, INPUT);
  
  // Wait for hardware to stabilize
  delay(1000);
  
  // Initialize the timing engine
  previousMillis = micros();
}

// ============================================================
// Main Loop
// ============================================================
void loop() {
  
  // ---- Safety Check ----
  // If the delay is too long (potentiometer at minimum),
  // stop the motor to prevent overheating/stalling.
  if(tiempo > 1950) {
    Stop = 0;
    tiempo = 1950;
    
    // Turn off all MOSFETs
    digitalWrite(AA1, LOW);
    digitalWrite(AA2, LOW);
    digitalWrite(BB1, LOW);
    digitalWrite(CC2, LOW);
    digitalWrite(BB2, LOW);
    digitalWrite(CC1, LOW);
  } else {
    Stop = 1;
  }

  // ---- Non-Blocking Timing Engine ----
  if(Stop == 1) {
    unsigned long currentMillis = micros();
    
    if(currentMillis - previousMillis >= tiempo) {
      previousMillis += tiempo;
      
      // ---- Six-Step Commutation ----
      switch(fase) {
        
        // Phase 1: C → B (0 degrees)
        case 1:
          digitalWrite(AA1, LOW);
          digitalWrite(AA2, LOW);
          digitalWrite(BB1, LOW);
          digitalWrite(CC2, LOW);
          digitalWrite(BB2, HIGH);
          digitalWrite(CC1, HIGH);
          break;

        // Phase 2: A → B (60 degrees)
        case 2:
          digitalWrite(AA2, LOW);
          digitalWrite(BB1, LOW);
          digitalWrite(CC1, LOW);
          digitalWrite(CC2, LOW);
          digitalWrite(AA1, HIGH);
          digitalWrite(BB2, HIGH);
          break;

        // Phase 3: A → C (120 degrees)
        case 3:
          digitalWrite(AA2, LOW);
          digitalWrite(BB1, LOW);
          digitalWrite(BB2, LOW);
          digitalWrite(CC1, LOW);
          digitalWrite(CC2, HIGH);
          digitalWrite(AA1, HIGH);
          break;

        // Phase 4: B → C (180 degrees)
        case 4:
          digitalWrite(AA1, LOW);
          digitalWrite(AA2, LOW);
          digitalWrite(BB2, LOW);
          digitalWrite(CC1, LOW);
          digitalWrite(BB1, HIGH);
          digitalWrite(CC2, HIGH);
          break;

        // Phase 5: B → A (240 degrees)
        case 5:
          digitalWrite(AA1, LOW);
          digitalWrite(BB2, LOW);
          digitalWrite(CC1, LOW);
          digitalWrite(CC2, LOW);
          digitalWrite(AA2, HIGH);
          digitalWrite(BB1, HIGH);
          break;

        // Phase 6: C → A (300 degrees)
        case 6:
          digitalWrite(AA1, LOW);
          digitalWrite(BB1, LOW);
          digitalWrite(BB2, LOW);
          digitalWrite(CC2, LOW);
          digitalWrite(CC1, HIGH);
          digitalWrite(AA2, HIGH);
          break;
      }

      // Advance to the next phase
      if(fase < 6) {
        fase = fase + 1;
      } else {
        fase = 1;
      }
    }
  }

  // ---- Speed Control ----
  int t = analogRead(val);
  tiempo = map(t, 0, 1024, 1, 2000);
}

// ============================================================
// End of Code
// ============================================================