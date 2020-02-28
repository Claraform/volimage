#ifndef VOLIMAGE_H
#define VOLIMAGE_H

#include <string>
#include <vector>
#include <ostream>
#include <istream>
#include <iostream>
#include <sstream>
#include <fstream>

class VolImage
{
    private: // private members

        int width, height,numImages; // width and height of image stack and number of images
        std::vector<unsigned char**> slices; // data for each slice, in order

    public: // public members

        VolImage(); // default constructor - define in .cpp
        ~VolImage(); // destructor - define in .cpp file
        // populate the object with images in stack and
        //set member variables define in .cpp
        bool readImages(std::string baseName);
        // compute difference map and write out; define in .cpp
        void diffmap(int sliceI, int sliceJ, std::string output_prefix);
        // extract slice sliceId and write to output - define in .cpp
        void extract(int sliceId, std::string output_prefix);
        void extract_row(int rowId, std::string output_prefix);
        // number of bytes uses to store image data bytes
        //and pointers (ignore vector<> container, dims etc)
        int volImageSize(void); // define in .cpp
        int noImages(void);
};
#endif
