// Copyright (c) 2022, The MaPra Authors.

#include "student.h"
//#include <cstring>
// Eingabeoperator ">>"
std::istream& mapra::operator>>(std::istream& s, mapra::Student& a) {
  s >> a.first_name >> a.last_name >> a.matr_nr >> a.grade;
  return s;
}

// Ausgabeoperator "<<"
std::ostream& mapra::operator<<(std::ostream& s, const mapra::Student& a) {
  s << a.first_name << a.last_name << a.matr_nr << a.grade; 
  return s; 
}

// Vergleichsoperator "<"
bool mapra::operator<(const mapra::Student& a, const mapra::Student& b ) {
  /*char a_last_name[a.last_name.size()]; 
  for (int i = 0; i < a.last_name.size(); i++){
      a_last_name[i] = a.last_name[i]; 
  }
  char b_last_name[b.last_name.size()]; 
  for (int i = 0; i < b.last_name.size(); i++){
      b_last_name[i] = b.last_name[i]; 
  }
  
  int value = strcmp(a_last_name, b_last_name); 
  if (value == 0){
    char a_first[a.first_name.size()]; 
    for (int i = 0; i < a.first_name.size(); i++){
        a_first[i] = a.first_name[i]; 
    }
    char b_first[b.first_name.size()]; 
    for (int i = 0; i < b.first_name.size(); i++){
        b_first[i] = b.first_name[i]; 
    }
    value = strcmp(a_first, b_first);
    if (value < 0){
      return false; 
    }
    return true;  
  }else if (value < 0){
    return true; 
  }
  return false;*/
  int compare = a.last_name.compare(b.last_name); 
  if (compare == 0){
    compare = a.first_name.compare(b.first_name); 
    if (compare < 0){
      return true; 
    }
    return false; 
  }else if ( compare < 0){
    return true; 
  }
  return false; 
}

// Vergleichsoperatoren "==" bzw. "!="
bool mapra::operator==(const mapra::Student& a, const mapra::Student& b) {
  int name = a.last_name.compare(b.last_name); 
  int first = a.first_name.compare(b.first_name); 
   if ((name == 0) && ( first == 0) && (a.matr_nr == b.matr_nr) && (a.grade == b.grade)){
    return true; 
   }
   return false; 
   
}

bool mapra::operator!=(const mapra::Student& a, const mapra::Student& b) {
  return !(mapra:: operator==(a, b)); 
}

bool mapra::operator>(const mapra::Student& a, const mapra::Student& b){
  return !(mapra::operator<(a,b)); 
}
