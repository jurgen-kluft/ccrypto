/**
 * @file x_cipher_engine.h
 *
 * Core Cipher Engine
 */

// x_cipher_engine.h - Core Cipher Engine - 
#ifndef __XCRYPTO_CIPHER_ENGINE_H__
#define __XCRYPTO_CIPHER_ENGINE_H__
#include "xbase/x_target.h"
#ifdef USE_PRAGMA_ONCE
#pragma once
#endif


namespace xcore
{
	class xcipher_engine
	{
	public:
		virtual void		reset() = 0;

		virtual void		initialize(reader_t* key, u32 key_len) = 0;

		virtual void		encrypt_begin(u32 total_src_len, writer_t* dst) = 0;
		virtual void		encrypt_block(reader_t* src, u32 src_len, writer_t* dst) = 0;
		virtual void		encrypt_final(writer_t* dst) = 0;

		virtual void		decrypt_begin(u32 total_src_len) = 0;
		virtual void		decrypt_block(reader_t* src, u32 src_len, writer_t* dst) = 0;
		virtual void		decrypt_final(writer_t* dst) = 0;
	};
}

#endif	///< __XCRYPTO_CIPHER_ENGINE_H__
