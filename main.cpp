#include "cli.h"


int main() {
	int init, commands;
	cin >> init >> commands;
	
	queue<operation> queue;

	while (commands)
	{
		operator_ op;
		operand value;
		cin >> op >> value;
		queue.push({ op , value });

		--commands;
	}

	stringstream input_equation;

	input_equation << string(queue.size(), '(') << init << ")";

	while (!queue.empty())
	{
		input_equation << " " << queue.back().first <<  " " << queue.back().second << ")";
		queue.pop();
	}
	cout << input_equation.str();

	return 0;
}
