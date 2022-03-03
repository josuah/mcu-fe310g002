#include <stddef.h>
#include <stdint.h>
#include <binary.h>

#define UART0 ((struct sdk_uart *)0x10013000)
#define UART1 ((struct sdk_uart *)0x10023000)

struct sdk_uart {

	/* 0x00: Transmit data register */
	uint32_t volatile TXDATA;
#define UART_TXDATA_DATA(x)			((x) << 0)
#define UART_TXDATA_FULL			(1u << 31)

	/* 0x04: Receive data register */
	uint32_t volatile RXDATA;
#define UART_RXDATA_DATA(x)			((x) << 0)
#define UART_RXDATA_EMPTY			(1u << 31)

	/* 0x08: Transmit control register */
	uint32_t volatile TXCTRL;
#define UART_TXCTRL_TXEN			(1u << 0)
#define UART_TXCTRL_NSTOP			(1u << 1)
#define UART_TXCTRL_TXCNT(x)			((x) << 16)

	/* 0x0C: Receive control register */
	uint32_t volatile RXCTRL;
#define UART_RXCTRL_RXEN			(1u << 0)
#define UART_RXCTRL_RXCNT(x)			((x) << 16)

	/* 0x10: UART interrupt enable */
	uint32_t volatile IE;
#define UART_IE_TXWM				(1u << 0)
#define UART_IE_RXWM				(1u << 1)

	/* 0x14: UART interrupt pending */
	uint32_t volatile IP;
#define UART_IP_TXWM				(1u << 0)
#define UART_IP_RXWM				(1u << 1)

	/* 0x18: Baud rate divisor */
	uint32_t volatile DIV;

};
