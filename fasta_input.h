#include<string>
#include<fstream>
#include "dna_profile.h"
#include<filesystem>
#include<string>
#include<iostream>


class fasta_input {

    public :
        
        static dna_profile file_input(std::filesystem::path s);
};
