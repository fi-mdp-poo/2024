#ifndef CCOLOR_H
#define CCOLOR_H

#include <iostream>

using namespace std;

class CColor
{
    public:
        CColor(int Color=0);
        virtual ~CColor();

        int GetBlue() { return Blue; }
        void SetBlue(int val);
        int GetGreen() { return Green; }
        void SetGreen(int val);
        int GetRed() { return Red; }
        void SetRed(int val);
        int GetAlpha() { return Alpha; }
        void SetAlpha(int val);
        int GetColor() { return Color; }
        void SetColor(int val) { Color = val; }

        friend ostream& operator<< (ostream& co, CColor &cmp);

    protected:

    private:
        int Blue;
        int Green;
        int Red;
        int Alpha;
        int Color;
};

#endif // CCOLOR_H
