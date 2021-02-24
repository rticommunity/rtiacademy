

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from chat.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef chat_1436264776_hpp
#define chat_1436264776_hpp

#include <iosfwd>

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport __declspec(dllexport)
#endif

#include "dds/domain/DomainParticipant.hpp"
#include "dds/topic/TopicTraits.hpp"
#include "dds/core/SafeEnumeration.hpp"
#include "dds/core/String.hpp"
#include "dds/core/array.hpp"
#include "dds/core/vector.hpp"
#include "dds/core/Optional.hpp"
#include "dds/core/xtypes/DynamicType.hpp"
#include "dds/core/xtypes/StructType.hpp"
#include "dds/core/xtypes/UnionType.hpp"
#include "dds/core/xtypes/EnumType.hpp"
#include "dds/core/xtypes/AliasType.hpp"
#include "rti/core/array.hpp"
#include "rti/core/BoundedSequence.hpp"
#include "rti/util/StreamFlagSaver.hpp"
#include "rti/domain/PluginSupport.hpp"
#include "rti/core/LongDouble.hpp"
#include "dds/core/External.hpp"
#include "rti/core/Pointer.hpp"
#include "rti/topic/TopicTraits.hpp"

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

static const int32_t MAX_NAME_SIZE = 128;

static const int32_t MAX_MSG_SIZE = 512;

class NDDSUSERDllExport ChatUser {
  public:
    ChatUser();

    ChatUser(
        const std::string& username,
        const std::string& group,
        const dds::core::optional<std::string>& firstName,
        const dds::core::optional<std::string>& lastName);

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    ChatUser (ChatUser&&) = default;
    ChatUser& operator=(ChatUser&&) = default;
    ChatUser& operator=(const ChatUser&) = default;
    ChatUser(const ChatUser&) = default;
    #else
    ChatUser(ChatUser&& other_) OMG_NOEXCEPT;  
    ChatUser& operator=(ChatUser&&  other_) OMG_NOEXCEPT;
    #endif
    #endif 

    std::string& username() OMG_NOEXCEPT {
        return m_username_;
    }

    const std::string& username() const OMG_NOEXCEPT {
        return m_username_;
    }

    void username(const std::string& value) {
        m_username_ = value;
    }

    std::string& group() OMG_NOEXCEPT {
        return m_group_;
    }

    const std::string& group() const OMG_NOEXCEPT {
        return m_group_;
    }

    void group(const std::string& value) {
        m_group_ = value;
    }

    dds::core::optional<std::string>& firstName() OMG_NOEXCEPT {
        return m_firstName_;
    }

    const dds::core::optional<std::string>& firstName() const OMG_NOEXCEPT {
        return m_firstName_;
    }

    void firstName(const dds::core::optional<std::string>& value) {
        m_firstName_ = value;
    }

    dds::core::optional<std::string>& lastName() OMG_NOEXCEPT {
        return m_lastName_;
    }

    const dds::core::optional<std::string>& lastName() const OMG_NOEXCEPT {
        return m_lastName_;
    }

    void lastName(const dds::core::optional<std::string>& value) {
        m_lastName_ = value;
    }

    bool operator == (const ChatUser& other_) const;
    bool operator != (const ChatUser& other_) const;

    void swap(ChatUser& other_) OMG_NOEXCEPT ;

  private:

    std::string m_username_;
    std::string m_group_;
    dds::core::optional<std::string> m_firstName_;
    dds::core::optional<std::string> m_lastName_;

};

inline void swap(ChatUser& a, ChatUser& b)  OMG_NOEXCEPT 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const ChatUser& sample);

class NDDSUSERDllExport ChatMessage {
  public:
    ChatMessage();

    ChatMessage(
        const std::string& fromUser,
        const std::string& toUser,
        const std::string& toGroup,
        const std::string& message);

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    ChatMessage (ChatMessage&&) = default;
    ChatMessage& operator=(ChatMessage&&) = default;
    ChatMessage& operator=(const ChatMessage&) = default;
    ChatMessage(const ChatMessage&) = default;
    #else
    ChatMessage(ChatMessage&& other_) OMG_NOEXCEPT;  
    ChatMessage& operator=(ChatMessage&&  other_) OMG_NOEXCEPT;
    #endif
    #endif 

    std::string& fromUser() OMG_NOEXCEPT {
        return m_fromUser_;
    }

    const std::string& fromUser() const OMG_NOEXCEPT {
        return m_fromUser_;
    }

    void fromUser(const std::string& value) {
        m_fromUser_ = value;
    }

    std::string& toUser() OMG_NOEXCEPT {
        return m_toUser_;
    }

    const std::string& toUser() const OMG_NOEXCEPT {
        return m_toUser_;
    }

    void toUser(const std::string& value) {
        m_toUser_ = value;
    }

    std::string& toGroup() OMG_NOEXCEPT {
        return m_toGroup_;
    }

    const std::string& toGroup() const OMG_NOEXCEPT {
        return m_toGroup_;
    }

    void toGroup(const std::string& value) {
        m_toGroup_ = value;
    }

    std::string& message() OMG_NOEXCEPT {
        return m_message_;
    }

    const std::string& message() const OMG_NOEXCEPT {
        return m_message_;
    }

    void message(const std::string& value) {
        m_message_ = value;
    }

    bool operator == (const ChatMessage& other_) const;
    bool operator != (const ChatMessage& other_) const;

    void swap(ChatMessage& other_) OMG_NOEXCEPT ;

  private:

    std::string m_fromUser_;
    std::string m_toUser_;
    std::string m_toGroup_;
    std::string m_message_;

};

inline void swap(ChatMessage& a, ChatMessage& b)  OMG_NOEXCEPT 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const ChatMessage& sample);

namespace rti {
    namespace flat {
        namespace topic {
        }
    }
}
namespace dds {
    namespace topic {

        template<>
        struct topic_type_name<ChatUser> {
            NDDSUSERDllExport static std::string value() {
                return "ChatUser";
            }
        };

        template<>
        struct is_topic_type<ChatUser> : public dds::core::true_type {};

        template<>
        struct topic_type_support<ChatUser> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const ChatUser& sample,
                dds::core::policy::DataRepresentationId representation 
                = dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(ChatUser& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(ChatUser& sample);

            NDDSUSERDllExport 
            static void allocate_sample(ChatUser& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name<ChatMessage> {
            NDDSUSERDllExport static std::string value() {
                return "ChatMessage";
            }
        };

        template<>
        struct is_topic_type<ChatMessage> : public dds::core::true_type {};

        template<>
        struct topic_type_support<ChatMessage> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const ChatMessage& sample,
                dds::core::policy::DataRepresentationId representation 
                = dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(ChatMessage& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(ChatMessage& sample);

            NDDSUSERDllExport 
            static void allocate_sample(ChatMessage& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

    }
}

namespace rti { 
    namespace topic {

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type<ChatUser> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility<ChatUser> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type<ChatMessage> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility<ChatMessage> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

    }
}

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif // chat_1436264776_hpp

