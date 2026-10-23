
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

void polynomialCircle(int xc, int yc, int r) {
    for (int x = 0; x <= r; x++) {
        float value = (float)r * r - (float)x * x;
        int y = round(sqrt(max(0.0f, value)));

        plotCirclePoints(xc, yc, x, y);
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

    polynomialCircle(xc, yc, r);

    return 0;
}
