#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
using namespace std;

int highest(vector<int> &values){
	vector<int>::iterator current = values.begin();
	int high = *current++;

	while (current != values.end())
	{
		cout << "value " << *current << endl;
		if (*current > high)
		{
			high = *current;
		}
		current++;
	}
	return high;
}

int main(){
	{
		vector<int> values;
		values.push_back(10);
		values.push_back(1);
		values.push_back(20);
		values.push_back(30);
		values.push_back(-11);
		vector<int> values2;
		values2=values;
		int high = highest(values2);
		//sort(values.begin(),values.end());
		cout << "Highest: " << high << endl;
	}
	{
		list<int> values;
		values.push_back(10);
		values.push_back(1);
		values.push_back(20);
		values.push_back(30);
		values.push_back(-11);
		int high = highest(values);
		//sort(values.begin(),values.end());
		cout << "Highest: " << high << endl;
	}
	{
		queue<int> values;
		values.push(10);
		values.push(1);
		values.push(20);
		values.push(30);
		values.push(-11);

		cout << values.front() << endl;
		values.pop();
		cout << values.front() << endl;
		values.pop();
		cout << values.front() << endl;
		values.pop();
	}
}
