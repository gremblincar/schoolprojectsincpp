#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

class Usuarios
{
public:
    char usuario[10], password[10], nombre[35];
    void Capturar();
    void Modificar();
    void Mostrar();
};
Usuarios datos;
void Usuarios::Capturar()

{
    cout<<endl<<"Usuario: ";
    cin.getline(usuario,35);
    cout<<endl<<"Password: ";
    cin.getline(password,10);
    cout<<endl<<"Nombre: ";
    cin.getline(nombre,35);
    ofstream a("usuarios.txt",ios::app);
    a.write((char*)&datos,sizeof(datos));
    a.close();
}

void Usuarios::Mostrar()
{
    char usuario2[10], password2[10];
    int band=0;
    ifstream a("usuarios.txt");
    if(!a.good())
    {
        cout<<endl<<"NO EXISTE ARCHIVO.....";
    }
    else
    {

        cout<<endl<<"Ingrese usuario: ";
        cin.getline(usuario2,10);
        cout<<endl<<"Ingrese contraseÒa: ";
        cin.getline(password2,10);
    }
    while(!a.eof())
    {
        a.read((char*)&datos,sizeof(datos));
        if(a.eof())
        {
            break;
        }

        if(strcmp(usuario,usuario2)==0 && strcmp(password,password2)== 0)
        {
            int opc;
            cout<<endl<<"----ACCESO EXITOSO----"<<endl;
            cout<<endl<<"NOMBRE: "<<nombre;
            band=1;
        }
    }

    if(band==0)
    {
        cout<<"Usuario o contraseÒa erronea\n";
    }
    a.close();
}

void Usuarios::Modificar()
{
    char usuario3[10], password2[10];
    int opc,val;
    cout<<endl<<"Ingrese usuario: ";
    cin.getline(usuario3,10);
    cout<<endl<<"Ingrese contraseÒa: ";
    cin.getline(password2,10);
    fflush(stdin);

    ifstream modifica("usuarios.txt");
    ofstream temp("temporal.txt",ios::app);

    if(!modifica.good())
    {

        cout<<"No se encontro el archivo..."<<endl;

    }
    else
    {
        while(!modifica.eof())
        {
            modifica.read((char *)&datos, sizeof(datos));
            if(modifica.eof())
                break;
            if(strcmp(usuario,usuario3)==0 && strcmp(password,password2)== 0)
            {
                if(modifica.eof())
                    break;
                cout<<endl<<"-----ACCESO EXITOSO-----"<<endl;
                cout<<endl<<"Nombre anterior: "<<datos.nombre;
                cout<<endl<<"Nombre nuevo: ";

                cin.getline(datos.nombre, 35);

                val = 1;


            }

            temp.write((char*)&datos, sizeof(datos));



        }
        if(val == 1)
        {
            cout<<" **Se ha MODIFICADO con exito**"<<endl;

        }
        if(val != 1)
        {
            cout<<"No se encontro..."<<endl;
        }
    }
    modifica.close();
    temp.close();
    remove("usuarios.txt");
    rename("temporal.txt","usuarios.txt");

}

int main(){
    int opc;
    do{
        cout<<endl<<endl<<endl<<" 1.- CAPTURAR "<<endl<<" 2.- MOSTRAR "<<endl<<" 3.- MODIFICAR "<<endl<<" 4.- SALIR "<<endl<<endl<<"SELECCIONA LA OPCION (1-4): ";
        cin>>opc;
        cin.ignore();
        switch(opc){
            case 1:
                system("cls");
                datos.Capturar();
                break;

            case 2:
                system("cls");
                datos.Mostrar();
                break;

            case 3:
                system("cls");
                datos.Modificar();
                break;
        }

    }while(opc!=4);

    return 0;

}
