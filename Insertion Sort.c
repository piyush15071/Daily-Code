#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=0,n,c,d,temp;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int a[n];

    printf("Enter the elements: ");
    while(i<n){
        scanf("%d",&a[i]);
        i++;
    }
    for(i=0;i<(n-1);i++){
        d=i;
        while(d<(n-i)){
        if(a[d]>a[d+1]){
            temp=a[d];
            a[d]=a[d+1];
            a[d+1]=temp;
            }
        d++;
        }
    }

    printf("Sorted list in ascending order:\n");
    for (c=0;c<n;c++)
        printf("%d ",a[c]);

    return 0;
}
