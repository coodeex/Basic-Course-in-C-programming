### Task 8.6: XOR cipher (20 pts)

**Objective:** to get familiar with bitwise operation with longer data types.

Implement function **confidentiality_xor** that gets a 32-bit encryption key ('key')
as argument, the encrypted data ('data') along with its length ('len') as arguments.
The length is indicated as the number of 32-bit blocks the data contains.
The function should implement a simple encryption: each 32-bit data buffer will
be encrypted using the XOR-bitwise operation using the encryption key.
The function does not need to allocate memory, i.e., it operates on the data
buffer directly. **Note:** the data should be handled as 32-bit unsigned
integers (`uint32_t` data type in stdint.h header). More information
in [Wikipedia](https://en.wikipedia.org/wiki/XOR_cipher).

Implement also function **confidentiality_xor_shift** that, in addition to
encrypting the data, will modify the encryption key after each 32-bit block.
The function works otherwise similarly as the above one, but after each operation
it shifts the bits in the key one step left. At each shift, the most significant
(leftmost) bit it transferred to the other end, i.e. to represent the least
significant (rightmost) bit.
The modified key will be used on next encryption block, after which it is
again modified, and so on.
