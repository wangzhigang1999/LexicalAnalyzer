//
// Created by wangz on 2020/9/30.
//

#include "Pair.h"

Pair::Pair(int type, std::string &content) : type(type), content(content) {
    this->content = content;
    this->type = type;
}

std::ostream &operator<<(std::ostream &os, const Pair &pair) {
    os << "Type: " << pair.type << " content: " << pair.content;
    return os;
}

std::string Pair::str() {
    return "<" + std::to_string(type) + "," + content + ">";
}
