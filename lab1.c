#include<stdio.h>
#include<stdlib.h>

// problema 8.5

void matrix_read(int n,int a[][n])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("a[%d][%d] = ",i,j);
            scanf("%d",*(a+i)+j);
        }
    }
}

void ssum(int n,int a[][n],int *v1,int *v2)
{
    int s1;
    for(int j=0;j<n;j++)
    {
        *(v2+j)=0;
    }
    for(int i=0;i<n;i++)
    {
        s1=0;
        for(int j=0;j<n;j++)
        {
            *(v2+j)=*(v2+j)+*(*(a+i)+j);
            s1=s1+*(*(a+i)+j);
        }
        *(v1+i)=s1;
    }
}

void afisare(int *v1,int *v2,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",*(v1+i));
    }
    printf("\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",*(v2+i));
    }
    printf("\n");
}

int main(void)
{
    int n;
    printf("Dati n: ");
    scanf("%d",&n);
    int a[n][n],v1[n],v2[n];
    matrix_read(n,a);
    ssum(n,a,v1,v2);
    afisare(v1,v2,n);
    return 0;
}

//problema 8.6

void friends(int n,int a[][n])
{
    int f;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            a[i][j]=0;
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("Dati prietenii lui %d : ",i);
        while(scanf("%d",&f) && f!=-1)
        {
            a[i][f]=1;
        }
    }
}

void count(int n, int a[][n])
{
    int cnt;
    for(int i=0;i<n;i++)
    {
        cnt=0;
        for(int j=0;j<n;j++)
        {
            cnt+=a[i][j];
        }
        if (cnt!=1)
        {
            printf("Persoana %d are %d prieteni\n",i,cnt);
        }
        else
        {
            printf("Persoana %d are 1 prieten\n",i);
        }
    }
}

int main(void)
{
    int n;
    printf("Dati nr. de persoane: ");
    scanf("%d",&n);
    int a[n][n];
    friends(n,a);
    count(n,a);
    return 0;
}



//problema 8.7

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



//problema 8.8

void read_matrix(int m,int n,int a[][n])
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("a[%d][%d] = ",i,j);
            scanf("%d",&a[i][j]);
        }
    }
}

void multiply(int m,int n,int p,int a[][n], int b[][p],int c[][p])
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<p;j++)
        {
            c[i][j]=0;
            for(int k=0;k<n;k++)
            {
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
}

void print(int m,int n,int a[][n])
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    int m,n,p;
    printf("Dati m,n si p ");
    scanf("%d %d %d",&m,&n,&p);
    int a[m][n],b[n][p],c[m][p];
    read_matrix(m,n,a);
    read_matrix(n,p,b);
    multiply(m,n,p,a,b,c);
    print(m,p,c);
    return 0;
}

//problema 8.9

void myprint(int n,int a[][n])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    int n;
    printf("n=");
    scanf("%d",&n);
    int a[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if((i==j) || (i+j==n-1))
            {
                a[i][j]=1;
            }
            else
            {
                a[i][j]=0;
            }
        }
    }
    myprint(n,a);
    return 0;
}

//problema 8.10

void matrix_read(int a[][4],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("a[%d][%d] = ",i,j);
            scanf("%d",&a[i][j]);
        }
    }
}

void check_for_products(int a[][4],int n)
{
    int ok=1,nr=0;
    for(int i=0;i<n;i++)
    {
        ok=1;
        for(int j=1;j<4;j++)
        {
            if(a[i][j]<=a[i][j-1])
            {
                ok=0;
            }
        }
        if (ok) 
        {
            nr++;
            printf("%d ",i);
        }
    }
    if(nr==0)
    {
        printf("niciun produs");
    }
}

int main(void)
{
    int n;
    printf("Dati n : ");
    scanf("%d",&n);
    int a[n][4];
    matrix_read(a,n);
    check_for_products(a,n);
    return 0;
}

//problema 1 proiect

int **matrix_read(int n)
{
    int **m=NULL;
    if((m=(int **)malloc(n*sizeof(int *)))==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    for(int i=0;i<n;i++)
    {
        if((m[i]=(int *)malloc(n*sizeof(int)))==NULL)
        {
            for(int j=i-1;j>=0;j--)
            {
                free(m[j]);
            }
            free(m);
            perror(NULL);
            exit(-1);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("a[%d][%d] = ",i,j);
            scanf("%d",&m[i][j]);
        }
    }
    return m;
}

void search(int **a,int **b,int m,int n)
{
    int ok,t=0;
    for(int i=0;i<m-n+1;i++)
    {
        for(int j=0;j<m-n+1;j++)
        {
            ok=1;
            for(int k=0;k<n;k++)
            {
                for(int l=0;l<n;l++)
                {
                    if(b[k][l]!=a[i+k][j+l])
                    {
                        ok=0;
                    }
                }
            }
            if (ok==1)
            {
                t++;
                printf("(%d,%d) ",i,j);
            }
        }
    }
    if (t==0)
    {
        printf("nu apare");
    }
}

void matrix_free(int **a,int n)
{
    for(int i=0;i<n;i++)
    {
        free(a[i]);
    }
    free(a);
}

int main(void)
{
    int n,m,**m1=NULL,**m2=NULL;
    printf("Dati m si n: ");
    scanf("%d %d",&n,&m);
    m1=matrix_read(n);
    m2=matrix_read(m);
    search(m1,m2,n,m);
    matrix_free(m1,n);
    matrix_free(m2,m);
    printf("\n");
    return 0;
}