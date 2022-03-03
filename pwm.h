#include <stddef.h>
#include <stdint.h>
#include <binary.h>

#define PWM0 ((struct sdk_pwm *)0x10015000)
#define PWM1 ((struct sdk_pwm *)0x10025000)
#define PWM2 ((struct sdk_pwm *)0x10035000)

struct sdk_pwm {

	/* 0x00: PWM configuration register */
	uint32_t volatile PWMCFG;
#define PWM_PWMCFG_PWMSCALE(x)			((x) << 0)
#define PWM_PWMCFG_PWMSTICKY			(1u << 8)
#define PWM_PWMCFG_PWMZEROCMP			(1u << 9)
#define PWM_PWMCFG_PWMDEGLITCH			(1u << 10)
#define PWM_PWMCFG_PWMENALWAYS			(1u << 12)
#define PWM_PWMCFG_PWMENONESHOT			(1u << 13)
#define PWM_PWMCFG_PWMCMP0CENTER		(1u << 16)
#define PWM_PWMCFG_PWMCMP1CENTER		(1u << 17)
#define PWM_PWMCFG_PWMCMP2CENTER		(1u << 18)
#define PWM_PWMCFG_PWMCMP3CENTER		(1u << 19)
#define PWM_PWMCFG_PWMCMP0GANG			(1u << 24)
#define PWM_PWMCFG_PWMCMP1GANG			(1u << 25)
#define PWM_PWMCFG_PWMCMP2GANG			(1u << 26)
#define PWM_PWMCFG_PWMCMP3GANG			(1u << 27)
#define PWM_PWMCFG_PWMCMP0IP			(1u << 28)
#define PWM_PWMCFG_PWMCMP1IP			(1u << 29)
#define PWM_PWMCFG_PWMCMP2IP			(1u << 30)
#define PWM_PWMCFG_PWMCMP3IP			(1u << 31)

	/* 0x04 */
	uint8_t volatile RESERVED0[0x08-0x04];

	/* 0x08: PWM count register */
	uint32_t volatile PWMCOUNT;
#define PWM_PWMCOUNT_PWMCOUNT(x)		((x) << 0)

	/* 0x0C */
	uint8_t volatile RESERVED1[0x10-0x0C];

	/* 0x10: Scaled PWM count register */
	uint32_t volatile PWMS;

	/* 0x14 */
	uint8_t volatile RESERVED2[0x20-0x14];

	/* 0x20: PWM compare register */
	uint32_t volatile PWMCMP[4];

};
