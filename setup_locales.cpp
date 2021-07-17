#include "setup_locales.h"

//uncomment to output to file
#define USE_OUTPUT_FILE 

#ifdef USE_OUTPUT_FILE
#define OSTRM outfile
#else
#define OSTRM cout
#endif

using namespace std;

int main(int argc, char **argv){

    istringstream issline, iss;
    string line, str;

    if (argc != 3){
        std::cout << "usage: ./setuplocales input-file output-file" << std::endl;
    }
    ifstream file(argv[1]);
    
    #ifdef USE_OUTPUT_FILE
    ofstream outfile(argv[2]);
    if (!outfile.is_open()) {
        cerr << "Output file isn't open" << endl;
        exit(1);
    }
    #endif
    
    while (getline(file, line) && !line.empty()) {
        
    }

    #ifdef USE_OUTPUT_FILE
    outfile.close();
    #endif

    return 0;
}