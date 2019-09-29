//
// Created by ys on 2019/9/27.
//

#ifndef HELLOWORLD_HW1_H
#define HELLOWORLD_HW1_H

#include <iostream>
#include <vector>

using std::vector;



class UniformDistribution
{
public:

    double next();
    void generateNvalue(vector<double> &v, int n);
    void setPara(int A, int C, int M, int Sk);
    double CDF(double x, int N);
    void testCDF();

private:

    int M = 1 << 20;
    int A = 17;
    int C = 97;
    int S_k =  1;
};


class CustomDistribution
{
public:
    //生成n个随机数组
    void generateNvalue(vector<double> &v, int n);

    //每次生成一个随机数
    double next();
    //随机数的分布函数
    double CDF(double x, int N = 10000);
    //测试随机数的分布函数
    void testCDF();

private:
    UniformDistribution U01;
};


class hw1 {

};


#endif //HELLOWORLD_HW1_H
