#include<iostream>
using namespace std;
//Intercambiando 2 variables

int main()
{	int a,b;
	cout<<"ing val de a: ";
	cin>>a;
	cout<<"ing val de b: ";
	cin>>b;
	a=a+b;
	b=a-b;
	a=a-b;
	cout<<"nuevo val de a: ";
	cout<<a<<endl;
	cout<<"nuevo val de b: ";
	cout<<b;
	return 0;
}
