#include"library.h"
#include<iostream>
#include "/opt/intel/mkl/include/mkl.h"
#include <fstream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

string label_to_name(int label)
{
    if(label == 0) return "silence";
    if(label == 1) return "unknown";
    if(label == 2) return "yes";
    if(label == 3) return "no";
    if(label == 4) return "up";
    if(label == 5) return "down";
    if(label == 6) return "left";
    if(label == 7) return "right";
    if(label == 8) return "on";
    if(label == 9) return "off";
    if(label == 10) return "stop";
    if(label == 11) return "go";
    return "no label";
}

int main(int argc, char const *argv[])
{
 
    pred_t* pred;
    pred = (pred_t *)malloc(3*sizeof(pred_t));
    pred = libaudioAPI(argv[1], pred);
    ofstream output_file;
    output_file.open(argv[2],std::ios_base::app); 
    output_file<<argv[1]<< "\t" <<label_to_name(pred[0].label)<<"\t";
    output_file<<label_to_name(pred[1].label)<<"\t";
    output_file<<label_to_name(pred[2].label)<<"\t";
    output_file<<pred[0].prob<<"\t";
    output_file<<pred[1].prob<<"\t";
    output_file<<pred[2].prob<<"\n";
    output_file.close();  
}
