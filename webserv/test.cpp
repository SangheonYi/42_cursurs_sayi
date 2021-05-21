#include "Request.hpp"
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>

int main() {
	std::string get = "GET / HTTP/1.1\r\n"
						"Host: 192.241.213.46:6880\r\n"
						"Upgrade-Insecure-Requests: 1\r\n"
						"Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\n"
						"User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_12_3) AppleWebKit/602.4.8 (KHTML, like Gecko) Version/10.0.3 Safari/602.4.8\r\n"
						"Accept-Language: en-us\r\n"
						"Accept-Encoding: gzip, deflate\r\n"
						"Connection: keep-alive\r\n\r\n";


//  std::string data = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Disposition: attachment;filename=new.txt\n\ntest message";
	std::string data = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 11\n\nhello world";
	char buffer[100000];
	int server_fd;
	int new_socket;
	int bytes;
	sockaddr_in address;
	int addrlen = sizeof(address);

	server_fd = socket(AF_INET, SOCK_STREAM, 0); // err
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(8081);

	memset(address.sin_zero, '\0', sizeof(address.sin_zero));

	bind(server_fd, (sockaddr *)&address, sizeof(address));
	listen(server_fd, 5);
	while (1)
	{
		std::cout << "waiting..." << std::endl;
		new_socket = accept(server_fd, (sockaddr *)&address, (socklen_t *)&addrlen);
		bytes = read(new_socket, buffer, 100000);
		// std::cout << buffer << std::endl;
		write(new_socket, data.c_str(), data.length());
		close(new_socket);
	std::string stringed(buffer);

	Request req(buffer);
	Request::HeaderType headear = req.getHeaders();
	Request::HeaderType::iterator head = headear.begin();
	Request::HeaderType::iterator end = headear.end();
	while(head != end) {
		std::cout << "++" << head->first << "++" << std::endl;
		std::cout << "==" << head->second << "==" << std::endl;
		head++;
	}
	std::cout << "+body+" << std::endl;
	std::cout << req.getBody() << std::endl;
	}
	// std::cout<< "Upgrade-Insecure-Requests :" << head[ "Upgrade-~Insecure-Requests" ] << std::endl;
	// std::cout<< "Accept : " << head[ "Accept" ] << std::endl;
	// std::cout<< "User-Agent : " << head[ "User-Agent" ] << std::endl;
	// std::cout<< "Accept-Language : " << head[ "Accept-Language" ] << std::endl;
	// std::cout<< "Accept-Encoding : " << head[ "Accept-Encoding" ] << std::endl;
	// std::cout<< "Connection : " << head[ "Connection" ] << std::endl;

}
