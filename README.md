# Original Rijndael Implementation

A C implementation of the Rijndael Encryption Algorithm using T-Tables.

## Usage

This package is in the public domain and has no restrictions on use. It can be compiled as either C or C++ and can be used in any C environment.

## Installation

1. Clone the repository.
2. Building the program: The project uses a Makefile for building the program. To build the program, navigate to the directory containing the Makefile and run the `make` command.
3. The encryption program is called as follows: `encrypt  password  cryptofile`.
It encrypts the standard input (padding it with spaces, if necessary), and writes the result to the specified cryptofile.
4. The decryption program is called as follows: `decrypt  password  cryptofile`.
It decrypts the cryptofile contents and sends the result (padded with spaces, if necessary) to the standard output.
5. To build the timecop test run the `make test` command.
6. To clean the project and remove all object files and executables, run the command: `make clean`.

## Setting up the encryption/decryption buffer

To perform Rijndael encryption or decryption, first set up a buffer for encryption or decryption:
 ```c
// for encryption
nrounds = rijndaelSetupEncrypt(rk, key, keybits);

// for decryption
nrounds = rijndaelSetupDecrypt(rk, key, keybits);  

/*
pointer to encryption/decryption buffer, required space:                          
    keybits  32-bit words required                             
    128      44                                                
    192      52                                                
    256      60
*/
unsigned long *rk;                      

/*
key, where length in bytes is:
    keybits  number of bytes
    128      16
    192      24
    256      32
*/
const unsigned char *key;

// number of bits in key, must be 128, 192 or 256
int keybits;

/*
number of rounds:
    keybits  nrounds
    128      10
    192      12
    256      14
*/
int nrounds;

```

## Functionality

- AES encryption and decryption
- Support for 128-bit, 192-bit, and 256-bit keys

## Original Authors

- Vincent Rijmen vincent.rijmen@esat.kuleuven.ac.be
- Antoon Bosselaers antoon.bosselaers@esat.kuleuven.ac.be
- Paulo Barreto paulo.barreto@terra.com.br

## Modified by

- Philip J. Erdelsky

## Date

- September 3, 2002


Source: http://www.efgh.com/software/rijndael.htm
