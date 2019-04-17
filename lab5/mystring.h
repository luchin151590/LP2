#ifndef MY_STRING_H
#define MY_STRING_H


#include <iostream>


class my_string
{
        
        private:         
                char*         string ; 
                unsigned          leng; 
                
        public: 
        
                //Constructores
                my_string();                                                                 //Contructor por defecto
                //        my_string (char str);                                                //Constructor crea un objeto
                my_string ( const char * str = NULL); 
                my_string ( const my_string & str);                        //Constructor de copia
                
                //Destructor
                ~my_string();
                
                //Métodos Básicos
                unsigned length( )const;                // longitud constante
        
            int indice (char str) const;                // Encontrar el índice char (localización)
                bool vacio();                                   // si el string está vacio retorna true sino false
                        
                //Operadores
                
                my_string& operator = (const my_string & str);                //Operador de asignación
                friend my_string& operator + ( const my_string& l, const my_string& r);                //Operador de concatenación
                
                //Operadores Lógicos
                friend bool operator == (const my_string& izq, const my_string& der);        //Igualdad de ambos string
                friend bool operator > (const my_string& izq, const my_string& der);        
                friend bool operator < (const my_string& izq, const my_string& der);        
                
                friend std::ostream& operator<< (std::ostream& os, const my_string& str);        //cout << String 
            friend std::istream& operator>> (std::istream& os,       my_string& str);        //cin >> String 
                
                char  operator[] (int i) const;        // Referencia el acceso tuve q agregar esta wea!! sino todo iba mal
                char & operator[]( int  i); // Con y & el const iba mal COPIA al acceso!
                
};


#endif
