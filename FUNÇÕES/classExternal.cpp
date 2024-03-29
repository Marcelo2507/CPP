#include <iostream>
#include <string>
using namespace std;

class Car{
    public:
    int speed(int maxSpeed);
};

int main(){
    Car myObj;    
    cout << myObj.speed(200);
    return 0;
}

int Car::speed(int maxSpeed){
    return maxSpeed;
}