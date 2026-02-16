//Benigno BSCS1A

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

int main() {
    char again;

    do {
        int students, quizzes;
        cout << "Enter number of students: ";
        cin >> students;

        cout << "Enter number of quizzes: ";
        cin >> quizzes;

        int scores[50][50];
        double average[50];

        for (int i = 0; i < students; i++) {
            int sum = 0;
            cout << "\nStudent " << (i + 1) << " scores:\n";

            for (int j = 0; j < quizzes; j++) {
                cout << "Quiz " << (j + 1) << ": ";
                cin >> scores[i][j];
                sum += scores[i][j];
            }

            average[i] = (double)sum / quizzes;
        }

        // Final Output table like format
        cout << "\nStudent\t";
        for (int j = 0; j < quizzes; j++) {
            cout << "Q" << (j + 1) << "\t";
        }
        cout << "Average\n";

        for (int i = 0; i < students; i++) {
            cout << (i + 1) << "\t";
            for (int j = 0; j < quizzes; j++) {
                cout << scores[i][j] << "\t";
            }
            cout << average[i] << endl;
        }

        cout << "\nRun again? (Y/N): ";
        cin >> again;

    } while (again == 'Y' || again == 'y');

    return 0;
}
