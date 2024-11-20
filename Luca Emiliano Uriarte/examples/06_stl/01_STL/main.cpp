#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> iValores(3);
    iValores[0] = 7;
    iValores[1] = iValores[0] + 1;
    iValores[2] = iValores[0] + iValores[1];

    for(int i=0; i<3; i++)
        cout << iValores[i] << endl;
    reverse(iValores.begin(), iValores.end());
    for(int i=0; i<3; i++)
        cout << iValores[i] << endl;

    char Ch[5] = { 'A', 'E', 'I', 'O', 'U' };
    reverse(Ch + 1, Ch + 4);
    for (int i = 0; i < 5; ++i)
        cout << "Ch[" << i << "] = " << Ch[i] <<endl;

    return 0;
}
