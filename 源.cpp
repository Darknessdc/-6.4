/*1.���Ƶ�ʵ��N*M				
  2.��㣬�յ�
  3.���H1��H2����ż����
  4.����������
  4.�����׶���ʵ�� 
  5.��������İ�͹��
  6.��ǵĴ�ӡ*/

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
	double temp2[2] = { 100,100 };
	double temp3[2] = { 190,100 };

	//		��   ���� �߶�Z ���� ���� E1����
	//tiaoWen(temp, 90, 0.2, 0.4, 3, 1);
	//tiaoWen2(temp2, 100, 0.2, 0.4, 3, 1);
	//     ���  �͵ĳ���  �ߵĳ��� �͵Ĳ�� �ߵĲ�� ������Ŀ �������� ����ֱ��
	//waves(temp2,5,8,0.1,0.3,5,5,0.4,1);

	//waves2(temp3, 8, 8, 0.1, 0.3, 5, 5, 0.4, 1);
	//��㣬����ߣ����������*2������
	cube(temp2,100,40,8,3,0.4);

	//������ȥ���䣬��Ȼ��Ƭ�����ʾ���Ǻ�ɫ���ߣ����ʱsimplify3d
	ofstream myGcodefile(myFile, ios_base::app);
	myGcodefile << "G0 F1000 X249.2 Y249.2"<<endl<<"G0 F9000 X249.6 Y249.6";

	//printWireframe(aa,bb);
}