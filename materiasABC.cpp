/*implementar un programa ABC, para gestionar un listado de materias con sus prerrequisitos, aplicando la técnica de “recorrer registros eliminados”,
 donde, si se capturara el siguiente listado de materias con sus prerrequisitos, al solicitar del menú la opción “Listar registros”,
  se imprimiera en la consola tal cual se muestra a continuación
   (nótese que “Estructuras de Datos I” y “Sistemas Concurrentes y Distribuidos” tienen 2 prerrequisitos)
	incluir en el programa una subrutina de inicialización, la cual emule la carga de información proveniente de un archivo 
	y que dicha subrutina se ejecute antes de que se muestre el menú principal; pero, en lugar de cargar información de un archivo,
	 que agregue en la lista de materias, todos y cada uno de los registros citados en la ilustración previa, usando valores hardcodeados.
*/	

#include <iostream>
#include <string>
#include <string.h>
#define MAX_MATERIAS 15
using namespace std;
int cuentaMaterias;
int pre;
void iniciarPrograma();
void menu();
void altaMateria();
void bajaMateria();
void modificarMateria(int indice);
void mostrarMateria(int indice);
void limpiarRegistroMateria(int indice);
void listarMaterias();
struct Materia
{
	string codigo;
	string nombre;
	string prerequisito[MAX_MATERIAS];
};
struct Materia materia[MAX_MATERIAS];
main ()
{
	int a;
	char rep;
	char iniYN;
	cout<<"Desea ver la rutina de inicializar programa?(y/n): ";
	cin>>iniYN;
	if(iniYN=='y')
	{
		iniciarPrograma();
	}
	do{
		system("CLS");
		system("clear");
		menu();
		cout<<"Que opcion gusta hacer?: ";
		cin>>a;
		switch(a)
	{
		case 1:
			altaMateria();
			break;
		case 2:
			bajaMateria();
			break;
		case 3:
			listarMaterias();
			break;
		default:
			
			break;
	}
	cout<<endl<<"Desea hacer algo mas?(y/n): ";
	cin>>rep;
	}while(rep=='y');
	return(0);
}
void iniciarPrograma()
{
	cout<<"--------------------------------------------------------------------"<<endl
	<<"Clave | Nombre\t\t\t\t\t | Prerequisito(s)"<<endl
	<<"--------------------------------------------------------------------"<<endl
	<<"I5882 | Programacion\t\t\t\t | Logica"<<endl
	<<"--------------------------------------------------------------------"<<endl
	<<"I5892 | Matematica Discreta\t\t\t | Algebra"<<endl
	<<"--------------------------------------------------------------------"<<endl
	<<"I5886 | Estructura de Datos I\t\t\t | I5882"<<endl
	<<"      | \t\t\t\t\t | I5892"<<endl
	<<"--------------------------------------------------------------------"<<endl
	<<"I5888 | Estructuras de Datos II\t\t\t | I5886"<<endl
	<<"--------------------------------------------------------------------"<<endl
	<<"I5890 | Bases de Datos\t\t\t\t | I5886"<<endl
	<<"--------------------------------------------------------------------"<<endl
	<<"I5898 | Programacion para Internet\t\t | I5890"<<endl
	<<"--------------------------------------------------------------------"<<endl
	<<"I7029 | Sistemas Operativos\t\t\t | I5888"<<endl
	<<"--------------------------------------------------------------------"<<endl
	<<"I7033 | Sistemas Operativos de Red\t\t | I7029"<<endl
	<<"--------------------------------------------------------------------"<<endl
	<<"I7035 | Sistemas Concurrentes y Distribuidos\t | I7033"<<endl
	<<"      | \t\t\t\t\t | I5898"<<endl
	<<"--------------------------------------------------------------------"<<endl;
}
void menu()
{
	cout<<"----------------Menu de Registro de Materias----------------"<<endl;
	cout<<"1.- Registrar nueva materia"<<endl
	<<"2.- Borrar Materia"<<endl
	<<"3.- Listar Registros"<<endl;
}
void altaMateria()
{
	cout<<"Alta Nueva Materia\n\n";
    if (cuentaMaterias<MAX_MATERIAS){
        modificarMateria(cuentaMaterias);
        cuentaMaterias++;
    }
    else{
        cout<<"No hay mas espacio para la captura\n\n";
    }
}
void bajaMateria()
{
	int i;
    char opcion;
    cout<<"Baja de Materia"<<endl<<endl;
    cout<<"Indica el numero de registro a eliminar (1 a "<<MAX_MATERIAS<<"): ";
    cin>>i;
    i--;
    cout<<"\n";
    mostrarMateria(i);
    cout<<endl<<"Estas seguro de eliminar el registro (s/n)?: ";
    cin.ignore();
    cin>>opcion;
    if (opcion=='S' || opcion=='s'){
        for(cuentaMaterias--;i<cuentaMaterias;i++){
                materia[i]=materia[i+1];
            }
            limpiarRegistroMateria(i);
            cout<<"Registro eliminado!"<<endl;
     }
        else{
            cout<<"Registro conservado!"<<endl;
        }
}
void modificarMateria(int indice)
{
	int i=indice;
    cout<<"Provee datos para el registro "<<i+1<<endl;
    cout<<"Codigo de la Materia: ";
    cin.ignore();
    getline(cin,materia[i].codigo);
    cout<<"Nombre de la Materia: ";
    cin.ignore();
    getline(cin,materia[i].nombre);
    cout<<"Cuantos prerequisitos tiene: ";
    cin>>pre;
    if(pre==1)
    {
    	cout<<"Dame el prerequisito: ";
    	cin.ignore();
    	getline(cin,materia[i].prerequisito[0]);
	}
	else if(pre>1)
	{
		for(int j=0;j<=pre-1;j++)
		{
			cout<<"Dame el prerequisito "<<j+1<<": ";
			cin.ignore();
			getline(cin,materia[i].prerequisito[j]);
		}
	}
	else
	{
		cout<<"ERROR ABORTANDO...";
	}
}
void mostrarMateria(int indice)
{
	int i=indice;
    cout<<"Registro "<<i+1<<endl;
   	cout<<"Codigo de Materia: "<<materia[i].codigo<<endl;
   	cout<<"Nombre de Materia: "<<materia[i].nombre<<endl;
   	cout<<"Prerequisito de la Materia: "<<materia[i].prerequisito[0]<<endl;
}
void limpiarRegistroMateria(int indice){
    int i=indice;
    materia[i].codigo="";
    materia[i].nombre="";
    materia[i].prerequisito[0]="";
   	materia[i].prerequisito[1]="";
}
void listarMaterias()
{
	int k;
	cout<<endl<<"--------------------------------------------------------------------"<<endl
		<<"Clave | Nombre\t\t\t\t\t | Prerequisito(s)"<<endl;
	for (k=0;k<=cuentaMaterias-1;k++)
	{
		cout<<"--------------------------------------------------------------------"<<endl
		<<materia[k].codigo<<" | "<<materia[k].nombre<<" | "<<materia[k].prerequisito[0]<<endl;
	}
}

