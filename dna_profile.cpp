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
    int str_len = str.length();
    
    int str_count = 0;
    bool matched = false;

    // check first STR
    for(int k = str_len-1; k <= str_len+1; k++) {

        if(start + k > strand_pattern_length || k <= 0) continue;

        string temp = strand_pattern.substr(start,k);

        if(temp==str || check_local_tandem_alignment(temp,str)){
            str_count++;
            start += k;
            matched = true;
            break;
        }
    }

    if(!matched){
        return {};
    }

    for(int i=start;i<strand_pattern_length;) {

        matched = false;

        for(int k = str_len-1; k <= str_len+1; k++) {

            if(i + k > strand_pattern_length || k <= 0) continue;

            string temp = strand_pattern.substr(i,k);

            if(temp==str || check_local_tandem_alignment(temp,str)){
                str_count++;
                i += k;
                matched = true;
                break;
            }
        }

        if(!matched){
            return {i,str_count};
        }
    }

    return {};
}

bool dna_profile::is_right_flank_present(int start,string right_flank) {

    return right_flank==strand_pattern.substr(start,right_flank.length());

}

bool dna_profile::check_local_tandem_alignment(string present_str,string standard_tandem) {

    int present_str_length = present_str.length();
    int standard_tandem_length = standard_tandem.length();

    int match = 1;
    int mis_match = 0;
    int gap = -1;

    vector<vector<int>> dp(present_str_length+1, vector<int>(standard_tandem_length+1,0));

    int best_score = 0;

    for(int i=1;i<=present_str_length;i++){

        for(int j=1;j<=standard_tandem_length;j++){

            int c_diag= dp[i-1][j-1];
            int c_left = dp[i-1][j]+gap;
            int c_up = dp[i][j-1]+gap;
            
            if(present_str.at(i-1)==standard_tandem.at(j-1)){
                c_diag += match; 
            }

            dp[i][j] = max(0,max(c_diag,max(c_left,c_up)));

            best_score = max(dp[i][j],best_score);

        }

    }

    if((((double)best_score*100)/max(present_str_length,standard_tandem_length))>=75) return true;

    return false;
}

bool dna_profile::iupac_character_detection(char be_checked,char original) {

    

}