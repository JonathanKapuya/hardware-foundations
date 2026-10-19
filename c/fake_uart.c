//clang -Wall -Wextra -g -fsanitize=address fake_uart.c -o fake_uart && ./fake_uart

/*

Fake UART, a UART transmits bits one by one

A uart uses three variables, the ctrl switch says if its literally off or on, the status says if it is ready to recieve the next bit
When sending a byte, the code makes sure the byte before is fully sent. Then, the uart's data field is set to the current byte, and status
is turned to not ready. This runs on repeat until all the data is transmitted.

Learned define for consts. Uppercase.
Learned typedef struct where you can define variables inside a type, the type's name, and initiate it using {0} to indicate all fields start at 0.

&u: the & means send the pointer to the address of the actual uart_t, rather than a copy. Methods directly manipulate.
u->data accesses the data field in the uart_t.
In the methods *u means it is recieving the actual address so compiler knows.

*/

#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#define UART_READY (1u << 0)
#define UART_ENABLE (1u << 0)



typedef struct {

    uint32_t ctrl;
    volatile uint32_t status;
    uint32_t data;

} uart_t;

void uart_init (uart_t *t) {

    //set both to bit 0 on to indicate enabled.
    t->ctrl |= UART_ENABLE;
    t->status |= UART_READY;

}

int uart_ready(uart_t *t) {

    //if status ready returns not 0, else returns 0
    return t->status & UART_READY;

}

void fake_hw_step(uart_t *u) {

    if(u->status != UART_READY) {
        printf("%c", u->data);
        u->status = UART_READY;
    }

}

void uart_send(uart_t *u, uint8_t byte) {

    while(u->status != UART_READY) {

        fake_hw_step(u);

    }

    u-> data = byte;
    u->status &= ~UART_READY;

}

int main() {

    uart_t u = {0};
    uart_init(&u);
    uart_send(&u, 'H');
    uart_send(&u, 'i');
    uart_send(&u, '!');
    uart_send(&u, '\n');
    fake_hw_step(&u);
    return 0;

}




