#ifndef CCOLOR_H_INCLUDED
#define CCOLOR_H_INCLUDED
#include <ostream>

using namespace std;

class CColor
{
public:
    CColor();
    CColor(int);
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
    friend ostream& operator<< (ostream&, CColor&);
private:
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char alpha;
    int color;
};


#endif // CCOLOR_H_INCLUDED
