#include <map>
#include "FileProcess/FileReader.h"
#include "Pair/Pair.h"
#include "FileProcess/FileWriter.h"
#include "Analyzer//LexicalAnalyzer.h"

#define  input "C:\\Users\\wangz\\CLionProjects\\LexicalAnalyzer\\input.cpp"
#define  output "C:\\Users\\wangz\\CLionProjects\\LexicalAnalyzer\\out.txt"


// todo 检查词法错误,并且报告位置
// todo 恢复错误


int line_cn = 0;
int char_cnt = 0;
int something[6] = {0, 0, 0, 0, 0, 0};
std::string help[6] = {"nothing", "chars    ", "keyword  ", "constant ", "operators", "boundary "};


void countLineAndChar(const std::string &filename);

void count(const std::vector<Pair> &vector);

void other(const std::vector<Pair> &res);

int main() {

    // 读取文件
    auto fileReader = FileReader(input);


    // 获取处理注释之后的文件
    std::vector<char> codeWithoutComment = fileReader.read();

    // 进行此法分析
    auto lexicalAnalyzer = LexicalAnalyzer(codeWithoutComment);

    // 获得分析结果
    std::vector<Pair> res = lexicalAnalyzer.analyzer();


    // 常见一个输出文件
    auto fileWriter = FileWriter(output);

    // 将分析结果打印出来
//    FileWriter::printToScreen(res);

    // 将分析结果输出到文件
    fileWriter.write(res);


    //统计一下边边角角并且打印出来
    other(res);


}

void other(const std::vector<Pair> &res) {

    countLineAndChar(input);

    count(res);


    std::cout << "total lines : " << line_cn << " total chars : " << char_cnt << std::endl;

    for (int i = 0; i < 5; ++i) {
        std::cout << i + 1 << " " << help[i + 1] << " " << something[i + 1] << std::endl;
    }
}

void count(const std::vector<Pair> &vector) {
    for (auto &pair : vector) {
        something[pair.type]++;
    }
}

void countLineAndChar(const std::string &filename) {
    char buf[1024];
    std::ifstream infile;
    infile.open(filename);

    if (infile.is_open()) {
        while (infile.good() && !infile.eof()) {
            infile.getline(buf, 1204);
            line_cn++;
        }


        infile.seekg(std::ios_base::beg);

        while (infile.good()) {
            infile.get();
            char_cnt++;
        }

        infile.close();
    }
}
