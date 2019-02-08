// File: a6.hpp
// Stephen
// Yang
// I AFFIRM THAT WHEN WORKING ON THIS ASSIGNMENT
// I WILL FOLLOW UB STUDENT CODE OF CONDUCT, AND
// I WILL NOT VIOLATE ACADEMIC INTEGRITY RULES

#ifndef A6_HPP
#define A6_HPP

#include <ostream>
#include "symbol.hpp"
#include <string>
#include <queue>
#include <vector>
#include <stack>

// MAKE SURE TO UPDATE YOUR INFORMATION IN THE HEADER OF THIS FILE
// IMPLEMENT ALL REQUIRED FUNCTIONS BELOW
// YOU ARE NOT ALLOWED TO ALTER ANY INTERFACE
// INSIDE A FUNCTION YOU CAN DO WHATEVER YOU LIKE
class mycomp{

public:

  bool operator() (const bnode<symbol>* lhs, const bnode<symbol>* rhs){

    return rhs->value < lhs->value;
  }
};
// IMPLEMENT YOUR FUNCTION huffman_tree
template <typename Iter>
bnode<symbol>* huffman_tree(Iter first, Iter last){
  std::priority_queue<bnode<symbol>*, std::vector<bnode<symbol>*>, mycomp> toFormHT;

  for(;first != last; first++)  toFormHT.push(new bnode<symbol>(*first));
  while(toFormHT.size() != 1){
    bnode<symbol>* firstmin = toFormHT.top(); toFormHT.pop();
    bnode<symbol>* secondmin = toFormHT.top(); toFormHT.pop();
    int sum = (firstmin->value).count + (secondmin->value).count;
    char tempp = 0;
    if((firstmin->value).value < (secondmin->value).value){
      tempp = (firstmin->value).value;
    }else{
       tempp = (secondmin->value).value;
    }

    toFormHT.push(new bnode<symbol>(symbol(tempp,sum),firstmin,secondmin));

  }
  return toFormHT.top();
}

// IMPLEMENT YOUR FUNCTION print_dictionary
void print_dictionary(std::ostream& os, bnode<symbol>* root){
  std::stack<const bnode<symbol>*> Q;
  const bnode<symbol>* curr = root;
  Q.push(curr);
  std::string code = "";
  std::vector<int> count(256, 0);
  while(!Q.empty()){
    if(curr->left == nullptr){
      if((curr->value).value != 0 && (count[(int)((curr->value).value)] == 0)){
         os<<(curr->value).value << " " << code <<"\n";
         count[(int)((curr->value).value)] = 1;
      }
      Q.pop();
      while(!Q.empty() && code.back() == '1'){
        Q.pop();
        code.pop_back();
      }code.pop_back();
      if(!Q.empty()){
        Q.push(Q.top()->right);
        curr = Q.top();
        code = code + "1";
      }
    }else{
      Q.push(curr->left);
      curr = curr->left;
      code = code + "0";
    }
  }
}

// IMPLEMENT YOUR FUNCTION release_tree
void release_tree(bnode<symbol>* root){

  if(root->left == nullptr){delete root; return ;}
  else{
    release_tree(root->left);
    release_tree(root->right);
  }delete root;
}

#endif // A6_HPP
