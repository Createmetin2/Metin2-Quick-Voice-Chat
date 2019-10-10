//Find
		void		SendPartyUnlinkOneToAll(LPCHARACTER ch);
	
///Add
#if defined(VOICE_CHAT)
		void		SendPartyVoiceToAll(LPCHARACTER ch, int msg);
#endif

//Find
		DWORD		m_dwLeaderPID;
		
///Add
#if defined(VOICE_CHAT)
		DWORD		VoiceChatTime;
#endif