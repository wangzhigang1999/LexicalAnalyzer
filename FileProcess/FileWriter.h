//
// Created by wangz on 2020/9/30.
//

#ifndef LEXICALANALYZER_FILEWRITER_H
#define LEXICALANALYZER_FILEWRITER_H
#include <string>
#include <vector>
#include "../Pair/Pair.h"

class FileWriter {
private:
    std::string fileName;
public:
    explicit FileWriter(const std::string &fileName);

    static void printToScreen(std::vector<Pair> vector);

    void write(const std::string& str);

    void write(const std::vector<char>& str);

    void write(const std::vector<Pair>& str);

};


#endif //LEXICALANALYZER_FILEWRITER_H
