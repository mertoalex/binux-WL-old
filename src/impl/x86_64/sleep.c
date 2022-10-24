// source: https://www.codeproject.com/Articles/1225196/Create-Your-Own-Kernel-In-C-2
#include "sleep.h"

void wait_for_io(uint32 timer_count) {
	while(1){
		asm volatile("nop");
		timer_count--;
		if(timer_count <= 0)
			break;
	}
}

void sleep(uint32 timer_count) {
  wait_for_io(timer_count);
}
