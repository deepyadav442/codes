#include<bits/stdc++.h>
#define mod 1000000007
void precompute();
typedef long long int ll;
using namespace std;
inline ll input() //for input integers call it long long int n=input();
{
    ll n=0;
    char ch=getchar_unlocked();
    while( ch < '0' || ch > '9' )
    {
        ch=getchar_unlocked();
    }
    while( ch >= '0' && ch <= '9' )
    {
        n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
    }
    return n;
}
inline void output(ll n)     //for output call output(count) and then for space use put('\n');
{
    char b[35];
    ll i=0;
    do
    {
        b[i++]=n%10+48;
        n=n/10;
    }while(n!=0);
    --i;
    while(i>=0)
    putchar_unlocked(b[i--]);
}
inline void faststring(char *str)  //for entering a string use faststring(p);
{
    register char c = 0;
    register long long i = 0;
    while (c < 33)
    c = getchar_unlocked();
    while (c != '\n')
    {
        str[i] = c;
        c = getchar_unlocked();
        ++i;
    }
    str[i] = '\0';
}
vector<pair<ll, char*> >myvec(1000001);
typedef struct var
{
   ll a,b,c,d,ness,nwss,swss,sw,value;
}var;
map<ll,var> mapped;
ll n,c;
ll final,solve[50][30];
int main()
{
   ll t,i,j,k,a,b,flag=0,m,z,xr,xl,yu,yd;
   scanf("%lld",&t);
   while(t--)
   {
    final=0;
    cin>>z;
    c=0;
    xr=INT_MIN;
    xl=INT_MAX;
    yu=INT_MIN;
    yd=INT_MAX;
    precompute();
    for(i=0;i<z;i++)
    {
       scanf("%lld%lld",&a,&b);
       if(a>=xr)
       {
         xr=a;

         if(solve[0][0]<a || solve[1][0]<a)
            solve[0][0]=a,solve[0][1]=b,solve[1][0]=a,solve[1][1]=b,solve[1][2]=i,solve[0][2]=i;
         else
         {
           if(solve[0][0]==a && solve[1][0]==a )
           {
               if(solve[0][1]<b)
                solve[0][0]=a,solve[0][1]=b,solve[0][2]=i;
               if(solve[1][1]>b)
                solve[1][0]=a,solve[1][1]=b,solve[1][2]=i;
           }
         }
        }

      if(a<=xl)
       {
         xl=a;

         if(solve[2][0]>a || solve[2][0]>a)
            solve[2][0]=a,solve[2][1]=b,solve[3][0]=a,solve[3][1]=b,solve[2][2]=i,solve[3][2]=i;
         else
         {
           if(solve[2][0]==a && solve[3][0]==a )
           {
               if(solve[2][1]<b)
                solve[2][0]=a,solve[2][1]=b,solve[2][2]=i;
               if(solve[3][1]>b)
                solve[3][0]=a,solve[3][1]=b,solve[3][2]=i;
           }
         }
        }


      if(b>=yu)
       {
         yu=b;

         if(solve[4][1]<b || solve[5][1]<b)
            solve[4][0]=a,solve[4][1]=b,solve[5][0]=a,solve[5][1]=b,solve[4][2]=i,solve[5][2]=i;
         else
         {
           if(solve[4][1]==b && solve[5][1]==b )
           {
               if(solve[4][0]<a)
                solve[4][0]=a,solve[4][1]=b,solve[4][2]=i;
               if(solve[5][0]>a)
                solve[5][0]=a,solve[5][1]=b,solve[5][2]=i;
           }
         }
        }

      if(b<=yd)
       {
         yd=b;

         if(solve[6][1]>b || solve[7][1]>b)
            solve[6][0]=a,solve[6][1]=b,solve[7][0]=a,solve[7][1]=b,solve[6][2]=i,solve[7][2]=i;
         else
         {
           if(solve[6][1]==b && solve[7][1]==b )
           {
               if(solve[6][0]<a)
                solve[6][0]=a,solve[6][1]=b,solve[6][2]=i;
               if(solve[7][0]>a)
                solve[7][0]=a,solve[7][1]=b,solve[7][2]=i;
           }
         }
        }
    }

n=0;
for(i=0;i<8;i++)
{
  for(j=i+1;j<8;j++)
  {
    if((solve[i][0]==solve[j][0] && solve[i][1]==solve[j][1]) && (j!=i))
        break;
  }

  if(j>=8)
  {
    mapped[n]={solve[i][0],solve[i][1],0,0,0,0,0,0,solve[i][2]};
    n++;
  }
}


 while(1)
    {

       flag=0;
       k=0;
       for(i=0;i<n;i++)
       {
         if(mapped[i].c==1)
             k++;
         else
             flag=1;

            mapped[i].ness=0,mapped[i].nwss=0,mapped[i].sw=0,mapped[i].swss=0;
       }

       if(k==n || flag==0)
        break;

       for(i=0;i<n;i++)
       {
         if(mapped[i].d==0 )
         {
            for(j=0 ;j<n; j++)
            {
              if(mapped[j].c==0)
              {

		if((mapped[j].a-mapped[i].a)>=0 && (mapped[j].b-mapped[i].b)<=0)
                	mapped[i].swss=mapped[i].swss+1;
		if((mapped[j].a-mapped[i].a)<=0 && (mapped[j].b-mapped[i].b)<=0)
	                mapped[i].sw=mapped[i].sw+1;
               if((mapped[j].a-mapped[i].a)>=0 && (mapped[j].b-mapped[i].b)>=0)
                mapped[i].ness=mapped[i].ness+1;

               if((mapped[j].a-mapped[i].a)<=0 && (mapped[j].b-mapped[i].b)>=0)
                mapped[i].nwss=mapped[i].nwss+1;




             }
            }
         }
       }

       m=0,k=-1;

       for(i=0;i<n;i++)
       {
         if(mapped[i].d==0)
         {
              if(mapped[i].ness>m)
               {
                m=mapped[i].ness;
                k=i;
               }

               if(mapped[i].nwss>m)
               {
                m=mapped[i].nwss;
                k=i;
               }

               if(mapped[i].sw>m)
               {
                m=mapped[i].sw;
                k=i;
               }

               if(mapped[i].swss>m)
               {
                m=mapped[i].swss;
                k=i;
               }
            }
           }

         if(k==-1)
            break;

         if(m==mapped[k].ness)
         {
           myvec[final].first=mapped[k].value;
           myvec[final].second="NE";
           final++;
           mapped[k].d=1;
           mapped[k].c=1;
           for(i=0;i<n;i++)
           {
             if((mapped[i].a-mapped[k].a)>=0 && (mapped[i].b-mapped[k].b)>=0)
                mapped[i].c=1;
           }
         }
         else
         {
          if(m==mapped[k].nwss)
           {
            myvec[final].first=mapped[k].value;
            myvec[final].second="NW";
            final++;
            mapped[k].d=1;
            mapped[k].c=1;
            for(i=0;i<n;i++)
            {
              if((mapped[i].a-mapped[k].a)<=0 && (mapped[i].b-mapped[k].b)>=0)
                 mapped[i].c=1;
            }
           }
            else
            {
             if(m==mapped[k].swss)
              {
                myvec[final].first=mapped[k].value;
                myvec[final].second="SE";
                final++;
                mapped[k].d=1;
                mapped[k].c=1;
                for(i=0;i<n;i++)
                {
                  if((mapped[i].a-mapped[k].a)>=0 && (mapped[i].b-mapped[k].b)<=0)
                  mapped[i].c=1;
                }
               }
               else
               {
                if(m==mapped[k].sw)
                {
                 myvec[final].first=mapped[k].value;
                 myvec[final].second="SW";
                 final++;
                 mapped[k].d=1;
                 mapped[k].c=1;
                 for(i=0;i<n;i++)
                 {
                  if((mapped[i].a-mapped[k].a)<=0 && (mapped[i].b-mapped[k].b)<=0)
                   mapped[i].c=1;
                 }
                }
               }
              }
             }



      }


cout<<final<<"\n";
for(i=0;i<final;i++)
  cout<<myvec[i].first+1<<" "<<myvec[i].second<<"\n";
   }

return 0;
}
void precompute()
{
 solve[0][0]=INT_MIN,solve[0][1]=INT_MIN;
 solve[1][0]=INT_MIN,solve[1][1]=INT_MAX;
 solve[2][0]=INT_MAX,solve[2][1]=INT_MIN;
 solve[3][0]=INT_MAX,solve[3][1]=INT_MAX;
 solve[4][0]=INT_MIN,solve[4][1]=INT_MIN;
 solve[5][0]=INT_MIN,solve[5][1]=INT_MAX;
 solve[6][0]=INT_MIN,solve[6][1]=INT_MAX;
 solve[7][0]=INT_MIN,solve[7][1]=INT_MAX;
return ;
}

