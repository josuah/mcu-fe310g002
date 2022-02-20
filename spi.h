#include <stddef.h>
#include <stdint.h>
#include <binary.h>

#define SPI1 ((struct zmcu_spi *)0x10024000)
#define SPI2 ((struct zmcu_spi *)0x10034000)

struct zmcu_spi {

	/* 0x00: Serial clock divisor */
	uint32_t volatile SCKDIV;

	/* 0x04: Serial clock mode */
	uint32_t volatile SCKMODE;
#define SPI_SCKMODE_PHA				(1u << 0)
#define SPI_SCKMODE_POL				(1u << 1)

	/* 0x08 */
	uint8_t volatile RESERVED0[0x10-0x08];

	/* 0x10: Chip select ID */
	uint32_t volatile CSID;

	/* 0x14: Chip select default */
	uint32_t volatile CSDEF;

	/* 0x18: Chip select mode */
	uint32_t volatile CSMODE;

	/* 0x1C */
	uint8_t volatile RESERVED1[0x28-0x1C];

	/* 0x28: Delay control */
	uint32_t volatile DELAY[2];
#define SPI_DELAY0_CSSCK(x)			((x) << 0)
#define SPI_DELAY0_SCKCS(x)			((x) << 16)
#define SPI_DELAY1_INTERCS(x)			((x) << 0)
#define SPI_DELAY1_INTERXFR(x)			((x) << 16)

	/* 0x30 */
	uint8_t volatile RESERVED2[0x40-0x30];

	/* 0x40: Frame format */
	uint32_t volatile FMT;

	/* 0x44 */
	uint32_t volatile RESERVED3;

	/* 0x48: Tx FIFO Data */
	uint32_t volatile TXDATA;
#define SPI_TXDATA_DATA(x)			((x) << 0)
#define SPI_TXDATA_FULL				(1u << 31)

	/* 0x4C: Rx FIFO data */
	uint32_t volatile RXDATA;
#define SPI_RXDATA_DATA(x)			((x) << 0)
#define SPI_RXDATA_EMPTY			(1u << 31)

	/* 0x50: Tx FIFO watermark */
	uint32_t volatile TXMARK;

	/* 0x54: Rx FIFO watermark */
	uint32_t volatile RXMARK;

	/* 0x58 */
	uint8_t volatile RESERVED4[0x60-0x58];

	/* 0x60: SPI flash interface control* */
	uint32_t volatile FCTRL;
#define SPI_FCTRL_EN				(1u << 0)

	/* 0x64: SPI flash instruction format* */
	uint32_t volatile FFMT;
#define SPI_FFMT_CMD_EN				(1u << 0)
#define SPI_FFMT_ADDR_LEN(x)			((x) << 1)
#define SPI_FFMT_PAD_CNT(x)			((x) << 4)
#define SPI_FFMT_CMD_PROTO(x)			((x) << 8)
#define SPI_FFMT_ADDR_PROTO(x)			((x) << 10)
#define SPI_FFMT_DATA_PROTO(x)			((x) << 12)
#define SPI_FFMT_CMD_CODE(x)			((x) << 16)
#define SPI_FFMT_PAD_CODE(x)			((x) << 24)

	/* 0x68 */
	uint8_t volatile RESERVED5[0x70-0x68];

	/* 0x70: SPI interrupt enable */
	uint32_t volatile IE;
#define SPI_IE_TXWM				(1u << 0)
#define SPI_IE_RXWM				(1u << 1)
#define SPI_IP_TXWM				(1u << 0)
#define SPI_IP_RXWM				(1u << 1)

	/* 0x74: SPI interrupt pending */
	uint32_t volatile IP;

};
