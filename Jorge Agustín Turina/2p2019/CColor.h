#ifndef CCOLOR_H
#define CCOLOR_H

using namespace std;
#include <ostream>
class CColor
{
    public:
        CColor();
        CColor(int );
        ~CColor();
        unsigned char GetRed();
        unsigned char GetGreen();
        unsigned char GetBlue();
        unsigned char GetAlpha();
        int GetColor();
        void SetRed(unsigned char);
        void SetGreen(unsigned char);
        void SetBlue(unsigned char);
        void SetAlpha(unsigned char);
        void SetColor(int);
        friend ostream& operator<< (ostream&, CColor);

    protected:

    private:
        unsigned char r;
        unsigned char g;
        unsigned char b;
        unsigned char a;
        int color;
};

#endif // CCOLOR_H
