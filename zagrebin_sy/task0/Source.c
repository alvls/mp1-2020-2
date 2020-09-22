#include <stdio.h>

void main() {

    double x1, x2, y1, y2, r1, r2, d;

    printf("Enter  x1, x2, y1, y2 \n");
    scanf_s("%lf %lf %lf %lf", &x1, &x2, &y1, &y2);
     do{
        printf("Enter  r1, r2 \n");
        scanf_s("%lf %lf", &r1, &r2);
     } while ((r1<=0)&&(r2<=0));

    if ((x1 == x2)&&(y1 == y2)) {
        if (r1 == r2) {
            printf("They are the same \n");
            scanf_s("%lf", &d);
            return;
        }
        else {
            printf("One in other \n");
            scanf_s("%lf", &d);
            return;
        }
    }

    d = (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);

    if (d > (r1 + r2)*(r1 + r2)) {
        printf("Too far.. \n");
    }
    else {
        if (d == (r1 + r2)*(r1 + r2)) {
            printf("Touched \n");
        }
        else {
            printf("Crossed \n");
        }
    }
    scanf_s("%lf", &d);
}
