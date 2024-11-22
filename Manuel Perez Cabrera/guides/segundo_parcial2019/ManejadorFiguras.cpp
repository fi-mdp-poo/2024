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
    MyRec->vSetForeColor(color); /// es equivalente a hacer MyRec->vSetForeColor(CColor(color));
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
    base = 0.7;
    altura = 0.3;
    color = 0x03FAAF00;
    MyRec->vSetBase(base);
    MyRec->vSetAltura(altura);
    MyRec->vSetForeColor(color);
    color = 0xFA03AF00;
    MyRec->vSetBackColor(color);
    Figuras.push_back(MyRec);


}


void ManejadorFiguras::ImprimirFiguras(ostream& os)
{
    int tam = Figuras.size();

    for(int i = 0 ; i < tam ; i++)
    {
        Figuras[i]->vImprimir(os);
        os << *Figuras[i];
    }

}

double ManejadorFiguras::TotalArea()
{
    int tam = Figuras.size();
    double area_total = 0;
    for(int i = 0 ; i < tam ; i++)
    {
        area_total = area_total + Figuras[i]->GetArea();
    }
    return area_total;
}

CFigura* ManejadorFiguras::Get(uint8_t n)
{
    return Figuras[n];
}

void ManejadorFiguras::Ordenar()
{
    // Ordena las figuras según su área en orden ascendente
    sort(Figuras.begin(), Figuras.end(),[](CFigura* a, CFigura* b)
    {
        return a->GetArea() < b->GetArea(); // Comparación basada en el área
    }
             );
}
