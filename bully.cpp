//credits - code-master5
#include<bits/stdc++.h>
using namespace std;
struct proc{
	int pid,st,p;
}pd[20];
bool compare(proc a, proc b){
	return a.p<b.p;
}
int n;
int bully(int pid){
	int index;
	for(int i=0;i<n;i++){
		if(pd[i].pid == pid){
			index = i;
		}
	}
	int mindex=index;
	for(int i=index;i<n;i++){
		if(pd[i].st == 1)
			mindex = i;

	}

	return pd[mindex].pid;
}

int main(){
	cout<<"\n enter the number of processes ";
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"\n enter the priority of process "<<i<<" : ";
		cin>>pd[i].p;
		pd[i].st=1;
		pd[i].pid=i;
	}
	sort(pd, pd+n, compare);
	char choice;
	int pid, leader;


	
	do{
		cout<<"\n 1. Activate ";
		cout<<"\n 2. Crash ";
		cout<<"\n 3. Start Election ";
		cout<<"\n 4. Exit ";

		cin>>choice;
		switch(choice){
		case '1':
		cout<<"\n enter the process id ";
		cin>>pid;
		for(int i=0;i<n;i++){
			if(pd[i].pid == pid)
				pd[i].st=1;
		}
		break;
		case '2':
		cout<<"\n enter the process id ";
		cin>>pid;
		for(int i=0;i<n;i++){
			if(pd[i].pid == pid)
				pd[i].st=0;
		}
		break;
		case '3':
		cout<<"\n enter the process id ";
		cin>>pid;
		leader = bully(pid);
		cout<<"\n coordinator--> : "<<leader;
		break;

	}
	}while(choice!='4');
	
}