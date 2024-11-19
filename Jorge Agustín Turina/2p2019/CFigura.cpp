#include "CFigura.h"

CFigura::CFigura()
{
    //ctor
}

CFigura::~CFigura()
{
    //dtor
}


CColor CFigura::colGetForeColor(){
    return CFigura::Color_linea;

}


        CColor CFigura::colGetBackColor(){
            return Color_fondo;
        }
        void CFigura::vSetForeColor(CColor c){
            Color_linea = c;

        }
        void CFigura::vSetBackColor(CColor f){
            Color_fondo = f;
        }
        double CFigura::dCalcArea() {
;
        }

        ostream& operator<< (ostream&os, CFigura& cf){
            os << endl;
            //CColor a = cf.colGetBackColor();
            //CColor b = cf.colGetForeColor();

            os << "BackgroundColor:" << endl;
            os << cf.colGetBackColor()<< endl;

            os << "ForeColor:" << endl;
            os << cf.colGetForeColor() << endl;
        return os;
        }


         void CFigura::vImprimir(ostream& os){


         }

         void CFigura::SetValores(float, float){

         }
         void CFigura::SetValores(float){
         }
