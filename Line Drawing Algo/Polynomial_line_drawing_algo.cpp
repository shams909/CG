
#include <bits/stdc++.h>
using namespace std;

void plot(int x, int y) {
    cout << "(" << x << ", " << y << ")\n";
}

void polynomialLine(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    // Handle vertical lines
    if (dx == 0) {
        int startY = min(y1, y2);
        int endY = max(y1, y2);

        for (int y = startY; y <= endY; y++)
            plot(x1, y);

        return;
    }

    float m = (float)dy / dx;
    float c = y1 - m * x1;

    // Shallow slope: |m| <= 1
    if (abs(m) <= 1) {
        int startX = min(x1, x2);
        int endX = max(x1, x2);

        for (int x = startX; x <= endX; x++)
            plot(x, round(m * x + c));
    }
    // Steep slope: |m| > 1
    else {
        int startY = min(y1, y2);
        int endY = max(y1, y2);

        for (int y = startY; y <= endY; y++)
            plot(round((y - c) / m), y);
    }
}

int main() {
    int x1, y1, x2, y2;

    cout << "Enter x1 y1 x2 y2: ";
    cin >> x1 >> y1 >> x2 >> y2;

    polynomialLine(x1, y1, x2, y2);

    return 0;
}
