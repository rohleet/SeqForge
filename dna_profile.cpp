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

    int left_flank_start = 0;

    while(true){

        int str_start = find_left_flank(left_flank_start,tandem_obj.at(0));

        vector<int> count_str_result = count_str(str_start,tandem_obj.at(1));

        if(count_str_result.size()==0){
            left_flank_start = str_start;
            continue;
        }

        if(is_right_flank_present(count_str_result.at(0),tandem_obj.at(2))){
            return count_str_result.at(1);
        } 

        left_flank_start = count_str_result.at(0);

    }

}

int dna_profile::find_left_flank(int start,string left_flank) {

    string temp = strand_pattern.substr(start,left_flank.length());
    start += left_flank.length();

    int strand_pattern_length = strand_pattern.length();

    for(int i=start;i<strand_pattern_length-4;i++) {
        if(temp==left_flank){
            return i;
        }

        temp.erase(0,1);
        temp+=strand_pattern.at(i);
    }
    
    return -1;
}

vector<int> dna_profile::count_str(int start, string str) {

    int strand_pattern_length = strand_pattern.length();
    string temp = strand_pattern.substr(start,4);
    
    int str_count = 0;

    if(temp==str){
        str_count++;
    } else {
        return {};
    }

    start+=4;

    for(int i=start;i<strand_pattern_length;i+=4) {
        temp=strand_pattern.substr(i,4);
        if(temp==str){
            str_count++;
        } else {
            return {i,str_count};
        }
    }

    return {};
}

bool dna_profile::is_right_flank_present(int start,string right_flank) {

    return right_flank==strand_pattern.substr(start,right_flank.length());

}

bool dna_profile::iupac_character_detection(string be_checked,string str) {

    for(int i=0;i<str.length();i++){
        if(be_checked.at(i)==str.at(i)){
            continue;
        } else {

            switch (be_checked.at(i))
            {
            case 'N':
                
                break;
            
            default:
                break;
            }

        }
    }

}