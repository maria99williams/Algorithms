#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
#include<string>
using namespace std;

#include "solution.h"


class Runner {
    int t ;
    vector<string> arr;

public:
    void takeInput()
    {
        cin >> t;
        arr.resize(t);
        for (int i = 0; i < t; i++)
        {
            string str;
            cin >> str;
            arr[i] = str;
        }
    }

    void execute()
    {
        vector<string>arrCopy = arr;

        for (int i = 0; i < t; i++)
        {
            string ans = maximumBinaryString(arrCopy[i]);
        }
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            string ans = maximumBinaryString(arr[i]);
            cout << ans;
            cout << "\n";
        }
    }
};


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}