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

		virtual void		encrypt(xbyte* cipher, u32 inLength) = 0;
		virtual void		decrypt(xbyte* cipher, u32 inLength) = 0;
	};
}

#endif	///< __XCRYPTO_CIPHER_ENGINE_H__
