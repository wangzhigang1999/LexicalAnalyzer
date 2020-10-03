//
// Created by wangz on 2020/9/30.
//

#ifndef LEXICALANALYZER_LEXICALANALYZER_H
#define LEXICALANALYZER_LEXICALANALYZER_H

#include <string>
#include <vector>

#include <utility>
#include <iostream>

#include "../Pair/Pair.h"


//全局变量, 保留字表
static char reserveWordTbl[34][20] = {
        "auto", "break", "case", "char", "const", "continue",
        "default", "do", "double", "else", "enum", "extern",
        "float", "for", "goto", "if", "int", "long",
        "register", "return", "short", "signed", "sizeof", "static",
        "struct", "switch", "typedef", "union", "unsigned", "void",
        "volatile", "while", "printf", "define"
};

// 界符
static char delimiterTbl[12][3]={
        "#", "(", ")", "{", "}", ";",
        "[", "]", ",", ";", '"', '\''
};

//运算符表, 根据需要可以自行增加
static char operatorTbl[10][4]={
        "<", "<=", ">", ">=", "=", "+", "-", "*", "/", "^"
};

class LexicalAnalyzer {

    std::vector<char> text;

    int pointer = 0;

public:
    explicit LexicalAnalyzer(std::vector<char> text);

    std::vector<Pair> analyzer();


    int scanner(std::vector<char> str, std::vector<Pair> &res);
};


#endif //LEXICALANALYZER_LEXICALANALYZER_H
