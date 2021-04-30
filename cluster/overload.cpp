#include <iostream>
#include <list>

class Par {
	public:
	int a;

	Par(): a(0) {};
	Par(Par const &other): a(other.a) {};
	virtual ~Par() {};
/*
**  postfix op
*/
	Par operator++(int) {
	std::cout << "pa1" << std::endl;
		return (operator++());
	}
	Par operator--(int) {
	std::cout << "pa3" << std::endl;
		return (operator--());
	}
/*
**  prefix op
*/
	Par &operator++() {
		this->a++;
	std::cout << "pa2" << std::endl;
		return (*this);
	}
	Par &operator--() {
		this->a--;
	std::cout << "pa4" << std::endl;
		return (*this);
	}
};


class Chi: public Par {
	public:

	Chi(): Par() {};
	Chi(Par const &other): Par(other) {};
	virtual ~Chi() {};
/*
**  postfix op
*/
	Chi operator++(int) {
		operator++();
		return (*this);
	}

	Chi operator--(int) {
		operator--();
		return (*this);
	}
/*
**  prefix op
*/
	Chi &operator++() {
		Par::operator--();
		return (*this);
	}

	Chi &operator--() {
		Par::operator++();
		return (*this);
	}
};

int main() {
	std::list<int> a;
	a.push_back(0);
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	std::list<int>::iterator it = a.begin();
	std::cout << *(it) << std::endl;
	(it++)++;
	std::cout << *(it) << std::endl;
	++(++it);
	std::cout << *(it) << std::endl;
	std::cout << "=================" << std::endl;

	Par p;

	std::cout << p.a << std::endl;
	p++;
	std::cout << p.a << std::endl;

	Chi c(p);

	std::cout << c.a << std::endl;
	c++;
	std::cout << c.a << std::endl;
	(c++)++;
	std::cout << c.a << std::endl;
	++(++c);
	std::cout << c.a << std::endl;
}
