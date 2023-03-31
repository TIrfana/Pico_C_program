//
// Created by Thilras Irfana on 9/3/23.
//
#include "aes.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#include "pico/stdlib.h"



/*function declaration*/
void AES_init_ctx(struct AES_ctx* ctx, const uint8_t* key);
void AES_ECB_encrypt(const struct AES_ctx* ctx, uint8_t* buf);

int main(){

    stdio_init_all(); //Initialise I/O
    //initialise trigger 
    gpio_init(16);
    gpio_set_dir(16, GPIO_OUT);
    gpio_put(25, 0); // Set pin 25 to low
    uint8_t key[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06,
                     0x07};
    struct AES_ctx ctx;
    /*context calling AES encryption*/
    AES_init_ctx(&ctx, key);
    char rand_bytes[16]; // array to generate PT

    while (1){

        size_t bytes_read = fread(rand_bytes, 1, sizeof(rand_bytes), stdin);
        if (bytes_read == 16) {
            //printf(rand_bytes);
            gpio_put(16, 1);
            AES_ECB_encrypt(&ctx, rand_bytes);
            gpio_put(16, 0);
        }

        printf(rand_bytes);

    }

}

