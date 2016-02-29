#include<stdio.h>
#include<stdlib.h>
#define max 50
void input(int a[][max],int new,int old)
{
    int i,j,t;
    for(i=0;i<old;i++)
    {
        for(j=0;j<old;j++)
        {
            printf("\n\tEnter MATa[%d][%d] value :-",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
        for(j=old;j<new;j++)
            a[i][j]=0;
    }
    for(i=old;i<new;i++)
    {
        for(j=0;j<new;j++)
            a[i][j]=0;
    }

}
void display(int a[][max],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf(" %d\t",a[i][j]);
        printf("\n");
    }
}
void add(int a[][max],int b[][max],int c[][max],int n)
{

    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            c[i][j]=a[i][j]+b[i][j];
    }
}
void sub(int a[][max],int b[][max],int c[][max],int n)
{

    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            c[i][j]=a[i][j]-b[i][j];
    }
}
void strassen(int a[][max],int b[][max],int c[][max],int n)
{
    int p1[max][max], p2[max][max], p3[max][max], p4[max][max], p5[max][max], p6[max][max], p7[max][max];
    int t1[max][max],t2[max][max], a11[max][max],a12[max][max],a21[max][max],a22[max][max],i,j;
    int  b11[max][max],b12[max][max],b21[max][max],b22[max][max];

    if(n>=2)
    {

        for(i=0;i<n/2;i++)
        {
            for(j=0;j<n/2;j++)
            {
                a11[i][j]=a[i][j];
            }
        }
        for(i=0;i<n/2;i++)
        {
            for(j=0;j<n/2;j++)
            {
                a12[i][j]=a[i][j+n/2];
            }
        }
        for(i=0;i<n/2;i++)
        {
            for(j=0;j<n/2;j++)
            {
                a21[i][j]=a[i+n/2][j];
            }
        }
        for(i=0;i<n/2;i++)
        {
            for(j=0;j<n/2;j++)
            {
                a22[i][j]=a[i+n/2][j+n/2];
            }
        }


       for(i=0;i<n/2;i++)
        {
            for(j=0;j<n/2;j++)
            {
                b11[i][j]=b[i][j];
            }
        }
        for(i=0;i<n/2;i++)
        {
            for(j=0;j<n/2;j++)
            {
                b12[i][j]=b[i][j+n/2];
            }
        }
        for(i=0;i<n/2;i++)
        {
            for(j=0;j<n/2;j++)
            {
                b21[i][j]=b[i+n/2][j];
            }
        }
        for(i=0;i<n/2;i++)
        {
            for(j=0;j<n/2;j++)
            {
                b22[i][j]=b[i+n/2][j+n/2];
            }
        }


//P1=(A11+A22)(B11+b22)

        add(a11,a22,t1,n/2);
        add(b11,b22,t2,n/2);
        strassen(t1,t2,p1,n/2);



//P2=(A21+A22)(B11)
        add(a21,a22,t1,n/2);
        strassen(t1,b11,p2,n/2);


//P3=(A11)(B12-B22)
        sub(b12,b22,t1,n/2);
        strassen(a11,t1,p3,n/2);



//P4=(A22)(B21-B11)

        sub(b21,b11,t1,n/2);
        strassen(a22,t1,p4,n/2);

//P5=(A11+A12)(B22)
        add(a11,a12,t1,n/2);
        strassen(t1,b22,p5,n/2);


//P6=(A21-A11)(B11+B12)

        sub(a21,a11,t1,n/2);
        add(b11,b12,t2,n/2);
        strassen(t1,t2,p6,n/2);


//P7=(A12-A22)(B21+B22)

        sub(a12,a22,t1,n/2);
        add(b21,b22,t2,n/2);
        strassen(t1,t2,p7,n/2);

//strassen(temp1, temp2, p7, n / 2);

//c11

        for(i = 0; i < n / 2; i++)
        {

            for(j = 0; j < n / 2; j++)
            {

                c[i][j] = p1[i][j] + p4[i][j] - p5[i][j] + p7[i][j];


            }

        }

//c12

    for(i = 0; i < n / 2; i++)
        {

            for(j = 0; j < n / 2; j++)
            {

                c[i][j + n / 2] = p3[i][j] + p5[i][j];

            }

        }

//c21

    for(i = 0; i < n / 2; i++)
    {

        for(j = 0; j < n / 2; j++)
        {

            c[i + n/ 2][j] = p2[i][j] + p4[i][j];

        }

    }

//c22

    for(i = 0; i < n / 2; i++)
    {

        for(j = 0; j < n/ 2; j++)
        {

            c[i + n / 2][j + n/ 2] = p1[i][j] + p3[i][j] - p2[i][j] + p6[i][j];

        }

    }
}
else if(n==1)
    c[0][0]=a[0][0]*b[0][0];
}
int main()
{

    int i,j,temp,n,ch,a[max][max],b[max][max],c[max][max],num=1;
    do
    {
        printf("\n*******Menu********\n\n1.Input  matrices.\n2.Display matrices.\n3.Multipy two matrices using strassen's.\n\nenter your choice::");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\nenter size of matrix::");
            scanf("%d",&n);

           while(n<0)
           {
               printf("\nenter size greater than Zero of the matrix::");
               scanf("%d",&n);
           }
            if(n==1)
                num=1;
            while(num<n)
            {
                num=num*2;
            }
            printf("%d",num);
            printf("\nenter first matrix::---------------\n");
            input(a,num,n);
            printf("\nenter second matrix::---------------\n");
            input(b,num,n);
            break;
        case 2:
            printf("\n\nFIRST MATRIX::*********************\n");
            display(a,num);
            printf("\n\nSECOND MATRIX::********************\n");
            display(b,num);
            break;
        case 3:
            strassen(a,b,c,num);
            display(c,n);
            break;
        }

    }while(ch!=4);
    return 0;
    //n=size(n);
}
