#include "config.h"
#include <gmp.h>
void rsa_partial_box_4(m, r, g)
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
    /* real_j is 1, bit 78 is 1 */
    Y(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    X(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    /* real_j is 1, bit 79 is 0 */
    Y(&m[0], &r[0], g);
    X(&m[2], &r[2], g);
    Y(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    SWAP(0, 0);
    SWAP(1, 1);
    SWAP(2, 1);
    /* real_j is 2, bit 80 is 1 */
    X(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    X(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    /* real_j is 2, bit 81 is 1 */
    Y(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    X(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    /* real_j is 2, bit 82 is 0 */
    X(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    X(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    /* real_j is 2, bit 83 is 0 */
    Y(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    Y(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    /* real_j is 2, bit 84 is 0 */
    X(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    X(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    /* real_j is 2, bit 85 is 0 */
    X(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    Y(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    /* real_j is 2, bit 86 is 0 */
    X(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    Y(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    SWAP(0, 0);
    SWAP(1, 1);
    SWAP(2, 2);
    /* real_j is 2, bit 87 is 0 */
    Y(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    Y(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    /* real_j is 2, bit 88 is 1 */
    Y(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    X(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    /* real_j is 2, bit 89 is 1 */
    Y(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    Y(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    /* real_j is 2, bit 90 is 1 */
    X(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    X(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    /* real_j is 2, bit 91 is 0 */
    Y(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    X(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    /* real_j is 2, bit 92 is 1 */
    Y(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    X(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    SWAP(0, 0);
    SWAP(1, 0);
    SWAP(2, 1);
}
