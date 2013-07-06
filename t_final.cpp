#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct sRegistro {// estructura que declara
   int clave;
   char al;
   char tipo;
   char titulo[30];
   char autor[30];
   char editorial[30];
   float precio;
   int existenxia;
   struct {
           int dia;
           int mes;
           int ao;
           }entrada;

 struct {
           int dia;
           int mes;
           int ao;
           }salida;
   
} registro;


FILE *archivo; //archivo puntero

void file(FILE *archivo);//genera el archivo
void Ver(FILE *archivo);//muestra el archivo
void midificar(FILE *archivo);//modifica el archivo
void consul(FILE *archivo);//ve un registro
void baja(FILE *archivo);//da de baja registros
void entrada(FILE *archivo);// entra a los libros
void salida(FILE *archivo);// salida de libros


int main()
{
 int opc; 
 char s;// opcion si o no

 do{
system("color f9");// da color al menu
 printf("\t\t\tHouse Library LARA's\n");
 
do{
             printf("\n         ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ*");
			 printf("\n         Ý                    :: Menu Principal ::                   Ý");
			 printf("\n         ÝอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออÝ");
			 printf("\n         Ý                                                           Ý");
			 printf("\n         Ý  1-Generar un Archivo         3-Menu de Entradas-Salidas  Ý");
			 printf("\n         Ý                                                           Ý");
			 printf("\n         Ý  2-Menu de Actualicacion      4-Listar                    Ý");
			 printf("\n         Ý                                                           Ý");
			 printf("\n         Ý                        0.-Terminar                        Ý");
			 printf("\n         ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ*");
			 printf("\n\n");
			 printf("\n\nFecha: ");system("date /t");printf("Hora: ");system("time /t");
 printf("\nEscoja la opcion a realizar\n");
 fflush(stdin);
 scanf("%d",&opc);
 if(opc>4||opc<0)
 {system("cls");
  system("color f4"); 
  printf("Escoja una obcion valida\n");
  system("pause");system("color f9");}
  }while(opc>4||opc<0);
	switch(opc)
	{       
        case 0:
             s='n';
               break;
        case 1:
             do{
             system("cls");
             printf("Fecha: ");system("date /t");printf("Hora: ");system("time /t");
             printf("\n\n");
             file(archivo);//generar archivo
             if(registro.clave==9999)
             {s='n';}else{
             printf("\nDesea continuar <S/N>\t");
             s=getch();}// si la resuesta es si continua si no se sale y regresa al menu principal
             }while(s=='s'||s=='S');
             s='s';
              break;
        case 2: // va al menu de actualizacion
             system("cls"); 
             system("color f2");
              printf("\t\t\tHouse Library LARA's\n");
do{
             printf("\n         ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ*");
			 printf("\n         Ý                 :: Menu de Actualizacion ::               Ý");
			 printf("\n         ÝอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออÝ");
			 printf("\n         Ý                                                           Ý");
			 printf("\n         Ý  0.-Terminar                3-Bajas                       Ý");
			 printf("\n         Ý                                                           Ý");
			 printf("\n         Ý  1-Menu Principal           4-Modificaciones              Ý");
			 printf("\n         Ý                                                           Ý");
			 printf("\n         Ý  2-Altas                    5-Consultas                   Ý");
			 printf("\n         ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ*");
			 printf("\n\n");
			 printf("\n\nFecha: ");system("date /t");printf("Hora: ");system("time /t");
 printf("\nEscoja la opcion a realizar\n");
 fflush(stdin);
 scanf("%d",&opc);
 if(opc>5||opc<0)
 {system("cls");
  system("color f4"); 
  printf("Escoja una obcion valida\n");
  system("pause");system("color f2");}
  }while(opc>5||opc<0);
  switch(opc)
  {
   case 0:
        s='n';
        break;
   case 1:
        system("cls");
        s='s';
        break;
   case 2://Falta preguntar si existe
       do{
             system("cls");
             printf("Fecha: ");system("date /t");printf("Hora: ");system("time /t");
             printf("\n\n");
             file(archivo);// pregunta si desea reemplazarlo
             if(registro.clave==9999)
             {s='n';}else{
             printf("\nDesea continuar <S/N>\t");
             s=getch();}
             }while(s=='s'||s=='S');
             s='s';
        break;
   case 3:
        system("cls");
         baja(archivo);//bajas del archivo
         s='s';//si la opcion es si se regresa
        break;
   case 4:
        system("cls");
        midificar(archivo);//modifica el archivo
        s='s';
        break;
   case 5:
        system("cls");
        consul(archivo);//consulta el archivo
        s='s';
        break;
  }     
   
             break;
        case 3: 
             system("cls");
             system("color f1");
                           printf("\t\t\tHouse Library LARA's\n");
do{
             printf("\n         ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ*");
			 printf("\n         Ý               :: Menu de Entradas-Salidas ::              Ý");
			 printf("\n         ÝอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออÝ");
			 printf("\n         Ý                                                           Ý");
			 printf("\n         Ý  0.-Terminar                2-Entrada de Libros           Ý");
			 printf("\n         Ý                                                           Ý");
			 printf("\n         Ý  1-Menu Principal           3-Salida de libros            Ý");
			 printf("\n         Ý                                                           Ý");
			 printf("\n         Ý                                                           Ý");
			 printf("\n         ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ*");
			 printf("\n\n");
			 printf("\n\nFecha: ");system("date /t");printf("Hora: ");system("time /t");
 printf("\nEscoja la opcion a realizar\n");
 fflush(stdin);
 scanf("%d",&opc);
 if(opc>3||opc<0)
 {system("cls");
  system("color f4"); 
  printf("Escoja una obcion valida\n");
  system("pause");system("color f1");}
  }while(opc>3||opc<0);
  switch(opc)
  {
   case 0:
        s='n';
        break;
   case 1:
        system("cls");
         s='s';
        break;
   case 2:
        system("cls");
        entrada(archivo);
        s='s';
        break;
   case 3:
        system("cls");
        salida(archivo);
         s='s';
        break;
  }
 
             break;
        case 4:
             system("cls");
             printf("Fecha: ");system("date /t");printf("Hora: ");system("time /t");
             printf("\n\n");
             Ver(archivo);
             printf("\nDesea continuar <S/N>\t");
             s=getch();
             break;

	 }
	 system("cls");
}while(s=='s'||s=='S');
        printf("\n\nUsted acaba de salir del SISTEMA\n");
getch();

}


void file(FILE *archivo)
{ 
     char s;

             
if((archivo,"Libros.dat")!=NULL)
{
    do{
                                system("cls");
printf("\t\t\tGeneracion de Registros\n");
    printf("Fecha: ");system("date /t");printf("Hora: ");system("time /t");
             printf("\n\n");
     printf("El archivo ya exite desea remplazarlo <S/N>\t");
     fflush(stdin);
      scanf("%c",&s);
    }while(s!='s' && s !='S' && s!='n' && s!='N');
  if(s=='s')
    {
    
    fopen("Libros.dat","w");// reemplaza el archivo
    
    printf("Archivo Remplazado exitosamente:\n\n");
    printf("\n\n"); 
    system("pause");      
    } 
                           
} 
system("cls");
printf("\t\t\tGeneracion de Registros\n");
             printf("Fecha: ");system("date /t");printf("Hora: ");system("time /t");
             printf("\n\n");
archivo = fopen("Libros.dat","ab");  

do{
 printf("Clave:\t");
 fflush(stdin);
 scanf("%d",&registro.clave);
 if(registro.clave>9999||registro.clave<0)
   {
     system("cls");
     printf("Fecha: ");system("date /t");printf("Hora: ");system("time /t");
     system("color f4");
     printf("\nIngrese una clave > 0 o 9999 para salir \n\n");
     system("pause");
     system("color f9");
     system("cls");
     printf("Fecha: ");system("date /t");printf("Hora: ");system("time /t");
     printf("\n\n");
   }
 }while(registro.clave>9999||registro.clave<0);
 if(registro.clave==9999)
    {fclose(archivo);}else{
 //fprintf(archivo,"%d\t",registro.clave);
 (registro.al)='1';
do{
 printf("\nTipo:\t");
 fflush(stdin);
 scanf("%c",&registro.tipo);
 if(registro.tipo!='t'&&registro.tipo!='T'&&registro.tipo!='c'&&registro.tipo!='C')
    {
     system("cls");
     system("color f4");
     printf("Ingrese T de texto O C de consulta\n");
     system("pause");
      system("color f9");
     printf("Clave:\t%d",registro.clave);
    }
 }while(registro.tipo!='t'&&registro.tipo!='T'&&registro.tipo!='c'&&registro.tipo!='C');
 //fprintf(archivo,"%c\t",registro.tipo);
 
 printf("\nTitulo:\t");
 scanf("%s",&registro.titulo);
 //fprintf(archivo,"%s\t",registro.titulo);
 
 printf("\nAutor:\t");
 scanf("%s",&registro.autor);
 //fprintf(archivo,"%s\t",registro.autor);
 
 printf("\nEditorial:\t");
 scanf("%s",&registro.editorial);
 //fprintf(archivo,"%s\t",registro.editorial);
   
 printf("\nPrecio:\t");
 scanf("%f",&registro.precio);
 //fprintf(archivo,"%.2f\t",registro.precio);
 
 printf("\nExistencia:\t");
 scanf("%d",&registro.existenxia);
 //fprintf(archivo,"%d\t",registro.existenxia);
 printf("\nFecha Entrada:\t");
 do{
 printf("\tA\244o:\t");
 scanf("%d",&registro.entrada.ao);
 if(registro.entrada.ao<1990)
   {
     system("cls");
     system("color f4");//aqui podemos ver que requerimientos falta y se ve de color 
     printf("Ingrese un A\244o valido\n");
      system("pause");
      system("color f9");
        printf("Clave:\t%d\n",registro.clave);
        printf("Tipo:\t%c\n",registro.tipo);
        printf("titulo:\t%s\n",registro.titulo);
        printf("Autor:\t%s\n",registro.autor);
        printf("Editorial:\t%s\n",registro.editorial);
        printf("Precio:\t%.2f\n",registro.precio);
        printf("Existencia:\t%d",registro.existenxia);
        printf("\nFecha Entrada:\t");
        
   }
  }while(registro.entrada.ao<1990);
 //fprintf(archivo,"%d\t",registro.entrada.ao);
  
  do{
     printf("\t\t\tMes:\t");
     scanf("%d",&registro.entrada.mes);
     if(registro.entrada.mes>12||registro.entrada.mes<1)
       {
        system("cls");
      system("color f4");
        printf("Ingrese un Mes valido\n");
        system("pause");
      system("color f9");
       
        printf("Clave:\t%d\n",registro.clave);
        printf("Tipo:\t%c\n",registro.tipo);
        printf("titulo:\t%s\n",registro.titulo);
        printf("Autor:\t%s\n",registro.autor);
        printf("Editorial:\t%s\n",registro.editorial);
        printf("Precio:\t%.2f\n",registro.precio);
        printf("Existencia:\t%d\n",registro.existenxia);
        printf("\nFecha Entrada:\t");
        printf("\tA\244o:\t%d\n",registro.entrada.ao);
        }
    }while(registro.entrada.mes>12||registro.entrada.mes<1);
    //fprintf(archivo,"%d\t",registro.entrada.mes);
     if(registro.entrada.mes==1||registro.entrada.mes==3||registro.entrada.mes==5||registro.entrada.mes==7||registro.entrada.mes==8||registro.entrada.mes==10||registro.entrada.mes==12)
       {
         do{
             printf("\t\t\tDia:\t");
             scanf("%d",&registro.entrada.dia);
             if(registro.entrada.dia>31||registro.entrada.dia<1)
                {
                system("cls");
               system("color f4");
                printf("Ingrese un dia valido\n");
                system("pause");
                system("color f9");
                
                printf("Clave:\t%d\n",registro.clave);
                printf("Tipo:\t%c\n",registro.tipo);
                printf("titulo:\t%s\n",registro.titulo);
                printf("Autor:\t%s\n",registro.autor);
                printf("Editorial:\t%s\n",registro.editorial);
                printf("Precio:\t%.2f\n",registro.precio);
                printf("Existencia:\t%d\n",registro.existenxia);
                printf("\nFecha Entrada:\t");
                printf("\tA\244o:\t%d\n",registro.entrada.ao);
                printf("\t\t\tMes:\t%d\n",registro.entrada.mes);
                }               
           }while(registro.entrada.dia>31||registro.entrada.dia<1);
       }else if(registro.entrada.mes==4||registro.entrada.mes==6||registro.entrada.mes==9||registro.entrada.mes==11) 
               {
                 do{
                      
                       
                     printf("\t\t\tDia:\t");
                     scanf("%d",&registro.entrada.dia);
                     
                     if(registro.entrada.dia>30||registro.entrada.dia<1)
                        {
                        system("cls");
                        system("color f4");
                        printf("Ingrese un dia valido\n");
                        system("pause");
                        system("color f9");
                        
                        printf("Clave:\t%d\n",registro.clave);
                        printf("Tipo:\t%c\n",registro.tipo);
                        printf("titulo:\t%s\n",registro.titulo);
                        printf("Autor:\t%s\n",registro.autor);
                        printf("Editorial:\t%s\n",registro.editorial);
                        printf("Precio:\t%.2f\n",registro.precio);
                        printf("Existencia:\t%d\n",registro.existenxia);
                        printf("\nFecha Entrada:\t");
                        printf("\tA\244o:\t%d\n",registro.entrada.ao);
                        printf("\t\t\tMes:\t%d\n",registro.entrada.mes);
                        }               
                   }while(registro.entrada.dia>30||registro.entrada.dia<1);
               }else if(registro.entrada.mes==2)
                        {
                          if(registro.entrada.ao%4==0)
                             {
                               do{
                               
                                     printf("\t\t\tDia:\t");
                                     scanf("%d",&registro.entrada.dia);
                                     
                                     if(registro.entrada.dia>29||registro.entrada.dia<1)
                                        {
                                            system("cls");
                                            system("color f4");
                                            printf("Ingrese un dia valido\n");
                                            system("pause");
                                            system("color f9");
                                            
                                            printf("Clave:\t%d\n",registro.clave);
                                            printf("Tipo:\t%c\n",registro.tipo);
                                            printf("titulo:\t%s\n",registro.titulo);
                                            printf("Autor:\t%s\n",registro.autor);
                                            printf("Editorial:\t%s\n",registro.editorial);
                                            printf("Precio:\t%.2f\n",registro.precio);
                                            printf("Existencia:\t%d\n",registro.existenxia);
                                            printf("\nFecha Entrada:\t");
                                            printf("\tA\244o:\t%d\n",registro.entrada.ao);
                                            printf("\t\t\tMes:\t%d\n",registro.entrada.mes);
                                        }               
                                   }while(registro.entrada.dia>29||registro.entrada.dia<1);
                             }else{
                                   do{
                                         printf("\t\t\tDia:\t");
                                         scanf("%d",&registro.entrada.dia);
                                         
                                         if(registro.entrada.dia>28||registro.entrada.dia<1)
                                         {
                                            system("cls");
                                            if(registro.entrada.dia==29)
                                            {
                                            system("color f4");
                                            printf("NO es biciesto:\nIngrese un dia valido\n");
                                            system("pause");
                                           system("color f9");
                                            }
                                            else
                                                {
                                                  system("color f4");       
                                                 printf("Ingrese un dia valido\n");
                                                 system("pause");
                                                 system("color f9");
                                                }
                                            printf("Clave:\t%d\n",registro.clave);
                                            printf("Tipo:\t%c\n",registro.tipo);
                                            printf("titulo:\t%s\n",registro.titulo);
                                            printf("Autor:\t%s\n",registro.autor);
                                            printf("Editorial:\t%s\n",registro.editorial);
                                            printf("Precio:\t%.2f\n",registro.precio);
                                            printf("Existencia:\t%d\n",registro.existenxia);
                                            printf("\nFecha Entrada:\t");
                                            printf("\tA\244o:\t%d\n",registro.entrada.ao);
                                            printf("\t\t\tMes:\t%d\n",registro.entrada.mes);
                                         }                  
                                      }while(registro.entrada.dia>28||registro.entrada.dia<1);
                                   }
                             }//fprintf(archivo,"%d\t",registro.entrada.dia);
//dia mes a๑o salida--------------------------------------------------------
printf("\nFecha Salida:\t");
 do{
 printf("\tA\244o:\t");
 scanf("%d",&registro.salida.ao);
 if(registro.salida.ao<1990)
   {
     system("cls");
     system("color f4");//aqui podemos ver que requerimientos falta y se ve de color 
     printf("Ingrese un A\244o valido\n");
      system("pause");
      system("color f9");
        printf("Clave:\t%d\n",registro.clave);
        printf("Tipo:\t%c\n",registro.tipo);
        printf("titulo:\t%s\n",registro.titulo);
        printf("Autor:\t%s\n",registro.autor);
        printf("Editorial:\t%s\n",registro.editorial);
        printf("Precio:\t%.2f\n",registro.precio);
        printf("Existencia:\t%d",registro.existenxia);
        printf("\nFecha Entrada:\t");
        printf("\tA\244o:\t%d\n",registro.entrada.ao);
        printf("\t\t\tMes:\t%d\n",registro.entrada.mes);
        printf("\t\t\tDia:\t%d\n",registro.entrada.dia);
        printf("\nFecha Salida:\t");
        
   }
  }while(registro.salida.ao<1990);
  //fprintf(archivo,"%d\t",registro.salida.ao);
  
  do{
     printf("\t\t\tMes:\t");
     scanf("%d",&registro.salida.mes);
     if(registro.salida.mes>12||registro.salida.mes<1)
       {
        system("cls");
      system("color f4");
        printf("Ingrese un Mes valido\n");
        system("pause");
      system("color f9");
       
        printf("Clave:\t%d\n",registro.clave);
        printf("Tipo:\t%c\n",registro.tipo);
        printf("titulo:\t%s\n",registro.titulo);
        printf("Autor:\t%s\n",registro.autor);
        printf("Editorial:\t%s\n",registro.editorial);
        printf("Precio:\t%.2f\n",registro.precio);
        printf("Existencia:\t%d\n",registro.existenxia);
        printf("\nFecha Entrada:\t");
        printf("\tA\244o:\t%d\n",registro.entrada.ao);
        printf("\t\t\tMes:\t%d\n",registro.entrada.mes);
        printf("\t\t\tDia:\t%d\n",registro.entrada.dia);
        printf("\nFecha Salida:\t");
        printf("\tA\244o:\t%d\n",registro.salida.ao);
        }
    }while(registro.salida.mes>12||registro.salida.mes<1);
   //fprintf(archivo,"%d\t",registro.salida.mes);
     if(registro.salida.mes==1||registro.salida.mes==3||registro.salida.mes==5||registro.salida.mes==7||registro.salida.mes==8||registro.salida.mes==10||registro.salida.mes==12)
       {
         do{
             printf("\t\t\tDia:\t");
             scanf("%d",&registro.salida.dia);
             if(registro.salida.dia>31||registro.salida.dia<1)
                {
                system("cls");
               system("color f4");
                printf("Ingrese un dia valido\n");
                system("pause");
                system("color f9");
                
                printf("Clave:\t%d\n",registro.clave);
                printf("Tipo:\t%c\n",registro.tipo);
                printf("titulo:\t%s\n",registro.titulo);
                printf("Autor:\t%s\n",registro.autor);
                printf("Editorial:\t%s\n",registro.editorial);
                printf("Precio:\t%.2f\n",registro.precio);
                printf("Existencia:\t%d\n",registro.existenxia);
                printf("\nFecha Entrada:\t");
                printf("\tA\244o:\t%d\n",registro.entrada.ao);
                printf("\t\t\tMes:\t%d\n",registro.entrada.mes);
                printf("\t\t\tDia:\t%d\n",registro.entrada.dia);
                printf("\nFecha Salida:\t");
                printf("\tA\244o:\t%d\n",registro.salida.ao);
                printf("\t\t\tMes:\t%d\n",registro.salida.mes);
                }               
           }while(registro.salida.dia>31||registro.salida.dia<1);
       }else if(registro.salida.mes==4||registro.salida.mes==6||registro.salida.mes==9||registro.salida.mes==11) 
               {
                 do{
                      
                       
                     printf("\t\t\tDia:\t");
                     scanf("%d",&registro.salida.dia);
                     
                     if(registro.salida.dia>30||registro.salida.dia<1)
                        {
                        system("cls");
                        system("color f4");
                        printf("Ingrese un dia valido\n");
                        system("pause");
                        system("color f9");
                        
                        printf("Clave:\t%d\n",registro.clave);
                        printf("Tipo:\t%c\n",registro.tipo);
                        printf("titulo:\t%s\n",registro.titulo);
                        printf("Autor:\t%s\n",registro.autor);
                        printf("Editorial:\t%s\n",registro.editorial);
                        printf("Precio:\t%.2f\n",registro.precio);
                        printf("Existencia:\t%d\n",registro.existenxia);
                        printf("\nFecha Entrada:\t");
                        printf("\tA\244o:\t%d\n",registro.entrada.ao);
                        printf("\t\t\tMes:\t%d\n",registro.entrada.mes);
                        printf("\t\t\tDia:\t%d\n",registro.entrada.dia);
                        printf("\nFecha Salida:\t");
                        printf("\tA\244o:\t%d\n",registro.salida.ao);
                        printf("\t\t\tMes:\t%d\n",registro.salida.mes);
                        }               
                   }while(registro.salida.dia>30||registro.salida.dia<1);
               }else if(registro.salida.mes==2)
                        {
                          if(registro.salida.ao%4==0)
                             {
                               do{
                               
                                     printf("\t\t\tDia:\t");
                                     scanf("%d",&registro.salida.dia);
                                     
                                     if(registro.salida.dia>29||registro.salida.dia<1)
                                        {
                                            system("cls");
                                            system("color f4");
                                            printf("Ingrese un dia valido\n");
                                            system("pause");
                                            system("color f9");
                                            
                                            printf("Clave:\t%d\n",registro.clave);
                                            printf("Tipo:\t%c\n",registro.tipo);
                                            printf("titulo:\t%s\n",registro.titulo);
                                            printf("Autor:\t%s\n",registro.autor);
                                            printf("Editorial:\t%s\n",registro.editorial);
                                            printf("Precio:\t%.2f\n",registro.precio);
                                            printf("Existencia:\t%d\n",registro.existenxia);
                                            printf("\nFecha Entrada:\t");
                                            printf("\tA\244o:\t%d\n",registro.entrada.ao);
                                            printf("\t\t\tMes:\t%d\n",registro.entrada.mes);
                                            printf("\t\t\tDia:\t%d\n",registro.entrada.dia);
                                            printf("\nFecha Salida:\t");
                                            printf("\tA\244o:\t%d\n",registro.salida.ao);
                                            printf("\t\t\tMes:\t%d\n",registro.salida.mes);
                                        }               
                                   }while(registro.salida.dia>29||registro.salida.dia<1);
                             }else{
                                   do{
                                         printf("\t\t\tDia:\t");
                                         scanf("%d",&registro.salida.dia);
                                         
                                         if(registro.salida.dia>28||registro.salida.dia<1)
                                         {
                                            system("cls");
                                            if(registro.salida.dia==29)
                                            {
                                            system("color f4");
                                            printf("NO es biciesto:\nIngrese un dia valido\n");
                                            system("pause");
                                           system("color f9");
                                            }
                                            else
                                                {
                                                  system("color f4");       
                                                 printf("Ingrese un dia valido\n");
                                                 system("pause");
                                                 system("color f9");
                                                }
                                            printf("Clave:\t%d\n",registro.clave);
                                            printf("Tipo:\t%c\n",registro.tipo);
                                            printf("titulo:\t%s\n",registro.titulo);
                                            printf("Autor:\t%s\n",registro.autor);
                                            printf("Editorial:\t%s\n",registro.editorial);
                                            printf("Precio:\t%.2f\n",registro.precio);
                                            printf("Existencia:\t%d\n",registro.existenxia);
                                            printf("\nFecha Entrada:\t");
                                            printf("\tA\244o:\t%d\n",registro.entrada.ao);
                                            printf("\t\t\tMes:\t%d\n",registro.entrada.mes);
                                            printf("\t\t\tDia:\t%d\n",registro.entrada.dia);
                                            printf("\nFecha Salida:\t");
                                            printf("\tA\244o:\t%d\n",registro.salida.ao);
                                            printf("\t\t\tMes:\t%d\n",registro.salida.mes);
                                         }                  
                                      }while(registro.salida.dia>28||registro.salida.dia<1);
                                   }
                             }//fprintf(archivo,"%d\t",registro.salida.dia);
 
                           
 fseek(archivo,((registro.clave-1)*sizeof(struct sRegistro)), SEEK_SET);
 fwrite(&registro,sizeof(struct sRegistro),1,archivo);  
       
   fclose(archivo);}
}



void Ver(FILE *archivo)
{
      
 
        archivo = fopen("Libros.dat", "r");
 
        if(archivo == NULL)
        {
                system("color f4");
                printf("\nFichero no existe! \nPor favor creelo");
                system("color f9");
                return;
        }
 
        fread(&registro, sizeof(struct sRegistro), 1, archivo);
 
        printf("\nClave\tTipo\tTitulo\t\tExistencia\tFecha Entrada\tFecha Salida");
 
        while(!feof(archivo))
        {
                 printf("\n%d\t%c\t%s\t\t%d\t\t%d/%d/%d\t%d/%d/%d\n", 
                 registro.clave,registro.tipo,registro.titulo,
                 registro.existenxia,registro.entrada.dia,
                 registro.entrada.mes,registro.entrada.ao,
                 registro.salida.dia,registro.salida.mes,
                 registro.salida.ao);
                fread(&registro, sizeof(struct sRegistro), 1, archivo);
               
        }
 
        fclose(archivo);
 
        return;
}

void consul(FILE *archivo)
{
     int id=0;
     
     printf("\t\t\tBajas, Modificaciones y Consultas\n"); 
     printf("\nFecha: ");system("date /t");printf("Hora: ");system("time /t");
             printf("\n\n");       
     do{
               archivo=fopen("Libros.dat","rb");
               printf("\nClave del Registro a consultar:\t");
               scanf("%d", &id);
               fseek(archivo, 0L, SEEK_SET); 
               while(!feof(archivo))
               {             
               fread(&registro, sizeof(struct sRegistro), 1, archivo);
               if (id==(registro.clave))
               {
                  if((registro.al=='1'))
                  {
                  
                      printf("\nClave:\t%d", (registro.clave));      
                      printf("\nTipo:\t%c",(registro.tipo));
                      printf("\nTitulo:\t");     
                      puts(registro.titulo);
                      printf("\nAutor:\t");
                      puts(registro.autor);
                      printf("\nEditorial:\t");                       
                      puts(registro.editorial);
                      printf("\nPrecio:\t%.2f",(registro.precio));                       
                      printf("\nExistencia:\t%d",(registro.existenxia));                       
                      printf("\nFecha Entrada:\t%d/%d/%d",registro.entrada.dia,registro.entrada.mes,registro.entrada.ao);
                      printf("\nFecha Salida:\t%d/%d/%d\n\n",registro.salida.dia,registro.salida.mes,registro.salida.ao);
                      system("pause");
                      break;               
                    } else{
                             system("color f4");
                             printf("\nLa Clave esta de baja\n\n");
                             system("pause");
                             system("color f2");
                             break;
                             }
                  }    
               }
               if(id==9999||id>9999)
            return;
           if(id!=(registro.clave))
              {  system("color f4");
                printf("\nClave NO Existe\n\n");
                 system("pause");
                 system("color f2");
              }
          if(id<9999)
          {
               system("cls"); 
             printf("\t\t\tBajas, Modificaciones y Consultas\n");
             printf("\nFecha: ");system("date /t");printf("Hora: ");system("time /t");                               
         }
     }while(id<9999&&id!=9999);
}





void baja(FILE *archivo)
{
     int id;
     
                    
     do{      
              printf("\t\t\tBajas, Modificaciones y Consultas\n\n");
              printf("Fecha: ");system("date /t");printf("Hora: ");system("time /t");
             printf("\n\n"); 
               archivo=fopen("Libros.dat","r+b");
               printf("\nClave a dar de baja:\t");
               scanf("%d", &id);
               if(id==9999||id>9999)
                  return;
               fseek(archivo, 0L, SEEK_SET);    
               while(!feof(archivo))
               {
                   fread(&registro, sizeof(sRegistro), 1, archivo); 
                   if (id==(registro.clave)){
                                         (registro.al) = '0';
                                         break;
                                         }
                   }
                    if(id==9999||id>9999)
            return;
           if(id!=(registro.clave))
              { 
                printf("\nClave NO Valida\n\n");
                 system("pause");
                 
              }
                  
                  fseek(archivo, -sizeof(sRegistro), SEEK_CUR );
                  fwrite(&registro, sizeof(sRegistro),1, archivo);
                  fflush(stdin);
                  if (id==(registro.clave))                                                     
                  {printf("\nEl contacto fue borrado exitosamente\n\n");
                  system("pause");}
                  fclose(archivo); 
                   
                                         
              system("cls");
              }while(id<9999&&id!=9999);
}



void entrada(FILE *archivo) 
{
     int id,cant;
     do{
     printf("\t\t\tBajas, Modificaciones y Consultas\n"); 
     printf("\nFecha: ");system("date /t");printf("Hora: ");system("time /t");
             printf("\n\n");
             
        archivo=fopen("Libros.dat","r+b");
               printf("\nClave:\t");
               scanf("%d", &id);
               if(id==9999||id>9999)
                  return;
        
        fseek(archivo, 0L, SEEK_SET);
        while(!feof(archivo))
        {
               
          fread(&registro, sizeof(sRegistro), 1, archivo);
          if (id == (registro.clave))                                              
                  {
                  if (registro.al == '1')
                     {
                    
                       printf("\nCantidad:\t");
                                          scanf("%d",&cant);
                                          (registro.existenxia)=(registro.existenxia)+cant;
                                         printf("\nFecha Salida:\t");
 do{
 printf("\tA\244o:\t");
 scanf("%d",&registro.salida.ao);
 if(registro.salida.ao<1990)
   {
     system("cls");
     system("color f4"); 
     printf("Ingrese un A\244o valido\n");
      system("pause");
      system("color f1");
      printf("\nClave:\t%d",id);
        printf("\nCantidad:\t%d",cant);
        printf("\nFecha Entrada:\t");
        
   }
  }while(registro.entrada.ao<1990);

  
  do{
     printf("\t\t\tMes:\t");
     scanf("%d",&registro.entrada.mes);
     if(registro.entrada.mes>12||registro.entrada.mes<1)
       {
        system("cls");
      system("color f4");
        printf("Ingrese un Mes valido\n");
        system("pause");
      system("color f1");
       printf("\nClave:\t%d",id);
        printf("\nCantidad:\t%d",cant);
        printf("\nFecha Entrada:\t");
        printf("\tA\244o:\t%d\n",registro.entrada.ao);
        }
    }while(registro.salida.mes>12||registro.entrada.mes<1);
    
     if(registro.entrada.mes==1||registro.entrada.mes==3||registro.entrada.mes==5||registro.entrada.mes==7||registro.entrada.mes==8||registro.entrada.mes==10||registro.entrada.mes==12)
       {
         do{
             printf("\t\t\tDia:\t");
             scanf("%d",&registro.salida.dia);
             if(registro.entrada.dia>31||registro.entrada.dia<1)
                {
                system("cls");
               system("color f4");
                printf("Ingrese un dia valido\n");
                system("pause");
                system("color f1");
                printf("\nClave:\t%d",id);
                printf("\nCantidad:\t%d",cant);
                printf("\nFecha Entrada:\t");
                printf("\tA\244o:\t%d\n",registro.entrada.ao);
                printf("\t\t\tMes:\t%d\n",registro.entrada.mes);
                }               
           }while(registro.entrada.dia>31||registro.entrada.dia<1);
       }else if(registro.entrada.mes==4||registro.entrada.mes==6||registro.entrada.mes==9||registro.entrada.mes==11) 
               {
                 do{
                      
                       
                     printf("\t\t\tDia:\t");
                     scanf("%d",&registro.entrada.dia);
                     
                     if(registro.entrada.dia>30||registro.entrada.dia<1)
                        {
                        system("cls");
                        system("color f4");
                        printf("Ingrese un dia valido\n");
                        system("pause");
                        system("color f1");
                        printf("\nClave:\t%d",id);
                        printf("\nCantidad:\t%d",cant);
                        printf("\nFecha Entrada:\t");
                        printf("\tA\244o:\t%d\n",registro.entrada.ao);
                        printf("\t\t\tMes:\t%d\n",registro.entrada.mes);
                        }               
                   }while(registro.salida.dia>30||registro.entrada.dia<1);
               }else if(registro.entrada.mes==2)
                        {
                          if(registro.entrada.ao%4==0)
                             {
                               do{
                               
                                     printf("\t\t\tDia:\t");
                                     scanf("%d",&registro.entrada.dia);
                                     
                                     if(registro.entrada.dia>29||registro.entrada.dia<1)
                                        {
                                            system("cls");
                                            system("color f4");
                                            printf("Ingrese un dia valido\n");
                                            system("pause");
                                            system("color f1");
                                            printf("\nClave:\t%d",id);
                                            printf("\nCantidad:\t%d",cant);
                                            printf("\nFecha Entrada:\t");
                                            printf("\tA\244o:\t%d\n",registro.entrada.ao);
                                            printf("\t\t\tMes:\t%d\n",registro.entrada.mes);
                                        }               
                                   }while(registro.entrada.dia>29||registro.entrada.dia<1);
                             }else{
                                   do{
                                         printf("\t\t\tDia:\t");
                                         scanf("%d",&registro.entrada.dia);
                                         
                                         if(registro.entrada.dia>28||registro.entrada.dia<1)
                                         {
                                            system("cls");
                                            if(registro.entrada.dia==29)
                                            {
                                            system("color f4");
                                            printf("NO es biciesto:\nIngrese un dia valido\n");
                                            system("pause");
                                           system("color f1");
                                            }
                                            else
                                                {
                                                  system("color f4");       
                                                 printf("Ingrese un dia valido\n");
                                                 system("pause");
                                                 system("color f1");
                                                }
                                                printf("\nClave:\t%d",id);
                                            printf("\nCantidad:\t%d",cant);
                                            printf("\nFecha Entrada:\t");
                                            printf("\tA\244o:\t%d\n",registro.entrada.ao);
                                            printf("\t\t\tMes:\t%d\n",registro.entrada.mes);
                                         }                  
                                      }while(registro.entrada.dia>28||registro.entrada.dia<1);
                                   }
                             }
                                         break;
                                         }/*else{
                                               printf("La Clave del registro NO exite\n");
                                               system("pause");
                                               break;
                                             }*/ 
                                }                             
                               }

           fseek(archivo, -sizeof(sRegistro), SEEK_CUR);
           fwrite(&registro, sizeof(sRegistro),1, archivo);
           fclose(archivo);
           if(id==9999)
              return;
     
            system("cls"); 
             
          }while(id<9999&&id!=9999);   
      
}


void salida(FILE *archivo) 
{
     int id,cant;
     do{
     printf("\t\t\tBajas, Modificaciones y Consultas\n"); 
     printf("\nFecha: ");system("date /t");printf("Hora: ");system("time /t");
             printf("\n\n");
             
        archivo=fopen("Libros.dat","r+b");
               printf("\nClave:\t");
               scanf("%d", &id);
               if(id==9999||id>9999)
                  return;
        
        fseek(archivo, 0L, SEEK_SET);
        while(!feof(archivo))
        {
               
          fread(&registro, sizeof(sRegistro), 1, archivo);
          if (id == (registro.clave))                                              
                  {
                  if (registro.al == '1')
                     {
                    do{
                       printf("\nCantidad:\t");
                      
                      scanf("%d",&cant);
                      if(cant>registro.existenxia)
                      {printf("No puede sacar mas libros de los que exiten\n\n");
                     system("pause");
                      system("cls");
                      printf("\t\t\tBajas, Modificaciones y Consultas\n"); 
     printf("\nFecha: ");system("date /t");printf("Hora: ");system("time /t");
             printf("\n\n");printf("\nClave:\t%d",id);}
                       
                      }while(cant>registro.existenxia);
                                          (registro.existenxia)=(registro.existenxia)-cant;
                                          printf("\nFecha Salida:\t");
                                         
 do{
     
                      
 printf("\tA\244o:\t");
 scanf("%d",&registro.salida.ao);
 if(registro.salida.ao<1990)
   {
     system("cls");
     system("color f4"); 
     printf("Ingrese un A\244o valido\n");
      system("pause");
      system("color f1");
      printf("\nClave:\t%d",id);
        printf("\nCantidad:\t%d",cant);
        printf("\nFecha Entrada:\t");
        
   }
  }while(registro.salida.ao<1990);

  
  do{
     printf("\t\t\tMes:\t");
     scanf("%d",&registro.salida.mes);
     if(registro.salida.mes>12||registro.salida.mes<1)
       {
        system("cls");
      system("color f4");
        printf("Ingrese un Mes valido\n");
        system("pause");
      system("color f1");
       printf("\nClave:\t%d",id);
        printf("\nCantidad:\t%d",cant);
        printf("\nFecha Entrada:\t");
        printf("\tA\244o:\t%d\n",registro.salida.ao);
        }
    }while(registro.salida.mes>12||registro.salida.mes<1);
    
     if(registro.salida.mes==1||registro.salida.mes==3||registro.salida.mes==5||registro.salida.mes==7||registro.salida.mes==8||registro.salida.mes==10||registro.salida.mes==12)
       {
         do{
             printf("\t\t\tDia:\t");
             scanf("%d",&registro.salida.dia);
             if(registro.salida.dia>31||registro.salida.dia<1)
                {
                system("cls");
               system("color f4");
                printf("Ingrese un dia valido\n");
                system("pause");
                system("color f1");
                printf("\nClave:\t%d",id);
                printf("\nCantidad:\t%d",cant);
                printf("\nFecha Entrada:\t");
                printf("\tA\244o:\t%d\n",registro.salida.ao);
                printf("\t\t\tMes:\t%d\n",registro.salida.mes);
                }               
           }while(registro.salida.dia>31||registro.salida.dia<1);
       }else if(registro.salida.mes==4||registro.salida.mes==6||registro.salida.mes==9||registro.salida.mes==11) 
               {
                 do{
                      
                       
                     printf("\t\t\tDia:\t");
                     scanf("%d",&registro.salida.dia);
                     
                     if(registro.salida.dia>30||registro.salida.dia<1)
                        {
                        system("cls");
                        system("color f4");
                        printf("Ingrese un dia valido\n");
                        system("pause");
                        system("color f1");
                        printf("\nClave:\t%d",id);
                        printf("\nCantidad:\t%d",cant);
                        printf("\nFecha Entrada:\t");
                        printf("\tA\244o:\t%d\n",registro.salida.ao);
                        printf("\t\t\tMes:\t%d\n",registro.salida.mes);
                        }               
                   }while(registro.salida.dia>30||registro.salida.dia<1);
               }else if(registro.salida.mes==2)
                        {
                          if(registro.salida.ao%4==0)
                             {
                               do{
                               
                                     printf("\t\t\tDia:\t");
                                     scanf("%d",&registro.salida.dia);
                                     
                                     if(registro.entrada.dia>29||registro.salida.dia<1)
                                        {
                                            system("cls");
                                            system("color f4");
                                            printf("Ingrese un dia valido\n");
                                            system("pause");
                                            system("color f1");
                                            printf("\nClave:\t%d",id);
                                            printf("\nCantidad:\t%d",cant);
                                            printf("\nFecha Entrada:\t");
                                            printf("\tA\244o:\t%d\n",registro.salida.ao);
                                            printf("\t\t\tMes:\t%d\n",registro.salida.mes);
                                        }               
                                   }while(registro.salida.dia>29||registro.salida.dia<1);
                             }else{
                                   do{
                                         printf("\t\t\tDia:\t");
                                         scanf("%d",&registro.salida.dia);
                                         
                                         if(registro.salida.dia>28||registro.salida.dia<1)
                                         {
                                            system("cls");
                                            if(registro.salida.dia==29)
                                            {
                                            system("color f4");
                                            printf("NO es biciesto:\nIngrese un dia valido\n");
                                            system("pause");
                                           system("color f1");
                                            }
                                            else
                                                {
                                                  system("color f4");       
                                                 printf("Ingrese un dia valido\n");
                                                 system("pause");
                                                 system("color f1");
                                                }
                                                printf("\nClave:\t%d",id);
                                            printf("\nCantidad:\t%d",cant);
                                            printf("\nFecha Entrada:\t");
                                            printf("\tA\244o:\t%d\n",registro.salida.ao);
                                            printf("\t\t\tMes:\t%d\n",registro.salida.mes);
                                         }                  
                                      }while(registro.salida.dia>28||registro.salida.dia<1);
                                   }
                             }
                                         break;
                                         }/*else{
                                               printf("La Clave del registro NO exite\n");
                                               system("pause");
                                               break;
                                             }*/ 
                                }                             
                               }

           fseek(archivo, -sizeof(sRegistro), SEEK_CUR);
           fwrite(&registro, sizeof(sRegistro),1, archivo);
           fclose(archivo);
           if(id==9999)
              return;
     
            system("cls"); 
             
          }while(id<9999&&id!=9999);   
      
}



void midificar(FILE *archivo)
{
     int id,opc;
     do{
     printf("\t\t\tBajas, Modificaciones y Consultas\n"); 
     printf("\nFecha: ");system("date /t");printf("Hora: ");system("time /t");
             printf("\n\n");
             
       
        archivo = fopen("Libros.dat","r+b"); 
         printf("\nClave del Registro a modificar\t");
        scanf("%d", &id);
        fseek(archivo, 0L, SEEK_SET);
        while(!feof(archivo))
        {
               
          fread(&registro, sizeof(sRegistro), 1, archivo);
          if (id == (registro.clave))                                              
                  {
                  if (registro.al == '1')
                     {
                    
                     printf("\n1.-Tipo");
                     printf("\n2.-Titulo");
                     printf("\n3.-Autor");
                     printf("\n4.-Editorial");
                     printf("\n5.-Precio");
                     printf("\n6.-Exietncia");
                     printf("\n7.-Fecha Entrada");
                     printf("\n8.-Fecha Salida");
                     printf("\n9.-No Editar");
                     printf("\nOpcion a modificar:\t");
                     scanf("%d", &opc);
                     switch(opc){
                                 case 1:
                                      do{
 printf("\nTipo:\t");
 fflush(stdin);
 scanf("%c",&registro.tipo);
 if(registro.tipo!='t'&&registro.tipo!='T'&&registro.tipo!='c'&&registro.tipo!='C')
    {
     system("cls");
     system("color f4");
     printf("Ingrese T de texto O C de consulta\n");
     system("pause");
      system("color f2");
     printf("\t\t\tBajas, Modificaciones y Consultas\n"); 
     printf("\nFecha: ");system("date /t");printf("Hora: ");system("time /t");
             printf("\n\n");
                printf("\n1.-Tipo");
                     printf("\n2.-Titulo");
                     printf("\n3.-Autor");
                     printf("\n4.-Editorial");
                     printf("\n5.-Precio");
                     printf("\n6.-Exietncia");
                     printf("\n7.-Fecha Entrada");
                     printf("\n8.-Fecha Salida");
                     printf("\n9.-No Editar");
                     printf("\nOpcion a modificar:\t%d\n",opc);
    }
 }while(registro.tipo!='t'&&registro.tipo!='T'&&registro.tipo!='c'&&registro.tipo!='C');    
                                      break;
                      
                                 case 2:     
                                      printf("\nTitulo:\t");      
                                      fflush(stdin);
                                      scanf("%s",&(registro.titulo)); 
                                      break;
     
                                 case 3:     
                                      printf("\nAutor:\t");      
                                      fflush(stdin);
                                      scanf("%s",&registro.autor); 
                                      break;
                           
                                 case 4:     
                                      printf("\nEditorial:\t");      
                                      fflush(stdin);
                                      scanf("%s",&registro.editorial); 
                                      break; 
                                      
                                  case 5: 
                                       printf("\nPrecio:\t");      
                                      fflush(stdin);
                                      scanf("%f",&registro.precio);    
                                       break;
                                   case 6:
                                       printf("\nExistencia:\t");      
                                      fflush(stdin);
                                      scanf("%d",&registro.existenxia);
                                      break;
                                  case 7:
                                       printf("\nFecha Entrada:\t");      
                                      do{
 printf("\tA\244o:\t");
 scanf("%d",&registro.entrada.ao);
 if(registro.entrada.ao<1990)
   {
     system("cls");
     system("color f4");
     printf("Ingrese un A\244o valido\n");
      system("pause");
      system("color f2");
        printf("Clave:\t%d\n",registro.clave);
        printf("Tipo:\t%c\n",registro.tipo);
        printf("titulo:\t%s\n",registro.titulo);
        printf("Autor:\t%s\n",registro.autor);
        printf("Editorial:\t%s\n",registro.editorial);
        printf("Precio:\t%.2f\n",registro.precio);
        printf("Existencia:\t%d",registro.existenxia);
        printf("\nFecha Entrada:\t");
        
   }
  }while(registro.entrada.ao<1990);

  
  do{
     printf("\t\t\tMes:\t");
     scanf("%d",&registro.entrada.mes);
     if(registro.entrada.mes>12||registro.entrada.mes<1)
       {
        system("cls");
      system("color f4");
        printf("Ingrese un Mes valido\n");
        system("pause");
      system("color f2");
       
        printf("Clave:\t%d\n",registro.clave);
        printf("Tipo:\t%c\n",registro.tipo);
        printf("titulo:\t%s\n",registro.titulo);
        printf("Autor:\t%s\n",registro.autor);
        printf("Editorial:\t%s\n",registro.editorial);
        printf("Precio:\t%.2f\n",registro.precio);
        printf("Existencia:\t%d\n",registro.existenxia);
        printf("\nFecha Entrada:\t");
        printf("\tA\244o:\t%d\n",registro.entrada.ao);
        }
    }while(registro.entrada.mes>12||registro.entrada.mes<1);
    
     if(registro.entrada.mes==1||registro.entrada.mes==3||registro.entrada.mes==5||registro.entrada.mes==7||registro.entrada.mes==8||registro.entrada.mes==10||registro.entrada.mes==12)
       {
         do{
             printf("\t\t\tDia:\t");
             scanf("%d",&registro.entrada.dia);
             if(registro.entrada.dia>31||registro.entrada.dia<1)
                {
                system("cls");
               system("color f4");
                printf("Ingrese un dia valido\n");
                system("pause");
                system("color f2");
                
                printf("Clave:\t%d\n",registro.clave);
                printf("Tipo:\t%c\n",registro.tipo);
                printf("titulo:\t%s\n",registro.titulo);
                printf("Autor:\t%s\n",registro.autor);
                printf("Editorial:\t%s\n",registro.editorial);
                printf("Precio:\t%.2f\n",registro.precio);
                printf("Existencia:\t%d\n",registro.existenxia);
                printf("\nFecha Entrada:\t");
                printf("\tA\244o:\t%d\n",registro.entrada.ao);
                printf("\t\t\tMes:\t%d\n",registro.entrada.mes);
                }               
           }while(registro.entrada.dia>31||registro.entrada.dia<1);
       }else if(registro.entrada.mes==4||registro.entrada.mes==6||registro.entrada.mes==9||registro.entrada.mes==11) 
               {
                 do{
                      
                       
                     printf("\t\t\tDia:\t");
                     scanf("%d",&registro.entrada.dia);
                     
                     if(registro.entrada.dia>30||registro.entrada.dia<1)
                        {
                        system("cls");
                        system("color f4");
                        printf("Ingrese un dia valido\n");
                        system("pause");
                        system("color f2");
                        
                        printf("Clave:\t%d\n",registro.clave);
                        printf("Tipo:\t%c\n",registro.tipo);
                        printf("titulo:\t%s\n",registro.titulo);
                        printf("Autor:\t%s\n",registro.autor);
                        printf("Editorial:\t%s\n",registro.editorial);
                        printf("Precio:\t%.2f\n",registro.precio);
                        printf("Existencia:\t%d\n",registro.existenxia);
                        printf("\nFecha Entrada:\t");
                        printf("\tA\244o:\t%d\n",registro.entrada.ao);
                        printf("\t\t\tMes:\t%d\n",registro.entrada.mes);
                        }               
                   }while(registro.entrada.dia>30||registro.entrada.dia<1);
               }else if(registro.entrada.mes==2)
                        {
                          if(registro.entrada.ao%4==0)
                             {
                               do{
                               
                                     printf("\t\t\tDia:\t");
                                     scanf("%d",&registro.entrada.dia);
                                     
                                     if(registro.entrada.dia>29||registro.entrada.dia<1)
                                        {
                                            system("cls");
                                            system("color f4");
                                            printf("Ingrese un dia valido\n");
                                            system("pause");
                                            system("color f2");
                                            
                                            printf("Clave:\t%d\n",registro.clave);
                                            printf("Tipo:\t%c\n",registro.tipo);
                                            printf("titulo:\t%s\n",registro.titulo);
                                            printf("Autor:\t%s\n",registro.autor);
                                            printf("Editorial:\t%s\n",registro.editorial);
                                            printf("Precio:\t%.2f\n",registro.precio);
                                            printf("Existencia:\t%d\n",registro.existenxia);
                                            printf("\nFecha Entrada:\t");
                                            printf("\tA\244o:\t%d\n",registro.entrada.ao);
                                            printf("\t\t\tMes:\t%d\n",registro.entrada.mes);
                                        }               
                                   }while(registro.entrada.dia>29||registro.entrada.dia<1);
                             }else{
                                   do{
                                         printf("\t\t\tDia:\t");
                                         scanf("%d",&registro.entrada.dia);
                                         
                                         if(registro.entrada.dia>28||registro.entrada.dia<1)
                                         {
                                            system("cls");
                                            if(registro.entrada.dia==29)
                                            {
                                            system("color f4");
                                            printf("NO es biciesto:\nIngrese un dia valido\n");
                                            system("pause");
                                           system("color f2");
                                            }
                                            else
                                                {
                                                  system("color f4");       
                                                 printf("Ingrese un dia valido\n");
                                                 system("pause");
                                                 system("color f2");
                                                }
                                            printf("Clave:\t%d\n",registro.clave);
                                            printf("Tipo:\t%c\n",registro.tipo);
                                            printf("titulo:\t%s\n",registro.titulo);
                                            printf("Autor:\t%s\n",registro.autor);
                                            printf("Editorial:\t%s\n",registro.editorial);
                                            printf("Precio:\t%.2f\n",registro.precio);
                                            printf("Existencia:\t%d\n",registro.existenxia);
                                            printf("\nFecha Entrada:\t");
                                            printf("\tA\244o:\t%d\n",registro.entrada.ao);
                                            printf("\t\t\tMes:\t%d\n",registro.entrada.mes);
                                         }                  
                                      }while(registro.entrada.dia>28||registro.entrada.dia<1);
                                   }
                             }
                                      break;
                                  case 8:
                                       printf("\nFecha Salida:\t");      
                                      
 do{
 printf("\tA\244o:\t");
 scanf("%d",&registro.salida.ao);
 if(registro.salida.ao<1990)
   {
     system("cls");
     system("color f4");
     printf("Ingrese un A\244o valido\n");
      system("pause");
      system("color f2");
        printf("Clave:\t%d\n",registro.clave);
        printf("Tipo:\t%c\n",registro.tipo);
        printf("titulo:\t%s\n",registro.titulo);
        printf("Autor:\t%s\n",registro.autor);
        printf("Editorial:\t%s\n",registro.editorial);
        printf("Precio:\t%.2f\n",registro.precio);
        printf("Existencia:\t%d",registro.existenxia);
        printf("\nFecha Entrada:\t");
        printf("\tA\244o:\t%d\n",registro.entrada.ao);
        printf("\t\t\tMes:\t%d\n",registro.entrada.mes);
        printf("\t\t\tDia:\t%d\n",registro.entrada.dia);
        printf("\nFecha Salida:\t");
        
   }
  }while(registro.salida.ao<1990);
  
  
  do{
     printf("\t\t\tMes:\t");
     scanf("%d",&registro.salida.mes);
     if(registro.salida.mes>12||registro.salida.mes<1)
       {
        system("cls");
      system("color f4");
        printf("Ingrese un Mes valido\n");
        system("pause");
      system("color f2");
       
        printf("Clave:\t%d\n",registro.clave);
        printf("Tipo:\t%c\n",registro.tipo);
        printf("titulo:\t%s\n",registro.titulo);
        printf("Autor:\t%s\n",registro.autor);
        printf("Editorial:\t%s\n",registro.editorial);
        printf("Precio:\t%.2f\n",registro.precio);
        printf("Existencia:\t%d\n",registro.existenxia);
        printf("\nFecha Entrada:\t");
        printf("\tA\244o:\t%d\n",registro.entrada.ao);
        printf("\t\t\tMes:\t%d\n",registro.entrada.mes);
        printf("\t\t\tDia:\t%d\n",registro.entrada.dia);
        printf("\nFecha Salida:\t");
        printf("\tA\244o:\t%d\n",registro.salida.ao);
        }
    }while(registro.salida.mes>12||registro.salida.mes<1);
   
     if(registro.salida.mes==1||registro.salida.mes==3||registro.salida.mes==5||registro.salida.mes==7||registro.salida.mes==8||registro.salida.mes==10||registro.salida.mes==12)
       {
         do{
             printf("\t\t\tDia:\t");
             scanf("%d",&registro.salida.dia);
             if(registro.salida.dia>31||registro.salida.dia<1)
                {
                system("cls");
               system("color f4");
                printf("Ingrese un dia valido\n");
                system("pause");
                system("color f2");
                
                printf("Clave:\t%d\n",registro.clave);
                printf("Tipo:\t%c\n",registro.tipo);
                printf("titulo:\t%s\n",registro.titulo);
                printf("Autor:\t%s\n",registro.autor);
                printf("Editorial:\t%s\n",registro.editorial);
                printf("Precio:\t%.2f\n",registro.precio);
                printf("Existencia:\t%d\n",registro.existenxia);
                printf("\nFecha Entrada:\t");
                printf("\tA\244o:\t%d\n",registro.entrada.ao);
                printf("\t\t\tMes:\t%d\n",registro.entrada.mes);
                printf("\t\t\tDia:\t%d\n",registro.entrada.dia);
                printf("\nFecha Salida:\t");
                printf("\tA\244o:\t%d\n",registro.salida.ao);
                printf("\t\t\tMes:\t%d\n",registro.salida.mes);
                }               
           }while(registro.salida.dia>31||registro.salida.dia<1);
       }else if(registro.salida.mes==4||registro.salida.mes==6||registro.salida.mes==9||registro.salida.mes==11) 
               {
                 do{
                      
                       
                     printf("\t\t\tDia:\t");
                     scanf("%d",&registro.salida.dia);
                     
                     if(registro.salida.dia>30||registro.salida.dia<1)
                        {
                        system("cls");
                        system("color f4");
                        printf("Ingrese un dia valido\n");
                        system("pause");
                        system("color f2");
                        
                        printf("Clave:\t%d\n",registro.clave);
                        printf("Tipo:\t%c\n",registro.tipo);
                        printf("titulo:\t%s\n",registro.titulo);
                        printf("Autor:\t%s\n",registro.autor);
                        printf("Editorial:\t%s\n",registro.editorial);
                        printf("Precio:\t%.2f\n",registro.precio);
                        printf("Existencia:\t%d\n",registro.existenxia);
                        printf("\nFecha Entrada:\t");
                        printf("\tA\244o:\t%d\n",registro.entrada.ao);
                        printf("\t\t\tMes:\t%d\n",registro.entrada.mes);
                        printf("\t\t\tDia:\t%d\n",registro.entrada.dia);
                        printf("\nFecha Salida:\t");
                        printf("\tA\244o:\t%d\n",registro.salida.ao);
                        printf("\t\t\tMes:\t%d\n",registro.salida.mes);
                        }               
                   }while(registro.salida.dia>30||registro.salida.dia<1);
               }else if(registro.salida.mes==2)
                        {
                          if(registro.salida.ao%4==0)
                             {
                               do{
                               
                                     printf("\t\t\tDia:\t");
                                     scanf("%d",&registro.salida.dia);
                                     
                                     if(registro.salida.dia>29||registro.salida.dia<1)
                                        {
                                            system("cls");
                                            system("color f4");
                                            printf("Ingrese un dia valido\n");
                                            system("pause");
                                            system("color f2");
                                            
                                            printf("Clave:\t%d\n",registro.clave);
                                            printf("Tipo:\t%c\n",registro.tipo);
                                            printf("titulo:\t%s\n",registro.titulo);
                                            printf("Autor:\t%s\n",registro.autor);
                                            printf("Editorial:\t%s\n",registro.editorial);
                                            printf("Precio:\t%.2f\n",registro.precio);
                                            printf("Existencia:\t%d\n",registro.existenxia);
                                            printf("\nFecha Entrada:\t");
                                            printf("\tA\244o:\t%d\n",registro.entrada.ao);
                                            printf("\t\t\tMes:\t%d\n",registro.entrada.mes);
                                            printf("\t\t\tDia:\t%d\n",registro.entrada.dia);
                                            printf("\nFecha Salida:\t");
                                            printf("\tA\244o:\t%d\n",registro.salida.ao);
                                            printf("\t\t\tMes:\t%d\n",registro.salida.mes);
                                        }               
                                   }while(registro.salida.dia>29||registro.salida.dia<1);
                             }else{
                                   do{
                                         printf("\t\t\tDia:\t");
                                         scanf("%d",&registro.salida.dia);
                                         
                                         if(registro.salida.dia>28||registro.salida.dia<1)
                                         {
                                            system("cls");
                                            if(registro.salida.dia==29)
                                            {
                                            system("color f4");
                                            printf("NO es biciesto:\nIngrese un dia valido\n");
                                            system("pause");
                                           system("color f2");
                                            }
                                            else
                                                {
                                                  system("color f4");       
                                                 printf("Ingrese un dia valido\n");
                                                 system("pause");
                                                 system("color f2");
                                                }
                                            printf("Clave:\t%d\n",registro.clave);
                                            printf("Tipo:\t%c\n",registro.tipo);
                                            printf("titulo:\t%s\n",registro.titulo);
                                            printf("Autor:\t%s\n",registro.autor);
                                            printf("Editorial:\t%s\n",registro.editorial);
                                            printf("Precio:\t%.2f\n",registro.precio);
                                            printf("Existencia:\t%d\n",registro.existenxia);
                                            printf("\nFecha Entrada:\t");
                                            printf("\tA\244o:\t%d\n",registro.entrada.ao);
                                            printf("\t\t\tMes:\t%d\n",registro.entrada.mes);
                                            printf("\t\t\tDia:\t%d\n",registro.entrada.dia);
                                            printf("\nFecha Salida:\t");
                                            printf("\tA\244o:\t%d\n",registro.salida.ao);
                                            printf("\t\t\tMes:\t%d\n",registro.salida.mes);
                                         }                  
                                      }while(registro.salida.dia>28||registro.salida.dia<1);
                                   }
                             }
                                      break;
                                  case 9:
                                       break;
                                  default:
                                          printf("Ingrese una opcion valida");
                                          break;
                                }//fin swithc
                              break; 
                      }else{
                             system("color f4");
                             printf("\nLa Clave esta de baja\n\n");
                             system("pause");
                             system("color f2");
                             break;
                             }
                             

                  }
         
           }//while
            
           fseek(archivo, -sizeof(sRegistro), SEEK_CUR);
           fwrite(&registro, sizeof(sRegistro),1, archivo);
           fclose(archivo);
         
     if(id==9999||id>9999)
            return;
            if((registro.clave)!=id)
              {system("color f4"); 
                printf("\nClave NO Existe\n\n");
                 system("pause");
                  system("color f2");
                 
                 }
          
            system("cls"); 
             
          }while(id<9999&&id!=9999);   
      
}


