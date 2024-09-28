#include<stdio.h>
#include<string.h>
#define num 100
#define i
int main(int argc, char const *argv[])
{
    char Titre_Livre[num][30];
    char Auteur_Live[num][30];
    float Prix[num];
    int Quantite[num];
    int n;
    do
    {
       printf("---Menu---\n\n");
        printf("1.Ajouter un livre au stock.\n");
        printf("2.Afficher tous les livres disponibles.\n");
        printf("3.Rechercher un livre par son titre.\n");
        printf("4.Mettre à jour la quantité d'un livre.\n");
        printf("5.Supprimer un livre du stock.\n");
        printf("6.Afficher le nombre total de livres en stock.\n");
        printf("7.Sortir.\n");
        printf("Donner votre choix ? \n ");
        scanf("%d",&n);
        switch (n)
        {
        case 1 :
            Ajouter(Titre_Livre, Auteur_Live, Prix,Quantite);
            break;
        case 2 :
            Affichage(Titre_Livre, Auteur_Live, Prix, Quantite);
            break;
        case 3 :
            
            break;
        case 4 :
            
            break;
        case 5 :
            
            break;
        case 6 :
            
            break;        
        default:
            break;
        }
    } while (n >= 0 || n < 7);

    return 0;
}
