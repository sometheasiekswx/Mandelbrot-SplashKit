# Mandelbrot-SplashKit

Made by [Somethea Siek](https://github.com/sometheasiekswx), an Aspiring Developer.

## Screenshot

![Preview of Mandelbrot-SplashKit](https://github.com/sometheasiekswx/Mandelbrot-SplashKit/blob/master/mandelbrot.jpg "Preview of Mandelbrot-SplashKit")

## Description

This is a C++ program that simulates the Mandelbrot Set using the SplashKit library. 

## Features

- Zoom In & Out: Right click to Zoom In and Left Click to Zoom Out.
- Change Colors: edit the "iteration_color" function in "mandelbrot.cpp". 
- Change Screen Size: Go to "main" and change "open_window" in "program.cpp". 
- Adjust Detail: change "MAX_INTERATION" in "mandelbrot.h".

## To Compile & Run:
### Linux/Mac: 
- Open terminal 
- Make sure Splashkit is installed by running the command "skm" 
    - If not yet installed, go to https://www.splashkit.io/articles/installation/
- Go to the directory with the source code 
- Enter "skm clang++ *.cpp  -o [program_name]" to Compile
- Enter "./[program_name]" to run

### Windows: 
- Make sure a terminal emulator like MSYS2 is installed 
    - If not yet installed, go to https://www.msys2.org/
- Open terminal (MSYS2)
- Make sure Splashkit is installed by running the command "skm"
    - If not yet installed, go to https://www.splashkit.io/articles/installation/
- Go to the directory with the source code 
- Enter "skm clang++ *.cpp  -o [program_name]" to Compile
- Enter "./[program_name]" to run
