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
 * @file    saiqosmap.h
 *
 * @brief   This module defines SAI QOS Maps interface
 */

#if !defined (__SAIQOSMAP_H_)
#define __SAIQOSMAP_H_

#include <saitypes.h>

/**
 * @defgroup SAIQOSMAPS SAI - QOS Maps specific API definitions.
 *
 * @{
 */

/**
 * @brief Enum defining QOS map types.
 */
typedef enum _sai_qos_map_type_t
{
    /** QOS Map to set DOT1P to Traffic class */
    SAI_QOS_MAP_TYPE_DOT1P_TO_TC = 0x00000000,

    /** QOS Map to set DOT1P to color */
    SAI_QOS_MAP_TYPE_DOT1P_TO_COLOR = 0x00000001,

    /** QOS Map to set DSCP to Traffic class */
    SAI_QOS_MAP_TYPE_DSCP_TO_TC = 0x00000002,

    /** QOS Map to set DSCP to color */
    SAI_QOS_MAP_TYPE_DSCP_TO_COLOR = 0x00000003,

    /** QOS Map to set traffic class to queue */
    SAI_QOS_MAP_TYPE_TC_TO_QUEUE = 0x00000004,

    /** QOS Map to set traffic class and color to DSCP */
    SAI_QOS_MAP_TYPE_TC_AND_COLOR_TO_DSCP = 0x00000005,

    /** QOS Map to set traffic class and color to DSCP */
    SAI_QOS_MAP_TYPE_TC_AND_COLOR_TO_DOT1P = 0x00000006,

    /** QOS Map to set traffic class to priority group */
    SAI_QOS_MAP_TYPE_TC_TO_PRIORITY_GROUP = 0x00000007,

    /** QOS Map to set PFC priority to priority group */
    SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_PRIORITY_GROUP = 0x00000008,

    /** QOS Map to set PFC priority to queue */
    SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_QUEUE = 0x00000009,

    /** QOS Map to set EXP to Traffic class */
    SAI_QOS_MAP_TYPE_MPLS_EXP_TO_TC = 0x0000000a,

    /** QOS Map to set EXP to color */
    SAI_QOS_MAP_TYPE_MPLS_EXP_TO_COLOR = 0x0000000b,

    /** QOS Map to set traffic class and color to EXP */
    SAI_QOS_MAP_TYPE_TC_AND_COLOR_TO_MPLS_EXP = 0x0000000c,

    /** QOS Map to set DSCP to Forwarding class */
    SAI_QOS_MAP_TYPE_DSCP_TO_FORWARDING_CLASS = 0x0000000d,

    /** QOS Map to set EXP to Forwarding class */
    SAI_QOS_MAP_TYPE_MPLS_EXP_TO_FORWARDING_CLASS = 0x0000000e,

    /** QOS Map to set traffic class and ingress port to queue */
    SAI_QOS_MAP_TYPE_TC_AND_INGRESS_PORT_TO_QUEUE = 0x0000000f,

    /** QOS Map to set queue and color to DSCP */
    SAI_QOS_MAP_TYPE_TC_AND_INGRESS_PORT_AND_COLOR_TO_DSCP = 0x00000010,

    /** Custom range base value */
    SAI_QOS_MAP_TYPE_CUSTOM_RANGE_BASE = 0x10000000

} sai_qos_map_type_t;

typedef enum _sai_qos_map_entry_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_QOS_MAP_ENTRY_ATTR_START = 0x00000000,

    /**
     * @brief QOS Map type
     *
     * @type sai_qos_map_type_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_QOS_MAP_ENTRY_ATTR_QOS_MAP_TYPE = SAI_QOS_MAP_ENTRY_ATTR_START,

    /**
     * @brief QOS map ID
     *
     * @type sai_object_id_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     * @objects SAI_OBJECT_TYPE_QOS_MAP
     */
    SAI_QOS_MAP_ENTRY_ATTR_QOS_MAP = 0x00000001,

    /**
     * @brief TC key
     *
     * @type sai_uint8_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     * @condition SAI_QOS_MAP_ENTRY_ATTR_QOS_MAP_TYPE == SAI_QOS_MAP_TYPE_TC_AND_INGRESS_PORT_TO_QUEUE or SAI_QOS_MAP_ENTRY_ATTR_QOS_MAP_TYPE == SAI_QOS_MAP_TYPE_TC_AND_INGRESS_PORT_AND_COLOR_TO_DSCP
     */
    SAI_QOS_MAP_ENTRY_ATTR_KEY_TC = 0x00000002,

    /**
     * @brief Ingress port list
     *
     * @type sai_object_list_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     * @objects SAI_OBJECT_TYPE_PORT
     * @condition SAI_QOS_MAP_ENTRY_ATTR_QOS_MAP_TYPE == SAI_QOS_MAP_TYPE_TC_AND_INGRESS_PORT_TO_QUEUE or SAI_QOS_MAP_ENTRY_ATTR_QOS_MAP_TYPE == SAI_QOS_MAP_TYPE_TC_AND_INGRESS_PORT_AND_COLOR_TO_DSCP
     */
    SAI_QOS_MAP_ENTRY_ATTR_KEY_INGRESS_PORT_LIST = 0x00000003,

    /**
     * @brief Packet color key
     *
     * @type sai_packet_color_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     * @condition SAI_QOS_MAP_ENTRY_ATTR_QOS_MAP_TYPE == SAI_QOS_MAP_TYPE_TC_AND_INGRESS_PORT_AND_COLOR_TO_DSCP
     */
    SAI_QOS_MAP_ENTRY_ATTR_KEY_PACKET_COLOR = 0x00000004,

    /**
     * @brief Queue index value
     *
     * @type sai_uint8_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     * @condition SAI_QOS_MAP_ENTRY_ATTR_QOS_MAP_TYPE == SAI_QOS_MAP_TYPE_TC_AND_INGRESS_PORT_TO_QUEUE
     */
    SAI_QOS_MAP_ENTRY_ATTR_VALUE_QUEUE_INDEX = 0x00000005,

    /**
     * @brief DSCP value
     *
     * @type sai_uint8_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     * @condition SAI_QOS_MAP_ENTRY_ATTR_QOS_MAP_TYPE == SAI_QOS_MAP_TYPE_TC_AND_INGRESS_PORT_AND_COLOR_TO_DSCP
     */
    SAI_QOS_MAP_ENTRY_ATTR_VALUE_DSCP = 0x00000006,

    /**
     * @brief End of attributes
     */
    SAI_QOS_MAP_ENTRY_ATTR_END,

    /** Custom range base value */
    SAI_QOS_MAP_ENTRY_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_QOS_MAP_ENTRY_ATTR_CUSTOM_RANGE_END

} sai_qos_map_entry_attr_t;

/**
 * @brief Enum defining attributes for QOS Maps.
 */
typedef enum _sai_qos_map_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_QOS_MAP_ATTR_START,

    /**
     * @brief QOS Map type
     *
     * @type sai_qos_map_type_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_QOS_MAP_ATTR_TYPE = SAI_QOS_MAP_ATTR_START,

    /**
     * @brief Dot1p to TC Mapping
     *
     * Defaults:
     * - All Dot1p/DSCP maps to traffic class 0
     * - All Dot1p/DSCP maps to color #SAI_PACKET_COLOR_GREEN
     * - All traffic class maps to queue 0
     *
     * @type sai_qos_map_list_t
     * @flags MANDATORY_ON_CREATE | CREATE_AND_SET
     */
    SAI_QOS_MAP_ATTR_MAP_TO_VALUE_LIST = 0x00000001,

    /**
     * @brief QOS map entries associated with this map.
     *
     * @type sai_object_list_t
     * @flags READ_ONLY
     * @objects SAI_OBJECT_TYPE_QOS_MAP_ENTRY
     */
    SAI_QOS_MAP_ATTR_ENTRY_LIST = 0x00000002,

    /**
     * @brief End of attributes
     */
    SAI_QOS_MAP_ATTR_END,

    /** Custom range base value */
    SAI_QOS_MAP_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_QOS_MAP_ATTR_CUSTOM_RANGE_END

} sai_qos_map_attr_t;

/**
 * @brief Create QOS Map
 *
 * @param[out] qos_map_id QOS Map Id
 * @param[in] switch_id Switch id
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_create_qos_map_fn)(
        _Out_ sai_object_id_t *qos_map_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove QOS Map
 *
 * @param[in] qos_map_id QOS Map id to be removed.
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_remove_qos_map_fn)(
        _In_ sai_object_id_t qos_map_id);

/**
 * @brief Set attributes for QOS map
 *
 * @param[in] qos_map_id QOS Map Id
 * @param[in] attr Attribute to set
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_set_qos_map_attribute_fn)(
        _In_ sai_object_id_t qos_map_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get attributes of QOS map
 *
 * @param[in] qos_map_id Map id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_qos_map_attribute_fn)(
        _In_ sai_object_id_t qos_map_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Create QOS map item
 *
 * @param[out] qos_map_entry_id QOS map item id
 * @param[in] switch_id Switch Id
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_create_qos_map_entry_fn)(
        _Out_ sai_object_id_t *qos_map_entry_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove QOS map item
 *
 * @param[in] qos_map_entry_id QOS map item id
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_remove_qos_map_entry_fn)(
        _In_ sai_object_id_t qos_map_entry_id);

/**
 * @brief Set QOS map item attribute
 *
 * @param[in] qos_map_entry_id QOS map item id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_set_qos_map_entry_attribute_fn)(
        _In_ sai_object_id_t qos_map_entry_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get QOS map item attributes
 *
 * @param[in] qos_map_entry_id QOS map item id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_qos_map_entry_attribute_fn)(
        _In_ sai_object_id_t qos_map_entry_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief QOS Map methods table retrieved with sai_api_query()
 */
typedef struct _sai_qos_map_api_t
{
    sai_create_qos_map_fn               create_qos_map;
    sai_remove_qos_map_fn               remove_qos_map;
    sai_set_qos_map_attribute_fn        set_qos_map_attribute;
    sai_get_qos_map_attribute_fn        get_qos_map_attribute;
    sai_create_qos_map_entry_fn         create_qos_map_entry;
    sai_remove_qos_map_entry_fn         remove_qos_map_entry;
    sai_set_qos_map_entry_attribute_fn  set_qos_map_entry_attribute;
    sai_get_qos_map_entry_attribute_fn  get_qos_map_entry_attribute;

} sai_qos_map_api_t;

/**
 * @}
 */
#endif /** __SAIQOSMAP_H_ */
