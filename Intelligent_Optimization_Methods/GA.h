//
// Created by ys on 2019/10/20.
//

#ifndef HELLOWORLD_GA_H
#define HELLOWORLD_GA_H

#include <iostream>
#include <vector>
#include <random>

using byte = unsigned char;
using std::vector;

class Chromosome {
public:
    Chromosome(int length) : distribution(0.0,1.0){
        //初始化基因
        this->length = length;
        code.reserve(this->length);

        for (int i = 0; i < code.size(); ++i) {
            if (distribution(generator) < 0.5) {
                code[i] = 0;
            } else {
                code[i] = 1;
            }
        }

    }

    double singleFitness(vector<bool>::iterator beg, vector<bool>::iterator end);

    void clone(Chromosome c);

    void mute(double p);

    void crossOver(Chromosome c);

    double fitness();

    void decode(int len, vector<int> &v) {
        int n = code.size() / len;

    }

private:
    vector<bool> code;
    int length;
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution;
};


class GA {

};


#endif //HELLOWORLD_GA_H
