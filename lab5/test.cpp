#include<fstream>
#include<iostream>
#include "mystring.h"
#include "mystring.cpp"
using namespace std;
int main ()
{
	std::string str = "hola";
	std::string a, b, c;
	a= str + str;
	b = a;
	c = a+b;
	c = " ";
	cout<< b[3]<<endl;
	cout<<a;
	a[1] = 'H';
	cout<<a[1];
	if(a==b)
	cout<<"son iguales"<<endl;
	if(a>c)
	cout<<" es mayor a que c";
}
