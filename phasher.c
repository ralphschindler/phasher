
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_phasher.h"

/* If you declare any globals in php_phasher.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(phasher)
*/

/* True global resources - no need for thread safety here */
static int le_phasher;

/* {{{ phasher_functions[]
 *
 * Every user visible function must have an entry in phasher_functions[].
 */
const zend_function_entry phasher_functions[] = {
	PHP_FE(confirm_phasher_compiled,	NULL)		/* For testing, remove later. */
	PHP_FE_END	/* Must be the last line in phasher_functions[] */
};
/* }}} */

/* {{{ phasher_module_entry
 */
zend_module_entry phasher_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"phasher",
	phasher_functions,
	PHP_MINIT(phasher),
	PHP_MSHUTDOWN(phasher),
	PHP_RINIT(phasher),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(phasher),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(phasher),
#if ZEND_MODULE_API_NO >= 20010901
	PHP_PHASHER_VERSION,
#endif
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_PHASHER
ZEND_GET_MODULE(phasher)
#endif

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("phasher.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_phasher_globals, phasher_globals)
    STD_PHP_INI_ENTRY("phasher.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_phasher_globals, phasher_globals)
PHP_INI_END()
*/
/* }}} */

/* {{{ php_phasher_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_phasher_init_globals(zend_phasher_globals *phasher_globals)
{
	phasher_globals->global_value = 0;
	phasher_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(phasher)
{
	/* If you have INI entries, uncomment these lines 
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(phasher)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(phasher)
{
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(phasher)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(phasher)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "phasher support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */


/* Remove the following function when you have successfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto string confirm_phasher_compiled(string arg)
   Return a string to confirm that the module is compiled in */
PHP_FUNCTION(confirm_phasher_compiled)
{
	char *arg = NULL;
	int arg_len, len;
	char *strg;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &arg, &arg_len) == FAILURE) {
		return;
	}

	len = spprintf(&strg, 0, "Congratulations! You have successfully modified ext/%.78s/config.m4. Module %.78s is now compiled into PHP.", "phasher", arg);
	RETURN_STRINGL(strg, len, 0);
}
/* }}} */
/* The previous line is meant for vim and emacs, so it can correctly fold and 
   unfold functions in source code. See the corresponding marks just before 
   function definition, where the functions purpose is also documented. Please 
   follow this convention for the convenience of others editing your code.
*/


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */