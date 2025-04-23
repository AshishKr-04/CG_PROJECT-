# CG_PROJECT-
# 🌌 Solar System Simulation in C++

This is a simple animated simulation of the Solar System written in **C++** using the classic **Turbo C++ graphics library** (`graphics.h`). It displays 8 planets orbiting around the sun with zoom functionality.

---

## 🚀 Features

- Simulates 8 orbiting planets
- Tilted elliptical orbits for 3D-like effect
- Smooth circular motion using trigonometry
- Zoom in and out (`+` and `-` keys)
- Exit with `ESC` key
  
---

## 🧱 Requirements

- **Turbo C++** or any DOSBox setup that supports `graphics.h`
- A proper path to the BGI directory (typically: `C:\\TURBOC3\\BGI`)
- Windows OS (for legacy compatibility with graphics.h)

---

## 📦 File Structure

- `main.cpp`: The source code for the solar system animation
- `README.md`: Project documentation

---

## 🛠️ How to Compile & Run

1. Open the Turbo C++ IDE or a DOSBox environment.
2. Paste the code into `main.cpp` or `solar.cpp`.
3. Ensure you have the correct BGI path in `initgraph()`:
   ```cpp
   initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
