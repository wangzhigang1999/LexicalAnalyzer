//
// Created by wangz on 2020/9/30.
//

#include <vector>
#include "FileReader.h"

FileReader::FileReader(const std::string &fileName) : fileName(fileName) {
    this->fileName = fileName;
}

std::vector<char> FileReader::read() {

    std::vector<char> res;

    FILE *file = fopen(fileName.c_str(), "r");

    processComment(file, res);

    return res;
}


/**
 * 处理注释的函数
 * @param file
 * @param res
 */
void FileReader::processComment(FILE *file, std::vector<char> &res) {
    int cur;
    while ((cur = getc(file)) != EOF) {
        if (cur == '\'' || cur == '"') {
            int q = cur;
            do {
                res.push_back(cur);
                // 过滤转义符
                if (cur == '\\') {
                    res.push_back(getc(file));
                }
                cur = getc(file);
            } while (cur != q);
            res.push_back(cur);
        } else if (cur == '/') {
            cur = getc(file);
            if (cur != '*') {
                if (cur == '/') {
                    cur = getc(file);
                    while (cur != '\n') {
                        cur = getc(file);
                    }
                } else {
                    res.push_back('/');
                    ungetc(cur, file);
                }
            } else {
                res.push_back(' ');
                do {
                    cur = getc(file);
                } while (cur != '/' != 0);
            }
        } else {
            if(cur!='\n'){
                res.push_back(cur);
            }
        }
    }
}
