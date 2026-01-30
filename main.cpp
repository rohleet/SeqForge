#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
#include "fasta_input.h"
#include "dna_profile.h"

using namespace std;

int main(int argc, char* argv[]) {

    if(argc!=3){
        cerr<<"Incorrect usage! Correct usage : seqforge file"<<endl;
    }

    dna_profile d1 = fasta_input::file_input(argv[1]);
    dna_profile d2 = fasta_input::file_input(argv[2]);

    cout<<"The dna profile matches"<<d1.dna_profile_comparison(d2);

    return 0;
}
