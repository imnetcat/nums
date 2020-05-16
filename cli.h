#pragma once
#include <map>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using operator_ = string;
using operand = int;
using operation = pair<operator_, operand>;


int main() {
	int init, commands;
	cin >> init >> commands;

	queue<operation> queue;

	while (commands)
	{
		string operation;
		int value;
		cin >> operation >> value;
		--commands;
	}

	return 0;
}
