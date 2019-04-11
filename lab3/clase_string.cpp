#include<isotream>

class my_string
{
	private:
		char c;
		int ta;
	public:
		my_string(const char *str=NULL);  //puntero a char
		my_string(const my_string &str);
		~my_string();
		my_string &operator =(const my_string &str);
		my_string &operator +(const my_string &str); //concatena

};

my_string::my_string(const char *str=NULL)
{	
	str=new[ta];
	for(int i=0;i<ta;i++)
	{
		str[i]='\0';
	}
	
}

my_string::my_string(const my_string &str)
{
	c=str.c;
}
my_string::~my_string()
{
	delete str[];
}
