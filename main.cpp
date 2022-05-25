#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

#include <conio.h>
#include <io.h>
#include <fcntl.h>
#include <stdlib.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>

#include<stdio.h>
#include<windows.h>

#include "src/generate.hpp"

int main(int argc, char **argv){

system("cls");


    RSA * rsa = NULL;
    static unsigned char passphrase[] = "0123456789";
    int keySize = 2048;
    int keyExponent = 65537;
    BIGNUM *bn;
    /* контекст алгоритма шифрования */
	const EVP_CIPHER *cipher = NULL;
    bn = BN_new();
    BN_set_word(bn, keyExponent);
    rsa = RSA_new();
    /* Генерируем ключи */
    RSA_generate_key_ex(rsa, keySize, bn, nullptr);
    FILE* fp = fopen("private.key", "w");
    FILE * privKey_file = fopen("public.key", "w");
    FILE * pubKey_file = fopen("public.key", "wb");
    cipher = EVP_get_cipherbyname("bf-ofb");
    PEM_write_RSAPrivateKey(fp, rsa, EVP_des_ede3_cbc(), passphrase, 10, nullptr, nullptr);
    //PEM_write_RSAPrivateKey(fp, rsa, cipher, passphrase, 10, nullptr, nullptr);
    PEM_write_RSAPublicKey(pubKey_file, rsa);

    RSA_free(rsa);
	fclose(privKey_file);
	fclose(pubKey_file);
	std::cout << "Ключи сгенерированы и помещены в папку с исполняемым файлом" << std::endl;

    generate gn;
    gn.initkeis();
   

    return 0;
}
