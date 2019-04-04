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
int *a;
typedef long long my_int; //se usa un alias para un long long llamado my_int
typedef void(*fun_sort)(int *,int); //se usa un alias para una funcion

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
void merge(int *A,int i,int m,int j);
void merge_sort(int *A,int i, int j);
void merge_sort(int *A,int n);


//---------------------FUN. PRINCIPAL
int main()
{ //int ta=5;
//  int a[ta]={1,5,3,0,7};
//  int x;
	srand(time(NULL)); 					// se llama a la funcion srand y se inicializa
	int N=100000;	
	int *A=new int[N]; 						//se inicia un puntero con reserva de memoria y un tamaño N
	TA=new int[N];							//se reserva memoria de los punteros globales a array, con un tamaño N
	TB=new int[N];
  	fun_sort sort[4]={burbuja,insertion,seleccion,merge_sort}; 
  	for(int n=100;n<=N;n*=10)   
  	{	for(int i=0;i<n;i++)
  		{
  			A[i]=rand()%n;			 //se asigna UN VALOR ALEATORIO al arreglo en la posicion i
  						  			 // el numero aleatorio con limite 100
		}
  		cout<<n<<" ";
  		for(int s=0;s<4;s++)
  		{
  			if(!test_sort(sort[s],A,n)) //si no funciona test sort...muestra FAIL
  			{
  				cout<<"FAIL\n";
  				return 0;
		    }
		}
		cout<<endl;
	
	}
	delete []a;
	delete []TA;
	delete []TB;

  
	return 0;
}

// ORDENAMIENTOS

//-------------------ORD. POR MEZCLA
void merge(int *A,int i,int m,int j)
{
  int b=i;
  int d=m+1;
  int c=0;
  while (b<=m && d<=j)
  {
    if(A[b] >= A[d])
    {
      a[c] = a[d];
      d++;c++;
     }
    else
    {
      a[c]=A[b];
      b++;c++;
    }
  }
  while (b<=m) a[c++]=A[b++];
  while (d<=j) a[c++]=A[d++];
  for (int in=0;in<j-i+1;in++)
  {
    A[in+i]=a[in];
  }
  
}

void merge_sort(int *A,int i, int j)
{
  if (i==j) return;
  int m=(i+j)/2;
  merge_sort(A,i,m);
  merge_sort(A,m+1,j);
  merge (A,i,m,j);
  memcpy(A+i,a,(j-i+1)*sizeof(int));
}
void merge_sort(int *A,int n)
{	merge_sort(A,0,n-1);
}

//---------------ORD. POR SELECCION
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


}
//---------------ORD POR BURBUJA
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

}

//--------------ORD. POR INSERCION
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

}
//BUSQUEDAS

//----------------------busqueda lineal
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
//----------------------busqueda binaria
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
