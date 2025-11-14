//used stm32f401ve controller

#include "stm32f401xe.h"

int main(void)
{

    RCC->AHB1ENR |= (1 << 4); // RCC_APB2ENR_IOPAEN(or using this instead of 1<<4)  //giving clock to the gpio peripheralsgiv
                              // This is macro present in header file.
    GPIOE->MODER &= ~(3 << (14 * 2));   //first clearing the bits
    GPIOE->MODER |=  (1 << (14 * 2));   //enabling the bits as output (28 and 29 with 0 1)

    while (1)
    {
        // 3. LED ON
        GPIOE->BSRR = (1 << 14);
        for (volatile int i = 0; i < 1000000; i++);

        // 4. LED OFF
        GPIOE->BSRR = (1 << (14 + 16));
        for (volatile int i = 0; i < 1000000; i++);
    }
}
