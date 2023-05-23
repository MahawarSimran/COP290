#include <iostream>
#include "helper.h"
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() 
{   string x;
    cin >> x;
    if (x == "sigmoid"){
        sigmoid();
    }
    else{
        softmax();
    }
}
