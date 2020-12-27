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

  //C++
  //range based for
  for(const auto& c : word) {
    std::cout << c << '\n'
  }

  return word;
}