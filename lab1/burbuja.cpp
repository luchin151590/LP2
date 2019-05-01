    
#include<iostream>
using namespace std;
void burbuja(int a[],int n);
int main()
{	int ta=4;
	int a[ta]={2,1,1,0};
	burbuja(a,ta);
	for(int i=0;i<ta;i++)
	{
		cout<<a[i]<<" ";
	}
 	return 0;
}
void burbuja(int a[],int n)
{int aux;
	for(int i=0;i<(n-1);i++)
	{
		for(int j=0;j<n-1;j++)
		{if(a[j]>a[j+1])
			{
				aux=a[j];
				a[j]=a[j+1];
				a[j+1]=aux;
			}
		}
 }
}
