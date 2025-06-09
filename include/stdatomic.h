/*
 * Custom stdatomic.h implementation for Unikraft
 */

#ifndef _STDATOMIC_H
#define _STDATOMIC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Basic atomic types */
typedef int atomic_int;

/* Basic atomic operations */
#define atomic_store(ptr, val) (*(ptr) = (val))
#define atomic_load(ptr) (*(ptr))
#define atomic_compare_exchange_strong(ptr, expected, desired) \
    (*(expected) == (*(ptr)) ? (*(ptr) = (desired), 1) : (*(expected) = *(ptr), 0))
#define atomic_compare_exchange_weak atomic_compare_exchange_strong

/* Memory order not supported in this basic implementation */
typedef enum {
    memory_order_relaxed,
    memory_order_consume,
    memory_order_acquire,
    memory_order_release,
    memory_order_acq_rel,
    memory_order_seq_cst
} memory_order;

#ifdef __cplusplus
}
#endif

#endif /* _STDATOMIC_H */
