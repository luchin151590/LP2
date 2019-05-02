#include<iostream>
using namespace std;
bool lineal(int *,int,int);
bool binary(int *,int,int);
void burbuja(int *,int);
void seleccion(int *,int);
void insertion(int *,int);
int main()
{ int ta=5;
  int a[ta]={1,5,3,0,7};
  int x;
  
  for(int i=0;i<ta;i++)
  {
  	cout<<a[i]<<" ";
  }
  cout<<endl;
  cout<<ta<<endl;
  cout<<"elemento a buscar:";
  cin>>x;
  cout<<"busqda binary"<<endl;
  cout<<binary(a,x,ta);
  cout<<endl;
  cout<<"busqueda lineal"<<endl;
  cout<<lineal(a,x,ta)<<endl;
  cout<<"ordenamiento burble"<<endl;
  burbuja(a,ta);cout<<endl;
  cout<<"ordenamiento por seleccion"<<endl;
  seleccion(a,ta);
  cout<<endl;
  cout<<"ordenamiento por insercion"<<endl;
  insertion(a,ta);
  
	return 0;
}
void insertion(int *a,int n)
{
   int i,j,v;
   for (i = 1; i < n; i++)
   {
        v = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > v)
        {
                  a[j + 1] = a[j];
                  j--;
        }
             
        a[j + 1] = v;
    }   
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
void seleccion(int *a,int n)
{
	int min,aux;
	for(int i=0;i<n;i++)
	{
		min=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
			{	min=j;
			}
		
		}
		aux=a[min];
		a[min]=a[i];
		a[i]=aux;
	}
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}

}
void burbuja(int *a,int n)
{	int aux;
	for(int i=0;i<(n-1);i++)
	{	for(int j=0;j<n-1;j++)
		{if(a[j]>a[j+1])
			{
				aux=a[j];
				a[j]=a[j+1];
				a[j+1]=aux;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
bool lineal(int *a,int x,int ta)
{
	for(int i=0;i<ta-1;i++)
	{
		if(a[i]==x)
		{
			return true;
		}
	}
	return false;
}
bool binary(int *a,int x,int ta)
{	int m=0,i=0,j=ta-1; 
	while(i<=j)
	{
		m=(i+j)/2;
		if(a[m]==x)
		{
			return 1;
		} 
		else if(a[m]<x)
		{
			i=m+1;
		}
		else
		{	j=m-1;
		}
	
	}	return 0;
	
}
