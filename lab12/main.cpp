// Task description //
/*
  Create your own implementation of simplified std::string class.
  Use appropriate functions from C library, overload operators and don't forget about all needed constructors.
  Take care of proper memory management, do not declare friendship with any functions and leave this file unmodified.
*/

// Actual code //
#include "MyString.hpp"
#include <iostream>

using namespace mystring;

int main() 
{
  std::cout << "13th task: MyString with operators!\n" << std::endl;
    
	MyString s0("Exams are coming up.");  
	MyString s1("Exams are coming up");
	const MyString s2(s0);  

	s0.print("S0: "); s1.print("S1: "); s2.print("S2: "); 
	std::cout << "\n*** Comparing ***" << std::endl;
	std::cout << "Strings s0 and s2 " << (s0 == s2 ? "are identical" : "are not identical") << std::endl;
	std::cout << "Strings s2 and s1 " << (s2 == s1 ? "are identical" : "are not identical") << std::endl;
	std::cout << "Strings s2 and \"Exams are coming up.\" " 
            << (s2 == "Exams are coming up." ? "are identical" : "are not identical") << std::endl;
	
	std::cout << "\n*** Concatenating and assigning ***" <<  std::endl;
	std::cout << "S2: " << static_cast<char*>(s2) << std::endl; // s2.print("S2: :");
	s1 = "This is the last chance to start studying!!!";
	std::cout << "S1: " << s1 << std::endl;
	MyString s3 = s2 + " Here and now...";
	s3.print("S3: " );
	MyString s4 = s2 + ".. " + s1 + "\n\t" + s3 + '!'; // adding char!
	s4.print("S4: " );
	
	std::cout << "\n*** Duplicating ***" << std::endl;
  MyString s5 = 2 * String(":-)");
  s5.print("S5: ");
  MyString s6 = 4 * s5 + ":-D ";
	s6.print("S6: " );
    
	MyString const s7 = std::move(s1);
  std::cout << "S7: "<< s7 << std::endl; 
  s1.print("S1: ");
}

// Expected output //
/*
  13th task: MyString with operators!

  S0: Exams are coming up.
  S1: Exams are coming up
  S2: Exams are coming up.

  *** Comparing ***
  Strings s0 and s2 are identical
  Strings s2 and s1 are not identical
  Strings s2 and "Exams are coming up." are identical

  *** Concatenating and assigning ***
  S2: Exams are coming up.
  S1: This is the last chance to start studying!!!
  S3: Exams are coming up. Here and now...
  S4: Exams are coming up... This is the last chance to start studying!!!
          Exams are coming up. Here and now...!

  *** Duplicating ***
  S5: :-):-)
  S6: :-):-):-):-):-):-):-):-):-D 
  S7: This is the last chance to start studying!!!
  S1: 
*/
