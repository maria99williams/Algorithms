/*
    Time Complexity : O(N)
    Space Complexity : O(1)

    Where 'N' is the length of the binary string
*/

string maximumBinaryString(string &bString)
{    
	// Create a variable countZeros to count the total number of 0's in the string
	int countZeros = 0;

	// Create a variable start to find the index of the first leftmost '0' in the given string
	int start  = -1;
    
    // Find the location of the first leftmost '0' in the string 
	for (int i = 0 ; i < bString.length() ; i++) 
	{
		if (bString[i] == '0') 
		{
			start = i;
			break;
		}
	}
    
    // If string contains all 1's then the string is maximum in itself
	if (start == -1) 
	{
		return bString;
	}
    
    // Count the total number of 0's in the string and also side by side fill the string with 1
	for (int i = 0 ; i < bString.length() ; i++) 
	{
		if (bString[i] == '0') 
		{
			countZeros++;
		}

		bString[i] = '1';
	}
    
	// Place the single zero at its correct position
	bString[countZeros + start - 1] = '0';
	
	// Finally return the string
	return bString;
}