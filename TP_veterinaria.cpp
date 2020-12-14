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
struct usuario{
	char usuario[10];
	char contrasena [20];
	char apeynom[10];
	char contpremio;
};
struct veterinario{
	char apeynomvet[10];
	int matricula;
	char contrasenia[10]; 
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
struct turno{
	int matricvet;
	fecha fect;
	int DNI_duenio;
	char detat[380];
};
////////////////////////
////////////////////////
////////PROTOTIPOS//////
int menu();
int mod1();
int mod2();
int mod3();
void crearvet(veterinario v);
void casist (usuario user);
void atencvec (veterinario v,turno t);
void rankingvet (usuario user);
void Datos (FILE *vete, veterinario v, char pass[10]);//PROTOTIPO PARA EL INICIO DE SESION EN EL CONSULTORIO
void Turnos (veterinario v, turno t, mascota masc);//PROTOTIPO PARA VER LA LISTA DE ESPERA DE TURNOS
void Evolucion (FILE *aturn, turno t);//PROTOTIPO PARA REGISTRAR LA EVOLUCION DE LA MASCOTA
///////////////////////////////////
main(){
	FILE *vete;
	FILE *auser;
	FILE *amasc;
	FILE *aturn;
	int opc;
	int opcmod1=0;
	int opcmod2=0;
	int opcmod3=0;
	usuario user;
	char pass[10];
	mascota m;
	turno t;
	fecha fec;
	veterinario v;
		do{
		opc =menu();
		system ("cls");
		switch (opc)
		{
	///////////////////////////////////////////////////////////////////////////////////MODULO CONSULTORIO
		case 1:
			{
				do{
				opcmod1 = -1;
				opcmod1 = mod1();
				system ("cls");
				switch (opcmod1)
				{
				case 1:
					{
						printf ("//Iniciar Sesion//");
						Datos (vete, v, pass);
						printf ("\n\n");
						system ("pause");
						break;
					}
				case 2:
					{
						printf ("\n//Visualizar lista de espera de turnos (Informe)//");
						Turnos (v,t,m);
						printf ("\n\n");
						system ("pause");
						break;	
					}
				case 3:
					{
						printf ("\n//Registrar Evolucion de la Mascota//");
						Evolucion (aturn , t);
						printf ("\n\n");
						system ("pause");
						break;
					}
				case 4:
					{
						printf ("\nUsted salio del Programa");
						system ("pause");
						break;
					}
				default:
				{
					printf ("\nLa Opcion ingresada es incorrecta\n");
					system ("pause");
				}
						
				}	
			 }while(opcmod1 != 4);	
			break;	
			}
			
	////////////////////////////////////////////////////////////////////////////////////MODULO ASISTENTE
		case 2:
			{	
			break;	
			}
	////////////////////////////////////////////////////////////////////////////////////MODULO ADMINISTRACI�N		
		case 3:
			{
			do{
				opcmod3 = -1;
				opcmod3=mod3();
				system ("cls");
				switch (opcmod3)
				{
				case 1:
					{	
					printf ("\n*/*/*/*/*/*/*/*/*/*/\n");
					printf("Registrar Veterinario");
					printf ("\n*/*/*/*/*/*/*/*/*/*/\n");
					crearvet(v);
					system ("pause");
					system ("cls");
					break;	
					}
				
				case 2:
					{	
					printf ("\n*/*/*/*/*/*/*/*/*/*/*/*/\n");
					printf("Registrar Usuario Asistente");
					printf ("\n*/*/*/*/**/*/**/*/*/*/*/\n");
					casist (user);
					system ("pause");
					system ("cls");
					break;	
					}
				case 3:
					{
					printf("Atenciones por Veterinarios");
					atencvec (v,t);
				    system ("pause");
				    system ("cls");
				    break;	
				  
					}
				case 4:
					{	
					printf ("Ranking de Veterinarios por Atenciones");
					rankingvet (user);
					system ("pause");
					system ("cls");
					break;
					}
				case 5:
					{	
					printf ("\nEl programa ha finalizado\n");
					system ("cls");
					break;
					}
				default:
					{
					
					printf ("\nUsted selecciono una opcion incorrecta\n");
					break;	
					}
				
				}
		
		
			}while(opcmod3 != 5);
		    break;	
	
			}
		case 4:
			{	
			printf ("\nEl programa ha finalizado\n");
			system ("cls");
			break;
			}
		default:
			{
			
			printf ("\nUsted selecciono una opcion incorrecta\n");
			system ("cls");
			break;	
			}
		
		}
	
	}while(opc != 4);
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
	return opcionmod3;
}
//////////////////////////////////////////////////////////
void crearvet (veterinario v){
	bool valido;
	FILE *vete;
	int cantnum;
			system ("cls");
			vete=fopen("Veterinarios.dat","a+b");
			printf ("\n*/*/*/*/*/*//*/*/*/*/*/*/*/*/*/\n");
			printf("Registro de veterinario");
			printf ("\n*/*/*/*/*/*//*/*/*/*/*/*/*/*/*/\n");
			printf("\nIngrese su apellido y nombre: ");
			_flushall();
			gets(v.apeynomvet);
			printf("\nIngrese numero de matricula: ");
			scanf("%d",&v.matricula);
			printf("\nIngrese contrase%ca: ",164);
			_flushall();
			gets (v.contrasenia);
			cantnum=strlen(v.contrasenia);
			valido=false;
			/////////////////////////////////////////////ESPACIO CONTRASEÑA VETERINARIO
			while (valido==false){
				if(strstr(v.contrasenia,"A")==NULL &&strstr(v.contrasenia,"B")==NULL && strstr(v.contrasenia,"C")==NULL && strstr(v.contrasenia,"D")==NULL && strstr(v.contrasenia,"E")==NULL && strstr(v.contrasenia,"F")==NULL && strstr(v.contrasenia,"G")==NULL && strstr(v.contrasenia,"H")==NULL && strstr(v.contrasenia,"I")==NULL && strstr(v.contrasenia,"J")==NULL && strstr(v.contrasenia,"K")==NULL && strstr(v.contrasenia,"L")==NULL && strstr(v.contrasenia,"M")==NULL && strstr(v.contrasenia,"N")==NULL && strstr(v.contrasenia,"O")==NULL && strstr(v.contrasenia,"P")==NULL && strstr(v.contrasenia,"Q")==NULL && strstr(v.contrasenia,"R")==NULL && strstr(v.contrasenia,"S")==NULL && strstr(v.contrasenia,"T")==NULL && strstr(v.contrasenia,"U")==NULL && strstr(v.contrasenia,"V")==NULL && strstr(v.contrasenia,"W")==NULL && strstr(v.contrasenia,"X")==NULL && strstr(v.contrasenia,"Y")==NULL && strstr(v.contrasenia,"Z")==NULL){
					printf ("La contrase%ca no posee mayuscula, ingrese de nuevo: ",164);
					gets (v.contrasenia);
				}

				
				if(strstr(v.contrasenia,"a")==NULL &&strstr(v.contrasenia,"b")==NULL && strstr(v.contrasenia,"c")==NULL && strstr(v.contrasenia,"d")==NULL && strstr(v.contrasenia,"e")==NULL && strstr(v.contrasenia,"f")==NULL && strstr(v.contrasenia,"g")==NULL && strstr(v.contrasenia,"h")==NULL && strstr(v.contrasenia,"i")==NULL && strstr(v.contrasenia,"j")==NULL && strstr(v.contrasenia,"k")==NULL && strstr(v.contrasenia,"l")==NULL && strstr(v.contrasenia,"m")==NULL && strstr(v.contrasenia,"n")==NULL && strstr(v.contrasenia,"o")==NULL && strstr(v.contrasenia,"p")==NULL && strstr(v.contrasenia,"q")==NULL && strstr(v.contrasenia,"r")==NULL && strstr(v.contrasenia,"s")==NULL && strstr(v.contrasenia,"t")==NULL && strstr(v.contrasenia,"u")==NULL && strstr(v.contrasenia,"v")==NULL && strstr(v.contrasenia,"w")==NULL && strstr(v.contrasenia,"x")==NULL && strstr(v.contrasenia,"y")==NULL && strstr(v.contrasenia,"z")==NULL)
			{
					printf("La contrase%ca no posee minuscula, ingrese de nuevo: ",164);
						_flushall;
						gets(v.contrasenia);
			}
			else
			{
						if(strstr(v.contrasenia,"0")==NULL && strstr(v.contrasenia,"1")==NULL && strstr(v.contrasenia,"2")==NULL && strstr(v.contrasenia,"3")==NULL && strstr(v.contrasenia,"4")==NULL && strstr(v.contrasenia,"5")==NULL && strstr(v.contrasenia,"6")==NULL && strstr(v.contrasenia,"7")==NULL && strstr(v.contrasenia,"8")==NULL && strstr(v.contrasenia,"9")==NULL)
						{
							printf("La contrase%ca no posee numeros, ingrese de nuevo la contrase%ca: ",164,164);
							_flushall;
							gets(v.contrasenia);
						}
				else
				{
							if(strstr(v.contrasenia,",")!=NULL && strstr(v.contrasenia,".")!=NULL && strstr(v.contrasenia,"-")!=NULL && strstr(v.contrasenia,"á")!=NULL && strstr(v.contrasenia,"é")!=NULL && strstr(v.contrasenia,"í")!=NULL && strstr(v.contrasenia,"ó")!=NULL && strstr(v.contrasenia,"ú")!=NULL && strstr(v.contrasenia,",")!=NULL && strstr(v.contrasenia,"Á")!=NULL && strstr(v.contrasenia,"É")!=NULL && strstr(v.contrasenia,"Í")!=NULL && strstr(v.contrasenia,"Ó")!=NULL && strstr(v.contrasenia,"Ú")!=NULL)
							{
								printf("La contrase%ca posee signos de puntuacion, ingrese de nuevo la contrase%ca: ",164,164);
								_flushall;
								gets(v.contrasenia);
							}
					else{
							if (cantnum>32){
								printf ("La contrase%ca es demasiado larga, ingrese nuevamente: ",164);
								_flushall();
								gets (v.contrasenia);
							}
							else{
								if (cantnum<6){
									printf ("La contrase%ca es demasiado corta, ingrese nuevamente: ",164);
									_flushall();
									gets (v.contrasenia);
								}
								else{
									for (int i=0;i<cantnum;i++){
										if((v.contrasenia[i+2]==v.contrasenia[i+1]+1) && (v.contrasenia[i+1]==v.contrasenia[i]+1)){
											printf ("No ingrese numeros ni letras consecutivos, ingrese de nuevamente: ");
											_flushall();
											gets (v.contrasenia);
											}
											else{
												valido=true;
											}
											}
											if (valido==true){
												printf ("El usuario ha sido registrado correctamente\n");
											}
							}		
						}
					}
				}
			
			}
		}
		/////////////////////////////////////////////////////FIN CONTRASEÑA VETERINARIO
	fwrite(&v,sizeof(veterinario),1,vete);
	system("pause");
	system("cls");
}

void casist (usuario user) {
	system ("cls");
	FILE *auser;
	int cantcaract;
	bool valido;
	char usuario[20];
	int cn; //contador de numeros
	int cm; //contador de mayusculas
	bool r1, r2,r3,r4,r5; //Booleanos para los requisitos propuestos en el enunciado
	auser=fopen ("asistentes.dat","a+b");
	printf ("\n*/*/*/*/*/*//*/*/*/*/*/*/*/*/*/\n");
	printf ("REGISTRO DE USUARIO ASISTENTE");
	printf ("\n*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/\n");
	printf ("\nIngrese un nombre de usuario\n");
	/////////////////////////////////////////// ESPACIO USUARIO
	_flushall();
	gets (usuario); //Se utiliza la variable usuario y no la user.usuario para poder comparar y verificar las condiciones del enunciado. Luego se la copia a la cadena del registro
	cantcaract=strlen(usuario);
	r1=false, r2=false,r3=false,r4=false,r5=false;
	while (r1==false && r2==false && r3==false && r4==false && r5==false){
		rewind (auser);
		fread (&user,sizeof(usuario),1,auser);
		while (!feof (auser)){
			if (strcmp(usuario,user.usuario)==0){
				printf ("Nombre de usuario ya existente, por favor ingrese nuevamente: ");
				gets (usuario);
				r1==false;
				printf ("r1 falso");
		}
		else{
			r1==true;
			printf ("r1 verdadero");
		}
			fread (&user,sizeof(usuario),1,auser);
				}		
		//////////////////////////////////////////////////////////////////////////////////////FIN R1
		if (usuario[0]=='a' ||	usuario[0]=='b' || usuario[0]=='c' || usuario[0]=='d' || usuario[0]=='e' || usuario[0]=='f' || usuario[0]=='g' || usuario[0]=='h' || usuario[0]=='i' || usuario[0]=='j' || usuario[0]=='k' || usuario[0]=='l' || usuario[0]=='m' || usuario[0]=='n' || usuario[0]=='o' || usuario[0]=='p' || usuario[0]=='q' || usuario[0]=='r' || usuario[0]=='s' || usuario[0]=='t' || usuario[0]=='u' || usuario[0]=='v' || usuario[0]=='w' || usuario[0]=='x' || usuario[0]=='y' || usuario[0]=='z'){
			r2==true;
			printf ("r2 verdadero");
			}
			else{
				r2==false;
				printf ("El nombre de usuario debe comenzar con minuscula, ingrese nuevamente: ");
				gets (usuario);
			}
		//////////////////////////////////////////////////////////////////////////////////////FIN R2
		for (int i=0;i<20;i++){
		if (usuario[i]=='A' ||	usuario[i]=='B' || usuario[i]=='C' || usuario[i]=='D' || usuario[i]=='E' || usuario[i]=='F' || usuario[i]=='G' || usuario[i]=='H' || usuario[i]=='I' || usuario[i]=='J' || usuario[i]=='K' || usuario[i]=='L' || usuario[i]=='M' || usuario[i]=='N' || usuario[i]=='O' || usuario[i]=='P' || usuario[i]=='Q' || usuario[i]=='R' || usuario[i]=='S' || usuario[i]=='T' || usuario[i]=='U' || usuario[i]=='V' || usuario[i]=='W' || usuario[i]=='X' || usuario[i]=='Y' || usuario[i]=='Z'){
			cm++;			
		}
		}
		if (cm<2){
			r3==false;
			printf ("El nombre de usuario debe tener 2 mayusculas o mas, ingrese nuevamente: ");
			gets (usuario);
		}
		else{
			r3==true;
			printf ("r3 verdadero");
		}
		///////////////////////////////////////////////////////////////////////////////////// FIN R3
	
		
				if (cn>3){
						printf ("Error. El numero maximo de numeros permitidos es 3,ingrese nuevamente");
						gets (usuario);
						r4=false;
					}
					else{
						r4=true;
						printf ("r4 verdadero");
					}
	///////////////////////////////////////////////////////////////////////////////////////////////////////FIN R4
					if (cantcaract>10 || cantcaract<6){
						r5==false;
						printf ("El tama%co del nombre no es valido, este tiene que ser menor a 10 y mayor a 6 caracteres");
						gets (usuario);
					}
					else{
						r5==true;
						printf ("r5 verdadero");
					}
		
/////////////////////////////////////////////////////////////FIN R5

/////////////////////////////////////////////////////////////ESPACIO CONTRASEÑA
printf ("Ingrese contrase%ca: ",164);
_flushall();
gets (user.contrasena);
valido=false;
	while (valido==false){
				if(strstr(user.contrasena,"A")==NULL && strstr(user.contrasena,"B")==NULL && strstr(user.contrasena,"C")==NULL && strstr(user.contrasena,"D")==NULL && strstr(user.contrasena,"E")==NULL && strstr(user.contrasena,"F")==NULL && strstr(user.contrasena,"G")==NULL && strstr(user.contrasena,"H")==NULL && strstr(user.contrasena,"I")==NULL && strstr(user.contrasena,"J")==NULL && strstr(user.contrasena,"K")==NULL && strstr(user.contrasena,"L")==NULL && strstr(user.contrasena,"M")==NULL && strstr(user.contrasena,"N")==NULL && strstr(user.contrasena,"O")==NULL && strstr(user.contrasena,"P")==NULL && strstr(user.contrasena,"Q")==NULL && strstr(user.contrasena,"R")==NULL && strstr(user.contrasena,"S")==NULL && strstr(user.contrasena,"T")==NULL && strstr(user.contrasena,"U")==NULL && strstr(user.contrasena,"V")==NULL && strstr(user.contrasena,"W")==NULL && strstr(user.contrasena,"X")==NULL && strstr(user.contrasena,"Y")==NULL && strstr(user.contrasena,"Z")==NULL){
					printf ("La contrase%ca no posee mayuscula, ingrese de nuevo: ",164);
					gets (user.contrasena);
				}

				
				if(strstr(user.contrasena,"a")==NULL && strstr(user.contrasena,"b")==NULL && strstr(user.contrasena,"c")==NULL && strstr(user.contrasena,"d")==NULL && strstr(user.contrasena,"e")==NULL && strstr(user.contrasena,"f")==NULL && strstr(user.contrasena,"g")==NULL && strstr(user.contrasena,"h")==NULL && strstr(user.contrasena,"i")==NULL && strstr(user.contrasena,"j")==NULL && strstr(user.contrasena,"k")==NULL && strstr(user.contrasena,"l")==NULL && strstr(user.contrasena,"m")==NULL && strstr(user.contrasena,"n")==NULL && strstr(user.contrasena,"o")==NULL && strstr(user.contrasena,"p")==NULL && strstr(user.contrasena,"q")==NULL && strstr(user.contrasena,"r")==NULL && strstr(user.contrasena,"s")==NULL && strstr(user.contrasena,"t")==NULL && strstr(user.contrasena,"u")==NULL && strstr(user.contrasena,"v")==NULL && strstr(user.contrasena,"w")==NULL && strstr(user.contrasena,"x")==NULL && strstr(user.contrasena,"y")==NULL && strstr(user.contrasena,"z")==NULL)
			{
					printf("La contrase%ca no posee minuscula, ingrese de nuevo: ",164);
						_flushall;
						gets(user.contrasena);
			}
			else
			{
						if(strstr(user.contrasena,"0")==NULL && strstr(user.contrasena,"1")==NULL && strstr(user.contrasena,"2")==NULL && strstr(user.contrasena,"3")==NULL && strstr(user.contrasena,"4")==NULL && strstr(user.contrasena,"5")==NULL && strstr(user.contrasena,"6")==NULL && strstr(user.contrasena,"7")==NULL && strstr(user.contrasena,"8")==NULL && strstr(user.contrasena,"9")==NULL)
						{
							printf("La contrase%ca no posee numeros, ingrese de nuevo la contrase%ca: ",164,164);
							_flushall;
							gets(user.contrasena);
						}
				else
				{
							if(strstr(user.contrasena,",")!=NULL && strstr(user.contrasena,".")!=NULL && strstr(user.contrasena,"-")!=NULL && strstr(user.contrasena,"á")!=NULL && strstr(user.contrasena,"é")!=NULL && strstr(user.contrasena,"í")!=NULL && strstr(user.contrasena,"ó")!=NULL && strstr(user.contrasena,"ú")!=NULL && strstr(user.contrasena,",")!=NULL && strstr(user.contrasena,"Á")!=NULL && strstr(user.contrasena,"É")!=NULL && strstr(user.contrasena,"Í")!=NULL && strstr(user.contrasena,"Ó")!=NULL && strstr(user.contrasena,"Ú")!=NULL)
							{
								printf("La contrase%ca posee signos de puntuacion, ingrese de nuevo la contrase%ca: ",164,164);
								_flushall;
								gets(user.contrasena);
							}
					else{
							if (strlen(user.contrasena)>32){
								printf ("La contrase%ca es demasiado larga, ingrese nuevamente: ",164);
								_flushall();
								gets (user.contrasena);
							}
							else{
								if (strlen (user.contrasena)<6){
									printf ("La contrase%ca es demasiado corta, ingrese nuevamente: ",164);
									_flushall();
									gets (user.contrasena);
								}
								else{
									for (int i=0;i<strlen(user.contrasena);i++){
										if((user.contrasena[i+2]==user.contrasena[i+1]+1) && (user.contrasena[i+1]==user.contrasena[i]+1)){
											printf ("No ingrese numeros ni letras consecutivos, ingrese de nuevamente: ");
											_flushall();
											gets (user.contrasena);
											}
											else{
												valido=true;
											}
											}
											if (valido==true){
												printf ("El usuario ha sido registrado correctamente\n");
											}
							}		
						}
					}
				}
			
			}
			}
		}

		}
//////////////////////////////////////////////////////////////FUNCION ATENCION VETERINARIO
void atencvec (veterinario v,turno t){
	FILE *aturn;
	FILE *vete;
	vete=fopen ("Veterinarios.dat", "r+b");
	aturn=fopen ("turnos.dat","r+b");
	int ct=0; //Contador de turnos;
	char at[25];
	printf ("\n*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*\n");
	printf ("\n*/*/*/*/*//*/*/*/*/Atenciones por veterinarios*/*/*/*/*/*/*/*/*\n");
	printf ("\n/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*\n");
	printf ("\nIngrese el veterinario para el cual quiere consultar: ");
	_flushall();
	gets (at);
	fread (&v,sizeof (veterinario),1,vete);
	fread (&t,sizeof (turno),1,aturn);
	while (!feof (vete) && !feof (aturn)){
		if (strcmp (at,v.apeynomvet)==0){
			if (t.matricvet==v.matricula){
				printf ("\n*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/\n");
				printf ("\n/*/*/*/*/*/*/CARGA DE TURNOS DE VETERINARIO/*/*/*/*/*/*/\n");
				printf ("\n*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*\n");
				printf ("\nTurno [%d]\n",ct);
				ct++;
				printf ("\n*/*/*/*/*/*/*/Fecha de turno/*/*/*/*/*/*/*/\n");
				printf ("\nDia [%d]",t.fect.dia);
				printf ("\nMes [%d]",t.fect.mes);
				printf ("\nA%co [%d]",164,t.fect.anio);
				printf ("\nDNI del due%co [%d]",164,t.DNI_duenio);
				fread (&v,sizeof(veterinario),1,vete);
				fread (&t,sizeof(turno),1,aturn);
				
			}
			else{
				fread (&v,sizeof(veterinario),1,vete);
				fread (&t,sizeof(turno),1,aturn);
			}
		}
		else{
			fread (&v,sizeof(veterinario),1,vete);
			fread (&t,sizeof(turno),1,aturn);
		}
	}
	system ("pause");
}
///////////////////////////////////////////////////////////////////////////////////
void rankingvet (usuario user){
	char umay[30];
	int may=0;
	FILE *auser;
	system ("cls");
	printf ("\n/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/\n");
	printf ("/*/*/*/*/*/*/*/*/*/RANKING DE VETERINARIOS/*/*/*/*/*/*/*/");
	printf ("\n/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*\n");
	rewind (auser);
	fread (&user,sizeof (usuario),1,auser);
	while (!feof (auser)){
		if (user.contpremio>may){
			may=user.contpremio;
			strcpy (user.apeynom,umay);
		}
		fread (&user,sizeof(usuario),1,auser);
	}
	printf ("\nEl veterinario que registro mas mascotas es: [%s] con [%d] mascotas registradas",umay,may);
	system ("pause");
}
///////////////////////////////////////////////////////////////////////////////// FUNCIONES REY
void Datos (FILE *vete, veterinario v, char pass[10])
{

   	int op, matri;
	bool band;	
			vete = fopen("Veterinarios.dat","r+b");
			system("cls");
			printf("//Inicio de Sesion//");
			printf("\nIngrese su matricula: ");
			scanf("%d",&matri);
			rewind (vete);
			fread(&v,sizeof(veterinario),1,vete);
			band=false;
			while(band==false)
			{
				while(!feof(vete))
				{
					if(matri == v.matricula)
					{
						band=true;
						fread(&v,sizeof(veterinario),1,vete);
					}
					else
					{
						fread(&v,sizeof(veterinario),1,vete);
					}
				
				}
				if(band==false)
				{
					printf("\nLa Matricula ingresada es incorrecta, por favor vuelva a ingresarla: ");
					scanf("%d",&matri);
				}
				
			}
			printf("\nMatricula Correcta//");
			printf ("\nIngrese su contrase�a: ");
			_flushall();
			gets(pass);
			rewind(vete);
			fread(&v,sizeof(veterinario),1,vete);
			band=false;
			while(band==false)
			{
				while(!feof(vete))
				{
					if(strcmp(pass,v.contrasenia)==0)
					{
						band=true;
						fread(&v,sizeof(veterinario),1,vete);
					}
					else
					{
						fread(&v,sizeof(veterinario),1,vete);
					}
				}
				if(band==false)
				{
					printf("\nLa Contrase�a Ingresada es incorrecta, por favor ingrese su contrase�a de nuevo: ");
					_flushall();
					gets(pass);
				}
			}
			
			printf("\nContrase�a Correcta\nSesion iniciada con exito!");
			fclose(vete);
			system("pause");
			system("cls");
			printf("Ingrese su proxima operacion: \n\n2-Visualizar lista de espera de mascotas \n3-Registrar evolucion de los mascotas\n\n4-Salir del programa");
			printf("\nOpcion: ");
			scanf("%d",&op);
			fclose (vete);
			
}

void Turnos (veterinario v, turno t, mascota masc)
{				

				FILE *aturn;
				FILE *vete;
				FILE *amasc;
				aturn=fopen("turnos.dat","r+b");
				vete=fopen("Veterinarios.dat","r+b");
				amasc=fopen("Mascotas.dat","r+b");
				int i=0;
                int op;
				
				system("cls");
				printf("//LISTA DE ESPERA DE MASCOTAS//");
				printf ("\n\n");
				
				fread(&v,sizeof(veterinario),1,vete);
				fread(&t,sizeof(turno),1,aturn);
				fread(&masc,sizeof(mascota),1,amasc);
				while(!feof(vete)||!feof(aturn)||!feof(amasc))
				{
					if(v.matricula==t.matricvet)
					{
						printf("\nTurno %d:",i+1);
						printf("\nFecha:");
						printf("\n\nDia: %d",t.fect.dia);
						printf("\nMes: %d",t.fect.mes);
						printf("\nA%co: %d",164,t.fect.anio);
						printf("\nDNI del due�o: %d", t.DNI_duenio);
						printf("\nNombre y apellido: %s", masc.apeynommasc);
						printf("\nEdad: %d a%cos",t.fect.anio, 164);
						printf("\nLocalidad: ");
						puts(masc.localidad);
						printf("\nPeso: %.2f",masc.peso);
						
						fread(&v,sizeof(veterinario),1,vete);
						fread(&t,sizeof(turno),1,aturn);
						fread(&masc,sizeof(mascota),1,amasc);
					}
					else
					{
						fread(&v,sizeof(veterinario),1,vete);
						fread(&t,sizeof(turno),1,aturn);
						fread(&masc,sizeof(mascota),1,amasc);
					}
				}
				
				fclose(vete);
				fclose(aturn);
				fclose(amasc);
				printf("\n\n");
				system("pause");
				system("cls");
}
void Evolucion (FILE *aturn, turno t)	
{
	int opc;
	
    aturn = fopen("turnos.dat","a+b");
    _flushall();
    printf("\nRegistre la evolucion de la mascota: ");
	gets(t.detat);
	fwrite(&t, sizeof(turno), 1,aturn);
	system("pause");
	system("cls");
}


