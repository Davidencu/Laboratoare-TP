#include<stdio.h>
#include<stdlib.h>

void city_distance_read(int n,int a[][n])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if (i==j)
            {
                a[i][j]=0;
            }
            else
            {
                if (i<j)
                {
                    printf("Dati distanta dintre orasele %d si %d: ",i,j);
                    scanf("%d",&a[i][j]);
                    a[j][i]=a[i][j];
                }
            }
        }
    }
}

int min_distance(int n,int a[][n])
{
    int minn=100000;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i][j]<minn)
            {
                minn=a[i][j];
            }
        }
    }
    return minn;
}

int main(void)
{
    int n;
    printf("Dati numarul de orase : ");
    scanf("%d",&n);
    int a[n][n];
    city_distance_read(n,a);
    printf("Cea mai mica distanta este %d\n",min_distance(n,a));
    return 0;
}