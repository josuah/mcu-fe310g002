#include <stddef.h>
#include <stdint.h>
#include <binary.h>

#define I2C0 ((struct sdk_i2c *)0x10016000)

struct sdk_i2c {

	/* 0x00: Clock Prescale register */
	uint16_t volatile PRER;
#define I2C_PRER_EN				(1u << 7)
#define I2C_PRER_IEN				(1u << 6)
 
	/* 0x02: Control register */
	uint8_t volatile CTR;

	/* 0x03: Transmit register */
	uint8_t volatile TXR;

	/* 0x03: Receive register */
	uint8_t volatile RXR;

	/* 0x04: Command and Status Register */
	uint8_t volatile CSR;
#define I2C_CR_STA				(1u << 7)
#define I2C_CR_STO				(1u << 6)
#define I2C_CR_RD				(1u << 5)
#define I2C_CR_WR				(1u << 4)
#define I2C_CR_ACK				(1u << 3)
#define I2C_CR_IACK				(1u << 0)
#define I2C_SR_RXACK				(1u << 7)
#define I2C_SR_BUSY				(1u << 6)
#define I2C_SR_TIP				(1u << 1)
#define I2C_SR_IF				(1u << 0)

};
