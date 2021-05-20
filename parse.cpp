#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <sstream>

void parse_header( void * );

// int main()
// {

//     char * msg= "GET / HTTP/1.1\r\n"
//                 "Host: 192.241.213.46:6880\r\n"
//                 "Upgrade-Insecure-Requests: 1\r\n"
//                 "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\n"
//                 "User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_12_3) AppleWebKit/602.4.8 (KHTML, like Gecko) Version/10.0.3 Safari/602.4.8\r\n"
//                 "Accept-Language: en-us\r\n"
//                 "Accept-Encoding: gzip, deflate\r\n"
//                 "Connection: keep-alive\r\n\r\n";

//     parse_header( msg );

// }


std::vector<std::string> split(std::string str, char delimiter);

int main(){
    std::string get = "GET / HTTP/1.1\r\n"
						"Host: 192.241.213.46:6880\r\n"
						"Upgrade-Insecure-Requests: 1\r\n"
						"Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\n"
						"User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_12_3) AppleWebKit/602.4.8 (KHTML, like Gecko) Version/10.0.3 Safari/602.4.8\r\n"
						"Accept-Language: en-us\r\n"
						"Accept-Encoding: gzip, deflate\r\n"
						"Connection: keep-alive\r\n\r\n";
	std::string post = "POST /myform.html HTTP/1.1\r\n"
"Host: developer.mozilla.org\r\n"
"User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10.9; rv:50.0) Gecko/20100101 Firefox/50.0\r\n"
"Content-Length: 128\r\n";
// POST /payment-sync HTTP/1.1

// Accept: application/json
// Accept-Encoding: gzip, deflate
// Connection: keep-alive
// Content-Length: 83
// Content-Type: application/json
// Host: intropython.com
// User-Agent: HTTPie/0.9.3

// {
//     "imp_uid": "imp_1234567890",
//     "merchant_uid": "order_id_8237352",
//     "status": "paid"
// }
    std::vector<std::string> result = split(get, ' ');

}

std::vector<std::string> split(std::string input, char delimiter) {
    std::vector<std::string> answer;
    std::stringstream ss(input);
	std::map<std::string, std::string> headers;
    std::string key;
    std::string value;
    std::string type;
    std::string path;
    std::string version;
    std::string whiteSpace;

	getline(ss, value, delimiter);
	type = value;
	getline(ss, value, delimiter);
	path = value;
	getline(ss, value, '\r');
	getline(ss, whiteSpace, '\n');
	version = value;
	std::cout << "type:*" << type << "*" << std::endl;
	std::cout << "path:*" << path << "*" << std::endl;
	std::cout << "version:*" << version << "*" << std::endl;

    while (getline(ss, key, ':') && getline(ss, whiteSpace, delimiter) && getline(ss, value, '\r')) {
		getline(ss, whiteSpace, '\n');

		std::cout << "key:*" << key << "*" << std::endl;
		std::cout << "value:*" << value << "*" << std::endl;
        headers.insert( std::pair<std::string, std::string>(key, value));
    }
	std::cout<< "Upgrade-Insecure-Requests :" << headers[ "Upgrade-~Insecure-Requests" ] << std::endl;
    std::cout<< "Accept : " << headers[ "Accept" ] << std::endl;
    std::cout<< "User-Agent : " << headers[ "User-Agent" ] << std::endl;
    std::cout<< "Accept-Language : " << headers[ "Accept-Language" ] << std::endl;
    std::cout<< "Accept-Encoding : " << headers[ "Accept-Encoding" ] << std::endl;
    std::cout<< "Connection : " << headers[ "Connection" ] << std::endl;
    return answer;
}
