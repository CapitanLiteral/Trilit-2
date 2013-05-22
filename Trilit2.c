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
        int tematica; // 1 --> Ciencia // 2 --> Humanistic // 3 --> Cultura general //
        int dificultat; // de 1 a 3

    }preguntes;

    typedef struct
    {
        int  id;
        char nik[25];
        char pass[16]; 
    }usuari;

//Funcions
    void menu (void);
    int login (void);
    void merl(void);
    void registre(void);
    void sobre(void);
    void alta(preguntes *);

// Body
 int main (void)
     {
    // Crear Structs
        preguntes pregunta[100];
        FILE * fpreguntes;
    // Variables
        int i;
        i = -1;
// Copiar preguntes a struct
    fpreguntes = fopen("data\\pregun.bin", "rb");
    if(fpreguntes == NULL)
    {
        fpreguntes = fopen("data\\pregun.bin", "wb+");
    }
    else
    {
        i = 0;
        do
        {
            fread(&pregunta[i], sizeof(preguntes), 1, fpreguntes);
            pregunta[i].id = i;
            i++;
        }while (feof(fpreguntes) == 0);      
        fclose(fpreguntes);
        // Imprimir preguntes PROVA
        i = 0;
        while(pregunta[i].id != -1)
        {
            printf("id: %s\n", pregunta[i].id);
            printf("Enunciat: %s\n", pregunta[i].enunciat);
            i++;
        }
    } 
    pregunta[i+1].id = -1;   
// Menu Inicial

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
    while (opcio != 4)   //El numero es igual al numero d'opcions
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
              sobre();
              
        }
    }

}
// Menu --------------------------------------------------------------------------- PLANTILLA
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
        fflush(stdin);
        scanf("%d", &opcio);
        fflush(stdin);
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
int login(void)
{
    char nik[25];
    char contrasenya[16];
    char caracter;
    usuari usuaris[200];

    printf("\n\t Login\n\n\n");
    printf("Nikname: ");
    gets(nik);
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
    if (nik == "admin" && contrasenya == "admin")
    {
        return(1);
    }
    else
    {
        return(0);
    }
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
            auser[i].id = i;
            i++;
        }while (feof(fusuaris) == 0);      
        fclose(fusuaris);
        auser[i+1].id = -1;

        i = 0;
        while(auser[i].id != -1)
        {
            printf("nik: %s\n", auser[i].nik);
            printf("pass: %s\n", auser[i].pass);
            i++;
        }
    // Comprovar si aquest nom d'usuari ja hi es dins el Array de Structs.
        i = 0;
        while(auser[i].id != -1 && pillat == 0)
        {
            if(strcmp(ruser.nik, auser[i].nik) == 0)
            {
                printf("Aquest nom d'usuari ja ha estat escollit.\n");
                pillat = 1;
            }            
            i++;
        }
        if (pillat == 0)
        {
        // Escriure el struct al fitxer
            fusuaris = fopen("data\\usuaris.bin", "ab");
            fwrite(&ruser, sizeof(usuari), 1, fusuaris);
            fclose(fusuaris);        
        }
    // Copiar fitxer a array de structs

        fusuaris = fopen("data\\usuaris.bin", "rb");
        i = 0;
        do
        {
            fread(&auser[i], sizeof(usuari), 1, fusuaris);
            i++;
        }while (feof(fusuaris) == 0);      
        fclose(fusuaris);
        i = 0;
        while(auser[i].id != -1)
        {
            printf("2nik: %s\n", auser[i].nik);
            printf("2pass: %s\n", auser[i].pass);
            i++;
        }
}

// Sobre el Joc PER ACABAR
void sobre(void)
{
    printf("El joc esta sent construit. PACIENCIA!\n");
    printf(".\n");
    printf(".\n");
    printf(".\n");
}

// Alta preguntes
void alta(preguntes *inipreg)
{
    preguntes *pregunta;
    pregunta = inipreg;
    int i, opcio;
    opcio = -1;
    // Trobar pregunta final +1
    while ((*pregunta).id != -1)
    {
        pregunta++;
    }
    if ((*(pregunta+1)).id == -1)
    {
        pregunta++;
    }

    // Introduir dades pregunta
        // Enunciat
            printf("Introdueixi l'enunciat:");
            gets((*pregunta).enunciat);
        // Solucions Falses
            i = 0;
            do
            {
                printf("\nIntrodueixi la resposta falsa nº%d\n", i+1);
                gets((*pregunta).solucions[i]);
                i++;
            }while(i < 6);
        // Solucio Correcta
            printf("\nIntrodueixi la resposta correcta\n");
            gets((*pregunta).correcta);
        // Tematica
            printf("\nIntrodueixi una tematica:\n");
            printf("\n1.- Ciencia\n");
            printf("2.- Humanistic\n");
            printf("3.- Cultura General\n");
            fflush(stdin);
            scanf("%d", &opcio);
            fflush(stdin);
            while(opcio < 0 || opcio > 3)
            {
                printf("Ha introduit una opcio incorrecta, torni a introduir una opcio.\n");
                scanf("%d", &opcio);
            }
            if(opcio==1)
            {
                  (*pregunta).tematica = 1;  
                         
            }
            else if(opcio==2)
            {
                  (*pregunta).tematica = 2;
            }      
            else if(opcio==3)
            {
                  (*pregunta).tematica = 3;
                  
            }
        // Dificultat
            printf("\nIntrodueixi una dificultat:\n");
            printf("\n1.- Facil\n");
            printf("2.- Mitg\n");
            printf("3.- Dificil\n");
            fflush(stdin);
            scanf("%d", &opcio);
            fflush(stdin);
            while(opcio < 0 || opcio > 3)
            {
                printf("Ha introduit una opcio incorrecta, torni a introduir una opcio.\n");
                scanf("%d", &opcio);
            }
            if(opcio==1)
            {
                    (*pregunta).dificultat = 1;
                         
            }
            else if(opcio==2)
            {
                  (*pregunta).dificultat = 2;
            }      
            else if(opcio==3)
            {
                  (*pregunta).dificultat = 3;
                  
            }
}
// Baixa preguntes --------------------------- (Opcional)

// Modificar preguntes ----------------------- (Opcional)

// Mostra preguntes



