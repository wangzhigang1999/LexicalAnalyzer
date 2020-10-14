//
// Created by wangz on 2020/9/30.
//

#include "Pair.h"

Pair::Pair(int type, std::string &content) : type(type), content(content) {
    this->content = content;
    this->type = type;
}


std::string Pair::str() {
    std::string res;
    switch (type) {
        case keyword:
            res.push_back('<');
            res.append("keyword  ");
            res.push_back(',');
            res.append(content);
            res.push_back('>');
            break;
        case chars:
            res.push_back('<');
            res.append("string   ");
            res.push_back(',');
            res.append(content);
            res.push_back('>');
            break;
        case boundary:
            res.push_back('<');
            res.append("boundary ");
            res.push_back(',');
            res.append(content);
            res.push_back('>');
            break;
        case constant:
            res.push_back('<');
            res.append("constant ");
            res.push_back(',');
            res.append(content);
            res.push_back('>');
            break;

        case operators:
            res.push_back('<');
            res.append("operators ");
            res.push_back(',');
            res.append(content);
            res.push_back('>');
            break;

    }
    return res;

}
