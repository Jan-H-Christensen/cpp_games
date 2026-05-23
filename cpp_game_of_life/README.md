# Raylib Game of Life

An interactive "Conway's Game of Life" implementation written in C++ using the [raylib](https://www.raylib.com/) graphics library.

## ✨ Features

* **Toroidal Field (World Globe Effect):** Cells seamlessly cross the screen boundaries, wrapping around to the opposite side (Pac-Man effect).
* **Pause Functionality:** Freeze the evolution at any time using the `Spacebar` to analyze the current generation.
* **Interactive Sandbox (Mouse Controls):** * `Hold Left-Click`: Draw and bring new cells to life directly on the grid.
  * `Hold Right-Click`: Erase cells and set them back to dead.
* **Optimized Simulation Speed:** The game renders smoothly at 60 FPS while the cellular evolution runs at a controlled, comfortable pace (e.g., 10 generations per second).

## 🛠️ Prerequisites

The project is configured for Linux systems and requires:
* An installed C++ compiler (`clang++` or `g++`)
* The `raylib` library installed on your system
* `make` for the build process

*Note: Paths within the Makefile and `compile_flags.txt` are currently set to the `/home/j_c/...` directory.*

## 🚀 Getting Started

1. **Compile the Project:**
   Build the executable program using the Makefile:
   ```bash
   make
