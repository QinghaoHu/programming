#include <bits/stdc++.h>

int main() {
    int x, y; scanf("%d%d", &x, &y);
    long double sum = 0;
    double x1, y1, x2, y2;

    while (std::cin >> x1 >> y1 >> x2 >> y2, x1 || y1 || x2 || y2) {
        int diffx = x2 - x1, diffy = y2 - y1;
        sum += 2 * sqrt(diffx * diffx + diffy * diffy);
    }

    int minutes = round(sum / 1000 / 20 * 60);
    int hours = minutes / 60;
    minutes %= 60;

    printf("%d:%02d\n", hours, minutes);

    return 0;
}
