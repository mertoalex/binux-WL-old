// source: https://www.codeproject.com/Articles/1225196/Create-Your-Own-Kernel-In-C-2

#pragma once

#include <stdint.h>
#include <stddef.h>

typedef unsigned int uint32;

void sleep(uint32 timer_count);