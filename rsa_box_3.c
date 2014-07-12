#include "config.h"
#include <gmp.h>
void rsa_partial_box_3(m, r, g)
MP_INT* m, * r;
MP_INT* g;
{
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
    /* real_j is 0, bit 56 is 0 */
    X(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    Y(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    /* real_j is 0, bit 57 is 0 */
    X(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    Y(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    SWAP(0, 0);
    SWAP(1, 0);
    SWAP(2, 2);
    /* real_j is 1, bit 58 is 0 */
    Y(&m[0], &r[0], g);
    X(&m[2], &r[2], g);
    X(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    /* real_j is 1, bit 59 is 1 */
    Y(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    Y(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    SWAP(0, 0);
    SWAP(1, 1);
    SWAP(2, 0);
    /* real_j is 1, bit 60 is 0 */
    X(&m[0], &r[0], g);
    Y(&m[2], &r[2], g);
    Y(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    SWAP(0, 0);
    SWAP(1, 1);
    SWAP(2, 0);
    /* real_j is 1, bit 61 is 0 */
    Y(&m[0], &r[0], g);
    X(&m[2], &r[2], g);
    X(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    /* real_j is 1, bit 62 is 1 */
    Y(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    Y(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    /* real_j is 1, bit 63 is 1 */
    X(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    X(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    /* real_j is 1, bit 64 is 1 */
    X(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    X(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    /* real_j is 1, bit 65 is 0 */
    X(&m[0], &r[0], g);
    X(&m[2], &r[2], g);
    X(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    /* real_j is 1, bit 66 is 0 */
    Y(&m[0], &r[0], g);
    X(&m[2], &r[2], g);
    X(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    /* real_j is 1, bit 67 is 1 */
    Y(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    X(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    /* real_j is 1, bit 68 is 0 */
    X(&m[0], &r[0], g);
    X(&m[2], &r[2], g);
    Y(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    SWAP(0, 0);
    SWAP(1, 1);
    SWAP(2, 1);
    /* real_j is 2, bit 69 is 0 */
    Y(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    X(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    /* real_j is 2, bit 70 is 1 */
    Y(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    X(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    /* real_j is 2, bit 71 is 0 */
    X(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    Y(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    /* real_j is 2, bit 72 is 0 */
    Y(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    X(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    SWAP(0, 0);
    SWAP(1, 0);
    SWAP(2, 1);
    /* real_j is 1, bit 73 is 0 */
    Y(&m[0], &r[0], g);
    Y(&m[2], &r[2], g);
    X(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    SWAP(0, 0);
    SWAP(1, 1);
    SWAP(2, 0);
}
