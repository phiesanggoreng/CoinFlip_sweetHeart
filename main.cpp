/*
Dalam permainan seru yang dikenal sebagai "Coin Flip Sweet Heart," 
keseruan terletak pada menebak hasil lemparan koin yang acak.
Apakah koin akan jatuh dengan sisi gambar, ataukah dengan sisi angka ?
Keberuntungan pemain ditentukan oleh lemparan koin
*/

#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include <random>

using namespace std;

const int MaxLives = 3;
const int LoadingBarDuration = 10; // detik
const int LoadingBarWidth = 50;    //widht loading bar nya cuy

void menu()
{
    system("cls");
    cout << "SELAMAT DATANG DI COINFLIP SWEET HEART\n";
    cout << "1. Start" << endl;
    cout << "2. Settings" << endl;
    cout << "3. Exit" << endl;
}

void startGame()
{
    int poin = 0;
    int nyawa = MaxLives;

    while (nyawa > 0)
    {
         
        cout << "Tebak sisi koin (kepala/ekor): ";
        string tebakan;
        cin >> tebakan;

        random_device rd;
        mt19937 random(rd());
        uniform_int_distribution<int> coin(0, 1);
        int sisi_koin = coin(random);

        if (tebakan == "kepala" && sisi_koin == 0)
        {
            poin++;
            cout << "Tebakan Anda benar! Poin Anda sekarang " << poin << endl;
        }
        else if (tebakan == "ekor" && sisi_koin == 1)
        {
            poin++;
            cout << "Tebakan Anda benar! Poin Anda sekarang " << poin << endl;
        }
        else
        {
            nyawa--;
            cout << "Tebakan Anda salah! Nyawa Anda sekarang " << nyawa << endl;
        }

        if (nyawa == 0)
        {
            cout << "Game over! Anda kalah." << endl;
            break;
        }
    }

    cout << "Skor akhir Anda: " << poin << endl;
    cin.ignore();
    cin.get();
}

void settings()
{
    system("cls"); 
    cout << "Changing the settings..." << endl;
    cout << "ganti warna ungu" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
    
    cin.ignore();
    cin.get();
}

void exitProgram()
{
    system("cls"); 
    cout << "Exiting the program..." << endl;
    cin.ignore();
    cin.get();
}

void loading_bar(int num, int width)
{
    string str = "";
    int val = (int)((double)num / 100.0 * width);
    for (int i = 0; i < val; i++)
    {
        str += "|";
    }
    cout << "\r[" << str << "] " << num << "%" << flush;
}



int main()
{
    vector<string> options = { "Start", "Settings", "Exit" };
    int choice;
    
    do
    {
        menu();
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= options.size())
        {
            cout << options[choice - 1] << "..." << endl;

            if (choice == 1)
            {
                for (int i = 0; i <= 100; i++)
                {
                    loading_bar(i, LoadingBarWidth);
                    Sleep(LoadingBarDuration * 1000 / 100);
                    system("cls");
                }
                cout << endl;
                startGame(); 
            }
            else if (choice == 2)
            {
                
                settings();
                
            }
        }
        else
        {
            cout << "Please enter a choice between 1 and 3" << endl;
        }
    } while (choice != 3);

    return 0;
}
