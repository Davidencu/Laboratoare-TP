#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>

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
