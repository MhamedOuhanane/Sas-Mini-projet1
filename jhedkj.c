#include<stdio.h>
int main(int argc, char const *argv[])
{
    char i[20];
    fgets(i,20,stdin);
    printf("%s",i);
    return 0;
}
