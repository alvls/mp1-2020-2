#include <stdio.h>
#include <math.h>

int main() {
    int x1, y1, x2, y2, r1, r2; // ��� (x1,y1) (x2,y2)���������� ������ ������ � ������  ����������� �������������, r1/r2 �� �������
    float d;
    //������ ���������� ����� �������� ����������
    printf_s("Enter data into the console x1, y1, x2, y2 \n");
    scanf_s("%d %d %d %d", &x1, &y1, &x2, &y2);
    printf_s("Enter data into the console r1, r2 \n");
    scanf_s("%d %d", &r1, &r2);
    d = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    //������� ���������� ������ ����� ���������� ���������, �.�. ����� ���������� ���������� ������� � ��������
    if (x1 == x2 && y1 == y2 & r1 == r2) {
        printf("The circles match\n"); //���������� ���������
    }
    //���������� ������ ����� ���������� �� ����� ����� ����� (����� ��� ���� �����), �� ���� ����� �� �������� ������ �������, ������������ ������.

    else if (d > r1 + r2) {
        printf("Zero points, vne\n");
    }
    // ���������� ������ ����� ���� ����� ������ ������, �� �� ����� ����� �����
    else if ((d < r1 - r2) || (d < r2 - r1))
        printf("zero points, vnutri\n");

    // ���������� ������ ����� ���� ���������� ����� ������ ������ � ����� ��������� ����� �������
    else if ((d == r1 - r2) || (d == r2 - r1)) {

        printf("vnutri, 1 point\n");
    }
    //������������
    else if ((r1 - r2<d && d > r1 + r2) || (r2 - r1<d && d > r2 + r1))
        printf("2 point\n");

    // ������� �������
    else if (d == r1 + r2)
        printf("vne, 1 point\n");
  getchar();
  getchar();
}
