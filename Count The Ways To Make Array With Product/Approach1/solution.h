/*
   Time Complexity : O(Q*N*P*Sqrt(P))
   Space Complexity : O(Q*N*P)

   Where ‘Q’ is the total number of queries, ‘N’ is the size of the array to build and ‘P’ is the product that array should have.
*/

#include<cmath>

vector<int> countWays(vector<vector<int>> &queries)
{
	// Create an array to store the answer to each query
	vector<int> ans(queries.size());

	// Iterate over all queries
	for (int q = 0 ; q < queries.size() ; q++)
	{
		int n = queries[q][0];
		int p = queries[q][1];

		// Construct a Dp table
		vector<vector<int>> dp(n + 1 , vector<int>(p + 1 , 0));

		// Update the value of row whose product is equal to 1
		for (int i = 1 ; i <= n ; i++)
		{
			dp[i][1] = 1;
		}

		// Update the value of column whose size is equal to 1
		for (int j = 1 ; j <= p ; j++)
		{
			dp[1][j] = 1;
		}

		// Fill the Dp table as per the logic
		for (int i = 2 ; i <= n ; i++)
		{
			for (int j = 2 ; j <= p ; j++)
			{
				for (int f = 1 ; f <= sqrt(j) ; f++)
				{
					if (j % f == 0)
					{
						dp[i][j] = (dp[i][j] + dp[i - 1][j / f]) % 1000000007;
						if (f != j / f)
						{
							dp[i][j] = (dp[i][j] + dp[i - 1][f]) % 1000000007;
						}
					}
				}
			}
		}

		// Insert the answer to the query in the array
		ans[q] = (dp[n][p] % 1000000007);
	}
	return ans;
}
