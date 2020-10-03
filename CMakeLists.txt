cmake_minimum_required(VERSION 3.17)
project(LexicalAnalyzer)

set(CMAKE_CXX_STANDARD 20)

add_executable(LexicalAnalyzer main.cpp Analyzer/LexicalAnalyzer.cpp Analyzer/LexicalAnalyzer.h FileProcess/FileReader.cpp FileProcess/FileReader.h FileProcess/FileWriter.cpp FileProcess/FileWriter.h Pair/Pair.cpp Pair/Pair.h)