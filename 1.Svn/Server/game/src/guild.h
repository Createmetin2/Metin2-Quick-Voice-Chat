//Find
		void		SendGuildDataUpdateToAllMember(SQLMsg* pmsg);
		
///Add
#if defined(VOICE_CHAT)
		void		SendGuildVoiceToAll(LPCHARACTER ch, int msg);
#endif

//Find
		int		m_general_count;
		
///Add
#if defined(VOICE_CHAT)
		DWORD	VoiceChatTime;
#endif