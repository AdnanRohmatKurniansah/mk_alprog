#include <iostream> 

using namespace std;

void A(int &c),B(int c);
int C(int c);

int a=1,b=2;

int main(){
    int c = 5;
    cout<<a<<" "<<b<<" "<<c<<endl;
    A(c);
    cout<<a<<" "<<b<<" "<<c<<endl;

    return 0;
}

void A(int &c){
    B(c);
}

void B(int c){
    cout << a << " " << b << " "<<c<<endl;
    for (int i=0;i>-1; i--) c=C(2+c)+b+i; 
    cout<< a << " " << b <<" "<<c<<endl;
}
int C(int c){
    return c+1;
}