#ifndef ___FIRSTMODE_H___
#define  ___FIRSTMODE_H___

int FirstFunctionMode();
double FirstElementFunPointer(double x, double(*foo)(double));
double FirstElemSin(double x);
double FirstElemSh(double x);
double FirstElemCh(double x);
double FirstElemCos(double x);
double FirstElemExp(double x);
double FirstElemCoth(double x);
double EtalonFunPointer(double x, double(*foo)(double));
double EtalonSin(double x);
double EtalonCh(double x);
double EtalonSh(double x);
double EtalonCos(double x);
double EtalonExp(double x);
double EtalonCoth(double x);
double CalculateExp(double eta, double* temp, double x, double accu, int* i, int count);
double MnozhitelFunctionExp(double x, long i);
double CalculateSh(double eta, double* temp, double x, double accu, int* i, int count);
double MnozhitelFunctionSh(double x, long i);
double CalculateSin(double eta, double* temp, double x, double accu, int* i, int count);
double MnozhitelFunctionSin(double x, long i);
double CalculateCos(double eta, double* temp, double x, double accu, int* i, int count);
double MnozhitelFunctionCos(double x, long i);
double CalculateCh(double eta, double* temp, double x, double accu, int* i, int count);
double MnozhitelFunctionCh(double x, long i);
double Bink(int n, int k);
double Bernulli(int n);
double CalculateCoth(double eta, double* temp, double x, double accu, int* i, int count);

#endif 