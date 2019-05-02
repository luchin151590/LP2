#include<iostream>
//potencia con menor numero de multiplicaciones//
using namespace std;
int main()
{	float b,e,m=1;
	cout<<"ingrese base y exp: ";
	cin>>b>>e;
	if(e==0)
	{
		b=1;
	}
	else
	{
	for(int i=1;i<=e;i++)
		{
	 	m=m*b;	
		}
	}
	cout<<m;
	return 0;
}
