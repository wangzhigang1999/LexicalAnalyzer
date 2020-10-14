//
// Created by wangz on 2020/9/30.
//

#ifndef LEXICALANALYZER_PAIR_H
#define LEXICALANALYZER_PAIR_H

#include <string>
#include <ostream>


#define chars 1
#define keyword 2
#define constant 3
#define operators 4
#define boundary 5


class Pair {
public:
    int type;
    std::string content;
public:
    Pair(int type, std::string &content);

    std::string str();

};


#endif //LEXICALANALYZER_PAIR_H
