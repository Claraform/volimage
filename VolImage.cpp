#include "VolImage.h"
#include <string>
#include <vector>

using namespace std;

//constructor
VolImage::VolImage(){
	int width=0;
	int height=0;
	vector<unsigned char**> slices;

}

//destructor
VolImage::~VolImage(){

}	

// populate the object with images in stack and
//set member variables define in .cpp
bool VolImage::readImages(std::string baseName){

}

// compute difference map and write out; define in .cpp
void VolImage::diffmap(int sliceI, int sliceJ, std::string output_prefix){
	//(unsigned char)(abs((float)volume[i][r][c] - (float)volume[j][r][c])/2)
}

// extract slice sliceId and write to output - define in .cpp
void VolImage::extract_row(int sliceId, std::string output_prefix){

}
// extract slice sliceId and write to output - define in .cpp
void VolImage::extract_col(int sliceId, std::string output_prefix){

}

// number of bytes uses to store image data bytes
//and pointers (ignore vector<> container, dims etc)
int VolImage::volImageSize(void){

}


