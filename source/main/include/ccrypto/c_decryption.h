#ifndef __CCRYPTO_DECRYPTION_H__
#define __CCRYPTO_DECRYPTION_H__
#include "ccore/c_target.h"
#ifdef USE_PRAGMA_ONCE
#    pragma once
#endif

#include "ccore/c_stream.h"

namespace ncore
{
    class alloc_t;
    class decryption_t;

    void g_decrypt_begin(decryption_t*, u32 total_src_len);
    void g_decrypt_block(decryption_t*, reader_t* src, u32 src_len, writer_t* dst);
    void g_decrypt_final(decryption_t*, writer_t* dst);

}  // namespace ncore

#endif  // __CCRYPTO_CIPHER_ENGINE_H__
