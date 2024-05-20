/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.8 */

#ifndef PB_REMOTEAPIRS232_COFFEE_MACHINE_PB_H_INCLUDED
#define PB_REMOTEAPIRS232_COFFEE_MACHINE_PB_H_INCLUDED
#include <pb.h>

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Enum definitions */
typedef enum _RemoteApiRs232_ResponseCode {
    RemoteApiRs232_ResponseCode_UNKOWN_RESPONSE_CODE = 0, /* Place holder for protobuf */
    RemoteApiRs232_ResponseCode_SUCCESS = 1, /* The request succeeded */
    RemoteApiRs232_ResponseCode_INALID_PARAMETER = 2, /* One of the given parameters is invalid */
    RemoteApiRs232_ResponseCode_DBUS_ADAPTER_ERROR = 3, /* A failure occured in the communication between the remote API comonent and the Application */
    RemoteApiRs232_ResponseCode_GENERAL_ERROR = 4, /* The request failed due to not further specified issues */
    RemoteApiRs232_ResponseCode_SERVICE_LIMITED = 5, /* The request might be valid but the cloud connection was cut longer than allowed and thus the service is now only limited */
    RemoteApiRs232_ResponseCode_SYSTEM_BUSY = 100, /* The application is currently completing another request and can't execute this request */
    RemoteApiRs232_ResponseCode_UNKOWN_PRODUCT_ID = 101, /* The product id specified in a request is not known */
    RemoteApiRs232_ResponseCode_PRODUCT_NOT_AVAILABLE = 102, /* The product is known but cannot be poured at the moment */
    RemoteApiRs232_ResponseCode_PRODUCT_ID_NOT_POURING = 103, /* The product ID requested to cancel is not pouring at the moment */
    RemoteApiRs232_ResponseCode_MAX_POSTPONE_NUM_REACHED = 104, /* The maximum number of rinse postponements 15 reached */
    RemoteApiRs232_ResponseCode_NO_RINSING_UPCOMING = 105 /* No rinsing is upcoming and thus nothing will be postponed */
} RemoteApiRs232_ResponseCode;

/* Struct definitions */
/* *
 Request to start pouring a new product. The matching response is the
 'ProductStarted' message. */
typedef struct _RemoteApiRs232_StartProduct {
    pb_callback_t prudct_id; /* The product id of the product to be started */
    double start_delay_s; /* A delay after which the pouring should start */
} RemoteApiRs232_StartProduct;

/* *
 Request to cancel a pouring product. The matching response is the
 'ProductCancelled' message. */
typedef struct _RemoteApiRs232_CancelProduct {
    pb_callback_t product_id; /* The product id of the product to be cancelled */
    double cancel_delay_s; /* A dely after which the cancellation should start */
} RemoteApiRs232_CancelProduct;

/* *
 Request to start pouring a new product category. The matching response is the
 'ProductCategoryByNameStarted' message. */
typedef struct _RemoteApiRs232_StartProductCategoryByName {
    pb_callback_t product_name; /* The product category name of the product to be started */
    double start_delay_s; /* A delay after which the pouring should start */
} RemoteApiRs232_StartProductCategoryByName;

/* *
 Request to get a List of all known products with their ids and product names.
 The matching response is the 'ProductlList’ message. */
typedef struct _RemoteApiRs232_GetProductList {
    char dummy_field;
} RemoteApiRs232_GetProductList;

/* *
 Request to get a List of all available product ids.
 The matching response is the 'AvailableProductIds' message. */
typedef struct _RemoteApiRs232_GetAvailableProductIds {
    char dummy_field;
} RemoteApiRs232_GetAvailableProductIds;

/* *
 Request to get a List of all active events.
 The matching response is the 'ActiveEvents' message. */
typedef struct _RemoteApiRs232_GetActiveEvents {
    char dummy_field;
} RemoteApiRs232_GetActiveEvents;

/* *
 Request to force a rinse now.
 The matching response 15 the 'RinseForced’ message. */
typedef struct _RemoteApiRs232_ForceRinse {
    char dummy_field;
} RemoteApiRs232_ForceRinse;

/* *
 Request to postpone the next upcoming rinse by the specified number of milliseconds.
 The matching response is the 'RinsePostponed’ message. */
typedef struct _RemoteApiRs232_PostponeRinse {
    uint32_t milliseconds; /* Number of milliseconds the next rinse is postponed. */
} RemoteApiRs232_PostponeRinse;

/* *
 Request to get the current SW version.
 The matching response is the 'SwVersion' message. */
typedef struct _RemoteApiRs232_GetSwVersion {
    char dummy_field;
} RemoteApiRs232_GetSwVersion;

/* *
 Response message for the 'StartProduct' message.

 The response_code shows whether the start was successful or not. Once
 the product has completed pouring */
typedef struct _RemoteApiRs232_ProductStarted {
    RemoteApiRs232_ResponseCode response_code;
} RemoteApiRs232_ProductStarted;

/* *
 Response message for the 'StartProductCategoryByName' message.

 The response_code shows whether the start was successful or not. Once
 the product has completed pouring */
typedef struct _RemoteApiRs232_ProductCategoryByNameStarted {
    RemoteApiRs232_ResponseCode response_code;
} RemoteApiRs232_ProductCategoryByNameStarted;

/* *
 Response message for the 'CancelProduct' message.

 The response_code shows whether the cancellation was successful or not. Once
 the product has completed cancelling */
typedef struct _RemoteApiRs232_ProductCancelled {
    RemoteApiRs232_ResponseCode response_code;
} RemoteApiRs232_ProductCancelled;

typedef struct _RemoteApiRs232_ProductList {
    /* The response_code shows whether the 'GetProductlList' request
 was successfull */
    RemoteApiRs232_ResponseCode response_code;
    /* key contains the product names as shown on the UI, value
 contains the product 10 needed by the 'StartProduct’ message */
    pb_callback_t product_list;
} RemoteApiRs232_ProductList;

typedef struct _RemoteApiRs232_ProductList_ProductListEntry {
    pb_callback_t key;
    pb_callback_t value;
} RemoteApiRs232_ProductList_ProductListEntry;

typedef struct _RemoteApiRs232_AvailableProductIds {
    /* The response_code shows whether the 'GetAvailableProductIds' request
 was successfull */
    RemoteApiRs232_ResponseCode response_code;
    /* list contains the product ids */
    pb_callback_t available_product_ids;
} RemoteApiRs232_AvailableProductIds;

typedef struct _RemoteApiRs232_ActiveEvents {
    /* The response_code shows whether the 'GetActiveEvents' request
 was successfull */
    RemoteApiRs232_ResponseCode response_code;
    /* list contains tuples of the number, title and source index of events */
    pb_callback_t active_events;
} RemoteApiRs232_ActiveEvents;

typedef struct _RemoteApiRs232_RinseForced {
    /* The response_code shows whether the 'ForceRinse’ request
 was successfull */
    RemoteApiRs232_ResponseCode response_code;
} RemoteApiRs232_RinseForced;

typedef struct _RemoteApiRs232_RinsePostponed {
    /* The response_code shows whether the 'PostponeRinse’ request
 was successfull */
    RemoteApiRs232_ResponseCode response_code;
} RemoteApiRs232_RinsePostponed;

typedef struct _RemoteApiRs232_SwVersion {
    /* The response_code shows whether the 'GetSwVersion' request
 was successfull */
    RemoteApiRs232_ResponseCode response_code;
    /* list contains the product ids */
    pb_callback_t sw_version;
} RemoteApiRs232_SwVersion;

/* *
 A message indicating a status change on the coffee machine. The meaning
 of the error numbers is described in a separate place. The numbers
 consist of error conditions as well 05 the disappearance of such error
 conditions.
 The 'tittle' field contains an english error message that describes
 the error condition related to the 'error_number'.
 The 'source_index' may contain more details in case the component
 causing the error exists multiple times. For example when 0 bean hopper
 is removed, the 'source_index' will tell you, which bean hopper was
 removed (0 or 1). In these 60565 the 'title’ will usually contain a '%1'
 at the place where 'source_index' should be included. */
typedef struct _RemoteApiRs232_ErrorEvent {
    uint32_t error_number; /* number identifying the error condition */
    pb_callback_t title; /* text describing the error related to the error number */
    uint32_t source_index; /* index describing the source of the error in some more details */
} RemoteApiRs232_ErrorEvent;

/* *
 Event to tell the remote client when a product has finished. Such
 events are sent for products started through the API as well as
 any products or rinse-operations started through the UI. */
typedef struct _RemoteApiRs232_ProductFinished {
    /* The product 10 of the product that has finished */
    pb_callback_t product_id;
    /* A flag indicating whether the product was poured successfully */
    bool success;
} RemoteApiRs232_ProductFinished;

/* *
 Event message indicating the changed availability of products.
 Unavailable products are still known on the machine, however
 when trying to the start such a product, the machine will report
 PRODUCT_NOT_AVAILABLE. The reason for a product not being
 available is usually someting Like an empty milk container, a
 boiler temperature that has not yet been reached. A corresponding
 Errortvent has then been sent as well.
 The field 'product_ids’ will always contain a complete List of
 available products. Thus the unavailable products will be the
List of products reported by 'ProductlList’ without those in the
 'ProductAvailabilityChanged’ message. */
typedef struct _RemoteApiRs232_ProductAvailabilityChanged {
    pb_callback_t product_ids;
} RemoteApiRs232_ProductAvailabilityChanged;

/* *
 Informs in how many milliseconds the 607766 machine is about
 to execute a rinse operation. During the rinse operation any
 attempt 60 start a product will return a SYSTEM_BUSY status. */
typedef struct _RemoteApiRs232_RinsingUpcoming {
    uint32_t start_in_ms; /* Number in milliseconds when rinse will be started */
} RemoteApiRs232_RinsingUpcoming;

/* *
 A rinse operation is imminent or was just started. In case of
 an automatically triggered rinse, the user is now presented with
 a warning dialog for 5s before the actual rinsing takes place.
 In case of a rinse triggered through the 'ForceRinse' message
 or by pushing the corresponding button on the UI, the rinsing
 is started simultaneously with this message. */
typedef struct _RemoteApiRs232_RinseStarted {
    char dummy_field;
} RemoteApiRs232_RinseStarted;

/* *
 The remote control service has received a message with
 a message id that is not currently supported. */
typedef struct _RemoteApiRs232_UnknownMessage {
    char dummy_field;
} RemoteApiRs232_UnknownMessage;

/* *
 The remote control service has received a message with
 an invalid CRC value. No operation was executed. */
typedef struct _RemoteApiRs232_WrongCrc {
    char dummy_field;
} RemoteApiRs232_WrongCrc;

/* *
 The remote control service has received a message with
 a valid CRC value but the contained message could not
 be parsed according to this protobuf description */
typedef struct _RemoteApiRs232_BrokenMessage {
    char dummy_field;
} RemoteApiRs232_BrokenMessage;

typedef struct _RemoteApiRs232_ApiMessage {
    uint32_t protocol_version; /* currently always with value 1 */
    uint32_t sequence_id; /* wrap around to 0 at 255; i.e. it is treated as uint8 */
    pb_size_t which_api_message;
    union {
        RemoteApiRs232_StartProduct start_product;
        RemoteApiRs232_GetProductList get_product_list;
        RemoteApiRs232_CancelProduct cancel_product;
        RemoteApiRs232_GetAvailableProductIds get_available_product_ids;
        RemoteApiRs232_GetActiveEvents get_active_events;
        RemoteApiRs232_ForceRinse force_rinse;
        RemoteApiRs232_PostponeRinse postpone_rinse;
        RemoteApiRs232_StartProductCategoryByName start_product_category_by_name;
        RemoteApiRs232_GetSwVersion get_sw_version;
        RemoteApiRs232_ProductStarted product_started;
        RemoteApiRs232_ProductList product_list;
        RemoteApiRs232_ProductCancelled product_cancelled;
        RemoteApiRs232_AvailableProductIds available_product_ids;
        RemoteApiRs232_ActiveEvents active_events;
        RemoteApiRs232_RinseForced rinse_forced;
        RemoteApiRs232_RinsePostponed rinse_postponed;
        RemoteApiRs232_ProductCategoryByNameStarted product_category_by_name_started;
        RemoteApiRs232_SwVersion sw_version;
        RemoteApiRs232_ErrorEvent error_event;
        RemoteApiRs232_ProductFinished product_finishied;
        RemoteApiRs232_ProductAvailabilityChanged Product_availability_changed;
        RemoteApiRs232_RinsingUpcoming rinsing_upcoming;
        RemoteApiRs232_RinseStarted rinse_started;
        RemoteApiRs232_UnknownMessage unknown_message;
        RemoteApiRs232_WrongCrc wrong_crc;
        RemoteApiRs232_BrokenMessage broken_message;
    } api_message;
} RemoteApiRs232_ApiMessage;


#ifdef __cplusplus
extern "C" {
#endif

/* Helper constants for enums */
#define _RemoteApiRs232_ResponseCode_MIN RemoteApiRs232_ResponseCode_UNKOWN_RESPONSE_CODE
#define _RemoteApiRs232_ResponseCode_MAX RemoteApiRs232_ResponseCode_NO_RINSING_UPCOMING
#define _RemoteApiRs232_ResponseCode_ARRAYSIZE ((RemoteApiRs232_ResponseCode)(RemoteApiRs232_ResponseCode_NO_RINSING_UPCOMING+1))











#define RemoteApiRs232_ProductStarted_response_code_ENUMTYPE RemoteApiRs232_ResponseCode

#define RemoteApiRs232_ProductCategoryByNameStarted_response_code_ENUMTYPE RemoteApiRs232_ResponseCode

#define RemoteApiRs232_ProductCancelled_response_code_ENUMTYPE RemoteApiRs232_ResponseCode

#define RemoteApiRs232_ProductList_response_code_ENUMTYPE RemoteApiRs232_ResponseCode


#define RemoteApiRs232_AvailableProductIds_response_code_ENUMTYPE RemoteApiRs232_ResponseCode

#define RemoteApiRs232_ActiveEvents_response_code_ENUMTYPE RemoteApiRs232_ResponseCode

#define RemoteApiRs232_RinseForced_response_code_ENUMTYPE RemoteApiRs232_ResponseCode

#define RemoteApiRs232_RinsePostponed_response_code_ENUMTYPE RemoteApiRs232_ResponseCode

#define RemoteApiRs232_SwVersion_response_code_ENUMTYPE RemoteApiRs232_ResponseCode










/* Initializer values for message structs */
#define RemoteApiRs232_ApiMessage_init_default   {0, 0, 0, {RemoteApiRs232_StartProduct_init_default}}
#define RemoteApiRs232_StartProduct_init_default {{{NULL}, NULL}, 0}
#define RemoteApiRs232_CancelProduct_init_default {{{NULL}, NULL}, 0}
#define RemoteApiRs232_StartProductCategoryByName_init_default {{{NULL}, NULL}, 0}
#define RemoteApiRs232_GetProductList_init_default {0}
#define RemoteApiRs232_GetAvailableProductIds_init_default {0}
#define RemoteApiRs232_GetActiveEvents_init_default {0}
#define RemoteApiRs232_ForceRinse_init_default   {0}
#define RemoteApiRs232_PostponeRinse_init_default {0}
#define RemoteApiRs232_GetSwVersion_init_default {0}
#define RemoteApiRs232_ProductStarted_init_default {_RemoteApiRs232_ResponseCode_MIN}
#define RemoteApiRs232_ProductCategoryByNameStarted_init_default {_RemoteApiRs232_ResponseCode_MIN}
#define RemoteApiRs232_ProductCancelled_init_default {_RemoteApiRs232_ResponseCode_MIN}
#define RemoteApiRs232_ProductList_init_default  {_RemoteApiRs232_ResponseCode_MIN, {{NULL}, NULL}}
#define RemoteApiRs232_ProductList_ProductListEntry_init_default {{{NULL}, NULL}, {{NULL}, NULL}}
#define RemoteApiRs232_AvailableProductIds_init_default {_RemoteApiRs232_ResponseCode_MIN, {{NULL}, NULL}}
#define RemoteApiRs232_ActiveEvents_init_default {_RemoteApiRs232_ResponseCode_MIN, {{NULL}, NULL}}
#define RemoteApiRs232_RinseForced_init_default  {_RemoteApiRs232_ResponseCode_MIN}
#define RemoteApiRs232_RinsePostponed_init_default {_RemoteApiRs232_ResponseCode_MIN}
#define RemoteApiRs232_SwVersion_init_default    {_RemoteApiRs232_ResponseCode_MIN, {{NULL}, NULL}}
#define RemoteApiRs232_ErrorEvent_init_default   {0, {{NULL}, NULL}, 0}
#define RemoteApiRs232_ProductFinished_init_default {{{NULL}, NULL}, 0}
#define RemoteApiRs232_ProductAvailabilityChanged_init_default {{{NULL}, NULL}}
#define RemoteApiRs232_RinsingUpcoming_init_default {0}
#define RemoteApiRs232_RinseStarted_init_default {0}
#define RemoteApiRs232_UnknownMessage_init_default {0}
#define RemoteApiRs232_WrongCrc_init_default     {0}
#define RemoteApiRs232_BrokenMessage_init_default {0}
#define RemoteApiRs232_ApiMessage_init_zero      {0, 0, 0, {RemoteApiRs232_StartProduct_init_zero}}
#define RemoteApiRs232_StartProduct_init_zero    {{{NULL}, NULL}, 0}
#define RemoteApiRs232_CancelProduct_init_zero   {{{NULL}, NULL}, 0}
#define RemoteApiRs232_StartProductCategoryByName_init_zero {{{NULL}, NULL}, 0}
#define RemoteApiRs232_GetProductList_init_zero  {0}
#define RemoteApiRs232_GetAvailableProductIds_init_zero {0}
#define RemoteApiRs232_GetActiveEvents_init_zero {0}
#define RemoteApiRs232_ForceRinse_init_zero      {0}
#define RemoteApiRs232_PostponeRinse_init_zero   {0}
#define RemoteApiRs232_GetSwVersion_init_zero    {0}
#define RemoteApiRs232_ProductStarted_init_zero  {_RemoteApiRs232_ResponseCode_MIN}
#define RemoteApiRs232_ProductCategoryByNameStarted_init_zero {_RemoteApiRs232_ResponseCode_MIN}
#define RemoteApiRs232_ProductCancelled_init_zero {_RemoteApiRs232_ResponseCode_MIN}
#define RemoteApiRs232_ProductList_init_zero     {_RemoteApiRs232_ResponseCode_MIN, {{NULL}, NULL}}
#define RemoteApiRs232_ProductList_ProductListEntry_init_zero {{{NULL}, NULL}, {{NULL}, NULL}}
#define RemoteApiRs232_AvailableProductIds_init_zero {_RemoteApiRs232_ResponseCode_MIN, {{NULL}, NULL}}
#define RemoteApiRs232_ActiveEvents_init_zero    {_RemoteApiRs232_ResponseCode_MIN, {{NULL}, NULL}}
#define RemoteApiRs232_RinseForced_init_zero     {_RemoteApiRs232_ResponseCode_MIN}
#define RemoteApiRs232_RinsePostponed_init_zero  {_RemoteApiRs232_ResponseCode_MIN}
#define RemoteApiRs232_SwVersion_init_zero       {_RemoteApiRs232_ResponseCode_MIN, {{NULL}, NULL}}
#define RemoteApiRs232_ErrorEvent_init_zero      {0, {{NULL}, NULL}, 0}
#define RemoteApiRs232_ProductFinished_init_zero {{{NULL}, NULL}, 0}
#define RemoteApiRs232_ProductAvailabilityChanged_init_zero {{{NULL}, NULL}}
#define RemoteApiRs232_RinsingUpcoming_init_zero {0}
#define RemoteApiRs232_RinseStarted_init_zero    {0}
#define RemoteApiRs232_UnknownMessage_init_zero  {0}
#define RemoteApiRs232_WrongCrc_init_zero        {0}
#define RemoteApiRs232_BrokenMessage_init_zero   {0}

/* Field tags (for use in manual encoding/decoding) */
#define RemoteApiRs232_StartProduct_prudct_id_tag 1
#define RemoteApiRs232_StartProduct_start_delay_s_tag 2
#define RemoteApiRs232_CancelProduct_product_id_tag 1
#define RemoteApiRs232_CancelProduct_cancel_delay_s_tag 2
#define RemoteApiRs232_StartProductCategoryByName_product_name_tag 1
#define RemoteApiRs232_StartProductCategoryByName_start_delay_s_tag 2
#define RemoteApiRs232_PostponeRinse_milliseconds_tag 1
#define RemoteApiRs232_ProductStarted_response_code_tag 1
#define RemoteApiRs232_ProductCategoryByNameStarted_response_code_tag 1
#define RemoteApiRs232_ProductCancelled_response_code_tag 1
#define RemoteApiRs232_ProductList_response_code_tag 1
#define RemoteApiRs232_ProductList_product_list_tag 2
#define RemoteApiRs232_ProductList_ProductListEntry_key_tag 1
#define RemoteApiRs232_ProductList_ProductListEntry_value_tag 2
#define RemoteApiRs232_AvailableProductIds_response_code_tag 1
#define RemoteApiRs232_AvailableProductIds_available_product_ids_tag 2
#define RemoteApiRs232_ActiveEvents_response_code_tag 1
#define RemoteApiRs232_ActiveEvents_active_events_tag 2
#define RemoteApiRs232_RinseForced_response_code_tag 1
#define RemoteApiRs232_RinsePostponed_response_code_tag 1
#define RemoteApiRs232_SwVersion_response_code_tag 1
#define RemoteApiRs232_SwVersion_sw_version_tag  2
#define RemoteApiRs232_ErrorEvent_error_number_tag 1
#define RemoteApiRs232_ErrorEvent_title_tag      2
#define RemoteApiRs232_ErrorEvent_source_index_tag 3
#define RemoteApiRs232_ProductFinished_product_id_tag 1
#define RemoteApiRs232_ProductFinished_success_tag 2
#define RemoteApiRs232_ProductAvailabilityChanged_product_ids_tag 1
#define RemoteApiRs232_RinsingUpcoming_start_in_ms_tag 1
#define RemoteApiRs232_ApiMessage_protocol_version_tag 1
#define RemoteApiRs232_ApiMessage_sequence_id_tag 2
#define RemoteApiRs232_ApiMessage_start_product_tag 4097
#define RemoteApiRs232_ApiMessage_get_product_list_tag 4098
#define RemoteApiRs232_ApiMessage_cancel_product_tag 4099
#define RemoteApiRs232_ApiMessage_get_available_product_ids_tag 4100
#define RemoteApiRs232_ApiMessage_get_active_events_tag 4101
#define RemoteApiRs232_ApiMessage_force_rinse_tag 4102
#define RemoteApiRs232_ApiMessage_postpone_rinse_tag 4103
#define RemoteApiRs232_ApiMessage_start_product_category_by_name_tag 4104
#define RemoteApiRs232_ApiMessage_get_sw_version_tag 4105
#define RemoteApiRs232_ApiMessage_product_started_tag 16385
#define RemoteApiRs232_ApiMessage_product_list_tag 16386
#define RemoteApiRs232_ApiMessage_product_cancelled_tag 16387
#define RemoteApiRs232_ApiMessage_available_product_ids_tag 16388
#define RemoteApiRs232_ApiMessage_active_events_tag 16389
#define RemoteApiRs232_ApiMessage_rinse_forced_tag 16390
#define RemoteApiRs232_ApiMessage_rinse_postponed_tag 16391
#define RemoteApiRs232_ApiMessage_product_category_by_name_started_tag 16392
#define RemoteApiRs232_ApiMessage_sw_version_tag 16393
#define RemoteApiRs232_ApiMessage_error_event_tag 32768
#define RemoteApiRs232_ApiMessage_product_finishied_tag 32769
#define RemoteApiRs232_ApiMessage_Product_availability_changed_tag 32770
#define RemoteApiRs232_ApiMessage_rinsing_upcoming_tag 32771
#define RemoteApiRs232_ApiMessage_rinse_started_tag 32772
#define RemoteApiRs232_ApiMessage_unknown_message_tag 49152
#define RemoteApiRs232_ApiMessage_wrong_crc_tag  49153
#define RemoteApiRs232_ApiMessage_broken_message_tag 49154

/* Struct field encoding specification for nanopb */
#define RemoteApiRs232_ApiMessage_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   protocol_version,   1) \
X(a, STATIC,   SINGULAR, UINT32,   sequence_id,       2) \
X(a, STATIC,   ONEOF,    MESSAGE,  (api_message,start_product,api_message.start_product), 4097) \
X(a, STATIC,   ONEOF,    MESSAGE,  (api_message,get_product_list,api_message.get_product_list), 4098) \
X(a, STATIC,   ONEOF,    MESSAGE,  (api_message,cancel_product,api_message.cancel_product), 4099) \
X(a, STATIC,   ONEOF,    MESSAGE,  (api_message,get_available_product_ids,api_message.get_available_product_ids), 4100) \
X(a, STATIC,   ONEOF,    MESSAGE,  (api_message,get_active_events,api_message.get_active_events), 4101) \
X(a, STATIC,   ONEOF,    MESSAGE,  (api_message,force_rinse,api_message.force_rinse), 4102) \
X(a, STATIC,   ONEOF,    MESSAGE,  (api_message,postpone_rinse,api_message.postpone_rinse), 4103) \
X(a, STATIC,   ONEOF,    MESSAGE,  (api_message,start_product_category_by_name,api_message.start_product_category_by_name), 4104) \
X(a, STATIC,   ONEOF,    MESSAGE,  (api_message,get_sw_version,api_message.get_sw_version), 4105) \
X(a, STATIC,   ONEOF,    MESSAGE,  (api_message,product_started,api_message.product_started), 16385) \
X(a, STATIC,   ONEOF,    MESSAGE,  (api_message,product_list,api_message.product_list), 16386) \
X(a, STATIC,   ONEOF,    MESSAGE,  (api_message,product_cancelled,api_message.product_cancelled), 16387) \
X(a, STATIC,   ONEOF,    MESSAGE,  (api_message,available_product_ids,api_message.available_product_ids), 16388) \
X(a, STATIC,   ONEOF,    MESSAGE,  (api_message,active_events,api_message.active_events), 16389) \
X(a, STATIC,   ONEOF,    MESSAGE,  (api_message,rinse_forced,api_message.rinse_forced), 16390) \
X(a, STATIC,   ONEOF,    MESSAGE,  (api_message,rinse_postponed,api_message.rinse_postponed), 16391) \
X(a, STATIC,   ONEOF,    MESSAGE,  (api_message,product_category_by_name_started,api_message.product_category_by_name_started), 16392) \
X(a, STATIC,   ONEOF,    MESSAGE,  (api_message,sw_version,api_message.sw_version), 16393) \
X(a, STATIC,   ONEOF,    MESSAGE,  (api_message,error_event,api_message.error_event), 32768) \
X(a, STATIC,   ONEOF,    MESSAGE,  (api_message,product_finishied,api_message.product_finishied), 32769) \
X(a, STATIC,   ONEOF,    MESSAGE,  (api_message,Product_availability_changed,api_message.Product_availability_changed), 32770) \
X(a, STATIC,   ONEOF,    MESSAGE,  (api_message,rinsing_upcoming,api_message.rinsing_upcoming), 32771) \
X(a, STATIC,   ONEOF,    MESSAGE,  (api_message,rinse_started,api_message.rinse_started), 32772) \
X(a, STATIC,   ONEOF,    MESSAGE,  (api_message,unknown_message,api_message.unknown_message), 49152) \
X(a, STATIC,   ONEOF,    MESSAGE,  (api_message,wrong_crc,api_message.wrong_crc), 49153) \
X(a, STATIC,   ONEOF,    MESSAGE,  (api_message,broken_message,api_message.broken_message), 49154)
#define RemoteApiRs232_ApiMessage_CALLBACK NULL
#define RemoteApiRs232_ApiMessage_DEFAULT NULL
#define RemoteApiRs232_ApiMessage_api_message_start_product_MSGTYPE RemoteApiRs232_StartProduct
#define RemoteApiRs232_ApiMessage_api_message_get_product_list_MSGTYPE RemoteApiRs232_GetProductList
#define RemoteApiRs232_ApiMessage_api_message_cancel_product_MSGTYPE RemoteApiRs232_CancelProduct
#define RemoteApiRs232_ApiMessage_api_message_get_available_product_ids_MSGTYPE RemoteApiRs232_GetAvailableProductIds
#define RemoteApiRs232_ApiMessage_api_message_get_active_events_MSGTYPE RemoteApiRs232_GetActiveEvents
#define RemoteApiRs232_ApiMessage_api_message_force_rinse_MSGTYPE RemoteApiRs232_ForceRinse
#define RemoteApiRs232_ApiMessage_api_message_postpone_rinse_MSGTYPE RemoteApiRs232_PostponeRinse
#define RemoteApiRs232_ApiMessage_api_message_start_product_category_by_name_MSGTYPE RemoteApiRs232_StartProductCategoryByName
#define RemoteApiRs232_ApiMessage_api_message_get_sw_version_MSGTYPE RemoteApiRs232_GetSwVersion
#define RemoteApiRs232_ApiMessage_api_message_product_started_MSGTYPE RemoteApiRs232_ProductStarted
#define RemoteApiRs232_ApiMessage_api_message_product_list_MSGTYPE RemoteApiRs232_ProductList
#define RemoteApiRs232_ApiMessage_api_message_product_cancelled_MSGTYPE RemoteApiRs232_ProductCancelled
#define RemoteApiRs232_ApiMessage_api_message_available_product_ids_MSGTYPE RemoteApiRs232_AvailableProductIds
#define RemoteApiRs232_ApiMessage_api_message_active_events_MSGTYPE RemoteApiRs232_ActiveEvents
#define RemoteApiRs232_ApiMessage_api_message_rinse_forced_MSGTYPE RemoteApiRs232_RinseForced
#define RemoteApiRs232_ApiMessage_api_message_rinse_postponed_MSGTYPE RemoteApiRs232_RinsePostponed
#define RemoteApiRs232_ApiMessage_api_message_product_category_by_name_started_MSGTYPE RemoteApiRs232_ProductCategoryByNameStarted
#define RemoteApiRs232_ApiMessage_api_message_sw_version_MSGTYPE RemoteApiRs232_SwVersion
#define RemoteApiRs232_ApiMessage_api_message_error_event_MSGTYPE RemoteApiRs232_ErrorEvent
#define RemoteApiRs232_ApiMessage_api_message_product_finishied_MSGTYPE RemoteApiRs232_ProductFinished
#define RemoteApiRs232_ApiMessage_api_message_Product_availability_changed_MSGTYPE RemoteApiRs232_ProductAvailabilityChanged
#define RemoteApiRs232_ApiMessage_api_message_rinsing_upcoming_MSGTYPE RemoteApiRs232_RinsingUpcoming
#define RemoteApiRs232_ApiMessage_api_message_rinse_started_MSGTYPE RemoteApiRs232_RinseStarted
#define RemoteApiRs232_ApiMessage_api_message_unknown_message_MSGTYPE RemoteApiRs232_UnknownMessage
#define RemoteApiRs232_ApiMessage_api_message_wrong_crc_MSGTYPE RemoteApiRs232_WrongCrc
#define RemoteApiRs232_ApiMessage_api_message_broken_message_MSGTYPE RemoteApiRs232_BrokenMessage

#define RemoteApiRs232_StartProduct_FIELDLIST(X, a) \
X(a, CALLBACK, SINGULAR, STRING,   prudct_id,         1) \
X(a, STATIC,   SINGULAR, DOUBLE,   start_delay_s,     2)
#define RemoteApiRs232_StartProduct_CALLBACK pb_default_field_callback
#define RemoteApiRs232_StartProduct_DEFAULT NULL

#define RemoteApiRs232_CancelProduct_FIELDLIST(X, a) \
X(a, CALLBACK, SINGULAR, STRING,   product_id,        1) \
X(a, STATIC,   SINGULAR, DOUBLE,   cancel_delay_s,    2)
#define RemoteApiRs232_CancelProduct_CALLBACK pb_default_field_callback
#define RemoteApiRs232_CancelProduct_DEFAULT NULL

#define RemoteApiRs232_StartProductCategoryByName_FIELDLIST(X, a) \
X(a, CALLBACK, SINGULAR, STRING,   product_name,      1) \
X(a, STATIC,   SINGULAR, DOUBLE,   start_delay_s,     2)
#define RemoteApiRs232_StartProductCategoryByName_CALLBACK pb_default_field_callback
#define RemoteApiRs232_StartProductCategoryByName_DEFAULT NULL

#define RemoteApiRs232_GetProductList_FIELDLIST(X, a) \

#define RemoteApiRs232_GetProductList_CALLBACK NULL
#define RemoteApiRs232_GetProductList_DEFAULT NULL

#define RemoteApiRs232_GetAvailableProductIds_FIELDLIST(X, a) \

#define RemoteApiRs232_GetAvailableProductIds_CALLBACK NULL
#define RemoteApiRs232_GetAvailableProductIds_DEFAULT NULL

#define RemoteApiRs232_GetActiveEvents_FIELDLIST(X, a) \

#define RemoteApiRs232_GetActiveEvents_CALLBACK NULL
#define RemoteApiRs232_GetActiveEvents_DEFAULT NULL

#define RemoteApiRs232_ForceRinse_FIELDLIST(X, a) \

#define RemoteApiRs232_ForceRinse_CALLBACK NULL
#define RemoteApiRs232_ForceRinse_DEFAULT NULL

#define RemoteApiRs232_PostponeRinse_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   milliseconds,      1)
#define RemoteApiRs232_PostponeRinse_CALLBACK NULL
#define RemoteApiRs232_PostponeRinse_DEFAULT NULL

#define RemoteApiRs232_GetSwVersion_FIELDLIST(X, a) \

#define RemoteApiRs232_GetSwVersion_CALLBACK NULL
#define RemoteApiRs232_GetSwVersion_DEFAULT NULL

#define RemoteApiRs232_ProductStarted_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UENUM,    response_code,     1)
#define RemoteApiRs232_ProductStarted_CALLBACK NULL
#define RemoteApiRs232_ProductStarted_DEFAULT NULL

#define RemoteApiRs232_ProductCategoryByNameStarted_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UENUM,    response_code,     1)
#define RemoteApiRs232_ProductCategoryByNameStarted_CALLBACK NULL
#define RemoteApiRs232_ProductCategoryByNameStarted_DEFAULT NULL

#define RemoteApiRs232_ProductCancelled_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UENUM,    response_code,     1)
#define RemoteApiRs232_ProductCancelled_CALLBACK NULL
#define RemoteApiRs232_ProductCancelled_DEFAULT NULL

#define RemoteApiRs232_ProductList_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UENUM,    response_code,     1) \
X(a, CALLBACK, REPEATED, MESSAGE,  product_list,      2)
#define RemoteApiRs232_ProductList_CALLBACK pb_default_field_callback
#define RemoteApiRs232_ProductList_DEFAULT NULL
#define RemoteApiRs232_ProductList_product_list_MSGTYPE RemoteApiRs232_ProductList_ProductListEntry

#define RemoteApiRs232_ProductList_ProductListEntry_FIELDLIST(X, a) \
X(a, CALLBACK, SINGULAR, STRING,   key,               1) \
X(a, CALLBACK, SINGULAR, STRING,   value,             2)
#define RemoteApiRs232_ProductList_ProductListEntry_CALLBACK pb_default_field_callback
#define RemoteApiRs232_ProductList_ProductListEntry_DEFAULT NULL

#define RemoteApiRs232_AvailableProductIds_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UENUM,    response_code,     1) \
X(a, CALLBACK, REPEATED, STRING,   available_product_ids,   2)
#define RemoteApiRs232_AvailableProductIds_CALLBACK pb_default_field_callback
#define RemoteApiRs232_AvailableProductIds_DEFAULT NULL

#define RemoteApiRs232_ActiveEvents_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UENUM,    response_code,     1) \
X(a, CALLBACK, REPEATED, MESSAGE,  active_events,     2)
#define RemoteApiRs232_ActiveEvents_CALLBACK pb_default_field_callback
#define RemoteApiRs232_ActiveEvents_DEFAULT NULL
#define RemoteApiRs232_ActiveEvents_active_events_MSGTYPE RemoteApiRs232_ErrorEvent

#define RemoteApiRs232_RinseForced_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UENUM,    response_code,     1)
#define RemoteApiRs232_RinseForced_CALLBACK NULL
#define RemoteApiRs232_RinseForced_DEFAULT NULL

#define RemoteApiRs232_RinsePostponed_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UENUM,    response_code,     1)
#define RemoteApiRs232_RinsePostponed_CALLBACK NULL
#define RemoteApiRs232_RinsePostponed_DEFAULT NULL

#define RemoteApiRs232_SwVersion_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UENUM,    response_code,     1) \
X(a, CALLBACK, SINGULAR, STRING,   sw_version,        2)
#define RemoteApiRs232_SwVersion_CALLBACK pb_default_field_callback
#define RemoteApiRs232_SwVersion_DEFAULT NULL

#define RemoteApiRs232_ErrorEvent_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   error_number,      1) \
X(a, CALLBACK, SINGULAR, STRING,   title,             2) \
X(a, STATIC,   SINGULAR, UINT32,   source_index,      3)
#define RemoteApiRs232_ErrorEvent_CALLBACK pb_default_field_callback
#define RemoteApiRs232_ErrorEvent_DEFAULT NULL

#define RemoteApiRs232_ProductFinished_FIELDLIST(X, a) \
X(a, CALLBACK, SINGULAR, STRING,   product_id,        1) \
X(a, STATIC,   SINGULAR, BOOL,     success,           2)
#define RemoteApiRs232_ProductFinished_CALLBACK pb_default_field_callback
#define RemoteApiRs232_ProductFinished_DEFAULT NULL

#define RemoteApiRs232_ProductAvailabilityChanged_FIELDLIST(X, a) \
X(a, CALLBACK, REPEATED, STRING,   product_ids,       1)
#define RemoteApiRs232_ProductAvailabilityChanged_CALLBACK pb_default_field_callback
#define RemoteApiRs232_ProductAvailabilityChanged_DEFAULT NULL

#define RemoteApiRs232_RinsingUpcoming_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   start_in_ms,       1)
#define RemoteApiRs232_RinsingUpcoming_CALLBACK NULL
#define RemoteApiRs232_RinsingUpcoming_DEFAULT NULL

#define RemoteApiRs232_RinseStarted_FIELDLIST(X, a) \

#define RemoteApiRs232_RinseStarted_CALLBACK NULL
#define RemoteApiRs232_RinseStarted_DEFAULT NULL

#define RemoteApiRs232_UnknownMessage_FIELDLIST(X, a) \

#define RemoteApiRs232_UnknownMessage_CALLBACK NULL
#define RemoteApiRs232_UnknownMessage_DEFAULT NULL

#define RemoteApiRs232_WrongCrc_FIELDLIST(X, a) \

#define RemoteApiRs232_WrongCrc_CALLBACK NULL
#define RemoteApiRs232_WrongCrc_DEFAULT NULL

#define RemoteApiRs232_BrokenMessage_FIELDLIST(X, a) \

#define RemoteApiRs232_BrokenMessage_CALLBACK NULL
#define RemoteApiRs232_BrokenMessage_DEFAULT NULL

extern const pb_msgdesc_t RemoteApiRs232_ApiMessage_msg;
extern const pb_msgdesc_t RemoteApiRs232_StartProduct_msg;
extern const pb_msgdesc_t RemoteApiRs232_CancelProduct_msg;
extern const pb_msgdesc_t RemoteApiRs232_StartProductCategoryByName_msg;
extern const pb_msgdesc_t RemoteApiRs232_GetProductList_msg;
extern const pb_msgdesc_t RemoteApiRs232_GetAvailableProductIds_msg;
extern const pb_msgdesc_t RemoteApiRs232_GetActiveEvents_msg;
extern const pb_msgdesc_t RemoteApiRs232_ForceRinse_msg;
extern const pb_msgdesc_t RemoteApiRs232_PostponeRinse_msg;
extern const pb_msgdesc_t RemoteApiRs232_GetSwVersion_msg;
extern const pb_msgdesc_t RemoteApiRs232_ProductStarted_msg;
extern const pb_msgdesc_t RemoteApiRs232_ProductCategoryByNameStarted_msg;
extern const pb_msgdesc_t RemoteApiRs232_ProductCancelled_msg;
extern const pb_msgdesc_t RemoteApiRs232_ProductList_msg;
extern const pb_msgdesc_t RemoteApiRs232_ProductList_ProductListEntry_msg;
extern const pb_msgdesc_t RemoteApiRs232_AvailableProductIds_msg;
extern const pb_msgdesc_t RemoteApiRs232_ActiveEvents_msg;
extern const pb_msgdesc_t RemoteApiRs232_RinseForced_msg;
extern const pb_msgdesc_t RemoteApiRs232_RinsePostponed_msg;
extern const pb_msgdesc_t RemoteApiRs232_SwVersion_msg;
extern const pb_msgdesc_t RemoteApiRs232_ErrorEvent_msg;
extern const pb_msgdesc_t RemoteApiRs232_ProductFinished_msg;
extern const pb_msgdesc_t RemoteApiRs232_ProductAvailabilityChanged_msg;
extern const pb_msgdesc_t RemoteApiRs232_RinsingUpcoming_msg;
extern const pb_msgdesc_t RemoteApiRs232_RinseStarted_msg;
extern const pb_msgdesc_t RemoteApiRs232_UnknownMessage_msg;
extern const pb_msgdesc_t RemoteApiRs232_WrongCrc_msg;
extern const pb_msgdesc_t RemoteApiRs232_BrokenMessage_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define RemoteApiRs232_ApiMessage_fields &RemoteApiRs232_ApiMessage_msg
#define RemoteApiRs232_StartProduct_fields &RemoteApiRs232_StartProduct_msg
#define RemoteApiRs232_CancelProduct_fields &RemoteApiRs232_CancelProduct_msg
#define RemoteApiRs232_StartProductCategoryByName_fields &RemoteApiRs232_StartProductCategoryByName_msg
#define RemoteApiRs232_GetProductList_fields &RemoteApiRs232_GetProductList_msg
#define RemoteApiRs232_GetAvailableProductIds_fields &RemoteApiRs232_GetAvailableProductIds_msg
#define RemoteApiRs232_GetActiveEvents_fields &RemoteApiRs232_GetActiveEvents_msg
#define RemoteApiRs232_ForceRinse_fields &RemoteApiRs232_ForceRinse_msg
#define RemoteApiRs232_PostponeRinse_fields &RemoteApiRs232_PostponeRinse_msg
#define RemoteApiRs232_GetSwVersion_fields &RemoteApiRs232_GetSwVersion_msg
#define RemoteApiRs232_ProductStarted_fields &RemoteApiRs232_ProductStarted_msg
#define RemoteApiRs232_ProductCategoryByNameStarted_fields &RemoteApiRs232_ProductCategoryByNameStarted_msg
#define RemoteApiRs232_ProductCancelled_fields &RemoteApiRs232_ProductCancelled_msg
#define RemoteApiRs232_ProductList_fields &RemoteApiRs232_ProductList_msg
#define RemoteApiRs232_ProductList_ProductListEntry_fields &RemoteApiRs232_ProductList_ProductListEntry_msg
#define RemoteApiRs232_AvailableProductIds_fields &RemoteApiRs232_AvailableProductIds_msg
#define RemoteApiRs232_ActiveEvents_fields &RemoteApiRs232_ActiveEvents_msg
#define RemoteApiRs232_RinseForced_fields &RemoteApiRs232_RinseForced_msg
#define RemoteApiRs232_RinsePostponed_fields &RemoteApiRs232_RinsePostponed_msg
#define RemoteApiRs232_SwVersion_fields &RemoteApiRs232_SwVersion_msg
#define RemoteApiRs232_ErrorEvent_fields &RemoteApiRs232_ErrorEvent_msg
#define RemoteApiRs232_ProductFinished_fields &RemoteApiRs232_ProductFinished_msg
#define RemoteApiRs232_ProductAvailabilityChanged_fields &RemoteApiRs232_ProductAvailabilityChanged_msg
#define RemoteApiRs232_RinsingUpcoming_fields &RemoteApiRs232_RinsingUpcoming_msg
#define RemoteApiRs232_RinseStarted_fields &RemoteApiRs232_RinseStarted_msg
#define RemoteApiRs232_UnknownMessage_fields &RemoteApiRs232_UnknownMessage_msg
#define RemoteApiRs232_WrongCrc_fields &RemoteApiRs232_WrongCrc_msg
#define RemoteApiRs232_BrokenMessage_fields &RemoteApiRs232_BrokenMessage_msg

/* Maximum encoded size of messages (where known) */
/* RemoteApiRs232_ApiMessage_size depends on runtime parameters */
/* RemoteApiRs232_StartProduct_size depends on runtime parameters */
/* RemoteApiRs232_CancelProduct_size depends on runtime parameters */
/* RemoteApiRs232_StartProductCategoryByName_size depends on runtime parameters */
/* RemoteApiRs232_ProductList_size depends on runtime parameters */
/* RemoteApiRs232_ProductList_ProductListEntry_size depends on runtime parameters */
/* RemoteApiRs232_AvailableProductIds_size depends on runtime parameters */
/* RemoteApiRs232_ActiveEvents_size depends on runtime parameters */
/* RemoteApiRs232_SwVersion_size depends on runtime parameters */
/* RemoteApiRs232_ErrorEvent_size depends on runtime parameters */
/* RemoteApiRs232_ProductFinished_size depends on runtime parameters */
/* RemoteApiRs232_ProductAvailabilityChanged_size depends on runtime parameters */
#define REMOTEAPIRS232_COFFEE_MACHINE_PB_H_MAX_SIZE RemoteApiRs232_PostponeRinse_size
#define RemoteApiRs232_BrokenMessage_size        0
#define RemoteApiRs232_ForceRinse_size           0
#define RemoteApiRs232_GetActiveEvents_size      0
#define RemoteApiRs232_GetAvailableProductIds_size 0
#define RemoteApiRs232_GetProductList_size       0
#define RemoteApiRs232_GetSwVersion_size         0
#define RemoteApiRs232_PostponeRinse_size        6
#define RemoteApiRs232_ProductCancelled_size     2
#define RemoteApiRs232_ProductCategoryByNameStarted_size 2
#define RemoteApiRs232_ProductStarted_size       2
#define RemoteApiRs232_RinseForced_size          2
#define RemoteApiRs232_RinsePostponed_size       2
#define RemoteApiRs232_RinseStarted_size         0
#define RemoteApiRs232_RinsingUpcoming_size      6
#define RemoteApiRs232_UnknownMessage_size       0
#define RemoteApiRs232_WrongCrc_size             0

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif