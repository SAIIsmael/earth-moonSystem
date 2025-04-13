# Earth-Moon System Simulation

[![C++](https://img.shields.io/badge/C++-17-blue.svg)](https://en.cppreference.com/w/cpp/17)
[![OpenGL](https://img.shields.io/badge/OpenGL-3D--Graphics-green.svg)](https://www.opengl.org/)
[![Build with Make](https://img.shields.io/badge/build-make-informational.svg)](./build/Makefile)
[![Status](https://img.shields.io/badge/status-archived-lightgrey.svg)]()

A real-time 3D simulation of the Moon orbiting the Earth, written in C++ using OpenGL. This project was originally developed as part of a university research initiative, with a focus on applying low-level graphics programming to model orbital motion and basic planetary dynamics.

> **Main Author**: [Ismael Sai](mailto:contact@ismaelsai.com)

---

## Overview

This simulation models the Earth-Moon system with textured 3D rendering, lighting, and a basic camera system. It was built from scratch using OpenGL (fixed-function pipeline), with all geometry, colors, and transformations handled manually.

The objective was to explore:
- 3D transformations and coordinate systems
- Simulating relative motion and rotations
- Loading and mapping textures with bitmaps
- Camera manipulation for user-controlled visualization

---

## Features

- **Real-time rendering** using OpenGL
- **Textured Earth and Moon** using custom bitmap loader
- **Orbit mechanics**: rotation around both own axes and orbital path
- **Interactive camera** (keyboard-controlled movement)
- **Basic lighting** and color shading
- Written entirely in **modern C++ (C++17)**

---

## Getting Started

### Prerequisites

Make sure your system has the following:

- **C++17 compiler**
- **OpenGL**
- **GLUT or freeglut**
- **Make**

### Install Dependencies

**Ubuntu/Debian:**
```bash
sudo apt update
sudo apt install build-essential libgl1-mesa-dev libglu1-mesa-dev freeglut3-dev
```
**macOS (with Homebrew):**
```bash
brew install freeglut glew
```
### Build instructions
```bash
cd build
make
```
>This will compile the source code and create an executable.

### Run the simulation 
```bash
./earth-moon
```

Make sure to launch the executable from a location where the bitmaps/ folder is accessible. It contains required texture images for the planets.

### File structure 
```
earth-moonSystem/
├── src/        # C++ source files
├── inc/        # Header files
├── build/      # Makefile and build target
├── bitmaps/    # Bitmap texture images
├── doc/        # Doxygen-generated documentation
├── annexes/    # Supplementary documents (e.g., diagrams)
├── Doxyfile    # Doxygen config
└── README.md
```

### Documentation 

To generate documentation:
```bash
doxygen Doxyfile
```

The HTML output will be placed in the /doc directory.

### Author

**Ismael Sai**
Software engineer | Graphics & Simulation Enthusiast 

### License 

This project is released under the MIT License.
Feel free to use it for learning or inspiration.

### Acknowledgments

Thanks to my university teammates for their collaboration during the research phase.
Special credit to the OpenGL and GLUT communities for their rich documentation and support.


