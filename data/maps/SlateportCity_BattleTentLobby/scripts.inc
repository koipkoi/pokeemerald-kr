.set LOCALID_ATTENDANT, 1

SlateportCity_BattleTentLobby_MapScripts:: @ 8208730
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_BattleTentLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SlateportCity_BattleTentLobby_OnWarp
	.byte 0

SlateportCity_BattleTentLobby_OnWarp: @ 820873B
	map_script_2 VAR_TEMP_1, 0, SlateportCity_BattleTentLobby_EventScript_TurnPlayerNorth
	.2byte 0

SlateportCity_BattleTentLobby_EventScript_TurnPlayerNorth:: @ 8208745
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

SlateportCity_BattleTentLobby_OnFrame: @ 820874F
	map_script_2 VAR_TEMP_0, 0, SlateportCity_BattleTentLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_SAVING, SlateportCity_BattleTentLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_PAUSED, SlateportCity_BattleTentLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_WON, SlateportCity_BattleTentLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_LOST, SlateportCity_BattleTentLobby_EventScript_LostChallenge
	.2byte 0

SlateportCity_BattleTentLobby_EventScript_GetChallengeStatus:: @ 8208779
	frontier_getstatus
	end

SlateportCity_BattleTentLobby_EventScript_QuitWithoutSaving:: @ 8208782
	lockall
	msgbox SlateportCity_BattleTentLobby_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
	closemessage
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_0, 255
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	releaseall
	end

SlateportCity_BattleTentLobby_EventScript_WonChallenge:: @ 82087B7
	lockall
	message SlateportCity_BattleTentLobby_Text_WonThreeMatchesReturnMons
	waitmessage
	slateporttent_setrandomprize
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	slateporttent_save 0
	playse SE_SAVE
	waitse
SlateportCity_BattleTentLobby_EventScript_GivePrize:: @ 82087E9
	msgbox SlateportCity_BattleTentLobby_Text_AwardYouThisPrize, MSGBOX_DEFAULT
	slateporttent_giveprize
	switch VAR_RESULT
	case FALSE, SlateportCity_BattleTentLobby_EventScript_NoRoomForPrize
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	message BattleFrontier_BattleTowerLobby_Text_ReceivedPrize  @ Odd that it uses Tower's instead of Factory's or its own
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	goto SlateportCity_BattleTentLobby_EventScript_EndGivePrize

SlateportCity_BattleTentLobby_EventScript_NoRoomForPrize:: @ 820882A
	msgbox SlateportCity_BattleTentLobby_Text_NoRoomInBagMakeRoom, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentLobby_EventScript_EndGivePrize

SlateportCity_BattleTentLobby_EventScript_LostChallenge:: @ 8208837
	lockall
	message SlateportCity_BattleTentLobby_Text_ReturnRentalMonsSaveResults
	waitmessage
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	slateporttent_save 0
	playse SE_SAVE
	waitse

SlateportCity_BattleTentLobby_EventScript_EndGivePrize:: @ 8208861
	msgbox SlateportCity_BattleTentLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	releaseall
	end

SlateportCity_BattleTentLobby_EventScript_ResumeChallenge:: @ 8208871
	lockall
	message SlateportCity_BattleTentLobby_Text_BeenWaitingForYou
	waitmessage
	slateporttent_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_0, 255
	setvar VAR_0x8006, 2
	goto SlateportCity_BattleTentLobby_EventScript_EnterChallenge

SlateportCity_BattleTentLobby_EventScript_Attendant:: @ 82088AA
	lock
	faceplayer
	slateporttent_getprize
	compare VAR_RESULT, ITEM_NONE
	goto_if_ne SlateportCity_BattleTentLobby_EventScript_GivePrize
	special SavePlayerParty
	msgbox SlateportCity_BattleTentLobby_Text_WelcomeToBattleTent, MSGBOX_DEFAULT
SlateportCity_BattleTentLobby_EventScript_AskEnterChallenge:: @ 82088CA
	message SlateportCity_BattleTentLobby_Text_TakeChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, 0
	switch VAR_RESULT
	case 0, SlateportCity_BattleTentLobby_EventScript_TryEnterChallenge
	case 1, SlateportCity_BattleTentLobby_EventScript_ExplainChallenge
	case 2, SlateportCity_BattleTentLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, SlateportCity_BattleTentLobby_EventScript_CancelChallenge

SlateportCity_BattleTentLobby_EventScript_TryEnterChallenge:: @ 8208906
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_TENT
	msgbox SlateportCity_BattleTentLobby_Text_SaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, SlateportCity_BattleTentLobby_EventScript_LoadPartyCancelChallenge
	case YES, SlateportCity_BattleTentLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, SlateportCity_BattleTentLobby_EventScript_LoadPartyCancelChallenge

SlateportCity_BattleTentLobby_EventScript_SaveBeforeChallenge:: @ 8208950
	setvar VAR_TEMP_0, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	slateporttent_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_0, 255
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_BattleTentLobby_EventScript_CancelChallengeSaveFailed
	setvar VAR_0x8006, 0
SlateportCity_BattleTentLobby_EventScript_EnterChallenge:: @ 82089AC
	msgbox SlateportCity_BattleTentLobby_Text_StepThisWay, MSGBOX_DEFAULT
	closemessage
	call SlateportCity_BattleTentLobby_EventScript_WalkToDoor
	warp MAP_SLATEPORT_CITY_BATTLE_TENT_CORRIDOR, 255, 2, 7
	setvar VAR_TEMP_0, 0
	waitstate
	end

SlateportCity_BattleTentLobby_EventScript_WalkToDoor:: @ 82089C9
	applymovement LOCALID_ATTENDANT, SlateportCity_BattleTentLobby_Movement_AttendantWalkToDoor
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_BattleTentLobby_Movement_PlayerWalkToDoor
	waitmovement 0
	opendoor 6, 1
	waitdooranim
	applymovement LOCALID_ATTENDANT, SlateportCity_BattleTentLobby_Movement_AttendantEnterDoor
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_BattleTentLobby_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 6, 1
	waitdooranim
	return

SlateportCity_BattleTentLobby_Movement_AttendantWalkToDoor: @ 82089F8
	walk_up
	walk_up
	walk_up
	step_end

SlateportCity_BattleTentLobby_Movement_AttendantEnterDoor: @ 82089FC
	walk_up
	set_invisible
	step_end

SlateportCity_BattleTentLobby_Movement_PlayerWalkToDoor: @ 82089FF
	walk_up
	walk_up
	walk_up
	step_end

SlateportCity_BattleTentLobby_Movement_PlayerEnterDoor: @ 8208A03
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_BattleTentLobby_EventScript_ExplainChallenge:: @ 8208A07
	msgbox SlateportCity_BattleTentLobby_Text_ExplainSlateportTent, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentLobby_EventScript_AskEnterChallenge

SlateportCity_BattleTentLobby_EventScript_CancelChallengeSaveFailed:: @ 8208A14
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto SlateportCity_BattleTentLobby_EventScript_CancelChallenge

SlateportCity_BattleTentLobby_EventScript_LoadPartyCancelChallenge:: @ 8208A2B
	special LoadPlayerParty
SlateportCity_BattleTentLobby_EventScript_CancelChallenge:: @ 8208A2E
	msgbox SlateportCity_BattleTentLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
	release
	end

@ Unused
SlateportCity_BattleTentLobby_Movement_UnusedEnterDoor:: @ 8208A38
	walk_up
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_BattleTentLobby_EventScript_TormentGiver:: @ 8208A3D
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM41, SlateportCity_BattleTentLobby_EventScript_ReceivedTorment
	msgbox SlateportCity_BattleTentLobby_Text_CouldntFindMonForMe, MSGBOX_DEFAULT
	giveitem ITEM_TM41
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM41
	msgbox SlateportCity_BattleTentLobby_Text_ExplainTorment, MSGBOX_DEFAULT
	release
	end

SlateportCity_BattleTentLobby_EventScript_ReceivedTorment:: @ 8208A74
	msgbox SlateportCity_BattleTentLobby_Text_ExplainTorment, MSGBOX_DEFAULT
	release
	end

SlateportCity_BattleTentLobby_EventScript_Man:: @ 8208A7E
	msgbox SlateportCity_BattleTentLobby_Text_IllTryUsingBugMons, MSGBOX_NPC
	end

SlateportCity_BattleTentLobby_EventScript_Girl:: @ 8208A87
	msgbox SlateportCity_BattleTentLobby_Text_BattleEvenWithoutToughMons, MSGBOX_NPC
	end

SlateportCity_BattleTentLobby_EventScript_Woman:: @ 8208A90
	msgbox SlateportCity_BattleTentLobby_Text_NiceIfMoreSelection, MSGBOX_NPC
	end

SlateportCity_BattleTentLobby_EventScript_RulesBoard:: @ 8208A99
	lockall
	msgbox BattleFrontier_BattleFactoryLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentLobby_EventScript_ReadRulesBoard
	end

SlateportCity_BattleTentLobby_EventScript_ReadRulesBoard:: @ 8208AA8
	message BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 17, 0, MULTI_SLATEPORT_TENT_RULES, 0
	switch VAR_RESULT
	case 0, SlateportCity_BattleTentLobby_EventScript_RulesBasics
	case 1, SlateportCity_BattleTentLobby_EventScript_RulesSwapPartner
	case 2, SlateportCity_BattleTentLobby_EventScript_RulesSwapNumber
	case 3, SlateportCity_BattleTentLobby_EventScript_RulesSwapNotes
	case 4, SlateportCity_BattleTentLobby_EventScript_RulesMons
	case 5, SlateportCity_BattleTentLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, SlateportCity_BattleTentLobby_EventScript_ExitRules
	end

SlateportCity_BattleTentLobby_EventScript_RulesBasics:: @ 8208B06
	msgbox SlateportCity_BattleTentLobby_Text_ExplainBasicRules, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentLobby_EventScript_ReadRulesBoard
	end

SlateportCity_BattleTentLobby_EventScript_RulesSwapPartner:: @ 8208B14
	msgbox SlateportCity_BattleTentLobby_Text_ExplainSwapPartnerRules, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentLobby_EventScript_ReadRulesBoard
	end

SlateportCity_BattleTentLobby_EventScript_RulesSwapNumber:: @ 8208B22
	msgbox SlateportCity_BattleTentLobby_Text_ExplainSwapNumberRules, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentLobby_EventScript_ReadRulesBoard
	end

SlateportCity_BattleTentLobby_EventScript_RulesSwapNotes:: @ 8208B30
	msgbox SlateportCity_BattleTentLobby_Text_ExplainSwapNotes, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentLobby_EventScript_ReadRulesBoard
	end

SlateportCity_BattleTentLobby_EventScript_RulesMons:: @ 8208B3E
	msgbox SlateportCity_BattleTentLobby_Text_ExplainMonRules, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentLobby_EventScript_ReadRulesBoard
	end

SlateportCity_BattleTentLobby_EventScript_ExitRules:: @ 8208B4C
	releaseall
	end

SlateportCity_BattleTentLobby_Text_CouldntFindMonForMe: @ 8208B4E
	.string "좀처럼 빌리고 싶은 포켓몬을\n"
	.string "찾지 못하겠어서\l"
	.string "저기 있는 사람한테 말했는데\p"
	.string "전혀 들어주질 않는단 말이지\n"
	.string "물론 전혀 분하지 않아!\p"
	.string "어이 너!\n"
	.string "잠자코 이걸 받도록 해!$"
	@ なかなか かりたい ポケモンがｎ
	@ みつからねぇ からよぉｌ
	@ そこの に-さんに もんく いったけどよぉｐ
	@ ちぃっとも あいて してくれねぇのさｎ
	@ くやしいったら ありゃ しねぇぜ!ｐ
	@ おい おまえ!ｎ
	@ だまって これを うけとれよぉ!

SlateportCity_BattleTentLobby_Text_ExplainTorment: @ 8208C5C
	.string "기술머신41은 트집!\p"
	.string "상대가 계속 같은 기술을\n"
	.string "쓰지 못하게 하는 기술이지!\p"
	.string "말해 두지만\n"
	.string "나는 트집 잡은 적 없어!$"
	@ わざマシン41は いちゃもん!ｐ
	@ あいてによぉ おなじ わざを つづけてｎ
	@ ださせねえように する わざ なんだよぉ!ｐ
	@ いっとくけどなぁｎ
	@ おれは いちゃもん つけてねぇぞ!

SlateportCity_BattleTentLobby_Text_IllTryUsingBugMons: @ 8208D27
	.string "가끔은 싫어하는\n"
	.string "벌레타입 포켓몬도\l"
	.string "사용해 볼까?\l"
	.string "좋아하게 될지도 모르니까!$"
	@ たまには にがてなｎ
	@ むしタイプの ポケモンでもｌ
	@ つかって みようかな?ｌ
	@ スキに なるかも しれないし!

SlateportCity_BattleTentLobby_Text_BattleEvenWithoutToughMons: @ 8208DA6
	.string "강한 포켓몬이 없어도\n"
	.string "여기서라면 잔뜩 승부할 수 있어!$"
	@ つよい ポケモン もってなくてもｎ
	@ ここでなら いっぱい しょうぶできるね!

SlateportCity_BattleTentLobby_Text_NiceIfMoreSelection: @ 8208DF1
	.string "멋진 트레이너 오빠도\n"
	.string "빌릴 수 있으면 좋겠다$"
	@ ステキな トレ-ナ-の おにいさんもｎ
	@ かしだして くれれば いいのにぃ

