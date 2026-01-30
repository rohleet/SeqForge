#include "dna_profile.h"

using namespace std;

void dna_profile::str_pair_add(std::string str, int count){
    dna_profile_map[str] = count;
}

void dna_profile::traverse_dna_profile_map() {
    for(auto& pair : dna_profile_map){
        
    }
}

bool dna_profile::dna_profile_comparison(dna_profile dna_profile) {
    for(auto& pair : this->dna_profile_map){
        if(dna_profile.dna_profile_map[pair.first]!=pair.second){
            return false;
        }
    }
    return true;
}

dna_profile::dna_profile(std::string individual_credentails,std::string strand_pattern)
{
    this->individual_credentails = individual_credentails;
    this->strand_pattern = strand_pattern;
}

dna_profile::~dna_profile()
{
}

void dna_profile::count_str(string pattern) {
    
}