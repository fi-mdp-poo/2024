#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    string s("In Xanadu did Kubla Khan...");
    ofstream fout("output.txt");

    for( unsigned int i=0; i<s.length(); i++ )
    {
        cout << "File pointer: " << fout.tellp();
        fout.put( s[i] );
        cout << " " << s[i] << endl;
    }
    fout.close();

    ifstream fin("output.txt");
    char ss[40],
         ch;
    int i = 0;

    while(fin.get(ch))
    {
        ss[i++] = ch;
    }
    cout << "\n\n\nNueva salida: " << ss << endl;

    fin.clear();
    fin.seekg(0);

    while(fin >> ch)
    {
        ss[i++] = ch;
    }
    cout << "\n\n\nOtra nueva salida: " << ss << endl;

    fin.close();

    return 0;
}
