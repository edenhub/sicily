#include <stdio.h>  
#include <memory.h>  
#include <stdlib.h>  
int road[120][120];  
long long result[120][120];  
int main() {  
    int n,m,l;  
    int x,y,q;  
    int i,j,k;  
    while (scanf("%d",&n)!=EOF) {  
        scanf("%d%d",&m, &l);  
        memset(road, 0, 120*120);  
              
        for (i=0;i<m;i++) {  
            scanf("%d%d",&x,&y);  
            road[x][y]=1;  
        }  
        scanf("%d",&q);  
        while (q--) {  
            scanf("%d%d",&x,&y);  
            memset(result, 0, sizeof(result));  
            result[0][x]=1;  
            for (i=1;i<=l;i++) {  
                for (j=1;j<=n;j++) {  
                    for (k=1;k<=n;k++) {  
                        if (road[j][k]==1)  
                            result[i][k]+=result[i-1][j];  
                    }  
                }  
            }  
            printf("%lld\n", result[l][y]);  
        }     
    }  
    //system("pause");  
    return 0;  
}                