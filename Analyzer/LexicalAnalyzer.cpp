//
// Created by wangz on 2020/9/30.
//

#include "LexicalAnalyzer.h"


LexicalAnalyzer::LexicalAnalyzer(std::vector<char> text) {
    this->text = std::move(text);
}


std::vector<Pair> LexicalAnalyzer::analyzer() {

    std::vector<Pair> res;


    analyze(text, res);


    return res;
}


int LexicalAnalyzer::analyze(std::vector<char> str, std::vector<Pair> &res) {

    int chIndex = 0;


    // 遍历各字符
    while (chIndex < str.size()) {

        // 跳过一些无意义的东西,空格回车之类的
        while (str[chIndex] == ' ' || str[chIndex] == '\n' || str[chIndex] == '\t'
               || str[chIndex] == '\v' || str[chIndex] == '\r') {
            if (chIndex < str.size()) {
                chIndex++;
            }
        }

        // 以字母开头, 可能是标识符, 也可能是保留字
        if (isalpha(str[chIndex])) {

            std::string cur;

            cur.push_back(str[chIndex++]);

            while (isdigit(str[chIndex]) || isalpha(str[chIndex])|| str[chIndex] == '.') {
                cur.push_back(str[chIndex++]);
            }

            bool isReserve = false;
            // 判断是否是保留字
            for (auto &i : keywordTable) {
                if (cur == i) {
                    res.emplace_back(keyword, cur);
                    isReserve = true;
                    break;
                }
            }
            if (!isReserve) {
                res.emplace_back(chars, cur);
            }

        } else if (isdigit(str[chIndex])) {   // 遇到数字
            std::string cur;

            while (isdigit(str[chIndex])) {
                cur.push_back(str[chIndex++]);
            }

            res.emplace_back(constant, (cur));

        } else if (str[chIndex] == '<' || str[chIndex] == '>' || str[chIndex] == '=' || str[chIndex] == '+' ||
                   str[chIndex] == '-' || str[chIndex] == '*' || str[chIndex] == '/' || str[chIndex] == '^') {

            std::string cur;
            cur.push_back(str[chIndex]);

            cur.push_back(str[++chIndex]);


            bool isOperator = false;

            for (auto &i : operatorTable) {
                if ((cur == i)) {
                    res.emplace_back(operators, (cur));
                    isOperator = true;
                    break;
                }
            }
            if (!isOperator) {
                chIndex--;
                cur.pop_back();
                res.emplace_back(operators, (cur));
            }
            chIndex++;

        } else if (str[chIndex] == '#' || str[chIndex] == '(' || str[chIndex] == ')' || str[chIndex] == '{' ||
                   str[chIndex] == '}' || str[chIndex] == '[' || str[chIndex] == ']' || str[chIndex] == ',' ||
                   str[chIndex] == ';' || str[chIndex] == '"' || str[chIndex] == '\'') {

            std::string cur;
            cur.push_back(str[chIndex]);

            res.emplace_back(boundary, cur);

            // 当第一次遇到一个界符的时候,如果这个界符是一个单引号或者双引号,从这个符号开始直到下一个匹配的引号之间的内容都是一个字符串里的东西

            std::string string;
            if (str[chIndex] == '\'') {
                while (str[++chIndex] != '\'') {
                    string.push_back(string[chIndex]);
                }
                res.emplace_back(2, string);

                std::string delimiter;
                delimiter.push_back(str[chIndex]);
                res.emplace_back(5, delimiter);


            } else if (str[chIndex] == '\"') {
                while (str[++chIndex] != '\"') {
                    string.push_back(str[chIndex]);
                }
                res.emplace_back(2, string);

                std::string delimiter;
                delimiter.push_back(str[chIndex]);
                res.emplace_back(5, delimiter);

            }

            chIndex++;

        } else {
            chIndex++;
        }
    }
    return 0;
}



