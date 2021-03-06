#ifndef COMPRESSION_H
#define COMPRESSION_H

#include <string>
#include <bitset>

typedef struct huffmanNode{
    char character = 0;
    unsigned long long frequency = 0;
} huffmanNode;

typedef struct huffmanCode{
    char character = 0;
    std::bitset<256> code;
    int length = -1;
} huffmanCode;

std::string compress(std::string* data);

std::string decompress(std::string* data);

std::string minify(std::string* text);

#endif // COMPRESSION_H
