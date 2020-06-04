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
//A�������½� length�ǳ��� N������ֱ��һ��0.4mm M������,��ʵ��С��������M*2 E1����������ϵ����΢����������Z�й�
bool tiaoWen(double PointA[2],int length,double Z,double N, int M, double E1)
{
	ofstream myGcodefile(myFile,ios_base::app);
	if (!myGcodefile) return false;
	myGcodefile << "G0 F5000 " <<" Z" << Z << endl;

	double tempPoint[2] = { PointA[0],PointA[1] };
	double tempX = tempPoint[0];
	for (int i = 0; i < M; i++)
	{ 
		
		myGcodefile << "G1 X" << tempX << " Y" << tempPoint[1] << endl;
		sumOfE += E1*E*length;
		myGcodefile << "G1 X" << tempX << " Y" << tempPoint[1] + length << " E" << sumOfE << endl;
		tempX += N ;
		myGcodefile << "G1 X" << tempX << " Y" << tempPoint[1] + length << " E" << sumOfE << endl;
		sumOfE += E1*E*length;
		myGcodefile << "G1 X" << tempX << " Y"<< tempPoint[1] << " E" << sumOfE << endl;
		tempX += N ;
		myGcodefile << "G1 X" << tempX << " Y" << tempPoint[1] << " E" << sumOfE << endl;

	}
	return true;
}

bool tiaoWen2(double PointA[2], int length, double Z, double N, int M, double E1)
{
	ofstream myGcodefile(myFile, ios_base::app);
	if (!myGcodefile) return false;
	myGcodefile << "G0 F5000 " << " Z" << Z << endl;

	double tempPoint[2] = { PointA[0],PointA[1] };
	double tempY = tempPoint[1];
	for (int i = 0; i < M; i++)
	{
		myGcodefile << "G1 X" << tempPoint[0]  << " Y" << tempY << endl;
		sumOfE += E1 * E*length;
		myGcodefile << "G1 X" << tempPoint[0] + length << " Y" << tempY << " E" << sumOfE << endl;
		tempY += N;
		myGcodefile << "G1 X" << tempPoint[0] + length  << " Y" << tempY << " E" << sumOfE << endl;
		sumOfE += E1 * E*length;
		myGcodefile << "G1 X" << tempPoint[0]  << " Y" << tempY << " E" << sumOfE << endl;
		tempY += N;
		myGcodefile << "G1 X" << tempPoint[0] << " Y" << tempY << " E" << sumOfE << endl;
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
//��㣬�����abc��С��������M*2������N
void cube(double PointA[2], double a, double b, double c,int M, double N)
{
	double tempPoint[2] = { PointA[0],PointA[1] };
	double width = M * N * 2;
	//������������
	int numOftiaowen = a / width / 2;
	double tempZ = H1;

	//��һ����Ϊ�գ��ο����ģ����ǵڶ����ƣ�����ż����,��һ��
	printWireframe(tempPoint, a, b, tempZ);
	for (int i = 0; i < numOftiaowen; i++)
	{
		//���+NΪ���õ�һ���ͱ߿�ľ������
		double startPointx = tempPoint[0] + width * ((i * 2) + 1) + N;
		double startPointy = tempPoint[1];
		double startPoint[2] = { startPointx ,startPointy };

		tiaoWen(startPoint, b, tempZ, N, M, 1);
	}

	//�ڶ���
	//�����������
	int numOftiaowen2 = b / width / 2;
	printWireframe(tempPoint, a, b, tempZ+ H1);
	for (int i = 0; i < numOftiaowen2; i++)
	{
		double startPointx = tempPoint[0] ;
		double startPointy = tempPoint[1] + width * ((i * 2) + 1) + N;
		double startPoint[2] = { startPointx ,startPointy };
		//+N -N ����΢��
		waves2(startPoint, width+N, width-N, tempZ, tempZ+ H1, numOftiaowen,M * 2,N,1);
	}

	//������
	printWireframe(tempPoint, a, b, tempZ + H1*2);
	for (int i = 0; i < numOftiaowen; i++)
	{
		double startPointx = tempPoint[0] + width * (i * 2) + N;
		double startPointy = tempPoint[1];
		double startPoint[2] = { startPointx ,startPointy };
		waves(startPoint, width + N, width - N, tempZ, tempZ + H1, numOftiaowen2, M * 2, N, 1);
	}


		
}

bool printWireframe(const double PointA[2], double a, double b, double Z)
{
	ofstream myGcodefile(myFile, ios_base::app);
	if (!myGcodefile) return false;

	double tempPoint[2] = { PointA[0],PointA[1] };
	myGcodefile << "G1 F1000 Z" << Z << endl;

	myGcodefile << "G1 X" << tempPoint[0] << " Y" << tempPoint[1] << endl;
	sumOfE += E * a;
	myGcodefile << "G1 X" << tempPoint[0]+a << " Y" << tempPoint[1] <<" E"<< sumOfE << endl;
	sumOfE += E * b;
	myGcodefile << "G1 X" << tempPoint[0] + a << " Y" << tempPoint[1]+b << " E" << sumOfE << endl;
	sumOfE += E * a;
	myGcodefile << "G1 X" << tempPoint[0] << " Y" << tempPoint[1] + b << " E" << sumOfE << endl;
	sumOfE += E * b;
	myGcodefile << "G1 X" << tempPoint[0] << " Y" << tempPoint[1] << " E" << sumOfE << endl;

	return true;
}