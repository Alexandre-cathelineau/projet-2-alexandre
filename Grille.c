#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Grille.h"


void grille(char reponse[9])  
{

    printf("| %c | %c | %c |\n",reponse[0],reponse[1],reponse[2]);
    printf("|---|---|---|\n");
    printf("| %c | %c | %c |\n",reponse[3],reponse[4],reponse[5]);
    printf("|---|---|---|\n");
    printf("| %c | %c | %c |\n",reponse[6],reponse[7],reponse[8]);

}

void croix(char reponse[9])
{
    int position;
    int ok=0;
    
    while (ok==0)
    {
        printf("tu veux poser la croix ou: \n");
        if (scanf("%d", &position) != 1)
        {
            printf("Saisie invalide !\n");
            return;
        }

        if (position >= 0 && position <= 8 && reponse[position] == ' ')
        {
            ok=1;
            reponse[position] = 'X';
        }
        else
        {
            printf("Position invalide !\n");
        }
    }
}

void rond(char reponse[9])
{
    int random_number;
    int ok=1;

    while (ok ==1)
    {
        random_number = rand() % 9;
        
        if (reponse[random_number] != ' ')
        {
            ok=1;
        }
        else
        {
            reponse[random_number]= 'O';
            break;
        }
    }
}

int gagnant(char reponse[9])
{
    if (reponse[0]==reponse[1] && reponse[1]==reponse[2] && reponse[0]!= ' ')
    {
        return 1;
    }
    if (reponse[3]==reponse[4] && reponse[4]==reponse[5] && reponse[3]!= ' ')
    {
        return 1;
    }
    if (reponse[6]==reponse[7] && reponse[7]==reponse[8] && reponse[6]!= ' ')
    {
        return 1;
    }


    if (reponse[0]==reponse[3] && reponse[3]==reponse[6] && reponse[0]!= ' ')
    {
        return 1;
    }
    if (reponse[1]==reponse[4] && reponse[4]==reponse[7] && reponse[1]!= ' ')
    {
        return 1;
    }
    if (reponse[2]==reponse[5] && reponse[5]==reponse[8] && reponse[2]!= ' ')
    {
        return 1;
    }


    if (reponse[0]==reponse[4] && reponse[4]==reponse[8] && reponse[0]!= ' ')
    {
        return 1;
    }
    if (reponse[2]==reponse[4] && reponse[4]==reponse[6] && reponse[2]!= ' ')
    {
        return 1;
    }
    return 0;
    
}

int nul(char reponse[9])
{
    int i=0;

    while (i<9)
    {
        if (reponse[i]==' ')
        {
            return 0;
        }
        i++;
    }
    return 1;
}