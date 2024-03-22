#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>

#define ADMINUSER "Teacher"
#define ADMINPASSWORD "teacher123"
#define USER "Student"
#define USERPASSWORD "student123"

using namespace std;

int addBook();
int deleteBook();
int updateBook();
int listOfAllBooks();
int borrowBook();
int returnBook();
int adminLogin();
int userLogin();

int main(int argc, char **argv) {

    int outerChoice = 0;

    while (outerChoice != 9) {

        system("cls");

        cout << "\n Library Management System \n\n";
        cout << "\n1. Teacher";
        cout << "\n2. Student";
        cout << "\n9. Exit";
        cout << "\n\nEnter your choice : ";
        cin >> outerChoice;

        if (outerChoice == 1) {

            char adminUser[10];
            char adminPassword[10];

            system("cls");

            cout << "\n ---------- Teacher Login -------";
            cout << "\n\n Please enter your username: ";
            cin >> adminUser;
            cout << "\n Please enter your password:";
            cin >> adminPassword;

            if ((strcmp(adminUser, ADMINUSER) == 0) &&
                (strcmp(adminPassword, ADMINPASSWORD) == 0)) {

                getchar();
                getchar();

                system("cls");

                int innerChoice = 0;

                while (innerChoice != 9) {

                    cout << "\n\n Teacher Login is Successful !! Press any button to continue..";
                    cout << "\n1. Add new book";
                    cout << "\n2. Update any Book";
                    cout << "\n3. Delete Book";
                    cout << "\n4. List of all Books";
                    cout << "\n9. Exit";
                    cout << "\n\n Please enter your choice : ";
                    cin >> innerChoice;

                    switch (innerChoice) {

                        case 1:
                            addBook();
                            break;

                        case 2:
                            updateBook();
                            break;

                        case 3:
                            deleteBook();
                            break;

                        case 4:
                            listOfAllBooks();
                            break;

                        default:
                            cout << "\n\n Invalid Choice. Please enter the valid one";
                            getchar();
                    }

                    system("cls");
                }
            } else {
                cout << "\n\n Error : Invalid Credentials. Please check your Credentials";
                getchar();
                getchar();
            }

        } else if (outerChoice == 2) {

            char studentUser[10];
            char studentPassword[10];

            system("cls");

            cout << "\n ---------- Student Login -------";
            cout << "\n\n Please enter your username: ";
            cin >> studentUser;
            cout << "\n Please enter your password:";
            cin >> studentPassword;

            if ((strcmp(studentUser, USER) == 0) &&
                (strcmp(studentPassword, USERPASSWORD) == 0)) {

                int innerChoice = 0;

                while (innerChoice != 9) {

                    system("cls");

                    cout << "\n1. Borrow a Book";
                    cout << "\n2. Return a Book";
                    cout << "\n3. List of All Books";
                    cout << "\n9. Exit";
                    cout << "\n\n Enter your choice : ";
                    cin >> innerChoice;

                    switch (innerChoice) {

                        case 1:
                            borrowBook();
                            break;

                        case 2:
                            returnBook();
                            break;

                        case 3:
                            listOfAllBooks();
                            break;

                        case 9:
                            break;

                        default:
                            cout << "\n\n Error: Invalid Choice. Please enter the valid one";
                            getchar();
                            getchar();
                    }
                }

                system("cls");

            } else {
                cout << "\n\n Error : Invalid Credentials. Please check your Credentials";
                getchar();
                getchar();
            }

        } else if (outerChoice != 9) {
            cout << "\n\n Invalid choice. Press any key to continue..";
            getchar();
            getchar();
        } else {
            cout << "\n\n Thank you for using it !! Press any key to exit";
            getchar();
            getchar();
        }
    }
    return 0;
}

int addBook() {
    int bookid;
    char bookname[20];
    char bookauthor[20];
    int year, month, day;

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    year = tm.tm_year + 1900;
    month = tm.tm_mon + 1;
    day = tm.tm_mday;

    system("cls");
    cout << "\n ---- Add a new Book ----";
    cout << "\n\n Please enter 4 digit numeric id :";
    cin >> bookid;
    cout << "\n Please enter book name : ";
    cin >> bookname;
    cout << "\n Please enter book author : ";
    cin >> bookauthor;
    char filename[20];
    sprintf(filename, "%d%s", bookid, ".dat");
    ofstream file(filename);
    file << bookname << "\n";
    file << bookauthor << "\n";
    file << year << "\n";
    file << month << "\n";
    file << day << "\n";
    file.close();
    cout << "\n Your file Saved Successfully !!";
    getchar();
    getchar();
    return 0;
}

int deleteBook() {
    return 0;
}

int updateBook() {
    return 0;
}

int listOfAllBooks() {
    return 0;
}

int borrowBook() {
    return 0;
}

int returnBook() {
    return 0;
}

int adminLogin() {
    return 0;
}

int userLogin() {
    return 0;
}
