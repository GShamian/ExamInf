#include <cxxtest/TestSuite.h>
#include <stdexcept>
#include "stdfx.h"


class VectorTestSuite : public CxxTest::TestSuite {
    public:
        /**
         * Test constructors for initialisation.
         */
        void test_init()
        {
            UIntVector a(0);
            TS_ASSERT(a.size() == 0);
            UIntVector b(1);
            TS_ASSERT(b.size() == 1);
            UIntVector c(123);
            TS_ASSERT(c.size() == 123);

            UIntVector d(c);
            TS_ASSERT(d.size() == c.size());
            UIntVector e = c;
            TS_ASSERT(e.size() == c.size());

            UIntVector f(3);
            TS_ASSERT(f[0] == 0);
            TS_ASSERT(f[1] == 0);
            TS_ASSERT(f[2] == 0);

            const UIntVector constA(10);
            TS_ASSERT(constA.size() == 10);
        }

        /**
         * Test assignment
         */
        void test_assign()
        {
            UIntVector a(10);
            a[0] = 1;
            a[9] = 2;
            UIntVector b = a;
            TS_ASSERT(b[0] == 1);
            TS_ASSERT(b[9] == 2);

            UIntVector c(5);
            c[1] = 3;
            c[2] = 4;
            int x = c[1];
            int y = c[2];
            TS_ASSERT(x == 3);
            TS_ASSERT(y == 4);

            UIntVector d(10);
            d[5] = 10;
            d[5]++;
            TS_ASSERT(d[5] == 11);
        }

        /**
         * Test resetting.
         */
        void test_reset()
        {
            UIntVector a(5);
            for (unsigned int i = 0; i < a.size(); ++i)
                a[i] = i;
            a.reset();
            for (unsigned int i = 0; i < a.size(); ++i)
                TS_ASSERT(a[i] == 0);
        }

        /**
         * Test the add functionality.
         */
        void test_add()
        {
            UIntVector a(13);
            a.add(5);
            TS_ASSERT_EQUALS(a[13], (unsigned int) 5);
            TS_ASSERT_EQUALS(a[10], (unsigned int) 0);

            UIntVector b(a);
            TS_ASSERT_EQUALS(b[13], (unsigned int) 5);
            TS_ASSERT_EQUALS(b[9], (unsigned int) 0);

            a.add(17);
            TS_ASSERT_EQUALS(a[14], (unsigned int) 17);
            TS_ASSERT_THROWS(b[14], std::out_of_range);

            UIntVector c(0);
            c.add(1);
            c.add(2);
            c.add(3);
            TS_ASSERT_EQUALS(c[1], (unsigned int) 2);
            c[0] = 5;
            TS_ASSERT_EQUALS(c[0], (unsigned int) 5);
        }

        /**
         * Test copy.
         */
        void test_copy_op()
        {
            UIntVector a(5);
            a[2] = (unsigned int) 3;
            UIntVector b(7);
            b = a;
            TS_ASSERT_EQUALS(b[2], (unsigned int) 3);
            TS_ASSERT_EQUALS(a[2], (unsigned int) 3);
            TS_ASSERT(b.size() == 5);

            a.add(19);
            TS_ASSERT_THROWS(b[5],std::out_of_range);

            a[2] = (unsigned int) 4;
            TS_ASSERT_EQUALS(b[2], (unsigned int) 3);
            TS_ASSERT_EQUALS(a[2], (unsigned int) 4);

            b[2] = (unsigned int) 5;
            TS_ASSERT_EQUALS(b[2], (unsigned int) 5);
            TS_ASSERT_EQUALS(a[2], (unsigned int) 4);
        }

        /**
         * Self copy test.
         */
        void test_copy_self()
        {
            UIntVector a(4);
            a[1] = 8;
            a = a;
            TS_ASSERT(a[1] == 8);
            TS_ASSERT(a[0] == 0);
        }

        void test_initializer_list() {
            UIntVector a({4,5,6});
            TS_ASSERT(a.size() == 3);
            TS_ASSERT(a[0] == 4);
            TS_ASSERT(a[1] == 5);
            TS_ASSERT(a[2] == 6);
        }

        /**
         * Test copy assignment where the array sizes differ.
         */
        void test_copy_assign_diffsize()
        {
            UIntVector a(5);
            a[4] = 1;
            UIntVector b(2);
            b = a;
            TS_ASSERT(b[4] == 1);

            UIntVector c(12);
            c[10] = 2;
            UIntVector d(20);
            d[19] = 3;
            d[10] = 4;
            c = d;
            TS_ASSERT(c[19] == 3);
            TS_ASSERT(c[10] == 4);
        }

        /**
         * Test going out-of-bounds.
         */
        void test_index_except()
        {
            UIntVector a(5);
            const UIntVector b(1);
            TS_ASSERT_THROWS(a[5] = 1, std::out_of_range);
            TS_ASSERT_THROWS(b[2], std::out_of_range);
        }

        /**
         * Test constructing vector with const size_t
         */
        void test_const_size()
        {
            const size_t s = 17;
            UIntVector a(s);
            TS_ASSERT_EQUALS(a.size(), (std::size_t) 17);
        }

        // shouldn't compile
//        void test_stuff()
//        {
//            std::size_t n = 24;
//            UIntVector a(1);
//            a = n;
//            TS_ASSERT(a.size() != n);
//            UIntVector b = n;
//            TS_ASSERT(b.size() != n);
//        }

        /**
         *
         */
        void test_mem_leak()
        {
            UIntVector v(20);
            for(unsigned int i = 0; i < 100000; ++i)
                v.add(i);
            TS_ASSERT_EQUALS(v.size(), (std::size_t) 100020);
            UIntVector u = std::move(v);
            v = u;
            UIntVector * w = new UIntVector(7);
            delete w;

            UIntVector a(123232);
            a = v;

            UIntVector b(2);
            a.reset();
            b = std::move(a);
        }

        /**
         * Test to add over the internal capacity.
         */
        void test_add_lots()
        {
            UIntVector a(0); // Should default to internal size 10
            for (int i = 0; i < 20; ++i)
                a.add(i);

            TS_ASSERT(a[9] == 9);
            TS_ASSERT(a[10] == 10);
            TS_ASSERT(a[15] == 15);
            TS_ASSERT(a[19] == 19);
        }
};
