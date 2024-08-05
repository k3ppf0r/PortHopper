#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <openssl/ssl.h>
#include <openssl/err.h>

typedef enum {
    SSL_MODE_SERVER,
    SSL_MODE_CLIENT
} SSL_MODE;

typedef struct {  
    int data;  
    SSL *ssl; 
} ThreadArgs;

// Function declarations
SSL* sync_initialize_ssl(const char* cert_path, const char* key_path, SSL_MODE mode, int fd);
SSL_CTX* init_openssl(void);
void cleanup_openssl(SSL_CTX *ctx);
SSL* create_ssl_connection(SSL_CTX *ctx, int socket);
int ssl_read(SSL *ssl, void *buf, int num);
int ssl_write(SSL *ssl, const void *buf, int num);

#endif /* ENCRYPTION_H */
