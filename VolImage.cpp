#include "VolImage.h"

using namespace std;

//constructor
VolImage::VolImage(){
	int width=0;
	int height=0;
    int numImages=0;
	vector<unsigned char**> slices;

}

//destructor
VolImage::~VolImage(){

}	

// populate the object with images in stack and
//set member variables define in .cpp
bool VolImage::readImages(string baseName){
    ifstream ifs("data/" + baseName + ".dat");
    if (!ifs){
        cout << "Error opening " << baseName << ".dat header file." << endl;
        cout << "Does the file exist in directory data/?" << endl;
        return false;
    }
    string temp;
    getline(ifs, temp, '\n');
    istringstream iss(temp);
    int i = 1;
    string val;
	while(getline(iss, val, ' ')){
        if (i=1){
            if (!val.empty()){
                width = stoi(val);
            }
            else{
                cout << "File " << baseName << ".dat contains an incorrect format." << endl;
                cout << "Expected format: <width> <height> <number_images>" << endl;
                return false;
            }
        }
        if (i=2){
            if (!val.empty()){
                height = stoi(val);
            }
            else{
                cout << "File " << baseName << ".dat contains an incorrect format." << endl;
                cout << "Expected format: <width> <height> <number_images>" << endl;
                return false;
            }
        }
        if (i=3){
            if (!val.empty()){
                numImages = stoi(val);
                ifs.close();
                break;
            }
            else{
                cout << "File " << baseName << ".dat contains an incorrect format." << endl;
                cout << "Expected format: <width> <height> <number_images>" << endl;
                return false;
            }
        }
        i++;
    }
    for (int i = 0; i<numImages; i++){
        stringstream s;
        s << i;
        string fnum = s.str();
        string imagename = "data/" + baseName + fnum + ".raw";
        ifstream ifs(imagename, ios::in|ios::binary|ios::ate);

        //Following code adapted from cplusplus.com    
        streampos size;
        char * memblock;
        if (ifs.is_open()){
            size = ifs.tellg();
            memblock = new char [size];
            ifs.seekg (0, ios::beg);
            ifs.read (memblock, size);
            ifs.close();
        }
        else{
            cout << "Unable to open file " << imagename << ". " << endl;
            return false;
        }
    
        //Create array for image slice with correct dimensions
        unsigned char ** image = new unsigned char* [height];
        for (int g = 0; g<height; g++){
            image[g] = new unsigned char[width];
        }
        //Put memory block data from .raw file into image slice array
        int mem_ind=0;
        for (int y=0; y<height; y++){
            for (int x=0; x<width; x++){
                image[y][x] = memblock[mem_ind];
                mem_ind++;
            }
        }
        delete[] memblock;
        slices.push_back(image);
    }
    return true;    
}

// compute difference map and write out; define in .cpp
void VolImage::diffmap(int sliceI, int sliceJ, string output_prefix){
	//(unsigned char)(abs((float)volume[i][r][c] - (float)volume[j][r][c])/2)
}

// extract slice sliceId and write to output - define in .cpp
void VolImage::extract_row(int sliceId, string output_prefix){

}
// extract slice sliceId and write to output - define in .cpp
void VolImage::extract_col(int sliceId, string output_prefix){

}

// number of bytes uses to store image data bytes
//and pointers (ignore vector<> container, dims etc)
int VolImage::volImageSize(void){

}


