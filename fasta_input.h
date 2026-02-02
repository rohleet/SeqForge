#include<string>
#include<fstream>
#include "dna_profile.h"
#include<filesystem>
#include<string>
#include<iostream>
#include<cctype>
#include<algorithm>


class fasta_input {

    public :
        
        static dna_profile file_input(std::filesystem::path s);
};
