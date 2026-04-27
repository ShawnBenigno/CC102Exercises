//BENIGNO BSCS1A

#include <iostream>
#include <fstream>
using namespace std;


bool isPrime(int n){
    if(n <= 1)
        return false;
    if(n == 2)
        return true;
    if(n % 2 == 0)
        return false;

    for(int i = 3; i * i <= n; i += 2){
        if(n % i == 0)
            return false;
    }
    return true;
}


int countPrimes(){
    ifstream file("NUMS.TXT");
    int num, count=0;

    if(!file){
        cout<<"Error opening file!"<<endl;
        return 0;
    }

    while(file>>num){
        if(isPrime(num))
            count++;
    }

    file.close();
    return count;
}

int main(){
    cout<<"Number of prime numbers: "<<countPrimes()<<endl;
    return 0;
}
