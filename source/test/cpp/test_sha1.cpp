#include "cbase/c_target.h"
#include "cbase/c_runes.h"
#include "ccrypto/c_cipher_engine.h"

#include "cunittest/xunittest.h"

using namespace ncore;

UNITTEST_SUITE_BEGIN(sha1_t)
{
	UNITTEST_FIXTURE(encrypt)
	{
		UNITTEST_FIXTURE_SETUP() {}
		UNITTEST_FIXTURE_TEARDOWN() {}
	}
}
UNITTEST_SUITE_END
