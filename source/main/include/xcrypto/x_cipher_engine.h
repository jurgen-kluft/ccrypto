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

		virtual void		initialize(xreader* key, u32 key_len) = 0;

		virtual void		encrypt_begin(u32 total_src_len, xwriter* dst) = 0;
		virtual void		encrypt_block(xreader* src, u32 src_len, xwriter* dst) = 0;
		virtual void		encrypt_final(xwriter* dst) = 0;

		virtual void		decrypt_begin(u32 total_src_len) = 0;
		virtual void		decrypt_block(xreader* src, u32 src_len, xwriter* dst) = 0;
		virtual void		decrypt_final(xwriter* dst) = 0;
	};
}

#endif	///< __XCRYPTO_CIPHER_ENGINE_H__
