#ifndef __CALCULATING_H__
#define __CALCULATING_H__
typedef double db;
db polinom(db acc, int count, db x, db(*etalon)(db));
int proverka(db acc, db x, db Teilor, db(*etalon)(db));
#endif
