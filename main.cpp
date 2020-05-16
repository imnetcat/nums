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

	input_equation << init;

	int counter = 0;
	operator_ last = "*";
	while (!queue.empty())
	{
		if ((queue.front().first == "/" || queue.front().first == "*") && (last == "-" || last == "+"))
		{
			counter++;
			input_equation << ")";
		}

		input_equation << " " << queue.front().first << " " << queue.front().second;

		last = queue.front().first;

		queue.pop();
	}

	cout << string(counter, '(') << input_equation.str();

	return 0;
}
