#include <fe310g002.h>

extern int main(void);
extern void __reset_handler(void);

extern char __data_start, __data_end, __data_load_start;
extern char __bss_start, __bss_end, __stack_top;

void
__reset_handler(void)
{
	volatile char *src, *dst;

	/* fill initialised and uninitialised variables */
	src = &__data_load_start;
	for (dst = &__data_start; dst < &__data_end; *dst++ = *src++);
	for (dst = &__bss_start; dst < &__bss_end; *dst++ = 0);

	main();
	__stop_program();
}

void
__stop_program(void)
{
	for (int volatile i = 0 ;; i++);
}
