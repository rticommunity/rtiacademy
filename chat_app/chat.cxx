

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from chat.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#include <iosfwd>
#include <iomanip>

#include "rti/topic/cdr/Serialization.hpp"

#include "chat.hpp"
#include "chatPlugin.hpp"

#include <rti/util/ostream_operators.hpp>

// ---- ChatUser: 

ChatUser::ChatUser() :
    m_username_ ("") ,
    m_group_ ("")  {
}   

ChatUser::ChatUser (
    const std::string& username,
    const std::string& group,
    const dds::core::optional<std::string>& firstName,
    const dds::core::optional<std::string>& lastName)
    :
        m_username_( username ),
        m_group_( group ),
        m_firstName_( firstName ),
        m_lastName_( lastName ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
ChatUser::ChatUser(ChatUser&& other_) OMG_NOEXCEPT  :m_username_ (std::move(other_.m_username_))
,
m_group_ (std::move(other_.m_group_))
,
m_firstName_ (std::move(other_.m_firstName_))
,
m_lastName_ (std::move(other_.m_lastName_))
{
} 

ChatUser& ChatUser::operator=(ChatUser&&  other_) OMG_NOEXCEPT {
    ChatUser tmp(std::move(other_));
    swap(tmp); 
    return *this;
}
#endif
#endif   

void ChatUser::swap(ChatUser& other_)  OMG_NOEXCEPT 
{
    using std::swap;
    swap(m_username_, other_.m_username_);
    swap(m_group_, other_.m_group_);
    swap(m_firstName_, other_.m_firstName_);
    swap(m_lastName_, other_.m_lastName_);
}  

bool ChatUser::operator == (const ChatUser& other_) const {
    if (m_username_ != other_.m_username_) {
        return false;
    }
    if (m_group_ != other_.m_group_) {
        return false;
    }
    if (m_firstName_ != other_.m_firstName_) {
        return false;
    }
    if (m_lastName_ != other_.m_lastName_) {
        return false;
    }
    return true;
}
bool ChatUser::operator != (const ChatUser& other_) const {
    return !this->operator ==(other_);
}

std::ostream& operator << (std::ostream& o,const ChatUser& sample)
{
    rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "username: " << sample.username()<<", ";
    o << "group: " << sample.group()<<", ";
    o << "firstName: " << sample.firstName()<<", ";
    o << "lastName: " << sample.lastName() ;
    o <<"]";
    return o;
}

// ---- ChatMessage: 

ChatMessage::ChatMessage() :
    m_fromUser_ ("") ,
    m_toUser_ ("") ,
    m_toGroup_ ("") ,
    m_message_ ("")  {
}   

ChatMessage::ChatMessage (
    const std::string& fromUser,
    const std::string& toUser,
    const std::string& toGroup,
    const std::string& message)
    :
        m_fromUser_( fromUser ),
        m_toUser_( toUser ),
        m_toGroup_( toGroup ),
        m_message_( message ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
ChatMessage::ChatMessage(ChatMessage&& other_) OMG_NOEXCEPT  :m_fromUser_ (std::move(other_.m_fromUser_))
,
m_toUser_ (std::move(other_.m_toUser_))
,
m_toGroup_ (std::move(other_.m_toGroup_))
,
m_message_ (std::move(other_.m_message_))
{
} 

ChatMessage& ChatMessage::operator=(ChatMessage&&  other_) OMG_NOEXCEPT {
    ChatMessage tmp(std::move(other_));
    swap(tmp); 
    return *this;
}
#endif
#endif   

void ChatMessage::swap(ChatMessage& other_)  OMG_NOEXCEPT 
{
    using std::swap;
    swap(m_fromUser_, other_.m_fromUser_);
    swap(m_toUser_, other_.m_toUser_);
    swap(m_toGroup_, other_.m_toGroup_);
    swap(m_message_, other_.m_message_);
}  

bool ChatMessage::operator == (const ChatMessage& other_) const {
    if (m_fromUser_ != other_.m_fromUser_) {
        return false;
    }
    if (m_toUser_ != other_.m_toUser_) {
        return false;
    }
    if (m_toGroup_ != other_.m_toGroup_) {
        return false;
    }
    if (m_message_ != other_.m_message_) {
        return false;
    }
    return true;
}
bool ChatMessage::operator != (const ChatMessage& other_) const {
    return !this->operator ==(other_);
}

std::ostream& operator << (std::ostream& o,const ChatMessage& sample)
{
    rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "fromUser: " << sample.fromUser()<<", ";
    o << "toUser: " << sample.toUser()<<", ";
    o << "toGroup: " << sample.toGroup()<<", ";
    o << "message: " << sample.message() ;
    o <<"]";
    return o;
}

// --- Type traits: -------------------------------------------------

namespace rti { 
    namespace topic {

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code<ChatUser> {
            static DDS_TypeCode * get()
            {
                using namespace rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode ChatUser_g_tc_username_string;
                static DDS_TypeCode ChatUser_g_tc_group_string;
                static DDS_TypeCode ChatUser_g_tc_firstName_string;
                static DDS_TypeCode ChatUser_g_tc_lastName_string;

                static DDS_TypeCode_Member ChatUser_g_tc_members[4]=
                {

                    {
                        (char *)"username",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_KEY_MEMBER , /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"group",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"firstName",/* Member name */
                        {
                            2,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_NONKEY_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"lastName",/* Member name */
                        {
                            3,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_NONKEY_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode ChatUser_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"ChatUser", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        4, /* Number of members */
                        ChatUser_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for ChatUser*/

                if (is_initialized) {
                    return &ChatUser_g_tc;
                }

                ChatUser_g_tc_username_string = initialize_string_typecode(((MAX_NAME_SIZE)));
                ChatUser_g_tc_group_string = initialize_string_typecode(((MAX_NAME_SIZE)));
                ChatUser_g_tc_firstName_string = initialize_string_typecode(((MAX_NAME_SIZE)));
                ChatUser_g_tc_lastName_string = initialize_string_typecode(((MAX_NAME_SIZE)));

                ChatUser_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                ChatUser_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&ChatUser_g_tc_username_string;
                ChatUser_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&ChatUser_g_tc_group_string;
                ChatUser_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&ChatUser_g_tc_firstName_string;
                ChatUser_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&ChatUser_g_tc_lastName_string;

                /* Initialize the values for member annotations. */
                ChatUser_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                ChatUser_g_tc_members[0]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

                ChatUser_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                ChatUser_g_tc_members[1]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

                ChatUser_g_tc._data._sampleAccessInfo = sample_access_info();
                ChatUser_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &ChatUser_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ChatUser *sample;

                static RTIXCdrMemberAccessInfo ChatUser_g_memberAccessInfos[4] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo ChatUser_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &ChatUser_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ChatUser);
                if (sample == NULL) {
                    return NULL;
                }

                ChatUser_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->username() - (char *)sample);

                ChatUser_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->group() - (char *)sample);

                ChatUser_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->firstName() - (char *)sample);

                ChatUser_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->lastName() - (char *)sample);

                ChatUser_g_sampleAccessInfo.memberAccessInfos = 
                ChatUser_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(ChatUser);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        ChatUser_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        ChatUser_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                ChatUser_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                ChatUser_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer<ChatUser>;

                ChatUser_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &ChatUser_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin ChatUser_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &ChatUser_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const dds::core::xtypes::StructType& dynamic_type<ChatUser>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<ChatUser>::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code<ChatMessage> {
            static DDS_TypeCode * get()
            {
                using namespace rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode ChatMessage_g_tc_fromUser_string;
                static DDS_TypeCode ChatMessage_g_tc_toUser_string;
                static DDS_TypeCode ChatMessage_g_tc_toGroup_string;
                static DDS_TypeCode ChatMessage_g_tc_message_string;

                static DDS_TypeCode_Member ChatMessage_g_tc_members[4]=
                {

                    {
                        (char *)"fromUser",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_KEY_MEMBER , /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"toUser",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_KEY_MEMBER , /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"toGroup",/* Member name */
                        {
                            2,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_KEY_MEMBER , /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"message",/* Member name */
                        {
                            3,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode ChatMessage_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"ChatMessage", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        4, /* Number of members */
                        ChatMessage_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for ChatMessage*/

                if (is_initialized) {
                    return &ChatMessage_g_tc;
                }

                ChatMessage_g_tc_fromUser_string = initialize_string_typecode(((MAX_NAME_SIZE)));
                ChatMessage_g_tc_toUser_string = initialize_string_typecode(((MAX_NAME_SIZE)));
                ChatMessage_g_tc_toGroup_string = initialize_string_typecode(((MAX_NAME_SIZE)));
                ChatMessage_g_tc_message_string = initialize_string_typecode(((MAX_MSG_SIZE)));

                ChatMessage_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                ChatMessage_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&ChatMessage_g_tc_fromUser_string;
                ChatMessage_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&ChatMessage_g_tc_toUser_string;
                ChatMessage_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&ChatMessage_g_tc_toGroup_string;
                ChatMessage_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&ChatMessage_g_tc_message_string;

                /* Initialize the values for member annotations. */
                ChatMessage_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                ChatMessage_g_tc_members[0]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

                ChatMessage_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                ChatMessage_g_tc_members[1]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

                ChatMessage_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                ChatMessage_g_tc_members[2]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

                ChatMessage_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                ChatMessage_g_tc_members[3]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

                ChatMessage_g_tc._data._sampleAccessInfo = sample_access_info();
                ChatMessage_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &ChatMessage_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ChatMessage *sample;

                static RTIXCdrMemberAccessInfo ChatMessage_g_memberAccessInfos[4] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo ChatMessage_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &ChatMessage_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ChatMessage);
                if (sample == NULL) {
                    return NULL;
                }

                ChatMessage_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->fromUser() - (char *)sample);

                ChatMessage_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->toUser() - (char *)sample);

                ChatMessage_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->toGroup() - (char *)sample);

                ChatMessage_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->message() - (char *)sample);

                ChatMessage_g_sampleAccessInfo.memberAccessInfos = 
                ChatMessage_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(ChatMessage);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        ChatMessage_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        ChatMessage_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                ChatMessage_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                ChatMessage_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer<ChatMessage>;

                ChatMessage_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &ChatMessage_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin ChatMessage_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &ChatMessage_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const dds::core::xtypes::StructType& dynamic_type<ChatMessage>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<ChatMessage>::get())));
        }

    }
}

namespace dds { 
    namespace topic {
        void topic_type_support<ChatUser>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                ChatUserPlugin_new,
                ChatUserPlugin_delete);
        }

        std::vector<char>& topic_type_support<ChatUser>::to_cdr_buffer(
            std::vector<char>& buffer, 
            const ChatUser& sample,
            dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = ChatUserPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = ChatUserPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<ChatUser>::from_cdr_buffer(ChatUser& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = ChatUserPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create ChatUser from cdr buffer");
        }

        void topic_type_support<ChatUser>::reset_sample(ChatUser& sample) 
        {
            sample.username("");
            sample.group("");
            rti::topic::reset_sample(sample.firstName());
            rti::topic::reset_sample(sample.lastName());
        }

        void topic_type_support<ChatUser>::allocate_sample(ChatUser& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

            rti::topic::allocate_sample(sample.username(),  -1, (MAX_NAME_SIZE));
            rti::topic::allocate_sample(sample.group(),  -1, (MAX_NAME_SIZE));
        }

        void topic_type_support<ChatMessage>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                ChatMessagePlugin_new,
                ChatMessagePlugin_delete);
        }

        std::vector<char>& topic_type_support<ChatMessage>::to_cdr_buffer(
            std::vector<char>& buffer, 
            const ChatMessage& sample,
            dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = ChatMessagePlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = ChatMessagePlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<ChatMessage>::from_cdr_buffer(ChatMessage& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = ChatMessagePlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create ChatMessage from cdr buffer");
        }

        void topic_type_support<ChatMessage>::reset_sample(ChatMessage& sample) 
        {
            sample.fromUser("");
            sample.toUser("");
            sample.toGroup("");
            sample.message("");
        }

        void topic_type_support<ChatMessage>::allocate_sample(ChatMessage& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

            rti::topic::allocate_sample(sample.fromUser(),  -1, (MAX_NAME_SIZE));
            rti::topic::allocate_sample(sample.toUser(),  -1, (MAX_NAME_SIZE));
            rti::topic::allocate_sample(sample.toGroup(),  -1, (MAX_NAME_SIZE));
            rti::topic::allocate_sample(sample.message(),  -1, (MAX_MSG_SIZE));
        }

    }
}  

