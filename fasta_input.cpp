#include "fasta_input.h"

using namespace std;
using namespace std::filesystem;

unordered_set<char> nitrogen_base = {'A', 'C', 'T', 'G'};

unordered_set<char> nitrogen_base_lower_case = {'a', 'c', 't', 'g'};

dna_profile fasta_input::file_input(path s) {

    if(!exists(s)){
        throw std::runtime_error("File doesn't exist");
    }

    if(!is_regular_file(s)){
        throw std::runtime_error("Ther is some problem with the input file");
    }

    ifstream ip_file(s);

    // string input = "";

    char input;

    bool individual_detail = false;

    string header = "";
    string line;

    while(ip_file.get(input)){
        if(!individual_detail){
            if(input=='\n'){
                individual_detail = 1;
                continue;
            }
            header+=input;
        } else {
            if(input == '\n') {
                continue;
            }
            if(nitrogen_base.find(input)!=nitrogen_base.end()){
                line+=input;
            } else if(nitrogen_base_lower_case.find(input)!=nitrogen_base_lower_case.end()){
                line+=static_cast<char>(toupper(static_cast<unsigned char>(input)));
            } else {
                cerr<<"Rejected : corrupted dna sequence, contains number or special characters";
                exit(-1);
            } 
        }
    }

    // while(getline(ip_file,line)){
    //     if(!individual_detail){
    //         header = line;
    //         individual_detail = 1;
    //     } else 
    //         for(unsigned char c : line){

    //             if(c>='0' && c<='9'){
    //                 cerr<<"Rejected : corrupted dna sequence, contains number";
    //                 exit(-1);
    //             }

    //             std::transform(line.begin(), line.end(), line.begin(),
    //                 [](unsigned char c) {
    //                 return std::toupper(c);
    //             });

    //         }

    //         input+=line;

    // }

    if(line.length()==0){
        cerr<<"Error file doesn't contain dna sequence";
        exit(-2);
    }

    return dna_profile(header,line);

}
