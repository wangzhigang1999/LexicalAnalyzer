#include "FileProcess/FileReader.h"
#include "Pair/Pair.h"
#include "FileProcess/FileWriter.h"
#include "Analyzer//LexicalAnalyzer.h"

#define  input "C:\\Users\\wangz\\CLionProjects\\LexicalAnalyzer\\input.txt"
#define  output "C:\\Users\\wangz\\CLionProjects\\LexicalAnalyzer\\out.txt"

int main() {
    auto fileReader = FileReader(input);

    auto codeWithoutComment = fileReader.read();

    auto lexicalAnalyzer = LexicalAnalyzer(codeWithoutComment);

    std::vector<Pair> res = lexicalAnalyzer.analyzer();

    auto fileWriter = FileWriter(output);

    FileWriter::printToScreen(res);

    fileWriter.write(res);
}