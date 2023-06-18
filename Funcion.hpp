#include <iostream>
#include <math.h>
#include <iomanip>
#include "rang.hpp"
using namespace std; 
using namespace rang;
class Funcion
{ 
    private:
    float x;
    float y;
    float x2;
    float y2;
    float xo;
    float yo;
    float xn;
    float yn;
    float xexp;
    float yexp;
    float fx;
    float fy;
    float fx2;
    float fy2;
    float fxn;
    float fyn;
    float cont;
    float fcont;
    int fxexp;
    int fyexp;

    float ex;
    float ey;
    float inx;
    float iny;
    float xb;
    float yb;
    float fxb;
    float fyb;
    float xd;
    float yd;
    float fxd;
    float fyd;
    float res[2];
    int b;
    public:
    Funcion();
    void ingresar();
    void derivar();
    void intervalo();
    void evaluar();
    void evaluacion();
    void matriz();
    int segundointento();
};
Funcion::Funcion()
{
	b=0;
    cout<< fg::magenta << style::bold<<"****Newton Raphson****"<<endl;
    cout<<fg::magenta << style::bold<<"*****Hola Usuario*****"<<endl;
}
int Funcion::segundointento()
{
    int opc;
    cout<<fgB::cyan << style::italic <<"Desea ingresar otro ejercicio"<<endl;
    cout<<fgB::cyan << style::italic <<"1.-SI\n2.-NO: ";
    cin>>opc;
    if(opc==1)
    {
        b=0;
    }
    return opc;
}
void Funcion::ingresar()
{
    cout<<fgB::blue << style::italic<<"Igrese el valor que va a X= ";
    cin>>x;
    cout<<fgB::blue << style::italic<<"Igrese el valor del Exponente de X= ";
    cin>>xexp;
    cout<<fgB::blue << style::italic<<"Igrese el segundo valor que va a alguna otra variable X (si es que lo hay)= ";
    cin>>x2;
    cout<<fgB::blue << style::italic<<"Igrese el valor que va a Y= ";
    cin>>y;
    cout<<fgB::blue << style::italic<<"Igrese el valor del Exponente de Y= ";
    cin>>yexp; 
    cout<<fgB::blue << style::italic<<"Igrese el segundo valor que va a alguna otra variable y (si es que lo hay)= ";
    cin>>y2;
    cout<<fgB::blue << style::italic<<"Igrese el valor de la constante (si es que lo hay)= ";
    cin>>cont;
    cout<<fgB::blue << style::italic<<"F2= "<<x<<"x^"<<xexp<<"+"<<x2<<"x+"<<y<<"y^"<<yexp<<"+"<<y2<<"y+"<<cont<<endl; 
    
    cout<<fgB::green << style::italic<<"Igrese el valor que va a X= ";
    cin>>fx;
    cout<<fgB::green << style::italic<<"Igrese el valor del Exponente de X= ";
    cin>>fxexp;
    cout<<fgB::green << style::italic<<"Igrese el segundo valor que va a alguna otra variable X (si es que lo hay)= ";
    cin>>fx2;
    cout<<fgB::green << style::italic<<"Igrese el valor que va a Y= ";
    cin>>fy;
    cout<<fgB::green << style::italic<<"Igrese el valor del Exponente de Y= ";
    cin>>fyexp; 
    cout<<fgB::green << style::italic<<"Igrese el segundo valor que va a alguna otra variable y (si es que lo hay)= ";
    cin>>fy2;
    cout<<fgB::green << style::italic<<"Igrese el valor de la constante (si es que lo hay)= ";
    cin>>fcont;
    cout<<fgB::green << style::italic<<"F2= "<<fx<<"x^"<<fxexp<<"+"<<fx2<<"x+"<<fy<<"y^"<<fyexp<<"+"<<fy2<<"y+"<<fcont<<endl; 
}
void Funcion::derivar()
{
    xd = xexp*x;
    yd = yexp*y;
    cout<<fgB::yellow << style::italic <<"F1="<<xd<<"x+"<<x2<<"\t"<<yd<<"y+"<<y2<<endl;
    fxd = fxexp*fx;
    fyd = fyexp*fy;
    cout<<fgB::yellow << style::italic <<"F2="<<fxd<<"x+"<<fx2<<"\t"<<fyd  <<"y+"<<fy2<<endl;
}
void Funcion::intervalo()
{
    cout<<fgB::blue << style::italic<<"ingrese el valor de x del intervalo: ";
    cin>>xo;
    cout<<fgB::blue << style::italic<<"ingrese el valor de y del intervalo: ";
    cin>>yo;
}
void Funcion::evaluar()
{
    xn=xd*xo+x2;
    yn=yd*yo+y2;
    fxn=fxd*xo+fx2;
    fyn=fyd*yo+fy2;
    if(b==0)
	{
		cout<<fgB::yellow << style::italic <<"F1="<<xn<<"\t"<<yn<<endl;
    	cout<<fgB::yellow << style::italic <<"F2="<<fxn<<"\t"<<fyn<<endl;
	}
}
void Funcion::evaluacion()
{
    ex=x*pow(xo,xexp)+y*pow(yo,yexp)+(x2*xo)+(y2*yo)+cont;
    ey=fx*pow(xo,fxexp)+fy*pow(yo,fyexp)+(fx2*xo)+(fy2*yo)+fcont;
    if(b==0)
    {
    	cout<<fgB::yellow << style::italic <<"F1="<<ex<<endl;
    	cout<<fgB::yellow << style::italic <<"F2="<<ey<<endl;
	}
}
void Funcion::matriz()
{ 
    int i=0,j=0,n=2,k=0;
    float pivote=0,aux=0;
    float matriz[n][n], inv[n][n];
    float intervalo[2], evaluada[2],mult[2];
    //llenado
    for(i=0;i<n;i++)  
    {
        for(j=0;j<n;j++)
        {
            if(i==0 && j==0)
            {
                matriz[i][j]=xn;
            }
            if(i==0 && j==1)
            {
                matriz[i][j]=yn;
            }
            if(i==1 && j==0)
            {
                matriz[i][j]=fxn;
            }
            if(i==1 && j==1)
            {
                matriz[i][j]=fyn;
            }
            inv[i][j]=0;
            if(i==j)
            {
                inv[i][j]=1;

            }
        }
    }
    for(i=0;i<n;i++) 
    {
        if(i==0)
        {
            intervalo[i]=xo;
        }
        else
        {
            intervalo[i]=yo;
        }
    }
    for(i=0;i<n;i++) 
    {   
        if(i==0)
        {
            evaluada[i]=ex;
        }
        else
        {
            evaluada[i]=ey;
        }
    }

    //impresion
    if(b==0)
    {
	    for(i=0;i<n;i++)
	    {
	        for (j=0;j<n;j++)
	        {
	            cout<<fg::red << style::bold<<matriz[i][j]<<"\t";
	        }
	        cout<<"|\t";
	        for(j=0;j<n;j++)
	        {
	            cout<<fg::red << style::bold<<inv[i][j]<<"\t";
	        }
	        cout<<endl;
	    }
	}
    //inversa
    for(i=0;i<n;i++)
    {
        pivote=matriz[i][i];
        for(j=0;j<n;j++)
        {
            matriz[i][j]=matriz[i][j]/pivote;
            inv[i][j]=inv[i][j]/pivote;
        }
        for(j=0;j<n;j++)
        {
            if(i!=j)
            {
                aux=matriz[j][i];
                for(k=0;k<n;k++)
                {
                    matriz[j][k]=matriz[j][k]-aux*matriz[i][k];
                    inv[j][k]=inv[j][k]-aux*inv[i][k];
                }
            }
        }

    }
    //impresion
    if(b==0)
    {
	    cout<<endl;
	    for(i=0;i<n;i++)
	    {
	        for (j=0;j<n;j++)
	        {
	            cout<<fg::blue << style::bold<<fixed<<setprecision(3)<<abs(matriz[i][j])<<"\t";
	        }
	        cout<<"|\t";
	        for(j=0;j<n;j++)
	        {
	            cout<<fg::blue << style::bold<<fixed<<setprecision(3)<<inv[i][j]<<"\t";
	        }
	        cout<<endl;
	    }
	    //impresion
	    cout<<endl;
	    for(i=0;i<n;i++)
	    {
	        if(i==0)
	        {
	            cout<<fgB::gray << style::italic <<"x=\t";
	        }
	        else
	        {
	            cout<<fgB::gray << style::italic <<"y=\t";
	        }
	        cout<<"|\t";
	        cout<<fgB::gray << style::italic <<intervalo[i]<<"\t";
	        cout<<"|-\t";
	        for(j=0;j<n;j++)
	        {
	            cout<<fgB::gray << style::italic <<fixed<<setprecision(5)<<inv[i][j]<<"\t";
	        }
	        cout<<"|\t";
	        cout<<fgB::gray << style::italic <<evaluada[i]<<endl;;
	    }
	}
    //multiplicacion
    for(i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            mult[i]+=inv[i][j]*evaluada[j];
        }
    }
    //resta
    for(i=0;i<n;i++)
    {
        res[i]=intervalo[i]-mult[i];
    }
    cout<<endl;
    //impresion
    cout<<fgB::red << style::italic <<fixed<<setprecision(5)<<"X\t\tY"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<fgB::yellow << style::italic <<res[i]<<"\t\t";
        if(i==0)
		{
			xo=res[i];
		}
		else
		{
			yo=res[i];
		}
    }
    cout<<endl;
    b++;
}