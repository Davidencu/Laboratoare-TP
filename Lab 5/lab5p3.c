#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>

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