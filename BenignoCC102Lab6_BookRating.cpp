//BENIGNO BSCS1A

#include <iostream>
#include <string>
#include <array>
#include <iomanip>
using namespace std;

struct Book{
    int barcode;
    string title;
    int year;
    int rating;
};

string getCategory(int rating){
    if(rating == 5) return "Excellent";
    else if(rating == 4) return "Very Good";
    else if(rating == 3) return "Good";
    else if(rating == 2) return "Fair";
    else if(rating == 1) return "Poor";
    else return "No Rating";
}

bool isDuplicate(Book books[], int n, int barcode){
    for (int i = 0;i < n;i++){
        if (books[i].barcode == barcode){
            return true;
        }
    }
    return false;
}

int main(){
    int n;
    char choice;
    Book books[n];

    do{
        cout<<"Enter number of books: ";
        cin>>n;


        for(int i = 0;i < n;i++){
            cout<<"\nBook "<<i + 1<<endl;

            do{
                cout<<"Enter barcode: ";
                cin>>books[i].barcode;

                if(isDuplicate(books, i, books[i].barcode)){
                    cout<<"Barcode already exists! Try again.\n";
                }else{
                    break;
                }
            }while(true);

            cin.ignore();

            cout<<"Enter title: ";
            getline(cin, books[i].title);

            cout<<"Enter year: ";
            cin>>books[i].year;

            do{
                cout<<"Enter rating (0-5): ";
                cin>>books[i].rating;

                if(books[i].rating < 0 || books[i].rating > 5){
                    cout<<"Invalid rating! Try again.\n";
                }else{
                    break;
                }
            }while(true);
        }

        cout<<"\n\n--------------------- Book List ---------------------------------\n";
        cout<<left
            <<setw(10)<<"Barcode"
            <<setw(25)<<"Title"
            <<setw(10)<<"Year"
            <<setw(10)<<"Rating"
            <<setw(15)<<"Category"<<endl;
        cout<<"-----------------------------------------------------------------\n";

        for(int i = 0; i < n; i++){
            cout<<left
                <<setw(10)<<books[i].barcode
                <<setw(25)<<books[i].title
                <<setw(10)<<books[i].year
                <<setw(10)<<books[i].rating
                <<setw(15)<<getCategory(books[i].rating)
                <<endl;
        }

        cout<<"\nDo you want to run again? (y/n): ";
        cin>>choice;

    } while(choice == 'y' || choice == 'Y');

    return 0;
}
