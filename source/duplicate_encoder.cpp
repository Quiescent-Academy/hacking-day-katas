#include <iostream>
#include <algorithm>
#include <map>
#include <cctype>
#include <sstream>
#include <kata/duplicate_encoder.h>

std::string duplicate_encoder(const std::string& word){
  std::map<char, size_t> seen_chars;
  //C++
  //range based for
  // This for loop will check if a given character has been seen,
  // if so, increment, if not, add one
  for(const auto& c : word) {
    const char key = static_cast<char>(std::tolower(c));
    if (seen_chars.count(key) == 1) {
      seen_chars[key]++;
    } else {
      seen_chars[key] = 1;
    }
  }

  std::stringstream ss;
  for(const auto& c : word) {
    const char key = static_cast<char>(std::tolower(c));
    if(seen_chars.at(key) > 1) {
      ss << ")";
    }else{
      ss<<"(";
    }
  }

  return ss.str();
}
