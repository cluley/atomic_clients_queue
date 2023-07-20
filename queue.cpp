#include "queue.h"

std::mutex m;

void client(std::atomic<int>& cnt) {
	while (cnt.load() != 5) {
		std::this_thread::sleep_for(std::chrono::seconds(1));
		cnt.store(cnt.load() + 1);

		m.lock();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
		q_status(cnt);
		m.unlock();
	}
}

void teller(std::atomic<int>& cnt) {
	do {
		std::this_thread::sleep_for(std::chrono::seconds(2));
		cnt.store(cnt.load() - 1);

		m.lock();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		if (cnt.load() >= 0) q_status(cnt);
		m.unlock();
	} while (cnt.load() != -1);
}

void q_status(std::atomic<int>& cnt) {
	std::cout << "Длина очереди: " << cnt.load();
	if (cnt.load() > 1 && cnt.load() < 5) {
		std::cout << " человека" << std::endl;
	}
	else {
		std::cout << " человек" << std::endl;
	}
}