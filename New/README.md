# Computer Graphics Lab — C++ FreeGLUT

This package follows the uploaded **List of CG experiments (Computer Graphics Lab)**.

## Included programs
1. Polynomial line algorithm
2. DDA line algorithm
3. Bresenham line algorithm
4. Midpoint circle algorithm
5. Polynomial circle algorithm
6. Trigonometric circle algorithm
7. Bresenham circle algorithm
8. Ellipse: polynomial and trigonometric algorithms
9. Arc and sector
10. Bitmap and outline text
11. Rotate line, triangle and rectangle about a point
12. Magnify (scale) circle, triangle and rectangle about a point
13. Rotate a 3D cube using OpenGL
14. Projection of a 3D cube (orthographic and perspective)
15. Line and polygon clipping (Cohen–Sutherland and Sutherland–Hodgman)
16. Drawing objects and animation
17. Small OpenGL project demo

Each `.cpp` file is a separate program and has its own `main()`. Compile one file at a time.

## Windows / MinGW compile
Install MinGW-w64 and FreeGLUT, configure the include/library paths, then:
```bash
g++ 01_polynomial_line.cpp -o run.exe -lfreeglut -lopengl32 -lglu32
```
Replace the source filename for each experiment. Run `run.exe`.

For a typical MSYS2 MinGW 64-bit shell, install FreeGLUT:
```bash
pacman -S mingw-w64-x86_64-freeglut
```

## Notes
- Programs use legacy OpenGL immediate mode (`glBegin`, `glEnd`) because it is commonly used in introductory graphics labs.
- `gluOrtho2D` sets a 2D coordinate system with origin at bottom-left.
- Some algorithms use floating-point math for clarity; the Bresenham programs use integer decision variables.
- The text experiment demonstrates both GLUT bitmap fonts and GLUT stroke/outline fonts.
