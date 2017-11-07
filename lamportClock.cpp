//credits - code-master5
#include<bits/stdc++.h>
using namespace std;

//to find the maximum timestamp between two events
int max1(int a, int b) {
    if (a>b)
        return a;
    else
        return b;
}

int main() {
    int i,j,k,p1[20],p2[20],e1,e2,dep[20][20];
    printf("Enter the events: ");
    scanf("%d %d", &e1, &e2);
    for(i=0;i<e1;i++)
        p1[i]=i+1;
    for(i=0;i<e2;i++)
        p2[i]=i+1;
    printf("Enter the dependency matrix:\n");
    printf("\t Enter 1 if e1->e2 \n\t Enter -1, if e2->e1 \n\t else Enter 0 \n\n");
    for(i=0;i<e2;i++)
        printf("\te2%d",i+1);
    for(i=0;i<e1;i++) {
        printf("\n e1%d \t",i+1);
        for(j=0;j<e2;j++)
            scanf("%d",&dep[i][j]);
    }

    for(i=0;i<e1;i++){
        for(j=0;j<e2;j++){
            //change the timestamp if dependency exist
            if(dep[i][j]==1){   
                p2[j]=max1(p2[j],p1[i]+1);
                    for(k=j;k<e2;k++)
                        p2[k+1]=p2[k]+1;
            }
            //change the timestamp if dependency exist
            if(dep[i][j]==-1){
                p1[i]=max1(p1[i],p2[j]+1);
                for(k=i;k<e1;k++)
                    p2[k+1]=p1[k]+1;
            }

        }
    }
    //to print the outcome of Lamport Logical Clock
    printf("\n");
    printf("P1 : ");     
    for(i=0;i<e1;i++)
        printf("%d ",p1[i]);
    printf("\n");
    printf("P2 : ");
    for(j=0;j<e2;j++)
        printf("%d ",p2[j]);
    printf("\n");
    return 0 ;
}
