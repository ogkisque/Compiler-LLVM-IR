#ifndef PRINT_HEADER
#define PRINT_HEADER

#include <stdio.h>
#include <stdint.h>

#include "tree.h"
#include "error.h"

const char* const LLVM_HEADER      = "declare i32 @__isoc99_scanf(i8* noundef, ...)\n"
                                     "declare i32 @printf(i8* noundef, ...)\n\n"
                                     "@.str = private unnamed_addr constant [4 x i8] c\"%%lf\\00\", align 1\n"
                                     "@.str.1 = private unnamed_addr constant [5 x i8] c\"%%lf\\0A\\00\", align 1\n\n";
const char* const LLVM_FUNC_HEADER = "define dso_local double @";
const char* const LLVM_MAIN_HEADER = "define dso_local i32 @";
const char* const LLVM_CALL_SCANF  = "call i32 (i8*, ...) @__isoc99_scanf(i8* noundef getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i64 0, i64 0), double* noundef %%%sp)\n";
const char* const LLVM_CALL_PRINTF = "call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([5 x i8], [5 x i8]* @.str.1, i64 0, i64 0), double noundef %%%d)\n";
const int         SIZE_NUM_STR     = 12;
const int         MAX_NUM_VARS     = 1000;

Error   print_funcs                 (const Functions* funcs, FILE* file);
Error   print_header                (FILE* file);
Error   print_func_decl             (Function* func, IfWhileId* if_while_id, FILE* file);
Error   print_args                  (const Node* node, Function* func, FILE* file);
Error   print_args_store            (const Node* node, int* alloc_vars, Function* func, FILE* file);
Error   print_commands              (const Node* node, IfWhileId* if_while_id, int* alloc_vars, Function* func, FILE* file);
Error   print_input_output_return   (const Node* node, int* alloc_vars, bool* is_print, Function* func, FILE* file);
Error   print_assign                (const Node* node, bool* is_print, int* alloc_vars, Function* func, FILE* file);
Error   print_expression            (const Node* node, Function* func, int* var, FILE* file);
Error   print_func_call             (const Node* node, int* var, Function* func, FILE* file);
Error   print_args_call             (const Node* node, int num_var, Function* func, FILE* file);
Error   print_args_call_load        (const Node* node, Function* func, FILE* file);
Error   print_if                    (const Node* node, IfWhileId* if_while_id, bool* is_print, int* alloc_vars, Function* func, FILE* file);
Error   print_while                 (const Node* node, IfWhileId* if_while_id, bool* is_print, int* alloc_vars, Function* func, FILE* file);
int     get_num_var                 (const char* name);
void    print_store_num_reg         (FILE* file, double num, int reg);
void    print_load_reg_reg          (FILE* file, int reg1, int reg2);
void    print_load_reg_var          (FILE* file, int reg, const char* var);
void    print_store_reg_reg         (FILE* file, int reg1, int reg2);
void    print_store_reg_var         (FILE* file, int reg, const char* var);
void    print_store_var_var         (FILE* file, const char* var1, const char* var2);
void    print_alloca_reg            (FILE* file, int reg);
void    print_alloca_var            (FILE* file, const char* var);

#endif //PRINT_HEADER
