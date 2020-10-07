/*��������� ������ ������ �� ��� ������� h �� 180 �� 220 ��, ������� w �� 80 �� 120 �� � �������� 5 ��,
��� �������� �� ��� ������� h, �������� d �� 50 �� 90 �� � �������� 15 ��,
��������� ������� � ������ ������ �� ��� ������� w, �������� d � �������� 15 ��,
��� ��������� ����� �� ������ ������� h, ����� ������� w � �������� 1 ��,
���������� ����� � ����� ����� ������ 40 �� �� ���.*/

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