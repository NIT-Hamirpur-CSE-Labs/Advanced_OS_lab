#include<iostream>
using namespace std;
int main(){
int t1i,t1f,t2,rtt, ft;
int h1i,m1i,s1i,h2,m2,s2,h1f,m1f,s1f;
cout<<"\nEnter the initial time of A(Hours:Min:Sec): ";
cin>>h1i>>m1i>>s1i;
t1i=h1i*60*60 + m1i*60 +s1i;

cout<<"\nEnter the time sent by B(Hours:Min:Sec): ";
cin>>h2>>m2>>s2;
t2=h2*60*60 + m2*60 +s2;

cout<<"\nEnter the time when A receives the message from B(Hours:Min:Sec): ";
cin>>h1f>>m1f>>s1f;
t1f=h1f*60*60 + m1f*60 +s1f;

rtt=t1f-t1i;
ft = t2+rtt/2;

//cout<<"\n initial time of process "<<t1;
cout<<"\nFinal time after synchronisation "<<ft/3600<<":"<<(ft%3600)/60<<":"<<(ft%3600)%60<<"\n";
return 0;
}
