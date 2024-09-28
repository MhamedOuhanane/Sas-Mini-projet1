void Affichage(char A , char B , float c , int d)
{
    if (i == 0)
    {
        printf("la Librairie est vide!");
    }
    else
    {
        for ( j = 0; j < i; j++)
        {
            printf("Livre %d :\t",j);
            printf("%s.\t",&A[i][30]);
            printf("%s.\t",&B[i][30]);
            printf("Prix:%f.\t",&C[i]);
            printf("Qantite:%d.\n\n",&D[i]);
        }
        
    }
    
}