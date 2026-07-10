# Arduino VFD Code

## 📖 Overview

This folder contains the Arduino code for the Three-Phase VFD controller.

## 📁 Files

| File | Description |
|:---|:---|
| `vfd_controller.ino` | Main VFD code (recommended) |
| `vfd_controller_with_debug.ino` | Same code with Serial debugging enabled |

## 📊 Pin Mapping

| Phase | High-Side Pin | Low-Side Pin | Arduino Pin |
|:---|:---|:---|:---|
| A | AA1 | AA2 | D9, D3 |
| B | BB1 | BB2 | D10, D5 |
| C | CC1 | CC2 | D11, D6 |

## 🧪 How to Test

1. Upload the code to your Arduino
2. Connect a 10kΩ potentiometer to pin A0
3. Open Serial Monitor (9600 baud)
4. Turn the potentiometer

## ⚙️ Customization

```cpp
// Change speed range
tiempo = map(t, 0, 1024, 100, 3000);

// Enable debug output (uncomment)
Serial.print(fase);
Serial.print("  ");
Serial.println(tiempo);
text

---

## 📄 Documentation/Project_Report.md

```markdown
# Three-Phase VFD: Complete Project Report

## 📖 Executive Summary

This report documents the complete design, simulation, and implementation of a **Three-Phase Variable Frequency Drive (VFD)** using an **Arduino Nano/Uno**. The system converts fixed AC input into variable-frequency AC output, enabling precise speed control of a 3-phase induction motor.

### Key Achievements

| Achievement | Status |
|:---|:---|
| ✅ **Functional VFD** | Successfully drives 3-phase motors |
| ✅ **Simulation Verified** | Perfectly working in Proteus |
| ✅ **Clean Linear Supply** | 7812/7805 for stable 12V/5V |
| ✅ **Open Source** | MIT License - free to use |
| ✅ **Comprehensive Docs** | Complete build guide |

---

## 1. System Overview

### 1.1 Block Diagram
220V AC (3-Phase)
↓
Bridge Rectifier
↓
310V DC Bus
↓
┌──────┼──────┐
│ │ │
Phase A Phase B Phase C
│ │ │
IR2110 IR2110 IR2110
│ │ │
MOSFETs MOSFETs MOSFETs
│ │ │
└──────┼──────┘
↓
3-Phase Motor

text

### 1.2 Power Supply
220V AC → 12V AC Transformer → Bridge Rectifier → 7812 (12V) → 7805 (5V)

text

---

## 2. Hardware Design

### 2.1 Complete BOM

| Category | Component | Model | Quantity |
|:---|:---|:---|:---|
| **Power Stage** | Bridge Rectifier | KBP310 | 1 |
| | DC Bus Capacitor | 470µF / 400V | 1 |
| **Gate Drive** | Driver IC | IR2110 | 3 |
| | Bootstrap Capacitor | 100µF / 25V | 3 |
| | Bootstrap Diode | UF5406 | 3 |
| | Gate Resistor | 22Ω | 6 |
| **Power Switch** | IGBT | IRG4PH50UD | 6 |
| **Control** | Arduino | Nano/Uno | 1 |
| | Potentiometer | 10kΩ | 1 |

---

## 3. Firmware Design

### 3.1 Six-Step Commutation

| Phase | High-Side ON | Low-Side ON |
|:---|:---|:---|
| 1 | C | B |
| 2 | A | B |
| 3 | A | C |
| 4 | B | C |
| 5 | B | A |
| 6 | C | A |

### 3.2 Frequency Control
f_out = 1 / (6 × tiempo × 10^-6) Hz

text

---

## 4. Proteus Simulation

### 4.1 Simulation Settings

| Setting | Value |
|:---|:---|
| AC Source Amplitude | 311V (220V RMS) |
| AC Source Frequency | 50Hz |
| Motor Inductance | 1mH |
| Motor Resistance | 10Ω |

### 4.2 Status: ✅ PERFECTLY WORKING

---

## 5. Acknowledgments

This project was inspired by:
- **[Muhammad Ansar](https://github.com/embeddedlab786)** - Three Phase Soft Starter VFD
- **[YouTube Tutorial](https://www.youtube.com/watch?v=b0kbwg2XOtQ)** - Original inspiration video
- **International Rectifier** - IR2110 Datasheet
- **Arduino Community** - Open-source hardware and software
