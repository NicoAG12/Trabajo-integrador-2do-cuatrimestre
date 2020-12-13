#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
/////////////////////////////
////REGISTROS///////////////
typedef char cadena[80];

struct fecha{
	int dia;
	int mes;
	int anio;
};
struct fechaturnos{
	int dia;
	int mes;
	int anio;
};
struct usuario{
	char usuario[10];
	char contrasena [10];
	char apeynom[10];
};
struct veterinario{
	char apeynomvet[10];
	int matricula;
	int DNI;
	char telefono[25];
};
struct mascota{
	char apeynommasc[60];
	char domicilio[60];
	int DNI_duenio;
	char localidad[60];
	fecha fecnacimiento;
	float peso;
	char telefonomasc[25];
};
struct turnos{
	int matricvet;
	fechaturnos fect;
	int DNI_duenio;
	char detat[380];
};
////////////////////////
////////////////////////////////////////////////
////////PROTOTIPOS////////////////////
int menu();
int mod1();
int mod2();
int mod3();
void crearusuario(usuario user);
///////////////////////////////////
main(){
	FILE *vet, *auser, *amasc, *aturn;
	int opc;
	int opcmod1;
	int opcmod2;
	int opcmod3;
	usuario user;
	mascota masc[50];
	turnos turn[50];
	fecha fec[50];
	fechaturnos fect[50];
	
	opc=menu();
	switch (opc){
		case 1:{
			system ("cls");
			opcmod1=mod1();
			switch (opcmod1){
				case 1:{
					printf ("\nINICIAR SESION\n");
					break;
				}
				case 2:{
				}
			}
			break;
		}
		case 2:{
			system ("cls");
			opcmod2=mod2();
			break;
		}
		case 3:{
			system ("cls");
			opcmod3=mod3();
			switch (opcmod3){
				case 1:{
					crearusuario(user);
					break;
				}
			}
			break;
		}
	}
}
///////////////////////////////////////////
///////////////////FUNCIONES//////////////
/////////////////////////////////////////
int menu(){
	int opcion;
	printf ("/*/*/*/*/*/*/MENU PRINCIPAL/*/*/*/*/*/*/*/*/");
	printf ("\n===========================================\n");
	printf ("\n1.-Modulo consultorio veterinario\n");
	printf ("\n2.-Modulo Asistente\n");
	printf ("\n3.-Modulo recepcion\n\n");
	printf ("Opcion-> ");
	scanf ("%d",&opcion);
	return opcion;
}
///////////////////////////////////////////////////////////
int mod1(){
	int opcionmod1;
	printf ("Modulo Consultorio Veterinario");
	printf ("\n=========================\n");
	printf ("\n1.-Iniciar sesion\n");
	printf ("\n2.-Visualizar lista de espera de turnos (informe)\n");
	printf ("\n3.-Registrar evolucion de la mascota\n");
	printf ("\n4.- Cerrar la aplicacion\n");
	printf ("\nIngrese una opcion: ");
	scanf ("%d",&opcionmod1);
	return opcionmod1;
}
///////////////////////////////////////////////////////////
int mod2(){
	int opcionmod2;
	printf ("Modulo del asistente");
	printf ("\n===================\n");
	printf ("\n1.-Iniciar sesion\n");
	printf ("\n2.-Registrar mascota\n");
	printf ("\n3.-Registrar turno\n");
	printf ("\n4.-Listado de atenciones por veterinario y fecha\n");
	printf ("\n5.-Cerrar la aplicacion\n");
	printf ("\nIngrese una opcion: ");
	scanf ("%d",&opcionmod2);
	return opcionmod2;
}
///////////////////////////////////////////////////////////
int mod3(){
	int opcionmod3;
	printf ("Modulo administracion");
	printf ("\n===================\n");
	printf ("\n1.-Registrar veterinario\n");
	printf ("\n2.-Registrar usuario asistente\n");
	printf ("\n3.-Atenciones por veterinarios\n");
	printf ("\n4.-Ranking de veterinarios por atenciones\n");
	printf ("\n5.-Cerrar la aplicacion\n");
	printf ("\nIngrese una opcion: ");
	scanf ("%d",&opcionmod3);
}
//////////////////////////////////////////////////////////
void crearusuario (usuario user){
	char AB[]="aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";
	int cantcaract;
	bool F;
	system ("cls");
	do{
	printf ("\nIngrese un nuevo nombre de usuario\n");	
	_flushall();
	gets(user.usuario);
	F=true;
	cantcaract=strlen(user.usuario);
	for (int i=0;i<cantcaract;i++){
		 if(i==0 || (user.usuario[i-1]==' ')){
                for(int k=0;k<54;k=k+2){
                    if(user.usuario[i] == AB[k]){
                        F=false;
                    }
                }
            }
            else{
                for(int k=0;k<54;k=k+2){
                    if(user.usuario[i] == AB[k+1]){
                        F=false;
                    }
                }
            }
	}
	if (cantcaract<6  || cantcaract>10){
		printf ("\nIngrese nuevamente un nombre de usuario\n");
	}
	if (F==false){
		printf ("\nEl nombre de usuario debe cumplir con los requisitos");
	}
	}while (cantcaract<=6 && cantcaract>=10|| F==false);
	printf ("\nIngrese una contrasenia\n");

}
