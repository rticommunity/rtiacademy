

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from chat.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef chatPlugin_1436264776_h
#define chatPlugin_1436264776_h

#include "chat.hpp"

struct RTICdrStream;

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

/* The type used to store keys for instances of type struct
* AnotherSimple.
*
* By default, this type is struct ChatUser
* itself. However, if for some reason this choice is not practical for your
* system (e.g. if sizeof(struct ChatUser)
* is very large), you may redefine this typedef in terms of another type of
* your choosing. HOWEVER, if you define the KeyHolder type to be something
* other than struct AnotherSimple, the
* following restriction applies: the key of struct
* ChatUser must consist of a
* single field of your redefined KeyHolder type and that field must be the
* first field in struct ChatUser.
*/
typedef  class ChatUser ChatUserKeyHolder;

#define ChatUserPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define ChatUserPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define ChatUserPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define ChatUserPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
#define ChatUserPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

#define ChatUserPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define ChatUserPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern ChatUser*
ChatUserPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern ChatUser*
ChatUserPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern ChatUser*
ChatUserPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
ChatUserPluginSupport_copy_data(
    ChatUser *out,
    const ChatUser *in);

NDDSUSERDllExport extern void 
ChatUserPluginSupport_destroy_data_w_params(
    ChatUser *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
ChatUserPluginSupport_destroy_data_ex(
    ChatUser *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
ChatUserPluginSupport_destroy_data(
    ChatUser *sample);

NDDSUSERDllExport extern void 
ChatUserPluginSupport_print_data(
    const ChatUser *sample,
    const char *desc,
    unsigned int indent);

NDDSUSERDllExport extern ChatUser*
ChatUserPluginSupport_create_key_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern ChatUser*
ChatUserPluginSupport_create_key(void);

NDDSUSERDllExport extern void 
ChatUserPluginSupport_destroy_key_ex(
    ChatUserKeyHolder *key,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
ChatUserPluginSupport_destroy_key(
    ChatUserKeyHolder *key);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
ChatUserPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
ChatUserPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
ChatUserPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
ChatUserPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
ChatUserPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    ChatUser *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
ChatUserPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    ChatUser *out,
    const ChatUser *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool
ChatUserPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const ChatUser *sample,
    dds::core::policy::DataRepresentationId representation
    = dds::core::policy::DataRepresentation::xcdr()); 

NDDSUSERDllExport extern RTIBool 
ChatUserPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    ChatUser **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
ChatUserPlugin_deserialize_from_cdr_buffer(
    ChatUser *sample,
    const char * buffer,
    unsigned int length);    

NDDSUSERDllExport extern unsigned int 
ChatUserPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
ChatUserPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
ChatUserPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
ChatUserPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
ChatUserPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    ChatUser ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
ChatUserPlugin_instance_to_key(
    PRESTypePluginEndpointData endpoint_data,
    ChatUserKeyHolder *key, 
    const ChatUser *instance);

NDDSUSERDllExport extern RTIBool 
ChatUserPlugin_key_to_instance(
    PRESTypePluginEndpointData endpoint_data,
    ChatUser *instance, 
    const ChatUserKeyHolder *key);

NDDSUSERDllExport extern RTIBool 
ChatUserPlugin_instance_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    DDS_KeyHash_t *keyhash,
    const ChatUser *instance,
    RTIEncapsulationId encapsulationId);

NDDSUSERDllExport extern RTIBool 
ChatUserPlugin_serialized_sample_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    DDS_KeyHash_t *keyhash,
    RTIBool deserialize_encapsulation,
    void *endpoint_plugin_qos); 

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
ChatUserPlugin_new(void);

NDDSUSERDllExport extern void
ChatUserPlugin_delete(struct PRESTypePlugin *);

/* The type used to store keys for instances of type struct
* AnotherSimple.
*
* By default, this type is struct ChatMessage
* itself. However, if for some reason this choice is not practical for your
* system (e.g. if sizeof(struct ChatMessage)
* is very large), you may redefine this typedef in terms of another type of
* your choosing. HOWEVER, if you define the KeyHolder type to be something
* other than struct AnotherSimple, the
* following restriction applies: the key of struct
* ChatMessage must consist of a
* single field of your redefined KeyHolder type and that field must be the
* first field in struct ChatMessage.
*/
typedef  class ChatMessage ChatMessageKeyHolder;

#define ChatMessagePlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define ChatMessagePlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define ChatMessagePlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define ChatMessagePlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
#define ChatMessagePlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

#define ChatMessagePlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define ChatMessagePlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern ChatMessage*
ChatMessagePluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern ChatMessage*
ChatMessagePluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern ChatMessage*
ChatMessagePluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
ChatMessagePluginSupport_copy_data(
    ChatMessage *out,
    const ChatMessage *in);

NDDSUSERDllExport extern void 
ChatMessagePluginSupport_destroy_data_w_params(
    ChatMessage *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
ChatMessagePluginSupport_destroy_data_ex(
    ChatMessage *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
ChatMessagePluginSupport_destroy_data(
    ChatMessage *sample);

NDDSUSERDllExport extern void 
ChatMessagePluginSupport_print_data(
    const ChatMessage *sample,
    const char *desc,
    unsigned int indent);

NDDSUSERDllExport extern ChatMessage*
ChatMessagePluginSupport_create_key_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern ChatMessage*
ChatMessagePluginSupport_create_key(void);

NDDSUSERDllExport extern void 
ChatMessagePluginSupport_destroy_key_ex(
    ChatMessageKeyHolder *key,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
ChatMessagePluginSupport_destroy_key(
    ChatMessageKeyHolder *key);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
ChatMessagePlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
ChatMessagePlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
ChatMessagePlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
ChatMessagePlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
ChatMessagePlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    ChatMessage *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
ChatMessagePlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    ChatMessage *out,
    const ChatMessage *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool
ChatMessagePlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const ChatMessage *sample,
    dds::core::policy::DataRepresentationId representation
    = dds::core::policy::DataRepresentation::xcdr()); 

NDDSUSERDllExport extern RTIBool 
ChatMessagePlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    ChatMessage **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
ChatMessagePlugin_deserialize_from_cdr_buffer(
    ChatMessage *sample,
    const char * buffer,
    unsigned int length);    

NDDSUSERDllExport extern unsigned int 
ChatMessagePlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
ChatMessagePlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
ChatMessagePlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
ChatMessagePlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
ChatMessagePlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    ChatMessage ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
ChatMessagePlugin_instance_to_key(
    PRESTypePluginEndpointData endpoint_data,
    ChatMessageKeyHolder *key, 
    const ChatMessage *instance);

NDDSUSERDllExport extern RTIBool 
ChatMessagePlugin_key_to_instance(
    PRESTypePluginEndpointData endpoint_data,
    ChatMessage *instance, 
    const ChatMessageKeyHolder *key);

NDDSUSERDllExport extern RTIBool 
ChatMessagePlugin_instance_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    DDS_KeyHash_t *keyhash,
    const ChatMessage *instance,
    RTIEncapsulationId encapsulationId);

NDDSUSERDllExport extern RTIBool 
ChatMessagePlugin_serialized_sample_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    DDS_KeyHash_t *keyhash,
    RTIBool deserialize_encapsulation,
    void *endpoint_plugin_qos); 

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
ChatMessagePlugin_new(void);

NDDSUSERDllExport extern void
ChatMessagePlugin_delete(struct PRESTypePlugin *);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* chatPlugin_1436264776_h */

