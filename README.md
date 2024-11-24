
# Simulation of Diode Using C Language

## Overview
This project simulates the behavior of Silicon and Germanium PN-Junction diodes under forward and reverse bias conditions. The project uses the **Shockley diode equation** to model current-voltage characteristics, providing results in text files for both materials and biases. 

## Features
- Simulates **Silicon** and **Germanium** diodes.
- Includes both **forward** and **reverse bias** conditions.
- Outputs results with clear voltage-current tables.
- Identifies **knee voltage** in forward bias and **breakdown voltage** in reverse bias.

## Project Motivation
The primary motivation for this project was to gain a deeper understanding of the physical and mathematical principles of diode behavior. As part of the learning process, this project helped bridge theoretical knowledge and practical implementation in C programming.

## Theory
1. **Forward Bias:**
   - Current increases exponentially with voltage after the knee voltage is reached.
   - Knee voltage for Silicon: ~0.7V; for Germanium: ~0.3V.
2. **Reverse Bias:**
   - Leakage current flows until breakdown voltage.
   - Breakdown voltage for Silicon: -50V; for Germanium: -30V.

3. **Shockley Diode Equation:**
   \[
   I = I_s (e^{V/V_t} - 1)
   \]
   Where:
   - \(I\): Diode current
   - \(I_s\): Reverse saturation current
   - \(V\): Voltage across the diode
   - \(V_t = \frac{kT}{q}\): Thermal voltage (dependent on temperature)

## Future Improvements
- Add graphical visualization of voltage-current characteristics.
- Extend simulation to include temperature dependence.
- Simulate Zener diodes or other types of special-purpose diodes.
- Provide a real-time user interface for simulations.

## Author
**Rajat Uniyal**  
GitHub: [Rajat-Kishore](https://github.com/Rajat-Kishore)  
I am a BTech student from the Computer Science and Engineering (CSE) department, passionate about coding, electronics, and bridging the gap between theory and practice.
