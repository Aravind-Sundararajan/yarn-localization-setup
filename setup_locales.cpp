#include "setup_locales.h"

//comment to output to cout
#define USE_OUTPUT_FILE 

#ifdef USE_OUTPUT_FILE
#define OSTRM out_yarn
#define CSVSTRM out_csv
#else
#define OSTRM cout
#define CSVSTRM cout
#endif

using namespace std;

int main(int argc, char **argv){

    string line;
    std::stringstream buf;
    int c;
    bool in_body;
    char delim = ',';
    string body_start = "---";
    string body_end   = "===";

    if (argc != 4){
        std::cout << "usage: ./setuplocales input-file metatagged-file csv-file" << std::endl;
    }
    string fpath = string(argv[1]);
    ifstream file(fpath);
    
    #ifdef USE_OUTPUT_FILE
    ofstream out_yarn(argv[2]);
    if (!out_yarn.is_open()) {
        cerr << "Output file isn't open" << endl;
        exit(1);
    }

    ofstream out_csv(argv[3]);
    if (!out_csv.is_open()) {
        cerr << "Output csv isn't open" << endl;
        exit(1);
    }
    #endif

    in_body = false;
    c = 0;
    while (getline(file, line)) {
        
        if (line == body_end){
            in_body = false;
        }

        if (in_body){
            c++;
            buf << "#line:" << std::hex << std::hash<std::string>{}(line + fpath + std::to_string(c));
            OSTRM << line << buf.str() << endl;
            CSVSTRM << buf.str() << delim << line << endl;
            buf.str("");
        }else{
            OSTRM << line << endl;
        }

        if (line == body_start){
            in_body = true;
        }
    }

    #ifdef USE_OUTPUT_FILE
    out_yarn.close();
    out_csv.close();
    #endif

    return 0;
}