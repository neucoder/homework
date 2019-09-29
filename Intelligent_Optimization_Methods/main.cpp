#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include "hw1.h"
using namespace std;


int main() {

    vector<double >v;
    UniformDistribution u01;
    //u01.generateNvalue(v, 80);
    CustomDistribution cd;
    cd.testCDF();

    return 0;
}