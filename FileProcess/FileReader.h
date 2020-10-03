//
// Created by wangz on 2020/9/30.
//

#ifndef LEXICALANALYZER_FILEREADER_H
#define LEXICALANALYZER_FILEREADER_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

class FileReader {
private:
    std::string fileName;
public:
    explicit FileReader(const std::string &fileName);

    std::vector<char> read();


private:
    static void processComment(FILE *file, std::vector<char> &res);

};


#endif //LEXICALANALYZER_FILEREADER_H
