#pragma once
#include <string>
#include "Queue.h"
#include "Lexema.h"

class LexicalAnalysis {
	Queue<Lexema>res;
public:
	void Analysis(string input);
	Queue<Lexema>getResult() { return res; }
	void PrintResult();
};