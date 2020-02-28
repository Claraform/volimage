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
        cout << "Reading in images..." << endl;
        if(!vm.readImages(in_prefix)){
            cout << "Error parsing data files. Terminating program..." << endl;
            return 0;
        }
        cout << "Number of images: " << vm.noImages() << endl;
        cout << "Number of bytes required: " << vm.volImageSize() << endl;
        return 0;
    }
    else if (argc == 5){
        if (string(argv[2])=="-x"){
            //output an extraction
            int col;
            stringstream s;
            s << argv[3];
            s >> col;
            string out = string(argv[4]);
            cout << "Column extraction along column " << col << " requested." << endl;
            cout << "Reading in images..." << endl;
            if(!vm.readImages(in_prefix)){
                cout << "Error parsing data files. Terminating program..." << endl;
                return 0;
            }
            cout << "Number of images: " << vm.noImages() << endl;
            cout << "Number of bytes required: " << vm.volImageSize() << endl;
            vm.extract(col, out);
        }
        else if (string(argv[2])=="-g"){
            //output a row extraction
            int row;
            stringstream s;
            s << argv[3];
            s >> row;
            string out = string(argv[4]);
            cout << "Row extraction along row " << row << " requested." << endl;
            cout << "Reading in images..." << endl;
            if(!vm.readImages(in_prefix)){
                cout << "Error parsing data files. Terminating program..." << endl;
                return 0;
            }
            cout << "Number of images: " << vm.noImages() << endl;
            cout << "Number of bytes required: " << vm.volImageSize() << endl;
            vm.extract_row(row, out);
        }
        else{
            cout << "Invalid arguments... terminating program..." << endl;
            return 0;
        }
    }
    else if (argc == 6){
        //compute difference map
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
        cout << "Difference map computation between slice " << sliceI << " and slice " << sliceJ << " requested." << endl;
        cout << "Reading in images..." << endl;
        if(!vm.readImages(in_prefix)){
            cout << "Error parsing data files. Terminating program..." << endl;
            return 0;
        }
        cout << "Number of images: " << vm.noImages() << endl;
        cout << "Number of bytes required: " << vm.volImageSize() << endl;
        vm.diffmap(sliceI, sliceJ, out);
    }
    else{
        cout << "Invalid arguments... terminating program..." << endl;
        return 0;
    }
}
