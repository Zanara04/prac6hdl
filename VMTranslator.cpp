#include <string>
#include <iostream>
#include <sstream>

#include "VMTranslator.h"

using namespace std;

int counter = 0;

/** Generate Hack Assembly code for a VM push operation assessed in Practical Assignment 6 */
string VMTranslator::vm_push(string segment, int offset){
    stringstream hack;
    hack.str(string());
    string index = to_string(offset);
    string seg; 
    int activate = 0;

    //seeing which segment, and thus, which call needed
    if(segment == "static"){
        seg = "16";
        activate = 1;
    } else if(segment == "temp"){
        seg = "5";
        activate = 1;
    } else if(segment == "pointer"){
        if(offset == 0){
            seg = "THIS";
        } else {
            seg = "THAT";
        }
        activate = 1;
    } else if(segment == "local"){
        seg = "LCL";
        activate = 1;
    } else if(segment == "argument"){
        seg = "ARG";
        activate = 1;
    } else if(segment == "this"){
        seg = "THIS";
        activate = 1;
    } else if(segment == "that"){
        seg = "THAT";
        activate = 1;
    }

    //constant
    if(segment == "constant"){
        hack << "@" << index << "\n";
        hack << "D=A" << "\n";
        hack << "@SP" << "\n";
        hack << "A=M" << "\n";
        hack << "M=D" << "\n";
        hack << "@SP" << "\n";
        hack << "M=M+1" << "\n";
    } else if (segment == "static" || segment == "temp"){ //static and temp
        hack << "@" << seg << "\n";
        hack << "D=A" << "\n";
        hack << "@" << index << "\n";
        hack << "A=A+D" << "\n";
        hack << "D=M" << "\n";
        hack << "@SP" << "\n";
        hack << "A=M" << "\n";
        hack << "M=D" << "\n";
        hack << "@SP" << "\n";
        hack << "M=M+1" << "\n";
    }else if (segment == "pointer"){ //pointer
        hack << "@" << seg << "\n";
        hack << "D=M" << "\n";
        hack << "@SP" << "\n";
        hack << "A=M" << "\n";
        hack << "M=D" << "\n";
        hack << "@SP" << "\n";
        hack << "M=M+1" << "\n";
    } else if (activate == 1){ //not constant
        hack << "@" << seg << "\n";
        hack << "D=M" << "\n";
        hack << "@" << index << "\n";
        hack << "A=A+D" << "\n";
        hack << "D=M" << "\n";
        hack << "@SP" << "\n";
        hack << "A=M" << "\n";
        hack << "M=D" << "\n";
        hack << "@SP" << "\n";
        hack << "M=M+1" << "\n";
    } else {
        return "";
    }

    return hack.str() + "\n";
}

/** Generate Hack Assembly code for a VM pop operation assessed in Practical Assignment 6 */
string VMTranslator::vm_pop(string segment, int offset){  
    stringstream hack;
    hack.str(string());
    string index = to_string(offset);
    string seg; 
    int activate = 0;

    //seeing which segment, and thus, which call needed
    if(segment == "temp"){
        seg = "5";
        activate = 1;
    } else if(segment == "pointer"){
        if(offset == 0){
            seg = "THIS";
        } else {
            seg = "THAT";
        }
        activate = 1;
    } else if(segment == "local"){
        seg = "LCL";
        activate = 1;
    } else if(segment == "argument"){
        seg = "ARG";
        activate = 1;
    } else if(segment == "this"){
        seg = "THIS";
        activate = 1;
    } else if(segment == "that"){
        seg = "THAT";
        activate = 1;
    }

    //constant
    if(segment == "constant"){
        return "constant is not a segment that can be popped";
    } else if (segment == "static"){ //static
        hack << "@" << index << "\n";
        hack << "D=A" << "\n";
        hack << "@16" << "\n";
        hack << "D=A+D" << "\n";
        hack << "@13" << "\n";
        hack << "M=D" << "\n";
        hack << "@SP" << "\n";
        hack << "AM=M-1" << "\n";
        hack << "D=M" << "\n";
        hack << "@13" << "\n";
        hack << "A=M" << "\n";
        hack << "M=D" << "\n";
    } else if (segment == "temp"){ //temp
        hack << "@0" << "\n";
        hack << "M=M-1" << "\n";
        hack << "A=M" << "\n";
        hack << "D=M" << "\n";
        hack << "@13" << "\n";
        hack << "M=D" << "\n";
        hack << "@" << index << "\n";
        hack << "D=A" << "\n";
        hack << "@" << seg << "\n";
        hack << "D=A+D" << "\n";
        hack << "@14" << "\n";
        hack << "M=D" << "\n";
        hack << "@13" << "\n";
        hack << "D=M" << "\n";
        hack << "@14" << "\n";
        hack << "A=M" << "\n";
        hack << "M=D" << "\n";
    } else if (segment == "pointer"){ //pointer
        hack << "@0" << "\n";
        hack << "M=M-1" << "\n";
        hack << "A=M" << "\n";
        hack << "D=M" << "\n";
        hack << "@" << seg << "\n";
        hack << "M=D" << "\n";
    } else if (activate == 1){ //not constant
        hack << "@0" << "\n";
        hack << "M=M-1" << "\n";
        hack << "A=M" << "\n";
        hack << "D=M" << "\n";
        hack << "@13" << "\n";
        hack << "M=D" << "\n";
        hack << "@" << index << "\n";
        hack << "D=A" << "\n";
        hack << "@" << seg << "\n";
        hack << "A=M" << "\n";
        hack << "D=A+D" << "\n";
        hack << "@14" << "\n";
        hack << "M=D" << "\n";
        hack << "@13" << "\n";
        hack << "D=M" << "\n";
        hack << "@14" << "\n";
        hack << "A=M" << "\n";
        hack << "M=D" << "\n";
    } else {
        return "";
    }

    return hack.str() + "\n";  
}

/** Generate Hack Assembly code for a VM add operation assessed in Practical Assignment 6 */
string VMTranslator::vm_add(){
    stringstream hack;
    hack.str(string());

    hack << "@SP" << "\n";
    hack << "AM=M-1" << "\n";
    hack << "D=M" << "\n";
    hack << "A=A-1" << "\n";
    hack << "M=D+M" << "\n";

    return hack.str() + "\n";
}

/** Generate Hack Assembly code for a VM sub operation assessed in Practical Assignment 6 */
string VMTranslator::vm_sub(){
    stringstream hack;
    hack.str(string());

    hack << "@SP" << "\n";
    hack << "AM=M-1" << "\n";
    hack << "D=M" << "\n";
    hack << "A=A-1" << "\n";
    hack << "M=M-D" << "\n";

    return hack.str() + "\n";
}

/** Generate Hack Assembly code for a VM neg operation assessed in Practical Assignment 6 */
string VMTranslator::vm_neg(){
    stringstream hack;
    hack.str(string());

    hack << "@SP" << "\n";
    hack << "A=M" << "\n";
    hack << "A=A-1" << "\n";
    hack << "M=-M" << "\n";

    return hack.str() + "\n";
}

/** Generate Hack Assembly code for a VM eq operation assessed in Practical Assignment 6 */
string VMTranslator::vm_eq(){
    stringstream hack;
    hack.str(string());

    hack << "@SP" << "\n";
    hack << "AM=M-1" << "\n";
    hack << "D=M" << "\n";
    hack << "@SP" << "\n";
    hack << "AM=M-1" << "\n";
    hack << "D=M-D" << "\n";
    hack << "@JEQ_TRUE_" << to_string(counter) << "\n";
    hack << "D;JEQ" << "\n";
    hack << "D=0" << "\n";
    hack << "@JEQ_FALSE_" << to_string(counter) << "\n";
    hack << "0;JMP" << "\n";
    hack << "(JEQ_TRUE_"  << to_string(counter) << ")" << "\n";
    hack << "D=-1" << "\n";
    hack << "(JEQ_FALSE_" << to_string(counter) << ")" << "\n";
    hack << "@SP" << "\n";
    hack << "A=M" << "\n";
    hack << "M=D" << "\n";
    hack << "@SP" << "\n";
    hack << "M=M+1" << "\n";

    counter++;
    return hack.str() + "\n";
}

/** Generate Hack Assembly code for a VM gt operation assessed in Practical Assignment 6 */
string VMTranslator::vm_gt(){
    stringstream hack;
    hack.str(string());

    hack << "@SP" << "\n";
    hack << "AM=M-1" << "\n";
    hack << "D=M" << "\n";
    hack << "@SP" << "\n";
    hack << "AM=M-1" << "\n";
    hack << "D=M-D" << "\n";
    hack << "@JGT_TRUE_" << to_string(counter) << "\n";
    hack << "D;JGT" << "\n";
    hack << "D=0" << "\n";
    hack << "@JGT_FALSE_" << to_string(counter) << "\n";
    hack << "0;JMP" << "\n";
    hack << "(JGT_TRUE_"  << to_string(counter) << ")" << "\n";
    hack << "D=-1" << "\n";
    hack << "(JGT_FALSE_" << to_string(counter) << ")" << "\n";
    hack << "@SP" << "\n";
    hack << "A=M" << "\n";
    hack << "M=D" << "\n";
    hack << "@SP" << "\n";
    hack << "M=M+1" << "\n";

    counter++;
    return hack.str() + "\n";
}

/** Generate Hack Assembly code for a VM lt operation assessed in Practical Assignment 6 */
string VMTranslator::vm_lt(){
    stringstream hack;
    hack.str(string());

    hack << "@SP" << "\n";
    hack << "AM=M-1" << "\n";
    hack << "D=M" << "\n";
    hack << "@SP" << "\n";
    hack << "AM=M-1" << "\n";
    hack << "D=M-D" << "\n";
    hack << "@JLT_TRUE_" << to_string(counter) << "\n";
    hack << "D;JLT" << "\n";
    hack << "D=0" << "\n";
    hack << "@JLT_FALSE_" << to_string(counter) << "\n";
    hack << "0;JMP" << "\n";
    hack << "(JLT_TRUE_"  << to_string(counter) << ")" << "\n";
    hack << "D=-1" << "\n";
    hack << "(JLT_FALSE_" << to_string(counter) << ")" << "\n";
    hack << "@SP" << "\n";
    hack << "A=M" << "\n";
    hack << "M=D" << "\n";
    hack << "@SP" << "\n";
    hack << "M=M+1" << "\n";

    counter++;
    return hack.str() + "\n";
}

/** Generate Hack Assembly code for a VM and operation assessed in Practical Assignment 6 */
string VMTranslator::vm_and(){
    stringstream hack;
    hack.str(string());

    hack << "@SP" << "\n";
    hack << "AM=M-1" << "\n";
    hack << "D=M" << "\n";
    hack << "A=A-1" << "\n";
    hack << "M=M&D" << "\n";

    return hack.str() + "\n";
}

/** Generate Hack Assembly code for a VM or operation assessed in Practical Assignment 6 */
string VMTranslator::vm_or(){
    stringstream hack;
    hack.str(string());

    hack << "@SP" << "\n";
    hack << "AM=M-1" << "\n";
    hack << "D=M" << "\n";
    hack << "A=A-1" << "\n";
    hack << "M=M|D" << "\n";

    return hack.str() + "\n";
}

/** Generate Hack Assembly code for a VM not operation assessed in Practical Assignment 6 */
string VMTranslator::vm_not(){
    stringstream hack;
    hack.str(string());

    hack << "@SP" << "\n";
    hack << "A=M" << "\n";
    hack << "A=A-1" << "\n";
    hack << "M=!M" << "\n";

    return hack.str() + "\n";
}

/** Generate Hack Assembly code for a VM label operation assessed in Practical Assignment 7 */
string VMTranslator::vm_label(string label){
    return "";
}

/** Generate Hack Assembly code for a VM goto operation assessed in Practical Assignment 7 */
string VMTranslator::vm_goto(string label){
    return "";
}

/** Generate Hack Assembly code for a VM if-goto operation assessed in Practical Assignment 7 */
string VMTranslator::vm_if(string label){
    return "";
}

/** Generate Hack Assembly code for a VM function operation assessed in Practical Assignment 7 */
string VMTranslator::vm_function(string function_name, int n_vars){
    return "";
}

/** Generate Hack Assembly code for a VM call operation assessed in Practical Assignment 7 */
string VMTranslator::vm_call(string function_name, int n_args){
    return "";
}

/** Generate Hack Assembly code for a VM return operation assessed in Practical Assignment 7 */
string VMTranslator::vm_return(){
    return "";
}