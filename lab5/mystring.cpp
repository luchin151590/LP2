#include "mystring.h"


//using namespace std;


        //Constructores


        my_string::my_string()                                //Constructor por defecto
        {
                leng = 0; 
                string = new char[0];
                                
        }         

        
        my_string::my_string( const char * str )  // *str= Null
        {
                if(str)
                {
                        unsigned n = 0; 
                        while( str[n] != '\0'){
                                n++;
                        }
                        
                        leng = n;
                        string = new char [n];
                        
                        for(unsigned i = 0; i<n ; i++)
                                string[i] = str[i]; 
                }
                else {
                        leng = 0; 
                        string = new char[0];
                }                        
                
        }
                
        
        my_string::my_string( const my_string & str)        //Constructor de copia
        {
                leng = str.length();
                   string   = new char[leng];
                   
            for (int i=0; i < leng; i++)
                        string[i] = str[i];
                        
        }
        
        //Destructor
        my_string::~my_string ( ) 
        {
            delete[] string;                        
        }        
        
        //Métodos Básicos
        
        unsigned my_string::length( )const                 // longitud constante
        {
            return leng;
        }
        
        int my_string::indice (char str) const                // Encontrar el índice char (localización)
        {
                for (int j=0; j<leng; j++)
                if (string[j] == str) 
                                return (int)j;
                    else
                            return -1;        
                
        }
        
        bool my_string::vacio()
        {
                if(string[0] == '\0' && leng <= 1){
                        return true;
                }
                else {
                        return false;
                }
        }
        
        //Operadores
        
        my_string& my_string::operator = (const my_string & str)                //Operador de asignación
        {
                 if(this == &str) 
                        return *this;


                    delete string;
    
                    leng= str.length();
                    
                    string = new char[leng];
    
            for (int i=0; i < leng; i++)
                string[i] = str[i];
            return *this;
                
        }


        my_string& operator + ( const my_string & l , const my_string& r)                //Concatenación                //Operador de concatenación
        {
           
                                int size = (l.leng -1) + (r.leng -1) +1;
                                
                                char * aux = new char[size];
                                
                                for(int i = 0; i < (l.leng -1);i++)
                                {
                                        aux[i] = l.string[i];
                                }
                                
                                int j = 0;
                                
                                for(int k = l.leng - 1 , j=0; k < (size-1) ; k++, j++)
                                {
                                        aux[k] = r.string[j];
                                }
                                
                                if(aux[size ] != '\0'){
                                        aux[size ] = '\0';
                                }
                                
                                my_string s3(aux);
                                
                                delete[] aux;
                                return s3; 
                
                
//                unsigned len = length + s.len();
//            char*    str = new char[len];
//        
//            for (unsigned j=0; j < length; j++)
//                str[j] = data[j];
//        
//            for (unsigned i=0; i < s.len(); i++)
//                str[length+i] = s[i];
//        
//            delete data;
//            length = len;
//            data   = str;
//            return *this;   
        }        
        
        bool operator == (const my_string& izq, const my_string& der)        //Igualdad de ambos string
        {
                if(izq.length() != der.length())
                        return false;
                        
                unsigned l_izq = izq.length();
                int n = 0;
                
                while((n < l_izq) && (izq[n] == der[n]))
                        n++;
                return (n == l_izq);
                return true;
                
        }
        
        bool operator > (const my_string& izq, const my_string& der)        
        {        
                int ch = 0;
                if(izq.length() < der.length() ) //ch toma el tamaño menor de los strings
                {
                        int ch = izq.length();
                }
                else 
                {
                        int ch = der.length();
                }
                
            int n = 0;
            
            while ((n < ch) && (izq[n] == der[n])) 
                        n++;
                        
            if (n == ch) 
                        return (izq.length() > der.length());
        
            if ( (('A'<=izq[n]&&izq[n]<='Z') || ('a'<=izq[n]&&izq[n]<='z')) &&
                 (('A'<=der[n]&&der[n]<='Z') || ('a'<=der[n]&&der[n]<='z')) )
            {
                char A = (izq[n] & ~32);
                char B = (der[n] & ~32);
                if (A != B) return (A > B);
            }
            
            return izq[n] > der[n];
                
        }
        
        bool operator < (const my_string& izq, const my_string& der)        
        {
                   return !(izq == der) && !(izq > der);
        }
        
        //Operadores stream
        
         std::ostream& operator<< (std::ostream& os, const my_string& str)        //cout << String 
        {
                //                if (str.length() > 0) 
                //            {        
                //                for (int j=0; j< str.length(); j++)
                //                    os << str[j];
                //            } 
                //                else os << "";
                os << str.string;
            return os;
        }
        
         std::istream& operator>> (std::istream& is,       my_string& str)        //cin >> String 
        {
                char* c = new char[1000];
            is >> c;
            
            str = my_string(c);
            
            delete[] c;
            
            return is;
        }
        
        char my_string::operator[] (int i) const                                // Referencia el acceso
        {
            if (i >= leng) 
                        throw 1;
            return string[i];
        }
        
        
        char& my_string::operator[] ( int i)                 //nuevamente sin const ni &
        {
            if (i >= leng) 
                        throw 1;
            return string[i];
        }
