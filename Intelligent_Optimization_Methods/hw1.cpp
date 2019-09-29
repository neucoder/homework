//
// Created by ys on 2019/9/27.
//

#include "hw1.h"
#include <iostream>
#include <cmath>
#include <algorithm>
using std::cout;
using std::endl;

double UniformDistribution::next() {
    int S_k1 = (A * S_k + C) % M;

    double res = 1.0 * S_k / M;
    S_k = S_k1;
    return res;
}

void UniformDistribution::generateNvalue(vector<double> &v, int n) {

    v.reserve(n);
    for (int i = 0; i < n; ++i) {
        v.push_back(next());
    }

}

void UniformDistribution::setPara(int A, int C, int M, int sk) {

    this->A = A;
    this->C = C;
    this->M = M;
    this->S_k = sk;

}

void UniformDistribution::testCDF() {
    for (int i = 0; i <= 10; ++i) {
        cout << CDF(0+0.1*i, 10000) << endl;
    }
}

double UniformDistribution::CDF(double x, int N) {

    UniformDistribution cd;
    int count = 0;
    for (int i = 0; i < N; ++i) {
        if(cd.next() < x)
        {
            count ++;
        }
    }
    double res = 1.0*count/N;
    return res;
}

void CustomDistribution::generateNvalue(vector<double> &v, int n) {
    v.reserve(n);
    for (int i = 0; i < n; ++i) {
        v.push_back(next());
    }
}

double CustomDistribution::next() {

    double res = 4.0 * sqrt(U01.next()) + 2;
    return res;
}

void CustomDistribution::testCDF() {
    for (int i = 0; i <= 40; ++i) {
        cout << CDF(2+0.1*i, 10000) << endl;
    }

}

double CustomDistribution::CDF(double x, int N) {
    CustomDistribution cd;
    int count = 0;
    for (int i = 0; i < N; ++i) {
        if(cd.next() < x)
        {
            count ++;
        }
    }
    double res = 1.0*count/N;
    return res;
}


