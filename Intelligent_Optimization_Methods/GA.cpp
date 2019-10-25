//
// Created by ys on 2019/10/20.
//

#include "GA.h"

void Chromosome::clone(Chromosome c) {

    for (int i = 0; i < c.code.size(); ++i) {
        this->code[i] = c.code[i];
    }
}

void Chromosome::mute(double p) {

    for (int i = 0; i < code.size(); ++i) {
        if(distribution(generator) < p)
        {
            code[i] = !code[i];
        }
    }
}

void Chromosome::crossOver(Chromosome c) {


}


double Chromosome::fitness() {

    double res = 0;
    double f[16] = {28,26,24,18,22,6,14,0,20,12,10,2,8,4,6,30};
    auto beg = code.begin();
    auto end = code.end();
    for (; beg < end; beg+4) {
        res += singleFitness(beg, beg+4);
    }
    return res;
}

double Chromosome::singleFitness(vector<bool>::iterator beg, vector<bool>::iterator end) {
    double res = 0;
    int value = 8;
    for (auto i = beg;i!=end;i++)
    {
        if(*i)
        {
            res += value;
        }
        value= value >> 1;
    }

    return res;
}

