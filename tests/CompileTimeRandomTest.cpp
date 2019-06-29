#include <string>

#include "doctest.h"

template<int N>
auto operator""_obfuscate(const char (&str)[N])
{
    return str;
}

int factorial(int number) { return number <= 1 ? number : factorial(number - 1) * number; }

TEST_CASE("testing the factorial function") {
	    CHECK(factorial(1) == 1);
	        CHECK(factorial(2) == 2);
		    CHECK(factorial(3) == 6);
		        CHECK(factorial(10) == 3628800);
}

TEST_CASE("Encrypt\\decrypt a string")
{
    auto encrypted = "Hello World"_obfuscate;
    std::string strDecrypted = encrypted.Decrypt();
    CHECK(strDecrypted == "Hello World");
}
