#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>

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