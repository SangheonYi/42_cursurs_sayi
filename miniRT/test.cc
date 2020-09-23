#include <stdio.h>
#include <iostream>
// thread를 사용하기 위한 라이브러리
#include <thread>
using namespace std;

// 함수
void thread_function(int count)
{
  // 파라미터로 받은 count 수치만큼 반복문을 실행한다.
  for (int i = 0; i < count; i++)
  {
    // 콘솔 출력
    cout << "i - " << i << endl;
    // 쓰레드의 비활성 상태 대기, 10ms간..
    this_thread::sleep_for(chrono::milliseconds(10));
  }
}
// 실행 함수
int main()
{
  // thraed 생성, thread_function함수를 호출하고 파라미터는 10을 넘긴다.
  thread _t1(thread_function, 10);
  // thraed 생성
  thread _t2(thread_function, 10);
  // 콘솔 출력
  cout << "main process " << endl;

  // thread가 종료될 때까지 대기
  _t1.join();
  _t2.join();
  return 0;
}


/*
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
	for (size_t i = 0; i < 11; i++)
	{
		printf("==  %f  ===\n", random_double());
	}
	return 0;
} */

