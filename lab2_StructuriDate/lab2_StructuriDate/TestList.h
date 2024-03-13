#pragma once
class TestList {
public:
	void test_push_back();
	void test_get_at();
	void test_update();
	void test_delete();
	void testAll()
	{
		test_push_back();
		test_get_at();
		test_update();
		test_delete();

	}
};
