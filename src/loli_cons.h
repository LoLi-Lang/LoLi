/*
 * =====================================================================================
 *
 *       Filename:  loli_cons.h
 *
 *    Description:  Functions of operating cons
 *
 *        Version:  1.0
 *        Created:  04/05/2014 02:15:01 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef __LOLI_CONS_
#define __LOLI_CONS_

#ifndef __LOLI_TYPES_
#include "loli_types.h"
#endif

extern loliObj cons(loliObj hd, loliObj tl);
extern loliObj head(loliObj cons);
extern loliObj tail(loliObj cons);

#endif
