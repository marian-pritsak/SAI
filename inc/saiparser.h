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
 * @file    saiparser.h
 *
 * @brief   This module defines SAI parser interface
 */

#if !defined (__SAIPARSER_H_)
#define __SAIPARSER_H_

#include <saitypes.h>

/**
 * @brief SAI standard protocols
 */
typedef enum _sai_parser_common_header_type_t
{
    SAI_PARSER_COMMON_HEADER_TYPE_ETH = 0,
    SAI_PARSER_COMMON_HEADER_TYPE_IPV4 = 1,
    SAI_PARSER_COMMON_HEADER_TYPE_IPV6 = 2,
    SAI_PARSER_COMMON_HEADER_TYPE_UDP = 3,
    SAI_PARSER_COMMON_HEADER_TYPE_TCP = 4,
    SAI_PARSER_COMMON_HEADER_TYPE_GRE = 5,
    SAI_PARSER_COMMON_HEADER_TYPE_VXLAN = 6,
    SAI_PARSER_COMMON_HEADER_TYPE_VXLAN_GPE = 7,
    SAI_PARSER_COMMON_HEADER_TYPE_MPLS = 8,
    SAI_PARSER_COMMON_HEADER_TYPE_MAX = 9,
} sai_parser_common_header_type_t

/**
 * @brief Common header definition
 */
typedef struct _sai_parser_common_header_t
{
    /**
     * @brief Parser ID
     *
     * @objects SAI_OBJECT_TYPE_PARSER
     */
    sai_object_id_t parser_id;

    /** Header type */
    sai_parser_common_header_type_t header_type;

} sai_parser_common_header_t;

/**
 * @brief Attribute Id for parser object
 */
typedef enum _sai_parser_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_PARSER_ATTR_START,

    /**
     * @brief List of common supported headers.
     *
     * @type sai_s32_list_t[sai_parser_common_header_type_t]
     * @flags READ_ONLY
     */
    SAI_PARSER_ATTR_COMMON_HEADER_LIST = SAI_PARSER_ATTR_START,

    /**
     * @brief End of attributes
     */
    SAI_PARSER_ATTR_END,

    /** Custom range base value */
    SAI_PARSER_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_PARSER_ATTR_CUSTOM_RANGE_END

} sai_parser_attr_t;

/**
 * @brief Attribute Id for parser header object
 */
typedef enum _sai_parser_header_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_PARSER_HEADER_ATTR_START,

    /**
     * @brief Parser ID
     *
     * @type sai_object_id_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     * @objects SAI_OBJECT_TYPE_PARSER
     */
    SAI_PARSER_HEADER_ATTR_PARSER_ID = SAI_PARSER_HEADER_ATTR_START,

    /**
     * @brief TODO - Header length
     *
     */
    SAI_PARSER_HEADER_ATTR_LENGTH,

    /**
     * @brief TODO - Next Header field
     *
     */
    SAI_PARSER_HEADER_ATTR_NEXT_HEADER,

    /**
     * @brief End of attributes
     */
    SAI_PARSER_ATTR_END,

    /** Custom range base value */
    SAI_PARSER_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_PARSER_ATTR_CUSTOM_RANGE_END

} sai_parser_header_attr_t;

/**
 * @brief Attribute Id for parser transition object
 */
typedef enum _sai_parser_transition_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_PARSER_TRANSITION_ATTR_START,

    /**
     * @brief Flag saying if the from header is common or custom
     *
     * @type sai_boolean_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_PARSER_TRANSITION_ATTR_FROM_HEADER_COMMON = SAI_PARSER_FIELD_ATTR_START,

    /**
     * @brief Common from header ID
     *
     * @type sai_parser_common_header_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     * @validonly SAI_PARSER_TRANSITION_ATTR_FROM_HEADER_COMMON == true
     */
    SAI_PARSER_TRANSITION_ATTR_COMMON_FROM_HEADER_ID,

    /**
     * @brief Custom from header ID
     *
     * @type sai_object_id_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     * @objects SAI_OBJECT_TYPE_PARSER_HEADER
     * @validonly SAI_PARSER_TRANSITION_ATTR_FROM_HEADER_COMMON == false
     */
    SAI_PARSER_TRANSITION_ATTR_CUSTOM_FROM_HEADER_ID,

    /**
     * @brief Flag saying ig the from to is common or custom
     *
     * @type sai_boolean_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_PARSER_TRANSITION_ATTR_TO_HEADER_COMMON,

    /**
     * @brief Common to header ID
     *
     * @type sai_parser_common_header_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     * @validonly SAI_PARSER_TRANSITION_ATTR_TO_HEADER_COMMON == true
     */
    SAI_PARSER_TRANSITION_ATTR_COMMON_TO_HEADER_ID,

    /**
     * @brief Custom to header ID
     *
     * @type sai_object_id_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     * @objects SAI_OBJECT_TYPE_PARSER_HEADER
     * @validonly SAI_PARSER_TRANSITION_ATTR_TO_HEADER_COMMON == false
     */
    SAI_PARSER_TRANSITION_ATTR_CUSTOM_TO_HEADER_ID,

    /**
     * @brief Transition value
     *
     * @type sai_uint16_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_PARSER_TRANSITION_ATTR_VALUE,

    /**
     * @brief End of attributes
     */
    SAI_PARSER_TRANSITION_ATTR_END,

    /** Custom range base value */
    SAI_PARSER_TRANSITION_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_PARSER_TRANSITION_ATTR_CUSTOM_RANGE_END

} sai_parser_transition_attr_t;

/**
 * @brief Attribute Id for parser field object
 */
typedef enum _sai_parser_field_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_PARSER_FIELD_ATTR_START,

    /**
     * @brief Flag saying ig the header field is common or custom
     *
     * @type sai_boolean_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_PARSER_FIELD_ATTR_HEADER_COMMON = SAI_PARSER_FIELD_ATTR_START,

    /**
     * @brief Common header ID
     *
     * @type sai_parser_common_header_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     * @validonly SAI_PARSER_FIELD_ATTR_HEADER_COMMON == true
     */
    SAI_PARSER_FIELD_ATTR_COMMON_HEADER_ID,

    /**
     * @brief Custom header ID
     *
     * @type sai_object_id_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     * @objects SAI_OBJECT_TYPE_PARSER_HEADER
     * @validonly SAI_PARSER_FIELD_ATTR_HEADER_COMMON == false
     */
    SAI_PARSER_FIELD_ATTR_CUSTOM_HEADER_ID,

    /**
     * @brief Offset from the header start in bytes (TODO bits as well)
     *
     * @type sai_uint32_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_PARSER_FIELD_ATTR_OFFSET,

    /**
     * @brief Field size in bytes (TODO how to deal with not byte aligned)
     *
     * @type sai_uint32_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_PARSER_FIELD_ATTR_OFFSET,

    /**
     * @brief End of attributes
     */
    SAI_PARSER_FIELD_ATTR_END,

    /** Custom range base value */
    SAI_PARSER_FIELD_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_PARSER_FIELD_ATTR_CUSTOM_RANGE_END

} sai_parser_field_attr_t;

/**
 * @brief Create parser
 *
 * @param[out] parser_id parser id
 * @param[in] switch_id Switch id
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_create_parser_fn)(
        _Out_ sai_object_id_t *parser_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove parser
 *
 * @param[in] parser_id parser id
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_remove_parser_fn)(
        _In_ sai_object_id_t parser_id);

/**
 * @brief Set parser attribute
 *
 * @param[in] parser_id parser id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_set_parser_attribute_fn)(
        _In_ sai_object_id_t parser_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get parser attribute
 *
 * @param[in] parser_id parser id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_parser_attribute_fn)(
        _In_ sai_object_id_t parser_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Create parser header
 *
 * @param[out] parser_header_id parser header id
 * @param[in] switch_id Switch id
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_create_parser_header_fn)(
        _Out_ sai_object_id_t *parser_header_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove parser header
 *
 * @param[in] parser_header_id parser header id
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_remove_parser_header_fn)(
        _In_ sai_object_id_t parser_header_id);

/**
 * @brief Set parser header attribute
 *
 * @param[in] parser_header_id parser header id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_set_parser_header_attribute_fn)(
        _In_ sai_object_id_t parser_header_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get parser header attribute
 *
 * @param[in] parser_header_id parser header id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_parser_header_attribute_fn)(
        _In_ sai_object_id_t parser_header_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Create parser transition
 *
 * @param[out] parser_transition_id parser transition id
 * @param[in] switch_id Switch id
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_create_parser_transition_fn)(
        _Out_ sai_object_id_t *parser_transition_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove parser transition
 *
 * @param[in] parser_transition_id parser transition id
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_remove_parser_transition_fn)(
        _In_ sai_object_id_t parser_transition_id);

/**
 * @brief Set parser transition attribute
 *
 * @param[in] parser_transition_id parser transition id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_set_parser_transition_attribute_fn)(
        _In_ sai_object_id_t parser_transition_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get parser transition attribute
 *
 * @param[in] parser_transition_id parser transition id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_parser_transition_attribute_fn)(
        _In_ sai_object_id_t parser_transition_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Create parser field
 *
 * @param[out] parser_field_id parser field id
 * @param[in] switch_id Switch id
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_create_parser_field_fn)(
        _Out_ sai_object_id_t *parser_field_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove parser field
 *
 * @param[in] parser_field_id parser field id
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_remove_parser_field_fn)(
        _In_ sai_object_id_t parser_field_id);

/**
 * @brief Set parser field attribute
 *
 * @param[in] parser_field_id parser field id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_set_parser_field_attribute_fn)(
        _In_ sai_object_id_t parser_field_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get parser field attribute
 *
 * @param[in] parser_field_id parser field id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_parser_field_attribute_fn)(
        _In_ sai_object_id_t parser_field_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief parser methods table retrieved with sai_api_query()
 */
typedef struct _sai_parser_api_t
{
    sai_create_parser_fn                   create_parser;
    sai_remove_parser_fn                   remove_parser;
    sai_set_parser_attribute_fn            set_parser_attribute;
    sai_get_parser_attribute_fn            get_parser_attribute;
    sai_create_parser_header_fn            create_header_parser;
    sai_remove_parser_header_fn            remove_header_parser;
    sai_set_parser_header_attribute_fn     set_parser_header_attribute;
    sai_get_parser_header_attribute_fn     get_parser_header_attribute;
    sai_create_parser_transition_fn        create_transition_parser;
    sai_remove_parser_transition_fn        remove_transition_parser;
    sai_set_parser_transition_attribute_fn set_parser_transition_attribute;
    sai_get_parser_transition_attribute_fn get_parser_transition_attribute;
    sai_create_parser_field_fn            create_field_parser;
    sai_remove_parser_field_fn            remove_field_parser;
    sai_set_parser_field_attribute_fn     set_parser_field_attribute;
    sai_get_parser_field_attribute_fn     get_parser_field_attribute;

} sai_parser_api_t;

/**
 * @}
 */
#endif /** __SAIPARSER_H_ */
