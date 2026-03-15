//BENIGNO BSCS1A

#include <iostream>
#include <array>
using namespace std;

void analyzeGrades(int *grades, int students, int subjects) {
    int highest = *(grades);

    cout<<"\nStudents\t";
    for(int i = 0;i < subjects;i++){
        cout<<"Sub "<<i+1<<"\t\t";
    }

    cout<<"Average";
    cout<<"\n";

    for (int i = 0;i < students;i++) {
        float sum = 0;
        cout<<"Student "<<i+1 <<"\t";
        for (int j = 0;j < subjects;j++) {
            int value = *(grades + i * subjects + j);
            cout<<value<<"\t\t";
            sum += value;

            if (value > highest) {
                highest = value;
            }
        }
        cout<<sum / subjects;
        cout<<endl;
    }

    cout<<"\nHighest Grade : "<<highest<<endl;
}

int main() {
    int students, subjects;

    cout<<"Enter number of students: ";
    cin>>students;

    cout<<"Enter number of subjects: ";
    cin>>subjects;

    int grades[students][subjects];

    cout<<"\nEnter grades:\n";
    for (int i = 0;i < students;i++) {
        for (int j = 0;j < subjects;j++) {
            cout<<"Student "<< i+1<<", Subject "<<j+1<<": ";
            cin>>grades[i][j];
        }
        cout<<"--------------------\n";
    }

    analyzeGrades(&grades[0][0], students, subjects);

    return 0;
}
