#include "xbase/x_target.h"
#include "xbase/x_runes.h"
#include "xcrypto/x_cipher_engine.h"

#include "xunittest/xunittest.h"

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
