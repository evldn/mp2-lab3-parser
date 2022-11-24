#include "SyntacticAnalysis.h"
#include <iostream>
using namespace std;

void SyntacticAnalysis::Analysis(Queue<Lexema>lexems) {
	Stack<Lexema>tmp;
	Lexema l;
	CreatePriority();
	while (!lexems.IsEmpty()) {
		l = lexems.Top();
		lexems.Pop();
		if (l.getType() == Value) {
			res.Push(l);
		}
		else if (l.getType() == Operation) {
			if (l.getStr() == "(") {
				tmp.Push(l);
			}
			else if (l.getStr() == ")") {
				while (!tmp.IsEmpty() && tmp.Top().getStr() != "(") {
					res.Push(tmp.Top());
					tmp.Pop();
				}
				if (!tmp.IsEmpty())
					tmp.Pop();
				else {
					throw NoParenthesis(l);
				}
			}
			else {
				if (tmp.IsEmpty()) {
					tmp.Push(l);
				}
				else if (!tmp.IsEmpty() && priority[tmp.Top().getStr()] < priority[l.getStr()]) {
					tmp.Push(l);
				}
				else if (!tmp.IsEmpty() && priority[tmp.Top().getStr()] >= priority[l.getStr()]) {
					while (!tmp.IsEmpty() && priority[tmp.Top().getStr()] >= priority[l.getStr()]) {
						res.Push(tmp.Top());
						tmp.Pop();
					}
					tmp.Push(l);
				}
			}
		}
	}
	while (!tmp.IsEmpty()) {
		res.Push(tmp.Top());
		if (tmp.Top().getStr() == "(") {
			throw NoParenthesis(tmp.Top());
		}
		tmp.Pop();
	}
}

void SyntacticAnalysis::PrintResult() {
	Queue<Lexema>t;
	t = res;
	while (!t.IsEmpty()) {
		cout << t.Top() << endl;
		t.Pop();
	}
}