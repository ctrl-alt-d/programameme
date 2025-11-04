#include <iostream>
using namespace std;

void caso(int dife, int vel_max, int segs) {

    auto vel_m_s = float(dife) / float(segs);
    auto vel_km_h = vel_m_s * 3.6;

    if (dife < 0 || vel_max < 0 || segs <= 0) {
        cout << "ERROR" << endl;
    } else if(vel_km_h <= vel_max) {
        cout<<"OK"<<endl;
    } else if (vel_km_h <= vel_max * 1.2) {
        cout<<"MULTA"<<endl;
    } else {
        cout<<"PUNTOS"<<endl;
    }
}

int main() {

    int dife, vel_max, segs;

    auto x = 111;

    cin>>dife>>vel_max>>segs;
    while(dife !=0 && vel_max != 0 && segs !=0) {
    
        caso(dife, vel_max, segs);
        cin>>dife>>vel_max>>segs;
    
    }
  
    return 0;
}