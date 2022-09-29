#include <iostream>
#include "complex.h"
#include <fstream>

int main(int argc, char** argv){

    if (argc < 2 ){
        cout << "Olvidó indicar la dirección del archivo que contiene la información." << endl;
        return 1;
    }

    Complex vecComplex[6];
    double  vecTheta[6];
    double aux;
    int i = 0;
    cout << "Archivo a procesar: " << argv[1] << endl;

    ifstream archivo;
    archivo.open ( argv[1] );
    if ( archivo.is_open() ){
        cout << "archivo abierto" << endl;
        archivo >> aux;
        while( !archivo.eof() ){
            vecComplex[i].real( aux );
            archivo >> aux;
            vecComplex[i].imag( aux );
            archivo >> aux;
            i++;
        }
        archivo.close();
    }
   
   
    for( i = 0; i < 6; i++){
        vecTheta[i] = vecComplex[i].angle();
    }
   
    bool cambio;
    double auxT;
    Complex auxC;
    do{
        cambio = false;
        for(int i = 0; i < 5; i++){
            if(vecTheta[i] > vecTheta[i+1] ){
                cambio = true;
                auxT = vecTheta[i];
                vecTheta[i] = vecTheta[i+1];
                vecTheta[i+1] = auxT;
               
                auxC = vecComplex[i];
                vecComplex[i] = vecComplex[i+1];
                vecComplex[i+1] = auxC;
            }
        }
    }while( cambio == true );
   
    // Una vez ordenado los imprimo
   
    for( int i = 0; i < 6; i++)
        cout << vecTheta[i] << ", ";
       
    cout << endl;
   
    for( int i = 0; i < 6; i++)
        cout << vecComplex[i].real() << " + " << vecComplex[i].imag() << "j\n";

    return 0;
}