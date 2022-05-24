#include<stdio.h>

struct std{
    char name[30];//30byte
    int m,s,e;//4 4 4
};
//exam -- result
int main(){
/*
    struct std s;//30 name , 4+4+4 => 12 m s e
    printf("Enter name and marks of three subjects");
    scanf("%s%d%d%d",&s.name,&s.m,&s.s,&s.e);

    [50]
    [25,2]
*/

/*
    struct std s[50];
    int i,n;
    printf("\nHow many students ? ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("Enter name and marks of three subjects");
        scanf("%s%d%d%d",&s[i].name,&s[i].m,&s[i].s,&s[i].e);
    }

    for(i=0;i<n;i++){
        printf("\n%s   %d   %d   %d",s[i].name,s[i].m,s[i].s,s[i].e);
    }
*/
    struct std *s;
    int i,n=3;
    //scanf -> n
     s = (struct std*)malloc(sizeof(struct std)*n);
    for(i=0;i<n;i++){
            printf("Enter name and marks of three subjects");
            scanf("%s%d%d%d",&s[i].name,&s[i].m,&s[i].s,&s[i].e);
   }
    for(i=0;i<n;i++){
             printf("\n%s  %d  %d  %d ",s[i].name,s[i].m,s[i].s,s[i].e);
   }


    return 0;
}
