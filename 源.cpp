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

int main()
{
	initPrinter();
	double aa[2];
	double bb[2];
	//cout << "Please your START and END POINT"<<endl;
	//cin >> aa[0]>> aa[1]>> bb[0]>> bb[1];

	double temp[2] = {50,20};
	tiaoWen(temp,100,0.2,0.4,5,1);
	printWireframe(aa,bb);
}