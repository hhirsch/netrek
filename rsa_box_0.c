#include "config.h"
#include <gmp.h>
void rsa_partial_box_0(m, r, g)
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
    /* real_j is 0, bit 0 is 1 */
    X(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    Y(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    /* real_j is 0, bit 1 is 0 */
    X(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    Y(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    /* real_j is 0, bit 2 is 0 */
    Y(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    Y(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    SWAP(0, 0);
    SWAP(1, 0);
    SWAP(2, 0);
    /* real_j is 1, bit 3 is 0 */
    Y(&m[0], &r[0], g);
    X(&m[2], &r[2], g);
    X(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    SWAP(0, 0);
    SWAP(1, 0);
    SWAP(2, 2);
    /* real_j is 0, bit 4 is 0 */
    X(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    Y(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    /* real_j is 0, bit 5 is 1 */
    X(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    Y(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    /* real_j is 0, bit 6 is 1 */
    X(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    Y(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    /* real_j is 0, bit 7 is 0 */
    X(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    Y(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    SWAP(0, 0);
    SWAP(1, 0);
    SWAP(2, 2);
    /* real_j is 1, bit 8 is 1 */
    Y(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    Y(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    /* real_j is 1, bit 9 is 1 */
    Y(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    Y(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    /* real_j is 1, bit 10 is 0 */
    X(&m[0], &r[0], g);
    Y(&m[2], &r[2], g);
    Y(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    SWAP(0, 0);
    SWAP(1, 0);
    SWAP(2, 2);
    /* real_j is 0, bit 11 is 0 */
    Y(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    Y(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    /* real_j is 0, bit 12 is 1 */
    X(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    Y(&m[0], &r[0], g);
    X(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    /* real_j is 0, bit 13 is 1 */
    X(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    X(&m[2], &r[2], g);
    Y(&m[0], &r[0], g);
    Y(&m[1], &r[1], g);
    Y(&m[2], &r[2], g);
    SWAP(0, 0);
    SWAP(1, 1);
    SWAP(2, 0);
}
