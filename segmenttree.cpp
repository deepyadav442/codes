#include<iostream>
using namespace std;
#include<math.h>
#include<cstdio>
template<class T>
class SegmentTree
{
     long int *A,size;
     public:
     SegmentTree(long int N)
     {
          long int x = (long int)(ceil(log2(N)))+1;
          size = 2*(long int)pow(2,x);
          A = new long int[size];
         // memset(A,-1,sizeof(A));
     }
     void initialize(long int node, long int start,
                         long int end, T *array)
     {

          if (start==end)
             A[node] = start;
          else
          {
              long int mid = (start+end)/2;
              initialize(2*node,start,mid,array);
              initialize(2*node+1,mid+1,end,array);
              if (array[A[2*node]]>=
                     array[A[2*node+1]])
                 A[node] = A[2 * node];
              else
                  A[node] = A[2 * node + 1];
          }
     }
     int query(long int node, long int start,
                  long int end, long int i, long int j, T *array)
     {
         long int id1,id2;
         if (i>end || j<start)
            return -1;

         if (start>=i && end<=j)
            return A[node];

         long int mid = (start+end)/2;
         id1 = query(2*node,start,mid,i,j,array);
         id2 = query(2*node+1,mid+1,end,i,j,array);

         if (id1==-1)
            return id2;
         if (id2==-1)
            return id1;

         if (array[id1]>=array[id2])
            return id1;
         else
             return id2;
     }
};

int main()
{
    long int i,j,N;
    long int A[100001];
    scanf("%ld",&N);
    for (i=0;i<N;i++)
        scanf("%ld",&A[i]);
    SegmentTree<long int> s(N);
    s.initialize(1,0,N-1,A);
    long int m,x,y,qs,qe;
    long long sum=0;
    scanf("%ld%ld%ld",&m,&x,&y);
     for(i=1;i<=m;i++)
    {
        if(i==1)
        {
        //qs=min(x,y);
            if(x<y)
            {
                qs=x;
                qe=y;
            }
            else
            {
                qs=y;
                qe=x;
            }
        //qe=max(x,y);
       // printf("%ld  %ld",qs,qe);
        }

        else
        {
            x=(x+7)%(N-1);
            y=(y+11)%(N);
        //qs=min(x,y);
                if(x<y)
            {
                qs=x;
                qe=y;
            }
        else
            {
                qs=y;
                qe=x;
            }
            //qs=min(qe,qs);
           // qe=max(qe,qs);
              //printf("%ld  %ld",qs,qe);
        }



        sum+=A[s.query(1,0,N-1,qs,qe,A)];
        //printf("%ld\n",sum);
    }
    printf("%lld\n",sum);
    return 0;
    //while (scanf("%d%d",&i,&j)!=EOF)
     // printf("%d\n",A[s.query(1,0,N-1,i-1,j-1,A)]);
}
