#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
	float conteoGeneral=0,area,randomNumber,acumEventos=0;
	int conteoEventos,a,i;
	srand((unsigned)time(0));
	cout<<"Estre programa calcula la probabilidad subjetiva"<<endl;
	cout<<"Cuantas veces quieres que se repita el evento: ";
	cin>>conteoEventos;
	int eventos[conteoEventos+1];
	cout<<"1.- Probabilidad de que salga par"<<endl<<"2.- Probabilidad de que sala impar"<<endl;
	cout<<"Que opcion gustas: ";
	cin>>a;
	switch(a)
	{
		case 1:
			for(i=0;i<=conteoEventos-1;i++)
			{
				conteoGeneral++;
				eventos[i]=(rand()%2)+1;
				if(eventos[i]%2==0)
				{
					acumEventos=acumEventos+eventos[i];
				}
				float probabilidad=(acumEventos/(conteoGeneral*2))*100;
				cout<<"Evento "<<i+1<<" = "<<eventos[i]<<" | Frecuencia Absoluta Acomulada: "<<acumEventos<<" | Probabilidad: "<<probabilidad<<"% | "<<acumEventos<<"/"<<conteoGeneral*2<<endl;
			}
			break;
		case 2:
			for(i=0;i<=conteoEventos-1;i++)
			{
				conteoGeneral++;
				eventos[i]=(rand()%2)+1;
				if(eventos[i]%2!=0)
				{
					acumEventos=acumEventos+eventos[i];
				}
				float probabilidad=(acumEventos/(conteoGeneral*2))*100;
				cout<<"Evento "<<i+1<<" = "<<eventos[i]<<" Frecuencia Absoluta Acomulada: "<<acumEventos<<" Probabilidad: "<<acumEventos/(conteoGeneral*2)<<" "<<acumEventos<<"/"<<conteoGeneral*2<<endl;
			}
			break;
		default:
			
			break;
	}
	return(0);
	
}
