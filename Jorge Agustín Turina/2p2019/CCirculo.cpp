#include "CCirculo.h"

CCirculo::CCirculo()
{
    //ctor
}

CCirculo::~CCirculo()
{
    //dtor
}


double CCirculo::dCalcArea(){
    return Radio*3.14;
}
        float CCirculo::fGetRadio(){
            return Radio;
        }
        void CCirculo::vSetRadio(float r){
            Radio = r;
        }

        void CCirculo::vImprimir(ostream& os){
            os << "soy un circulo de radio "<< fGetRadio() << "y area " << dCalcArea() << endl;

        }
        void CCirculo::SetValores(float r){
            Radio = r;
            cout << "estoy en setValores de circulo"<< endl;
         }
