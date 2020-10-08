/* #include <stdio.h>
#include <iostream>
// thread를 사용하기 위한 라이브러리
#include <thread>
using namespace std;

// 함수
void thread_function(int count, string &buf)
{
  // , string &buf
    buf += to_string(count);
    buf += to_string(count);
    buf += to_string(count);
    cout << count << endl;
}
// 실행 함수
int main()
{
  string buf1 = "";
  string buf2 = "";
  // thraed 생성, thread_function함수를 호출하고 파라미터는 10을 넘긴다.
  std::thread _t1(thread_function, 23, std::ref(buf1));
  // , buf1
  // thraed 생성
  std::thread _t2(thread_function, 111, std::ref(buf2));
  // , buf2
  // 콘솔 출력

  // thread가 종료될 때까지 대기
  _t1.join();
  _t2.join();

  cout << buf1 << endl;
  cout << buf2 << endl;
  return 0;
}
 */

#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>
#include <random>
#include <string.h>
#include <stdlib.h>

#include <iostream>
using namespace std;

inline double random_double()
{
	// Returns a random real in [0,1).
	return rand() / (RAND_MAX + 1.0);
}

int main(int argc, char const *argv[])
{
	for (size_t i = 0; i < 10; i++)
	{
		printf("==  %f  ===\n", random_double());
	}
	return 0;
}

