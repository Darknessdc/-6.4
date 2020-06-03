#include"initGcode.h"
#include<fstream>

using namespace std;

const char* myFile = "myGocde.gcode";

bool initPrinter()
{

	ofstream myGcodefile(myFile);
	if (!myGcodefile) return false;

	myGcodefile << "G28" << endl;
	myGcodefile << "M104 S195" << endl;
	myGcodefile << "M140 S40" << endl;
	myGcodefile << "M190 S40" << endl;
	myGcodefile << "M109 S195" << endl;

	return true;
}
//A点是左下角 length是长度 N是喷嘴直径一般0.4mm M是数量 E1挤出机比例系数的微调，可能与Z有关
bool tiaoWen(double PointA[2],int length,double Z,double N, int M, double E1)
{
	ofstream myGcodefile(myFile,ios_base::app);
	if (!myGcodefile) return false;
	myGcodefile << "G0 F5000 " <<" Z" << Z << endl;

	double tempPoint[2] = { PointA[0],PointA[1] };
	for (int i = 0; i < M; i++)
	{ 
		myGcodefile << "G1 X" << tempPoint[0]+N*i << " Y" << tempPoint[1] << endl;
		sumOfE += E1*E*length;
		myGcodefile << "G1 X" << tempPoint[0]+N*i << " Y" << tempPoint[1] + length << " E" << sumOfE << endl;
		myGcodefile << "G1 X" << tempPoint[0]+N*(i+1) << " Y" << tempPoint[1] + length << " E" << sumOfE << endl;
		sumOfE += E1*E*length;
		myGcodefile << "G1 X" << tempPoint[0]+N*(i+1) << " Y"<< tempPoint[1] << " E" << sumOfE << endl;
	}
	return true;
}

bool printWireframe(double PointA[2], double PointB[2])
{

	return true;
}