#pragma once

//分别是 喷嘴直径，单横竖纹来回数量，两个层高，挤出机
extern double N;
extern int M;
extern double H1;
extern double H2;
extern const double E;
extern  double sumOfE;
extern const char* myFile;

bool initPrinter();
bool printWireframe(double Pointa[2],double Pointb[2]);

//打印单一竖条纹需要起始点，长度，高度Z，喷嘴直径N，数量M，挤出机E E还可能与Z有关
bool tiaoWen(double PointA[2], int length, double Z, double N, int M, double E1);
//打印横条纹需要起点，长度，高度Z，喷嘴直径N，数量M，挤出机E
bool tiaoWen2(double PointA[2], int length, double Z, double N, int M, double E1);
//打印波浪竖纹      起点               低的长度            高的长度      低的层高     高的层高    波浪数目         几道波浪
bool waves(double PointA[2], double lengthOflow, double lengthOfhigh, double Z1, double Z2, int numberOfwaves, int M, double N, double E1);
//波浪横纹
bool waves2(double PointA[2], double lengthOflow, double lengthOfhigh, double Z1, double Z2, int numberOfwaves, int M, double N, double E1);
