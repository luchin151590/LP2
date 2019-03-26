#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char a[80];
	char h[80];
	cout<<"Ingrese un palindromo: ";
	cin>>a;
	//uso strcpy(destino,copia)
	strcpy(h,a); //copia el contenido de cad 1 a cad2
	//uso strrev para invertir la palabra
	strrev(h);
		// profe yo hago esta funcion me copia , pero le añade caracteres desconocidos
		//	int j=0;
		//	for(int i=ta2;i>=0;i--)
		//	{
		//		h[j]=a[i];
		//		j++;
		//	}
		//	
	//uso el strcmp para comparar
	if(strcmp(h,a)==0)
	{
		cout<<"PALINDROMO";
	}
	else{
		cout<<"no palindromo";
	}
	
	return 0;
}
