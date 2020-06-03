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
	double aa[2];
	double bb[2];
	//cout << "Please your START and END POINT"<<endl;
	//cin >> aa[0]>> aa[1]>> bb[0]>> bb[1];

	double temp[2] = {50,70};
	double temp2[2] = { 70,70 };
	//		点   长度 高度Z 喷嘴 道数 E1比例
	tiaoWen(temp, 100, 0.2, 0.3,  10,   1);
	tiaoWen(temp, 90, 0.2, 0.4, 10, 1);
	tiaoWen2(temp2, 100, 0.2, 0.4, 10, 1);
	



	//最后加上去两句，不然切片软件显示都是黑色的线，软件时simplify3d
	ofstream myGcodefile(myFile, ios_base::app);
	myGcodefile << "G0 F1000 X249.2 Y249.2"<<endl<<"G0 F9000 X249.6 Y249.6";

	printWireframe(aa,bb);
}