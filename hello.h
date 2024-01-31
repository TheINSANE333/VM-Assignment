#ifndef HELLO_H_INCLUDED
#define HELLO_H_INCLUDED

#pragma once

#include <iostream>
#include <vector>

class GetRsrcRdst  //for rsrc & rdst splitting
{
public:
    std::string rsrc, rdst;
};

class rorRol  //for bin & dec conversion in shift and rotate
{
public:
    unsigned int binary[8];
    unsigned int temp[8];
    unsigned int decimal;
};

void in(std::string, int*, unsigned int*);

void out(std::string, int*, unsigned int*);

void mov(int*, int*, std::string, std::string, unsigned int*);

void add(int*, std::string, std::string, unsigned int*);

void sub(int*, std::string, std::string, unsigned int*);

void mul(int*, std::string, std::string, unsigned int*);

void div(int*, std::string, std::string, unsigned int*);

void inc(int*, char, unsigned int*);

void dec(int*, char, unsigned int*);

void store(int*, int*, char, std::string, unsigned int*);

void load(int*, int*, char, std::string, unsigned int*);

rorRol ror(int*, unsigned char, std::string);

rorRol rol(int*, unsigned char, std::string);

rorRol shr(int*, unsigned char, std::string);

rorRol shl(int*, unsigned char, std::string);

rorRol decToBin(int);

rorRol binToDec();

void drawTable(std::string, int*, int*, unsigned int*, unsigned int);

void drawTableLite(std::string, int*, int*, unsigned int*, unsigned int);

void outputfile(char const*, int*, int*, unsigned int*, unsigned int);

std::vector<std::string> universalSplit (std::string, char);

GetRsrcRdst rsrcRdst(std::string);

#endif // HELLO_H_INCLUDED
