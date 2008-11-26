#include "common.h"
#include "nstring.h"
#include "mem.h"

struct nstring {
    uint32_t len;
    char data[];
};

nstring_t *ns_alloc (const void *data, uint32_t len) {
    nstring_t *ns = nbd_malloc(sizeof(nstring_t) + len);
    ns->len = len;
    memcpy(ns->data, data, len);
    return ns;
}

int ns_cmp_raw (nstring_t *ns, const void *data, uint32_t len) {
    int rc = memcmp(ns->data, data, (len < ns->len) ? len : ns->len);
    return (rc == 0) ? ns->len - len : rc;
}

const void *ns_data (nstring_t *ns) { return ns->data; }

uint64_t    ns_len  (nstring_t *ns) { return ns->len; }
