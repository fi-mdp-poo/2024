#include <cassert>
#include <iostream>
#include <ostream>
#include <string>

using namespace std;

int main()
{
    string s("A piece of text");
    string tag("$tag$");
    string replace_s;

    s.insert(8, tag + ' ');
    assert(s == "A piece $tag$ of text");
    int start = s.find(tag);
    assert(start == 8);
    assert(tag.size() == 5);

    cout << "S: " << s << endl;
    cout << "Tamaño de s: " << s.size() << endl;

    cout << "Ingrese una cadena de caracteres: " << endl;
    cin >> replace_s;
    s.replace(start, tag.size(), replace_s);

    cout << "S: " << s << endl;
    cout << "Tamaño de s: " << s.size() << endl;

    assert(s == "A piece " + replace_s + " of text");
}