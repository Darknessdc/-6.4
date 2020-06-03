#pragma once

//分别是 喷嘴直径，单横竖纹来回数量，两个层高，挤出机
extern double N;
extern int M;
extern double H1;
extern double H2;
extern const double E;
extern  double sumOfE;

bool initPrinter();
bool printWireframe(double Pointa[2],double Pointb[2]);
//打印单一条纹需要起始点，高度Z，喷嘴直径N，数量M，挤出机E E还可能与Z有关
bool tiaoWen(double PointA[2], int length, double Z, double N, int M, double E1);
