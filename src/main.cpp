
#include <iostream>
#include <fstream>
#include <string>
#include <openssl/evp.h>
#include <openssl/rand.h>

bool encrypt(const std::string &plaintext, std::string &ciphertext, const std::string &key) {
    unsigned char iv[16];
    if (!RAND_bytes(iv, sizeof(iv))) return false;

    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx) return false;

    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, (const unsigned char*)key.data(), iv) != 1) {
        EVP_CIPHER_CTX_free(ctx);
        return false;
    }

    std::string buffer(plaintext.size() + EVP_CIPHER_block_size(EVP_aes_256_cbc()), '\0');
    int out_len1 = 0;
    if (EVP_EncryptUpdate(ctx, (unsigned char*)&buffer[0], &out_len1, (const unsigned char*)plaintext.data(), plaintext.size()) != 1) {
        EVP_CIPHER_CTX_free(ctx);
        return false;
    }

    int out_len2 = 0;
    if (EVP_EncryptFinal_ex(ctx, (unsigned char*)&buffer[0] + out_len1, &out_len2) != 1) {
        EVP_CIPHER_CTX_free(ctx);
        return false;
    }

    EVP_CIPHER_CTX_free(ctx);
    ciphertext = std::string((char*)iv, sizeof(iv)) + buffer.substr(0, out_len1 + out_len2);
    return true;
}

int main() {
    std::string masterKey;
    std::getline(std::cin, masterKey);

    std::string site, password;
    std::getline(std::cin, site);
    std::getline(std::cin, password);

    std::string to_encrypt = "Site: " + site + "\nParola: " + password + "\n";
    std::string encrypted;

    if (encrypt(to_encrypt, encrypted, masterKey)) {
        std::ofstream out("vault.defter", std::ios::binary | std::ios::app);
        out.write(encrypted.data(), encrypted.size());
        out.close();
        std::cout << "✅\n";
    } else {
        std::cout << "❌\n";
    }

    return 0;
}
