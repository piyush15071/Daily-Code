#include <stdio.h>
int main()
{
    int t,x=0;
    scanf("%d",&t);
    while(x<t){
    long sum=0;
    int heap[100000],n,m,a,j,max,var,z=0,sample;
    scanf("%d %d",&n,&m);
    for (a=0;a<n;a++)
       scanf("%d",&heap[a]);
    while(z<m){
    for (a=1;a<n;a++)
    {j=a;
    do
        {max=(j-1)/2;
            if (heap[max]<heap[j])
            {var=heap[max];
             heap[max]=heap[j];
             heap[j]=var;}
            j=max;}
    while(j!=0);
    }
    sample=(heap[0])/2;
    sum+=(heap[0]-sample);
    heap[0]=sample;
    z++;
    }
    printf("%ld\n",sum);
    x++;
    }
return 0;
}
