// File: a7.cpp
// Stephen
// Yang
// I AFFIRM THAT WHEN WORKING ON THIS ASSIGNMENT
// I WILL FOLLOW UB STUDENT CODE OF CONDUCT, AND
// I WILL NOT VIOLATE ACADEMIC INTEGRITY RULES

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <istream>

struct wordAndFreq {
    wordAndFreq(std::string wordInp = "", int freqInp = 0) : word(wordInp), freq(freqInp) { }
    std::string word; // actual symbol, by default 0 (empty)
    int freq;  // count of the symbol, by default 0
};

inline bool operator<(const wordAndFreq lhs, const wordAndFreq rhs) {
  if(lhs.freq == rhs.freq) return rhs.word<lhs.word;
  else return lhs.freq < rhs.freq;
}

//calculates hamming
int isDistanceOne(std::string first, std::string second ){

  int diffInLength = first.size()-second.size();
  int distance = abs(diffInLength);
  if(distance > 1) return 2;
  int count = 0;
  std::string longer = first;
  std::string shorter = second;
  if(diffInLength < 0) {
    shorter = first;
    longer = second;
  }
  int shorterind = 0;
  int longerind = 0;
  while((static_cast<unsigned>(shorterind) < shorter.size()) && count < 2){
    if(shorter[shorterind] != longer[longerind] ){
      longerind = longerind + distance;
      count = count + 1;
      if(distance != 0){
        shorterind--; longerind--;
      }
    }
    shorterind++; longerind++;
  }
  if(static_cast<unsigned int>(longerind) < longer.size()) count++;
  return count;


}

int main(int argc, char* argv[]){
  std::vector<wordAndFreq> wordsByLength;
  std::vector<std::string> eachInput;

  std::ifstream f(argv[1]);
  while(!f.eof()){
    std::string a;
    int b;
    f >> a;
    f >> b;
    wordsByLength.push_back(wordAndFreq(a,b));

  }
  std::string each;
  while(std::cin >> each) eachInput.push_back(each);

  for(unsigned int i = 0; i < eachInput.size(); i++){//for each input
    wordAndFreq recommended;
    bool rec = false;

    bool printed = false;

    //checking if word is in dictionary
    for(unsigned int j = 0; j < wordsByLength.size(); j++){
      int x = isDistanceOne(eachInput[i],wordsByLength[j].word);
      if(x == 0){
        std::cout<< eachInput[i] << " " << wordsByLength[j].freq << "\n";
        wordsByLength[j].freq = wordsByLength[j].freq + 1;
        printed = true;
        break;
      }
      else if(x == 1){
        if(!rec) {
          recommended = wordsByLength[j];
          
          rec = true;
        }
        else if(recommended < wordsByLength[j]){
          recommended = wordsByLength[j];

        }
      }
    }
    if(!printed){
      if(!rec){
        std::cout << "-" << "\n";
        wordsByLength.push_back(wordAndFreq(eachInput[i],1));
      }
      else{
        std::cout<< recommended.word << " " << recommended.freq << "\n";

      }
    }
  }
  return 0;

}
