#ifndef __CCRYPTO_CIPHER_AES_H__
#define __CCRYPTO_CIPHER_AES_H__
#include "ccore/c_target.h"
#ifdef USE_PRAGMA_ONCE
#pragma once
#endif

namespace ncore
{
    class alloc_t;
    class cipher_t;

    cipher_t* gCreateAESCipher(alloc_t* allocator, const char * key, u32 key_size);
}

#endif	// __CCRYPTO_CIPHER_AES_H__
