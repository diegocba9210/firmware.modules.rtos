/* Copyright 2016, Gerardo Puga (UNLP)
 *
 * This file is part of CIAA Firmware.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef _SPARC_ARCH_H_
#define _SPARC_ARCH_H_

/** \brief SPARC Architecture Support Header File
 **
 ** \file sparc/Sparc_Arch.h
 ** \arch sparc
 **/

/** \addtogroup FreeOSEK
 ** @{ */
/** \addtogroup FreeOSEK_Os
 ** @{ */
/** \addtogroup FreeOSEK_Os_Internal
 ** @{ */

/*==================[inclusions]=============================================*/


#include "Types_Arch.h"


/*==================[macros]=================================================*/

/** \brief Bit mask for the PIL field in the PSR register */
#define SPARC_PSR_PIL_MASK 0x0f00


/** \brief Bit mask for the ET bit in the PSR register */
#define SPARC_PSR_ET_MASK  0x0020


/** \brief Bit mask for the CWP field in the PSR register */
#define SPARC_PSR_CWP_MASK 0x001f


/** \brief Amount of bytes to reserve on a thread's stack in order to store its integer context information.
 *
 * For alignments reasons this number must be a multiple of 8 (double word).
 */
#define SPARC_STACK_BARE_MINIMUM_STACK_FRAME_RESERVATION_SIZE 92


/** \brief Amount of bytes to reserve on a thread's stack in order to store its integer context information.
 *
 * For alignments reasons this number must be a multiple of 8 (double word).
 */
#define SPARC_STACK_BASE_CONTEXT_RESERVATION_SIZE 80


/** \brief Amount of bytes to reserve on a thread's stack in order to store its floating point context information.
 *
 * For alignments reasons this number must be a multiple of 8 (double word).
 * */
#define SPARC_STACK_FP_CONTEXT_RESERVATION_SIZE 0

#define SPARC_SYSCALL_SERVICE_SW_TRAP_NUMBER              0x00
#define SPARC_CALL_DEBUGGER_SW_TRAP_NUMBER                0x01
#define SPARC_SET_TASK_CONTEXT_SERVICE_SW_TRAP_NUMBER     0x02
#define SPARC_REPLACE_TASK_CONTEXT_SERVICE_SW_TRAP_NUMBER 0x03

#define SPARC_SYSCALL_ID_DISABLE_TRAPS 0x00
#define SPARC_SYSCALL_ID_MASK_INTR     0x01
#define SPARC_SYSCALL_ID_UNMASK_INTR   0x02
#define SPARC_SYSCALL_ID_REBOOT_SYSTEM 0x03

#define SPARC_CALL_DEBUGGER { asm("   flush\n\t nop\n\t nop\n\t nop\n\t nop\n\t nop\n\t nop\n ta 1\n\t nop\n\t nop\n\t nop\n\t nop\n\t nop\n\t nop\n" ); }

#define sparcAssert(assertion, errorString) { if(!(assertion)) { SPARC_CALL_DEBUGGER; } }


/*==================[typedef]================================================*/


/*==================[external data declaration]==============================*/


/*==================[external functions declaration]=========================*/


/*
 * Syscall service functions, defined in syscallservices.s
 * */

void sparcSystemServiceEnableTraps();

void sparcSystemServiceDisableTraps();

void sparcSystemServiceMaskInterrupts();

void sparcSystemServiceUnMaskInterrupts();

void sparcSystemServiceRebootSystem();

void sparcSystemServiceCallDebugger();

void sparcSystemServiceTriggerReplaceTaskContext();

void sparcSystemServiceTriggerSetTaskContext();


/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/
#endif /* #ifndef _OS_INTERNAL_ARCH_H_ */

