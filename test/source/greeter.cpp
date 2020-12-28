#include <doctest/doctest.h>
#include <greeter/greeter.h>
#include <greeter/version.h>

#include <kata/duplicate_encoder.h>

#include <string>

TEST_CASE("Greeter") {
  using namespace greeter;

  Greeter greeter("Tests");

  CHECK(greeter.greet(LanguageCode::EN) == "Hello, Tests!");
  CHECK(greeter.greet(LanguageCode::DE) == "Hallo Tests!");
  CHECK(greeter.greet(LanguageCode::ES) == "¡Hola Tests!");
  CHECK(greeter.greet(LanguageCode::FR) == "Bonjour Tests!");
}

TEST_CASE("Greeter version") {
  static_assert(std::string_view(GREETER_VERSION) == std::string_view("1.0"));
  CHECK(std::string(GREETER_VERSION) == std::string("1.0"));
}

TEST_CASE("CodeWars Kata Cases") {
  CHECK(duplicate_encoder("din") == "(((");
  CHECK(duplicate_encoder("recede") == "()()()");
  CHECK(duplicate_encoder("Success") == ")())())");
  CHECK(duplicate_encoder("CodeWarrior") == "()(((())())");
  CHECK(duplicate_encoder("Supralapsarian") == ")()))()))))()(");
  CHECK(duplicate_encoder("(( @") == "))((");
  CHECK(duplicate_encoder(" ( ( )") == ")))))(");
}


SCENARIO("Our Duplicate Encoder Translates Characters to Parens") {
  GIVEN("I have a string 'YourCodeNeedsTests'") {
    std::string s{"YourCodeNeedsTests"};

    WHEN("We encode it to parens") {
      const auto encoded = duplicate_encoder(s);

      THEN("the result should be the same length of the input") {

        CHECK(encoded.size() == s.size()+1);

      }
    }
  }
}