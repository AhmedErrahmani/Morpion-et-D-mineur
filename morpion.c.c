#include <stdio.h>
#include <stdlib.h>

void grille(char T[3][3])
{
    char*p=T;
    printf("  1 2 3\n");
    printf("1 %c|%c|%c\n",*(p+0),*(p+1),*(p+2));
    printf("2 %c|%c|%c\n",*(p+3),*(p+4),*(p+5));
    printf("3 %c|%c|%c\n",*(p+6),*(p+7),*(p+8));
    printf("--------\n");
}
int test(char T[3][3])
{
    char*p=T;
    int i,j;
    for(i=0;i<3;i++)
    {
        if(*(p+i*3+0)==*(p+i*3+1) && *(p+i*3+2)==*(p+i*3+1) && *(p+i*3+0)!=' ')
        {
            return 1;
        }
        if(*(p+i)==*(p+3+i) && *(p+3+i)==*(p+6+i) && *(p+i)!=' ')
        {
            return 1;
        }
    }
    if(*(p+0)==*(p+4) && *(p+8)==*(p+4) && *(p+0)!=' ')
    {
        return 1;
    }
    if(*(p+6)==*(p+4) && *(p+4)==*(p+2) && *(p+6)!=' ')
    {
        return 1;
    }


}
void main()
{
    char T[3][3];
    int i,j,c,d,e;
    char*p=T;
    char a,b;
    for(i=0;i<3;i++)
    {
         for(j=0;j<3;j++)
        {
               *(p+i*3+j)=' ';
        }
    }
    grille(T);
    do
    {
        printf("joueur1 par quoi tu vas jouer ?\n");
        scanf("%c",&a);
    }while(a!='x' && a!='o');
    if(a=='x')
    {
        b='o';
    }
    else
    {
        b=='x';
    }
    e=9;
    do
    {
        printf("joueur1 enter les cordonn�e de la case qui tu veux remplire:\n");
        scanf("%d%d",&c,&d);
        e++;
        *(p+(c-1)*3+d-1)='x';
        grille(T);
        if(test(T)==1)
        {
            printf("bravo joueur1");
            break;
        }
        printf("joueur2 enter les cordonn�e de la case qui tu veux remplire:\n");
        scanf("%d%d",&c,&d);
        e++;
        *(p+(c-1)*3+d-1)='o';
        grille(T);
        if(test(T)==1)
        {
            printf("bravo joueur2");
            break;
        }
    }while(e<=9);
}
