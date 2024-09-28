#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define n2 30

void Ajouter();
void Affichage();
void Rechercher();
int Mette_a_jour();
void Supprimer_Livre();
int Quantite_Total();
void clearBuffer();

int i = 0;
char Titre_Livre[10000][30];
char Auteur_Livre[10000][30];
float Prix[10000];
int Quantite[10000];

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

        switch (n)
        {
        case 1 :
            Ajouter();
            break;
        case 2 :
            Affichage();
            break;
        case 3 :
            Rechercher();
            break;
        case 4 :
            c = Mette_a_jour(Titre_Livre);
            printf("Donner la nouvelle quantite de livre : ");
            scanf("%d",&a);
            Quantite[c] = a;
            printf("La quantite est mette a jour...!");
            break;
        case 5 :
            Supprimer_Livre();
            i--;
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
    getchar();
    ++i;
    printf("Entrer le titre du livre : ");
    fgets(Titre_Livre[i],n2,stdin);  
    printf("Donner le nom de l'auteur : ");
    fgets(Auteur_Livre[i],n2,stdin);                    
    printf("Entrer le prix : ");
    scanf("%f",Prix[i]);
    printf("La Quantite a ajouter : ");
    scanf("%d",Quantite[i]);
    clearBuffer();
}
void Affichage()
{
    int j;
    if (i == 0)
    {
        printf("la Librairie est vide!\n\n");
    }
    else
    {
        for ( j = 1; j < i; j++)
        {
            printf("Livre %d :\t",j);
            printf("%s.\t",Titre_Livre[j]);
            printf("%s.\t",Auteur_Livre[j]);
            printf("Prix:%f.\t",&Prix[i]);
            printf("Qantite:%d.\n\n",&Quantite[j]);
        }
    }
}
void Rechercher()
{
    clearBuffer();
    char nom[n2];
    int j ,a;
    printf("Saisir le nom de livre a rechercher : ");
    fgets(nom,n2,stdin);
    for ( j = 0; j < i; j++)
    {
        a = 0;
        if (strcmp(Titre_Livre[j], nom))
        {
            printf("Le livre existe dans la Librairie . Ses informations est : \n");
            printf("Livre %d :\t",j);
            printf("%s.\n",&Titre_Livre[i]);
            printf("%s.\n",&Auteur_Livre[i]);
            printf("Prix:%.f.\n",&Prix[i]);
            printf("Qantite:%d.\n",&Quantite[i]); 
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
    getchar();
    int j;
    char a[n2];
    printf("Donner le titre de livre a mette a jours sa quantite : ");
    fgets(a,n2,stdin);
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
    getchar();
    char a[n2];
    int j , o,l;
    printf("Donner le titre de livre a supprimer : ");
    fgets(a,n2,stdin);
    for ( j = 0; j < i; j++)
    {
        if (strcmp(Titre_Livre[j],a))
        {
            for ( o = j; o < i; o++)
            {
                for ( l = 0; l < n2; l++)
                {
                    Titre_Livre[o][l] = Titre_Livre[o+1][l];
                    Auteur_Livre[o][l] = Auteur_Livre[o+1][l];
                }
                Prix[o] = Prix[o+1];
                Quantite[o] = Quantite[o+1];
            
            }
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
void clearBuffer()
{
    int c ;
    while ((c = getchar()) != '\n' && c != EOF) {}
    
}