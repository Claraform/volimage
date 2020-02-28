/**
 * Clara Esther Stassen
 * STSCLA001
 * CSC3022F Assignment 2
 * February 2020
 */
#include "VolImage.h"
#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[]){
    VolImage vm; //create a new object
    string in_prefix = argv[1];
    if (argc == 2){
        //build internal representation
        //clean memory
        vm.readImages(in_prefix);
        cout << "Number of images: " <<  endl;
        cout << "Number of bytes required: " << endl;
        //exit
    }
    else if (argc == 5){
        if (string(argv[2])=="-x"){
            int col;
            stringstream s;
            s << argv[3];
            s >> col;
            string out = string(argv[4]);
            vm.readImages(in_prefix);
            cout << "Number of images: " <<  endl;
            cout << "Number of bytes required: " << endl;
            vm.extract_col(col, out);
        }
        else if (string(argv[2])=="-g"){
            int row;
            stringstream s;
            s << argv[3];
            s >> row;
            string out = string(argv[4]);
            vm.readImages(in_prefix);
            cout << "Number of images: " <<  endl;
            cout << "Number of bytes required: " << endl;
            vm.extract_row(row, out);
        }
        else{
            cout << "Invalid arguments... terminating program..." << endl;
            return 0;
        }
    }
    else if (argc == 6){
        //compute difference map
        cout << "6 args" << endl;
        if (string(argv[2]) != "-d"){
            cout << "Invalid arguments... terminating program..." << endl;
            return 0;
        }
        int sliceI, sliceJ;
        stringstream s;
        s << argv[3];
        s >> sliceI;
        s.clear();
        s << argv[4];
        s >> sliceJ;
        string out = string(argv[5]);
        cout << sliceI << sliceJ << out << endl;
        vm.diffmap(sliceI, sliceJ, out);
    }
    else{
        cout << "Invalid arguments... terminating program..." << endl;
        return 0;
    }
}
