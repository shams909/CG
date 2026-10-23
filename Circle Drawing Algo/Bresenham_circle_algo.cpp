
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

void bresenhamCircle(int xc, int yc, int r) {
    int x = 0;
    int y = r;
    int d = 3 - 2 * r;

    while (x <= y) {
        plotCirclePoints(xc, yc, x, y);

        if (d < 0) {
            d = d + 4 * x + 6;
        } else {
            d = d + 4 * (x - y) + 10;
            y--;
        }

        x++;
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

    bresenhamCircle(xc, yc, r);

    return 0;
}
