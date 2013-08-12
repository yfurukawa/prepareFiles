/*
 * testMain.cpp
 *
 *  Created on: 2013/02/23
 *      Author: furukawayoshihiro
 */

#include <gtest/gtest.h>

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
