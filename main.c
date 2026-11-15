#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Grille.h"

int main(void)
{
    char reponse[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int i=0;


    while (i<9)
    {
        croix(reponse);


        if (gagnant(reponse) == 1)
        {
            grille(reponse);
            printf("vous avez gager !\n");
            break;
        }
        if (nul(reponse)==1)
        {
            printf("il y a egalitée\n");
            break;
        }


        srand(time(NULL));
        rond(reponse);

        grille(reponse);
        
        if (gagnant(reponse) == 1)
        {
            printf("l'ordinateur a gagner !\n");
            break;
        }
        if (nul(reponse)==1)
        {
            printf("il y a egalitée\n");
            break;
        }

        i+=1;
    }

    return 0;
}
