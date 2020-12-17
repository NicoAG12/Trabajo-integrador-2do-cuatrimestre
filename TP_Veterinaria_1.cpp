#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
/*

****2DO TRABAJO INTEGRADOR ALGORITMOS Y ESTRUCTURA DE DATOS****

*Integrantes*

-Acosta Berral,Javier Emiliano
-Agüero, Nicolás Javier
-Albarracín, Facundo Gabriel

*/

/////////////////////////////
////REGISTROS///////////////
///////////////////////////
struct fecha
{
    int dia;
    int mes;
    int anio;
};

struct usuario
{
    char usuario[60];
    char contrasena[60];
    char apeynom[60];
    int contpremio;
    
};

struct veterinario
{
    char apeynomvet[60];
    int matricula;
    char contrasenia[10]; 
    int DNI;
    char telefono[25];
    int cp;
};

struct turno
{
    int matricvet;
    fecha fect;
    int dni;
    char detalle[380];
    char ayn[60];
};

struct mascota
{
    char apeynommasc[60];
    char domicilio[60];
    int dni;
    char localidad[60];
    fecha fecnacimiento;
    int peso;
    char telefonomasc[25];
};
////////////////////////////////////
//////////PROTOTIPOS///////////////
//////////////////////////////////
int menu();
int mod1();
int mod2();
int mod3();
void crearvet(veterinario v);
void casist (usuario user);
void atencvec (veterinario v,turno t);
void rankingvet (veterinario v ,turno t);
///////////////////////////////////////
int Datos (FILE *vete, veterinario v, char pass[10]);//PROTOTIPO PARA EL INICIO DE SESION EN EL CONSULTORIO
void Turnos (veterinario v, turno t, mascota masc);//PROTOTIPO PARA VER LA LISTA DE ESPERA DE TURNOS
void Evolucion (FILE *atur, turno t);//PROTOTIPO PARA REGISTRAR LA EVOLUCION DE LA MASCOTA
//////////////////////////////////////////////////
void iniciosesion (usuario user); //PROTOTIPO PARA INICIO DE SESION
void regmascotas (mascota m); // PROTOTIPO DE REGISTRO DE MASCOTAS
void turnos (turno t); // PROTOTIPO PARA REGISTRAR TURNOS
void listadoatencion (turno t, mascota m, veterinario v); //PROTOTIPO PARA LISTAR ATENCIONES POR VETERINARIO Y FECHA

////////////////////////////////////
/////////////MAIN//////////////////
///////////////////////////////////
main ()
{
	system ("color 9E");
	printf ("\n\t\t/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/\n");
	printf ("\n\t\t/*/*/*/*/*/*/*/*/*/*/BIENVENIDO A VETERINARIA PERRAL*/*/*/*/*/*/*/*/*/*/*/\n");
	printf ("\n\t\t/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/\n");
	printf ("\n\n\n\n\n");
	system("pause");
	system("cls");
	FILE *vete;
	FILE *amasc;
	FILE *atur;
	FILE *auser;
	int matrix;
	int opc=-1;
	int opcmod1=-1;
	int opcmod2=-1;
	int opcmod3=-1;
	char auvet[80];	
	char pass [10];	
	usuario user;
	mascota m;
	turno t;
	fecha fec;
	veterinario v;
	bool inisec = false;
	do{	
		opc=menu();
		system ("cls");
		switch(opc)
		{
		case 1: 
		{	
			do
			{
				///////////////////////////////////////////////////MODULO DE CONSULTORIO
				opcmod1 = mod1();
				system ("cls");
				switch(opcmod1)
				{
					
					case 1:
					{
						printf ("\nIniciar sesion\n");
						matrix = Datos (vete , v , pass);
						system("pause");
						break;
					}
					case 2: 
					{
						printf("\nVisualizar Lista de Espera de Turnos\n");
						Turnos (v, t, m);
						system("pause");
						break;
					}
					case 3:
					{
						printf("\nRegistrar Evolución de la Mascota\n");
						Evolucion (atur , t);
						system("pause");
						break;
					}
					case 4:
					{
						printf("\nEl programa finalizo\n");
						system("pause");
						system ("cls");
						break;
					}
					default :
					{
						printf("Opcion seleccionada incorrecta");
						system("pause");
						break;
					}
				
				}
	
			}while(opcmod1 !=4);
			
			break;
		}
		///////////////////////////////////////////////////MODULO ASISTENTE
		case 2:
		{
			do
			{
				
				opcmod2 = mod2();
				system("cls");
				switch (opcmod2)
				{
				
				case 1:
				{
					printf("\n*/*/*/*/*/*/Iniciar Sesion/*/*/*/*/*/*/*/\n");
					iniciosesion(user);
					bool inisec = false;
					system("pause");
					break;
					
				}	
				case 2:
				{
					printf("\nRegistrar Mascota\n");
					regmascotas(m);
					system("pause");
					break;
				}
				case 3:
				{
					printf("\nRegistrar Turno\n");
					turnos(t);
					system("pause");
					break;
				}
				case 4:
				{
					printf("\nListado de Atenciones por Veterinario y Fecha\n");
					listadoatencion(t,m,v);
					system("pause");
					break;
				}

				case 5:
				{
					printf("\nEl programa finalizo\n");
					system("pause");
			 		system ("cls");
					break;
				}
				default :
				{
					printf("Opcion seleccionada incorrecta");
					system("pause");
					break;
				}
				
			}
			
			
				
			}while(opcmod2 !=5);
			break;
		}
		///////////////////////////////////////////////MODULO ADMINISTRACION
		case 3:
		{
			do
			{
				
				opcmod3 = mod3();
				system ("cls");
				switch(opcmod3)
				{
					
					case 1:
					{
						printf("\nRegistrar Veterinario\n"); 
						crearvet(v);
						system("pause");
						break;
					}
					case 2:
					{
						printf("\nRegistrar Usuario Asistente\n");
						casist(user);
						system("pause");
						break;
					}
					case 3:
					{
						printf("\nAtenciones por Veterinarios\n");
						atencvec(v,t);
						system("pause");
						break;
					}
					case 4:
					{
						printf("\nRanking de Veterinarios por Atenciones\n");
						rankingvet(v ,t);
						system("pause");
						break;
					}
					case 5:
					{
						printf("\nEl programa finalizo\n");
						system("pause");
						system ("cls");
						break;
					}					
					default :
					{
						printf("Opcion seleccionada incorrecta");
						system("pause");
						break;
					}
				}
				
			}while(opcmod3 !=5);
			
			break;
		}
		case 4:
		{
			printf("\nEl programa se cerro\n");
			system("pause");
			break;
		} 
		default :
		{
			printf("Opcion seleccionada incorrecta");
			system("pause");
			break;
		}	
		}
	 
	
	
	}while(opc!= 4);
}
///////////////////////////////////////////
///////////////////FUNCIONES//////////////
/////////////////////////////////////////
int menu ()
{
    int opcion=-1;
    printf ("/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/\n");
    printf("/*/*/*/*/*/*/*/*Menu principal/*/*/*/*/*/*/*/*/\n");
    printf ("/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/\n");
    printf("\n1-Modulo Consultorio Veterinario\n\n");
    printf("\n2-Modulo del asistente\n\n");
    printf("\n3-Modulo Administracion\n\n");
    printf("\n4-Cerrar el programa\n\n");
    printf("\nIngrese la opcion: ");
    scanf("%d", &opcion);
    return opcion;

}
///////////////////////////////////////////////////////////

int mod1()
{
	system("color 7C");
    int opcionmod1=-1;
	printf ("/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*//*/*/*/*/\n");
    printf("/*/*/*/*/*/*/*/*/Menu Consultorio Veterinario/*/*/*/*/*/*/*/\n");
    printf ("/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/\n");
    printf("\n\n1-Iniciar Sesion\n\n");
    printf("\n\n2-Visualizar Lista de espera de turnos\n\n");
    printf("\n\n3-Registrar Evolucion de la mascota\n\n");
    printf("\n\n4-Cerrar el programa\n\n");
    printf("\nIngrese la opcion: ");
    scanf("%d", &opcionmod1);
   	/*while(opcionmod1!=1&&opcionmod1!=4){    //Mientras la opcion sea distinta a 1(iniciar ss) o 4 (salir), se muestra una advertencia.
    printf("Debe iniciar sesion para realizar una accion, por favor escoja la opcion 1: ");
      scanf("%d",&opcionmod1);
    }*/
	return opcionmod1;
}
///////////////////////////////////////////////////////////

int mod2()
{
	system("color 4F");
	int opcionmod2=-1;
	printf ("/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/**\n");
	printf("/*/*/*/*/*/*/*/*/*/Menu del asistente*/*/*/*/*/*/*/*/*/\n");
	printf ("/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/\n");
	printf("\n\n1-Iniciar sesion\n\n");
	printf("\n\n2-Registrar mascota\n\n");
	printf("\n\n3-Registrar turno\n\n");
	printf("\n\n4-Listado de atenciones por veterinario y fecha\n\n");
	printf("\n\n5-Cerrar la aplicacion\n\n");
	printf("\nIngrese la opcion: ");
	scanf("%d", &opcionmod2);	
	/*while(opcionmod2!=1&&opcionmod2!=5)//Mientras la opcion sea distinta a 1(iniciar ss) o 5 (salir), se muestra una advertencia.
	{    
	printf("\nDebe iniciar sesion para realizar una accion, por favor escoja la opcion 1 (para iniciar sesion) o 5 (para salir):  ");
	scanf("%d",&opcionmod2);
	}*/
	return opcionmod2;
}
///////////////////////////////////////////////////////////

int mod3()
{
	system("color 5F");
	int opcionmod3=1;
	printf ("/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/\n");
	printf("/*/*/*/*/*/*Modulo Administracion/*/*/*/*/*/*/*/*/\n");
	printf ("/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/\n");
	printf("\n\n1-Registrar veterinario\n\n");
	printf("\n\n2-Registrar usuario asistente\n\n");
	printf("\n\n3-Atenciones por veterinarios\n\n");
	printf("\n\n4-Ranking de veterinarios por atenciones\n\n");
	printf("\n\n5-Cerrar la aplicacion\n\n");
	printf("\nIngrese una opcion: ");
	scanf("%d", &opcionmod3);
	return opcionmod3;
}
/////////////////////////////////////////////////////////// FUNCIONES NICO
void crearvet(veterinario v)
{
	FILE *vete;
	system("cls");
	int aceptar=false;
	vete = fopen("Veterinarios.dat", "r+b");
	printf("Registrar al veterinario\n");
	printf ("\n===========================================\n");
	printf("Ingrese el nombre y apellido del veterinario: \n");
	printf ("==========================================\n");
	_flushall();
	gets(v.apeynomvet);
	printf ("\n==================================\n");
	printf("\nIngrese la matricula: ");
	printf ("\n==================================\n");
	scanf("%d", &v.matricula);
	
	printf("\nIngrese la contrase%ca para el veterinario, debe cumplir con las siguientes caracteristicas: \n1) Poseer al menos, una letra mayuscula, una minuscula y un numero\n2) No debe poseer caracteres de puntuacion\n3) De entre al menos 6 y 32 caracteres\nd) No debe tener mas de 3 numeros consecutivos\n4) No debe contener 2 caracteres onsecutivos \nIngrese contrase%ca\n"),164,164;
	_flushall();
	gets(v.contrasenia);
	aceptar=false;
		while(aceptar==false){
		
				if(strstr(v.contrasenia,"A")==NULL &&strstr(v.contrasenia,"B")==NULL && strstr(v.contrasenia,"C")==NULL && strstr(v.contrasenia,"D")==NULL && strstr(v.contrasenia,"E")==NULL && strstr(v.contrasenia,"F")==NULL && strstr(v.contrasenia,"G")==NULL && strstr(v.contrasenia,"H")==NULL && strstr(v.contrasenia,"I")==NULL && strstr(v.contrasenia,"J")==NULL && strstr(v.contrasenia,"K")==NULL && strstr(v.contrasenia,"L")==NULL && strstr(v.contrasenia,"M")==NULL && strstr(v.contrasenia,"N")==NULL && strstr(v.contrasenia,"O")==NULL && strstr(v.contrasenia,"P")==NULL && strstr(v.contrasenia,"Q")==NULL && strstr(v.contrasenia,"R")==NULL && strstr(v.contrasenia,"S")==NULL && strstr(v.contrasenia,"T")==NULL && strstr(v.contrasenia,"U")==NULL && strstr(v.contrasenia,"V")==NULL && strstr(v.contrasenia,"W")==NULL && strstr(v.contrasenia,"X")==NULL && strstr(v.contrasenia,"Y")==NULL && strstr(v.contrasenia,"Z")==NULL)
				{
					printf("\nLa contrasenia no posee mayuscula, ingrese de nuevo la contrasenia: ");
					_flushall;
					gets(v.contrasenia);
				}
				else
				{
					if(strstr(v.contrasenia,"a")==NULL &&strstr(v.contrasenia,"b")==NULL && strstr(v.contrasenia,"c")==NULL && strstr(v.contrasenia,"d")==NULL && strstr(v.contrasenia,"e")==NULL && strstr(v.contrasenia,"f")==NULL && strstr(v.contrasenia,"g")==NULL && strstr(v.contrasenia,"h")==NULL && strstr(v.contrasenia,"i")==NULL && strstr(v.contrasenia,"j")==NULL && strstr(v.contrasenia,"k")==NULL && strstr(v.contrasenia,"l")==NULL && strstr(v.contrasenia,"m")==NULL && strstr(v.contrasenia,"n")==NULL && strstr(v.contrasenia,"o")==NULL && strstr(v.contrasenia,"p")==NULL && strstr(v.contrasenia,"q")==NULL && strstr(v.contrasenia,"r")==NULL && strstr(v.contrasenia,"s")==NULL && strstr(v.contrasenia,"t")==NULL && strstr(v.contrasenia,"u")==NULL && strstr(v.contrasenia,"v")==NULL && strstr(v.contrasenia,"w")==NULL && strstr(v.contrasenia,"x")==NULL && strstr(v.contrasenia,"y")==NULL && strstr(v.contrasenia,"z")==NULL)
					{
						printf("\nLa contrase&ca no posee minuscula, ingrese nuevamente: ",164);
						_flushall;
						gets(v.contrasenia);
					}
					else
					{
						if(strstr(v.contrasenia,"0")==NULL && strstr(v.contrasenia,"1")==NULL && strstr(v.contrasenia,"2")==NULL && strstr(v.contrasenia,"3")==NULL && strstr(v.contrasenia,"4")==NULL && strstr(v.contrasenia,"5")==NULL && strstr(v.contrasenia,"6")==NULL && strstr(v.contrasenia,"7")==NULL && strstr(v.contrasenia,"8")==NULL && strstr(v.contrasenia,"9")==NULL)
						{
							printf("\nLa contrase%ca no posee numeros, ingrese nuevamente: ",164);
							_flushall;
							gets(v.contrasenia);
						}
						else
						{
							if(strstr(v.contrasenia,",")!=NULL && strstr(v.contrasenia,".")!=NULL && strstr(v.contrasenia,"-")!=NULL && strstr(v.contrasenia,"á")!=NULL && strstr(v.contrasenia,"é")!=NULL && strstr(v.contrasenia,"í")!=NULL && strstr(v.contrasenia,"ó")!=NULL && strstr(v.contrasenia,"ú")!=NULL && strstr(v.contrasenia,",")!=NULL && strstr(v.contrasenia,"Á")!=NULL && strstr(v.contrasenia,"É")!=NULL && strstr(v.contrasenia,"Í")!=NULL && strstr(v.contrasenia,"Ó")!=NULL && strstr(v.contrasenia,"Ú")!=NULL)
							{
								printf("\nLa contrase%ca posee signos de puntuacion, ingrese nuevamente: ",164);
								_flushall;
								gets(v.contrasenia);
							}
							else
							{
								if(strlen(v.contrasenia)<6) 
								{
									printf("\nLa contrase%ca es muy corta, ingrese nuevamente: ",164);
									_flushall;
									gets(v.contrasenia);
								}
								else
								{
									if(strlen(v.contrasenia)>32)
									{
										printf("\nLa contrase%ca es muy larga, ingrese nuevamente ",164);
										_flushall;
										gets(v.contrasenia);
									}
									else
									{
										for(int i=0;i<strlen(v.contrasenia);i++)
										{
											if((v.contrasenia[i+2]==v.contrasenia[i+1]+1) && (v.contrasenia[i+1]==v.contrasenia[i]+1))
											{
												printf("\nNo ingrese numeros ni letras consecutivos, ingrese nuevamente: ");
												_flushall();
												gets(v.contrasenia);
											}
											else
											{
												aceptar=true;
											}
										}								
										if(aceptar==true)
										{
											printf("\nContrase%ca aceptada\n",164);
											
										}
									}
								}
							}
						}
					}
				}
			}
	
	printf("\nIngrese el DNI: ");
	scanf("%d", &v.DNI);
	
	printf("\nIngrese el numero de telefono: ");
	_flushall();
	gets(v.telefono);
	fwrite (&v,sizeof(veterinario),1,vete);

	
	system("cls");
	
}
///////////////////////////////////////////////////////////
void casist (usuario user)
{
	FILE *auser;
		char auxuser [30];
		int aceptar;
		int cm,cn;
		auser = fopen("Usuarios.dat" , "a+b");
		bool r1=false, r2=false, r3=false, r4=false, r5=false;
		printf("\nRegistrar al usuario\n");
		printf("\nIngrese el nombre del usuario\n\nCondiciones:\n1-Tiene que comenzar con minuscula\n2-Tener al menos dos mayusculas\n3-No mas de tres digitos:\n");
		_flushall();
		gets(auxuser);
		while(r1==false && r2==false && r3==false && r4==false && r5==false)
		{
			
			if(auxuser[0]=='a' || auxuser[0]=='b' || auxuser[0]=='c' || auxuser[0]=='d' ||  auxuser[0]=='e' ||  auxuser[0]=='f' ||  auxuser[0]=='g' || auxuser[0]=='h' || auxuser[0]=='i' ||  auxuser[0]=='j' || auxuser[0]=='k' ||  auxuser[0]=='l' ||  auxuser[0]=='m' ||  auxuser[0]=='n' ||  auxuser[0]=='o' ||  auxuser[0]=='p' ||  auxuser[0]=='q' || auxuser[0]=='r' ||  auxuser[0]=='s' ||  auxuser[0]=='t' || auxuser[0]=='u'  || auxuser[0]=='v' ||  auxuser[0]=='w' ||  auxuser[0]=='x' ||  auxuser[0]=='y' ||  auxuser[0]=='z')
			{
				r2=true;
			}
			else
			{
				r2=false;
				printf("\nEl nombre que ingreso no comienza con minuscula, ingrese otro: ");
				gets(auxuser);
				
			}
			for(int i=0;i<20;i++)
			{
            	if(auxuser[i]=='A' || auxuser[i]=='B' || auxuser[i]=='C' || auxuser[i]=='D' || auxuser[i]=='E' || auxuser[i]=='F' || auxuser[i]=='G' || auxuser[i]=='H' || auxuser[i]=='I' || auxuser[i]=='J' || auxuser[i]=='K' || auxuser[i]=='L' || auxuser[i]=='M' || auxuser[i]=='N' || auxuser[i]=='O' || auxuser[i]=='P' || auxuser[i]=='Q' || auxuser[i]=='R' || auxuser[i]=='S' || auxuser[i]=='T' || auxuser[i]=='U' || auxuser[i]=='V' || auxuser[i]=='W' || auxuser[i]=='X' || auxuser[i]=='Y'||auxuser[i]=='Z')
				{
					cm++;
                }
                
            }
            if(cm<2)
			{
				printf("\nNo posee 2 mayusculas o mas, Ingrese otro:  ");
				gets(auxuser);	
				r3=false;
			}
			else
			{
				r3=true;
			}
			for(int i=0;i<20;i++)
			{
						if(auxuser[i]=='1')
						{
							cn++;
						}
						else
						{
							if(auxuser[i]=='2')
							{
								cn++;
							}
							else
							{
								if(auxuser[i]=='3')
								{
									cn++;
								}
								else
								{
									if(auxuser[i]=='4'){
										cn++;	
						   			}
						   			else
									   {
						   				if(auxuser[i]=='5')
										   {
						   					cn++;
									    	}
									    else
										{
									    	if(auxuser[i]=='6')
											{
									    		cn++;
											}
											else{
												if(auxuser[i]=='7')
												{
													cn++;
												}
												else
												{
													if(auxuser[i]=='8')
													{
														cn++;
													}
													else
													{
														if(auxuser[i]=='9')
														{
															cn++;
														}
														else
														{
															if(auxuser[i]=='0')
															{
																cn++;
															}
														}
													}
												}
											}
										}
								    }
								}
							}
						}
			}
			if(cn>3)
			{
				printf("\nEl maximo de digitos permitidos es 3, Ingresar de nuevo: ");
				gets(auxuser);
				
				r4=false;
			}
			else
			{
				r4 = true;
			}
			if(strlen(auxuser)>10 && strlen(auxuser)<6)
			{
				printf("\nEl tamanio del nombre no es valido, por favor digite otro: ");
				gets(auxuser);
				r5=false;
			}
			else
			{
				r5=true;
			}
			rewind(auser);
			fread(&user,sizeof(usuario),1,auser);
			while(!feof(auser))
			{
				if(strcmp(auxuser,user.usuario)==0)
				{
					printf("\nUsuario existente, ingrese otro\n");
					gets(auxuser);
					r1=false;
					fread(&user,sizeof(usuario),1,auser);
				}
				else
				{
					r1=true;
					fread(&user,sizeof(usuario),1,auser);
				}
			}	
			
			printf("\nIngrese la contrase%ca para el usuario\n",164);
			printf ("Caracteristicas de nombre a cumplir: \n)Poseer una letra mayuscula, una minuscula y un numero \n2) No poseer caracteres de puntucion \n3)Tiene que tener entre 6 y 32 caracteres \n4)No debe tener mas de 3 numeros consecutivos \n5) No debe contener 2 caracteres consecutivos");
			_flushall();
			printf ("\n");
			gets(user.contrasena);
			aceptar = false;
			while(aceptar==false)
			{
				if(strstr(user.contrasena,"Q")==NULL && strstr(user.contrasena,"W")==NULL && strstr(user.contrasena,"E")==NULL && strstr(user.contrasena,"R")==NULL && strstr(user.contrasena,"T")==NULL && strstr(user.contrasena,"Y")==NULL && strstr(user.contrasena,"U")==NULL && strstr(user.contrasena,"I")==NULL && strstr(user.contrasena,"O")==NULL && strstr(user.contrasena,"P")==NULL && strstr(user.contrasena,"A")==NULL && strstr(user.contrasena,"S")==NULL && strstr(user.contrasena,"D")==NULL && strstr(user.contrasena,"F")==NULL && strstr(user.contrasena,"G")==NULL && strstr(user.contrasena,"H")==NULL && strstr(user.contrasena,"J")==NULL && strstr(user.contrasena,"K")==NULL && strstr(user.contrasena,"L")==NULL && strstr(user.contrasena,"Ñ")==NULL && strstr(user.contrasena,"Z")==NULL && strstr(user.contrasena,"X")==NULL && strstr(user.contrasena,"C")==NULL && strstr(user.contrasena,"V")==NULL && strstr(user.contrasena,"B")==NULL && strstr(user.contrasena,"N")==NULL && strstr(user.contrasena,"M")==NULL)
				{
					printf("\nLa contrase%cia no posee mayuscula, ingrese nuevamente:",164);
					_flushall;
					gets(user.contrasena);
				}
				else
				{
					if(strstr(user.contrasena,"q")==NULL && strstr(user.contrasena,"w")==NULL && strstr(user.contrasena,"e")==NULL && strstr(user.contrasena,"r")==NULL && strstr(user.contrasena,"t")==NULL && strstr(user.contrasena,"y")==NULL && strstr(user.contrasena,"u")==NULL && strstr(user.contrasena,"i")==NULL && strstr(user.contrasena,"o")==NULL && strstr(user.contrasena,"p")==NULL && strstr(user.contrasena,"a")==NULL && strstr(user.contrasena,"s")==NULL && strstr(user.contrasena,"d")==NULL && strstr(user.contrasena,"f")==NULL && strstr(user.contrasena,"g")==NULL && strstr(user.contrasena,"h")==NULL && strstr(user.contrasena,"j")==NULL && strstr(user.contrasena,"k")==NULL && strstr(user.contrasena,"l")==NULL && strstr(user.contrasena,"ñ")==NULL && strstr(user.contrasena,"z")==NULL && strstr(user.contrasena,"x")==NULL && strstr(user.contrasena,"c")==NULL && strstr(user.contrasena,"v")==NULL && strstr(user.contrasena,"b")==NULL && strstr(user.contrasena,"n")==NULL && strstr(user.contrasena,"m")==NULL)
					{
						printf("\nLa contrasenia no posee minuscula, ingrese nuevamente: ");
						_flushall;
						gets(user.contrasena);
					}
					else
					{
						if(strstr(user.contrasena,"0")==NULL && strstr(user.contrasena,"1")==NULL && strstr(user.contrasena,"2")==NULL && strstr(user.contrasena,"3")==NULL && strstr(user.contrasena,"4")==NULL && strstr(user.contrasena,"5")==NULL && strstr(user.contrasena,"6")==NULL && strstr(user.contrasena,"7")==NULL && strstr(user.contrasena,"8")==NULL && strstr(user.contrasena,"9")==NULL)
						{
							printf("\nLa contrasenia no posee numeros, ingrese de nuevo la contrasenia:");
							_flushall;
							gets(user.contrasena);
						}
						else
						{
							if(strstr(user.contrasena,",")!=NULL && strstr(user.contrasena,".")!=NULL && strstr(user.contrasena,"-")!=NULL && strstr(user.contrasena,"á")!=NULL && strstr(user.contrasena,"é")!=NULL && strstr(user.contrasena,"í")!=NULL && strstr(user.contrasena,"ó")!=NULL && strstr(user.contrasena,"ú")!=NULL && strstr(user.contrasena,",")!=NULL && strstr(user.contrasena,"Á")!=NULL && strstr(user.contrasena,"É")!=NULL && strstr(user.contrasena,"Í")!=NULL && strstr(user.contrasena,"Ó")!=NULL && strstr(user.contrasena,"Ú")!=NULL)
							{
								printf("\nLa contrase%cia posee signos de puntuacion, ingrese nuevamente:",164);
								_flushall;
								gets(user.contrasena);
							}
							else
							{
								if(strlen(user.contrasena)<6)
								{
									printf("\nLa contrase%cia es muy corta, ingrese de nuevo la contrasenia:",164);
									_flushall;
									gets(user.contrasena);
								}
								else
								{
									if(strlen(user.contrasena)>32)
									{
										printf("\nLa contrase%cia es muy larga, ingrese nuevamente:",164);
										_flushall;
										gets(user.contrasena);
									}
									else
									{
										for(int i=0;i<strlen(user.contrasena);i++)
										{
											if((user.contrasena[i+2]==user.contrasena[i+1]+1) && (user.contrasena[i+1]==user.contrasena[i]+1))
											{
												printf("No ingrese numeros ni letras consecutivos, ingrese nuevamente: ");
												_flushall();
												gets(user.contrasena);
											}
											else
											{
												aceptar=true;
											}
										}								
										if(aceptar==true)
										{
											printf("\nContrase%ca aceptada",164);
											
										}
									}
								}
							}
						}
					}
				}
			}	
		}
	strcpy(user.usuario,auxuser);
    fwrite(&user,sizeof(usuario),1,auser);
    printf("\nEl usuario fue registrado correctamente\n");
    system("pause");
    system("cls");
}
///////////////////////////////////////////////////////////
void atencvec (veterinario v,turno t)
{
	FILE *aturn;
	FILE *vete;
	char auvet[80];
	int i=0;
	vete=fopen("Veterinarios.dat","r+b");
	aturn=fopen("turnos.dat","r+b");
	printf ("\n========================\n");					
	printf("\nATENCIONES POR VETERINARIOS\n");
	printf ("\n========================\n");
	_flushall();
	printf("Veterinario: ");
	gets(auvet);
						
	fread(&v,sizeof(veterinario),1,vete);
	fread(&t,sizeof(turno),1,aturn);
	while(!feof(vete)&& !feof(aturn))
	{
		if(strcmp(auvet,v.apeynomvet)==0)
		{
								
			if(t.matricvet==v.matricula)
			{
				printf("Turno %d: \n",i);
				i++;
				printf("\nFecha:");
				printf("\nDia: %d", t.fect.dia);
				printf("\nMes: %d", t.fect.mes);
				printf("\nAnio: %d", t.fect.anio);
				printf("\nDNI del dueño: %d", t.dni);
				fread(&v,sizeof(veterinario),1,vete);
				fread(&t,sizeof(turno),1,aturn);
										
			}
			else
			{
				fread(&v,sizeof(veterinario),1,vete);
				fread(&t,sizeof(turno),1,aturn);
	
										
			}	
		}
		else
		{
			fread(&v,sizeof(veterinario),1,vete);
			fread(&t,sizeof(turno),1,aturn);
								
		}				
	}
	printf("\n\n");
	system("pause");
	system("cls");
}
void rankingvet (veterinario v,turno t )
{
	FILE *atur;
	FILE *vete;
	int i=0 , may = -1  , vueltas = 0;
    char umay[70];
    bool b=true;
    vete=fopen("Veterinarios.dat","r+b");

    atur=fopen("turno.dat","r+b");

    if(vete==NULL || atur==NULL)
    {
        printf("\nERROR!!!. El archivo es inexistente");
        b=false;

    }

    rewind(atur);
    rewind(vete);

    fread(&v,sizeof(veterinario),1,vete);
    fread(&t,sizeof(turno),1,atur);
    if(b==true)
    {
        while(!feof(vete))
        {

            while(!feof(atur)){

                if(v.matricula == t.matricvet){

                    i++;

                    fread(&t,sizeof(turno),1,atur);
                }
                else{

                    fread(&t,sizeof(turno),1,atur);
                }

                v.cp = i;

            }

            if(v.cp>may)
            {

                may=v.cp;

                strcpy(umay,v.apeynomvet);

            }
            fread(&v,sizeof(veterinario),1,vete);
            rewind(atur);

            i = 0;
            vueltas++;

        }

        rewind(vete);
        fread(&v,sizeof(veterinario),1,vete);
        printf("\nEl veterinario que registro mas mascotas es: %s con %d mascotas\n", umay, may);

    }				
					
}

//////////////////////////////////////////////////////////////////////////////////FUNCIONES REY

int Datos (FILE *vete, veterinario v, char pass[10])
{

   	int  matm;
	bool band;	
	
			vete= fopen("Veterinarios.dat","r+b");
			system("cls");
			printf("INICIO DE SESION");
			printf("\nIngrese su matricula: ");
			scanf("%d",&matm);
			fread(&v,sizeof(veterinario),1,vete);
			band=false;
			
			while(band==false)
			{
				while(!feof(vete))
				{
					if(matm == v.matricula)
					{
						band=true;
						fread(&v,sizeof(veterinario),1,vete);
					}
					else
					{
						fread(&v,sizeof(veterinario),1,vete);
					}
				
				}
				rewind(vete);
				if(band==false)
				{
					printf("\nMatricula incorrecta, por favor ingrese su matricula de nuevo: ");
					scanf("%d",&matm);
				}
				
			}
			printf("\nMatricula aceptada, ingrese su contraseña: ");
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
				rewind(vete);
				if(band==false)
				{
					printf("\nContraseña incorrecta, por favor ingrese su contraseña de nuevo: ");
					_flushall();
					gets(pass);
				}
			}
			
			printf("\nContraseña aceptada\nSesion iniciada con exito!");
			fclose(vete);
			
			
			return matm;
}
///////////////////////////////////////////////////////////
void Turnos (veterinario v, turno t, mascota m)
{
	FILE *atur; 
	FILE *vete;
	FILE *amasc; 
			atur=fopen("turnos.dat","r+b");
			vete=fopen("Veterinarios.dat","r+b");
			amasc=fopen("Mascotas.dat","r+b");
				int i=0;
                int op;
				
				system("cls");
				printf ("/*/*/*/*/*/*/*/*/*/*/*/*/*/\n");
				printf("Lista de espera de mascotas");
				printf ("\n/*/*/*/*/*/*/*/*/*/*/*/*/*/\n");
				
				fread(&t,sizeof(turno),1,atur);
			
				while(!feof(atur))
				{
					if(v.matricula==t.matricvet)
					{
						printf("\nTurno %d:",i);
						printf("\nFecha:");
						printf("\n\nDia: %d",t.fect.dia);
						printf("\nMes: %d",t.fect.mes);
						printf("\nA%co: %d",164,t.fect.anio);
						printf("\nDNI del dueño: %d", t.dni);
						printf("\nNombre y Apellido del duenio: %s",t.ayn);
					
						
						fread(&t,sizeof(turno),1,atur);
						
					}
					else
					{
						fread(&t,sizeof(turno),1,atur);
					
					}
				}
				
				fclose(atur);
	
				printf("\n\n");
				system("pause");
				system("cls");
}
///////////////////////////////////////////////////////////
void Evolucion (FILE *atur, turno t)
{
    int op;

    atur=fopen("turno.dat","r+b");
    _flushall();
     printf ("\n==================================\n");
    printf("\nRegistre la evolucion de la mascota: ");
    printf ("\n==================================\n");
    gets(t.detalle);
    printf ("\nSe registro con exito el avance de su mascota\n");
    fwrite(&t, sizeof(turno), 1,atur);

}
//////////////////////////////////////////////////////////////////////////////////FUNCIONES ALBA
void iniciosesion (usuario user)
{
	FILE *auser;
    char iniu[10], inic[10];
    bool b1, b2;

    auser=fopen("Usuarios.dat","r+b");


    printf("\nINICIO DE SESION");
    printf("\nUsuario: ");
    _flushall();
    gets(iniu);

    b1=false; b2=false;
    while(b1==false)
    {
        rewind(auser);
        fread(&user,sizeof(usuario),1,auser);
        while(!feof(auser))
        {
            if(strcmp(iniu,user.usuario)==0)
            {
                b1=true;
            }
            else
            {
                b1=false;
            }
            fread(&user,sizeof(usuario),1,auser);
        }

        if(b1==false)
        {
            printf("\nEl nombre de usuario ingresado no esta registrado, por favor digite otro: ");
            gets(iniu);
        }

    }

    printf("Contrase%ca:",164);
    _flushall();
    gets(inic);



    while(b2==false)
    {
        if(strcmp(inic,user.contrasena)==0)
        {
            b2=true;
            printf("\nContrase%ca aceptada", 164);
        }
        else
        {
            b2=false;
        }

        if(b2==false)
        {
            printf("\nLa contrase%ca ingresada es incorrecta, por favor intente de nuevo: ");
            gets(inic);
            b2=false;
        }
    }

    if(b1==true && b2==true)
    {
        printf("\n\nIniciaste sesion correctamente, Bienvendido: %s", iniu);
        printf ("\n\n");
    }



}
///////////////////////////////////////////////////////////
void regmascotas (mascota m)

{
	FILE *amasc;
	
	amasc=fopen("Mascotas.dat","a+b");
	
	printf("\nREGISTRACION DE MASCOTAS\n");
	
	printf("Apellido y nombre del due%co: " , 164);
	_flushall();
    gets(m.apeynommasc);
   
    printf("Domicilio: ");
    _flushall();
    gets(m.domicilio);
    
	printf("DNI del due%co: ",164);
    scanf("%d",&m.dni);

    printf("Localidad: ");
    _flushall();
    gets(m.localidad);
    
    printf("\nFecha de nacimiento:");
    printf ("\nIngresar Datos con Numeros");
    	printf("\nDia: ");
    	scanf("%d",&m.fecnacimiento.dia);
		printf("\nMes: ");
    	scanf("%d",&m.fecnacimiento.mes);
		printf("\nAnio: ");
    	scanf("%d",&m.fecnacimiento.anio);
   
   	printf ("\n\n");
    printf("Peso (kg): ");
    scanf("%d" ,&m.peso);
    
    printf("Ingrese el numero de telefono: ");
    _flushall();
	gets(m.telefonomasc);
	
    fwrite(&m,-sizeof(mascota),1,amasc);
    
	printf("\n-------->La mascota fue guardado correctamente<--------");
	
	fclose(amasc);	
	
}
///////////////////////////////////////////////////////////
void turnos (turno t)
{
	FILE *atur;
	atur=fopen("turnos.dat","a+b");
					
	printf("\nREGISTRACION DE TURNO\n");
	
	printf("Matricula del veterinario: ");
	scanf("%d",&t.matricvet);
	
	printf ("\nIngresar Datos Con numeros");
	printf("\nFecha:\n");
	printf("\nDia: ");
	scanf("%d", &t.fect.dia);
	printf("\nMes: ");
	scanf("%d", &t.fect.mes);
	printf("\nA%co: ",164);
	scanf("%d", &t.fect.anio);
		
	printf("\nDNI del due%co: ",164);
	scanf("%d",&t.dni);
	

	fwrite(&t,sizeof(turno),1,atur);	
	
	printf("\nEl turno fue guardado correctamente");
	fclose(atur);

}
///////////////////////////////////////////////////////////
void listadoatencion (turno t, mascota m, veterinario v)
{

	FILE *vete;
	FILE *atur;
	FILE *amasc;
	char auvet[40];
	int i=1;
	bool valido = false;
	
	vete=fopen("Veterinarios.dat","r+b");
	atur=fopen("turnos.dat","r+b");

	
	printf("LISTADO DE ATENCIONES POR VETERINARIOS Y FECHA\n");
	
	_flushall();
	gets(auvet);
	
	rewind(atur);
	rewind(vete);
	
	fread(&v,sizeof(veterinario),1,vete);
	fread(&t,sizeof(turno),1,atur);
	
	
	while(!feof(vete))
	{
		printf("Veterinario: ");
		
			while(!feof(vete))
			{
			
				if(t.matricvet==v.matricula)
				{
					printf("\nFecha de turno:");
					printf("\nDia: %d", t.fect.dia);
					printf("\nMes: %d", t.fect.mes);
					printf("\nA%co: %d",164, t.fect.anio);
					printf("\nDNI del dueño: %d", t.dni);
					printf("\nNombre del veterinario: %s",v.apeynomvet);
					printf("\nMatricula: %d",v.matricula);
					i++;
					
					fread(&t,sizeof(turno),1,atur);
					
				}
				else
				{
				
					fread(&t,sizeof(turno),1,atur);
					
				}	
		
			}

	}

	printf("\n\n");
	system("pause");
	system("cls");
}
