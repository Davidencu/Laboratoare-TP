#include<stdio.h>

//De-a lungul unei șosele trebuie amplasate una lângă alta următoarele entități: case, blocuri, grădini,
//ateliere. O entitate se poate învecina doar cu una de același tip (ex: casă cu casă) sau conform următoarelor reguli
//(orice relație o implică și pe cea inversă): un bloc poate avea ca vecini case; o casă sau un atelier poate avea ca
//vecini grădini. Se cer de la tastatură numerele c,b,g,a care reprezintă respectiv numărul de case, blocuri, grădini
//și ateliere. Să se determine toate variantele în care acestea pot fi aranjate.

//pentru simplitatea rezolvarii am notat casele cu cifra 1,blocurile cu 2,gradinile cu 3 si atelierele cu 4.

int valid(int c,int b,int g,int a,int *v,int k,int n)
{
    int c1=0,b1=0,g1=0,a1=0;
    for(int i=0;i<=k;i++)
    {
        switch(v[i])
        {
            case 0:
            {
                c1++;
                break;
            }
            case 1:
            {
                b1++;
                break;
            }
            case 2:
            {
                g1++;
                break;
            }
            case 3:
            {
                a1++;
                break;
            }
        }
    }
    
    if (c1>c || b1>b || g1>g || a1>a || k>n-1)
    {
        return 0;
    }
    if (k>0)
    {
        switch(v[k])  //b&c, (c|a)&g  cbga
        {
            case 0:
            {
                if(v[k-1]==3)
                {
                    return 0;
                }
                break;
            }
            case 1:
            {
                if(v[k-1]!=0 && v[k-1]!=1)
                {
                    return 0;
                }
                break;
            }
            case 2:
            {
                if(v[k-1]==1)
                {
                    return 0;
                }
                break;
            }
            case 3:
            {
                if(v[k-1]!=3 && v[k-1]!=2)
                {
                    return 0;
                }
                break;
            }
        }
    }
    return 1;
}

int solutie(int c,int b,int g,int a,int *v,int k,int n)
{
    int c1=0,b1=0,g1=0,a1=0;
    if(k==n-1)
    {
        for(int i=0;i<=k;i++)
        {
            switch(v[i])
            {
            case 0:
            {
                c1++;
                break;
            }
            case 1:
            {
                b1++;
                break;
            }
            case 2:
            {
                g1++;
                break;
            }
            case 3:
            {
                a1++;
                break;
            }
            }
        }
    }
    if (c1==c && b1==b && g1==g && a1==a)
    {
        return 1;
    }
    return 0;
}

void afisare(int c,int b,int g,int a,int *v,int k,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",v[i]);
    }
    printf("\n");
}

void back(int c,int b,int g,int a,int *v,int k,int n)
{
    for(int i=0;i<4;i++)
    {
        v[k]=i;
        if(valid(c,b,g,a,v,k,n))
        {
            if(solutie(c,b,g,a,v,k,n))
            {
                afisare(c,b,g,a,v,k,n);
            }
            else
            {
                back(c,b,g,a,v,k+1,n);
            }
        }
    }
}

int main()
{
    int c,b,g,a;
    printf("Dati c, b, g si a: ");
    scanf("%d%d%d%d",&c,&b,&g,&a);
    int n=c+b+g+a,v[n];
    back(c,b,g,a,v,0,n);
    return 0;
}