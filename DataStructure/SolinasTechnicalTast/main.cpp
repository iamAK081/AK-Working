
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


#include<stdio.h>
//Arul Changes
#include <stdint.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include<fstream>
#include<vector>

using namespace std;



struct Decrypted_Block {
    int32_t random_number;
    int32_t sort_key;
    char text[8];
};


void decryptBlock(char* block)
{
    // Reverse Step3. Each byte in a row is bitwise XOR'd to a special key 0xAA, 0xBB, 0xCC, 0xDD, i.e, 
    //   
    //  0xAA, 0xBB, 0xCC, 0xDD (XOR)  b00, b01, b02, b03
    //  0xAA, 0xBB, 0xCC, 0xDD (XOR)  b05, b06, b07, b04
    //  0xAA, 0xBB, 0xCC, 0xDD (XOR)  b10, b11, b08, b09
    //  0xAA, 0xBB, 0xCC, 0xDD (XOR)  b15, b12, b13, b14


    unsigned char special_key[4] = { 0xAA,0xBB,0xCC,0xDD };
    int key = 0;
    for (int i = 0; i < 16; i++)
    {
        block[i] ^= special_key[key++];
        if (key == 4)
            key = 0;
    }


    // Reverse Step2. The bytes are shuffled as follows
    //    
    //    (temp)                            (block)
    //   b00, b01, b02, b03              b00, b01, b02, b03
    //   b05, b06, b07, b04     ---\     b04, b05, b06, b07
    //   b10, b11, b08, b09     ---/     b08, b09, b10, b11
    //   b15, b12, b13, b14              b12, b13, b14, b15


    char temp[16];
    temp[0] = block[0]; temp[1] = block[1]; temp[2] = block[2]; temp[3] = block[3];
    temp[4] = block[7]; temp[5] = block[4]; temp[6] = block[5]; temp[7] = block[6];
    temp[8] = block[10]; temp[9] = block[11]; temp[10] = block[8]; temp[11] = block[9];
    temp[12] = block[15]; temp[13] = block[12]; temp[14] = block[13]; temp[15] = block[14];

    memcpy(block, temp, 16); // replace the blocks

    // Reverse Step1. The bits of each byte are inverted, i.e., Ex. 0b00001111 -> 0b11110000, to get new bytes b00, b01, ... b15.
    for (int i = 0; i < 16; i++)
    {
        block[i] = ~block[i];
    }
}


//  SDBM hash function 
/*the sdbm hash algorithm, which operates on byte strings.
Hash functions or checksums are used to provide a fixed length
summary of an arbitrary size data */


long sdbmHash(const char* str)
{
    long hash = 0;
    int c;

    while ((c = *str++))
    {
        hash = c + (hash << 6) + (hash << 16) - hash;
    }

    return hash;
}


void bubbleSort(Decrypted_Block arr[], int n) {
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i].sort_key > arr[i + 1].sort_key) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
}


// comparison function for quick sorting
int compareBlocks(const void* a, const void* b) {

    const Decrypted_Block* blockA = static_cast<const Decrypted_Block*>(a);
    const Decrypted_Block* blockB = static_cast<const Decrypted_Block*>(b);

    if (blockA->sort_key < blockB->sort_key) return -1;
    if (blockA->sort_key > blockB->sort_key) return 1;
    return 0;
}

int main(void) {
    printf("Basic C programming: Cryptography\n");


    // TODO: Load file to memory

    FILE* file;

    if (fopen_s(&file, "/cpp-task-easy/data.bin", "rb") != 0)
    {
        cout << "Error in opening file";
        return 1;
    }

    // hash count
        // Read the first 4 bytes
    long expected_hash_val;
    int hash_size = sizeof(expected_hash_val);
    fread((char*)(&expected_hash_val), hash_size, 1, file);
    fseek(file, hash_size, SEEK_SET);

   int numOfBlocks = 0;

    // Calculate file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);
    numOfBlocks = (file_size - sizeof(expected_hash_val)) / sizeof(Decrypted_Block);

    struct Decrypted_Block decrypted_blocks[numOfBlocks];

    fread(reinterpret_cast<char*>(decrypted_blocks), sizeof(Decrypted_Block), numOfBlocks, file);


    fclose(file);


    // TODO: Decrypt message
    for (int i = 0; i < numOfBlocks; i++) //block wise decrypting
    {
        decryptBlock(decrypted_blocks[i].text);
    }

    // TODO: Verify SDBM hash (zero initialized)

    //Verify the Sdbm Hash for each block
    long hash = 0;
    for (int i = 0; i < numOfBlocks; i++) {
        hash += sdbmHash(decrypted_blocks[i].text); // Accumulate hash value
    }

    //validate SDBM with hash count value
    if (hash != expected_hash_val)
    {
        cout << "Decryption failed: Hash Value mismatch\n";
       // delete[] decrypted_blocks; // Release allocated memory
        return 0;
    }
    else
    {
        cout << "Decryption Passed: Hash Value mismatch\n";
    }

    // TODO: Sort decrypted message


    //Generating random no(converting string to int )-- for sorting by using sorting key
    for (int i = 0; i < numOfBlocks; i++)
    {
        decrypted_blocks[i].random_number = 0;

        size_t len = strlen(decrypted_blocks[i].text);

        for (int j = 0; j < len; j++)
        {
            char c = decrypted_blocks[i].text[j];
            decrypted_blocks[i].random_number += int(c);
        }

        decrypted_blocks[i].sort_key = decrypted_blocks[i].random_number;
    }

    // std::qsort(decrypted_blocks, numOfBlocks, sizeof(struct Decrypted_Block), compareBlocks); // This is also work for large data

    bubbleSort(decrypted_blocks, numOfBlocks); //for small data , i am using bubble sort


    // TODO: Print custom message - text of all decrypted blocks after sorting
    // Print custom message
    for (int i = 0; i < numOfBlocks; i++)
    {
        cout << decrypted_blocks[i].text << endl;
    }

   
    // getchar();


    return 0;

}
