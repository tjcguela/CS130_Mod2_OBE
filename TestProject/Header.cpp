#include "Header.h"
#include <iostream>
int main() {
	int n = 1;
	ClassBasedNameSpace::Ageek a;
	std::cout << a.display("semipogi");
	std::cout << a.operation();
	ClassBasedNameSpace::sharable = 10;
}