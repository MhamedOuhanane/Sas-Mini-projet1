#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define n2 30
void Ajouter(char A[][n2] ,char B[][n2] ,float C[1] ,int D[]);
void Affichage(char A[][n2] ,char B[][n2] ,float C[1] ,int D[]);
void Rechercher(char A[][n2] ,char B[][n2] ,float C[1] ,int D[]);
int Mette_a_jour(char A[][n2]);
void Supprimer_Livre(char A[][n2] ,char B[][n2] ,float C[1] ,int D[]);
int Quantite_Total(int A[]);
int i =0;
int n1= 100;

int main(int argc, char const *argv[])
{
    char Titre_Livre[n1][n2];
    char Auteur_Livre[n1][n2];
    float Prix[n1];
    int Quantite[n1];
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
void Ajouter(char A[][n2] ,char B[][n2] ,float C[1] ,int D[])
{
    
    printf("Entrer le titre du livre : ");
    fgets(A[i],n2,stdin);                    // scanf("%s",A[i]);
    printf("Donner le nom de l'auteur : ");
    fgets(B[i],n2,stdin);                    // scanf("%s",B[i]);
    printf("Entrer le prix : ");
    scanf("%f",&C[i]);
    printf("La Quantite a ajouter : ");
    scanf("%d",&D[i]);
    n1++;
}
void Affichage(char A[][n2] ,char B[][n2] ,float C[1] ,int D[])
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
            printf("%s.\t",A[j]);
            printf("%s.\t",B[j]);
            printf("Prix:%f.\t",&C[i]);
            printf("Qantite:%d.\n\n",&D[j]);
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
        if (strcmp(A[j],nom[n2]))
        {
            printf("Le livre existe dans la Librairie . Ses informations est : \n");
            printf("Livre %d :\t",j);
            printf("%s.\n",&A[i]);
            printf("%s.\n",&B[i]);
            printf("Prix:%f.\n",&C[i]);
            printf("Qantite:%d.\n",&D[i]); 
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
        if (strcmp(A[j],a[n2]))
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
        if (strcmp(A[j],a[n2]))
        {
            for ( o = j; o < i; o++)
            {
                for ( l = 0; l < n2; l++)
                {
                    A[o][l] = A[o+1][l];
                    B[o][l] = A[o+1][l];
                }
                C[o] = C[o+1];
                D[o] = D[o+1];
            
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
        s += A[j];
    }
    return s;
}
