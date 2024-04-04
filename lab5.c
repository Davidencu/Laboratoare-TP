#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>

//pentru a rula unul dintre probleme va rebui pus tot restul codului in comentarii, inafara de biblioteci

//problema 1

int main(void)
{
    uint32_t n[1024];
    FILE *fp1=NULL;
    FILE *fp2=NULL;
    if((fp1=fopen("frame_data_1.bin","rb"))==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    if((fp2=fopen("file2a.bin","wb"))==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    while(fread(&n,sizeof(uint32_t),1024,fp1))
    {
        fwrite(&n,sizeof(uint32_t),1024,fp2);
    }
    if(fclose(fp1)!=0)
    {
        perror(NULL);
        exit(-1);
    }
    if(fclose(fp2)!=0)
    {
        perror(NULL);
        exit(-1);
    }
    return 0;
}

//problema 2

void citire(int m,int n, int a[][n])
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("a[%d][%d]=",i,j);
            scanf("%d",&a[i][j]);
        }
    }
}

void scriere(int m,int n,int a[][n],FILE *fp2)
{
    if((fp2=fopen("fisier2.bin","wb"))==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    fwrite(&m,sizeof(int),1,fp2);
    fwrite(&n,sizeof(int),1,fp2);
    fwrite(*a,sizeof(int),m*n,fp2);
    if(fclose(fp2)!=0)
    {
        perror(NULL);
        exit(-1);
    }
}

int main(void)
{
    int m,n;
    FILE *fp2=NULL;
    printf("Dati m si n : ");
    scanf("%d%d",&m,&n);
    int a[m][n];
    citire(m,n,a);
    scriere(m,n,a,fp2);
}

//problema 3

typedef struct{
    char *nume;
    float pret;
    }Produs;
 
Produs produse[1000];
int nProduse;
 
void adaugare()
{
    Produs p;
    char nume[1000];
 
    printf("nume: ");
    fgets(nume,1000,stdin);
    nume[strcspn(nume,"\r\n")]='\0';
    if((p.nume=(char*)malloc((strlen(nume)+1)*sizeof(char)))==NULL){
        printf("memorie insuficienta");
        exit(EXIT_FAILURE);
        }
    strcpy(p.nume,nume);
    printf("pret: ");
    scanf("%g",&p.pret);
    produse[nProduse]=p;
    nProduse++;
}
 
void afisare()
{
    int i;
    for(i=0;i<nProduse;i++){
        printf("%s: %g\n",produse[i].nume,produse[i].pret);
        }
}
 
void scriere()
{
    FILE *fis;
    int i;
    unsigned short nNume;		// numarul de caractere dintr-un nume de produs
 
    if((fis=fopen("produse.dat","wb"))==NULL){
        printf("nu se poate deschide fisierul\n");
        exit(EXIT_FAILURE);
        }
    fwrite(&nProduse,sizeof(int),1,fis);
    for(i=0;i<nProduse;i++){
        nNume=(unsigned short)strlen(produse[i].nume);
        fwrite(&nNume,sizeof(unsigned short),1,fis);		// scriere lungime sir in fisier
        fwrite(produse[i].nume,sizeof(char),nNume,fis);	// scriere sir, fara terminator
        fwrite(&produse[i].pret,sizeof(float),1,fis);
        }
 
    fclose(fis);
}
 
void eliberare()
{
    int i;
    for(i=0;i<nProduse;i++)free(produse[i].nume);
}

void citire()
{
    FILE *fis;
    unsigned short nNume;
 
    if((fis=fopen("produse.dat","rb"))==NULL)return;	// iesire din functie in caz cu nu exista baza de date
        
        fread(&nProduse,sizeof(int),1,fis);
        for(int i=0;i<nProduse;i++)
        {
            if(fread(&nNume,sizeof(unsigned short),1,fis)==0)
            {
                fclose(fis);
                return;
            }
            char *pNume=(char*)malloc((nNume+1)*sizeof(char));		// alocare memorie pentru nume si terminator
            if(pNume==NULL)
            {
                printf("memorie insuficienta");
                fclose(fis);
                eliberare();
                exit(EXIT_FAILURE);
            }
            fread(pNume,sizeof(char),nNume,fis);				// citire caractere nume
            pNume[nNume]='\0';	// deoarece in fisier nu exista terminatorul de sir, acesta se adauga separat
            produse[i].nume=pNume;
            fread(&produse[i].pret,sizeof(float),1,fis);		// citeste pretul produsului
        }
}
 
int main()
{
    int optiune;
 
    citire();			// citirea bazei de date la inceputul programului
    do{
        printf("optiune: ");
        scanf("%d",&optiune);
        getchar();
        switch(optiune){
            case 1:adaugare();break;
            case 2:afisare();break;
            case 3:scriere();eliberare();break;
            default:printf("optiune invalida\n");
            }
        }while(optiune!=3);
    return 0;
}

//problema 4

void my_hexdump(FILE *fp)
{
    if((fp=fopen("frame_data_1.bin","rb"))==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    unsigned long offset=0x0;
    char line[49];
    char nr[3];
    uint8_t a[16];
    nr[2]='\0';
    int nrchr=0;
    while((nrchr=fread(a,sizeof(uint8_t),16,fp))!=0)
    {
        printf("%08lX: ",offset);
        offset=offset+0x10;
        line[0]=0;
        for(int i=0;i<nrchr;i++)
        {
            sprintf(nr,"%02X",a[i]);
            strcat(line,nr);
            strcat(line," ");
        }
        if(nrchr<16)
        {
            for(int j=nrchr;j<16;j++)
            {
                strcat(line,"00");
                strcat(line," ");
            }
        }
        line[48]='\0';
        printf("%s",line);
        printf(" | ");
        for(int k=0;k<16;k++)
        {
            if(a[k]<32)
            {
                printf(".");
            }
            else{
                printf("%c",a[k]);
            }
        }
        printf("\n"); 
    }
    if(fclose(fp)!=0)
        {
            perror(NULL);
            exit(-1);
        }
}

int main(void)
{
    FILE *fp1=NULL;  
    my_hexdump(fp1);
    return 0;
}

//problema 5

void comparare(FILE *fp1,FILE *fp2)
{
    uint32_t nr1[32];
    uint32_t nr2[32];
    int a,b,offset=0;
    while((a=fread(&nr1,sizeof(uint32_t),32,fp1))!=0 && (b=fread(&nr2,sizeof(uint32_t),32,fp2))!=0)
    {
        if (a==32 && b==32)
        {
            for(int i=0;i<32;i++)
            {
                if(nr1[i]!=nr2[i])
                {
                    printf("%d: %02X - %02X\n",offset,nr1[i],nr2[i]);
                }
                offset++;
            }
        }
        else
        {
            int maxx,ch;
            if(a>b)
            {
                maxx=a;
                ch=1;
            }
            else
            {
                maxx=b;
                ch=0;
            }
            for(int i=0;i<maxx;i++)
            {
                if(nr1[i]!=nr2[i])
                {
                    printf("%d: %02X - %02X\n",offset,nr1[i],nr2[i]);
                }
                offset++;
            }
            for(int i=maxx;i<32;i++)
            {
                if(ch)
                {
                    printf("%d: %02X\n",offset,nr1[i]);
                }
                else
                {
                    printf("%d: %02X\n",offset,nr2[i]);
                }
                offset++;
            }
        }
    }
    while((a=fread(&nr1,sizeof(uint32_t),32,fp1))!=0)
    {
        for(int i=0;i<32;i++)
        {
            printf("%d: %02X\n",offset,nr1[i]);
            offset++;
        }
    }
    while((b=fread(&nr2,sizeof(uint32_t),32,fp2))!=0)
    {
        for(int i=0;i<32;i++)
        {
            printf("%d: %02X\n",offset,nr2[i]);
            offset++;
        }
    }
}

int main()
{
    FILE *fp1 = NULL;
    FILE *fp2 = NULL;
    if((fp1=fopen("frame_data_1.bin","rb"))==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    if((fp2=fopen("file3a.bin","rb"))==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    comparare(fp1,fp2);
    if(fclose(fp1)!=0)
        {
            perror(NULL);
            exit(-1);
        }
    if(fclose(fp2)!=0)
        {
            perror(NULL);
            exit(-1);
        }    
    return 0;
}

//problema 6

void extragere(int a,long *offset,char **argv,uint8_t *v)
{
    *offset=strtol(argv[2],NULL,16);
    for(int i=3;i<a;i++)
    {
        v[i-3]=(uint8_t)strtol(argv[i],NULL,16);
    }
}

int main(int argc,char **argv)
{
    FILE *fp=NULL;
    long offset;
    uint8_t v[argc-3];
    if(argc<4)
    {
        perror(NULL);
        exit(-1);
    }
    if((fp=fopen(argv[1],"rb+"))==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    extragere(argc,&offset,argv,v);
    if (fseek(fp, offset, SEEK_SET)==0)
    {
        fwrite(&v,sizeof(uint8_t),argc-3,fp);
    }
    if(fclose(fp)!=0)
    {
        perror(NULL);
        exit(-1);
    }
    return 0;
}

//problema 7

int checkk(uint8_t *v,uint8_t *w,int n)
{
    int ok=1;
    for(int i=0;i<n;i++)
    {
        if(v[i]!=w[i])
        {
            ok=0;
        }
    }
    return ok;
}

void extragere(int a,char **argv,uint8_t *v)
{
    for(int j=2;j<a;j++)
    {
        v[j-2]=(uint8_t)strtol(argv[j],NULL,16);
    }
}

void cautare(FILE *fp,uint8_t *v,int size)
{
    uint8_t w[size];
    int a;
    fseek(fp,0,SEEK_END); //returneaza 0 ca s-a reusit
    int end=ftell(fp); //end primeste pozitia cursorului care acum este la capatul fisierului
    for(int i=0;i<end-size+1;i++)
    {
        fseek(fp,i,SEEK_SET);
        fread(&w,sizeof(uint8_t),size,fp);
        if(checkk(v,w,size))
        {   
            a=ftell(fp); //a primeste pozitia pe care vrem sa o aflam
            printf("%d\n",a);
        }
    }
}

int main(int argc,char **argv)
{
    FILE *fp=NULL;
    uint8_t v[argc-2];
    if(argc<3)
    {
        perror(NULL);
        exit(-1);
    }
    if((fp=fopen(argv[1],"rb+"))==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    extragere(argc,argv,v);
    cautare(fp,v,argc-2);
    if(fclose(fp)!=0)
    {
        perror(NULL);
        exit(-1);
    }
    return 0;
}


