#include <stdio.h>

int a[2][3] = {{1,2,3},{4,5,6}};
int b[2][3] = {{10,20,30},{40,50,60}};
int (*c[2])[3] = {b, a};
int (**p)[3] = c;

// c[1] => a
// 6: a[1][2] = c[1][1][2] = f1()[1][2]
// f1() = c[1]

// int (*[2])[3] => c
// int (*)[3] => c[1]

int (*f1(void))[3]
{
     return c[1];
}

// int (*[2])[3] => c
// int (**)[3] => c 등가

// f2() = c+1
// f2()-1 = c
// 6 = a[1][2] = c[1][1][2] = (f2()-1)[1][1][2] = f2()[0][1][2]

int (**f2(void))[3]
{
     return c+1;
}

// int a[2][3] => a
// int [3] => a[0]
// int *


// f3()+1 = a[0]
// 6 = a[1][2] = a[0][5] = (f3()+1)[5] = f3()[6]


int * f3(void)
{
     return a[0]-1;
}

//int (**)[3] => p
// p = c => c[1] = a = p[1]
// p[1] = a, a[1][2] = p[1][1][2]

int (**f4(void))[3]
{
    return p;
}


// int (*(*)[2])[3] => &c
// *f5() = c
// c[1] = a, a[1][2] = c[1][1][2] = (*f5())[1][1][2] = f5()[0][1][1][2]


int (*(*f5(void))[2])[3]
{
    return &c;
}

int main(void)
{
     printf("6=%d\n", f1()[1][2]);
     printf("6=%d\n", f2()[0][1][2]);
     printf("6=%d\n", f3()[6]);
     printf("6=%d\n", f4()[1][1][2]);
     printf("6=%d\n", f5()[0][1][1][2]);

     return 0;
}