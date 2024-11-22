#include "prototipos.h"

void confirmarSalida(int &option){
    cout<<"You are about to exit the program, to confirm the action press 0.\n";
    cin>>option;
}

bool findFile(const string& path){
    bool resultado;
    ifstream inputFile(path);
    if(inputFile.is_open()){
        resultado=true;
        inputFile.close();
    }
    else
        resultado=false;
    return resultado;
}

void createFile(fstream &file){
    string nombre, path="registros/";
    cout<<"File name: ";
    cin>>nombre;
    path+=nombre;
    if(findFile(path)){
        int option;
        cout<<"The file already exist. Do you want to overwrite it?\n1. Yes\t0.No";
        cin>>option;
        if(option)
            file.open(path, ios::out);
    }
    else
        file.open(path, ios::out);
}

void deleteFile(const string &path){
    if (remove(path) == 0)
        cout <<"File successfully removed.\n";
    else
        cerr<<"An error occurred when deleting the file.\n";
}

void openFile(fstream &file, const string& path){
    if(findFile(path)){
        int option;
        cout<<"Do you want to delete the existing data?\n1. Yes\t0.No";
        cin>>option;
        (option)? file.open(path, ios::out | ios::in) : file.open(path, ios::app | ios::in);
    }
    else
        cout<<"File not found.\n";
}

void writeFile(fstream &file){
    if(file.is_open()){
        string newData;
        cout<<"Data to write: \n";
        cin>>newData;
        file<<newData<<endl;
    }
    else
        cout<<"No file given.\n";
}

void addToFile(fstream &file){
    if(file.is_open()){
        string newData;
        cout<<"Data to write: \n";
        cin>>newData;
        file<<newData<<endl;
    }
    else
        cout<<"No file given.\n";
}
