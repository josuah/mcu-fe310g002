#include <stddef.h>
#include <stdint.h>
#include <binary.h>

#define PRCI ((struct sdk_pcri *)0x10008000)

struct sdk_pcri {

	/* 0x00: Ring Oscillator Configuration and Status */
	uint32_t volatile HFROSCCFG;
#define PRCI_HFROSCCFG_HFROSCDIV(x)		((x) << 0)
#define PRCI_HFROSCCFG_HFROSCTRIM(x)		((x) << 16)
#define PRCI_HFROSCCFG_HFROSCEN			(1u << 30)
#define PRCI_HFROSCCFG_HFROSCRDY		(1u << 31)

	/* 0x04: Crystal Oscillator Configuration and Status */
	uint32_t volatile HFXOSCCFG;
#define PRCI_HFXOSCCFG_HFXOSCEN			(1u << 30)
#define PRCI_HFXOSCCFG_HFXOSCRDY		(1u << 31)

	/* 0x08: PLL Configuration and Status */
	uint32_t volatile PLLCFG;
#define PRCI_PLLCFG_PLLR(x)			((x) << 0)
#define PRCI_PLLCFG_PLLF(x)			((x) << 4)
#define PRCI_PLLCFG_PLLQ(x)			((x) << 10)
#define PRCI_PLLCFG_PLLSEL			(1u << 16)
#define PRCI_PLLCFG_PLLREFSEL			(1u << 17)
#define PRCI_PLLCFG_PLLBYPASS			(1u << 18)
#define PRCI_PLLCFG_PLLLOCK			(1u << 31)

	/* 0x0C: PLL Final Divide Configuration */
	uint32_t volatile PLLOUTDIV;
#define PRCI_PLLOUTDIV_PLLOUTDIV(x)		((x) << 0)
#define PRCI_PLLOUTDIV_PLLOUTDIVBY1(x)		((x) << 8)

	/* 0xF0: Process Monitor Configuration and Status */
	uint32_t volatile PROCMONCFG;

};
