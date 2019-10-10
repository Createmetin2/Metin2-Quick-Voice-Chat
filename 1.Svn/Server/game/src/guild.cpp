//Find
	m_general_count = 0;
	
///Add
#if defined(VOICE_CHAT)
	VoiceChatTime = 0;
#endif

//Find
void CGuild::SendGuildDataUpdateToAllMember(SQLMsg* pmsg)
{
	...
}

///Add
#if defined(VOICE_CHAT)
#include "VoiceMessage.h"
void CGuild::SendGuildVoiceToAll(LPCHARACTER ch, int msg)
{
	if (!ch || !m_memberOnline.size() || msg < 0 || msg >= VoiceMessage::voiceinfo.size())
		return;
	if (VoiceChatTime > get_global_time()) {
		ch->ChatPacket(CHAT_TYPE_INFO, "You need to wait!");
		return;
	}
	std::string mes = std::string(ch->GetName()) + "->[VOICE CHAT]:" + VoiceMessage::voiceinfo[msg].msg;
	for (const auto & it : m_memberOnline) {
		if (it && it->GetDesc()) {
			it->ChatPacket(CHAT_TYPE_COMMAND, "voicechat %s", VoiceMessage::voiceinfo[msg].dir.c_str());
			it->ChatPacket(CHAT_TYPE_GUILD, mes.c_str());
		}
	}
	VoiceChatTime = get_global_time() + 4; // Change duration
}
#endif