#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>

void create_matrix(int n,char a[][n])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("a[%d][%d]=",i,j);
            scanf("%c",&a[i][j]);
            getchar();
        }
    }
}

void afis(int n,char a[][n])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%c",a[i][j]);
        }
        printf("\n");
    }
}

void verif(char *s,int n,char a[][n])
{
    int ok=0;
    for(int i=0;i<n;i++)
    {
        int cnt=0,ln=0,cl=0;
        for(int j=0;j<n;j++)
        {
            if(a[i][j]==s[cnt])
            {
                if(cnt==0)
                {
                    ln=i; cl=j;
                }
                if(cnt!=strlen(s)-1)
                {
                    cnt++;
                }
                else
                {
                    ok=1;
                    cnt=0;
                    printf("linia %d,coloana %d, dreapta\n",ln,cl);
                }
            }
            else
            {
                cnt=0;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        int cnt=0,ln=0,cl=0;
        for(int j=n-1;j>=0;j--)
        {
            if(a[i][j]==s[cnt])
            {
                if(cnt==0)
                {
                    ln=i; cl=j;
                }
                if(cnt!=strlen(s)-1)
                {
                    cnt++;
                }
                else
                {
                    ok=1;
                    cnt=0;
                    printf("linia %d,coloana %d, stanga\n",ln,cl);
                }
            }
            else
            {
                cnt=0;
            }
        }
    }
    for(int j=0;j<n;j++)
    {
        int cnt=0,ln=0,cl=0;
        for(int i=0;i<n;i++)
        {
            if(a[i][j]==s[cnt])
            {
                if(cnt==0)
                {
                    ln=i; cl=j;
                }
                if(cnt!=strlen(s)-1)
                {
                    cnt++;
                }
                else
                {
                    ok=1;
                    cnt=0;
                    printf("linia %d,coloana %d, jos\n",ln,cl);
                }
            }
            else
            {
                cnt=0;
            }
        }
    }
    for(int j=0;j<n;j++)
    {
        int cnt=0,ln=0,cl=0;
        for(int i=n-1;i>=0;i--)
        {
            if(a[i][j]==s[cnt])
            {
                if(cnt==0)
                {
                    ln=i; cl=j;
                }
                if(cnt!=strlen(s)-1)
                {
                    cnt++;
                }
                else
                {
                    ok=1;
                    cnt=0;
                    printf("linia %d,coloana %d, sus\n",ln,cl);
                }
            }
            else
            {
                if(cnt==1 && a[i][j]==s[0])
                {
                    ln=i; cl=j;
                }
                else
                {
                    cnt=0;
                }
            }
        }
    }
    if (ok==0)
    {
        printf("Nu exista\n");
    }
}

int main()
{
    int n;
    printf("Dati n: ");
    scanf("%d",&n);
    getchar();
    char a[n][n],s[21];
    create_matrix(n,a);
    afis(n,a);
    printf("Dati sirul: ");
    scanf("%20s",s);
    verif(s,n,a);
    return 0;
}
