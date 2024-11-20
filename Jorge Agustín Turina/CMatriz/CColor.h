#ifndef CCOLOR_H
#define CCOLOR_H

#include <ostream>
#include "CMatriz.h"
using namespace std;
class CColor
{
    public:
        CColor(CMatriz&);
        virtual ~CColor();
        friend ostream& operator<<(ostream& os, const CColor& m);  // Sobrecarga de <<

    protected:

    private:
};

#endif // CCOLOR_H
