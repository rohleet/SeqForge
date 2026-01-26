#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
#include "dna_individual.h"
#include "fasta_input.h"

using namespace std;

int main(int argc, char* argv[]) {

    if(argc!=3){
        cerr<<"Incorrect usage! Correct usage : seqforge file"<<endl;
    }

    dna_individual d1 = fasta_input::file_input(argv[1]);
    dna_individual d2 = fasta_input::file_input(argv[2]);

    return 0;
}
