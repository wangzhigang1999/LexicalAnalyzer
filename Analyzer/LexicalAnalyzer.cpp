//
// Created by wangz on 2020/9/30.
//

#include "LexicalAnalyzer.h"


LexicalAnalyzer::LexicalAnalyzer(std::vector<char> text) {
    this->text = std::move(text);
}


std::vector<Pair> LexicalAnalyzer::analyzer() {

    std::vector<Pair> res;


    scanner(text, res);


    return res;
}


int LexicalAnalyzer::scanner(std::vector<char> str, std::vector<Pair> &res) {

    int chIndex = 0;

    // 遍历各字符
    while (chIndex < (str).size()) {

        while (str[chIndex] == ' ' || str[chIndex] == '\n' || str[chIndex] == '\t' || str[chIndex] == '\v' ||
               str[chIndex] == '\r') {
            if (chIndex < str.size()) {
                chIndex++;
            }
        }

        // 以字母开头, 可能是标识符, 也可能是保留字
        if (isalpha(str[chIndex])) {
            std::string tmp;
            tmp.push_back(str[chIndex++]);

            while (isdigit(str[chIndex]) || isalpha(str[chIndex])) {
                tmp.push_back(str[chIndex++]);
            }
            // cout << "得到: " << tmp << endl;
            bool isReserve = false;
            // 判断是否是保留字
            for (int i = 0; i < 34; i++) {
                if (tmp == reserveWordTbl[i]) {

                    Pair pair = Pair(1, tmp);

                    res.push_back(pair);

                    isReserve = true;
                    break;
                }
            }
            if (!isReserve) {

                Pair pair = Pair(2, tmp);
                res.push_back(pair);

            }
        } else if (isdigit(str[chIndex])) {   // 遇到数字
            std::string tmp;
            while (isdigit(str[chIndex])) {
                tmp.push_back(str[chIndex++]);
            }

            Pair pair = Pair(3, (tmp));
            res.push_back(pair);

            // cout << "数字: " << tmp << endl;
        } else if (str[chIndex] == '<' || str[chIndex] == '>' || str[chIndex] == '=' || str[chIndex] == '+' ||
                   str[chIndex] == '-' || str[chIndex] == '*' || str[chIndex] == '/' || str[chIndex] == '^') {

            std::string tmp;

            if (str[chIndex] == '<' && str[chIndex + 1] == '=') {
                tmp.push_back(str[chIndex++]);
            } else if (str[chIndex] == '>' && str[chIndex + 1] == '=') {
                tmp.push_back(str[chIndex++]);
            } else {
                tmp.push_back(str[chIndex++]);
            }
            for (int i = 0; i < 10; i++) {
                if ((tmp == operatorTbl[i])) {
                    Pair pair = Pair(4, (tmp));
                    res.push_back(pair);

                    // cout << "运算符" << table[wordIndex].word << endl;
                    break;
                }
            }
        } else if (str[chIndex] == '#' || str[chIndex] == '(' || str[chIndex] == ')' || str[chIndex] == '{' ||
                   str[chIndex] == '}' || str[chIndex] == '[' || str[chIndex] == ']' || str[chIndex] == ',' ||
                   str[chIndex] == ';' || str[chIndex] == '"' || str[chIndex] == '\'') {

            std::string tmp;
            tmp.push_back(str[chIndex++]);

            // cout << "得到界符: " << tmp << endl;
            for (int i = 0; i < 11; i++) {
                if ((tmp == delimiterTbl[i])) {
                    Pair pair = Pair(5, (tmp));
                    res.push_back(pair);
                    // cout << "界符: " << table[wordIndex].word << endl;
                    break;
                }
            }
        } else {
            chIndex++;
        }
    }
    return 0;
}



