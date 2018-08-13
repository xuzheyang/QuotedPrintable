#ifndef _QUOTEDPRINTABLE_HPP__
#define _QUOTEDPRINTABLE_HPP__


class QuotedPrintable{
    public:
        static std::string encode(const std::string& input) {
            std::string output;
        
            char byte;
            const char hex[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

            for (int i = 0; i < input.length() ; ++i)
            {
                byte = input[i];
        
                if ((byte == ' ') || ((byte >= 33) && (byte <= 126)  && (byte != '='))) {
                    output += byte;
                } else {
                    output += '=';
                    output +=  hex[((byte >> 4) & 0x0F)];
                    output += hex[(byte & 0x0F)];
                }
            }
        
            return output;
        };
        
        static std::string decode(const std::string& input) {
            std::string output;
        
            for (int i = 0; i < input.length(); ++i)
            {
                if (input.at(i) == '=' && i+2<input.length())
                {
                    std::string strValue = input.substr((++i)++, 2);
                    //            bool converted;
                    char character = std::stoi(strValue, nullptr, 16);
                    if( character )
                        output += character;
                    else
                        output = output + "=" + strValue;
                }
                else
                {
                    output += input.at(i);
                }
            }
        
            return output;
        }
    };

#endif // _QUOTEDPRINTABLE_HPP__