#include <iostream>
using namespace std;
#define TAM_ARREGLO 10
main()
{
	int capturaArreglo [TAM_ARREGLO+1], resultadoArreglo [TAM_ARREGLO+1],i,multiplicador;
	char opc;
	cout << "Este es un programa multiplicador de numeros\n";
	do
	{
		cout<<"Por cual numero quieres multiplicar el arreglo?: ";
		cin>>multiplicador;
		for(i=0;i<=TAM_ARREGLO-1;i++)
		{
		cout<<"\nDame el elemento "<<i+1 <<"/10"<< " : ";
		cin>>capturaArreglo[i];
		resultadoArreglo[i]=multiplicador*capturaArreglo[i];
		}
		for(i=0;i<=TAM_ARREGLO-1;i++)
		{
			cout<<"\nEl elemento "<<i +1<<"/10"<< " es: "<<resultadoArreglo[i];
		}
		cout<<"\nQuiere repetir el programa?   y/n: ";
		cin>>opc;
	}while(opc=='y');
	
	return(0);
}
