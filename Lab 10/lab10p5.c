#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* concat(const char *s1, const char *s2) {
    char *s = malloc(strlen(s1) + strlen(s2) + 1);
    strcpy(s, s1);
    strcat(s, s2);
    return s;
}

char* fibo2(int n, char *str1, char *str2) {
    if (n == 0)
    {
        return "";
    }
    if (n == 1) {
        return strdup(str1);
    }
    if (n == 2) {
        return strdup(str2);
    }
    char *p1 = fibo2(n-1, str1, str2);
    char *p2 = fibo2(n-2, str1, str2);
    char *r = concat(p2, p1);
    free(p1);
    free(p2);
    return r;
}

int main(void)
{
    char *z=NULL,a[1000],b[1000];
    scanf("%9s",a);
    scanf("%9s",b);
    int n;
    scanf("%d",&n);
    z=fibo2(n,a,b);
    printf("%s\n",z);
    free(z);
    return 0;
}