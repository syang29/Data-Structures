// File: a2.hpp
// Stephen
// Yang
// I AFFIRM THAT WHEN WORKING ON THIS ASSIGNMENT
// I WILL FOLLOW UB STUDENT CODE OF CONDUCT, AND
// I WILL NOT VIOLATE ACADEMIC INTEGRITY RULES

#ifndef A2_HPP
#define A2_HPP

// IMPLEMENT MISSING FUNCTIONALITY OF sorted_sc_array IN THIS FILE
// YOU ARE NOT ALLOWED TO INCLUDE ANY OTHER HEADERS EXCEPT OF <algorithm>
// YOU CAN CHANGE/EDIT ANY CODE IN THIS FILE AS LONG AS SEMANTICS IS UNCHANGED
// AND MATCHES SPECIFICATION AS PROVIDED IN THE ASSIGNMENT TEXT

#include <algorithm>


class sorted_sc_array {
public:
    sorted_sc_array() : size_(0), ptr_(new signed char[10000]), length(10000) { }


    ~sorted_sc_array() {  delete[] ptr_;  }

    // IMPLEMENT ME
    sorted_sc_array(const sorted_sc_array& A){
      size_ = A.size();
      length = A.length;
      ptr_ = new signed char[length];
      std::copy(A.ptr_, A.ptr_ + size_, ptr_);

    }

    // IMPLEMENT ME
    sorted_sc_array& operator=(const sorted_sc_array& A){
      if (this == &A) return *this;
      delete[] ptr_;
      size_ = A.size_;
      length = A.length;
      ptr_ = new signed char[length];
      std::copy(A.ptr_, A.ptr_ + size_, ptr_);
      return *this;
    }

    // RETURNS SIZE OF THE ARRAY (i.e. HOW MANY ELEMENTS IT STORES)
    int size() const { return size_; }

    // RETURNS RAW POINTER TO THE ACTUAL DATA, CAN BE INVOKED AT ANY TIME
    const signed char* data() const {
      int* count = new int[256];
      for(int i = 0; i < 256; i++) count[i]= 0;
      for(signed char* loc = ptr_; loc != ptr_+size_; loc++) count[(int)*loc+128]++;
      int ind = 0;
      for(int i = 0; i < 256; i++){
        if(count[i] != 0){
          for(int j = 0; j < count[i]; j++){
            ptr_[ind] = i -128;
            ind++;
          }
        }
      }
      delete[] count;
      return ptr_;
    }


    // IMPLEMENT ME: AFTER INSERT COMPLETES THE ARRAY MUST BE IN ASCENDING ORDER
    void insert(signed char c){
      if(size_ == length){
        signed char* temp = new signed char[size_*2];
        std::copy(ptr_,ptr_+size_,temp);
        delete[] ptr_;
        ptr_ = temp;
        length = size_*2;
      }
      ptr_[size_] = c;
      size_++;
    }


private:
    int size_;         // size of the array
    signed char* ptr_; // pointer to the array
    int length;   //size of ptr container
}; // class sorted_sc_array

#endif // A2_HPP
