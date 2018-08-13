# QuotedPrintable 编码

## 例子  

~~~
#include "QuotedPrintable.hpp"

int main(int argc, char *argv[])
{
	std::string str = "hello world!";
	std::cout << "str: " << str << std::endl;

	str = QuotedPrintable::encode(str);
	std::cout << "encode: " << str << std::endl;

	str = QuotedPrintable::decode(str);
	std::cout << "decode: " << str << std::endl;
}
~~~