
#include <bits/stdc++.h>
using namespace std;

void plot(int x, int y) {
    cout << "(" << x << ", " << y << ")\n";
}

void trigonometricCircle(int xc, int yc, int r) {
    const float PI = 3.14159265f;

    for (int angle = 0; angle < 360; angle++) {
        float theta = angle * PI / 180.0f;

        int x = round(r * cos(theta));
        int y = round(r * sin(theta));

        plot(xc + x, yc + y);
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

    trigonometricCircle(xc, yc, r);

    return 0;
}
