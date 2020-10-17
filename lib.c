#include <ether/ether.h>

#include <endian.h>

#define DEF(FN)                                         \
  static eth_t                                          \
  _##FN(void)                                           \
  {                                                     \
    eth_args args = eth_start(1);                       \
    eth_t x = eth_arg2(args, eth_number_type);          \
    eth_return(args, eth_num(FN(eth_num_val(x)))); \
  }

DEF(htobe16);
DEF(htobe32);
DEF(htobe64);

DEF(htole16);
DEF(htole32);
DEF(htole64);

DEF(be16toh);
DEF(be32toh);
DEF(be64toh);

DEF(le16toh);
DEF(le32toh);
DEF(le64toh);

int
ether_module(eth_module *mod)
{
#define EXPORT(FN) eth_define(mod, #FN, eth_proc(_##FN, 1))

  EXPORT(htobe16);
  EXPORT(htobe32);
  EXPORT(htobe64);

  EXPORT(htole16);
  EXPORT(htole32);
  EXPORT(htole64);

  EXPORT(be16toh);
  EXPORT(be32toh);
  EXPORT(be64toh);

  EXPORT(le16toh);
  EXPORT(le32toh);
  EXPORT(le64toh);

  return 0;
}
