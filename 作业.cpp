#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <time.h>
#include <cmath>
#include <fstream>

using namespace std;

// ȫ�ֱ���
int problemCount; // ��ʽ����
int maxNumber; // �����
int operandCount; // ���Ӹ���
int operation; // �û�����������
int hasBracket; // �Ƿ�������
int isFloat; // �Ƿ���С��
int outputType; // �����ʽ
char operators[4] = { '+', '-', '*', '/' }; // �����
ofstream outfile; // ����д���ļ�

// ���������
int randNum(int max) {
    return (rand() % max) + 1;
}

// �������������
float randFloat(int max) {
    return (float)rand() / RAND_MAX * max + 1.0;
}

// ���������ڱ��ʽ
void genBracketExpr(bool isFloat, ostream& out) {
    int op = rand() % 4;
    out << "(";
    if (isFloat) {
        out << randFloat(maxNumber) << operators[op];
        out << randFloat(maxNumber) << ")";
    }
    else {
        out << randNum(maxNumber) << operators[op];
        out << randNum(maxNumber) << ")";
    }
}

// ���ɵ�����
void genTerm(bool isFloat, bool hasBracket, int n, ostream& out) {
    if (hasBracket && n > 1 && rand() % 2) {
        genBracketExpr(isFloat, out);
    }
    else {
        if (isFloat) {
            out << randFloat(maxNumber);
        }
        else {
            out << randNum(maxNumber);
        }
    }
}

// ������ʽ
void genExpr(bool isFloat, bool hasBracket, int op, ostream& out) {
    int i = 0;
    genTerm(isFloat, hasBracket, operandCount, out);
    for (i = 1; i < operandCount; i++) {
        if (op == 5) {
            out << operators[rand() % 4];
        }
        else {
            out << operators[op - 1];
        }
        genTerm(isFloat, hasBracket, operandCount - i, out);
    }
    out << "=" << endl;
}

int main() {
    cout << "-----Сѧ������������ϰϵͳ-----" << endl;
    cout << "******************************** " << endl;
    cout << "      1: ��������ʽ����: " << endl;
    cin >> problemCount;
    cout << "      2: �����������: " << endl;
    cin >> maxNumber;
    cout << "      3: ��������������" << endl;
    cin >> operandCount;
    cout << "      4: �����������: " << endl;
    cout << "      1����+ 2����- 3����* 4����/ 5������:" << endl;
    cin >> operation;
    cout << "      5: ��ѡ����������: " << endl;
    cout << "      1�������� 2����С��" << endl;
    cin >> isFloat;
    cout << "      6: ��ѡ���Ƿ���Ҫ���� " << endl;
    cout << "      1������Ҫ���� 2������Ҫ����" << endl;
    cin >> hasBracket;
    cout << "      7: ��ѡ�������ʽ " << endl;
    cout << "      1����������ļ� 2�����ӡ����Ļ" << endl;
    cin >> outputType;

    if (outputType == 1) {
        outfile.open("test.txt");
    }

    srand(time(NULL));
    for (int i = 0; i < problemCount; i++) {
        if (isFloat == 1) {
            genExpr(false, hasBracket == 2, operation, outputType == 1 ? outfile : cout);
        }
        else {
            genExpr(true, hasBracket == 2, operation, outputType == 1 ? outfile : cout);
        }
    }

    if (outputType == 1) {
        outfile.close();
    }

    cout << "******************************** " << endl;
    return 0;
}