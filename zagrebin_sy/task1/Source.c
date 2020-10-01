/*накладна€ задн€€ стенка из ƒ¬ѕ высотой h от 180 до 220 см, шириной w от 80 до 120 см и толщиной 5 мм,
две боковины из ƒ—ѕ высотой h, глубиной d от 50 до 90 см и толщиной 15 мм,
накладные верхн€€ и нижн€€ крышки из ƒ—ѕ шириной w, глубиной d и толщиной 15 мм,
две накладные двери из дерева высотой h, общей шириной w и толщиной 1 см,
внутренние полки в шкафу через каждый 40 см из ƒ—ѕ.*/

#include <stdio.h>

void main() {

    double h, w, d, back, sides, caps, doors, shelf, dvp = 0.8, dsp = 0.65, c, m;

    do {
        printf("Enter Height 180-220, Width 80-120, Depth 50-90 \n");
        scanf_s("%lf %lf %lf", &h, &w, &d);
    } while (h < 180 || h>220 || w < 80 || w>120 || d < 50 || d>90);

    back = h * w * 0.5;
    sides = 2 * h * d * 1.5;
    caps = 2 * w * d * 1.5;
    doors = 2 * h * w * 1;
    shelf = d * (w - 2 * 1.5);

    c = (int)h / 40;

    m = back * dvp + sides * dsp + caps * dsp + doors * 0.85 + c * shelf * dsp;

    printf("%lf kg\n", m/1000);
    scanf_s("%lf", &c);
}