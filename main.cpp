#include <iostream>

#include "queue.h"

int main() {
	std::atomic<int> cnt = 0;

	std::thread ct(client, std::ref(cnt));
	std::thread tt(teller, std::ref(cnt));

	if(ct.joinable()) ct.join();
	if(tt.joinable()) tt.join();

	return 0;
}