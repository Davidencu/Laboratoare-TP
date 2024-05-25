#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>

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