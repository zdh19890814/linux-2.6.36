/* This is an autogenerated file */
/* Tag: noCheckHeader */
/*    Copyright (C) Cambridge Silicon Radio Ltd 2009. All rights reserved. */
/* */
/*   Refer to LICENSE.txt included with this source for details on the */
/*   license terms. */

#ifndef SCAN_MANAGER_XML_TYPES_H
#define SCAN_MANAGER_XML_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum unifi_IECapabilityMask
{
    unifi_IECapabilityMask_Wmm                              = 0x0001,
    unifi_IECapabilityMask_WmmUapsd                         = 0x0002,
    unifi_IECapabilityMask_Ccx                              = 0x0004,
    unifi_IECapabilityMask_Wps                              = 0x0008,
    unifi_IECapabilityMask_PreAuth                          = 0x0010
} unifi_IECapabilityMask;

typedef enum unifi_ScanStopCondition
{
    unifi_ScanStopAllResults                                = 0x0000,
    unifi_ScanStopFirstResult                               = 0x0001,
    unifi_ScanStopSatisfactoryRoam                          = 0x0002
} unifi_ScanStopCondition;

typedef enum unifi_ScanUpdateAction
{
    unifi_ScanStopOnly                                      = 0x0000,
    unifi_ScanStartOnly                                     = 0x0001,
    unifi_ScanStopStart                                     = 0x0002,
    unifi_ScanCloakedSsidRescan                             = 0x0003
} unifi_ScanUpdateAction;











#ifdef __cplusplus
}
#endif

#endif /* SCAN_MANAGER_XML_TYPES_H */
