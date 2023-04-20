#include <stdint.h>
#include <stdio.h>

#include "../rijndael.h"

#define KEYBITS 128

unsigned long rk[RKLENGTH(KEYBITS)];
int nrounds;
uint8_t key[16];

extern void RunTarget(FILE *input) {
  // TODO Read test case and execute target primitive

  // Everything in this function is traced.

  // Avoid calling a library's debug output functionality outside clear error
  // conditions: These functions can produce _a lot_ of trace entries and, as
  // they are almost certainly not constant-time, they may also generate a
  // considerable number of false positives. printf() and others I/O
  // functionality from the C standard library are _usually_ fine, as this
  // library is skipped during the analysis by default.
  //
  //
  //
  //
  uint8_t in[16];
  uint8_t ciphertext[16];
  
  if (fread(in, 1, 16, input) != 16)
    return;
    
    rijndaelEncrypt(rk, nrounds, in, ciphertext);
}

extern void InitTarget(FILE *input) {
  // TODO Initialize library

  // This function is called once before running the first test case.
  // In some scenarios, especially if there isn't a dedicated initialization
  // function, it is best to just run the first test case, which is why this
  // method receives a file handle for the first test case file:
  // RunTarget(input);

  // You should really avoid that a part of the library gets initialized late,
  // as this may generate false positives.
  //

  nrounds = rijndaelSetupEncrypt(rk, key, KEYBITS);
  if (fread(key, 1, 16, input) != 16)
    return;

}
