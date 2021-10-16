/*
   Time Complexity : O(Q*Log(P) + K + K*Log(Log(K)))
   Space Complexity : O(K)

   Where ‘Q’ is the total number of queries, ‘K’ is equal to 10^4 and ‘P’ is the product that array should have.
*/

#include<unordered_map>

vector<int> countWays(vector<vector<int>> &queries)
{
	// Precompute all values of binomial coefficients(N choose R)
	vector<vector<int>> combination(10015 , vector<int>(15));
	for (int i = 0; i <= 10014; ++i)
	{
		combination[i][0] = 1;
		for (int j = 1; j <= min(i, 14); ++j)
		{
			combination[i][j] = (combination[i - 1][j - 1] + combination[i - 1][j]) % 1000000007;
		}
	}

	// Precomputation of smallest prime factor to every number till 10^4
	int smallPrimeFactor[10001];
	smallPrimeFactor[1] = 1;
	for (int i = 2 ; i < 10001 ; i++)
	{
		smallPrimeFactor[i] = i;
	}
	for (int i = 4 ; i < 10001 ; i += 2)
	{
		smallPrimeFactor[i] = 2;
	}
	for (int i = 3 ; i * i < 10001 ; i += 2)
	{
		if (smallPrimeFactor[i] == i)
		{
			for (int j = i * i ; j < 10001 ; j += i)
			{
				if (smallPrimeFactor[j] == j)
				{
					smallPrimeFactor[j] = i;
				}
			}
		}
	}

	// Create an array ans to store the answer to each query
	vector<int> result(queries.size());

	// Iterate over all queries
	for (int i = 0 ; i < queries.size() ; i++)
	{
		long long int ans = 1;
		int n = queries[i][0];
		int p = queries[i][1];

		// Store the frequency of each prime factor in a hashmap
		unordered_map<int, int> freq;
		while (p != 1)
		{
			freq[smallPrimeFactor[p]] += 1;
			p = p / smallPrimeFactor[p];
		}

		// For each count of distinct prime factor update the ans as per the formulae
		unordered_map<int , int>:: iterator count;
		for (count = freq.begin() ; count != freq.end() ; count++)
		{
			ans = ans * combination[count->second + n - 1][count->second] % 1000000007;
		}

		result[i] = ans;
	}
	return result;
}

