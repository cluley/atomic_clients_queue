#pragma once

#include <iostream>
#include <thread>
#include <chrono>
#include <Windows.h>
#include <mutex>

void q_status(std::atomic<int>& cnt);
void client(std::atomic<int>& cnt);
void teller(std::atomic<int>& cnt);