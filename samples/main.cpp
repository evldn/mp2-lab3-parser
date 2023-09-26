#include "Lexema.h"
#include "LexicalAnalysis.h"
#include "SyntacticAnalysis.h"
#include "Translator.h"
#include "Stack.h"
#include "Queue.h"
#include <string>
#include <iostream>

using namespace std;

//вместо switch можно сделать список(массив) правил
//базовый класс rool, три метода: перейти, чек и действие
//сделать отдельными классами лексический, синтаксический анализы и транслятор


int main() {
	string str = "15 - 13) / 20";
	cout << str << endl;
	LexicalAnalysis lex;
	SyntacticAnalysis sin;
	Translator trans;
	lex.Analysis(str);
	lex.PrintResult();
	cout << endl;
	try {
		sin.Analysis(lex.getResult());
		sin.PrintResult();
		cout << endl;
		trans.Сalculate(sin.getResult());
		cout << trans.getResult();
	}
	catch (AddException& e) {
		e.show();
	}
	return 0;
}