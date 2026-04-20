//BENIGNO BSCS1A

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main(){
    fstream file;
    string words[10];
    int count = 0;

    file.open("original.txt", ios::out);
    if(file.is_open()){
        file<<"One\nTwo\nThree\nFour\nFive\nSix\n";
        file.close();
    }else{
        cout<<"Failed to create file.\n";
        return 1;
    }

    file.open("original.txt", ios::in);
    if(file.is_open()){
        while (getline(file, words[count])){
            count++;
        }
        file.close();
    }else{
        cout<<"Failed to read file.\n";
        return 1;
    }


    sort(words, words+count);

    file.open("sorted.txt", ios::out);
    if(file.is_open()){
        for (int i=0; i<count; i++){
            file<<words[i]<<endl;
        }
        file.close();
    }else{
        cout<<"Failed to write sorted file.\n";
    }

    cout<<"Sorting complete!\n";
    return 0;
}
