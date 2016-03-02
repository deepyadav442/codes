#include<iostream>
#include<stdio.h>
#define INF 800000
#define MOD 10000000000
#define ll long long
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef struct strin
{
  ll i;
  char *name;
}strin;


typedef struct str
{
   ll x,y,l,h,ne,nw,se,sw,key;
}str;

map<ll,str> mymap;

ll n,c;
vector<strin> vec(10);


ll tot,arr[8][3];


void init()
{
 arr[0][0]=-MOD,arr[0][1]=-MOD; //r u
 arr[1][0]=-MOD,arr[1][1]=MOD;  //r d
 arr[2][0]=MOD,arr[2][1]=-MOD; // l u
 arr[3][0]=MOD,arr[3][1]=MOD; // l d
 arr[4][0]=-MOD,arr[4][1]=-MOD; // t r
 arr[5][0]=-MOD,arr[5][1]=MOD; // t l
 arr[6][0]=-MOD,arr[6][1]=MOD; // b r
 arr[7][0]=-MOD,arr[7][1]=MOD; // b l
return ;
}

int main()
{
   ll t,i,j,k,x,y,flag=0,m,n2,xr,xl,yu,yd;
   cin>>t;
   while(t--)
   {
    tot=0;
    cin>>n2;
    c=0;
    xr=-MOD;
    xl=MOD;
    yu=-MOD;
    yd=MOD;
    init();
    for(i=0;i<n2;i++)
    {
       scanf("%lld%lld",&x,&y);
       if(x>=xr)
       {
         xr=x;

         if(arr[0][0]<x || arr[1][0]<x)
            arr[0][0]=x,arr[0][1]=y,arr[1][0]=x,arr[1][1]=y,arr[1][2]=i,arr[0][2]=i;
         else
         {
           if(arr[0][0]==x && arr[1][0]==x )
           {
               if(arr[0][1]<y)
                arr[0][0]=x,arr[0][1]=y,arr[0][2]=i;
               if(arr[1][1]>y)
                arr[1][0]=x,arr[1][1]=y,arr[1][2]=i;
           }
         }
        }

      if(x<=xl)
       {
         xl=x;

         if(arr[2][0]>x || arr[2][0]>x)
            arr[2][0]=x,arr[2][1]=y,arr[3][0]=x,arr[3][1]=y,arr[2][2]=i,arr[3][2]=i;
         else
         {
           if(arr[2][0]==x && arr[3][0]==x )
           {
               if(arr[2][1]<y)
                arr[2][0]=x,arr[2][1]=y,arr[2][2]=i;
               if(arr[3][1]>y)
                arr[3][0]=x,arr[3][1]=y,arr[3][2]=i;
           }
         }
        }


      if(y>=yu)
       {
         yu=y;

         if(arr[4][1]<y || arr[5][1]<y)
            arr[4][0]=x,arr[4][1]=y,arr[5][0]=x,arr[5][1]=y,arr[4][2]=i,arr[5][2]=i;
         else
         {
           if(arr[4][1]==y && arr[5][1]==y )
           {
               if(arr[4][0]<x)
                arr[4][0]=x,arr[4][1]=y,arr[4][2]=i;
               if(arr[5][0]>x)
                arr[5][0]=x,arr[5][1]=y,arr[5][2]=i;
           }
         }
        }

      if(y<=yd)
       {
         yd=y;

         if(arr[6][1]>y || arr[7][1]>y)
            arr[6][0]=x,arr[6][1]=y,arr[7][0]=x,arr[7][1]=y,arr[6][2]=i,arr[7][2]=i;
         else
         {
           if(arr[6][1]==y && arr[7][1]==y )
           {
               if(arr[6][0]<x)
                arr[6][0]=x,arr[6][1]=y,arr[6][2]=i;
               if(arr[7][0]>x)
                arr[7][0]=x,arr[7][1]=y,arr[7][2]=i;
           }
         }
        }
    }

n=0;
for(i=0;i<8;i++)
{
  for(j=i+1;j<8;j++)
  {
    if((arr[i][0]==arr[j][0] && arr[i][1]==arr[j][1]) && (j!=i))
        break;
  }

  if(j>=8)
  {
    mymap[n]={arr[i][0],arr[i][1],0,0,0,0,0,0,arr[i][2]};
    n++;
  }
}


 while(1)
    {

       flag=0;
       k=0;
       for(i=0;i<n;i++)
       {
         if(mymap[i].l==1)
             k++;
         else
             flag=1;

            mymap[i].ne=0,mymap[i].nw=0,mymap[i].sw=0,mymap[i].se=0;
       }

       if(k==n || flag==0)
        break;

       for(i=0;i<n;i++)
       {
         if(mymap[i].h==0 )
         {
            for(j=0 ;j<n; j++)
            {
              if(mymap[j].l==0)
              {
               if((mymap[j].x-mymap[i].x)>=0 && (mymap[j].y-mymap[i].y)>=0)
                mymap[i].ne=mymap[i].ne+1;

               if((mymap[j].x-mymap[i].x)<=0 && (mymap[j].y-mymap[i].y)>=0)
                mymap[i].nw=mymap[i].nw+1;

               if((mymap[j].x-mymap[i].x)<=0 && (mymap[j].y-mymap[i].y)<=0)
                mymap[i].sw=mymap[i].sw+1;

               if((mymap[j].x-mymap[i].x)>=0 && (mymap[j].y-mymap[i].y)<=0)
                mymap[i].se=mymap[i].se+1;
             }
            }
         }
       }

       m=0,k=-1;

       for(i=0;i<n;i++)
       {
         if(mymap[i].h==0)
         {
              if(mymap[i].ne>m)
               {
                m=mymap[i].ne;
                k=i;
               }

               if(mymap[i].nw>m)
               {
                m=mymap[i].nw;
                k=i;
               }

               if(mymap[i].sw>m)
               {
                m=mymap[i].sw;
                k=i;
               }

               if(mymap[i].se>m)
               {
                m=mymap[i].se;
                k=i;
               }
            }
           }

         if(k==-1)
            break;

         if(m==mymap[k].ne)
         {
           vec[tot].i=mymap[k].key;
           vec[tot].name="NE";
           tot++;
           mymap[k].h=1;
           mymap[k].l=1;
           for(i=0;i<n;i++)
           {
             if((mymap[i].x-mymap[k].x)>=0 && (mymap[i].y-mymap[k].y)>=0)
                mymap[i].l=1;
           }
         }
         else
         {
          if(m==mymap[k].nw)
           {
            vec[tot].i=mymap[k].key;
            vec[tot].name="NW";
            tot++;
            mymap[k].h=1;
            mymap[k].l=1;
            for(i=0;i<n;i++)
            {
              if((mymap[i].x-mymap[k].x)<=0 && (mymap[i].y-mymap[k].y)>=0)
                 mymap[i].l=1;
            }
           }
            else
            {
             if(m==mymap[k].se)
              {
                vec[tot].i=mymap[k].key;
                vec[tot].name="SE";
                tot++;
                mymap[k].h=1;
                mymap[k].l=1;
                for(i=0;i<n;i++)
                {
                  if((mymap[i].x-mymap[k].x)>=0 && (mymap[i].y-mymap[k].y)<=0)
                  mymap[i].l=1;
                }
               }
               else
               {
                if(m==mymap[k].sw)
                {
                 vec[tot].i=mymap[k].key;
                 vec[tot].name="SW";
                 tot++;
                 mymap[k].h=1;
                 mymap[k].l=1;
                 for(i=0;i<n;i++)
                 {
                  if((mymap[i].x-mymap[k].x)<=0 && (mymap[i].y-mymap[k].y)<=0)
                   mymap[i].l=1;
                 }
                }
               }
              }
             }
      }//end of while(1);


cout<<tot<<"\n";
for(i=0;i<tot;i++)
  cout<<vec[i].i+1<<" "<<vec[i].name<<"\n";
   }

return 0;
}
