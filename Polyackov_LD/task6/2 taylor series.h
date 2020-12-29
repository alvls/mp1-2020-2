#ifndef _2_TAYLOR_SERIES_H_
#define _2_TAYLOR_SERIES_H_

double summator(double x, double eps, int n, double etalon, function func, rezhimfunction condition);
int condition_one(double x, int i, int n, double etalon, function func, double sum, double eps);
int condition_two(double x, int i, int n, double etalon, function func, double sum, double eps);

double taylor_sin(int n, double previous, double x);
double taylor_cos(int n, double previous, double x);
double taylor_arcsin(int n, double previous, double x);
double taylor_arccos(int n, double previous, double x);
double taylor_sinh(int n, double previous, double x);
double taylor_cosh(int n, double previous, double x);
double taylor_exp(int n, double previous, double x);

#endif // !TAYLOR_SERIES_H_
