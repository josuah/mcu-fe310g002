#include <stddef.h>
#include <stdint.h>
#include <binary.h>

#define GPIO ((struct zmcu_gpio *)0x10012000)

struct zmcu_gpio {

	/* 0x00: Pin value */
	uint32_t volatile INPUT_VAL;

	/* 0x04: Pin input enable* */
	uint32_t volatile INPUT_EN;

	/* 0x08: Pin output enable* */
	uint32_t volatile OUTPUT_EN;

	/* 0x0C: Output value */
	uint32_t volatile OUTPUT_VAL;

	/* 0x10: Internal pull-up enable* */
	uint32_t volatile PUE;

	/* 0x14: Pin drive strength */
	uint32_t volatile DS;

	/* 0x18: Rise interrupt enable */
	uint32_t volatile RISE_IE;

	/* 0x1C: Rise interrupt pending */
	uint32_t volatile RISE_IP;

	/* 0x20: Fall interrupt enable */
	uint32_t volatile FALL_IE;

	/* 0x24: Fall interrupt pending */
	uint32_t volatile FALL_IP;

	/* 0x28: High interrupt enable */
	uint32_t volatile HIGH_IE;

	/* 0x2C: High interrupt pending */
	uint32_t volatile HIGH_IP;

	/* 0x30: Low interrupt enable */
	uint32_t volatile LOW_IE;

	/* 0x34: Low interrupt pending */
	uint32_t volatile LOW_IP;

	/* 0x40: Output XOR (invert) */
	uint32_t volatile OUT_XOR;

};
