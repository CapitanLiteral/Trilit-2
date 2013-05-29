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
// Struct de usuaris
    typedef struct
    {
        int  id;
        char nik[25];
        char pass[16]; 
    }usuari;

//Funcions
    void menu (void);
    int login (void);
    int merl(void);
    void registre(void);
    void sobre(void);
    void alta(preguntes *);
    int menuAdmin(void);
    int menuUser(void);
    void jugar(void);
    void continuarPartida(void);
    void consultarPreguntes(void);
    void entreno(void);

// MAIN ************************************************************************* MAIN
 int main (void)
{
    // Crear Structs
        preguntes pregunta[100];
        FILE * fpreguntes;
    // Variables
        int i, cmerl, clogin, cMenuAdmin, cMenuUser;
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
        while (feof(fpreguntes) == 0)
        {
            fread(&pregunta[i], sizeof(preguntes), 1, fpreguntes);
            pregunta[i].id = i;
            i++;
        }      
        fclose(fpreguntes);
        // Imprimir preguntes PROVA
        i = 0;
    } 
    pregunta[i+1].id = -1;  
    
    /*i=0;
    while (i < 5)
    {
        alta(&pregunta[0]);     
    } */
    
// Menu Inicial
do
{

    cmerl = merl();
    // Login
    if (cmerl == 1)
    {
        clogin = login();
        // Administrador
        if (clogin == 1)
        {
            do
            {
                cMenuAdmin = menuAdmin();
                // 
                if (cMenuAdmin == 1)
                {
                    alta(&pregunta[0]);
                }
                else if (cMenuAdmin == 2)
                {
                    //continuarPartida();
                }
                else if (cMenuAdmin == 3)
                {
                    //jugar();
                }
                else if (cMenuAdmin == 4)
                {
                    //consultarPreguntes();
                }
                else if (cMenuAdmin == 5)
                {
                    //entreno();
                }
            } while (cMenuAdmin != 6);
        }
        // usuari
        else if (clogin == 0)
        {
            do
            {
                cMenuUser = menuUser();
            } while (cMenuUser =! 5);
            printf("usuari\n");
        }
    }
    // Registre
    else if (cmerl == 2)
    {
        registre();
    }
    // Sobre
    else if (cmerl == 3)
    {
        sobre();
    }    

} while (cmerl != 1);
    
// Pegar alta preguntes al Fitxer
    fpreguntes = fopen("data\\pregun.bin", "wb");
    i = 0;
    while (pregunta[i].id != -1)
    {
        fwrite(&pregunta[i], sizeof(preguntes), 1, fpreguntes);
        i++;
    }     
    fclose(fpreguntes);

}

//*************************************************
//**                  Funcions                   **
//*************************************************
// Menu Login/Registre
int merl(void)
{
    //Declaració variables menú
        int opcio; // controla el menú
        int privilegis; // 1 --> admin || 0 --> user
    //inicialitzacio variables menú
        opcio = -1;
   
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
        if(opcio == 1)
        {
            return(1);         
        }
        else if(opcio == 2)
        {
            
            return(2);
        }      
        else if(opcio == 3)
        {
            return(3);
        }
        else if(opcio == 4)
        {
            return(-1);
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
// Menu ADMIN --------------------------------------------------------------------- Menu ADMIN
int menuAdmin(void)
{

    //Declaració variables menú
        int opcio; // controla el menú
    //inicialitzacio variables menú
        opcio = -1;
        printf("\t\tAdministrador\n");
        printf("\n1.- Alta de preguntes\n");
        printf("2.- Continuar partida\n");
        printf("3.- Partida nova\n");
        printf("4.- Consultar preguntes\n");
        printf("5.- Entrenament\n");
        printf("6.- EXIT.\n");
        fflush(stdin);
        scanf("%d", &opcio);
        fflush(stdin);
        while(opcio < 0 || opcio > 6)
        {
            printf("Ha introduit una opcio incorrecta, torni a introduir una opcio.\n");
            scanf("%d", &opcio);
        }
        if(opcio == 1)
        {  
            return(1);        
        }
        else if(opcio == 2)
        {
            return(2);
        }      
        else if(opcio == 3)
        {
            return(3);              
        }
        else if(opcio == 4)
        {              
            return(4);     
        }
        else if (opcio == 5)
        {
            return(5);
        }
        else if (opcio == 6)
        {
            return(6);
        }
}
// Menu USER ---------------------------------------------------------------------- Menu USER
int menuUser(void)
{

    //Declaració variables menú
        int opcio; // controla el menú
    //inicialitzacio variables menú
        opcio = -1;
        printf("\t\tUsuari\n");
        printf("1.- Continuar partida\n");
        printf("2.- Partida nova\n");
        printf("3.- Consultar preguntes\n");
        printf("4.- Entrenament\n");
        printf("5.- EXIT.\n");
        fflush(stdin);
        scanf("%d", &opcio);
        fflush(stdin);
        while(opcio < 0 || opcio > 5)
        {
            printf("Ha introduit una opcio incorrecta, torni a introduir una opcio.\n");
            scanf("%d", &opcio);
        }
        if(opcio == 1)
        {  
            return(1);        
        }
        else if(opcio == 2)
        {
            return(2);
        }      
        else if(opcio == 3)
        {
            return(3);              
        }
        else if(opcio == 4)
        {              
            return(4);     
        }
        else if (opcio == 5)
        {
            return(5);
        }

}
// Login -------------------------------------------------------------------------- Login
int login(void)
{
    char nik[25];
    char contrasenya[16];
    char caracter;
    usuari usuaris[200];

    printf("\n\t Login\n\n\n");
    printf("Nikname: ");
    fflush(stdin);
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
    printf("\n\n\n");
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
// Registre ----------------------------------------------------------------------- Registre
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

// Alta preguntes ----------------------------------------------------------------- Alta Pregunte
void alta(preguntes *inipreg)
{
    preguntes *pregunta;
    pregunta = inipreg;
    int i, opcio, v_id;
    opcio = -1;
    v_id = 0;
    // Trobar pregunta final +1
    while ((*pregunta).id != -1)
    {
        pregunta++;
        v_id++;
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
            (*pregunta).id = v_id+1;
            (*(pregunta+1)).id = -1;       
}
// Baixa preguntes --------------------------- (Opcional)

// Modificar preguntes ----------------------- (Opcional)

// Mostra preguntes

