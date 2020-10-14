//
// Created by wangz on 2020/9/30.
//

#include "FileWriter.h"

FileWriter::FileWriter(const std::string &fileName) : fileName(fileName) {
    this->fileName = fileName;
}

void FileWriter::printToScreen(std::vector<Pair> vector) {
    for (auto &i : vector) {
        std::cout << i.str() << std::endl;
    }
}

void FileWriter::write(const std::string &str) {
    std::ofstream stream(fileName);

    stream << str;

    stream.close();

}

void FileWriter::write(const std::vector<char>& str) {
    std::ofstream stream(fileName);

    for (char i : str) {
        stream << i;
    }

    stream.close();
}

void FileWriter::write(const std::vector<Pair>& str) {
    std::ofstream stream(fileName);

    for (auto i : str) {
        stream << i.str() << std::endl;
    }

    stream.close();
}


