#include "LexicalAnalysis.h"

void LexicalAnalysis::Analysis(string input) {
	input += ' ';
	int i = 0;
	int pos = 0;
	string tmp = "";
	string op = "+-*/()";
	string sep = " \n\t";
	int state = 0;
	for (i = 0; i < input.size(); i++) {
		char c = input[i];
		int fres;
		switch (state)
		{
		case 0: // операция
			if (c >= '0' && c <= '9') {
				tmp = c;
				state = 1;
				break;
			}
			fres = op.find(c);
			if (fres >= 0) {
				tmp = c;
				Lexema l(tmp, Operation, pos);
				pos++;
				res.Push(l);
				state = 0;
				break;
			}
			break;
		case 1: // число
			if (c >= '0' && c <= '9') {
				tmp += c;
				state = 1;
				break;
			}
			fres = op.find(c);
			if (fres >= 0) {
				Lexema l1(tmp, Value, pos);
				pos++;
				res.Push(l1);
				tmp = c;
				Lexema l2(tmp, Operation, pos);
				pos++;
				res.Push(l2);
				state = 0;
				break;
			}
			fres = sep.find(c);
			if (fres >= 0) {
				Lexema l(tmp, Value, pos);
				pos++;
				res.Push(l);
				state = 0;
				break;
			}
			break;
		}
	}
}

void LexicalAnalysis::PrintResult() {
	Queue<Lexema>t;
	t = res;
	while (!t.IsEmpty()) {
		cout << t.Top() << endl;
		t.Pop();
	}
}