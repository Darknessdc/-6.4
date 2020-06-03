#include"initGcode.h"
#include<fstream>

using namespace std;



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

bool tiaoWen2(double PointA[2], int length, double Z, double N, int M, double E1)
{
	ofstream myGcodefile(myFile, ios_base::app);
	if (!myGcodefile) return false;
	myGcodefile << "G0 F5000 " << " Z" << Z << endl;

	double tempPoint[2] = { PointA[0],PointA[1] };

	for (int i = 0; i < M; i++)
	{
		myGcodefile << "G1 X" << tempPoint[0]  << " Y" << tempPoint[1] + N * i << endl;
		sumOfE += E1 * E*length;
		myGcodefile << "G1 X" << tempPoint[0] + length << " Y" << tempPoint[1] + N * i << " E" << sumOfE << endl;
		myGcodefile << "G1 X" << tempPoint[0] + length  << " Y" << tempPoint[1] + N * (i + 1) << " E" << sumOfE << endl;
		sumOfE += E1 * E*length;
		myGcodefile << "G1 X" << tempPoint[0]  << " Y" << tempPoint[1] + N * (i + 1) << " E" << sumOfE << endl;
	}

	return true;
}

bool waves(double PointA[2], double lengthOflow, double lengthOfhigh, double Z1, double Z2, int numberOfwaves, int M, double N, double E1)
{
	ofstream myGcodefile(myFile, ios_base::app);
	if (!myGcodefile) return false;

	double tempPoint[2] = { PointA[0],PointA[1] };

	for (int j = 0; j < M; j++)
	{
		for (int i = 0; i < numberOfwaves; i++)
		{
			myGcodefile << "G1 X" << tempPoint[0] + N * j  << " Y" << tempPoint[1] + (lengthOflow + lengthOfhigh) * i << " Z" << Z1 << endl;
			sumOfE += E1 * E * lengthOflow * (i + 1);
			myGcodefile << "G1 X" << tempPoint[0] + N * j << " Y" << tempPoint[1] + (lengthOflow + lengthOfhigh) * i + lengthOflow << " E" << sumOfE << endl;

			myGcodefile << "G1 Z" << Z2 << endl;
			sumOfE += E1 * E * lengthOfhigh * (i + 1);
			myGcodefile << "G1 X" << tempPoint[0] + N * j << " Y" << tempPoint[1] + (lengthOflow + lengthOfhigh) * i + lengthOflow + lengthOfhigh << " E" << sumOfE << endl;
			myGcodefile << "G1 Z" << Z1 << endl;
		}
	
	}
	return true;
}

bool waves2(double PointA[2], double lengthOflow, double lengthOfhigh, double Z1, double Z2, int numberOfwaves, int M, double N, double E1)
{
	ofstream myGcodefile(myFile, ios_base::app);
	if (!myGcodefile) return false;

	double tempPoint[2] = { PointA[0],PointA[1] };

	for (int j = 0; j < M; j++)
	{
		for (int i = 0; i < numberOfwaves; i++)
		{
			myGcodefile << "G1 X" << tempPoint[0] + (lengthOflow + lengthOfhigh) * i << " Y" << tempPoint[1] + N * j << " Z" << Z1 << endl;
			sumOfE += E1 * E * lengthOflow * (i + 1);
			myGcodefile << "G1 X" << tempPoint[0] + (lengthOflow + lengthOfhigh) * i + lengthOflow << " Y" << tempPoint[1] + N * j << " E" << sumOfE << endl;

			myGcodefile << "G1 Z" << Z2 << endl;
			sumOfE += E1 * E * lengthOfhigh * (i + 1);
			myGcodefile << "G1 X" << tempPoint[0] + (lengthOflow + lengthOfhigh) * i + lengthOflow + lengthOfhigh << " Y" << tempPoint[1] + N * j << " E" << sumOfE << endl;
			myGcodefile << "G1 Z" << Z1 << endl;
		}

	}
	return true;
}

bool printWireframe(double PointA[2], double PointB[2])
{

	return true;
}