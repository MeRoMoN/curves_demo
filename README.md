# Curves Demo

## Overview
This project implements a hierarchy of 3D curves in modern C++17.  
Supported curve types:
- **Circle** – defined by radius (planar in the XOY plane, optional Z offset).
- **Ellipse** – defined by two radii (along X and Y axes, optional Z offset).
- **Helix** – defined by radius and step. One full turn (Δt = 2π) increases Z by `step`.

Each curve exposes:
- `point(t)` → returns a 3D coordinate at parameter `t`
- `derivative(t)` → returns the first derivative (tangent vector) at `t`

---

## Features
1. Populates a container with randomly created curves and parameters.
2. Prints coordinates and derivatives of all curves at **t = π/4**.
3. Collects only circles into a second container (using shared pointers, no cloning).
4. Sorts the circles by radius (ascending).
5. Computes the total sum of all radii in the circle container.  
   - Uses parallel reduction if `<execution>` is available (C++17).

Additional requirements:
- Implementation is split into a shared library (`curves`) and an executable (`curves_app`) that uses its API.
- STL containers and algorithms are used throughout.
- No manual memory management (`shared_ptr` used).
- Parameters are validated (e.g. radii > 0).

---

## Build & Run

### Windows (Visual Studio 2022)
```powershell
mkdir build
cd build
cmake -G "Visual Studio 17 2022" -A x64 ..
cmake --build . --config Release
.\Release\curves_app.exe
