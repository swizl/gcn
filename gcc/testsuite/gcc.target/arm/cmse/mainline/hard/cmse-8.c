/* { dg-do compile } */
/* { dg-options "-mcmse -mfloat-abi=hard -mfpu=fpv5-d16" }  */
/* { dg-skip-if "Do not combine float-abi= hard | soft | softfp" {*-*-*} {"-mfloat-abi=soft" -mfloat-abi=softfp } {""} } */
/* { dg-skip-if "Skip these if testing single precision" {*-*-*} {"-mfpu=*-sp-*"} {""} } */

#include "../../cmse-8.x"

/* Checks for saving and clearing prior to function call.  */
/* { dg-final { scan-assembler "lsrs\tr4, r4, #1" } } */
/* { dg-final { scan-assembler "lsls\tr4, r4, #1" } } */
/* { dg-final { scan-assembler "mov\tr0, r4" } } */
/* { dg-final { scan-assembler "mov\tr1, r4" } } */
/* { dg-final { scan-assembler "mov\tr2, r4" } } */
/* { dg-final { scan-assembler "mov\tr3, r4" } } */
/* { dg-final { scan-assembler-not "vldr\.64\td0, .L" } } */
/* { dg-final { scan-assembler "vldr\.64\td1, .L" } } */
/* { dg-final { scan-assembler "vldr\.64\td2, .L" } } */
/* { dg-final { scan-assembler "vldr\.64\td3, .L" } } */
/* { dg-final { scan-assembler "vldr\.64\td4, .L" } } */
/* { dg-final { scan-assembler "vldr\.64\td5, .L" } } */
/* { dg-final { scan-assembler "vldr\.64\td6, .L" } } */
/* { dg-final { scan-assembler "vldr\.64\td7, .L" } } */

/* Now we check that we use the correct intrinsic to call.  */
/* { dg-final { scan-assembler "bl\t__gnu_cmse_nonsecure_call" } } */
