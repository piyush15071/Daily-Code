#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n,t,k,i=1,j;
    char state[4];
    scanf("%d",&t);
    while(i<=t){
        scanf("%d",&n);
        scanf("%d",&k);
        strcpy(state,"off");
        j=1;
        while(j<=n){
            if(k%j!=0){
                if(strcmp(state,"off")==0)
                    strcpy(state,"on");
                else
                    strcpy(state,"off");
            }
        j++;
        }
    printf("%s\n",state);
    i++;

    }

    return 0;
}
