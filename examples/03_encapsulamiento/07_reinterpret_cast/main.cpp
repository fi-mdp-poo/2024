#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int x = 0x12dc34f2;
    int *pix = &x;
    unsigned char *pcx;

    pcx = reinterpret_cast<unsigned char *> (pix);

    cout << x << " = " << hex << pcx[0] << ", "   << pcx[1] << ", "
             << pcx[2] << ", " << pcx[3] << dec << endl << endl;

    cout << x << " = " << hex
             << static_cast<unsigned int> (pcx[0]) << ", "   << static_cast<unsigned int> (pcx[1]) << ", "
             << static_cast<unsigned int> (pcx[2]) << ", "   << static_cast<unsigned int> (pcx[3]) << endl;

    return 0;
}
