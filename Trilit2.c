/*
	Name: TRILIT2
	Author: Capitàn Literal
	Date: Start --> 15/05/2013 End --> 
	Description: Trivial
*/
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

//Struct de preguntes

    typedef struct
    {
        int id;
        char enunciat[100];
        char solucions[6][100]; //[Files][Cols] Son mes de 3 perque potser implemento que les incorrectes no sempre siguin iguals 
        char correcta[100];
        int tematica; // 1 --> // 2 --> // 3 --> //
        int dificultat; // de 1 a 3

    }preguntes;

    typedef struct
    {
        char nik[25];
        char pass[16]; 
    }usuari;

//Funcions
    void menu (void);
    void login (void);
    void merl(void);
    void registre(void);

// Body
 int main (void)
 {
    merl();

 }

//*************************************************
//**                  Funcions                   **
//*************************************************
// Menu Login/Registre
void merl(void)
{
    //Declaració variables menú
        int opcio; // controla el menú
    //inicialitzacio variables menú
        opcio = -1;
    while (opcio != 4)/*el numero depen del nombre d'opcions*/
    {    
        printf("\tTRILI 2\n");
        printf("\n1.- Login\n");
        printf("2.- Registrarse\n");
        printf("3.- Sobre el joc\n");
        printf("4.- EXIT.\n");
        scanf("%d", &opcio);
        while(opcio < 0 || opcio > 4)
        {
            printf("Ha introduit una opcio incorrecta, torni a introduir una opcio.\n");
            scanf("%d", &opcio);
        }
        if(opcio==1)
        {
              login();  
                     
        }
        else if(opcio==2)
        {
              registre();
        }      
        else if(opcio==3)
        {
              
              
        }
    }

}
// Menu --------------------------------------------------------------------------- S'ha de retocar
void menu(void)
{

    //Declaració variables menú
        int opcio; // controla el menú
    //inicialitzacio variables menú
        opcio = -1;
 
    while (opcio != 5)/*el numero depen del nombre d'opcions*/
    {
        printf("\n1.- Exemple de primera opcio.\n");
        printf("2.- Exemple de segona opcio.\n");
        printf("3.- Exemple de tercera opcio.\n");
        printf("4.- Exemple de quarta opcio.\n");
        printf("5.- EXIT.\n");
        scanf("%d", &opcio);
        while(opcio < 0 || opcio > 5)
        {
            printf("Ha introduit una opcio incorrecta, torni a introduir una opcio.\n");
            scanf("%d", &opcio);
        }
        if(opcio==1)
        {
                
                     
        }
        else if(opcio==2)
        {
              
        }      
        else if(opcio==3)
        {
              
              
        }
        else if(opcio==4)
        {
              
              
        } 
          
    }   
        
}
// Login
void login(void)
{
    char usuari[25];
    char contrasenya[16];
    char caracter;

    printf("\n\t Login\n\n\n");
    printf("Usuari: ");
    gets(usuari);
    printf("\nContrasenya: ");
    do
    {
        caracter = getch();
        if (caracter != 13)
        {
            printf("*");
        }        
        //printf("%d", caracter);
    } while (caracter != 13 );

    printf("\nlogin complet!\n");
    
     
}
// Registre
void registre(void)
{
    // Creacio de variables
        FILE *fusuaris;
        usuari ruser, auser[100];
        int i, j, pos, pillat;
        pillat = 0;
    // Inicialitzar struct a '\0'
        // RUSER
        for (i = 0; i < 25; ++i)
        {
            ruser.nik[i] = '\0';
        }
        for (i = 0; i < 16; ++i)
        {
            ruser.pass[i] = '\0';
        }
        // AUSER
        /*for(i = 0; i < 100; i++)
        {
            for(j = 0; j < 25; j++)
            {
                auser[j].nik[j] = '\0';
            }
            for (j = 0; j < 16; ++j)
            {
                auser[j].pass[j] = '\0';
            }
        }*/
    // Recollida de dades
        printf("Usuari: ");
        fflush(stdin);
        gets(ruser.nik);
        fflush(stdin),
        printf("\nContrasenya: ");
    // Convertir caracters en * 
        i = -1;
        do
        {
            i++;
            ruser.pass[i] = getch();
            if (ruser.pass[i] != 13)
            {
                printf("*");
            }        
            //printf("%d", caracter);
        } while(ruser.pass[i] != 13 ); 
        printf("\n"); 
    // Copiar fitxer a array de structs

        fusuaris = fopen("data\\usuaris.bin", "rb");
        i = 0;
        do
        {
            printf("3\n");
            fread(&auser[i], sizeof(usuari), 1, fusuaris);
            i++;
        }while (feof(fusuaris) == 0);      
        fclose(fusuaris);

        for (i = 0; i < 20; ++i)
        {
            printf("nik: %s\n", auser[i].nik);
            printf("pass: %s\n", auser[i].pass);
        }
    // Comprovar si aquest nom d'usuari ja hi es.
        for (i = 0; i < 100; ++i)
        {
            if(strcmp(ruser.nik, auser[i].nik) == 0)
            {
                printf("Aquest nom d'usuari ja ha estat escollit.\n");
                i=100;
                pillat = 1;
            }            
        }
        if (pillat == 0)
        {
        // Escriure el struct al fitxer
            fusuaris = fopen("data\\usuaris.bin", "ab");
            fwrite(&ruser, sizeof(usuari), 1, fusuaris);
            fclose(fusuaris);        
        }

   /* // Buscar lloc buit per a registrar nou usuari.
        while(ruser[i].nik[1] != '\0')
        {
            pos = i;
            i++;
        }
 */
        printf("hola git\n");
    // Copiar fitxer a array de structs

        fusuaris = fopen("data\\usuaris.bin", "rb");
        i = 0;
        do
        {
            fread(&auser[i], sizeof(usuari), 1, fusuaris);
            i++;
        }while (feof(fusuaris) == 0);      
        fclose(fusuaris);

        for (i = 0; i < 20; ++i)
        {
            printf("2nik: %s\n", auser[i].nik);
            printf("2pass: %s\n", auser[i].pass);
        }
}



