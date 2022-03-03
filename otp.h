#include <stddef.h>
#include <stdint.h>
#include <binary.h>

#define OTP ((struct sdk_otp *)0x10010000)

struct sdk_otp {

	/* 0x00: Programmed-I/O lock register */
	uint32_t volatile LOCK;

	/* 0x04: OTP device clock signals */
	uint32_t volatile CK;

	/* 0x08: OTP device output-enable signal */
	uint32_t volatile OE;

	/* 0x0C: OTP device chip-select signal */
	uint32_t volatile SEL;

	/* 0x10: OTP device write-enable signal */
	uint32_t volatile WE;

	/* 0x14: OTP device mode register */
	uint32_t volatile MR;

	/* 0x18: OTP read-voltage regulator control */
	uint32_t volatile MRR;

	/* 0x1C: OTP write-voltage charge pump control */
	uint32_t volatile MPP;

	/* 0x20: OTP read-voltage enable */
	uint32_t volatile VRREN;

	/* 0x24: OTP write-voltage enable */
	uint32_t volatile VPPEN;

	/* 0x28: OTP device address */
	uint32_t volatile A;

	/* 0x2C: OTP device data input */
	uint32_t volatile D;

	/* 0x30: OTP device data output */
	uint32_t volatile Q;

	/* 0x34: OTP read sequencer control */
	uint32_t volatile RSCTRL;
#define OTP_RSCTRL_SCALE(x)			((x) << 0)
#define OTP_RSCTRL_TAS				(1u << 3)
#define OTP_RSCTRL_TRP				(1u << 4)
#define OTP_RSCTRL_TACC				(1u << 5)

};
