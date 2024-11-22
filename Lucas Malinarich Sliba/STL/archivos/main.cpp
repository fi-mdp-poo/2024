#include "prototipos.h"

//TODO: controlar que filePtr cierre los archivos con los que interactúa
//TODO: deleteFile() tira error por los tipos de datos (string -> char*)

int main(){
    fstream filePtr;
    string nombre, path="registros/";
    int option=1;
    while(option){
//        cout<<"Current file: ";
        cout<<"Choose an option: \n";
        cout<<"\t0.Exit the program \n\t1.New file \n";
        cout<<"\t2.Open file \n\t3.Add to file\n";
        cout<<"\t4.Search file\n\t5.Modify file\n";
        cout<<"\t6.Delete file\n";
        cin>>option;
        switch(option){
            case 0 : confirmarSalida(option); break;
            case 1 : createFile(filePtr); break;
            case 2 : {
                cout<<"File name: ";
                cin>>nombre;
                path+=nombre;
                openFile(filePtr, path);
            } break;
            case 3 : addToFile(filePtr); break;
            case 4 :{
                cout<<"File name: ";
                cin>>nombre;
                path+=nombre;
                (findFile(path))? cout<<"File found.\n" : cout<<"File not found.\n";
            } break;
            case 5 : writeFile(filePtr); break;
            case 6 : {
                cout<<"File name: ";
                cin>>nombre;
                path+=nombre;
                deleteFile(path);
            } break;
            default : cout<<"No option selected.\n";
        }
    }
    return 0;
}

/*
    Todos los caracteres imprimibles están entre los valores 32 y 126

    ofstream outputFile("registros/prueba.txt", ios::app);
    if(outputFile.is_open()){
        outputFile<<"Creating an append in this file.\n";
        outputFile.close();
    }
    else
        cerr<<"File not found.\n";

    char ch;
    ifstream inputFile("registros/prueba.txt");
    try{
        if(!inputFile.is_open())
            throw 1;
        while (inputFile.get(ch)) {
            cout<<ch<<" ";  // Imprimir un carácter a la vez
        }
        inputFile.close();
    }
    catch(int){
        cerr<<"File not found.\n";
    }

    ifstream inputFile("archivo.txt");
    string line;
    while (getline(inputFile, line)) {
        cout<<line<<endl;
    }
*/
