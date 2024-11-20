#include "CRectangulo.h"

 CRectangulo::CRectangulo(){
 }
         CRectangulo::CRectangulo(float b , float a){
             Base = b;
             Altura = a;
         }
        CRectangulo::~CRectangulo(){
        }
        float  CRectangulo::fGetBase(){
        return Base;
        }
        void  CRectangulo::vSetBase(float b){
        Base = b;
        }
        float  CRectangulo::fGetAltura(){
        return Altura;
        }
        void  CRectangulo::vSetAltura(float a){
        Altura = a;
        }
        double  CRectangulo::dCalcArea(){
        return Base*Altura;
        }
        void  CRectangulo::vImprimir(ostream& os){
        os << "soy un rectangulo de base " << fGetBase() << ", altura" << fGetAltura() <<", y area" << dCalcArea() << endl;
        }
        void  CRectangulo::SetValores(float b, float a){
            Base = b;
            Altura = a;
        }
