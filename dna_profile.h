#include<string>
#include<vector>
#include<unordered_map>

struct tandems
{
    static std::vector<std::vector<std::string>> tandems_list;
};


class dna_profile
{

    std::string individual_credentails;
    std::string strand_pattern;

    std::unordered_map<std::string,int> dna_profile_map;

    int find_left_flank(int start,std::string left_flank);
    std::vector<int> count_str(int start, std::string str);
    bool is_right_flank_present(int start,std::string right_flank);

public:

    void total_iterated_count_str();

    int count_single_tandem_repeats(const std::vector<std::string>& tandem_obj);

    void str_pair_add(std::string str, int count);

    void traverse_dna_profile_map();

    bool dna_profile_comparison(dna_profile dna_profile);



    dna_profile(std::string individual_credentails,std::string strand_pattern);
    ~dna_profile();

};

