/**
 * Copyright (c) 2014 Microsoft Open Technologies, Inc.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License"); you may
 *    not use this file except in compliance with the License. You may obtain
 *    a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
 *
 *    THIS CODE IS PROVIDED ON AN *AS IS* BASIS, WITHOUT WARRANTIES OR
 *    CONDITIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT
 *    LIMITATION ANY IMPLIED WARRANTIES OR CONDITIONS OF TITLE, FITNESS
 *    FOR A PARTICULAR PURPOSE, MERCHANTABILITY OR NON-INFRINGEMENT.
 *
 *    See the Apache Version 2.0 License for specific language governing
 *    permissions and limitations under the License.
 *
 *    Microsoft would like to thank the following companies for their review and
 *    assistance with these files: Intel Corporation, Mellanox Technologies Ltd,
 *    Dell Products, L.P., Facebook, Inc., Marvell International Ltd.
 *
 * @file    saiexperimentaldash.h
 *
 * @brief   This module defines SAI P4 extension  interface
 */

#if !defined (__SAIEXPERIMENTALDASH_H_)
#define __SAIEXPERIMENTALDASH_H_

#include <saitypes.h>

/**
 * @defgroup SAIEXPERIMENTALDASH SAI - Extension specific API definitions
 *
 * @{
 */

/**
 * @brief Attribute data for #SAI_INBOUND_ROUTING_ENTRY_ATTR_ACTION
 */
typedef enum _sai_inbound_routing_entry_action_t
{
    SAI_INBOUND_ROUTING_ENTRY_ACTION_VXLAN_DECAP,

    SAI_INBOUND_ROUTING_ENTRY_ACTION_VXLAN_DECAP_PA_VALIDATE,

    SAI_INBOUND_ROUTING_ENTRY_ACTION_DENY,

} sai_inbound_routing_entry_action_t;

/**
 * @brief Attribute data for #SAI_PA_VALIDATION_ENTRY_ATTR_ACTION
 */
typedef enum _sai_pa_validation_entry_action_t
{
    SAI_PA_VALIDATION_ENTRY_ACTION_PERMIT,

    SAI_PA_VALIDATION_ENTRY_ACTION_DENY,

} sai_pa_validation_entry_action_t;

/**
 * @brief Attribute data for #SAI_OUTBOUND_ACL_STAGE1_ATTR_ACTION
 */
typedef enum _sai_outbound_acl_stage1_action_t
{
    SAI_OUTBOUND_ACL_STAGE1_ACTION_PERMIT,

    SAI_OUTBOUND_ACL_STAGE1_ACTION_PERMIT_AND_CONTINUE,

    SAI_OUTBOUND_ACL_STAGE1_ACTION_DENY,

    SAI_OUTBOUND_ACL_STAGE1_ACTION_DENY_AND_CONTINUE,

} sai_outbound_acl_stage1_action_t;

/**
 * @brief Attribute data for #SAI_OUTBOUND_ACL_STAGE2_ATTR_ACTION
 */
typedef enum _sai_outbound_acl_stage2_action_t
{
    SAI_OUTBOUND_ACL_STAGE2_ACTION_PERMIT,

    SAI_OUTBOUND_ACL_STAGE2_ACTION_PERMIT_AND_CONTINUE,

    SAI_OUTBOUND_ACL_STAGE2_ACTION_DENY,

    SAI_OUTBOUND_ACL_STAGE2_ACTION_DENY_AND_CONTINUE,

} sai_outbound_acl_stage2_action_t;

/**
 * @brief Attribute data for #SAI_OUTBOUND_ACL_STAGE3_ATTR_ACTION
 */
typedef enum _sai_outbound_acl_stage3_action_t
{
    SAI_OUTBOUND_ACL_STAGE3_ACTION_PERMIT,

    SAI_OUTBOUND_ACL_STAGE3_ACTION_PERMIT_AND_CONTINUE,

    SAI_OUTBOUND_ACL_STAGE3_ACTION_DENY,

    SAI_OUTBOUND_ACL_STAGE3_ACTION_DENY_AND_CONTINUE,

} sai_outbound_acl_stage3_action_t;

/**
 * @brief Attribute data for #SAI_INBOUND_ACL_STAGE1_ATTR_ACTION
 */
typedef enum _sai_inbound_acl_stage1_action_t
{
    SAI_INBOUND_ACL_STAGE1_ACTION_PERMIT,

    SAI_INBOUND_ACL_STAGE1_ACTION_PERMIT_AND_CONTINUE,

    SAI_INBOUND_ACL_STAGE1_ACTION_DENY,

    SAI_INBOUND_ACL_STAGE1_ACTION_DENY_AND_CONTINUE,

} sai_inbound_acl_stage1_action_t;

/**
 * @brief Attribute data for #SAI_INBOUND_ACL_STAGE2_ATTR_ACTION
 */
typedef enum _sai_inbound_acl_stage2_action_t
{
    SAI_INBOUND_ACL_STAGE2_ACTION_PERMIT,

    SAI_INBOUND_ACL_STAGE2_ACTION_PERMIT_AND_CONTINUE,

    SAI_INBOUND_ACL_STAGE2_ACTION_DENY,

    SAI_INBOUND_ACL_STAGE2_ACTION_DENY_AND_CONTINUE,

} sai_inbound_acl_stage2_action_t;

/**
 * @brief Attribute data for #SAI_INBOUND_ACL_STAGE3_ATTR_ACTION
 */
typedef enum _sai_inbound_acl_stage3_action_t
{
    SAI_INBOUND_ACL_STAGE3_ACTION_PERMIT,

    SAI_INBOUND_ACL_STAGE3_ACTION_PERMIT_AND_CONTINUE,

    SAI_INBOUND_ACL_STAGE3_ACTION_DENY,

    SAI_INBOUND_ACL_STAGE3_ACTION_DENY_AND_CONTINUE,

} sai_inbound_acl_stage3_action_t;

/**
 * @brief Entry for direction_lookup_entry
 */
typedef struct _sai_direction_lookup_entry_t
{
    /**
     * @brief Switch ID
     *
     * @objects SAI_OBJECT_TYPE_SWITCH
     */
    sai_object_id_t switch_id;

    /**
     * @brief Exact matched key VNI
     */
    sai_uint32_t VNI;

} sai_direction_lookup_entry_t;

/**
 * @brief Attribute ID for direction_lookup_entry
 */
typedef enum _sai_direction_lookup_entry_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_DIRECTION_LOOKUP_ENTRY_ATTR_START,

    /**
     * @brief Action set_direction parameter DIRECTION
     *
     * @type sai_uint32_t
     * @flags CREATE_AND_SET
     * @default 0
     */
    SAI_DIRECTION_LOOKUP_ENTRY_ATTR_DIRECTION = SAI_DIRECTION_LOOKUP_ENTRY_ATTR_START,

    /**
     * @brief End of attributes
     */
    SAI_DIRECTION_LOOKUP_ENTRY_ATTR_END,

    /** Custom range base value */
    SAI_DIRECTION_LOOKUP_ENTRY_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_DIRECTION_LOOKUP_ENTRY_ATTR_CUSTOM_RANGE_END,

} sai_direction_lookup_entry_attr_t;

/**
 * @brief Entry for eni_lookup_to_vm_entry
 */
typedef struct _sai_eni_lookup_to_vm_entry_t
{
    /**
     * @brief Switch ID
     *
     * @objects SAI_OBJECT_TYPE_SWITCH
     */
    sai_object_id_t switch_id;

    /**
     * @brief Exact matched key dst_mac
     */
    sai_mac_t dst_mac;

} sai_eni_lookup_to_vm_entry_t;

/**
 * @brief Attribute ID for eni_lookup_to_vm_entry
 */
typedef enum _sai_eni_lookup_to_vm_entry_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_ENI_LOOKUP_TO_VM_ENTRY_ATTR_START,

    /**
     * @brief Action set_eni parameter ENI
     *
     * @type sai_uint16_t
     * @flags CREATE_AND_SET
     * @isvlan false
     * @default 0
     */
    SAI_ENI_LOOKUP_TO_VM_ENTRY_ATTR_ENI = SAI_ENI_LOOKUP_TO_VM_ENTRY_ATTR_START,

    /**
     * @brief End of attributes
     */
    SAI_ENI_LOOKUP_TO_VM_ENTRY_ATTR_END,

    /** Custom range base value */
    SAI_ENI_LOOKUP_TO_VM_ENTRY_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_ENI_LOOKUP_TO_VM_ENTRY_ATTR_CUSTOM_RANGE_END,

} sai_eni_lookup_to_vm_entry_attr_t;

/**
 * @brief Entry for inbound_routing_entry
 */
typedef struct _sai_inbound_routing_entry_t
{
    /**
     * @brief Switch ID
     *
     * @objects SAI_OBJECT_TYPE_SWITCH
     */
    sai_object_id_t switch_id;

    /**
     * @brief Exact matched key VNI
     */
    sai_uint32_t VNI;

} sai_inbound_routing_entry_t;

/**
 * @brief Attribute ID for inbound_routing_entry
 */
typedef enum _sai_inbound_routing_entry_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_INBOUND_ROUTING_ENTRY_ATTR_START,

    /**
     * @brief Action
     *
     * @type sai_inbound_routing_entry_action_t
     * @flags CREATE_AND_SET
     * @default SAI_INBOUND_ROUTING_ENTRY_ACTION_VXLAN_DECAP
     */
    SAI_INBOUND_ROUTING_ENTRY_ATTR_ACTION = SAI_INBOUND_ROUTING_ENTRY_ATTR_START,

    /**
     * @brief End of attributes
     */
    SAI_INBOUND_ROUTING_ENTRY_ATTR_END,

    /** Custom range base value */
    SAI_INBOUND_ROUTING_ENTRY_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_INBOUND_ROUTING_ENTRY_ATTR_CUSTOM_RANGE_END,

} sai_inbound_routing_entry_attr_t;

/**
 * @brief Entry for pa_validation_entry
 */
typedef struct _sai_pa_validation_entry_t
{
    /**
     * @brief Switch ID
     *
     * @objects SAI_OBJECT_TYPE_SWITCH
     */
    sai_object_id_t switch_id;

    /**
     * @brief Exact matched key ENI
     */
    sai_uint8_t ENI;

    /**
     * @brief Exact matched key sip
     */
    sai_ip_address_t sip;

    /**
     * @brief Exact matched key VNI
     */
    sai_uint32_t VNI;

} sai_pa_validation_entry_t;

/**
 * @brief Attribute ID for pa_validation_entry
 */
typedef enum _sai_pa_validation_entry_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_PA_VALIDATION_ENTRY_ATTR_START,

    /**
     * @brief Action
     *
     * @type sai_pa_validation_entry_action_t
     * @flags CREATE_AND_SET
     * @default SAI_PA_VALIDATION_ENTRY_ACTION_PERMIT
     */
    SAI_PA_VALIDATION_ENTRY_ATTR_ACTION = SAI_PA_VALIDATION_ENTRY_ATTR_START,

    /**
     * @brief End of attributes
     */
    SAI_PA_VALIDATION_ENTRY_ATTR_END,

    /** Custom range base value */
    SAI_PA_VALIDATION_ENTRY_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_PA_VALIDATION_ENTRY_ATTR_CUSTOM_RANGE_END,

} sai_pa_validation_entry_attr_t;

/**
 * @brief Entry for outbound_eni_lookup_from_vm_entry
 */
typedef struct _sai_outbound_eni_lookup_from_vm_entry_t
{
    /**
     * @brief Switch ID
     *
     * @objects SAI_OBJECT_TYPE_SWITCH
     */
    sai_object_id_t switch_id;

    /**
     * @brief Exact matched key src_mac
     */
    sai_mac_t src_mac;

} sai_outbound_eni_lookup_from_vm_entry_t;

/**
 * @brief Attribute ID for outbound_eni_lookup_from_vm_entry
 */
typedef enum _sai_outbound_eni_lookup_from_vm_entry_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_OUTBOUND_ENI_LOOKUP_FROM_VM_ENTRY_ATTR_START,

    /**
     * @brief Action set_eni parameter ENI
     *
     * @type sai_uint16_t
     * @flags CREATE_AND_SET
     * @isvlan false
     * @default 0
     */
    SAI_OUTBOUND_ENI_LOOKUP_FROM_VM_ENTRY_ATTR_ENI = SAI_OUTBOUND_ENI_LOOKUP_FROM_VM_ENTRY_ATTR_START,

    /**
     * @brief End of attributes
     */
    SAI_OUTBOUND_ENI_LOOKUP_FROM_VM_ENTRY_ATTR_END,

    /** Custom range base value */
    SAI_OUTBOUND_ENI_LOOKUP_FROM_VM_ENTRY_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_OUTBOUND_ENI_LOOKUP_FROM_VM_ENTRY_ATTR_CUSTOM_RANGE_END,

} sai_outbound_eni_lookup_from_vm_entry_attr_t;

/**
 * @brief Entry for outbound_eni_to_vni_entry
 */
typedef struct _sai_outbound_eni_to_vni_entry_t
{
    /**
     * @brief Switch ID
     *
     * @objects SAI_OBJECT_TYPE_SWITCH
     */
    sai_object_id_t switch_id;

    /**
     * @brief Exact matched key ENI
     */
    sai_uint8_t ENI;

} sai_outbound_eni_to_vni_entry_t;

/**
 * @brief Attribute ID for outbound_eni_to_vni_entry
 */
typedef enum _sai_outbound_eni_to_vni_entry_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_OUTBOUND_ENI_TO_VNI_ENTRY_ATTR_START,

    /**
     * @brief Action set_vni parameter VNI
     *
     * @type sai_uint32_t
     * @flags CREATE_AND_SET
     * @default 0
     */
    SAI_OUTBOUND_ENI_TO_VNI_ENTRY_ATTR_VNI = SAI_OUTBOUND_ENI_TO_VNI_ENTRY_ATTR_START,

    /**
     * @brief End of attributes
     */
    SAI_OUTBOUND_ENI_TO_VNI_ENTRY_ATTR_END,

    /** Custom range base value */
    SAI_OUTBOUND_ENI_TO_VNI_ENTRY_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_OUTBOUND_ENI_TO_VNI_ENTRY_ATTR_CUSTOM_RANGE_END,

} sai_outbound_eni_to_vni_entry_attr_t;

/**
 * @brief Attribute ID for outbound_acl_stage1
 */
typedef enum _sai_outbound_acl_stage1_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_OUTBOUND_ACL_STAGE1_ATTR_START,

    /**
     * @brief Action
     *
     * @type sai_outbound_acl_stage1_action_t
     * @flags CREATE_AND_SET
     * @default SAI_OUTBOUND_ACL_STAGE1_ACTION_PERMIT
     */
    SAI_OUTBOUND_ACL_STAGE1_ATTR_ACTION = SAI_OUTBOUND_ACL_STAGE1_ATTR_START,

    /**
     * @brief Exact matched key ENI
     *
     * @type sai_uint8_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_OUTBOUND_ACL_STAGE1_ATTR_ENI,

    /**
     * @brief List matched key dip
     *
     * @type sai_ip_address_list_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_OUTBOUND_ACL_STAGE1_ATTR_DIP,

    /**
     * @brief List matched key sip
     *
     * @type sai_ip_address_list_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_OUTBOUND_ACL_STAGE1_ATTR_SIP,

    /**
     * @brief List matched key protocol
     *
     * @type sai_u8_list_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_OUTBOUND_ACL_STAGE1_ATTR_PROTOCOL,

    /**
     * @brief Range_list matched key src_port
     *
     * @type sai_u16_range_list_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_OUTBOUND_ACL_STAGE1_ATTR_SRC_PORT,

    /**
     * @brief Range_list matched key dst_port
     *
     * @type sai_u16_range_list_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_OUTBOUND_ACL_STAGE1_ATTR_DST_PORT,

    /**
     * @brief End of attributes
     */
    SAI_OUTBOUND_ACL_STAGE1_ATTR_END,

    /** Custom range base value */
    SAI_OUTBOUND_ACL_STAGE1_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_OUTBOUND_ACL_STAGE1_ATTR_CUSTOM_RANGE_END,

} sai_outbound_acl_stage1_attr_t;

/**
 * @brief Attribute ID for outbound_acl_stage2
 */
typedef enum _sai_outbound_acl_stage2_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_OUTBOUND_ACL_STAGE2_ATTR_START,

    /**
     * @brief Action
     *
     * @type sai_outbound_acl_stage2_action_t
     * @flags CREATE_AND_SET
     * @default SAI_OUTBOUND_ACL_STAGE2_ACTION_PERMIT
     */
    SAI_OUTBOUND_ACL_STAGE2_ATTR_ACTION = SAI_OUTBOUND_ACL_STAGE2_ATTR_START,

    /**
     * @brief Exact matched key ENI
     *
     * @type sai_uint8_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_OUTBOUND_ACL_STAGE2_ATTR_ENI,

    /**
     * @brief List matched key dip
     *
     * @type sai_ip_address_list_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_OUTBOUND_ACL_STAGE2_ATTR_DIP,

    /**
     * @brief List matched key sip
     *
     * @type sai_ip_address_list_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_OUTBOUND_ACL_STAGE2_ATTR_SIP,

    /**
     * @brief List matched key protocol
     *
     * @type sai_u8_list_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_OUTBOUND_ACL_STAGE2_ATTR_PROTOCOL,

    /**
     * @brief Range_list matched key src_port
     *
     * @type sai_u16_range_list_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_OUTBOUND_ACL_STAGE2_ATTR_SRC_PORT,

    /**
     * @brief Range_list matched key dst_port
     *
     * @type sai_u16_range_list_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_OUTBOUND_ACL_STAGE2_ATTR_DST_PORT,

    /**
     * @brief End of attributes
     */
    SAI_OUTBOUND_ACL_STAGE2_ATTR_END,

    /** Custom range base value */
    SAI_OUTBOUND_ACL_STAGE2_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_OUTBOUND_ACL_STAGE2_ATTR_CUSTOM_RANGE_END,

} sai_outbound_acl_stage2_attr_t;

/**
 * @brief Attribute ID for outbound_acl_stage3
 */
typedef enum _sai_outbound_acl_stage3_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_OUTBOUND_ACL_STAGE3_ATTR_START,

    /**
     * @brief Action
     *
     * @type sai_outbound_acl_stage3_action_t
     * @flags CREATE_AND_SET
     * @default SAI_OUTBOUND_ACL_STAGE3_ACTION_PERMIT
     */
    SAI_OUTBOUND_ACL_STAGE3_ATTR_ACTION = SAI_OUTBOUND_ACL_STAGE3_ATTR_START,

    /**
     * @brief Exact matched key ENI
     *
     * @type sai_uint8_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_OUTBOUND_ACL_STAGE3_ATTR_ENI,

    /**
     * @brief List matched key dip
     *
     * @type sai_ip_address_list_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_OUTBOUND_ACL_STAGE3_ATTR_DIP,

    /**
     * @brief List matched key sip
     *
     * @type sai_ip_address_list_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_OUTBOUND_ACL_STAGE3_ATTR_SIP,

    /**
     * @brief List matched key protocol
     *
     * @type sai_u8_list_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_OUTBOUND_ACL_STAGE3_ATTR_PROTOCOL,

    /**
     * @brief Range_list matched key src_port
     *
     * @type sai_u16_range_list_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_OUTBOUND_ACL_STAGE3_ATTR_SRC_PORT,

    /**
     * @brief Range_list matched key dst_port
     *
     * @type sai_u16_range_list_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_OUTBOUND_ACL_STAGE3_ATTR_DST_PORT,

    /**
     * @brief End of attributes
     */
    SAI_OUTBOUND_ACL_STAGE3_ATTR_END,

    /** Custom range base value */
    SAI_OUTBOUND_ACL_STAGE3_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_OUTBOUND_ACL_STAGE3_ATTR_CUSTOM_RANGE_END,

} sai_outbound_acl_stage3_attr_t;

/**
 * @brief Entry for outbound_routing_entry
 */
typedef struct _sai_outbound_routing_entry_t
{
    /**
     * @brief Switch ID
     *
     * @objects SAI_OBJECT_TYPE_SWITCH
     */
    sai_object_id_t switch_id;

    /**
     * @brief Exact matched key ENI
     */
    sai_uint8_t ENI;

    /**
     * @brief LPM matched key destination
     */
    sai_ip_prefix_t destination;

} sai_outbound_routing_entry_t;

/**
 * @brief Attribute ID for outbound_routing_entry
 */
typedef enum _sai_outbound_routing_entry_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_OUTBOUND_ROUTING_ENTRY_ATTR_START,

    /**
     * @brief Action route_vnet parameter DEST_VNET_VNI
     *
     * @type sai_uint32_t
     * @flags CREATE_AND_SET
     * @default 0
     */
    SAI_OUTBOUND_ROUTING_ENTRY_ATTR_DEST_VNET_VNI = SAI_OUTBOUND_ROUTING_ENTRY_ATTR_START,

    /**
     * @brief End of attributes
     */
    SAI_OUTBOUND_ROUTING_ENTRY_ATTR_END,

    /** Custom range base value */
    SAI_OUTBOUND_ROUTING_ENTRY_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_OUTBOUND_ROUTING_ENTRY_ATTR_CUSTOM_RANGE_END,

} sai_outbound_routing_entry_attr_t;

/**
 * @brief Entry for outbound_ca_to_pa_entry
 */
typedef struct _sai_outbound_ca_to_pa_entry_t
{
    /**
     * @brief Switch ID
     *
     * @objects SAI_OBJECT_TYPE_SWITCH
     */
    sai_object_id_t switch_id;

    /**
     * @brief Exact matched key dest_vni
     */
    sai_uint8_t dest_vni;

    /**
     * @brief Exact matched key dip
     */
    sai_ip_address_t dip;

} sai_outbound_ca_to_pa_entry_t;

/**
 * @brief Attribute ID for outbound_ca_to_pa_entry
 */
typedef enum _sai_outbound_ca_to_pa_entry_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_OUTBOUND_CA_TO_PA_ENTRY_ATTR_START,

    /**
     * @brief Action set_tunnel_mapping parameter UNDERLAY_DIP
     *
     * @type sai_ip_address_t
     * @flags CREATE_AND_SET
     * @default 0.0.0.0
     */
    SAI_OUTBOUND_CA_TO_PA_ENTRY_ATTR_UNDERLAY_DIP = SAI_OUTBOUND_CA_TO_PA_ENTRY_ATTR_START,

    /**
     * @brief Action set_tunnel_mapping parameter OVERLAY_DMAC
     *
     * @type sai_mac_t
     * @flags CREATE_AND_SET
     * @default 0:0:0:0:0:0
     */
    SAI_OUTBOUND_CA_TO_PA_ENTRY_ATTR_OVERLAY_DMAC,

    /**
     * @brief Action set_tunnel_mapping parameter USE_DST_VNI
     *
     * @type bool
     * @flags CREATE_AND_SET
     * @default false
     */
    SAI_OUTBOUND_CA_TO_PA_ENTRY_ATTR_USE_DST_VNI,

    /**
     * @brief End of attributes
     */
    SAI_OUTBOUND_CA_TO_PA_ENTRY_ATTR_END,

    /** Custom range base value */
    SAI_OUTBOUND_CA_TO_PA_ENTRY_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_OUTBOUND_CA_TO_PA_ENTRY_ATTR_CUSTOM_RANGE_END,

} sai_outbound_ca_to_pa_entry_attr_t;

/**
 * @brief Entry for inbound_eni_to_vm_entry
 */
typedef struct _sai_inbound_eni_to_vm_entry_t
{
    /**
     * @brief Switch ID
     *
     * @objects SAI_OBJECT_TYPE_SWITCH
     */
    sai_object_id_t switch_id;

    /**
     * @brief Exact matched key ENI
     */
    sai_uint8_t ENI;

} sai_inbound_eni_to_vm_entry_t;

/**
 * @brief Attribute ID for inbound_eni_to_vm_entry
 */
typedef enum _sai_inbound_eni_to_vm_entry_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_INBOUND_ENI_TO_VM_ENTRY_ATTR_START,

    /**
     * @brief Action set_vm_id parameter VM_ID
     *
     * @type sai_uint16_t
     * @flags CREATE_AND_SET
     * @isvlan false
     * @default 0
     */
    SAI_INBOUND_ENI_TO_VM_ENTRY_ATTR_VM_ID = SAI_INBOUND_ENI_TO_VM_ENTRY_ATTR_START,

    /**
     * @brief End of attributes
     */
    SAI_INBOUND_ENI_TO_VM_ENTRY_ATTR_END,

    /** Custom range base value */
    SAI_INBOUND_ENI_TO_VM_ENTRY_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_INBOUND_ENI_TO_VM_ENTRY_ATTR_CUSTOM_RANGE_END,

} sai_inbound_eni_to_vm_entry_attr_t;

/**
 * @brief Attribute ID for inbound_vm
 */
typedef enum _sai_inbound_vm_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_INBOUND_VM_ATTR_START,

    /**
     * @brief Action set_vm_attributes parameter UNDERLAY_DMAC
     *
     * @type sai_mac_t
     * @flags CREATE_AND_SET
     * @default 0:0:0:0:0:0
     */
    SAI_INBOUND_VM_ATTR_UNDERLAY_DMAC = SAI_INBOUND_VM_ATTR_START,

    /**
     * @brief Action set_vm_attributes parameter UNDERLAY_DIP
     *
     * @type sai_ip_address_t
     * @flags CREATE_AND_SET
     * @default 0.0.0.0
     */
    SAI_INBOUND_VM_ATTR_UNDERLAY_DIP,

    /**
     * @brief Action set_vm_attributes parameter VNI
     *
     * @type sai_uint32_t
     * @flags CREATE_AND_SET
     * @default 0
     */
    SAI_INBOUND_VM_ATTR_VNI,

    /**
     * @brief End of attributes
     */
    SAI_INBOUND_VM_ATTR_END,

    /** Custom range base value */
    SAI_INBOUND_VM_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_INBOUND_VM_ATTR_CUSTOM_RANGE_END,

} sai_inbound_vm_attr_t;

/**
 * @brief Attribute ID for inbound_acl_stage1
 */
typedef enum _sai_inbound_acl_stage1_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_INBOUND_ACL_STAGE1_ATTR_START,

    /**
     * @brief Action
     *
     * @type sai_inbound_acl_stage1_action_t
     * @flags CREATE_AND_SET
     * @default SAI_INBOUND_ACL_STAGE1_ACTION_PERMIT
     */
    SAI_INBOUND_ACL_STAGE1_ATTR_ACTION = SAI_INBOUND_ACL_STAGE1_ATTR_START,

    /**
     * @brief Exact matched key ENI
     *
     * @type sai_uint8_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_INBOUND_ACL_STAGE1_ATTR_ENI,

    /**
     * @brief List matched key dip
     *
     * @type sai_ip_address_list_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_INBOUND_ACL_STAGE1_ATTR_DIP,

    /**
     * @brief List matched key sip
     *
     * @type sai_ip_address_list_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_INBOUND_ACL_STAGE1_ATTR_SIP,

    /**
     * @brief List matched key protocol
     *
     * @type sai_u8_list_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_INBOUND_ACL_STAGE1_ATTR_PROTOCOL,

    /**
     * @brief Range_list matched key src_port
     *
     * @type sai_u16_range_list_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_INBOUND_ACL_STAGE1_ATTR_SRC_PORT,

    /**
     * @brief Range_list matched key dst_port
     *
     * @type sai_u16_range_list_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_INBOUND_ACL_STAGE1_ATTR_DST_PORT,

    /**
     * @brief End of attributes
     */
    SAI_INBOUND_ACL_STAGE1_ATTR_END,

    /** Custom range base value */
    SAI_INBOUND_ACL_STAGE1_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_INBOUND_ACL_STAGE1_ATTR_CUSTOM_RANGE_END,

} sai_inbound_acl_stage1_attr_t;

/**
 * @brief Attribute ID for inbound_acl_stage2
 */
typedef enum _sai_inbound_acl_stage2_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_INBOUND_ACL_STAGE2_ATTR_START,

    /**
     * @brief Action
     *
     * @type sai_inbound_acl_stage2_action_t
     * @flags CREATE_AND_SET
     * @default SAI_INBOUND_ACL_STAGE2_ACTION_PERMIT
     */
    SAI_INBOUND_ACL_STAGE2_ATTR_ACTION = SAI_INBOUND_ACL_STAGE2_ATTR_START,

    /**
     * @brief Exact matched key ENI
     *
     * @type sai_uint8_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_INBOUND_ACL_STAGE2_ATTR_ENI,

    /**
     * @brief List matched key dip
     *
     * @type sai_ip_address_list_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_INBOUND_ACL_STAGE2_ATTR_DIP,

    /**
     * @brief List matched key sip
     *
     * @type sai_ip_address_list_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_INBOUND_ACL_STAGE2_ATTR_SIP,

    /**
     * @brief List matched key protocol
     *
     * @type sai_u8_list_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_INBOUND_ACL_STAGE2_ATTR_PROTOCOL,

    /**
     * @brief Range_list matched key src_port
     *
     * @type sai_u16_range_list_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_INBOUND_ACL_STAGE2_ATTR_SRC_PORT,

    /**
     * @brief Range_list matched key dst_port
     *
     * @type sai_u16_range_list_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_INBOUND_ACL_STAGE2_ATTR_DST_PORT,

    /**
     * @brief End of attributes
     */
    SAI_INBOUND_ACL_STAGE2_ATTR_END,

    /** Custom range base value */
    SAI_INBOUND_ACL_STAGE2_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_INBOUND_ACL_STAGE2_ATTR_CUSTOM_RANGE_END,

} sai_inbound_acl_stage2_attr_t;

/**
 * @brief Attribute ID for inbound_acl_stage3
 */
typedef enum _sai_inbound_acl_stage3_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_INBOUND_ACL_STAGE3_ATTR_START,

    /**
     * @brief Action
     *
     * @type sai_inbound_acl_stage3_action_t
     * @flags CREATE_AND_SET
     * @default SAI_INBOUND_ACL_STAGE3_ACTION_PERMIT
     */
    SAI_INBOUND_ACL_STAGE3_ATTR_ACTION = SAI_INBOUND_ACL_STAGE3_ATTR_START,

    /**
     * @brief Exact matched key ENI
     *
     * @type sai_uint8_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_INBOUND_ACL_STAGE3_ATTR_ENI,

    /**
     * @brief List matched key dip
     *
     * @type sai_ip_address_list_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_INBOUND_ACL_STAGE3_ATTR_DIP,

    /**
     * @brief List matched key sip
     *
     * @type sai_ip_address_list_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_INBOUND_ACL_STAGE3_ATTR_SIP,

    /**
     * @brief List matched key protocol
     *
     * @type sai_u8_list_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_INBOUND_ACL_STAGE3_ATTR_PROTOCOL,

    /**
     * @brief Range_list matched key src_port
     *
     * @type sai_u16_range_list_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_INBOUND_ACL_STAGE3_ATTR_SRC_PORT,

    /**
     * @brief Range_list matched key dst_port
     *
     * @type sai_u16_range_list_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_INBOUND_ACL_STAGE3_ATTR_DST_PORT,

    /**
     * @brief End of attributes
     */
    SAI_INBOUND_ACL_STAGE3_ATTR_END,

    /** Custom range base value */
    SAI_INBOUND_ACL_STAGE3_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_INBOUND_ACL_STAGE3_ATTR_CUSTOM_RANGE_END,

} sai_inbound_acl_stage3_attr_t;

/**
 * @brief Create direction_lookup_entry
 *
 * @param[in] direction_lookup_entry Entry
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_create_direction_lookup_entry_fn)(
        _In_ const sai_direction_lookup_entry_t *direction_lookup_entry,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove direction_lookup_entry
 *
 * @param[in] direction_lookup_entry Entry
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_remove_direction_lookup_entry_fn)(
        _In_ const sai_direction_lookup_entry_t *direction_lookup_entry);

/**
 * @brief Set attribute for direction_lookup_entry
 *
 * @param[in] direction_lookup_entry Entry
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_set_direction_lookup_entry_attribute_fn)(
        _In_ const sai_direction_lookup_entry_t *direction_lookup_entry,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get attribute for direction_lookup_entry
 *
 * @param[in] direction_lookup_entry Entry
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_get_direction_lookup_entry_attribute_fn)(
        _In_ const sai_direction_lookup_entry_t *direction_lookup_entry,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Create eni_lookup_to_vm_entry
 *
 * @param[in] eni_lookup_to_vm_entry Entry
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_create_eni_lookup_to_vm_entry_fn)(
        _In_ const sai_eni_lookup_to_vm_entry_t *eni_lookup_to_vm_entry,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove eni_lookup_to_vm_entry
 *
 * @param[in] eni_lookup_to_vm_entry Entry
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_remove_eni_lookup_to_vm_entry_fn)(
        _In_ const sai_eni_lookup_to_vm_entry_t *eni_lookup_to_vm_entry);

/**
 * @brief Set attribute for eni_lookup_to_vm_entry
 *
 * @param[in] eni_lookup_to_vm_entry Entry
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_set_eni_lookup_to_vm_entry_attribute_fn)(
        _In_ const sai_eni_lookup_to_vm_entry_t *eni_lookup_to_vm_entry,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get attribute for eni_lookup_to_vm_entry
 *
 * @param[in] eni_lookup_to_vm_entry Entry
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_get_eni_lookup_to_vm_entry_attribute_fn)(
        _In_ const sai_eni_lookup_to_vm_entry_t *eni_lookup_to_vm_entry,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Create inbound_routing_entry
 *
 * @param[in] inbound_routing_entry Entry
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_create_inbound_routing_entry_fn)(
        _In_ const sai_inbound_routing_entry_t *inbound_routing_entry,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove inbound_routing_entry
 *
 * @param[in] inbound_routing_entry Entry
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_remove_inbound_routing_entry_fn)(
        _In_ const sai_inbound_routing_entry_t *inbound_routing_entry);

/**
 * @brief Set attribute for inbound_routing_entry
 *
 * @param[in] inbound_routing_entry Entry
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_set_inbound_routing_entry_attribute_fn)(
        _In_ const sai_inbound_routing_entry_t *inbound_routing_entry,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get attribute for inbound_routing_entry
 *
 * @param[in] inbound_routing_entry Entry
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_get_inbound_routing_entry_attribute_fn)(
        _In_ const sai_inbound_routing_entry_t *inbound_routing_entry,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Create pa_validation_entry
 *
 * @param[in] pa_validation_entry Entry
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_create_pa_validation_entry_fn)(
        _In_ const sai_pa_validation_entry_t *pa_validation_entry,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove pa_validation_entry
 *
 * @param[in] pa_validation_entry Entry
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_remove_pa_validation_entry_fn)(
        _In_ const sai_pa_validation_entry_t *pa_validation_entry);

/**
 * @brief Set attribute for pa_validation_entry
 *
 * @param[in] pa_validation_entry Entry
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_set_pa_validation_entry_attribute_fn)(
        _In_ const sai_pa_validation_entry_t *pa_validation_entry,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get attribute for pa_validation_entry
 *
 * @param[in] pa_validation_entry Entry
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_get_pa_validation_entry_attribute_fn)(
        _In_ const sai_pa_validation_entry_t *pa_validation_entry,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Create outbound_eni_lookup_from_vm_entry
 *
 * @param[in] outbound_eni_lookup_from_vm_entry Entry
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_create_outbound_eni_lookup_from_vm_entry_fn)(
        _In_ const sai_outbound_eni_lookup_from_vm_entry_t *outbound_eni_lookup_from_vm_entry,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove outbound_eni_lookup_from_vm_entry
 *
 * @param[in] outbound_eni_lookup_from_vm_entry Entry
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_remove_outbound_eni_lookup_from_vm_entry_fn)(
        _In_ const sai_outbound_eni_lookup_from_vm_entry_t *outbound_eni_lookup_from_vm_entry);

/**
 * @brief Set attribute for outbound_eni_lookup_from_vm_entry
 *
 * @param[in] outbound_eni_lookup_from_vm_entry Entry
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_set_outbound_eni_lookup_from_vm_entry_attribute_fn)(
        _In_ const sai_outbound_eni_lookup_from_vm_entry_t *outbound_eni_lookup_from_vm_entry,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get attribute for outbound_eni_lookup_from_vm_entry
 *
 * @param[in] outbound_eni_lookup_from_vm_entry Entry
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_get_outbound_eni_lookup_from_vm_entry_attribute_fn)(
        _In_ const sai_outbound_eni_lookup_from_vm_entry_t *outbound_eni_lookup_from_vm_entry,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Create outbound_eni_to_vni_entry
 *
 * @param[in] outbound_eni_to_vni_entry Entry
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_create_outbound_eni_to_vni_entry_fn)(
        _In_ const sai_outbound_eni_to_vni_entry_t *outbound_eni_to_vni_entry,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove outbound_eni_to_vni_entry
 *
 * @param[in] outbound_eni_to_vni_entry Entry
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_remove_outbound_eni_to_vni_entry_fn)(
        _In_ const sai_outbound_eni_to_vni_entry_t *outbound_eni_to_vni_entry);

/**
 * @brief Set attribute for outbound_eni_to_vni_entry
 *
 * @param[in] outbound_eni_to_vni_entry Entry
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_set_outbound_eni_to_vni_entry_attribute_fn)(
        _In_ const sai_outbound_eni_to_vni_entry_t *outbound_eni_to_vni_entry,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get attribute for outbound_eni_to_vni_entry
 *
 * @param[in] outbound_eni_to_vni_entry Entry
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_get_outbound_eni_to_vni_entry_attribute_fn)(
        _In_ const sai_outbound_eni_to_vni_entry_t *outbound_eni_to_vni_entry,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Create outbound_acl_stage1
 *
 * @param[out] outbound_acl_stage1_id Entry id
 * @param[in] switch_id Switch id
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_create_outbound_acl_stage1_fn)(
        _Out_ sai_object_id_t *outbound_acl_stage1_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove outbound_acl_stage1
 *
 * @param[in] outbound_acl_stage1_id Entry id
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_remove_outbound_acl_stage1_fn)(
        _In_ sai_object_id_t outbound_acl_stage1_id);

/**
 * @brief Set attribute for outbound_acl_stage1
 *
 * @param[in] outbound_acl_stage1_id Entry id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_set_outbound_acl_stage1_attribute_fn)(
        _In_ sai_object_id_t outbound_acl_stage1_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get attribute for outbound_acl_stage1
 *
 * @param[in] outbound_acl_stage1_id Entry id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_get_outbound_acl_stage1_attribute_fn)(
        _In_ sai_object_id_t outbound_acl_stage1_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Create outbound_acl_stage2
 *
 * @param[out] outbound_acl_stage2_id Entry id
 * @param[in] switch_id Switch id
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_create_outbound_acl_stage2_fn)(
        _Out_ sai_object_id_t *outbound_acl_stage2_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove outbound_acl_stage2
 *
 * @param[in] outbound_acl_stage2_id Entry id
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_remove_outbound_acl_stage2_fn)(
        _In_ sai_object_id_t outbound_acl_stage2_id);

/**
 * @brief Set attribute for outbound_acl_stage2
 *
 * @param[in] outbound_acl_stage2_id Entry id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_set_outbound_acl_stage2_attribute_fn)(
        _In_ sai_object_id_t outbound_acl_stage2_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get attribute for outbound_acl_stage2
 *
 * @param[in] outbound_acl_stage2_id Entry id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_get_outbound_acl_stage2_attribute_fn)(
        _In_ sai_object_id_t outbound_acl_stage2_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Create outbound_acl_stage3
 *
 * @param[out] outbound_acl_stage3_id Entry id
 * @param[in] switch_id Switch id
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_create_outbound_acl_stage3_fn)(
        _Out_ sai_object_id_t *outbound_acl_stage3_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove outbound_acl_stage3
 *
 * @param[in] outbound_acl_stage3_id Entry id
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_remove_outbound_acl_stage3_fn)(
        _In_ sai_object_id_t outbound_acl_stage3_id);

/**
 * @brief Set attribute for outbound_acl_stage3
 *
 * @param[in] outbound_acl_stage3_id Entry id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_set_outbound_acl_stage3_attribute_fn)(
        _In_ sai_object_id_t outbound_acl_stage3_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get attribute for outbound_acl_stage3
 *
 * @param[in] outbound_acl_stage3_id Entry id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_get_outbound_acl_stage3_attribute_fn)(
        _In_ sai_object_id_t outbound_acl_stage3_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Create outbound_routing_entry
 *
 * @param[in] outbound_routing_entry Entry
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_create_outbound_routing_entry_fn)(
        _In_ const sai_outbound_routing_entry_t *outbound_routing_entry,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove outbound_routing_entry
 *
 * @param[in] outbound_routing_entry Entry
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_remove_outbound_routing_entry_fn)(
        _In_ const sai_outbound_routing_entry_t *outbound_routing_entry);

/**
 * @brief Set attribute for outbound_routing_entry
 *
 * @param[in] outbound_routing_entry Entry
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_set_outbound_routing_entry_attribute_fn)(
        _In_ const sai_outbound_routing_entry_t *outbound_routing_entry,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get attribute for outbound_routing_entry
 *
 * @param[in] outbound_routing_entry Entry
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_get_outbound_routing_entry_attribute_fn)(
        _In_ const sai_outbound_routing_entry_t *outbound_routing_entry,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Create outbound_ca_to_pa_entry
 *
 * @param[in] outbound_ca_to_pa_entry Entry
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_create_outbound_ca_to_pa_entry_fn)(
        _In_ const sai_outbound_ca_to_pa_entry_t *outbound_ca_to_pa_entry,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove outbound_ca_to_pa_entry
 *
 * @param[in] outbound_ca_to_pa_entry Entry
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_remove_outbound_ca_to_pa_entry_fn)(
        _In_ const sai_outbound_ca_to_pa_entry_t *outbound_ca_to_pa_entry);

/**
 * @brief Set attribute for outbound_ca_to_pa_entry
 *
 * @param[in] outbound_ca_to_pa_entry Entry
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_set_outbound_ca_to_pa_entry_attribute_fn)(
        _In_ const sai_outbound_ca_to_pa_entry_t *outbound_ca_to_pa_entry,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get attribute for outbound_ca_to_pa_entry
 *
 * @param[in] outbound_ca_to_pa_entry Entry
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_get_outbound_ca_to_pa_entry_attribute_fn)(
        _In_ const sai_outbound_ca_to_pa_entry_t *outbound_ca_to_pa_entry,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Create inbound_eni_to_vm_entry
 *
 * @param[in] inbound_eni_to_vm_entry Entry
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_create_inbound_eni_to_vm_entry_fn)(
        _In_ const sai_inbound_eni_to_vm_entry_t *inbound_eni_to_vm_entry,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove inbound_eni_to_vm_entry
 *
 * @param[in] inbound_eni_to_vm_entry Entry
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_remove_inbound_eni_to_vm_entry_fn)(
        _In_ const sai_inbound_eni_to_vm_entry_t *inbound_eni_to_vm_entry);

/**
 * @brief Set attribute for inbound_eni_to_vm_entry
 *
 * @param[in] inbound_eni_to_vm_entry Entry
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_set_inbound_eni_to_vm_entry_attribute_fn)(
        _In_ const sai_inbound_eni_to_vm_entry_t *inbound_eni_to_vm_entry,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get attribute for inbound_eni_to_vm_entry
 *
 * @param[in] inbound_eni_to_vm_entry Entry
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_get_inbound_eni_to_vm_entry_attribute_fn)(
        _In_ const sai_inbound_eni_to_vm_entry_t *inbound_eni_to_vm_entry,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Create inbound_vm
 *
 * @param[out] inbound_vm_id Entry id
 * @param[in] switch_id Switch id
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_create_inbound_vm_fn)(
        _Out_ sai_object_id_t *inbound_vm_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove inbound_vm
 *
 * @param[in] inbound_vm_id Entry id
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_remove_inbound_vm_fn)(
        _In_ sai_object_id_t inbound_vm_id);

/**
 * @brief Set attribute for inbound_vm
 *
 * @param[in] inbound_vm_id Entry id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_set_inbound_vm_attribute_fn)(
        _In_ sai_object_id_t inbound_vm_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get attribute for inbound_vm
 *
 * @param[in] inbound_vm_id Entry id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_get_inbound_vm_attribute_fn)(
        _In_ sai_object_id_t inbound_vm_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Create inbound_acl_stage1
 *
 * @param[out] inbound_acl_stage1_id Entry id
 * @param[in] switch_id Switch id
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_create_inbound_acl_stage1_fn)(
        _Out_ sai_object_id_t *inbound_acl_stage1_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove inbound_acl_stage1
 *
 * @param[in] inbound_acl_stage1_id Entry id
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_remove_inbound_acl_stage1_fn)(
        _In_ sai_object_id_t inbound_acl_stage1_id);

/**
 * @brief Set attribute for inbound_acl_stage1
 *
 * @param[in] inbound_acl_stage1_id Entry id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_set_inbound_acl_stage1_attribute_fn)(
        _In_ sai_object_id_t inbound_acl_stage1_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get attribute for inbound_acl_stage1
 *
 * @param[in] inbound_acl_stage1_id Entry id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_get_inbound_acl_stage1_attribute_fn)(
        _In_ sai_object_id_t inbound_acl_stage1_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Create inbound_acl_stage2
 *
 * @param[out] inbound_acl_stage2_id Entry id
 * @param[in] switch_id Switch id
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_create_inbound_acl_stage2_fn)(
        _Out_ sai_object_id_t *inbound_acl_stage2_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove inbound_acl_stage2
 *
 * @param[in] inbound_acl_stage2_id Entry id
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_remove_inbound_acl_stage2_fn)(
        _In_ sai_object_id_t inbound_acl_stage2_id);

/**
 * @brief Set attribute for inbound_acl_stage2
 *
 * @param[in] inbound_acl_stage2_id Entry id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_set_inbound_acl_stage2_attribute_fn)(
        _In_ sai_object_id_t inbound_acl_stage2_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get attribute for inbound_acl_stage2
 *
 * @param[in] inbound_acl_stage2_id Entry id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_get_inbound_acl_stage2_attribute_fn)(
        _In_ sai_object_id_t inbound_acl_stage2_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Create inbound_acl_stage3
 *
 * @param[out] inbound_acl_stage3_id Entry id
 * @param[in] switch_id Switch id
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_create_inbound_acl_stage3_fn)(
        _Out_ sai_object_id_t *inbound_acl_stage3_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove inbound_acl_stage3
 *
 * @param[in] inbound_acl_stage3_id Entry id
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_remove_inbound_acl_stage3_fn)(
        _In_ sai_object_id_t inbound_acl_stage3_id);

/**
 * @brief Set attribute for inbound_acl_stage3
 *
 * @param[in] inbound_acl_stage3_id Entry id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_set_inbound_acl_stage3_attribute_fn)(
        _In_ sai_object_id_t inbound_acl_stage3_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get attribute for inbound_acl_stage3
 *
 * @param[in] inbound_acl_stage3_id Entry id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_get_inbound_acl_stage3_attribute_fn)(
        _In_ sai_object_id_t inbound_acl_stage3_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

typedef struct _sai_dash_api_t
{
    sai_create_direction_lookup_entry_fn                      create_direction_lookup_entry;
    sai_remove_direction_lookup_entry_fn                      remove_direction_lookup_entry;
    sai_set_direction_lookup_entry_attribute_fn               set_direction_lookup_entry_attribute;
    sai_get_direction_lookup_entry_attribute_fn               get_direction_lookup_entry_attribute;
    sai_create_eni_lookup_to_vm_entry_fn                      create_eni_lookup_to_vm_entry;
    sai_remove_eni_lookup_to_vm_entry_fn                      remove_eni_lookup_to_vm_entry;
    sai_set_eni_lookup_to_vm_entry_attribute_fn               set_eni_lookup_to_vm_entry_attribute;
    sai_get_eni_lookup_to_vm_entry_attribute_fn               get_eni_lookup_to_vm_entry_attribute;
    sai_create_inbound_routing_entry_fn                       create_inbound_routing_entry;
    sai_remove_inbound_routing_entry_fn                       remove_inbound_routing_entry;
    sai_set_inbound_routing_entry_attribute_fn                set_inbound_routing_entry_attribute;
    sai_get_inbound_routing_entry_attribute_fn                get_inbound_routing_entry_attribute;
    sai_create_pa_validation_entry_fn                         create_pa_validation_entry;
    sai_remove_pa_validation_entry_fn                         remove_pa_validation_entry;
    sai_set_pa_validation_entry_attribute_fn                  set_pa_validation_entry_attribute;
    sai_get_pa_validation_entry_attribute_fn                  get_pa_validation_entry_attribute;
    sai_create_outbound_eni_lookup_from_vm_entry_fn           create_outbound_eni_lookup_from_vm_entry;
    sai_remove_outbound_eni_lookup_from_vm_entry_fn           remove_outbound_eni_lookup_from_vm_entry;
    sai_set_outbound_eni_lookup_from_vm_entry_attribute_fn    set_outbound_eni_lookup_from_vm_entry_attribute;
    sai_get_outbound_eni_lookup_from_vm_entry_attribute_fn    get_outbound_eni_lookup_from_vm_entry_attribute;
    sai_create_outbound_eni_to_vni_entry_fn                   create_outbound_eni_to_vni_entry;
    sai_remove_outbound_eni_to_vni_entry_fn                   remove_outbound_eni_to_vni_entry;
    sai_set_outbound_eni_to_vni_entry_attribute_fn            set_outbound_eni_to_vni_entry_attribute;
    sai_get_outbound_eni_to_vni_entry_attribute_fn            get_outbound_eni_to_vni_entry_attribute;
    sai_create_outbound_acl_stage1_fn                         create_outbound_acl_stage1;
    sai_remove_outbound_acl_stage1_fn                         remove_outbound_acl_stage1;
    sai_set_outbound_acl_stage1_attribute_fn                  set_outbound_acl_stage1_attribute;
    sai_get_outbound_acl_stage1_attribute_fn                  get_outbound_acl_stage1_attribute;
    sai_create_outbound_acl_stage2_fn                         create_outbound_acl_stage2;
    sai_remove_outbound_acl_stage2_fn                         remove_outbound_acl_stage2;
    sai_set_outbound_acl_stage2_attribute_fn                  set_outbound_acl_stage2_attribute;
    sai_get_outbound_acl_stage2_attribute_fn                  get_outbound_acl_stage2_attribute;
    sai_create_outbound_acl_stage3_fn                         create_outbound_acl_stage3;
    sai_remove_outbound_acl_stage3_fn                         remove_outbound_acl_stage3;
    sai_set_outbound_acl_stage3_attribute_fn                  set_outbound_acl_stage3_attribute;
    sai_get_outbound_acl_stage3_attribute_fn                  get_outbound_acl_stage3_attribute;
    sai_create_outbound_routing_entry_fn                      create_outbound_routing_entry;
    sai_remove_outbound_routing_entry_fn                      remove_outbound_routing_entry;
    sai_set_outbound_routing_entry_attribute_fn               set_outbound_routing_entry_attribute;
    sai_get_outbound_routing_entry_attribute_fn               get_outbound_routing_entry_attribute;
    sai_create_outbound_ca_to_pa_entry_fn                     create_outbound_ca_to_pa_entry;
    sai_remove_outbound_ca_to_pa_entry_fn                     remove_outbound_ca_to_pa_entry;
    sai_set_outbound_ca_to_pa_entry_attribute_fn              set_outbound_ca_to_pa_entry_attribute;
    sai_get_outbound_ca_to_pa_entry_attribute_fn              get_outbound_ca_to_pa_entry_attribute;
    sai_create_inbound_eni_to_vm_entry_fn                     create_inbound_eni_to_vm_entry;
    sai_remove_inbound_eni_to_vm_entry_fn                     remove_inbound_eni_to_vm_entry;
    sai_set_inbound_eni_to_vm_entry_attribute_fn              set_inbound_eni_to_vm_entry_attribute;
    sai_get_inbound_eni_to_vm_entry_attribute_fn              get_inbound_eni_to_vm_entry_attribute;
    sai_create_inbound_vm_fn                                  create_inbound_vm;
    sai_remove_inbound_vm_fn                                  remove_inbound_vm;
    sai_set_inbound_vm_attribute_fn                           set_inbound_vm_attribute;
    sai_get_inbound_vm_attribute_fn                           get_inbound_vm_attribute;
    sai_create_inbound_acl_stage1_fn                          create_inbound_acl_stage1;
    sai_remove_inbound_acl_stage1_fn                          remove_inbound_acl_stage1;
    sai_set_inbound_acl_stage1_attribute_fn                   set_inbound_acl_stage1_attribute;
    sai_get_inbound_acl_stage1_attribute_fn                   get_inbound_acl_stage1_attribute;
    sai_create_inbound_acl_stage2_fn                          create_inbound_acl_stage2;
    sai_remove_inbound_acl_stage2_fn                          remove_inbound_acl_stage2;
    sai_set_inbound_acl_stage2_attribute_fn                   set_inbound_acl_stage2_attribute;
    sai_get_inbound_acl_stage2_attribute_fn                   get_inbound_acl_stage2_attribute;
    sai_create_inbound_acl_stage3_fn                          create_inbound_acl_stage3;
    sai_remove_inbound_acl_stage3_fn                          remove_inbound_acl_stage3;
    sai_set_inbound_acl_stage3_attribute_fn                   set_inbound_acl_stage3_attribute;
    sai_get_inbound_acl_stage3_attribute_fn                   get_inbound_acl_stage3_attribute;
} sai_dash_api_t;

/**
 * @}
 */
#endif /** __SAIEXPERIMENTALDASH_H_ */
