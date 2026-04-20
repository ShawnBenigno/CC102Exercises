//BENIGNO BSCS1A

#include <iostream>
#include <fstream>
using namespace std;

int main(){
    fstream file, copyFile;
    string line;

    file.open("color.txt", ios::out);
    if (file.is_open()){
        file<<"Red\nBlue\nGreen\nYellow\nPurple\n";
        file.close();
    }else{
        cout<<"Failed to create color.txt\n";
        return 1;
    }

    file.open("color.txt", ios::in);
    if(!file.is_open()){
        cout<<"Failed to open color.txt for reading\n";
        return 1;
    }

    copyFile.open("color_copy.txt", ios::out);
    if(!copyFile.is_open()){
        cout<<"Failed to create color_copy.txt\n";
        file.close();
        return 1;
    }

    while (getline(file, line)){
        copyFile<<line<<endl;
    }

    file.close();
    copyFile.close();

    cout<<"File copied successfully!\n";
    return 0;
}
