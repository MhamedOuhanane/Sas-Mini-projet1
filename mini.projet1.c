#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define n1 10000
#define n2 30

void Ajouter();
void Affichage();
void Rechercher();
int Mette_a_jour();
void Supprimer_Livre();
int Quantite_Total();

char Titre_Livre[n1][30];
char Auteur_Livre[n1][30];
float Prix[n1];
int Quantite[n1];
int i = 0;

int main()
{
    int a ,n , c;
    do
    {
        printf("---Menu---\n\n");
        printf("1.Ajouter un livre au stock.\n");
        printf("2.Afficher tous les livres disponibles.\n");
        printf("3.Rechercher un livre par son titre.\n");
        printf("4.Mettre a jour la quantite d'un livre.\n");
        printf("5.Supprimer un livre du stock.\n");
        printf("6.Afficher le nombre total de livres en stock.\n");
        printf("7.Sortir.\n");
        printf("Donner votre choix ? \n ");
        scanf("%d",&n);
        getchar();
        switch (n)
        {
        case 1 :
            Ajouter();
            i++;
            break;
        case 2 :
            Affichage();
            break;
        case 3 :
            Rechercher();
            break;
        case 4 :
            c = Mette_a_jour();
            printf("Donner la nouvelle quantite de livre : ");
            scanf("%d",&a);
            getchar();
            Quantite[c] = a;
            printf("La quantite est mette a jour.\n");
            break;
        case 5 :
            Supprimer_Livre();
            break;
        case 6 :
            printf("le Nombre Total de Livres en Stock est S = %d\n",Quantite_Total(Quantite));
            break;  
            case 7:
                return 0; 
        }
    } while (1);
    return 0;
}
void Ajouter()
{
    printf("Entrer le titre du livre : ");
    fgets(Titre_Livre[i],n2,stdin);
    Titre_Livre[i][strcspn(Titre_Livre[i],"\n")] = 0;
    printf("Donner le nom de l'auteur : ");
    fgets(Auteur_Livre[i],n2,stdin);
    Auteur_Livre[i][strcspn(Auteur_Livre[i],"\n")] = 0;
    printf("Entrer le prix : ");
    scanf("%f",&Prix[i]);
    getchar();
    printf("La Quantite a ajouter : ");
    scanf("%d",&Quantite[i]);
    getchar();
}
void Affichage() {
    if (i == 0) {
        printf("La Librairie est vide!\n\n");
    } else {
        for (int j = 0; j < i; j++) {
            printf("----Livre %d----\n", j + 1);
            printf("Titre: %s\n",Titre_Livre[j]);
            printf("Auteur: %s\n",Auteur_Livre[j]);
            printf("Prix: %.2f\n",Prix[j]);
            printf("Quantite: %d\n\n",Quantite[j]);
        }
    }
}
void Rechercher()
{
    char nom[n2];
    int j ,a;
    printf("Saisir le nom de livre a rechercher : ");
    fgets(nom,n2,stdin);
    nom[strcspn(nom,"\n")] = 0;
    for ( j = 1; j < i; j++)
    {
        a = 0;
        if (strcmp(Titre_Livre[j], nom))
        {
            printf("Le livre existe dans la Librairie . Ses informations est : \n");
            printf("Livre %d :\t",j);
            printf("Titre : %s\n",Titre_Livre[i]);
            printf("Auteur : %s\n",Auteur_Livre[i]);
            printf("Prix: %.2f\n",Prix[i]);
            printf("Quantite: %d\n",Quantite[i]); 
            a = 1;       
        }
    }
    if(a == 0) 
    {
        printf("Cette livre n'existe pas dans la Libairire.\n");
    }
}
int Mette_a_jour()
{
    int j;
    char a[n2];
    printf("Donner le titre de livre a mette a jours sa quantite : ");
    fgets(a,n2,stdin);
    a[strcspn(a,"\n")] = 0;
    for ( j = 0; j < i; j++)
    {
        if (strcmp(Titre_Livre[j],a))
        {
            return j;
            break;
        }
    }
}  
void Supprimer_Livre()
{
    char a[n2];
    int j , o,l;
    printf("Donner le titre de livre a supprimer : ");
    fgets(a,n2,stdin);
    a[strcspn(a,"\n")] = 0;
    for ( j = 0; j < i; j++)
    {
        if (strcmp(Titre_Livre[j],a))
        {
            for ( o = j; o < i-1; o++)
            {
                for ( l = 0; l < n2; l++)
                {
                    Titre_Livre[o][l] = Titre_Livre[o+1][l];
                    Auteur_Livre[o][l] = Auteur_Livre[o+1][l];
                }
                Prix[o] = Prix[o+1];
                Quantite[o] = Quantite[o+1];
            
            }
            i--;
            break;
        }
    }
}
int Quantite_Total()
{
    int j , s = 0;
    for ( j = 0; j < i; j++)
    {
        s += Quantite[j];
    }
    return s;
}


