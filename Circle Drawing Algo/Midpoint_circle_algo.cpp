
#include <bits/stdc++.h>
using namespace std;

void plot(int x, int y) {
    cout << "(" << x << ", " << y << ")\n";
}

void plotCirclePoints(int xc, int yc, int x, int y) {
    plot(xc + x, yc + y);
    plot(xc - x, yc + y);
    plot(xc + x, yc - y);
    plot(xc - x, yc - y);
    plot(xc + y, yc + x);
    plot(xc - y, yc + x);
    plot(xc + y, yc - x);
    plot(xc - y, yc - x);
}

void midpointCircle(int xc, int yc, int r) {
    int x = 0;
    int y = r;
    int p = 1 - r;

    while (x <= y) {
        plotCirclePoints(xc, yc, x, y);

        x++;

        if (p < 0) {
            p += 2 * x + 1;
        } else {
            y--;
            p += 2 * (x - y) + 1;
        }
    }
}

int main() {
    int xc, yc, r;

    cout << "Enter center (xc, yc) and radius: ";
    cin >> xc >> yc >> r;

    if (r < 0) {
        cout << "Radius must be non-negative.\n";
        return 1;
    }

    midpointCircle(xc, yc, r);

    return 0;
}
