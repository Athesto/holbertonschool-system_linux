#include "hls.h"
/**
 * globals - use static variable to create a global structure
 * Return: pointer to static structure
 */
global_t *globals(void)
{
	static global_t globals;

	return (&globals);
}
