#include "fasta_input.h"

using namespace std;
using namespace std::filesystem;

dna_individual fasta_input::file_input(path s) {

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
            input+=line;
    }

    return dna_individual(header,input);

}
