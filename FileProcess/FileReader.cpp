//
// Created by wangz on 2020/9/30.
//

#include "FileReader.h"

FileReader::FileReader(const std::string &fileName) : fileName(fileName) {
    this->fileName = fileName;
}

std::vector<char> FileReader::read() {

    std::vector<char> res;

    // 以只读模式打开文件,没有用C++的输入流,原因见实验报告遇到的问题部分
    FILE *file = fopen(fileName.c_str(), "r");

    // 处理注释
    processComment(file, res);

    fclose(file);

    return res;
}


/**
 * 处理注释的函数, 处理单行注释以及多行注释
 * @param file
 * @param res
 */
void FileReader::processComment(FILE *file, std::vector<char> &res) {
    int chr;
    while ((chr = getc(file)) != EOF) {
        // 遇到了单引号或者双引号,那么就应该匹配之间的所有东西
        if (chr == '\'' || chr == '"') {
            int next = chr;
            do {
                res.push_back(chr);

                // 过滤转义符
                if (chr == '\\') {
                    res.push_back(getc(file));
                }
                chr = getc(file);
            } while (chr != next);
            res.push_back(chr);

        } else if (chr == '/') {
            chr = getc(file);
            if (chr != '*') {
                if (chr == '/') {
                    chr = getc(file);
                    while (chr != '\n') {
                        chr = getc(file);
                    }
                } else {
                    res.push_back('/');
                    ungetc(chr, file);
                }
            } else {
                res.push_back(' ');
                do {
                    chr = getc(file);
                } while (chr != '/' != 0);
            }
        } else {
            if (chr != '\n') {
                res.push_back(chr);
            }
        }
    }
}
