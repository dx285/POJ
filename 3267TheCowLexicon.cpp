#include<iostream>
#include<string>
#include<set>
#include<string.h>
#include<stdio.h>
using namespace std;
char words[600][30];
char msg[310];
int W,L;
int dp[310];

int main()
{
    scanf("%d%d",&W,&L);
    scanf("%s",msg);
    for(int i=0;i<W;i++)
        scanf("%s",words[i]);
    
    dp[L]=0;
    for(int i=L-1;i>=0;i--)
    {
        dp[i]=dp[i+1]+1; // remove ith char
        
        //but if there is some match with any words
        for(int j=0;j<W;j++){
            if(msg[i]!=words[j][0]) continue;
            int len=strlen(words[j]);
            int k=0,t=i;
            for(k=0;k<len;k++,t++)
            {
                while(t<L && msg[t]!=words[j][k]) t++;
                if(t==L) break;
            }
            t--;
            //printf("%s -> %d",words[j],k);
            if(k==len) dp[i]=min(dp[i],dp[t+1]+t-i+1-len);
        }
        //printf("%d->%d\n",i,dp[i]);
        
    }
    
        
    printf("%d\n",dp[0]);
    
}
