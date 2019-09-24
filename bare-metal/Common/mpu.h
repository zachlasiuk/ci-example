/*
** Copyright (c) 2017 Arm Limited (or its affiliates). All rights reserved.
** Use, modification and redistribution of this file is subject to your possession of a
** valid End User License Agreement for the Arm Product of which these examples are part of 
** and your compliance with all applicable terms and conditions of such licence agreement.
*/

#ifndef MPU_H_
#define MPU_H_

/* MAIR Attribute descriptors */
#define MAIR_DEVICE_NgNrNe   0x00
#define MAIR_NORMAL_WB_NT    0xFF
#define MAIR_NORMAL_WT       0xDD

/* Region Permissions */

#define XN               1 /* Execute Never, fault on all instruction fetches */

#define P_RW            (0 << 1)
#define P_RW_U_RW       (1 << 1)
#define P_RO            (2 << 1)
#define P_RO_U_RO       (3 << 1)

/* Shareability */
#define NON_SHAREABLE   (0 << 3)
#define OUTER_SHAREABLE (2 << 3)
#define INNER_SHAREABLE (3 << 3)

/* Region enablement */
#define REGION_ENABLED   1

#define BAR_VAL(base, flags) ((((unsigned int) base) &~0x1Fu) | flags)
#define RLAR_VAL(base, attrIndx, flags) (((((unsigned int) base)+ 0x1Fu) &~0x1Fu) | (attrIndx  << 1) | flags)


#endif /* MPU_H_ */
