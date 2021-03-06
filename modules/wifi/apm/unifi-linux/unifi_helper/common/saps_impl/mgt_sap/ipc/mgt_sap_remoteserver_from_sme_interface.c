/* This is an autogenerated file */
/* Tag: noCheckHeader */

/*    CONFIDENTIAL */
/*    Copyright (C) Cambridge Silicon Radio Ltd 2008. All rights reserved. */

#include "sme_top_level_fsm/sme_top_level_fsm.h"
#include "mgt_sap_serialise.h"
#include "event_pack_unpack/event_pack_unpack.h"
#include "ipc/ipc.h"

extern ipcConnection* get_mgt_ipc_connection(FsmContext* context);

#ifndef CUSTOM_UNIFI_MGT_ASSOCIATION_COMPLETE_IND
void unifi_mgt_association_complete_ind(void* context, CsrUint16 appHandlesCount, void* *appHandles, unifi_Status status, const unifi_ConnectionInfo *connectionInfo, unifi_IEEE80211Reason deauthReason)
{
    CsrUint8* evt;
    CsrUint16 packedLength = serialise_unifi_mgt_association_complete_ind(&evt, appHandlesCount, appHandles, status, connectionInfo, deauthReason);

    (void)ipc_message_send(get_mgt_ipc_connection(context), evt, packedLength);
    CsrPfree(evt);
}
#endif /* CUSTOM_UNIFI_MGT_ASSOCIATION_COMPLETE_IND */

#ifndef CUSTOM_UNIFI_MGT_ASSOCIATION_START_IND
void unifi_mgt_association_start_ind(void* context, CsrUint16 appHandlesCount, void* *appHandles, const unifi_MACAddress *address, const unifi_SSID *ssid)
{
    CsrUint8* evt;
    CsrUint16 packedLength = serialise_unifi_mgt_association_start_ind(&evt, appHandlesCount, appHandles, address, ssid);

    (void)ipc_message_send(get_mgt_ipc_connection(context), evt, packedLength);
    CsrPfree(evt);
}
#endif /* CUSTOM_UNIFI_MGT_ASSOCIATION_START_IND */

#ifndef CUSTOM_UNIFI_MGT_BLACKLIST_CFM
void unifi_mgt_blacklist_cfm(void* context, void* appHandle, unifi_Status status, unifi_ListAction action, CsrUint8 getAddressCount, const unifi_MACAddress *getAddresses)
{
    CsrUint8* evt;
    CsrUint16 packedLength = serialise_unifi_mgt_blacklist_cfm(&evt, appHandle, status, action, getAddressCount, getAddresses);

    (void)ipc_message_send(get_mgt_ipc_connection(context), evt, packedLength);
    CsrPfree(evt);
}
#endif /* CUSTOM_UNIFI_MGT_BLACKLIST_CFM */

#ifndef CUSTOM_UNIFI_MGT_CONNECT_CFM
void unifi_mgt_connect_cfm(void* context, void* appHandle, unifi_Status status)
{
    CsrUint8* evt;
    CsrUint16 packedLength = serialise_unifi_mgt_connect_cfm(&evt, appHandle, status);

    (void)ipc_message_send(get_mgt_ipc_connection(context), evt, packedLength);
    CsrPfree(evt);
}
#endif /* CUSTOM_UNIFI_MGT_CONNECT_CFM */

#ifndef CUSTOM_UNIFI_MGT_CONNECTION_QUALITY_IND
void unifi_mgt_connection_quality_ind(void* context, CsrUint16 appHandlesCount, void* *appHandles, const unifi_LinkQuality *linkQuality)
{
    CsrUint8* evt;
    CsrUint16 packedLength = serialise_unifi_mgt_connection_quality_ind(&evt, appHandlesCount, appHandles, linkQuality);

    (void)ipc_message_send(get_mgt_ipc_connection(context), evt, packedLength);
    CsrPfree(evt);
}
#endif /* CUSTOM_UNIFI_MGT_CONNECTION_QUALITY_IND */

#ifndef CUSTOM_UNIFI_MGT_DISCONNECT_CFM
void unifi_mgt_disconnect_cfm(void* context, void* appHandle, unifi_Status status)
{
    CsrUint8* evt;
    CsrUint16 packedLength = serialise_unifi_mgt_disconnect_cfm(&evt, appHandle, status);

    (void)ipc_message_send(get_mgt_ipc_connection(context), evt, packedLength);
    CsrPfree(evt);
}
#endif /* CUSTOM_UNIFI_MGT_DISCONNECT_CFM */

#ifndef CUSTOM_UNIFI_MGT_EVENT_MASK_SET_CFM
void unifi_mgt_event_mask_set_cfm(void* context, void* appHandle, unifi_Status status)
{
    CsrUint8* evt;
    CsrUint16 packedLength = serialise_unifi_mgt_event_mask_set_cfm(&evt, appHandle, status);

    (void)ipc_message_send(get_mgt_ipc_connection(context), evt, packedLength);
    CsrPfree(evt);
}
#endif /* CUSTOM_UNIFI_MGT_EVENT_MASK_SET_CFM */

#ifndef CUSTOM_UNIFI_MGT_GET_VALUE_CFM
void unifi_mgt_get_value_cfm(void* context, void* appHandle, unifi_Status status, const unifi_AppValue *appValue)
{
    CsrUint8* evt;
    CsrUint16 packedLength = serialise_unifi_mgt_get_value_cfm(&evt, appHandle, status, appValue);

    (void)ipc_message_send(get_mgt_ipc_connection(context), evt, packedLength);
    CsrPfree(evt);
}
#endif /* CUSTOM_UNIFI_MGT_GET_VALUE_CFM */

#ifndef CUSTOM_UNIFI_MGT_IBSS_STATION_IND
void unifi_mgt_ibss_station_ind(void* context, CsrUint16 appHandlesCount, void* *appHandles, const unifi_MACAddress *address, CsrBool isconnected)
{
    CsrUint8* evt;
    CsrUint16 packedLength = serialise_unifi_mgt_ibss_station_ind(&evt, appHandlesCount, appHandles, address, isconnected);

    (void)ipc_message_send(get_mgt_ipc_connection(context), evt, packedLength);
    CsrPfree(evt);
}
#endif /* CUSTOM_UNIFI_MGT_IBSS_STATION_IND */

#ifndef CUSTOM_UNIFI_MGT_KEY_CFM
void unifi_mgt_key_cfm(void* context, void* appHandle, unifi_Status status, unifi_ListAction action)
{
    CsrUint8* evt;
    CsrUint16 packedLength = serialise_unifi_mgt_key_cfm(&evt, appHandle, status, action);

    (void)ipc_message_send(get_mgt_ipc_connection(context), evt, packedLength);
    CsrPfree(evt);
}
#endif /* CUSTOM_UNIFI_MGT_KEY_CFM */

#ifndef CUSTOM_UNIFI_MGT_MEDIA_STATUS_IND
void unifi_mgt_media_status_ind(void* context, CsrUint16 appHandlesCount, void* *appHandles, unifi_MediaStatus mediaStatus, const unifi_ConnectionInfo *connectionInfo, unifi_IEEE80211Reason disassocReason, unifi_IEEE80211Reason deauthReason)
{
    CsrUint8* evt;
    CsrUint16 packedLength = serialise_unifi_mgt_media_status_ind(&evt, appHandlesCount, appHandles, mediaStatus, connectionInfo, disassocReason, deauthReason);

    (void)ipc_message_send(get_mgt_ipc_connection(context), evt, packedLength);
    CsrPfree(evt);
}
#endif /* CUSTOM_UNIFI_MGT_MEDIA_STATUS_IND */

#ifndef CUSTOM_UNIFI_MGT_MIB_GET_CFM
void unifi_mgt_mib_get_cfm(void* context, void* appHandle, unifi_Status status, CsrUint16 mibAttributeLength, const CsrUint8 *mibAttribute)
{
    CsrUint8* evt;
    CsrUint16 packedLength = serialise_unifi_mgt_mib_get_cfm(&evt, appHandle, status, mibAttributeLength, mibAttribute);

    (void)ipc_message_send(get_mgt_ipc_connection(context), evt, packedLength);
    CsrPfree(evt);
}
#endif /* CUSTOM_UNIFI_MGT_MIB_GET_CFM */

#ifndef CUSTOM_UNIFI_MGT_MIB_GET_NEXT_CFM
void unifi_mgt_mib_get_next_cfm(void* context, void* appHandle, unifi_Status status, CsrUint16 mibAttributeLength, const CsrUint8 *mibAttribute)
{
    CsrUint8* evt;
    CsrUint16 packedLength = serialise_unifi_mgt_mib_get_next_cfm(&evt, appHandle, status, mibAttributeLength, mibAttribute);

    (void)ipc_message_send(get_mgt_ipc_connection(context), evt, packedLength);
    CsrPfree(evt);
}
#endif /* CUSTOM_UNIFI_MGT_MIB_GET_NEXT_CFM */

#ifndef CUSTOM_UNIFI_MGT_MIB_SET_CFM
void unifi_mgt_mib_set_cfm(void* context, void* appHandle, unifi_Status status)
{
    CsrUint8* evt;
    CsrUint16 packedLength = serialise_unifi_mgt_mib_set_cfm(&evt, appHandle, status);

    (void)ipc_message_send(get_mgt_ipc_connection(context), evt, packedLength);
    CsrPfree(evt);
}
#endif /* CUSTOM_UNIFI_MGT_MIB_SET_CFM */

#ifndef CUSTOM_UNIFI_MGT_MIC_FAILURE_IND
void unifi_mgt_mic_failure_ind(void* context, CsrUint16 appHandlesCount, void* *appHandles, CsrBool secondFailure, CsrUint16 count, const unifi_MACAddress *address, unifi_KeyType keyType, CsrUint16 keyId, const CsrUint16 *tsc)
{
    CsrUint8* evt;
    CsrUint16 packedLength = serialise_unifi_mgt_mic_failure_ind(&evt, appHandlesCount, appHandles, secondFailure, count, address, keyType, keyId, tsc);

    (void)ipc_message_send(get_mgt_ipc_connection(context), evt, packedLength);
    CsrPfree(evt);
}
#endif /* CUSTOM_UNIFI_MGT_MIC_FAILURE_IND */

#ifndef CUSTOM_UNIFI_MGT_MULTICAST_ADDRESS_CFM
void unifi_mgt_multicast_address_cfm(void* context, void* appHandle, unifi_Status status, unifi_ListAction action, CsrUint8 getAddressesCount, const unifi_MACAddress *getAddresses)
{
    CsrUint8* evt;
    CsrUint16 packedLength = serialise_unifi_mgt_multicast_address_cfm(&evt, appHandle, status, action, getAddressesCount, getAddresses);

    (void)ipc_message_send(get_mgt_ipc_connection(context), evt, packedLength);
    CsrPfree(evt);
}
#endif /* CUSTOM_UNIFI_MGT_MULTICAST_ADDRESS_CFM */

#ifndef CUSTOM_UNIFI_MGT_PACKET_FILTER_SET_CFM
void unifi_mgt_packet_filter_set_cfm(void* context, void* appHandle, unifi_Status status)
{
    CsrUint8* evt;
    CsrUint16 packedLength = serialise_unifi_mgt_packet_filter_set_cfm(&evt, appHandle, status);

    (void)ipc_message_send(get_mgt_ipc_connection(context), evt, packedLength);
    CsrPfree(evt);
}
#endif /* CUSTOM_UNIFI_MGT_PACKET_FILTER_SET_CFM */

#ifndef CUSTOM_UNIFI_MGT_PMKID_CFM
void unifi_mgt_pmkid_cfm(void* context, void* appHandle, unifi_Status status, unifi_ListAction action, CsrUint8 getPmkidsCount, const unifi_Pmkid *getPmkids)
{
    CsrUint8* evt;
    CsrUint16 packedLength = serialise_unifi_mgt_pmkid_cfm(&evt, appHandle, status, action, getPmkidsCount, getPmkids);

    (void)ipc_message_send(get_mgt_ipc_connection(context), evt, packedLength);
    CsrPfree(evt);
}
#endif /* CUSTOM_UNIFI_MGT_PMKID_CFM */

#ifndef CUSTOM_UNIFI_MGT_PMKID_CANDIDATE_LIST_IND
void unifi_mgt_pmkid_candidate_list_ind(void* context, CsrUint16 appHandlesCount, void* *appHandles, CsrUint8 pmkidCandidatesCount, const unifi_PmkidCandidate *pmkidCandidates)
{
    CsrUint8* evt;
    CsrUint16 packedLength = serialise_unifi_mgt_pmkid_candidate_list_ind(&evt, appHandlesCount, appHandles, pmkidCandidatesCount, pmkidCandidates);

    (void)ipc_message_send(get_mgt_ipc_connection(context), evt, packedLength);
    CsrPfree(evt);
}
#endif /* CUSTOM_UNIFI_MGT_PMKID_CANDIDATE_LIST_IND */

#ifndef CUSTOM_UNIFI_MGT_RESTRICTED_ACCESS_DISABLE_CFM
void unifi_mgt_restricted_access_disable_cfm(void* context, void* appHandle, unifi_Status status)
{
    CsrUint8* evt;
    CsrUint16 packedLength = serialise_unifi_mgt_restricted_access_disable_cfm(&evt, appHandle, status);

    (void)ipc_message_send(get_mgt_ipc_connection(context), evt, packedLength);
    CsrPfree(evt);
}
#endif /* CUSTOM_UNIFI_MGT_RESTRICTED_ACCESS_DISABLE_CFM */

#ifndef CUSTOM_UNIFI_MGT_RESTRICTED_ACCESS_ENABLE_CFM
void unifi_mgt_restricted_access_enable_cfm(void* context, void* appHandle, unifi_Status status)
{
    CsrUint8* evt;
    CsrUint16 packedLength = serialise_unifi_mgt_restricted_access_enable_cfm(&evt, appHandle, status);

    (void)ipc_message_send(get_mgt_ipc_connection(context), evt, packedLength);
    CsrPfree(evt);
}
#endif /* CUSTOM_UNIFI_MGT_RESTRICTED_ACCESS_ENABLE_CFM */

#ifndef CUSTOM_UNIFI_MGT_ROAM_COMPLETE_IND
void unifi_mgt_roam_complete_ind(void* context, CsrUint16 appHandlesCount, void* *appHandles, unifi_Status status)
{
    CsrUint8* evt;
    CsrUint16 packedLength = serialise_unifi_mgt_roam_complete_ind(&evt, appHandlesCount, appHandles, status);

    (void)ipc_message_send(get_mgt_ipc_connection(context), evt, packedLength);
    CsrPfree(evt);
}
#endif /* CUSTOM_UNIFI_MGT_ROAM_COMPLETE_IND */

#ifndef CUSTOM_UNIFI_MGT_ROAM_START_IND
void unifi_mgt_roam_start_ind(void* context, CsrUint16 appHandlesCount, void* *appHandles, unifi_RoamReason roamReason, unifi_IEEE80211Reason reason80211)
{
    CsrUint8* evt;
    CsrUint16 packedLength = serialise_unifi_mgt_roam_start_ind(&evt, appHandlesCount, appHandles, roamReason, reason80211);

    (void)ipc_message_send(get_mgt_ipc_connection(context), evt, packedLength);
    CsrPfree(evt);
}
#endif /* CUSTOM_UNIFI_MGT_ROAM_START_IND */

#ifndef CUSTOM_UNIFI_MGT_SCAN_FULL_CFM
void unifi_mgt_scan_full_cfm(void* context, void* appHandle, unifi_Status status)
{
    CsrUint8* evt;
    CsrUint16 packedLength = serialise_unifi_mgt_scan_full_cfm(&evt, appHandle, status);

    (void)ipc_message_send(get_mgt_ipc_connection(context), evt, packedLength);
    CsrPfree(evt);
}
#endif /* CUSTOM_UNIFI_MGT_SCAN_FULL_CFM */

#ifndef CUSTOM_UNIFI_MGT_SCAN_RESULT_IND
void unifi_mgt_scan_result_ind(void* context, CsrUint16 appHandlesCount, void* *appHandles, const unifi_ScanResult *result)
{
    CsrUint8* evt;
    CsrUint16 packedLength = serialise_unifi_mgt_scan_result_ind(&evt, appHandlesCount, appHandles, result);

    (void)ipc_message_send(get_mgt_ipc_connection(context), evt, packedLength);
    CsrPfree(evt);
}
#endif /* CUSTOM_UNIFI_MGT_SCAN_RESULT_IND */

#ifndef CUSTOM_UNIFI_MGT_SCAN_RESULTS_FLUSH_CFM
void unifi_mgt_scan_results_flush_cfm(void* context, void* appHandle, unifi_Status status)
{
    CsrUint8* evt;
    CsrUint16 packedLength = serialise_unifi_mgt_scan_results_flush_cfm(&evt, appHandle, status);

    (void)ipc_message_send(get_mgt_ipc_connection(context), evt, packedLength);
    CsrPfree(evt);
}
#endif /* CUSTOM_UNIFI_MGT_SCAN_RESULTS_FLUSH_CFM */

#ifndef CUSTOM_UNIFI_MGT_SCAN_RESULTS_GET_CFM
void unifi_mgt_scan_results_get_cfm(void* context, void* appHandle, unifi_Status status, CsrUint16 scanResultsCount, const unifi_ScanResult *scanResults)
{
    CsrUint8* evt;
    CsrUint16 packedLength = serialise_unifi_mgt_scan_results_get_cfm(&evt, appHandle, status, scanResultsCount, scanResults);

    (void)ipc_message_send(get_mgt_ipc_connection(context), evt, packedLength);
    CsrPfree(evt);
}
#endif /* CUSTOM_UNIFI_MGT_SCAN_RESULTS_GET_CFM */

#ifndef CUSTOM_UNIFI_MGT_SET_VALUE_CFM
void unifi_mgt_set_value_cfm(void* context, void* appHandle, unifi_Status status, unifi_AppValueId appValueId)
{
    CsrUint8* evt;
    CsrUint16 packedLength = serialise_unifi_mgt_set_value_cfm(&evt, appHandle, status, appValueId);

    (void)ipc_message_send(get_mgt_ipc_connection(context), evt, packedLength);
    CsrPfree(evt);
}
#endif /* CUSTOM_UNIFI_MGT_SET_VALUE_CFM */

#ifndef CUSTOM_UNIFI_MGT_TSPEC_IND
void unifi_mgt_tspec_ind(void* context, CsrUint16 appHandlesCount, void* *appHandles, CsrUint32 transactionId, unifi_TspecResultCode tspecResultCode, CsrUint16 tspecLength, const CsrUint8 *tspec)
{
    CsrUint8* evt;
    CsrUint16 packedLength = serialise_unifi_mgt_tspec_ind(&evt, appHandlesCount, appHandles, transactionId, tspecResultCode, tspecLength, tspec);

    (void)ipc_message_send(get_mgt_ipc_connection(context), evt, packedLength);
    CsrPfree(evt);
}
#endif /* CUSTOM_UNIFI_MGT_TSPEC_IND */

#ifndef CUSTOM_UNIFI_MGT_TSPEC_CFM
void unifi_mgt_tspec_cfm(void* context, void* appHandle, unifi_Status status, CsrUint32 transactionId, unifi_TspecResultCode tspecResultCode, CsrUint16 tspecLength, const CsrUint8 *tspec)
{
    CsrUint8* evt;
    CsrUint16 packedLength = serialise_unifi_mgt_tspec_cfm(&evt, appHandle, status, transactionId, tspecResultCode, tspecLength, tspec);

    (void)ipc_message_send(get_mgt_ipc_connection(context), evt, packedLength);
    CsrPfree(evt);
}
#endif /* CUSTOM_UNIFI_MGT_TSPEC_CFM */

#ifndef CUSTOM_UNIFI_MGT_WIFI_FLIGHTMODE_CFM
void unifi_mgt_wifi_flightmode_cfm(void* context, void* appHandle, unifi_Status status)
{
    CsrUint8* evt;
    CsrUint16 packedLength = serialise_unifi_mgt_wifi_flightmode_cfm(&evt, appHandle, status);

    (void)ipc_message_send(get_mgt_ipc_connection(context), evt, packedLength);
    CsrPfree(evt);
}
#endif /* CUSTOM_UNIFI_MGT_WIFI_FLIGHTMODE_CFM */

#ifndef CUSTOM_UNIFI_MGT_WIFI_OFF_IND
void unifi_mgt_wifi_off_ind(void* context, CsrUint16 appHandlesCount, void* *appHandles, unifi_ControlIndication controlIndication)
{
    CsrUint8* evt;
    CsrUint16 packedLength = serialise_unifi_mgt_wifi_off_ind(&evt, appHandlesCount, appHandles, controlIndication);

    (void)ipc_message_send(get_mgt_ipc_connection(context), evt, packedLength);
    CsrPfree(evt);
}
#endif /* CUSTOM_UNIFI_MGT_WIFI_OFF_IND */

#ifndef CUSTOM_UNIFI_MGT_WIFI_OFF_CFM
void unifi_mgt_wifi_off_cfm(void* context, void* appHandle, unifi_Status status)
{
    CsrUint8* evt;
    CsrUint16 packedLength = serialise_unifi_mgt_wifi_off_cfm(&evt, appHandle, status);

    (void)ipc_message_send(get_mgt_ipc_connection(context), evt, packedLength);
    CsrPfree(evt);
}
#endif /* CUSTOM_UNIFI_MGT_WIFI_OFF_CFM */

#ifndef CUSTOM_UNIFI_MGT_WIFI_ON_CFM
void unifi_mgt_wifi_on_cfm(void* context, void* appHandle, unifi_Status status)
{
    CsrUint8* evt;
    CsrUint16 packedLength = serialise_unifi_mgt_wifi_on_cfm(&evt, appHandle, status);

    (void)ipc_message_send(get_mgt_ipc_connection(context), evt, packedLength);
    CsrPfree(evt);
}
#endif /* CUSTOM_UNIFI_MGT_WIFI_ON_CFM */


