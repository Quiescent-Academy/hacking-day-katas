#include <iostream>
#include <map>
#include <kata/duplicate_encoder.h>

std::string duplicate_encoder(const std::string& word){
#if 0
  //C 
  for(int i = 0; i < word.size(); ++i) {
    char c = word[i]
  }

  //C++98
  for(std::string::const_iterator i = word.begin();
  i != word.end();
  ++i))
  {
    char c = *i;
  }


  //C++11
  for(auto i = std::cbegin(word)); i != std::cend(word); ++i) {
    char c = *i
  }
#endif
  std::map<char, size_t> seen_chars;
  //C++
  //range based for
  // This for loop will check if a given character has been seen,
  // if so, increment, if not, add one
  for(const auto& c : word) {
	if(seen_chars.contains(c)) {
		seen_chars[c] = seen_chars[c] + 1;
	} else {
		seen_chars[c] = 1;
	}
  }

  for(const auto& pair : seen_chars) { 
	std::cout << pair.first << "-" << pair.second << '\n';
  }

  return word;
}
