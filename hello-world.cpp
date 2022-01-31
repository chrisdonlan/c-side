#include <string>
#include <iostream>

struct Foo{
		std::string foo;
    Foo(){
        this->foo = "bar";
    }
};


int main()
{
		std::cout << "Hello C-side." << std::endl;
    return 0;
}
