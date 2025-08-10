#ifndef __CCRYPTO_ENCRYPTION_H__
#define __CCRYPTO_ENCRYPTION_H__
#include "ccore/c_target.h"
#ifdef USE_PRAGMA_ONCE
#    pragma once
#endif

#include "ccore/c_stream.h"

namespace ncore
{
    class alloc_t;

    class encryption_t;

    encryption_t* g_create_aes256_encryption(alloc_t* allocator, reader_t* key, u32 key_len);

    void g_encrypt_begin(encryption_t*, u32 total_src_len, writer_t* dst);
    void g_encrypt_block(encryption_t*, reader_t* src, u32 src_len, writer_t* dst);
    void g_encrypt_final(encryption_t*, writer_t* dst);

}  // namespace ncore

#endif  // __CCRYPTO_ENCRYPTION_H__
