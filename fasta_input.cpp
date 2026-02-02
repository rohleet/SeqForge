#include "fasta_input.h"

using namespace std;
using namespace std::filesystem;

dna_profile fasta_input::file_input(path s) {

    if(!exists(s)){
        throw std::runtime_error("File doesn't exist");
    }

    if(!is_regular_file(s)){
        throw std::runtime_error("Ther is some problem with the input file");
    }

    ifstream ip_file(s);

    string input = "";

    bool first = false;

    string header;
    string line;

    while(getline(ip_file,line)){
        if(!first){
            header = line;
            first = 1;
        } else 
            for(unsigned char c : line){

                if(c>='0' && c<='9'){
                    cerr<<"Rejected : corrupted dna sequence, contains number";
                    exit(-1);
                }

                std::transform(line.begin(), line.end(), line.begin(),
                    [](unsigned char c) {
                    return std::toupper(c);
                });

            }

            input+=line;

    }

    if(input.length()==0){
        cerr<<"Error file doesn't contain dna sequence";
        exit(-2);
    }

    return dna_profile(header,input);

}
