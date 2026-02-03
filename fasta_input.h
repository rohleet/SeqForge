#include<string>
#include<fstream>
#include "dna_profile.h"
#include<filesystem>
#include<string>
#include<iostream>
#include<cctype>
#include<algorithm>
#include<unordered_set>


class fasta_input {

    public :
        
        static std::unordered_set<int> nitrogen_base;
        static std::unordered_set<int> nitrogen_base_lower_case;
        static dna_profile file_input(std::filesystem::path s);
};
