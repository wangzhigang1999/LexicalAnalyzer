//
// Created by wangz on 2020/9/30.
//

#ifndef LEXICALANALYZER_PAIR_H
#define LEXICALANALYZER_PAIR_H

#include <string>
#include <ostream>

class Pair {
    int type;
    std::string content;
public:
    Pair(int type,  std::string &content);

    std::string str();

    friend std::ostream &operator<<(std::ostream &os, const Pair &pair);
};


#endif //LEXICALANALYZER_PAIR_H
