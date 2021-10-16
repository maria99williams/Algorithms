#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

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

int main()
{
    Runner runner;
    runner.takeInput();
    int execCount = stoi(getenv("EXECUTION_COUNT"));
    if (execCount == 1)
    {
        runner.executeAndPrintOutput();
    }
    else
    {

        ofstream file;
        file.open(getenv("EXEC_COUNTER_FILE"));
        for (int i = 0; i < execCount; i++)
        {
            runner.execute();
            file << i + 1;
            file << "\n";
            file.flush();
        }
        file.close();
    }

    return 0;
}