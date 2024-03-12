#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//tema 2

//problema 1

typedef struct
{
    char nume[20];
    int nota;
} S;

void citire(S *pt,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("Dati numele: ");
        getchar();
        fgets(pt[i].nume,20,stdin);
        if(pt[i].nume[strlen(pt[i].nume)-1]=='\n')
        {
            pt[i].nume[strlen(pt[i].nume)-1]=0;
        }
        printf("Dati nota: ");
        scanf("%d",&pt[i].nota);
    }
}

int comp(const void *elem1,const void *elem2)
{
    int a=0;
    const S *p1=(const S*)elem1;
    const S *p2=(const S*)elem2;
    if (p1->nota>p2->nota)
    {
        return -1;
    }
    else
    {
        if (p1->nota < p2 ->nota)
        {
            return 1;
        }
        else
        {
            a= strcmp(p1->nume,p2->nume);
            return a;
        }
    }
}



int main(void)
{
    int n;
    printf("Dati n: ");
    scanf("%d",&n);
    S student[n];
    citire(student,n);
    qsort(student,n,sizeof(S),comp);
    for(int i=0;i<n;i++)
    {
        printf("%s, %d\n",student[i].nume,student[i].nota);
    }
    return 0;
}

//problema 2

void read(int *v,int size)
{
    for(int i=0;i<size;i++)
    {
        printf("v[%d]=",i);
        scanf("%d",&v[i]);
    }
}

int negative(int n)
{
    return n<0;
}

void test(int *v,int *size,int (*cond)(int))
{
    for(int i=0;i<*size;i++)
    {
        if(!cond(v[i]))
        {
            for(int j=i;j<*size-1;j++)
            {
                v[j]=v[j+1];
            }
            *size=*size-1;
            i=i-1;
        }
    }
}

void print_array(int *v,int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d ",v[i]);
    }
    printf("\n");
}

int main(void)
{
    int size;
    printf("Dati marimea vectorului : ");
    scanf("%d",&size);
    int v[size];
    read(v,size);
    print_array(v,size);
    test(v,&size,negative);
    print_array(v,size);
    return 0;
}

//problema 3

void read(float *v,int size)
{
    for(int i=0;i<size;i++)
    {
        printf("v[%d]=",i);
        scanf("%f",&v[i]);
    }
}

int comp1(const void *elem1,const void *elem2)
{
    const float *a=(const float*)elem1;
    const float *b=(const float*)elem2;
    if(*a<*b)
    {
        return -1;
    }
    if(*a>*b)
    {
        return 1;
    }
    return 0;

}

int comp2(const void *key,const void *elem)
{
    const float *k=(const float*)key;
    const float *e=(const float*)elem;
    if(*e<*k)
    {
        return 1;
    }
    if(*e>*k)
    {
        return -1;
    }
    return 0;
}

void print_array(float *v,int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%f ",v[i]);
    }
    printf("\n");
}

int main(void)
{
    int size;
    float x;
    printf("Dati marimea vectorului : ");
    scanf("%d",&size);
    printf("Dati x: ");
    scanf("%f",&x);
    float v[size];
    read(v,size);
    print_array(v,size);
    qsort(v,size,sizeof(float),comp1);
    print_array(v,size);
    if(bsearch(&x,v,size,sizeof(float),comp2)==NULL)
    {
        printf("x nu a fost gasit\n");
    }
    else
    {
        printf("ok\n");
    }
    return 0;
}

//problema 4

void tabelare(double a,double b,double n,double (*f)(double))
{
    double cnt=a;
    while(cnt<=b)
    {
        printf("f(%.3lf)=%.3lf ",cnt,f(cnt));
        cnt=cnt+(b-a)/n;
    }
    printf("\n");
}

int main(void)
{
    double a,b,n;
    printf("Dati a, b si n : ");
    scanf("%lf %lf %lf",&a,&b,&n);
    tabelare(a,b,n,cos);
    tabelare(a,b,n,sqrt);
    tabelare(a,b,n,fabs);
    return 0;
}

//problema 1 proiect

double f1(double x)
{
    return (x*x*x+4)/(x*x+5);
}

double f2(double x)
{
    return x+10;
}

double f3(double x)
{
    return 2*x*x-1;
}

void tabelare(double a,double b,double n,double (*f)(double))
{
    double cnt=a;
    while(cnt<=b)
    {
        printf("f(%.03lf)=%.03lf ",cnt,f(cnt));
        cnt=cnt+(b-a)/n;
    }
    printf("\n");
}

int main(void)
{
    double a,b,p;
    printf("Dati a, b si n : ");
    scanf("%lf %lf %lf",&a,&b,&p);
    tabelare(a,b,p,f1);
    tabelare(a,b,p,f2);
    tabelare(a,b,p,f3);
    return 0;
}

//problema 2 proiect

int f1(char *s)
{
    return strlen(s);
}

int f2(char *s)
{
    int nr=0;
    for(int i=0;i<strlen(s);i++)
    {
        if (strchr("AEIOUaeiou",s[i])!=0)
        {
            nr++;
        }
    }
    return nr;
}

int f3(char *s)
{
    int nr=0;
    for(int i=0;i<strlen(s);i++)
    {
        if (s[i]>='A' && s[i]<='Z')
        {
            nr++;
        }
    }
    return nr;
}

int f4(char *s)
{
    int len=strlen(s);
    return s[len-1]-s[0];
}

int main(int argc,char **argv)
{
    FILE *fp=NULL;
    if((fp=fopen("CUVINTE.TXT","w"))==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    if (argc == 1)
    {
        printf("nu exista cuvinte\n");
        exit(-1);
    }
    int (*f[4])(char *)={f1,f2,f3,f4};
    for(int i=1;i<argc;i++)
    {
        printf("Cuvantul %s este de lungime %d, are %d vocale, are %d litere mari,iar diferenta dintre caractere este %d\n",argv[i],f[0](argv[i]),f[1](argv[i]),f[2](argv[i]),f[3](argv[i]));
        fprintf(fp,"Cuvantul %s este de lungime %d, are %d vocale, are %d litere mari,iar diferenta dintre caractere este %d\n",argv[i],f[0](argv[i]),f[1](argv[i]),f[2](argv[i]),f[3](argv[i]));
    }
    if(fclose(fp)!=0)
    {
        perror(NULL);
        exit(-1);
    }
    return 0;
}
