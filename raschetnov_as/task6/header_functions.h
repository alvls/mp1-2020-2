#ifndef HEADER_FUNCTIONS
#define HEADER_FUNCTIONS
void printOutputMode1(double sum, double i, double reference);
void printOutputMode2(double sum, double i, double reference, int princounter);
void modeChoicer(int* modechoice, int* choice);
void modeChoicerInputControl(int* modechoice);
void menuChoicer(int* choice);
void menuChoicerInputControl(int* choice);
void numberCheckerNoRestrictions(double* number);
void amountCheckerNoRestrictions1(int* amount);
void amountCheckerNoRestrictions2(int* amount);
void infelicityCheckerNoRestrictions(double* infelicity);
void numberCheckerAbsLessThenOneOrSame(double* number);
void exponent(double* number, int* amount, double* infelicity, int* modechoice);
void sine(double* number, int* amount, double* infelicity, int* modechoice);
void cosine(double* number, int* amount, double* infelicity, int* modechoice);
void squareRoot(double* number, int* amount, double* infelicity, int* modechoice);
void arctg(double* number, int* amount, double* infelicity, int* modechoice);
#endif 