#include "Lexema.h"
#include "LexicalAnalysis.h"
#include "SyntacticAnalysis.h"
#include "Translator.h"
#include "Stack.h"
#include "Queue.h"
#include <string>
#include <iostream>

using namespace std;

//������ switch ����� ������� ������(������) ������
//������� ����� rool, ��� ������: �������, ��� � ��������
//������� ���������� �������� �����������, �������������� ������� � ����������


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
		trans.�alculate(sin.getResult());
		cout << trans.getResult();
	}
	catch (AddException& e) {
		e.show();
	}
	return 0;
}