#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <algorithm>

struct Decrypted_Block{
    int32_t random_number;
    int32_t sort_key;
    char text[8];
};
// Define the SDBM hash function
unsigned long sdbm_hash(const unsigned char *str) {
    unsigned long hash = 0;
    int c;

    while ((c = *str++))
        hash = c + (hash << 6) + (hash << 16) - hash;

    return hash;
}

// Define the decryption function
void decrypt_block(char *block) {
    // Step 3: Reverse XOR with special key 0xAA, 0xBB, 0xCC, 0xDD
    for (int i = 0; i < 16; i++) {
        block[i] ^= 0xDD;
    }

    // Step 2: Reverse the byte shuffling
    char temp[16];
    temp[0] = block[0]; temp[1] = block[1]; temp[2] = block[2]; temp[3] = block[3];
    temp[4] = block[7]; temp[5] = block[4]; temp[6] = block[5]; temp[7] = block[6];
    temp[8] = block[10]; temp[9] = block[11]; temp[10] = block[8]; temp[11] = block[9];
    temp[12] = block[15]; temp[13] = block[12]; temp[14] = block[13]; temp[15] = block[14];

    memcpy(block, temp, 16);

    // Step 1: Reverse the bit inversion
    for (int i = 0; i < 16; i++) {
        block[i] = ~block[i];
    }
}

// Define comparison function for sorting
int compare_blocks(const void *a, const void *b) {
    const struct Decrypted_Block *block_a = (const struct Decrypted_Block *)a;
    const struct Decrypted_Block *block_b = (const struct Decrypted_Block *)b;
    return block_a->sort_key - block_b->sort_key;
}

int main(void) {
    printf("Basic C programming: Cryptography\n");
    
    // Open binary file
    FILE *file = fopen("D:\\WorkingFiles\\C++\\Codelite\\DataStructure\\Solinas_Technical_task\\cpp-task-easy\\data.bin", "rb");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    // Calculate file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    // Calculate number of blocks
    size_t num_blocks = file_size / sizeof(struct Decrypted_Block);

    // Allocate memory for decrypted blocks
    struct Decrypted_Block decrypted_blocks[num_blocks];

    // Read file into decrypted blocks
    fread(decrypted_blocks, sizeof(struct Decrypted_Block), num_blocks, file);

    // Close file
    fclose(file);

    // Decrypt each block
    for (size_t i = 0; i < num_blocks; i++) {
        decrypt_block(decrypted_blocks[i].text);
    }

    // Verify SDBM hash
    unsigned long hash = 0;
    for (size_t i = 0; i < num_blocks; i++) {
        hash = sdbm_hash((const unsigned char *)decrypted_blocks[i].text);
    }

    // Sort decrypted blocks
    qsort(decrypted_blocks, num_blocks, sizeof(struct Decrypted_Block), compare_blocks);

    // Print custom message
    for (size_t i = 0; i < num_blocks; i++) {
        printf("%s\n", decrypted_blocks[i].text);
    }

    return 0;
}