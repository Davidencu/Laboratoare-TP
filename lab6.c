#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>

//Pentru a rula una dintre probleme va trebui pus tot restul codului in comentarii, inafara de biblioteci

//problema 1

void err(int cond,const char *fmt,...)
{
if(cond)
    {
        va_list va; // pointer la lista de argumente variabile (varargs)
        va_start(va,fmt); // va trebuie initializat cu ultimul argument fix al functiei
        fprintf(stderr,"eroare: ");
        vfprintf(stderr,fmt,va); // varianta de fprintf care primeste o lista de argumente variabile
        va_end(va); // dupa folosirea argumentelor variabile, trebuie apelat va_end
        fputc('\n',stderr);
        exit(EXIT_FAILURE);
    }
}


int main()
{
    int i,n;
    float x,y,e,min,max;
    printf("n=");scanf("%d",&n);
    err(n<=0||n>=100,"n invalid: %d\n",n);
    printf("x=");scanf("%g",&x);
    printf("y=");scanf("%g",&y);
    err(x>=y,"x=%g nu este mai mic decat y=%g\n",x,y);
    max=x;
    min=y;
    for(i=0;i<n;i++)
    {
        printf("e=");scanf("%g",&e);
        if(e<x||e>y)
            err(e<x||e>y,"element invalid: %g\n",e);
        if(e<min)
            min=e;
        if(e>max)
            max=e;
    }
printf("min: %g, max: %g\n",min,max);
return 0;
}

//problema 2

float *allocVec(int n,...)
{
    float *array=NULL;
    if((array=(float *)malloc(n*sizeof(float)))==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    va_list va;
    va_start(va,n);
    for(int i=0;i<n;i++)
    {
        array[i]=va_arg(va,double);
    }
    va_end(va);
    return array;
}

void afisare(float *array,int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%f ",array[i]);
    }
    printf("\n");
}

int main(void)
{
    float *array=allocVec(3,1.0,1.5,2.0);
    afisare(array,3);
    free(array);
    return 0;
}

//problema 3

/*Să se scrie o funcție absN(int n,...) care primește un număr n de adrese de tip float și setează la
fiecare dintre aceste adrese valoarea absolută de la acea locație.
Exemplu: absN(2,&x,&y); // echivalent cu x=fabs(x); y=fabs(y);*/

void absN(int n,...)
{
    va_list va;
    va_start(va,n);
    double *aux;
    for(int i=0;i<n;i++)
    {
        aux=va_arg(va,double *);
        if (*aux<0)
        {
            *aux=-(*aux);
        }
    }
    va_end(va);
}

int main(void)
{
    float x=3.0,y=-4.0,z=1.5;
    absN(3,&x,&y,&z);
    printf("%f %f %f",x,y,z);
    return 0;
}

//problema 4

/*Să se scrie o funcție crescator(int n,char tip,...) care primește un număr n de valori și returnează 1
dacă ele sunt în ordine strict crescătoare, altfel 0. Caracterul tip indică tipul valorilor și poate fi ‘d’ - int, ‘f’ - double.
Exemplu: printf(“%d”,crescator(3,’d’,-1,7,9));*/

int crescator(int n,char tip,...)
{
    va_list va;
    va_start(va,tip);
    double minn=-1000000.0;
    double a2,prev=minn;
    int a1,ok=1;
    switch(tip)
    {
        case(100):
            for(int i=0;i<n;i++)
            {
                a1=va_arg(va,int);
                if(a1>(int)prev)
                {
                    prev=a1;
                }
                else
                {
                    ok=0;
                    break;
                }
            }
            break;
        case(102):
            for(int i=0;i<n;i++)
            {
                a2=va_arg(va,double);
                printf("%f ",a2);
                if(a2>prev)
                {
                    prev=a2;
                }
                else
                {
                    ok=0;
                    break;
                }
            }
            break;
        default:
            printf("eroare\n");
            exit(-1);
            break;
    }
    va_end(va);
    return ok;
}

int main()
{
    printf("%d\n",crescator(5,'d',2,3,6,4,5));
    return 0;
}

//problema 5

/*Să se implementeze o funcție input(const char *fmt,...). În șirul fmt pot fi caractere obișnuite (orice
în afară de %) și placeholdere (% urmat de o literă). Pentru fiecare placeholder posibil ( %d - int, %f -float, %c -
char ), în lista de argumente variabile se va afla adresa unei variabile de tipul corespunzător. Funcția afișează pe
ecran caracterele obișnuite și citește de la tastatură pentru placeholdere.
Exemplu: input(”n=%dch=%c”,&n,&ch); // citește o valoare de tip int în n și de tip char în ch*/

void input(const char *fmt,...)
{
    va_list va;
    int *d=NULL;
    double *f=NULL;
    int *c=NULL;
    va_start(va,fmt);
    for(int i=0;i<strlen(fmt);i++)
    {
        if(fmt[i]!='%')
        {
            printf("%c",fmt[i]);
        }
        else
        {
            switch(fmt[i+1])
            {
                case('d'):
                    d=va_arg(va,int *);
                    scanf("%d",d);
                    break;
                case('f'):
                    f=va_arg(va,double *);
                    scanf("%lf",f);
                    break;
                case('c'):
                    c=va_arg(va,int *);
                    scanf(" %lc",c);
                    break;
            }
            i++;
        }
    }
    va_end(va);
}

int main(void)
{
    int p1,p2,p3,p4,p5;
    input("nr1=%dnr2=%dch1=%cch2=%cnr2=%d",&p1,&p2,&p3,&p4,&p5);
    printf("%d%d%c%c%d\n",p1,p2,p3,p4,p5);
    return 0;
}

//problema 6

char *concat(int n,...)
{
    char *s=malloc(sizeof(char));
    s[0]='\0';
    char aux[20];
    int cnt=0;
    int len=0;
    va_list va;
    va_start(va,n);
    for(int i=0;i<n;i++)
    {
        strcpy(aux,va_arg(va,char *));
        len=strlen(aux)+1;
        cnt+=len;
        if((s=realloc(s,(cnt+1)*sizeof(char)))==NULL)
        {
            perror(NULL);
            exit(-1);
        }
        strcat(s,aux);
        strcat(s," ");
    }
    return s;
    va_end(va);
}

int main()
{
    char *s=concat(3,"ana","are","mere");
    printf("%s\n",s);
    free(s);
    return 0;
}

//problema 8

void sortare(int n, ...) 
{
    va_list arg1;
    int s,aux,*prev=NULL,*acc=NULL;
    do{
		s = 0; 
        va_start(arg1, n);
        prev=va_arg(arg1,int *);
		for (int i = 1; i < n; i++)
		{
            acc=va_arg(arg1,int *);
			if (*prev > *acc)
			{             
				aux = *prev;
				*prev = *acc;
				*acc = aux;
				s = 1;
			}
            prev=acc;
		}
        va_end(arg1);
	} while (s);
}

int main() {
    int a = 3, b = 1, c = 5, d = 2,e = 4;
    sortare(5, &a, &b, &c, &d, &e);
    printf("%d %d %d %d %d\n", a, b, c, d, e);
    
    return 0;
}

//problema 9

int main(int argc,char **argv)
{
    float sum=0,nr;
    for(int i=1;i<argc;i++)
    {
        nr=atof(argv[i]);
        sum+=nr;
    }
    if(argc==1)
    {
        printf("0\n");
    }
    else
    {
        printf("%f\n",sum);
    }
}

//problema 10

void criptare(char argc,char **argv)
{
    int n=atoi(argv[2]);
    
    if(strcmp(argv[1],"enc")==0)
    {
        for(int i=3;i<argc;i++)
        {
            for(int j=0;j<strlen(argv[i]);j++)
            {
                if('A'<argv[i][j] && argv[i][j]<'Z')
                {
                    argv[i][j]+=32;
                }
            }
            for(int j=0;j<strlen(argv[i]);j++)
            {
                if(n>('z'-argv[i][j]))
                {
                    argv[i][j]=argv[i][j]+n-26;
                }
                else
                {
                    argv[i][j]=argv[i][j]+n;
                }
            }
        }
    }
    if(strcmp(argv[1],"dec")==0)
    {
        for(int i=3;i<argc;i++)
        {
            for(int j=0;j<strlen(argv[i]);j++)
            {
                if('A'<argv[i][j] && argv[i][j]<'Z')
                {
                    argv[i][j]+=32;
                }
            }
            for(int j=0;j<strlen(argv[i]);j++)
            {
 
                if(n>(argv[i][j]-'a'))
                {
                    argv[i][j]=argv[i][j]-n+26;
                }
                else
                {
                    argv[i][j]=argv[i][j]-n;
                }
                
            }
        }
    }
}

int main(int argc,char **argv)
{
    if(argc<4)
    {
        perror(NULL);
        exit(-1);
    }
    criptare(argc,argv);
    for(int i=3;i<argc;i++)
    {
        printf("%s ",argv[i]);
    }
    printf("\n");
    return 0;
}

//problema 11

float algebra(int argc,char **argv)
{
    int i=2;
    float nr=atof(argv[1]);
    float aux;
    char str[3];
    while(i<argc)
    {
        strcpy(str,argv[i]);
        aux=atof(argv[i+1]);
        if(strcmp(str,"add")==0)
        {
            nr=nr+aux;
        }
        if(strcmp(str,"sub")==0)
        {
            nr=nr-aux;
        }
        if(strcmp(str,"mul")==0)
        {
            nr=nr*aux;
        }
        if(strcmp(str,"div")==0)
        {
            nr=nr/aux;
        }
        i+=2;
    }
    return nr;
}

int main(int argc, char **argv)
{
    if(argc<2)
    {
        perror(NULL);
        exit(-1);
    }
    else
    {
        float a=algebra(argc,argv);
        printf("%f\n",a);
    }
    return 0;
}

//problema 13

int main(int argc,char **argv)
{
    int nr;
    if(argc<3)
    {
        perror(NULL);
        exit(-1);
    }
    else
    {
        nr=atoi(argv[1]);
        switch(nr)
        {
            case 0:
                int s=0;
                for(int i=2;i<argc;i++)
                {
                    s=s+strlen(argv[i]);
                }
                printf("%d\n",s);
            case 1:
                char a[58]={0};
                for(int i=2;i<argc;i++)
                {
                    for(int j=0;j<strlen(argv[i]);j++)
                    {
                        if(isalpha(argv[i][j]))
                        {
                            a[argv[i][j]-'A']++;
                        }
                    }
                }
                for(int i=0;i<58;i++)
                {
                    if(isalpha(i+'A') && a[i]!=0)
                    {
                        printf("%c - de %d ori\n",i+'A',a[i]);
                    }
                }
        }
    }
    return 0;
}
