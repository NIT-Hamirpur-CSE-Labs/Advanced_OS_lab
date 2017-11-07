//credits - code-master5
#include<iostream>
using namespace std;

int main(){
    int t1,t2,rtt, ft;
    cout << "Enter the Initial Time: ";
    cin >> t1;
    cout << "Enter the Time Recieved: ";
    cin >> t2;
    cout << "Enter the Round Trip Time: ";
    cin >> rtt;
    ft = t2 + rtt/2;
    cout << "Initial Time of Process: " << t1 << endl;
    cout << "Final Time After Synchronisation: " << ft << endl;
    return 0;   
}
