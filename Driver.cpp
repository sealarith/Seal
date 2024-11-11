#include <iostream>
#include <unordered_map>
//#include "Wordle.h"
using namespace std;

int main()
{
    /*unordered_map<int, string> umap;
    
    int j = 1;
    while (j <= 10)
    {
        cout << "Enter a value: ";
        cin >> umap[j];
        j++;
    }

    for (int i = 1; i <= 10; i++)
    {
        
        cout << i  << ": "<< umap[i] << endl;
    }*/

    //Wordle a1;
    //a1.getCapacity();
    //a1.insertChar();
    //a1.printArray();
    //a1.insertItem();
    //a1.printTable();

    int attempt = 0;
    string a;
    string ans = "apple";
    int arr[] = {};
    int n = ans.length();
    cout << "Welcome to Wordle" << endl;
    cout << "Please Enter a word and you have 6 trys to win the games" << endl;
    while (attempt < 6)
    {
        cout << "Enter a word: ";
        cin >> a;
        if (a == ans)
        {
            cout << "You win";
            break;
        }
        if (attempt == 5)
        {
            cout << "You lose.";
            break;
        }
        if (a.length() > attempt)
        {
            cout << "Please enter a 5 letters word" << endl;
        }
        for (int i = 0; i < n+1; i++)
        {
            if (a[i] == ans[i])
            {
                arr[attempt] = i;
            }
        }
        for (int i = 0; i < n+1; i++)
        {
            cout << a[arr[i]] << " is correct.\n";
        }
        cout << "Try again." << endl;
        attempt++;
    }
    return 0;
}