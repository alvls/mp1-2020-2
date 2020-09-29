#include <stdio.h>

void main() {

    double x1, x2, y1, y2, r1, r2, d, sum, dif;

    printf("Enter  x1, x2, y1, y2 \n");
    scanf_s("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
    do {
        printf("Enter  r1, r2 \n");
        scanf_s("%lf %lf", &r1, &r2);
    } while ((r1 <= 0) && (r2 <= 0));

    d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    sum = (r1 + r2) * (r1 + r2);
    dif = (r1 - r2) * (r1 - r2);

        if (d > sum) {
            printf("Too far.. \n");
            scanf_s("%lf", x1);
        }
        else {
            if (d == sum) {
                printf("External touch \n");
                scanf_s("%lf", x1);
            }
            else {
                if (d == dif) {
                    if ((x1 == x2) && (y1 == y2)) {
                        printf("They are the same \n");
                        scanf_s("%lf", x1);
                    }
                    else {
                        printf("Inner touch \n");
                        scanf_s("%lf", x1);
                    }
                }
                else {
                    if (d < dif) {
                        printf("One in other \n");
                        scanf_s("%lf", x1);
                    }
                    else {
                        printf("Crossed \n");
                        scanf_s("%lf", x1);
                    }
                }
            }
        }
}
