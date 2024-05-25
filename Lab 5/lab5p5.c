#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>

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