#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
#include "solution.h"


class Runner
{
    int t;
    vector<vector<vector<int>>> arr;

public:
    void takeInput()
    {
        cin >> t;
        arr.resize(t);
        for (int c = 0; c < t; c++)
        {
            int n ;

            cin >> n ;
            arr[c].resize(n);
            for (int i = 0; i < n; i++)
            {
                arr[c][i].resize(2);
                for (int j = 0 ; j < 2 ; j++)
                {
                    cin >> arr[c][i][j];
                }
            }

        }
    }

    void execute()
    {
        vector<vector<vector<int>>> arrCopy = arr;

        for (int i = 0; i < t; i++)
        {
            vector<int> ans = countWays(arrCopy[i]);
        }
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            vector<int> ans = countWays(arr[i]);
            for (int i = 0 ; i < ans.size() ; i++)
            {
                cout << ans[i] << " ";
            }
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