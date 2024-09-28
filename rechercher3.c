#include<stdio.h>
#include<string.h>
void Rechercher(char A ,char B ,float C ,int D)
{
    char nom;
    printf("Saisir le nom de livre a rechercher : ");
    scanf("%s",nom);
    if (strcmp(A,nom))
    {
        printf("Le livre existe dans la Librairie . Ses informations est : \n");
        printf("Livre %d :\t",j);
        printf("%s.\n",&A[i][30]);
        printf("%s.\n",&B[i][30]);
        printf("Prix:%f.\n",&C[i]);
        printf("Qantite:%d.\n",&D[i]);        
    }
    else 
    {
        printf("Cette livre n'existe pas dans la Libairire.\n");
    }
}