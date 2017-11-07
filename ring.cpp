//credits - code-master5
#include<stdio.h>

struct proc{
	int pri;
	int flg;
}proc[20];
int e[20];	//to store ring status
int n;
int ring(int);
int main(){
	int ch,i,val,cord,fcord,pcrash,pstart,pact;
	val=0,cord=0;
	printf("\nEnter no of proc");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		printf("Enter Pri for %d : ",i);
		scanf("%d",&proc[i].pri);
		proc[i].flg=1;
	}//for scan & init 
	for(i=1;i<=n;i++){
		if(proc[i].pri>val){
			val=proc[i].pri;
			cord=i;
		}
	}
	fcord=cord;		//set initial cordinator
	printf("\n Coordinator is proc %d",fcord);
	do{

		printf("\n1)Crash Proc");
		printf("\n2)Activate Proc");
		printf("\n3) Display");
		printf("\n4)Exit");
		printf("\nEnter u r choice");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("\nEnter proc to be crashed");
				scanf("%d",&pcrash);
				printf("\nEnter proc to initiate");
				scanf("%d",&pstart);
				if(proc[pcrash].flg==0){	//already crashed
					printf("\nProc is already crashed");
				}else{
					proc[pcrash].flg=0;
					printf("\nProc Crashed ");
				}
				if(pcrash==fcord){
					fcord=ring(pstart);
				}else{
					pstart=ring(pstart);
					printf("\n Request Proc %d",pstart);
				}
			break;
			case 2:
				printf("\nEnter proc to be activate");
				scanf("%d",&pact);
				if(proc[pact].flg==1){
					printf("\nAlready Activated");
					break;
				}
				proc[pact].flg=1;
				if(proc[fcord].pri<proc[pact].pri){
					fcord=pact;
				}
				printf("\nCordinator is : %d",fcord);
				
			break;
			case 3:
				printf("\n Proc Status----------------------------------------->");
				printf("\n Proc Id Proc Pri  Proc Status");
				for(i=1;i<=n;i++){
					printf("\n %d %d %d",i,proc[i].pri,proc[i].flg);
				}
				printf("Cordinator---->%d",fcord);
			break;
		}//switch
	}while(ch!=4);
}//main
int ring(int r){
	int max,x,y,i=0,k;
	max=proc[r].pri;
	x=r;	//intial
	y=r+1;	//next in ring
	e[i++]=r;	//add r to array 
	while(y!=r){
		if(proc[y].flg!=0){		//check flg status for y
			e[i++]=y;
			printf("\nElection Msg from %d to %d",x,y);
			x=y;
			for(k=0;k<i;k++){		//i keep track of total values and k used to travel e
				printf("\t %d",proc[e[k]].pri);
			}//for
		}//if
		y=((y+1)%(n+1));	//to select next proc in ring
		max=e[0];	//set max to first
		for(k=0;k<i;k++){	
			if(proc[e[k]].pri>max){
				max=e[k];
			}
		}//for
	}//ring is complete
	return max;
}