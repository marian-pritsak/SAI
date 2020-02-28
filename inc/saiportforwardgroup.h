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
 * @file    saiportforwardgroup.h
 *
 * @brief   This module defines SAI Port Forward Group interface
 */

#if !defined (__SAIPORTFORWARDGROUP_H_)
#define __SAIPORTFORWARDGROUP_H_

#include <saitypes.h>

/**
 * @brief port forward group entry
 */
typedef struct _sai_port_forward_group_entry_t
{
    /**
     * @brief Port ID
     *
     * @objects SAI_OBJECT_TYPE_PORT
     */
    sai_object_id_t port_id;

    /**
     * @brief Entry's weight
     *
     * @type sai_uint32_t
     */
    sai_uint32_t weight;

} sai_port_forward_group_entry_t;

/**
 * @brief port forward group entry list
 */
typedef struct _sai_port_forward_group_entry_list_t
{
    /**
     * @brief Port forward entry list
     */
    sai_port_forward_group_entry_t *list;

    /**
     * @brief Entry count
     *
     * @type sai_uint32_t
     */
    sai_uint32_t count;

} sai_port_forward_group_entry_list_t;

/**
 * @brief Attribute Id for port forward group entry
 */
typedef enum _sai_port_forward_group_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_PORT_FORWARD_GROUP_ATTR_START,

    /**
     * @brief Port forward group size
     *
     * @type sai_uint32_t
     * @flags CREATE_ONLY
     * @default 512
     */
    SAI_PORT_FORWARD_GROUP_ATTR_SIZE,

    /**
     * @brief Port forward group entry list
     *
     * This list's size does not have to match the group size,
     * the SAI driver will adjust accordingly
     *
     * @type sai_port_forward_group_entry_list_t
     * @flags CREATE_AND_SET
     * @allownull true
     */
    SAI_PORT_FORWARD_GROUP_ATTR_ENTRY_LIST,

    /**
     * @brief End of attributes
     */
    SAI_PORT_FORWARD_GROUP_ATTR_END,

    /** Start of custom range base value */
    SAI_PORT_FORWARD_GROUP_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range */
    SAI_FPORT_FORWARD_GROUP_ATTR_CUSTOM_RANGE_END

} sai_port_forward_group_attr_t;

/**
 * @brief Create port forward group
 *
 * @param[in] port_forward_group port forward group
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_create_port_forward_group_fn)(
        _In_ const sai_object_id_t *port_forward_group,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove port forward group
 *
 * @param[in] port_forward_group port forward group
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_remove_port_forward_group_fn)(
        _In_ const sai_object_id_t *port_forward_group);

/**
 * @brief Set port forward group attribute value
 *
 * @param[in] port_forward_group port forward group
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_set_port_forward_group_attribute_fn)(
        _In_ const sai_object_id_t *port_forward_group,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get port forward group attribute value
 *
 * @param[in] port_forward_group port forward group
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_port_forward_group_attribute_fn)(
        _In_ const sai_object_id_t *port_forward_group,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief port forward entry method table retrieved with sai_api_query()
 */
typedef struct _sai_port_forward_group_api_t
{
    sai_create_port_forward_group_fn        create_port_forward_group;
    sai_remove_port_forward_group_fn        remove_port_forward_group;
    sai_set_port_forward_group_attribute_fn set_port_forward_group_attribute;
    sai_get_port_forward_group_attribute_fn get_port_forward_group_attribute;

} sai_port_forward_group_api_t;

/**
 * @}
 */
#endif /** __SAIPORTFORWARDGROUP_H_ */
