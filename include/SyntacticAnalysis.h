#pragma once
#include "Lexema.h"
#include "Queue.h"
#include "Stack.h"
#include "Exception.h"
#include <string>

class SyntacticAnalysis {
	Queue<Lexema>res;
	map <string, int> priority;
	void CreatePriority() {
		priority[")"] = 0;
		priority["("] = 0;
		priority["+"] = 1;
		priority["-"] = 1;
		priority["*"] = 2;
		priority["/"] = 2;
	}
public:
	void Analysis(Queue<Lexema>lexems);
	Queue<Lexema>getResult() { return res; };
	void PrintResult();
};