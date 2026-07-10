# 🔧 Troubleshooting Guide

## Common Issues and Solutions

| Problem | Likely Cause | Solution |
|:---|:---|:---|
| **Simulation won't run** | Too many duplicate components | Delete all extra components, keep only 1 of each |
| **7812 output 9.5V** | No minimum load | Add 1kΩ resistor from output to ground |
| **Motor doesn't spin** | VS pin floating | Connect IR2110 Pin 5 to phase output |
| **High-side MOSFETs off** | SD pin floating | Ground IR2110 Pin 11 |
| **Timestep error** | Motor inductance too high | Set motor inductance to 1mH |
| **Oscilloscope flat lines** | Simulation crashed | Fix timestep errors first |
| **No DC bus voltage** | AC source grounded | Remove ground from AC source |

## Debugging Checklist

- [ ] AC source amplitude = 311V (peak)
- [ ] AC source frequency = 50Hz
- [ ] Negative DC rail grounded
- [ ] IR2110 VCC = +12V
- [ ] IR2110 VDD = +5V
- [ ] IR2110 SD = GND
- [ ] IR2110 VS = Phase Output
- [ ] Bootstrap caps = 100µF
- [ ] Bootstrap diodes = UF5406
- [ ] Gate resistors = 22Ω
- [ ] Motor inductance = 1mH