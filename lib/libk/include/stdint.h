#ifndef LIBK_STDINT_H_
# define LIBK_STDINT_H_

/* Integral types. */

/* Signed. */
typedef signed char				int8_t;
typedef short int				int16_t;
typedef int						int32_t;
typedef long long int			int64_t;

/* Unsigned. */
typedef unsigned char			uint8_t;
typedef unsigned short int		uint16_t;
typedef unsigned int			uint32_t;
typedef unsigned long long int 	uint64_t;

/* Pointer types. */
typedef int						intptr_t;
typedef unsigned int			uintptr_t;


/* Limits for intregral types. */

/* Minimum signed */
# define INT8_MIN	(-127-1)
# define INT16_MIN	(-32767-1)
# define INT32_MIN	(-2147483647L-1)
# define INT64_MIN 	(-9223372036854775807LL-1)

/* Maximum signed */
# define INT8_MAX	(127)
# define INT16_MAX 	(32767)
# define INT32_MAX 	(2147483647L)
# define INT64_MAX 	(9223372036854775807LL)

/* Maximum unsigned */
# define UINT8_MAX	(255)
# define UINT16_MAX	(65535)
# define UINT32_MAX	(4294967295UL)
# define UINT64_MAX	(18446744073709551615ULL)

#endif /* !LIBK_STDINT_H_ */
