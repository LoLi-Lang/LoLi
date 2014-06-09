/*
 * =====================================================================================
 *
 *       Filename:  loli.h
 *
 *    Description:  Headers of LoLi
 *
 *        Version:  1.0
 *        Created:  05/04/2014 05:28:39 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef __LOLI_HEADER_
#define __LOLI_HEADER_

#include "loli_types.h"
#include "loli_symbols.h"
#include "loli_cons.h"
#include "loli_prim.h"
#include "loli_list.h"
#include "loli_ast.h"
#include "loli_output.h"
#include "loli_env.h"
#include "loli_repl.h"
#include "loli_read.h"
#include "loli_parser.h"
#include "loli_apply.h"
#include "loli_cbmi.h"
#include "loli_eval.h"
#include "loli_parser.h"
#include "loli_gui.h"
#include "loli_lambda.h"
#include "loli_def.h"
#include "loli_file.h"
#include "loli_set.h"

static loliObj* top_env = cons(nil, nil);

#endif
