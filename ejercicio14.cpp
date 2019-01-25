#include <iostream>
using namespace std;
#define TAM 10
struct{
	string Name [TAM+1];
	int asistPercent [TAM+1];
	float Grade [TAM+1];
}student;
main()
{
	char opc;
	cout << "This is a program for organize the students\n";
	int i=0,j=0;

	do
	{
		setbuf(stdin, NULL);
		cout<<"\nGive me de name of the student: ";
		getline(cin,student.Name[i]);
		setbuf(stdin, NULL);
		cout<<"Give me the assist percent of the student: ";
		cin>>student.asistPercent[i];
		cout<<"Give me the Grade of the student: ";
		cin>>student.Grade[i];
		cout<<"\nDo you like add more students (MAX 10)?   y/n: ";
		cin>>opc;
		setbuf(stdin, NULL);
		i++;
		j++;
	}while(opc=='y');
	for (i=0;i<j;i++)
	{
		cout<<"\nName: "<<student.Name[i];
		cout<<"\nPercent of assists: "<<student.asistPercent[i]<<"%";
		cout<<"\nGrade: "<<student.Grade[i]<<"\n";
	}
	
	return(0);
}
