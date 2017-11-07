//credits - code-master5
#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int mt, pt[100], diff[100],n, l=5, s=0,avg, count=0;
    
    cout << "Enter Master Time: ";
    cin >> mt;

    cout << "Enter the number of Process: ";
    cin >> n;

    cout << "Enter their Times: ";
    for(int i=0;i<n;i++) {
        cin >> pt[i];
    }
    for(int i=0;i<n;i++) {
        if(abs(mt-pt[i]) < 5) {
            s += pt[i];
            count++;
        }

    }
    avg = s/count;
    cout << "n average: " << avg << endl;
    for(int i=0; i<n; i++) {
        diff[i]=pt[i]-avg;
    }
    cout << endl;
    for(int i=0; i<n; i++){
        cout << "Error Value for Process " << i << ": " << diff[i] << endl; 
        cout << "Final Clock Value: " << pt[i]-diff[i] << endl;
    }

    return 0;
}

