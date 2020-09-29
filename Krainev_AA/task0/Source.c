#include <stdio.h>
#include <math.h>

int main() {
    int x1, y1, x2, y2, r1, r2; // где (x1,y1) (x2,y2)координаты центра первой и второй  окружностей соотвественно, r1/r2 их радиусы
    float d;
    //найдем расстояние между центрами окружности
    printf_s("Enter data into the console x1, y1, x2, y2 \n");
    scanf_s("%d %d %d %d", &x1, &y1, &x2, &y2);
    printf_s("Enter data into the console r1, r2 \n");
    scanf_s("%d %d", &r1, &r2);
    d = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    //сначала рассмотрим случай когда окружности совпадают, т.е. имеют одинаковые координаты центров и раудиусы
    if (x1 == x2 && y1 == y2 & r1 == r2) {
        printf("The circles match\n"); //окружности совпадают
    }
    //рассмотрим случай когда окружности не имеют общих точек (лежат вне друг друга), то есть сумма их радиусов меньше отрезка, соединяющего центры.

    else if (d > r1 + r2) {
        printf("Zero points, vne\n");
    }
    // рассмотрим случай когда одна лежит внутри другой, но не имеют общих точек
    else if ((d < r1 - r2) || (d < r2 - r1))
        printf("zero points, vnutri\n");

    // рассмотрим случай когда одна окружность лежит внутри другой и имеет внутренюю точку касания
    else if ((d == r1 - r2) || (d == r2 - r1)) {

        printf("vnutri, 1 point\n");
    }
    //пересекаются
    else if ((r1 - r2<d && d > r1 + r2) || (r2 - r1<d && d > r2 + r1))
        printf("2 point\n");

    // внешнее касание
    else if (d == r1 + r2)
        printf("vne, 1 point\n");
  getchar();
  getchar();
}
