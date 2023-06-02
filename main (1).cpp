#include <iostream>
#include <fstream>

using namespace std;

class shopping {
private:
    int pcode;
    float price;
    float dis;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};

void shopping::menu() {
    m:
    int choice;
    string email;
    string password;

    cout << "\t\t\t\t__________________________________\n";
    cout << "\t\t\t\t                                 \n";
    cout << "\t\t\t\t    supermarket main menu         \n";
    cout << "\t\t\t\t                                 \n";
    cout << "\t\t\t\t__________________________________\n";
    cout << "\t\t\t\t                                 \n";
    cout << "\t\t\t\t|  1) Administrator    |\n";
    cout << "\t\t\t\t|                      |\n";
    cout << "\t\t\t\t|  2) Buyer            |\n";
    cout << "\t\t\t\t|                      |\n";
    cout << "\t\t\t\t|  3) Exit             |\n";
    cout << "\t\t\t\t|                      |\n";
    cout << "\n\t\t\t please select!";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "\t\t\t Please Login \n";
            cout << "\t\t\t enter email  \n";
            cin >> email;
            cout << "\t\t\t password  \n";
            cin >> password;

            if (email == "bob@email.com" && password == "bob@123") {
                administrator();
            } else {
                cout << "invalid email/password";
            }
            break;

        case 2:
            buyer();
            break;

        case 3:
            exit(0);

        default:
            cout << "please select from given options";
            break;
    }

    goto m;
}

void shopping::administrator() {
    m:
    int choice;
    cout << "\n\n\n\t\t\t administrator menu";
    cout << "\n\t\t\t|_____1) Add the product______|";
    cout << "\n\t\t\t|                             |";
    cout << "\n\t\t\t|_____2) modify the product___|";
    cout << "\n\t\t\t|                             |";
    cout << "\n\t\t\t|_____3) delete the product___|";
    cout << "\n\t\t\t|                             |";
    cout << "\n\t\t\t|_____4) Back to main menu ___|";

    cout << "\n\t\t please enter your choice ";
    cin >> choice;

    switch (choice) {
        case 1:
            add();
            break;

        case 2:
            edit();
            break;

        case 3:
            rem();
            break;

        case 4:
            menu();
            break;

        default:
            cout << "invalid choice!! ";
            break;
    }

    goto m;
}

void shopping::buyer() {
m:
    int choice;
    cout << "\t\t\t    buyer     \n";
    cout << "\t\t\t______________\n";
    cout << "                     \n";
    cout << "\t\t\t 1) buy product\n";
    cout << "                     \n";
    cout << "\t\t\t 2) go back    \n";
    cout << "\t\t\t enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            receipt();
            break;

        case 2:
            menu();
            break;

        default:
            cout << "invalid choice";
            break;
    }

    goto m;
}

void shopping::add() {
m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout << "\n\n\t\t\t add new product";
    cout << "\n\n\t product code of the product ";
    cin >> pcode;
    cout << "\n\n Name of the product ";
    cin >> pname;
    cout << "\n\n\t Price of product";
    cin >> price;
    cout << "\n\n\t discount on product ";
    cin >> dis;

    data.open("database.txt", ios::in);

    if (!data) {
        data.open("database.txt", ios::app | ios::out);
        data << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close();

    } else {
        data >> c >> n >> p >> d;

        while (!data.eof()) {
            if (c == pcode) {
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();
    }

    if (token == 1)
        goto m;
    else {
        data.open("database.txt", ios::app | ios::out);
        data << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close();
    }
    cout << "\n\n\t\t record inserted!! ";
}

void shopping::edit() {
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout << "\n\t\t\t modify the record";
    cout << "\n\t\t\t product code: ";
    cin >> pkey;

    data.open("database.txt", ios::in);
    if (!data) {
        cout << "\n\nFile doesn't exist! ";
    } else {
        data1.open("database1.txt", ios::app | ios::out);

        data >> pcode >> pname >> price >> dis;
        while (!data.eof()) {
            if (pkey == pcode) {
                cout << "\n\t\t product new code: ";
                cin >> c;
                cout << "\n\n\t name of the product: ";
                cin >> n;
                cout << "\n\t\t price: ";
                cin >> p;
                cout << "\n\t\t discount: ";
                cin >> d;
                data1 << " " << c << " " << n << " " << p << " " << d << "\n";
                cout << "\n\t\t\t\t record edited ";
                token++;
            } else {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0) {
            cout << "\n\n record not found sorry!! ";
        }
    }
}

void shopping::rem() {
    fstream data, data1;
    int pkey;
    int token = 0;
    cout << "\n\n\t delete product ";
    cout << "\n\n\t product code : ";
    cin >> pkey;

    data.open("database.txt", ios::in);
    if (!data) {
        cout << "file doesnt exist";
    } else {
        data1.open("database.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof()) {
            if (pcode == pkey) {
                cout << "n\n\t product deleted successfully";
                token++;
            } else {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database.txt", "database.txt");

        if (token == 0) {
            cout << "\n\n record not found";
        }
    }
}

void shopping::list() {
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\n\n|_____________________________________\n";
    cout << "prono\t\tname\t\tprice\n";
    cout << "\n\n|_____________________________________\n";
    data >> pcode >> pname >> price >> dis;
    while (!data.eof()) {
        cout << pcode << "\t\t" << pname << "\t\t" << price << "\n";
        data >> pcode >> pname >> price >> dis;
    }
    data.close();
}

void shopping::receipt() {
    m:
    fstream data;

    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float dis = 0;
    float total = 0;

    cout << "\n\n\t\t\t\t RECEIPT ";
    data.open("database.txt", ios::in);
    if (!data) {
        cout << "\n\n empty database";
    } else {
        data.close();

        list();
        cout << "\n_________________________________\n";
        cout << "\n|                                \n";
        cout << "\n       please place the order    \n";
        cout << "\n|                                \n";
        cout << "\n_________________________________\n";
        do {
            cout << "\n\n enter the product code: ";
            cin >> arrc[c];
            cout << "\n\nenter the product quantity: ";
            cin >> arrq[c];
            for (int i = 0; i < c; i++) {
                if (arrc[c] == arrc[i]) {
                    cout << "\n\n duplicate product code. please try again!";
                    goto m;
                }
            }
            c++;
            cout << "\n\n do you want to buy another product? if yes then press y else no";
            cin >> choice;
        } while (choice == 'y' || choice == 'Y');

        cout << "\n\n\t\t\t________________RECEIPT________________\n";
        cout << "\nproduct no\t product name\t product quantity\tprice\tamount\tamount with discount\n";

        for (int i = 0; i < c; i++) {
            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> dis;
            while (!data.eof()) {
                if (pcode == arrc[i]) {
                    amount = price * arrq[i];
                    dis = amount - (amount * dis / 100);
                    total = total + dis;
                    cout << "\n" << pcode << "\t\t" << pname << "\t\t" << arrq[i] << "\t\t" << price << "\t" << amount << "\t\t" << dis;

                }
                data >> pcode >> pname >> price >> dis;
            }
            data.close();
        }
        cout << "\n_______________________________________________________\n";
        cout << "\n\n\t\t\t\t\ttotal : " << total;
        cout << "\n\n\t\t\t_________________________________________________";
    }
}

int main() {
    shopping s;
    s.menu();
    return 0;
}

