#include<string>
#include<unordered_map>

struct tandems
{
    
};


class dna_profile
{

    std::string individual_credentails;
    std::string strand_pattern;

    std::unordered_map<std::string,int> dna_profile_map;

public:

    void count_str(std::string pattern);

    void str_pair_add(std::string str, int count);

    void traverse_dna_profile_map();

    bool dna_profile_comparison(dna_profile dna_profile);

    dna_profile(std::string individual_credentails,std::string strand_pattern);
    ~dna_profile();

};

