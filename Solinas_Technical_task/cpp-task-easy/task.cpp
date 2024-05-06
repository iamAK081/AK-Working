
//
// Intro to Cryptography:
//
// In cryptography, 2 main things are done with the data
// 1. Encryption / Decryption of data
// 2. Summary of data
//
// Note: Data compression and decompression is not considered
// to be a part of cryptography.
//

//
// Encryption / Decryption of data
//
// Encryption of data is done using 2 methods
// 1. Symmetric key i.e., using a single key (known to the user)
// 2. Asymmetric key i.e., using a public key (known to public) 
//    and a private key (known to the user)
// 
// For symmetric key encryption, is done by 2 methods
// 1. Block cipher - ex. AES algorithm
// 2. Stream cipher
// Symmetric key encryption is typically used to encrypt large files.
// 
// Asymmetric key encryption uses 2 keys (public and private) to 
// encrypt data. Ex. RSA, ECC. They are used to encrypt web traffic 
// whenever we connect to any secured website (ex. HTTPS), server etc.
// The keys are typically exchanged between 2 computers using 
// Diffie-Hellman algorithm.
//

//
// Summary of data
//
// Hash functions or checksums are used to provide a fixed length
// summary of an arbitrary size data. Ex. SHA-256, CRC, MD5 etc.
// They are typically designed to generate a unique signature for
// the data. They are used to make sure that no one has tampered
// with the data.
//

//
// For more information: 
//
// https://www.youtube.com/playlist?list=PLBLfn3l3FkMsTGK-WFXRDjPb98_NDEo8P
// https://www.youtube.com/playlist?list=PLIvL2PgyB2oxDePrTzFF6YdQ9lQh9CC8G
//

// 
// Task: Decrypting custom message (Easy - max. 2 hrs)
// 
// In this task, you are given an encrypted message in "data.bin" file. 
// Your job is to decrypt this message and print the text. 
//
// File contents:
// 
// The first 4 bytes of the "data.bin" file contains the SDBM hash of the 
// decrypted message. The rest of the bytes in the file contain the encrypted 
// message.
//
// Encryption method:
// 
// Each 16 bytes after the initial 4 byte hash is an encrypted block. Each block
// is encrypted as follows (similar to AES encryption, with custom modifications)
// 
// Let a00, a01, ... a15 be the bytes of the original decrypted message.
// 
// 1. The bits of each byte are inverted, i.e., Ex. 0b00001111 -> 0b11110000, to
//    get new bytes b00, b01, ... b15.
// 2. The bytes are shuffled as follows
//    
//    b00, b01, b02, b03           b00, b01, b02, b03
//    b04, b05, b06, b07   ---\    b05, b06, b07, b04
//    b08, b09, b10, b11   ---/    b10, b11, b08, b09
//    b12, b13, b14, b15           b15, b12, b13, b14
// 3. Each byte in a row is bitwise XOR'd to a special key 0xAA, 0xBB, 0xCC, 0xDD, i.e, 
//   
//   b00, b01, b02, b03  (XOR)  0xAA, 0xBB, 0xCC, 0xDD
//   b05, b06, b07, b04  (XOR)  0xAA, 0xBB, 0xCC, 0xDD
//   b10, b11, b08, b09  (XOR)  0xAA, 0xBB, 0xCC, 0xDD
//   b15, b12, b13, b14  (XOR)  0xAA, 0xBB, 0xCC, 0xDD
// 
// Steps to complete task:
// 1. Decrypt each block by reversing the steps taken for encryption.
// 2. Verify the correctness of the decryption by computing
//    the SDBM hash (zero initialized) of the entire decrypted message.
// 3. Sort the decrypted block according to the sort key (check structs below).
// 4. Print the text of each decrypted block (after sorting) to reveal a
//    custom message for you.
// 5. Email back the solution (this file), along with a screenshot of the 
//    custom message.
// Note: If you have any doubts reach out to me at rahul@solinas.in

struct Decrypted_Block{
    int32_t random_number;
    int32_t sort_key;
    char text[8];
};

#include<stdio.h>

int main(void){
    printf("Basic C programming: Cryptography\n");
    
    // TODO: Load file to memory
    
    // TODO: Decrypt message
    
    // TODO: Verify SDBM hash (zero initialized)
    
    // TODO: Sort decrypted message
    
    // TODO: Print custom message - text of all decrypted blocks after sorting
    
}