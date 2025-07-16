# Health Check CLI 

A simple terminal-based BMI calculator. Supports Russian and English language input and provides basic health recommendations based on BMI and age.


## ✨ Features

- Input: name, age, height, weight
- Language switch: `ru` / `en`
- BMI calculation with status:
  - Underweight
  - Normal
  - Overweight
  - Obesity
- Custom recommendation for users under 17


## 🛠 Requirements

 - **Compiler**: GCC 9+ or Clang 10+ (or MSVC for Windows)
 - **C++ Standard**: C++17 or later
 - **Build System**: CMake (recommended) or direct compilation


## 🚀 Install & Run

  1. Clone or download this repository

    git clone https://github.com/Zzorro-Kid/Health_Checker_CLI.git
    
  2. Navigate to the project directory

    cd Health_Checker
    
  3. Compile & Run:

    g++ -std=c++17 -o health_checker main.cpp
    ./health_checker