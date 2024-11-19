int main()
{
CMatriz original;

original.cargar("colores.bin");
cout << "Matriz original:" << endl << original << endl;

CMatriz copia(original),
        suma;

suma = original;
suma+= (copia + 5);
cout << "Matriz suma:" << endl << suma <<endl;

CPantalla pantalla(original);
cout << "Pantalla original:" << endl << pantalla << endl;

pantalla.ajustarColor(3);
cout << "Pantalla con ajuste de color:" << endl << pantalla << endl;

pantalla.borrarVerde();
cout << "Pantalla sin componente verde:" << endl << pantalla << endl;

pantalla.reforzarRojo(0.35);
cout << "Pantalla modificada (rojo reforzado):" << endl << pantalla << endl;

//generar la misma informacion en un archivo de salida: pantalla.txt

CColor color(pantalla.getPtr()[pantalla.getFilas()*pantalla.getColumnas()-1]);

cout << "El color del ultimo punto de la pantalla es: " << endl
       << color << endl;

return 0;
}
