
#ifndef PHP_PHASHER_H
#define PHP_PHASHER_H

extern zend_module_entry phasher_module_entry;
#define phpext_phasher_ptr &phasher_module_entry

#define PHP_PHASHER_VERSION "0.1.0" /* Replace with version number for your extension */

#ifdef PHP_WIN32
#	define PHP_PHASHER_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_PHASHER_API __attribute__ ((visibility("default")))
#else
#	define PHP_PHASHER_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(phasher);
PHP_MSHUTDOWN_FUNCTION(phasher);
PHP_RINIT_FUNCTION(phasher);
PHP_RSHUTDOWN_FUNCTION(phasher);
PHP_MINFO_FUNCTION(phasher);

PHP_FUNCTION(confirm_phasher_compiled);	/* For testing, remove later. */

/* 
  	Declare any global variables you may need between the BEGIN
	and END macros here:     

ZEND_BEGIN_MODULE_GLOBALS(phasher)
	long  global_value;
	char *global_string;
ZEND_END_MODULE_GLOBALS(phasher)
*/

/* In every utility function you add that needs to use variables 
   in php_phasher_globals, call TSRMLS_FETCH(); after declaring other 
   variables used by that function, or better yet, pass in TSRMLS_CC
   after the last function argument and declare your utility function
   with TSRMLS_DC after the last declared argument.  Always refer to
   the globals in your function as PHASHER_G(variable).  You are 
   encouraged to rename these macros something shorter, see
   examples in any other php module directory.
*/

#ifdef ZTS
#define PHASHER_G(v) TSRMG(phasher_globals_id, zend_phasher_globals *, v)
#else
#define PHASHER_G(v) (phasher_globals.v)
#endif

#endif	/* PHP_PHASHER_H */

