#include<iostream>
#include<algorithm>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<cmath>

using namespace std;

int *TA;
int *TB;

typedef long long my_int;
typedef void(*fun_sort)(int *,int);
bool test_sort(fun_sort sort,const int *A,int n)
{
	memcpy(TA,A,sizeof(int)*n);
	memcpy(TB,A,sizeof(int)*n);
	
	clock_t t=clock();
	sort(TA,n);
	float time=float(clock()-t)/CLOCKS_PER_SEC;
	
	std::sort(TB,TB+n);
	for(int i=0;i<n;i++)
	{	if(TA[i]!=TB[i])
		{	return false;
		}
	}
	cout<<time<<" ";
	return true;
}
bool lineal(int *,int,int);
bool binary(int *,int,int);
void burbuja(int *,int);
void seleccion(int *,int);
void insertion(int *,int);

int main()
{ //int ta=5;
//  int a[ta]={1,5,3,0,7};
//  int x;
	srand(time(NULL));
	int N=100000;
	int *A=new int[N];
	TA=new int[N];
	TB=new int[N];
  	fun_sort sort[3]={burbuja,insertion,seleccion};
  	for(int n=100;n<=N;n*=10)
  	{	for(int i=0;i<n;i++)
  		{
  			A[i]=rand()%n;
		}
  		cout<<n<<" ";
  		for(int s=0;s<3;s++)
  		{
  			if(!test_sort(sort[s],A,n))
  			{
  				cout<<"FAIL\n";
  				return 0;
		    }
		}
		cout<<endl;
	
	}
	delete []A;
	delete []TA;
	delete []TB;
//  for(int i=0;i<ta;i++)
//  {
//  	cout<<a[i]<<" ";
//  }
//  cout<<endl;
//  cout<<ta<<endl;
//  cout<<"elemento a buscar:";
//  cin>>x;
//  cout<<"busqda binary"<<endl;
//  cout<<binary(a,x,ta);
//  cout<<endl;
//  cout<<"busqueda lineal"<<endl;
//  cout<<lineal(a,x,ta)<<endl;
//  cout<<"ordenamiento burble"<<endl;
//  burbuja(a,ta);cout<<endl;
//  cout<<"ordenamiento por seleccion"<<endl;
//  seleccion(a,ta);
//  cout<<endl;
//  cout<<"ordenamiento por insercion"<<endl;
//  insertion(a,ta);
  
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
//	for(int i=0;i<n;i++)
//	{
//		cout<<a[i]<<" ";
//		
//	}
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
//	for(int i=0;i<n;i++)
//	{
//		cout<<a[i]<<" ";
//	}

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
//	for(int i=0;i<n;i++)
//	{
//		cout<<a[i]<<" ";
//	}
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
