#include <iostream>
#include "Funcion.hpp"
using namespace std; 

int main ()
{
	int z=0,n=0,v=0;
    Funcion *f1 = new Funcion();
    cout<<"Ingrese el numero de Iteraciones que desea: ";
    cin>>n;
    do
    {
        for(z=0;z<n;z++)
        {
            if(z==0)
            {
                f1->ingresar();
                f1->derivar();
                f1->intervalo();
                f1->evaluar();
                f1->evaluacion();
                f1->matriz();	
            }
            else
            {
                f1->evaluar();
                f1->evaluacion();
                f1->matriz();	
            }
        }
        v=f1->segundointento();
    }
    while(v!=2);
return 0;
}