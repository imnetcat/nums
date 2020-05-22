#include "cli.h"


int main() {
	string tokens;
	cout << "Enter expression: ";
	getline(cin, tokens);

	int x = 0;
	auto node = Parse(tokens.begin(), tokens.end(), x);

	cout << "Enter x: ";
	while (cin >> x) {
		cout << "Expression value: " << node->Evaluate() << endl;
		cout << "Enter x: ";
	}

	return 0;
}
