//Combination Sum IV Problem...

// i/p: {1,2,5}
//target = 5

int solve(vector<int> &num, int tar) {
	//Base case
	
	if( tar < 0) 
	return 0;
	
	if( tar == 0)
	return 1;
	
	int ans = 0;
	for(int i=0; i<num.size(); i++) {
		ans += solve(num, tar - num[i]);
	}
	return ans;
}

int findWays(vector<int> &num, int tar)
{
	return solve(num, tar);
}

//Using Memoization...



int solveMem(vector<int> &num, int tar, vector<int>& dp) {
	//Base case
	
	if( tar < 0) 
	return 0;
	
	if( tar == 0)
	return 1;
	
	if(dp[tar] != -1) {
		return dp[tar];
	}
	
	int ans = 0;
	for(int i=0; i<num.size(); i++) {
		ans += solveMem(num, tar - num[i], dp);
	}
	
	
	dp[tar] = ans; 
	return dp[tar];
}

int findWays(vector<int> &num, int tar)
{
	//return solve(num, tar);
	
	vector<int> dp(tar+1, -1);
	return solveMem(num,tar, dp);
}

//Using Tabulation...

int solveTab(vector<int>& num, int tar) {
	vector<int> dp(tar+1, 0);
	dp[0] = 1;
	
	//traversing from target 1 to tar
	for(int i=1; i<=tar; i++) {
		//traversing on num vector
		for(int j=0; j<num.size(); j++) {
			if(i-num[j] >= 0)
			dp[i] += dp[i-num[j]];
		}
	}
	return dp[tar];
}

int findWays(vector<int> &num, int tar)
{
	return solveTab(num, tar);
}
