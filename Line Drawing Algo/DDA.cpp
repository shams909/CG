#include <bits/stdc++.h>
using namespace std;

void plot(int x, int y) {
    cout << "(" << x << ", " << y << ")\n";
}

void ddaLine(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = max(abs(dx), abs(dy));

    if (steps == 0) {
        plot(x1, y1);
        return;
    }

    float xInc = (float)dx / steps;
    float yInc = (float)dy / steps;

    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++) {
        plot(round(x), round(y));
        x += xInc;
        y += yInc;
    }
}

int main() {
    ddaLine(2, 3, 8, 6);
    return 0;
}