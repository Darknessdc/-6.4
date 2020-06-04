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
double H1 = 0.1;
double H2 = 0.2;
extern const double E = 0.038;
extern const char* myFile = "myGocde.gcode";

int main()
{
	initPrinter();

	//test
	double temp[2] = {50,70};
	double temp2[2] = { 100,100 };
	double temp3[2] = { 190,100 };

	cube(temp2,40,20,8,3,0.4);

	//最后加上去两句，不然切片软件显示都是黑色的线，软件时simplify3d
	ofstream myGcodefile(myFile, ios_base::app);
	myGcodefile << "G0 F1000 X249.2 Y249.2"<<endl<<"G0 F9000 X249.6 Y249.6";

	
}