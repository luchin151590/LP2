#include<iostream>
#include<stdlib.h>
template <class T>
class Matrix
{
  private:
		T **p1;
		size_t f;
		size_t c;
  public:
  	//constructor
  	Matrix(size_t f=0,size_t c=0);
  	Matrix(const Matrix<T> &m);
  	//metodos
  	T &operator()(size_t i,size_t j);
	Matrix<T>operator +(const Matrix<T> &m);
	Matrix<T>operator *(const Matrix<T> &n);
	friend ostream & operator<<(ostream &os,const Matrix<T> &m);
};
template<class T>
Matrix<T>::Matrix(size_t f,size_t c)
{	

	for(int i=0;i<=f;i++) 
	{for(int j=0;j<=c;j++)
		{
			p1[i][j]=0;
		}
	}	
}
template<class T>
Matrix<T>::Matrix(const Matrix<T> &m)
{
	f=m.f;
	c=m.c;
}
template<class T>
T & operator()(size_t i,size_t j)
{	for(int i= 0;i<f;i++)
	{for(int j=0;j<c;j++)
		{	(i,j);
			
		}
	}


}
Matrix<T>operator +(const matrix<T> &m)
{
}
Matrix<T>operator *(const matrix<T> &n)
{
}
Matrix<T>operator<<(T &v)
{
}
friend ostream&operator<<(ostream &os,const Matrix<T> &m);
int main()
{	Matrix<int> A;

	return 0;
}
