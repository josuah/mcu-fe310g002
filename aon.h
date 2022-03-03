#include <stddef.h>
#include <stdint.h>
#include <binary.h>

#define AON ((struct sdk_aon *)0x10000000)

struct sdk_aon {

	/* 0x000: wdog Configuration */
	uint32_t volatile WDOGCFG;
#define AON_WDOGCFG_WDOGSCALE(x)		((x) << 0)
#define AON_WDOGCFG_WDOGRSTEN			(1u << 8)
#define AON_WDOGCFG_WDOGZEROCMP			(1u << 9)
#define AON_WDOGCFG_WDOGENALWAYS		(1u << 12)
#define AON_WDOGCFG_WDOGCOREAWAKE		(1u << 13)
#define AON_WDOGCFG_WDOGIP0			(1u << 28)

	/* 0x008: Counter Register */
	uint32_t volatile WDOGCOUNT;

	/* 0x010: Scaled value of Counter */
	uint32_t volatile WDOGS;

	/* 0x018: Feed register */
	uint32_t volatile WDOGFEED;

	/* 0x01C: Key Register */
	uint32_t volatile WDOGKEY;

	/* 0x020: Comparator */
	uint32_t volatile WDOGCMP;
#define AON_WDOGCMP0_WDOGCMP0(x)		((x) << 0)

	/* 0x040: rtc Configuration */
	uint32_t volatile RTCCFG;
#define AON_RTCCFG_RTCENALWAYS			(1u << 12)
#define AON_RTCCFG_RTCIP0			(1u << 28)

	/* 0x048: Low bits of Counter */
	uint32_t volatile RTCCOUNTLO;

	/* 0x04C: High bits of Counter */
	uint32_t volatile RTCCOUNTHI;

	/* 0x050: Scaled value of Counter */
	uint32_t volatile RTCS;

	/* 0x060: Comparator */
	uint32_t volatile RTCCMP;

	/* 0x070: Ring Oscillator Configuration and Status */
	uint32_t volatile LFROSCCFG;
#define AON_LFROSCCFG_LFROSCDIV(x)		((x) << 0)
#define AON_LFROSCCFG_LFROSCTRIM(x)		((x) << 16)
#define AON_LFROSCCFG_LFROSCEN			(1u << 30)
#define AON_LFROSCCFG_LFROSCRDY			(1u << 31)
#define AON_LFCLKMUX_LFEXTCLK_SEL		(1u << 0)
#define AON_LFCLKMUX_LFEXTCLK_MUX_STATUS	(1u << 31)

	/* 0x07C: Low-Frequency Clock Mux Control and Status */
	uint32_t volatile LFCLKMUX;

	/* 0x080: Backup Register */
	uint32_t volatile BACKUP[16];

	/* 0x100: Wakeup program instruction */
	uint32_t volatile PMUWAKEUPI[8];

	/* 0x120: Sleep program instruction */
	uint32_t volatile PMUSLEEPI[8];
#define AON_SLEEP_WAKEUP_DELAY(x)		((x) << 0)
#define AON_SLEEP_WAKEUP_PMU_OUT_0_EN		(1u << 4)
#define AON_SLEEP_WAKEUP_PMU_OUT_1_EN		(1u << 5)
#define AON_SLEEP_WAKEUP_CORERST		(1u << 7)
#define AON_SLEEP_WAKEUP_HFCLKRST		(1u << 8)
#define AON_SLEEP_WAKEUP_ISOLATE		(1u << 9)

	/* 0x140: PMU Interrupt Enables */
	uint32_t volatile PMUIE;

	/* 0x144: PMU Wakeup Cause */
	uint32_t volatile PMUCAUSE;

	/* 0x148: Initiate PMU Sleep Sequence */
	uint32_t volatile PMUSLEEP;

	/* 0x14C: PMU Key. Reads as 1 when PMU is unlocked */
	uint32_t volatile PMUKEY;

	/* 0x210: Bandgap configuration */
	uint32_t volatile SIFIVEBANDGAP;

	/* 0x300: AON Block Configuration Information */
	uint32_t volatile AONCFG;
};
