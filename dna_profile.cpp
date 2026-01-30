#include "dna_profile.h"

using namespace std;

vector<vector<string>> tandems::tandems_list = {{"TGGGCTGAGGCTGAGTGC","AGAT","CCTATGACCATGTAGACC"},
                                                {"GATCTGGGCTTCTGTTGT","TCTA","AGGCTTCCAAAGTCTGGC"},
                                                {"CTCTATCTATCTATCT","TTTC","GATGACAGGATGGATGA"}};

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
    total_iterated_count_str();
}

dna_profile::~dna_profile()
{
}

void dna_profile::total_iterated_count_str() {

    for(const vector<string>& tandem_obj : tandems::tandems_list){
        str_pair_add(tandem_obj[1],count_single_tandem_repeats(tandem_obj));
    }

}

int dna_profile::count_single_tandem_repeats(const vector<string>& tandem_obj) {

    int left_flank_length = tandem_obj[0].length();
    int right_flank_length = tandem_obj[2].length();
    int tandem_length = tandem_obj[1].length();

    int strand_pattern_length = strand_pattern.length();

    string temp = strand_pattern.substr(0,left_flank_length);

    bool left_flank_present = false;

    int str_size = 0;

    int str_start;

    for(int i=0;i<strand_pattern_length-4;i++) {

        if(left_flank_present){
            if(temp==tandem_obj[2]){
                break;
            }
            str_size++;
        } else {
            if(temp==tandem_obj[0]){
                temp = strand_pattern.substr(i,right_flank_length);
                left_flank_present = 1;
            }
            
        }

        temp.erase(0,1);
        temp+=strand_pattern[i];
    }

    return str_size/tandem_length;

}

