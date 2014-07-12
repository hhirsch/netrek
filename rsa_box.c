char key_name[] = "key.cow.linux";
char client_type[] = "Client Of Win";
char client_arch[] = "automatic packaged key";
char client_creator[] = "quozl@us.netrek.org";
char client_comments[] = "netrek.org/files/COW/";
char client_key_date[] = "July 2014";
/*
 * DO NOT EDIT THIS FILE!!! GENERATED AUTOMATICALLY!!!
 */
#include "config.h"
#include <stdio.h>
#include <gmp.h>

void rsa_black_box(out, in, public, global)
unsigned char* out;
unsigned char* in;
unsigned char* public;
unsigned char* global;
{
    MP_INT m_msg;
    MP_INT m_result;
    MP_INT m_public;
    MP_INT m_global;
    MP_INT m_tmp;
    int i;
    mpz_init(&m_msg);
    mpz_init(&m_result);
    mpz_init(&m_public);
    mpz_init(&m_global);
    mpz_init(&m_tmp);
    for (i = 0; i < 32; i++) {
        mpz_mul_2exp(&m_msg, &m_msg, 8);
	mpz_add_ui(&m_msg, &m_msg, in[32-1-i]);
    }
    mpz_mul_2exp(&m_global, &m_global, 32);
    mpz_add_ui(&m_global, &m_global, (unsigned LONG) 0x4ee48ca1);
    mpz_mul_2exp(&m_global, &m_global, 32);
    mpz_add_ui(&m_global, &m_global, (unsigned LONG) 0xe7da94f5);
    mpz_mul_2exp(&m_global, &m_global, 32);
    mpz_add_ui(&m_global, &m_global, (unsigned LONG) 0x11222bcb);
    mpz_mul_2exp(&m_global, &m_global, 32);
    mpz_add_ui(&m_global, &m_global, (unsigned LONG) 0x7c6e3547);
    mpz_mul_2exp(&m_global, &m_global, 32);
    mpz_add_ui(&m_global, &m_global, (unsigned LONG) 0xa17a56d0);
    mpz_mul_2exp(&m_global, &m_global, 32);
    mpz_add_ui(&m_global, &m_global, (unsigned LONG) 0x7dc1ad);
    mpz_mul_2exp(&m_global, &m_global, 32);
    mpz_add_ui(&m_global, &m_global, (unsigned LONG) 0xc08d9e22);
    mpz_mul_2exp(&m_global, &m_global, 32);
    mpz_add_ui(&m_global, &m_global, (unsigned LONG) 0xafaceae5);
    if (global != NULL) {
        global[0] = 229;
        global[1] = 234;
        global[2] = 172;
        global[3] = 175;
        global[4] = 34;
        global[5] = 158;
        global[6] = 141;
        global[7] = 192;
        global[8] = 173;
        global[9] = 193;
        global[10] = 125;
        global[11] = 0;
        global[12] = 208;
        global[13] = 86;
        global[14] = 122;
        global[15] = 161;
        global[16] = 71;
        global[17] = 53;
        global[18] = 110;
        global[19] = 124;
        global[20] = 203;
        global[21] = 43;
        global[22] = 34;
        global[23] = 17;
        global[24] = 245;
        global[25] = 148;
        global[26] = 218;
        global[27] = 231;
        global[28] = 161;
        global[29] = 140;
        global[30] = 228;
        global[31] = 78;
    }
    mpz_mul_2exp(&m_public, &m_public, 32);
    mpz_add_ui(&m_public, &m_public, (unsigned LONG) 0x17c29f94);
    mpz_mul_2exp(&m_public, &m_public, 32);
    mpz_add_ui(&m_public, &m_public, (unsigned LONG) 0xdc59418b);
    mpz_mul_2exp(&m_public, &m_public, 32);
    mpz_add_ui(&m_public, &m_public, (unsigned LONG) 0xaaab1b9e);
    mpz_mul_2exp(&m_public, &m_public, 32);
    mpz_add_ui(&m_public, &m_public, (unsigned LONG) 0x1a158f4a);
    mpz_mul_2exp(&m_public, &m_public, 32);
    mpz_add_ui(&m_public, &m_public, (unsigned LONG) 0xf3cba27f);
    mpz_mul_2exp(&m_public, &m_public, 32);
    mpz_add_ui(&m_public, &m_public, (unsigned LONG) 0x65bee5f6);
    mpz_mul_2exp(&m_public, &m_public, 32);
    mpz_add_ui(&m_public, &m_public, (unsigned LONG) 0xbb3c22d6);
    mpz_mul_2exp(&m_public, &m_public, 32);
    mpz_add_ui(&m_public, &m_public, (unsigned LONG) 0xe2381341);
    if (public != NULL) {
        public[0] = 65;
        public[1] = 19;
        public[2] = 56;
        public[3] = 226;
        public[4] = 214;
        public[5] = 34;
        public[6] = 60;
        public[7] = 187;
        public[8] = 246;
        public[9] = 229;
        public[10] = 190;
        public[11] = 101;
        public[12] = 127;
        public[13] = 162;
        public[14] = 203;
        public[15] = 243;
        public[16] = 74;
        public[17] = 143;
        public[18] = 21;
        public[19] = 26;
        public[20] = 158;
        public[21] = 27;
        public[22] = 171;
        public[23] = 170;
        public[24] = 139;
        public[25] = 65;
        public[26] = 89;
        public[27] = 220;
        public[28] = 148;
        public[29] = 159;
        public[30] = 194;
        public[31] = 23;
    }
{
    MP_INT r[3], m[3], m_swap_tmp;
    for (i = 0; i < 3; i++) {
        mpz_init_set_ui(&r[i], 1); mpz_init(&m[i]);
    }
    mpz_set(&m[0], &m_msg);
#define g &m_global
#define X(m, r, g) \
    mpz_mul(r, m, r);\
    mpz_mod(r, r, g)
#define Y(m, r, g) \
    mpz_mul(m, m, m);\
    mpz_mod(m, m, g)
#define SWAP(i, j) \
    do { \
        MP_INT tmp; \
        tmp = m[i]; m[i] = m[j]; m[j] = tmp; \
        tmp = r[i]; r[i] = r[j]; r[j] = tmp; \
    } while(0)
    rsa_partial_box_0(m, r, &m_global);
    /* real_j is 2, bit 14 is 1 */
    X(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    Y(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    SWAP(0, 0);
    SWAP(1, 0);
    SWAP(2, 2);
    /* real_j is 2, bit 15 is 1 */
    X(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    Y(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    /* real_j is 2, bit 16 is 0 */
    X(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    X(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    SWAP(0, 0);
    SWAP(1, 1);
    SWAP(2, 1);
    /* real_j is 1, bit 17 is 1 */
    Y(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    Y(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    rsa_partial_box_1(m, r, &m_global);
    /* real_j is 1, bit 34 is 1 */
    Y(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    X(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    SWAP(0, 0);
    SWAP(1, 1);
    SWAP(2, 2);
    /* real_j is 1, bit 35 is 1 */
    X(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    Y(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    SWAP(0, 0);
    SWAP(1, 1);
    SWAP(2, 1);
    /* real_j is 2, bit 36 is 0 */
    X(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    X(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    SWAP(0, 0);
    SWAP(1, 1);
    SWAP(2, 0);
    rsa_partial_box_2(m, r, &m_global);
    /* real_j is 0, bit 52 is 1 */
    X(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    Y(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    /* real_j is 0, bit 53 is 1 */
    X(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    Y(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    /* real_j is 0, bit 54 is 1 */
    X(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    Y(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    /* real_j is 0, bit 55 is 1 */
    X(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    Y(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    rsa_partial_box_3(m, r, &m_global);
    /* real_j is 1, bit 74 is 0 */
    Y(&m[0], &r[0], g);
    X(&m[2], &r[2], g);
    Y(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    /* real_j is 1, bit 75 is 1 */
    Y(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    Y(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    /* real_j is 1, bit 76 is 0 */
    Y(&m[0], &r[0], g);
    Y(&m[2], &r[2], g);
    X(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    SWAP(0, 0);
    SWAP(1, 1);
    SWAP(2, 2);
    /* real_j is 1, bit 77 is 1 */
    Y(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    Y(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    rsa_partial_box_4(m, r, &m_global);
    /* real_j is 1, bit 93 is 0 */
    X(&m[0], &r[0], g);
    Y(&m[2], &r[2], g);
    Y(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    /* real_j is 1, bit 94 is 0 */
    X(&m[0], &r[0], g);
    Y(&m[2], &r[2], g);
    X(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    SWAP(0, 0);
    SWAP(1, 0);
    SWAP(2, 1);
    /* real_j is 0, bit 95 is 0 */
    Y(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    Y(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    rsa_partial_box_5(m, r, &m_global);
    /* real_j is 0, bit 110 is 1 */
    X(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    Y(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    /* real_j is 0, bit 111 is 0 */
    Y(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    Y(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    SWAP(0, 0);
    SWAP(1, 0);
    SWAP(2, 1);
    /* real_j is 2, bit 112 is 0 */
    Y(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    X(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    SWAP(0, 0);
    SWAP(1, 0);
    SWAP(2, 2);
    /* real_j is 2, bit 113 is 0 */
    X(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    Y(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    SWAP(0, 0);
    SWAP(1, 1);
    SWAP(2, 2);
    rsa_partial_box_6(m, r, &m_global);
    /* real_j is 0, bit 126 is 1 */
    X(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    Y(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    /* real_j is 0, bit 127 is 0 */
    X(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    Y(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    /* real_j is 0, bit 128 is 0 */
    Y(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    Y(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    SWAP(0, 0);
    SWAP(1, 0);
    SWAP(2, 1);
    /* real_j is 2, bit 129 is 1 */
    X(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    X(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    /* real_j is 2, bit 130 is 0 */
    Y(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    X(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    SWAP(0, 0);
    SWAP(1, 1);
    SWAP(2, 2);
    /* real_j is 2, bit 131 is 0 */
    Y(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    X(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    SWAP(0, 0);
    SWAP(1, 0);
    SWAP(2, 2);
    /* real_j is 2, bit 132 is 0 */
    Y(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    Y(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    /* real_j is 2, bit 133 is 1 */
    X(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    Y(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    /* real_j is 2, bit 134 is 0 */
    X(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    Y(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    /* real_j is 2, bit 135 is 1 */
    Y(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    Y(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    SWAP(0, 0);
    SWAP(1, 1);
    SWAP(2, 1);

    mpz_set(&m_result, &r[1]);
    for (i = 0; i < 3; i++) {
        mpz_clear(&r[i]); mpz_clear(&m[i]);
    }
}
    for (i = 0; i < 32; i++) {
	mpz_divmod_ui(&m_result, &m_tmp, &m_result, 256);
	*out++ = mpz_get_ui(&m_tmp);
    }
    mpz_clear(&m_msg);
    mpz_clear(&m_result);
    mpz_clear(&m_public);
    mpz_clear(&m_global);
    mpz_clear(&m_tmp);
}