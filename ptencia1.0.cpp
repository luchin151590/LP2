#include<iostream>
using namespace std;
//Potenciacion con menor intento de multiplicaciones
double pot(double,int);

int main()
{	double base;
	int expo;
	cout<<"ingrese la base b:";
	cin>>base;
	cout<<"ing el exponente: ";
	cin>>expo;
	cout<<pot(base,expo);
	return 0;
}
double pot(double b,int e)
{	double d=1;
	if(e!=0)
	{	for(int i=0;i<e;i++)
		{	
			d=d*b; 
		}
	}
	else
	{	return d;
	}
	return d;
}
