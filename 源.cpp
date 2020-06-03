/*1.条纹的实现N*M				
  2.起点，终点
  3.层高H1，H2，奇偶控制
  4.挤出量控制
  4.遇到孔洞的实现 
  5.生成任意的凹凸形
  6.外壳的打印*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include"initGcode.h"

using namespace std;

double sumOfE = 0.0;
double N = 0.4;
int M = 5;
double H1 = 0.1;
double H2 = 0.2;
extern const double E = 0.038;
extern const char* myFile = "myGocde.gcode";

int main()
{
	initPrinter();

	//test
	double temp[2] = {50,70};
	double temp2[2] = { 70,70 };
	double temp3[2] = { 190,100 };

	//		点   长度 高度Z 喷嘴 道数 E1比例
	tiaoWen(temp, 90, 0.2, 0.4, 10, 1);
	//tiaoWen2(temp2, 100, 0.2, 0.4, 10, 1);
	//     起点  低的长度  高的长度 低的层高 高的层高 波浪数目 几道波浪 喷嘴直径
	waves(temp2,5,8,0.1,0.3,5,5,0.4,1);

	waves2(temp3, 8, 8, 0.1, 0.3, 5, 5, 0.4, 1);



	//最后加上去两句，不然切片软件显示都是黑色的线，软件时simplify3d
	ofstream myGcodefile(myFile, ios_base::app);
	myGcodefile << "G0 F1000 X249.2 Y249.2"<<endl<<"G0 F9000 X249.6 Y249.6";

	printWireframe(aa,bb);
}