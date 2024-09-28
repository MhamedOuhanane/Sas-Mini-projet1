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
int i =0;
int n1 ;
char Titre_Livre[n1][30];
char Auteur_Livre[n1][30];
float Prix[n1];
int Quantite[n1];
int main(int argc, char const *argv[])
{
    int a ,n , c;
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
            Ajouter(Titre_Livre, Auteur_Livre, Prix ,Quantite);
            i++;
            break;
        case 2 :
            Affichage(Titre_Livre,Auteur_Livre , Prix ,Quantite);
            break;
        case 3 :
            Rechercher(Titre_Livre , Auteur_Livre , Prix ,Quantite);
            break;
        case 4 :
            printf("Donner la nouvelle quantite de livre : ");
            scanf("%d",&a);
            c = Mette_a_jour(Titre_Livre);
            Quantite[c] = a;
            break;
        case 5 :
            Supprimer_Livre(Titre_Livre , Auteur_Livre , Prix ,Quantite);
            i--;
            break;
        case 6 :
            printf("le Nombre Total de Livres en Stock est S = %d",Quantite_Total(Quantite));
            break;        
        default:
            break;
        }
    } while (n >= 0 || n < 7);

    return 0;
}
void Ajouter()
{
    
    printf("Entrer le titre du livre : ");
    fgets(Titre_Livre[i],n2,stdin);                    // scanf("%s",A[i]);
    printf("Donner le nom de l'auteur : ");
    fgets(Auteur_Livre[i],n2,stdin);                    // scanf("%s",B[i]);
    printf("Entrer le prix : ");
    scanf("%f",&Prix[i]);
    printf("La Quantite a ajouter : ");
    scanf("%d",&Quantite[i]);
    n1++;
}
void Affichage()
{
    int j;
    if (i == 0)
    {
        printf("la Librairie est vide!");
    }
    else
    {
        for ( j = 0; j < i; j++)
        {
            printf("Livre %d :\t",j);
            printf("%s.\t",Titre_Livre[j]);
            printf("%s.\t",Auteur_Livre[j]);
            printf("Prix:%f.\t",&Prix[i]);
            printf("Qantite:%d.\n\n",&Quantite[j]);
        }
    }
}
void Rechercher(char A[][n2] ,char B[][n2] ,float C[1] ,int D[])
{
    char nom[n2];
    int j ,a;
    printf("Saisir le nom de livre a rechercher : ");
    fgets(nom,n2,stdin);
    for ( j = 0; j < i; j++)
    {
        a = 0;
        if (strcmp(Titre_Livre[j], nom[n2]))
        {
            printf("Le livre existe dans la Librairie . Ses informations est : \n");
            printf("Livre %d :\t",j);
            printf("%s.\n",&Titre_Livre[i]);
            printf("%s.\n",&Auteur_Livre[i]);
            printf("Prix:%f.\n",&C[i]);
            printf("Qantite:%d.\n",&Quantite[i]); 
            a = 1;       
        }
    }
    if(a == 0) 
    {
        printf("Cette livre n'existe pas dans la Libairire.\n");
    }
}
int Mette_a_jour(char A[][n2])
{
    int j;
    char a[n2];
    printf("Donner le titre de livre a mette a jours sa quantite : ");
    fgets(a,n2,stdin);
    for ( j = 0; j < i; j++)
    {
        if (strcmp(Auteur_Livre[j],a[n2]))
        {
            return j;
            break;
        }
    }
}  
void Supprimer_Livre(char A[][n2] ,char B[][n2] ,float C[1] ,int D[])
{
    char a[n2];
    int j , o,l;
    printf("Donner le titre de livre a supprimer : ");
    fgets(a,n2,stdin);
    for ( j = 0; j < i; j++)
    {
        if (strcmp(Auteur_Livre[j],a[n2]))
        {
            for ( o = j; o < i; o++)
            {
                for ( l = 0; l < n2; l++)
                {
                    A[o][l] = A[o+1][l];
                    Auteur_Livre[o][l] = Auteur_Livre[o+1][l];
                }
                C[o] = C[o+1];
                Quantite[o] = Quantite[o+1];
            
            }
            break;
        }
    }
}
int Quantite_Total(int A[])
{
    int j , s = 0;
    for ( j = 0; j < i; j++)
    {
        s += Quantite[j];
    }
    return s;
}
