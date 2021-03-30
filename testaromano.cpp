#include "romano.hpp"
#include "gtest/gtest.h"

namespace{
    TEST(testa_valores, valores_basicos){
        EXPECT_EQ(valores('I'), 1);
        EXPECT_EQ(valores('V'), 5);
        EXPECT_EQ(valores('X'), 10);
        EXPECT_EQ(valores('L'), 50);
        EXPECT_EQ(valores('C'), 100);
        EXPECT_EQ(valores('D'), 500);
        EXPECT_EQ(valores('M'), 1000);
    }
    TEST(testa_valores, valores_validos){
        EXPECT_EQ(validar("DXXVI"), 526);
        EXPECT_EQ(validar("DCCLXXVII"), 777);
        EXPECT_EQ(validar("XIX"), 19);
        EXPECT_EQ(validar("CMXCIX"), 999);
        EXPECT_EQ(validar("CCCLXXXIX"), 389);
        EXPECT_EQ(validar("CDXCVII"), 497);
        EXPECT_EQ(validar("MMDCXLIX"), 2649);
    }
    TEST(converter_arabico, valores_invalido) {
        EXPECT_EQ(validar("CCXCIVI"), -1);
        EXPECT_EQ(validar("XXXX"), -1);
        EXPECT_EQ(validar("MMMI"), -1);
        EXPECT_EQ(validar("LL"), -1);
        EXPECT_EQ(validar("XM"), -1);
        EXPECT_EQ(validar("xiv"), -1);
        EXPECT_EQ(validar("IIIIIIIIIIIIIIIIIIIIIIIIIIIIIII"), -1);
        EXPECT_EQ(validar("LUI"), -1);
    }
}