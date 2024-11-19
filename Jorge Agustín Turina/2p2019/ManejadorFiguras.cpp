#include "ManejadorFiguras.h"

ManejadorFiguras::ManejadorFiguras()
{
    //ctor
}

ManejadorFiguras::~ManejadorFiguras()
{
    //dtor
}

void ManejadorFiguras::CargarFiguras()
{
    CRectangulo *MyRec = new CRectangulo();
    float base = 1.2, altura = 2.5;
    int color = 0x0A0BFE42;
    MyRec->vSetBase(base);
    MyRec->vSetAltura(altura);
    MyRec->vSetForeColor(color);
    color = 0x0BFE0A42;
    MyRec->vSetBackColor(color);
    Figuras.push_back(MyRec);

    CCirculo *MyCir = new CCirculo();
    float radio = 1.0;
    color = 0xFFFF0010;
    MyCir->vSetRadio(radio);
    MyCir->vSetForeColor(color);
    color = 0xFF00FF10;
    MyCir->vSetBackColor(color);
    Figuras.push_back(MyCir);

    MyRec = new CRectangulo();
    base = 0.7; altura = 0.3;
    color = 0x03FAAF00;
    MyRec->vSetBase(base);
    MyRec->vSetAltura(altura);
    MyRec->vSetForeColor(color);
    color = 0xFA03AF00;
    MyRec->vSetBackColor(color);
    Figuras.push_back(MyRec);





}

//    void ManejadorFiguras::ImprimirFiguras(ostream& os){
//
//    std::vector<CFigura*>::iterator it;
//    for (it = Figuras.begin(); it != Figuras.end(); ++it) {
//        if (*it) {  // Verifica que el puntero no sea nulo.
//            (*it)->vImprimir(os);  // Llama al método Imprimir de la figura.
//            os << (*it);
//            os << "\n";  // Opcional: agrega un salto de línea entre figuras.
//        }
//    }
//
//    }


    void ManejadorFiguras::ImprimirFiguras(std::ostream& os) {
    for (size_t i = 0; i < Figuras.size(); ++i) {
        if (Figuras[i]) {  // Verifica que el puntero no sea nulo.
            Figuras[i]->vImprimir(os);  // Llama al método Imprimir de la figura.
            os << *Figuras[i];
            os << "\n";  // Opcional: agrega un salto de línea entre figuras.
        }
    }
}


    double ManejadorFiguras::TotalArea(){
    double resultado = 0;
        std::vector<CFigura*>::iterator it;
    for (it = Figuras.begin(); it != Figuras.end(); ++it) {
        if (*it) {  // Verifica que el puntero no sea nulo.
            resultado = resultado + (*it)->dCalcArea();  // Llama al método Imprimir de la figura.
                // Opcional: agrega un salto de línea entre figuras.
        }
    }
    return resultado;

    }
    void ManejadorFiguras::AgregarFigura(CFigura*){}
    CFigura* ManejadorFiguras::Get(uint8_t indice){

    return Figuras[indice];
    }


   void ManejadorFiguras::Ordenar() {
    qsort(&Figuras[0], Figuras.size(), sizeof(CFigura*), [](const void* a, const void* b) {
        CFigura* figuraA = *(CFigura**)a;
        CFigura* figuraB = *(CFigura**)b;

        double areaA = figuraA->dCalcArea();
        double areaB = figuraB->dCalcArea();

        if (areaA < areaB) return -1;  // Menor área primero.
        if (areaA > areaB) return 1;   // Mayor área después.
        return 0;                      // Áreas iguales.
    });
}
