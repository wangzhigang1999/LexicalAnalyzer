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


//关键字 2
static std::string keywordTable[] = {
        "break", "case", "char", "const", "continue",
        "default", "do", "double", "else", "enum", "extern",
        "float", "for", "goto", "if", "int", "long",
        "return", "short", "signed", "sizeof", "static",
        "struct", "switch", "typedef", "union", "unsigned", "void",
        "while", "define"
};

// 常数3

//operator表, 4
static std::string operatorTable[] = {
        "<", "<=", ">", ">=", "=", "+", "-", "*", "/", "^", "++", "+=", "-=", "==", "^=", "|=", "&="
};

// 界符  5
static std::string delimiterTable[] = {
        "#", "(", ")", "{", "}", ";",
        "[", "]", ",", ";", "\"", "'"
};


class LexicalAnalyzer {

    std::vector<char> text;

public:
    explicit LexicalAnalyzer(std::vector<char> text);

    std::vector<Pair> analyzer();


    static int analyze(std::vector<char> str, std::vector<Pair> &res);
};


#endif //LEXICALANALYZER_LEXICALANALYZER_H
