#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int ancho = 10,    // fija el ancho del campo de impresión
	    fila, col;     // auxiliares para los lazos

    // setw(ancho) fija la cantidad de caracteres a imprimir para cada variable
    cout << "Se fija el ancho de cada campo a " << ancho << " caracteres:\n\n";
    cout << "         1         2         3         4         5\n";
    cout << "12345678901234567890123456789012345678901234567890\n\n";

	for(fila = 1; fila <=4; fila++)
    {
		for(col = 1; col <= 5; col++)
		{
			cout << setw(ancho) << fila * col;
		}
		cout << endl;
	}
	cout << endl;

    // setiosflags(ios::left)/resetiosflags(ios::right) alinea a derecha o izquierda
    cout << "\nAlinea las filas impares a la izquierda:\n";
	for(fila = 1; fila <= 4; fila++)
    {
        // si es fila impar alinea a la izquierda
		(fila % 2) ? cout << setiosflags(ios::left) : cout << resetiosflags(ios::left);

		for(int col = 1; col <= 5; col++)
        {
			cout << setw(ancho) << fila * col;
		}
		cout << endl;
	}
	cout << endl << endl;

    cout << "setiosflags(ios::right):\n";
	cout << setw(ancho) << setiosflags(ios::right) << 2 << endl;
    cout << "\nsetiosflags(ios::left):\n";
	cout << setw(ancho) << setiosflags(ios::left) << 2 << " (no funciona)" << endl;
	// para que justifique izquierda primero hay que resetear el flag ios::right
    cout << "\nresetiosflags(ios::right) + setiosflags(ios::left):\n";
	cout << setw(ancho) << resetiosflags(ios::right) << setiosflags(ios::left) << 2 << " (ahora OK)" << endl << endl;

   // con setfill(car) se puede fijar el caracter con que se quiere completar el campo, afecta a las salidas posteriores
    cout << "\n\nsetfill(car) permite fijar el car que completa el ancho del campo:\n";
	cout << setiosflags(ios::right) << setw(5) << 14 << "  car = ' ' por defecto\n";
	cout << setfill('0') << setw(5) << 14 << "  car = '0'\n";
	cout << setfill('#') << setw(5) << 14 << "  car = '#'\n\n";

	cout << "Ajustes de cout:\n\t width = " << cout.width()
         << "\tfill = " << cout.fill() << "\tprecision = " << cout.precision()
         << "\tflags = " << cout.flags() << "\n";
	cout.fill(' ');                    // para que no siga completando con #

	// ajuste de la cantidad de caracteres que se presentan
	double res = 800000.0/81.0;                       // res = 9876,5432098765432098765432098765
    cout << "\n\nantes de utilizar setprecision(num):\n";
	cout << "\t" << res << endl;
    cout << "\nsetprecision(3) (imprime 3 digitos):\n";
	cout << setprecision(3) << "\t" << res << endl;   // imprime 3 dígitos
    cout << "\nsetprecision(1) (redondeo!):\n";
	cout << setprecision(1) << "\t" << res << endl;   // imprime 1 dígito --> REONDEO!
    cout << "\nsetiosflags(ios::fixed) + setprecision(5) (imprime 5 digitos decimales):\n";
    cout << setiosflags(ios::fixed) << setprecision(5) << "\t" << res << endl;   // 5 dígitos decimales
	cout << "\t" << 3.14 << "\n\n";                   // la cantidad de dígitos quedó fijada a 5

    // se pueden imprimir los números en distintas bases
	long valor = 64206;
    cout << "\ncon el modificador \"oct\" el dato se presenta en octal:\n";
	cout << "\t" << valor << " en base 8 es " << oct << valor << endl;
    cout << "\ncon el modificador \"hex\" el dato se presenta en hexadecimal:\n";
	cout << "\t" << dec << valor << " en base 16 es " << hex << valor;
    cout.flags(ios::hex | ios::showbase | ios::uppercase);
    cout << " (" << valor << ")\n\n";

    cout.flags(ios::internal | ios::hex | ios::showbase | ios::uppercase);
    cout << setw(10) << setfill('_') << valor << "\n";
    cout.flags(ios::hex | ios::showbase | ios::uppercase);
    cout << setw(10) << setfill('_') << valor << " (sin fijar ios::internal)\n\n";

    cout.flags(ios::showpos | ios::dec);
    cout << setw(10) << setfill(' ') << valor << "\n\n";

    cout << "\nEl modificador tambien funciona para ingresar numeros en hexa: ";
	cin >> hex >> valor;
	//cin.ignore();
	cout.flags(cout.flags() & ~ios::showpos);
    cout << "el valor ingresado es: " << dec << valor << "\n\n\n";

    char car[10];
    cout << "Ingrese una cadena de 10 caracteres (puede tener espacios): ";
    cin.getline(car, 10);
    cout << "Ingrese otra cadena de 10 caracteres (puede tener espacios): ";
    cin.get(car, 10);
    //cin.ignore();       // evita que el \n provoque la ultima lectura
    cout << "Ingrese la tercer cadena de 10 caracteres (puede tener espacios): ";
    cin.getline(car, 10);

    cout << car;

    return 0;
}

