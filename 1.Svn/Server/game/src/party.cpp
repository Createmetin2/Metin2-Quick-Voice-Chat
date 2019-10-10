//Find
	m_dwLeaderPID = 0;
	
///Add
#if defined(VOICE_CHAT)
	VoiceChatTime = 0;
#endif

//Find
void CParty::SendPartyRemoveOneToAll(DWORD pid)
{
	...
}

///Add
#if defined(VOICE_CHAT)
#include "VoiceMessage.h"
void CParty::SendPartyVoiceToAll(LPCHARACTER ch, int msg)
{
	if (!ch || !m_memberMap.size() || msg < 0 || msg >= VoiceMessage::voiceinfo.size())
		return;
	if (VoiceChatTime > get_global_time()) {
		ch->ChatPacket(CHAT_TYPE_INFO, "You need to wait!");
		return;
	}
	std::string mes = std::string(ch->GetName()) + "->[VOICE CHAT]:" + VoiceMessage::voiceinfo[msg].msg;
	for (const auto & it : m_memberMap) {
		if (it.second.pCharacter && it.second.pCharacter->GetDesc()) {
			it.second.pCharacter->ChatPacket(CHAT_TYPE_COMMAND, "voicechat %s", VoiceMessage::voiceinfo[msg].dir.c_str());
			it.second.pCharacter->ChatPacket(CHAT_TYPE_PARTY, mes.c_str());
		}
	}
	VoiceChatTime = get_global_time() + 4; // Change duration
}
#endif