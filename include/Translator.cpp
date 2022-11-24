#include "Translator.h"

void Translator::Ñalculate(Queue<Lexema>pz) {
	Stack<double>locals;
	Lexema t;
	double first, second;
	int pos = 0;
	while (!pz.IsEmpty()) {
		t = pz.Top();
		pz.Pop();
		if (t.getType() == Value) {
			locals.Push(atof(t.getStr().c_str()));
		}
		else if (t.getType() == Operation) {
			if (!locals.IsEmpty()) {
				second = locals.Top();
				locals.Pop();
				if (!locals.IsEmpty()) {
					first = locals.Top();
					locals.Pop();
				}
				else {
					throw NoOperands(second);
				}
			}
			if (t.getStr() == "+") {
				locals.Push(first + second);
			}
			if (t.getStr() == "-") {
				locals.Push(first - second);
			}
			if (t.getStr() == "/") {
				locals.Push(first / second);
			}
			if (t.getStr() == "*") {
				locals.Push((first) * (second));
			}
		}
	}
	res = locals.Top();
}