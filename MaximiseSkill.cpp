#include<bits/stdc++.h>
using namespace std;

int maxSkill = INT_MIN;

void maximiseSkill(int index,int totalTime, int slots, int currSkills, int currTime, vector<int> &time, vector<int> &skill){

	if(currTime > totalTime){
		return;
	}
	if(slots == 0 ){
		maxSkill = max(maxSkill,currSkills);
		return;
	}

	for(int i=index;i<skill.size();i++)
	{
		maximiseSkill(i+1,totalTime,slots-1,currSkills+skill[i],currTime+time[i], time, skill);
	}

}

int dp[100][100][100];
int findMaxSkill(int index,int currTime, int currSkills, int totalTime, int slots, vector<int> &time, vector<int> &skill)
{

	if(currTime > totalTime){
		return dp[index][currTime][slots] = INT_MIN;
	}

	if(index==skill.size())
	{
		if(slots==0)
		{
			return dp[index][currTime][slots] = currSkills;
		}
		return dp[index][currTime][slots] = INT_MIN;
	}

	if(dp[index][currTime][slots]!=-1){
		return dp[index][currTime][slots];
	}


	int take = findMaxSkill(index+1,currTime+time[index],currSkills+skill[index],totalTime,slots-1,time,skill);
	int notTake = findMaxSkill(index+1,currTime,currSkills,totalTime,slots,time,skill);

	return dp[index][currTime][slots] = max(take,notTake);

}

int main()
{
	int n,totalTime,slots;
	cin>>n>>totalTime>>slots;
	vector<int> time(n);
	vector<int> skill(n);

	for(int i=0;i<n;i++)
	{
		cin>>time[i];
	}

	for(int i=0;i<n;i++)
	{
		cin>>skill[i];
	}

	memset(dp,-1,sizeof dp);


	maximiseSkill(0,totalTime,slots,0,0,time,skill);
	cout<<maxSkill<<"\n";
	cout<<findMaxSkill(0,0,0,totalTime,slots,time,skill);


}