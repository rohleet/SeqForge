#include<string>
#include<fstream>
#include "dna_individual.h"
#include<filesystem>
#include<string>
#include<iostream>


class fasta_input {

    public :
        
        static dna_individual file_input(std::filesystem::path s);
};
