#ifndef __CCRYPTO_CIPHER_AES_H__
#define __CCRYPTO_CIPHER_AES_H__
#include "ccore/c_target.h"
#ifdef USE_PRAGMA_ONCE
#pragma once
#endif

#include "ccore/c_allocator.h"
#include "ccore/c_stream.h"

namespace ncore
{
    class encryption_t;
    encryption_t* g_create_aes256_encryption(alloc_t* allocator, reader_t* key, u32 key_len);

    class decryption_t;
    decryption_t* g_create_aes256_decryption(alloc_t* allocator, reader_t* key, u32 key_len);
}

#endif	// __CCRYPTO_CIPHER_AES_H__
