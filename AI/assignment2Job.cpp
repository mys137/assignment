#include<bits/stdc++.h>
using namespace std;

class job
{
	public:
		int jobid;
		int deadline;
		int profit;
};

bool mycompare(job *x,job *y)
{
	
	return x->profit>y->profit; 
}

int maxProfit(job** obj,int n){
	int max=0,profit=0;;

	for(int i=0;i<n;i++){
		if(i==0){
			max=obj[i]->deadline;
		}
		else{
			if(obj[i]->deadline>max)
				max=obj[i]->deadline;
		}
	}
	
	sort(obj,obj+n,mycompare);
	
	int store[max]={0};
	bool slot[max]={false}; 
	for(int i=0;i<n;i++)
	{	
		for(int j=(obj[i]->deadline)-1;j>=0;j--)
		{
			if(slot[j]==false)
			{	
				profit+=obj[i]->profit;
				store[j]=obj[i]->jobid;
				slot[j]=true;
				break;
			}
		}
	}
	cout<<"jobs sequence is:"<<"\t";
	for(int i=0;i<max;i++)
	{	
		if(slot[i])
			cout<<store[i]<<"  ";
	}
	return profit;
}

int main()
{	
	int n,size,max,totalprofit=0;
	cout<<"enter the no. of jobs:";
	cin>>n;
	job *obj[n]; 
	for(int i=0;i<n;i++)
	{	
		obj[i]=(job*)malloc(sizeof(struct job));
		cout<<"enter jobid,deadline and profit of job "<<i+1<<endl;

		cin>>obj[i]->jobid;
		cin>>obj[i]->deadline;
		cin>>obj[i]->profit;
	}

	totalprofit=maxProfit(obj,n); 
	cout<<"\ntotal profit is "<<totalprofit<<"\n";
	
	return 0;	
}
