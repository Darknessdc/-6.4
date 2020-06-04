#pragma once

//�ֱ��� ����ֱ����������������������������ߣ�������
extern double N;
extern int M;
extern double H1;
extern double H2;
extern const double E;
extern  double sumOfE;
extern const char* myFile;

bool initPrinter();
bool printWireframe(const double PointA[2],double a,double b,double c);

//��ӡ��һ��������Ҫ��ʼ�㣬���ȣ��߶�Z������ֱ��N������M��������E E��������Z�й�
bool tiaoWen(double PointA[2], int length, double Z, double N, int M, double E1);
//��ӡ��������Ҫ��㣬���ȣ��߶�Z������ֱ��N������M��������E
bool tiaoWen2(double PointA[2], int length, double Z, double N, int M, double E1);
//��ӡ��������      ���               �͵ĳ���            �ߵĳ���      �͵Ĳ��     �ߵĲ��    ������Ŀ         ��������
bool waves(double PointA[2], double lengthOflow, double lengthOfhigh, double Z1, double Z2, int numberOfwaves, int M, double N, double E1);
//���˺���
bool waves2(double PointA[2], double lengthOflow, double lengthOfhigh, double Z1, double Z2, int numberOfwaves, int M, double N, double E1);
//�ñ�֯������ⳤ��ߵ�������
void cube(double PointA[2], double a,double b, double c, int M, double N);