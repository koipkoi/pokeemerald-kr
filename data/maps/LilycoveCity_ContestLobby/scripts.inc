@ Note: data/scripts/berry_blender.inc is for the same map, so shares local IDs
.set LOCALID_RECEPTIONIST, 1
.set LOCALID_LINK_RECEPTIONIST, 2
.set LOCALID_ARTIST, 4
.set LOCALID_ARTIST_LINK, 11

LilycoveCity_ContestLobby_MapScripts:: @ 821A211
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_ContestLobby_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LilycoveCity_ContestLobby_OnFrame
	.byte 0

@ Some scripts for this room are split into data/scripts/contest_hall and data/scripts/berry_blender

LilycoveCity_ContestLobby_OnTransition: @ 821A21C
	call LilycoveCity_ContestLobby_EventScript_TryShowContestReporter
	call LilycoveCity_ContestLobby_EventScript_TryShowBlendMaster
	end

LilycoveCity_ContestLobby_EventScript_TryShowBlendMaster:: @ 821A227
	getpricereduction POKENEWS_BLENDMASTER
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_ContestLobby_EventScript_ShowBlendMaster
	clearflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_BLEND_MASTER_REPLACEMENT
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_BLEND_MASTER
	return

LilycoveCity_ContestLobby_EventScript_ShowBlendMaster:: @ 821A23C
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_BLEND_MASTER_REPLACEMENT
	clearflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_BLEND_MASTER
	return

LilycoveCity_ContestLobby_OnFrame: @ 821A243
	map_script_2 VAR_LILYCOVE_CONTEST_LOBBY_STATE, 1, LilycoveCity_ContestLobby_EventScript_TryDoContestArtist
	map_script_2 VAR_LILYCOVE_CONTEST_LOBBY_STATE, 2, LilycoveCity_ContestLobby_EventScript_TryDoLinkContestArtist
	.2byte 0

LilycoveCity_ContestLobby_EventScript_TryDoContestArtist:: @ 821A255
	goto_if_set FLAG_HIDE_LILYCOVE_MUSEUM_CURATOR, LilycoveCity_ContestLobby_EventScript_ContestArtist
	setvar VAR_LILYCOVE_CONTEST_LOBBY_STATE, 0
	end

LilycoveCity_ContestLobby_EventScript_ContestArtist:: @ 821A264
	lockall
	addobject LOCALID_ARTIST
	applymovement LOCALID_ARTIST, LilycoveCity_ContestLobby_Movement_ArtistApproachPlayer
	waitmovement LOCALID_ARTIST
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_ContestLobby_Movement_PlayerFaceArtist
	waitmovement 0
	msgbox LilycoveCity_ContestLobby_Text_YourPokemonSpurredMeToPaint, MSGBOX_DEFAULT
	lockall
	fadescreen FADE_TO_BLACK
	showcontestwinner CONTEST_WINNER_ARTIST
	lockall
	msgbox LilycoveCity_ContestLobby_Text_ShouldITakePaintingToMuseum, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LilycoveCity_ContestLobby_EventScript_TakePaintingToMuseum
	compare VAR_RESULT, NO
	goto_if_eq LilycoveCity_ContestLobby_EventScript_ConfirmDontTakePainting
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_TakePaintingToMuseum:: @ 821A2AA
	msgbox LilycoveCity_ContestLobby_Text_IllTakePaintingToMuseum, MSGBOX_DEFAULT
	closemessage
	special SaveMuseumContestPainting
	setvar VAR_LILYCOVE_CONTEST_LOBBY_STATE, 0
	specialvar VAR_RESULT, GiveMonArtistRibbon
	compare VAR_RESULT, TRUE
	call_if_eq LilycoveCity_ContestLobby_EventScript_ReceivedArtistRibbon
	applymovement LOCALID_ARTIST, LilycoveCity_ContestLobby_Movement_ArtistExit
	waitmovement 0
	removeobject LOCALID_ARTIST
	call LilycoveCity_ContestLobby_EventScript_UpdateMuseumPatrons
	call LilycoveCity_ContestLobby_EventScript_SetPaintingFlag
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_ConfirmDontTakePainting:: @ 821A2E4
	msgbox LilycoveCity_ContestLobby_Text_TakeHomeButIdLikeToTakeToMuseum, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LilycoveCity_ContestLobby_EventScript_TakePaintingToMuseum
	msgbox LilycoveCity_ContestLobby_Text_FineThatsTheWayItIs, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ARTIST, LilycoveCity_ContestLobby_Movement_ArtistExit
	waitmovement 0
	setvar VAR_LILYCOVE_CONTEST_LOBBY_STATE, 0
	removeobject LOCALID_ARTIST
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_ReceivedArtistRibbon:: @ 821A314
	incrementgamestat GAME_STAT_RECEIVED_RIBBONS
	special BufferContestWinnerMonName
	applymovement LOCALID_ARTIST, LilycoveCity_ContestLobby_Movement_ArtistBeginToExit
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_ARTIST, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_ARTIST, LilycoveCity_ContestLobby_Movement_ArtistReturnToPlayer
	waitmovement 0
	msgbox LilycoveCity_ContestLobby_Text_TakeMementoOfPainting, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	msgbox LilycoveCity_ContestLobby_Text_ReceivedARibbon, MSGBOX_DEFAULT
	waitfanfare
	msgbox LilycoveCity_ContestLobby_Text_PutTheRibbonOnMon, MSGBOX_DEFAULT
	msgbox LilycoveCity_ContestLobby_Text_OkaySeeYou, MSGBOX_DEFAULT
	closemessage
	return

LilycoveCity_ContestLobby_EventScript_UpdateMuseumPatrons:: @ 821A360
	specialvar VAR_0x8004, CountPlayerContestPaintings
	switch VAR_0x8004
	case 1, LilycoveCity_ContestLobby_EventScript_ShowPatron1
	case 2, LilycoveCity_ContestLobby_EventScript_ShowPatron2
	case 3, LilycoveCity_ContestLobby_EventScript_ShowPatron3
	case 4, LilycoveCity_ContestLobby_EventScript_ShowPatron4
	case 5, LilycoveCity_ContestLobby_EventScript_ShowTourists
	return

LilycoveCity_ContestLobby_EventScript_ShowPatron1:: @ 821A3A2
	clearflag FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_1
	return

LilycoveCity_ContestLobby_EventScript_ShowPatron2:: @ 821A3A6
	clearflag FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_2
	return

LilycoveCity_ContestLobby_EventScript_ShowPatron3:: @ 821A3AA
	clearflag FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_3
	return

LilycoveCity_ContestLobby_EventScript_ShowPatron4:: @ 821A3AE
	clearflag FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_4
	return

LilycoveCity_ContestLobby_EventScript_ShowTourists:: @ 821A3B2
	clearflag FLAG_HIDE_LILYCOVE_MUSEUM_TOURISTS
	return

LilycoveCity_ContestLobby_EventScript_SetPaintingFlag:: @ 821A3B6
	switch VAR_CONTEST_CATEGORY
	case CONTEST_CATEGORY_COOL, LilycoveCity_ContestLobby_EventScript_MadeCoolPainting
	case CONTEST_CATEGORY_BEAUTY, LilycoveCity_ContestLobby_EventScript_MadeBeautyPainting
	case CONTEST_CATEGORY_CUTE, LilycoveCity_ContestLobby_EventScript_MadeCutePainting
	case CONTEST_CATEGORY_SMART, LilycoveCity_ContestLobby_EventScript_MadeSmartPainting
	case CONTEST_CATEGORY_TOUGH, LilycoveCity_ContestLobby_EventScript_MadeToughPainting
	return

LilycoveCity_ContestLobby_EventScript_MadeCoolPainting:: @ 821A3F3
	setflag FLAG_COOL_PAINTING_MADE
	return

LilycoveCity_ContestLobby_EventScript_MadeBeautyPainting:: @ 821A3F7
	setflag FLAG_BEAUTY_PAINTING_MADE
	return

LilycoveCity_ContestLobby_EventScript_MadeCutePainting:: @ 821A3FB
	setflag FLAG_CUTE_PAINTING_MADE
	return

LilycoveCity_ContestLobby_EventScript_MadeSmartPainting:: @ 821A3FF
	setflag FLAG_SMART_PAINTING_MADE
	return

LilycoveCity_ContestLobby_EventScript_MadeToughPainting:: @ 821A403
	setflag FLAG_TOUGH_PAINTING_MADE
	return

LilycoveCity_ContestLobby_Movement_ArtistApproachPlayer: @ 821A407
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

LilycoveCity_ContestLobby_Movement_ArtistExit: @ 821A40F
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LilycoveCity_ContestLobby_Movement_PlayerFaceArtist: @ 821A418
	walk_in_place_fastest_left
	step_end

LilycoveCity_ContestLobby_Movement_ArtistBeginToExit: @ 821A41A
	walk_down
	walk_down
	walk_down
	step_end

LilycoveCity_ContestLobby_Movement_ArtistReturnToPlayer: @ 821A41E
	delay_16
	delay_16
	delay_16
	delay_16
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_in_place_fastest_right
	step_end

LilycoveCity_ContestLobby_EventScript_TryDoLinkContestArtist:: @ 821A427
	goto_if_set FLAG_HIDE_LILYCOVE_MUSEUM_CURATOR, LilycoveCity_ContestLobby_EventScript_LinkContestArtist
	setvar VAR_LILYCOVE_CONTEST_LOBBY_STATE, 0
	end

LilycoveCity_ContestLobby_EventScript_LinkContestArtist:: @ 821A436
	lockall
	addobject LOCALID_ARTIST_LINK
	applymovement LOCALID_ARTIST_LINK, LilycoveCity_ContestLobby_Movement_LinkArtistApproachPlayer
	waitmovement LOCALID_ARTIST_LINK
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_ContestLobby_Movement_PlayerFaceLinkArtist
	waitmovement 0
	msgbox LilycoveCity_ContestLobby_Text_YourPokemonSpurredMeToPaint, MSGBOX_DEFAULT
	lockall
	fadescreen FADE_TO_BLACK
	showcontestwinner CONTEST_WINNER_ARTIST
	msgbox LilycoveCity_ContestLobby_Text_ShouldITakePaintingToMuseum, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LilycoveCity_ContestLobby_EventScript_TakePaintingToMuseumLink
	compare VAR_RESULT, NO
	goto_if_eq LilycoveCity_ContestLobby_EventScript_ConfirmDontTakePaintingLink
	end

LilycoveCity_ContestLobby_EventScript_TakePaintingToMuseumLink:: @ 821A47A
	msgbox LilycoveCity_ContestLobby_Text_IllTakePaintingToMuseum, MSGBOX_DEFAULT
	closemessage
	special SaveMuseumContestPainting
	setvar VAR_LILYCOVE_CONTEST_LOBBY_STATE, 0
	specialvar VAR_RESULT, GiveMonArtistRibbon
	compare VAR_RESULT, TRUE
	call_if_eq LilycoveCity_ContestLobby_EventScript_ReceivedLinkArtistRibbon
	applymovement LOCALID_ARTIST_LINK, LilycoveCity_ContestLobby_Movement_LinkArtistExit
	waitmovement 0
	removeobject LOCALID_ARTIST_LINK
	call LilycoveCity_ContestLobby_EventScript_UpdateMuseumPatrons
	call LilycoveCity_ContestLobby_EventScript_SetPaintingFlag
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_ConfirmDontTakePaintingLink:: @ 821A4B4
	msgbox LilycoveCity_ContestLobby_Text_TakeHomeButIdLikeToTakeToMuseum, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LilycoveCity_ContestLobby_EventScript_TakePaintingToMuseumLink
	msgbox LilycoveCity_ContestLobby_Text_FineThatsTheWayItIs, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ARTIST_LINK, LilycoveCity_ContestLobby_Movement_LinkArtistExit
	waitmovement 0
	setvar VAR_LILYCOVE_CONTEST_LOBBY_STATE, 0
	removeobject LOCALID_ARTIST_LINK
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_ReceivedLinkArtistRibbon:: @ 821A4E4
	incrementgamestat GAME_STAT_RECEIVED_RIBBONS
	setflag FLAG_SYS_RIBBON_GET
	special BufferContestWinnerMonName
	applymovement LOCALID_ARTIST_LINK, LilycoveCity_ContestLobby_Movement_LinkArtistBeginExit
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_ARTIST_LINK, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_ARTIST_LINK, LilycoveCity_ContestLobby_Movement_LinkArtistReturnToPlayer
	waitmovement 0
	msgbox LilycoveCity_ContestLobby_Text_TakeMementoOfPainting, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	msgbox LilycoveCity_ContestLobby_Text_ReceivedARibbon, MSGBOX_DEFAULT
	waitfanfare
	msgbox LilycoveCity_ContestLobby_Text_PutTheRibbonOnMon, MSGBOX_DEFAULT
	msgbox LilycoveCity_ContestLobby_Text_OkaySeeYou, MSGBOX_DEFAULT
	closemessage
	return

LilycoveCity_ContestLobby_Movement_LinkArtistApproachPlayer: @ 821A533
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LilycoveCity_ContestLobby_Movement_LinkArtistExit: @ 821A53C
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LilycoveCity_ContestLobby_Movement_PlayerFaceLinkArtist: @ 821A545
	walk_in_place_fastest_right
	step_end

LilycoveCity_ContestLobby_Movement_LinkArtistBeginExit: @ 821A547
	walk_down
	walk_down
	walk_down
	step_end

LilycoveCity_ContestLobby_Movement_LinkArtistReturnToPlayer: @ 821A54B
	delay_16
	delay_16
	delay_16
	delay_16
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_in_place_fastest_left
	step_end

@ EventScript_SpeakToContestReceptionist either ends or returns after a contest entry is submitted
LilycoveCity_ContestLobby_EventScript_ContestReceptionist:: @ 821A554
	special ClearLinkContestFlags
	specialvar VAR_RESULT, IsContestDebugActive  @ Always FALSE
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_ContestLobby_EventScript_SetDebug
	call LilycoveCity_ContestLobby_EventScript_SpeakToContestReceptionist
	call LilycoveCity_ContestLobby_EventScript_LeadToContestHall
	special SetContestTrainerGfxIds
	call LilycoveCity_ContestLobby_EventScript_SetPlayerGfx
	call LilycoveCity_ContestLobby_EventScript_SetContestType
	call LilycoveCity_ContestLobby_EventScript_WarpToContestHall
	waitstate
	end

LilycoveCity_ContestLobby_EventScript_SetContestType:: @ 821A585
	switch VAR_CONTEST_RANK
	case CONTEST_RANK_NORMAL, LilycoveCity_ContestLobby_EventScript_SetNormalContestType
	case CONTEST_RANK_SUPER, LilycoveCity_ContestLobby_EventScript_SetSuperContestType
	case CONTEST_RANK_HYPER, LilycoveCity_ContestLobby_EventScript_SetHyperContestType
	case CONTEST_RANK_MASTER, LilycoveCity_ContestLobby_EventScript_SetMasterContestType
	return

LilycoveCity_ContestLobby_EventScript_SetNormalContestType:: @ 821A5B7
	setvar VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_NORMAL
	return

LilycoveCity_ContestLobby_EventScript_SetSuperContestType:: @ 821A5BD
	setvar VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_SUPER
	return

LilycoveCity_ContestLobby_EventScript_SetHyperContestType:: @ 821A5C3
	setvar VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_HYPER
	return

LilycoveCity_ContestLobby_EventScript_SetMasterContestType:: @ 821A5C9
	setvar VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_MASTER
	return

@ Functionally unused
LilycoveCity_ContestLobby_EventScript_SetDebug:: @ 821A5CF
	setflag FLAG_HIDE_LILYCOVE_MUSEUM_CURATOR
	copyvar VAR_LILYCOVE_MUSEUM_2F_STATE, 1
	additem ITEM_CONTEST_PASS
	setvar VAR_0x800B, 8
	setvar VAR_CONTEST_RANK, CONTEST_RANK_MASTER
	setvar VAR_LILYCOVE_CONTEST_LOBBY_STATE, 1
	setflag FLAG_SYS_RIBBON_GET
	end

LilycoveCity_ContestLobby_EventScript_WarpToContestHall:: @ 821A5EF
	setflag FLAG_ENTERED_CONTEST
	switch VAR_CONTEST_CATEGORY
	case CONTEST_CATEGORY_COOL, LilycoveCity_ContestLobby_EventScript_WarpToCoolContestHall
	case CONTEST_CATEGORY_BEAUTY, LilycoveCity_ContestLobby_EventScript_WarpToBeautyContestHall
	case CONTEST_CATEGORY_CUTE, LilycoveCity_ContestLobby_EventScript_WarpToCuteContestHall
	case CONTEST_CATEGORY_SMART, LilycoveCity_ContestLobby_EventScript_WarpToSmartContestHall
	case CONTEST_CATEGORY_TOUGH, LilycoveCity_ContestLobby_EventScript_WarpToToughContestHall
	return

LilycoveCity_ContestLobby_EventScript_WarpToCoolContestHall:: @ 821A62F
	setwarp MAP_CONTEST_HALL_COOL, 255, 7, 5
	special DoContestHallWarp
	waitstate
	return

LilycoveCity_ContestLobby_EventScript_WarpToBeautyContestHall:: @ 821A63C
	setwarp MAP_CONTEST_HALL_BEAUTY, 255, 7, 5
	special DoContestHallWarp
	waitstate
	return

LilycoveCity_ContestLobby_EventScript_WarpToCuteContestHall:: @ 821A649
	setwarp MAP_CONTEST_HALL_CUTE, 255, 7, 5
	special DoContestHallWarp
	waitstate
	return

LilycoveCity_ContestLobby_EventScript_WarpToSmartContestHall:: @ 821A656
	setwarp MAP_CONTEST_HALL_SMART, 255, 7, 5
	special DoContestHallWarp
	waitstate
	return

LilycoveCity_ContestLobby_EventScript_WarpToToughContestHall:: @ 821A663
	setwarp MAP_CONTEST_HALL_TOUGH, 255, 7, 5
	special DoContestHallWarp
	waitstate
	return

LilycoveCity_ContestLobby_EventScript_LeadToContestHall:: @ 821A670
	lockall
	applymovement LOCALID_RECEPTIONIST, LilycoveCity_ContestLobby_Movement_ReceptionistApproachCounter
	waitmovement 0
	playse SE_BRIDGE_WALK
	setmetatile 12, 2, METATILE_Contest_WallShadow, 1
	setmetatile 12, 3, METATILE_Contest_FloorShadow, 1
	special DrawWholeMapView
	applymovement LOCALID_RECEPTIONIST, LilycoveCity_ContestLobby_Movement_ReceptionistExitCounter
	waitmovement 0
	playse SE_BRIDGE_WALK
	setmetatile 12, 2, METATILE_Contest_CounterFlap_Top, 1
	setmetatile 12, 3, METATILE_Contest_CounterFlap_Bottom, 1
	special DrawWholeMapView
	delay 20
	applymovement LOCALID_RECEPTIONIST, LilycoveCity_ContestLobby_Movement_ReceptionistFacePlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_ContestLobby_Movement_PlayerApproachReceptionist
	waitmovement 0
	msgbox LilycoveCity_ContestLobby_Text_ComeThroughHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RECEPTIONIST, LilycoveCity_ContestLobby_Movement_ReceptionistWalkToContestHall
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_ContestLobby_Movement_PlayerWalkToContestHall
	waitmovement 0
	releaseall
	return

LilycoveCity_ContestLobby_Movement_PlayerWalkToContestHall: @ 821A6E8
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	delay_8
	set_invisible
	step_end

LilycoveCity_ContestLobby_Movement_PlayerApproachReceptionist: @ 821A6F2
	walk_in_place_fastest_left
	walk_left
	step_end

LilycoveCity_ContestLobby_Movement_ReceptionistApproachCounter: @ 821A6F5
	walk_left
	walk_left
	walk_in_place_fastest_down
	step_end

LilycoveCity_ContestLobby_Movement_ReceptionistExitCounter: @ 821A6F9
	walk_down
	walk_down
	walk_in_place_fastest_up
	step_end

LilycoveCity_ContestLobby_Movement_ReceptionistWalkToContestHall: @ 821A6FD
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	delay_8
	set_invisible
	step_end

LilycoveCity_ContestLobby_Movement_ReceptionistFacePlayer: @ 821A706
	walk_in_place_fastest_right
	step_end

LilycoveCity_ContestLobby_EventScript_BlackBelt:: @ 821A708
	msgbox LilycoveCity_ContestLobby_Text_MasterRankHereICome, MSGBOX_NPC
	end

LilycoveCity_ContestLobby_EventScript_Girl:: @ 821A711
	msgbox LilycoveCity_ContestLobby_Text_WholeVarietyOfPokemonHere, MSGBOX_NPC
	end

LilycoveCity_ContestLobby_EventScript_Artist:: @ 821A71A
	msgbox LilycoveCity_ContestLobby_Text_ContestFeastForEyes, MSGBOX_NPC
	end

LilycoveCity_ContestLobby_EventScript_FatMan:: @ 821A723
	msgbox LilycoveCity_ContestLobby_Text_ToughContestIsExtreme, MSGBOX_NPC
	end

LilycoveCity_ContestLobby_EventScript_Fisherman:: @ 821A72C
	msgbox LilycoveCity_ContestLobby_Text_LavishedCareOnMon, MSGBOX_NPC
	end

LilycoveCity_ContestLobby_EventScript_NinjaBoy:: @ 821A735
	msgbox LilycoveCity_ContestLobby_Text_MadePokeblocksWithFamily, MSGBOX_NPC
	end

LilycoveCity_ContestLobby_EventScript_ContestWinner1:: @ 821A73E
	lockall
	fadescreen FADE_TO_BLACK
	showcontestwinner CONTEST_WINNER_HALL_1
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_ContestWinner2:: @ 821A745
	lockall
	fadescreen FADE_TO_BLACK
	showcontestwinner CONTEST_WINNER_HALL_2
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_ContestWinner3:: @ 821A74C
	lockall
	fadescreen FADE_TO_BLACK
	showcontestwinner CONTEST_WINNER_HALL_3
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_ContestWinner4:: @ 821A753
	lockall
	fadescreen FADE_TO_BLACK
	showcontestwinner CONTEST_WINNER_HALL_4
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_ContestWinner5:: @ 821A75A
	lockall
	fadescreen FADE_TO_BLACK
	showcontestwinner CONTEST_WINNER_HALL_5
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_ContestWinner6:: @ 821A761
	lockall
	fadescreen FADE_TO_BLACK
	showcontestwinner CONTEST_WINNER_HALL_6
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_Blender3Boy:: @ 821A768
	msgbox BerryBlender_Text_LetsGetBlendingAlready, MSGBOX_NPC
	end

LilycoveCity_ContestLobby_EventScript_Blender3Girl:: @ 821A771
	msgbox BerryBlender_Text_WhatKindOfPokeblockWillIGet, MSGBOX_NPC
	end

LilycoveCity_ContestLobby_EventScript_BerryBlenderSpeedRecords:: @ 821A77A
	lockall
	special ShowBerryBlenderRecordWindow
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_LinkContestResults:: @ 821A784
	lockall
	frontier_results FACILITY_LINK_CONTEST
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_BlendMaster:: @ 821A798
	lock
	faceplayer
	msgbox BerryBlender_Text_BlendWithTheBlendMaster, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_FaceOriginalDirection
	end

LilycoveCity_ContestLobby_EventScript_BlendMasterOnlooker1:: @ 821A7A8
	lock
	msgbox BerryBlender_Text_WhoaAwesome, MSGBOX_DEFAULT
	release
	end

LilycoveCity_ContestLobby_EventScript_BlendMasterOnlooker2:: @ 821A7B3
	lock
	msgbox BerryBlender_Text_WickedlyFast, MSGBOX_DEFAULT
	release
	end

LilycoveCity_ContestLobby_EventScript_BlendMasterOnlooker3:: @ 821A7BE
	lock
	msgbox BerryBlender_Text_WhatAnExpert, MSGBOX_DEFAULT
	release
	end

LilycoveCity_ContestLobby_EventScript_BlendMasterOnlooker4:: @ 821A7C9
	lock
	faceplayer
	msgbox BerryBlender_Text_MadeAmazingPokeblocksWithMaster, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_FaceOriginalDirection
	end

LilycoveCity_ContestLobby_EventScript_BlendMasterOnlooker5:: @ 821A7D9
	lock
	faceplayer
	msgbox BerryBlender_Text_QualitiesOfBlendMaster, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_FaceOriginalDirection
	end

LilycoveCity_ContestLobby_EventScript_BlendMasterOnlooker6:: @ 821A7E9
	lock
	faceplayer
	msgbox BerryBlender_Text_MasterWorksOnSkillsInMountains, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_FaceOriginalDirection
	end

LilycoveCity_ContestLobby_EventScript_FaceOriginalDirection:: @ 821A7F9
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestLobby_EventScript_LinkContestReceptionist:: @ 821A806
	special ClearLinkContestFlags
	lock
	faceplayer
	msgbox LilycoveCity_ContestLobby_Text_LinkContestReception, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_AskEnterLinkContest
	end

LilycoveCity_ContestLobby_EventScript_AskEnterLinkContest:: @ 821A819
	message LilycoveCity_ContestLobby_Text_EnterContest3
	waitmessage
	multichoice 0, 0, MULTI_ENTERINFO, 0
	switch VAR_RESULT
	case 0, LilycoveCity_ContestLobby_EventScript_TryEnterLinkContest
	case 1, LilycoveCity_ContestLobby_EventScript_LinkContestInfo
	case 2, LilycoveCity_ContestLobby_EventScript_CancelLinkContest
	case MULTI_B_PRESSED, LilycoveCity_ContestLobby_EventScript_CancelLinkContest
	end

LilycoveCity_ContestLobby_EventScript_TryEnterLinkContest:: @ 821A856
	msgbox LilycoveCity_ContestLobby_Text_ProgressWillBeSaved, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LilycoveCity_ContestLobby_EventScript_CancelLinkContest
	call Common_EventScript_SaveGame
	compare VAR_RESULT, FALSE
	goto_if_eq LilycoveCity_ContestLobby_EventScript_CancelLinkContest
	message LilycoveCity_ContestLobby_Text_WhichContestMode
	waitmessage
	specialvar VAR_TEMP_D, IsWirelessAdapterConnected
	multichoice 0, 0, MULTI_LINK_CONTEST_MODE, 0
	switch VAR_RESULT
	case 0, LilycoveCity_ContestLobby_EventScript_EmeraldMode  @ Shortened to E-Mode
	case 1, LilycoveCity_ContestLobby_EventScript_GlobalMode   @ Shortened to G-Mode
	case 2, LilycoveCity_ContestLobby_EventScript_CancelLinkContest
	case MULTI_B_PRESSED, LilycoveCity_ContestLobby_EventScript_CancelLinkContest
	end

LilycoveCity_ContestLobby_EventScript_EmeraldMode:: @ 821A8BB
	setvar VAR_TEMP_C, 0
	goto LilycoveCity_ContestLobby_EventScript_ChooseLinkContestType
	end

LilycoveCity_ContestLobby_EventScript_GlobalMode:: @ 821A8C6
	setvar VAR_TEMP_C, 1
	compare VAR_TEMP_D, 1
	goto_if_eq LilycoveCity_ContestLobby_EventScript_CancelLinkNoWirelessGMode
	goto LilycoveCity_ContestLobby_EventScript_ChooseLinkContestType
	end

LilycoveCity_ContestLobby_EventScript_ChooseLinkContestType:: @ 821A8DC
	message LilycoveCity_ContestLobby_Text_EnterWhichContest3
	waitmessage
	multichoice 0, 0, MULTI_CONTEST_TYPE, 0
	switch VAR_RESULT
	case CONTEST_CATEGORIES_COUNT, LilycoveCity_ContestLobby_EventScript_CancelLinkContest
	case MULTI_B_PRESSED, LilycoveCity_ContestLobby_EventScript_CancelLinkContest
	copyvar VAR_CONTEST_CATEGORY, VAR_RESULT
	goto LilycoveCity_ContestLobby_EventScript_ChooseLinkContestMon
	end

LilycoveCity_ContestLobby_EventScript_LinkContestInfo:: @ 821A90D
	message LilycoveCity_ContestLobby_Text_WhichTopic2
	waitmessage
	multichoice 0, 0, MULTI_LINK_CONTEST_INFO, 0
	switch VAR_RESULT
	case 0, LilycoveCity_ContestLobby_EventScript_ExplainLinkContest
	case 1, LilycoveCity_ContestLobby_EventScript_ExplainEMode
	case 2, LilycoveCity_ContestLobby_EventScript_ExplainGMode
	case 3, LilycoveCity_ContestLobby_EventScript_AskEnterLinkContest
	case MULTI_B_PRESSED, LilycoveCity_ContestLobby_EventScript_AskEnterLinkContest
	end

LilycoveCity_ContestLobby_EventScript_ExplainLinkContest:: @ 821A955
	msgbox LilycoveCity_ContestLobby_Text_ExplainLinkContest, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_LinkContestInfo
	end

LilycoveCity_ContestLobby_EventScript_ExplainEMode:: @ 821A963
	msgbox LilycoveCity_ContestLobby_Text_ExplainEMode, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_LinkContestInfo
	end

LilycoveCity_ContestLobby_EventScript_ExplainGMode:: @ 821A971
	msgbox LilycoveCity_ContestLobby_Text_ExplainGMode, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_LinkContestInfo
	end

LilycoveCity_ContestLobby_EventScript_CancelLinkContest:: @ 821A97F
	special CloseLink
	msgbox LilycoveCity_ContestLobby_Text_ParticipateAnotherTime, MSGBOX_DEFAULT
	release
	end

LilycoveCity_ContestLobby_EventScript_ChooseLinkContestMon:: @ 821A98C
	msgbox LilycoveCity_ContestLobby_Text_EnterWhichPokemon3, MSGBOX_DEFAULT
	setvar VAR_CONTEST_RANK, 0
	choosecontestmon
	compare VAR_0x8004, 255
	goto_if_eq LilycoveCity_ContestLobby_EventScript_CancelLinkContest
	special TryEnterContestMon
	compare VAR_RESULT, CANT_ENTER_CONTEST
	goto_if_eq LilycoveCity_ContestLobby_EventScript_LinkCantEnterLowRank
	compare VAR_RESULT, CAN_ENTER_CONTEST_EQUAL_RANK
	goto_if_eq LilycoveCity_ContestLobby_EventScript_EnterMonForLinkContest
	compare VAR_RESULT, CAN_ENTER_CONTEST_HIGH_RANK
	goto_if_eq LilycoveCity_ContestLobby_EventScript_EnterMonForLinkContest
	compare VAR_RESULT, CANT_ENTER_CONTEST_EGG
	goto_if_eq LilycoveCity_ContestLobby_EventScript_LinkCantEnterEgg
	compare VAR_RESULT, CANT_ENTER_CONTEST_FAINTED
	goto_if_eq LilycoveCity_ContestLobby_EventScript_LinkCantEnterFainted
	end

LilycoveCity_ContestLobby_EventScript_LinkCantEnterLowRank:: @ 821A9E0
	msgbox LilycoveCity_ContestLobby_Text_MonNotQualifiedForRank, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_ChooseLinkContestMon
	end

LilycoveCity_ContestLobby_EventScript_LinkCantEnterEgg:: @ 821A9EE
	msgbox LilycoveCity_ContestLobby_Text_EggCannotTakePart2, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_ChooseLinkContestMon
	end

LilycoveCity_ContestLobby_EventScript_LinkCantEnterFainted:: @ 821A9FC
	msgbox LilycoveCity_ContestLobby_Text_MonInNoCondition2, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_ChooseLinkContestMon
	end

LilycoveCity_ContestLobby_EventScript_EnterMonForLinkContest:: @ 821AA0A
	copyvar VAR_0x8008, VAR_0x8004
	goto LilycoveCity_ContestLobby_EventScript_TrySetUpLinkContest
	end

LilycoveCity_ContestLobby_EventScript_TrySetUpLinkContest:: @ 821AA15
	compare VAR_TEMP_D, 1
	goto_if_eq LilycoveCity_ContestLobby_EventScript_SetLinkGroupType
	compare VAR_TEMP_D, 2
	goto_if_ge LilycoveCity_ContestLobby_EventScript_CancelLinkContest
	message LilycoveCity_ContestLobby_Text_PleaseWaitBButtonCancel
	waitmessage
	copyvar VAR_0x8004, VAR_RESULT
	compare VAR_TEMP_C, 0
	call_if_eq LilycoveCity_ContestLobby_EventScript_TryLinkEMode
	compare VAR_TEMP_C, 1
	call_if_eq LilycoveCity_ContestLobby_EventScript_TryLinkGMode
	compare VAR_TEMP_C, 2
	goto_if_ge LilycoveCity_ContestLobby_EventScript_CancelLinkContest
	compare VAR_RESULT, LINKUP_WRONG_NUM_PLAYERS
	goto_if_eq LilycoveCity_ContestLobby_EventScript_CancelLinkDifferentChoices
	compare VAR_RESULT, LINKUP_DIFF_SELECTIONS
	goto_if_eq LilycoveCity_ContestLobby_EventScript_CancelLinkDifferentChoices
	compare VAR_RESULT, LINKUP_FAILED
	goto_if_eq LilycoveCity_ContestLobby_EventScript_CancelLinkContest
	compare VAR_RESULT, LINKUP_CONNECTION_ERROR
	goto_if_eq LilycoveCity_ContestLobby_EventScript_CancelLinkError
	compare VAR_RESULT, LINKUP_FAILED_CONTEST_GMODE
	goto_if_eq LilycoveCity_ContestLobby_EventScript_CancelLinkModeDifference
	message3 LilycoveCity_ContestLobby_Text_Transmitting
	contestlinktransfer
	switch VAR_0x8004
	case 0, LilycoveCity_ContestLobby_EventScript_StartLinkContest
	case 1, LilycoveCity_ContestLobby_EventScript_CancelLinkDifferentContest
	case 2, LilycoveCity_ContestLobby_EventScript_CancelLinkTransmissionError
	end

LilycoveCity_ContestLobby_EventScript_TryLinkEMode:: @ 821AABB
	special TryContestEModeLinkup
	waitstate
	return

LilycoveCity_ContestLobby_EventScript_TryLinkGMode:: @ 821AAC0
	special TryContestGModeLinkup
	waitstate
	return

LilycoveCity_ContestLobby_EventScript_CancelLinkDifferentContest:: @ 821AAC5
	msgbox LilycoveCity_ContestLobby_Text_PlayersChoseDifferentContest, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_CancelLinkContest
	end

LilycoveCity_ContestLobby_EventScript_CancelLinkDifferentChoices:: @ 821AAD3
	msgbox LilycoveCity_ContestLobby_Text_PlayersMadeDifferentChoice, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_CancelLinkContest
	end

LilycoveCity_ContestLobby_EventScript_CancelLinkModeDifference:: @ 821AAE1
	msgbox LilycoveCity_ContestLobby_Text_PlayerAt4PCounterUseGMode, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_CancelLinkContest
	end

LilycoveCity_ContestLobby_EventScript_CancelLinkError:: @ 821AAEF
	special CloseLink
	msgbox Text_LinkErrorPleaseReset, MSGBOX_DEFAULT
	release
	end

LilycoveCity_ContestLobby_EventScript_CancelLinkNoWirelessGMode:: @ 821AAFC
	special CloseLink
	msgbox LilycoveCity_ContestLobby_Text_NoWirelessAdapterInGMode, MSGBOX_DEFAULT
	release
	end

LilycoveCity_ContestLobby_EventScript_CancelLinkTransmissionError:: @ 821AB09
	msgbox LilycoveCity_ContestLobby_Text_TransmissionError, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_CancelLinkContest
	end

LilycoveCity_ContestLobby_EventScript_StartLinkContest:: @ 821AB17
	special GetContestPlayerId
	addvar VAR_0x8004, 1
	buffernumberstring 1, VAR_0x8004
	messageautoscroll LilycoveCity_ContestLobby_Text_YourMonIsEntryNumX
	waitmessage
	subvar VAR_0x8004, 1
	call LilycoveCity_ContestLobby_EventScript_LeadToLinkContestHall
	setvar VAR_CONTEST_HALL_STATE, 1
	special SetLinkContestPlayerGfx
	setvar VAR_CONTEST_TYPE, CONTEST_TYPE_LINK
	setvar VAR_CONTEST_RANK, CONTEST_RANK_MASTER
	call LilycoveCity_ContestLobby_EventScript_WarpToContestHall
	end

LilycoveCity_ContestLobby_EventScript_SetLinkGroupType:: @ 821AB4B
	compare VAR_CONTEST_CATEGORY, CONTEST_CATEGORY_COOL
	call_if_eq LilycoveCity_ContestLobby_EventScript_SetLinkGroupCoolContest
	compare VAR_CONTEST_CATEGORY, CONTEST_CATEGORY_BEAUTY
	call_if_eq LilycoveCity_ContestLobby_EventScript_SetLinkGroupBeautyContest
	compare VAR_CONTEST_CATEGORY, CONTEST_CATEGORY_CUTE
	call_if_eq LilycoveCity_ContestLobby_EventScript_SetLinkGroupCuteContest
	compare VAR_CONTEST_CATEGORY, CONTEST_CATEGORY_SMART
	call_if_eq LilycoveCity_ContestLobby_EventScript_SetLinkGroupSmartContest
	compare VAR_CONTEST_CATEGORY, CONTEST_CATEGORY_TOUGH
	call_if_eq LilycoveCity_ContestLobby_EventScript_SetLinkGroupToughContest
	goto LilycoveCity_ContestLobby_EventScript_DecideLinkLeader
	end

LilycoveCity_ContestLobby_EventScript_SetLinkGroupCoolContest:: @ 821AB88
	setvar VAR_0x8004, LINK_GROUP_COOL_CONTEST
	return

LilycoveCity_ContestLobby_EventScript_SetLinkGroupBeautyContest:: @ 821AB8E
	setvar VAR_0x8004, LINK_GROUP_BEAUTY_CONTEST
	return

LilycoveCity_ContestLobby_EventScript_SetLinkGroupCuteContest:: @ 821AB94
	setvar VAR_0x8004, LINK_GROUP_CUTE_CONTEST
	return

LilycoveCity_ContestLobby_EventScript_SetLinkGroupSmartContest:: @ 821AB9A
	setvar VAR_0x8004, LINK_GROUP_SMART_CONTEST
	return

LilycoveCity_ContestLobby_EventScript_SetLinkGroupToughContest:: @ 821ABA0
	setvar VAR_0x8004, LINK_GROUP_TOUGH_CONTEST
	return

LilycoveCity_ContestLobby_EventScript_DecideLinkLeader:: @ 821ABA6
	message LilycoveCity_ContestLobby_Text_PleaseDecideLinkLeader
	waitmessage
	multichoice 16, 6, MULTI_LINK_LEADER, 0
	switch VAR_RESULT
	case 0, LilycoveCity_ContestLobby_EventScript_TryJoinGroup
	case 1, LilycoveCity_ContestLobby_EventScript_TryLeadGroup
	case 2, LilycoveCity_ContestLobby_EventScript_CancelLinkContest
	case MULTI_B_PRESSED, LilycoveCity_ContestLobby_EventScript_CancelLinkContest
	end

LilycoveCity_ContestLobby_EventScript_TryLeadGroup:: @ 821ABE3
	call LilycoveCity_ContestLobby_EventScript_TryBecomeLinkLeader
	compare VAR_RESULT, LINKUP_SUCCESS
	goto_if_eq LilycoveCity_ContestLobby_EventScript_LinkLeaderDecided
	compare VAR_RESULT, LINKUP_FAILED
	goto_if_eq LilycoveCity_ContestLobby_EventScript_DecideLinkLeader
	compare VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN
	goto_if_eq LilycoveCity_ContestLobby_EventScript_TryLeadGroup
	release
	end

LilycoveCity_ContestLobby_EventScript_TryJoinGroup:: @ 821AC0B
	call LilycoveCity_ContestLobby_EventScript_TryJoinLinkGroup
	compare VAR_RESULT, LINKUP_SUCCESS
	goto_if_eq LilycoveCity_ContestLobby_EventScript_LinkLeaderDecided
	compare VAR_RESULT, LINKUP_FAILED
	goto_if_eq LilycoveCity_ContestLobby_EventScript_DecideLinkLeader
	compare VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN
	goto_if_eq LilycoveCity_ContestLobby_EventScript_TryJoinGroup
	release
	end

LilycoveCity_ContestLobby_EventScript_TryBecomeLinkLeader:: @ 821AC33
	special TryBecomeLinkLeader
	waitstate
	return

LilycoveCity_ContestLobby_EventScript_TryJoinLinkGroup:: @ 821AC38
	special TryJoinLinkGroup
	waitstate
	return

LilycoveCity_ContestLobby_EventScript_LinkLeaderDecided:: @ 821AC3D
	message3 LilycoveCity_ContestLobby_Text_Transmitting
	contestlinktransfer
	goto LilycoveCity_ContestLobby_EventScript_StartLinkContest
	end

LilycoveCity_ContestLobby_EventScript_LeadToLinkContestHall:: @ 821AC49
	messageautoscroll LilycoveCity_ContestLobby_Text_ContestBeginShortly
	waitmessage
	delay 20
	closemessage
	applymovement LOCALID_LINK_RECEPTIONIST, LilycoveCity_ContestLobby_Movement_LinkReceptionistApproachCounter
	waitmovement 0
	playse SE_BRIDGE_WALK
	setmetatile 17, 2, METATILE_Contest_WallShadow, 1
	setmetatile 17, 3, METATILE_Contest_FloorShadow, 1
	special DrawWholeMapView
	applymovement LOCALID_LINK_RECEPTIONIST, LilycoveCity_ContestLobby_Movement_LinkReceptionistExitCounter
	waitmovement 0
	playse SE_BRIDGE_WALK
	setmetatile 17, 2, METATILE_Contest_CounterFlap_Top, 1
	setmetatile 17, 3, METATILE_Contest_CounterFlap_Bottom, 1
	special DrawWholeMapView
	delay 20
	applymovement LOCALID_LINK_RECEPTIONIST, LilycoveCity_ContestLobby_Movement_LinkReceptionistFacePlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_ContestLobby_Movement_PlayerApproachLinkReceptionist
	waitmovement 0
	messageautoscroll LilycoveCity_ContestLobby_Text_ComeThroughHere
	waitmessage
	delay 20
	closemessage
	call LilycoveCity_ContestLobby_EventScript_DelayIfContestWithRSPlayer
	applymovement LOCALID_LINK_RECEPTIONIST, LilycoveCity_ContestLobby_Movement_LinkReceptionistWalkToContestHall
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_ContestLobby_Movement_PlayerWalkToLinkContestHall
	waitmovement 0
	release
	return

LilycoveCity_ContestLobby_Movement_PlayerWalkToLinkContestHall: @ 821ACD0
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	delay_8
	set_invisible
	step_end

LilycoveCity_ContestLobby_Movement_PlayerApproachLinkReceptionist: @ 821ACDB
	walk_right
	step_end

LilycoveCity_ContestLobby_Movement_LinkReceptionistApproachCounter: @ 821ACDD
	walk_right
	walk_right
	walk_in_place_fastest_down
	step_end

LilycoveCity_ContestLobby_Movement_LinkReceptionistExitCounter: @ 821ACE1
	walk_down
	walk_down
	walk_in_place_fastest_up
	step_end

LilycoveCity_ContestLobby_Movement_LinkReceptionistWalkToContestHall: @ 821ACE5
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	delay_8
	set_invisible
	step_end

LilycoveCity_ContestLobby_Movement_LinkReceptionistFacePlayer: @ 821ACEF
	walk_in_place_fastest_left
	step_end

LilycoveCity_ContestLobby_EventScript_LittleGirl:: @ 821ACF1
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POKEBLOCK_CASE, LilycoveCity_ContestLobby_EventScript_LittleGirlHaveCase
	msgbox LilycoveCity_ContestLobby_Text_LadyGaveMePokeblockCase, MSGBOX_DEFAULT
	release
	end

LilycoveCity_ContestLobby_EventScript_LittleGirlHaveCase:: @ 821AD06
	msgbox LilycoveCity_ContestLobby_Text_MakePokeblocksDifferentBerries, MSGBOX_DEFAULT
	release
	end

LilycoveCity_ContestLobby_Text_LadyGaveMePokeblockCase: @ 821AD10
	.string "우와-!\p"
	.string "접수원 언니한테서\n"
	.string "포켓몬스넥 넣는 케이스 받았다!$"
	@ うわ-い!ｐ
	@ うけつけの おねえちゃんからｎ
	@ ポロック いれる ケ-ス もらった!

LilycoveCity_ContestLobby_Text_MakePokeblocksDifferentBerries: @ 821AD55
	.string "포켓몬스넥케이스에\n"
	.string "포켓몬스넥을 만들고 넣어!\p"
	.string "근데 포켓몬스넥을 만들 때는\n"
	.string "모두 다른 나무열매로\l"
	.string "만들지 않으면 안 돼!$"
	@ ポロック つくって いれて!ｐ
	@ でね ポロック つくる ときはｎ
	@ みんなが ちがう きのみでｌ
	@ つくらないと ダメ なんだよ!

LilycoveCity_ContestLobby_Text_YourPokemonSpurredMeToPaint: @ 821ADB9
	.string "우승 축하해!\p"
	.string "서둘러서 기념으로\n"
	.string "네 포켓몬의 그림을\l"
	.string "그려 봤는데...\p"
	.string "뭔가 네 포켓몬 어필이\n"
	.string "정말 굉장해서\l"
	.string "평소보다 잘 그렸어!\l"
	.string "자 이거!$"
	@ ゆうしょう おめでとう!ｐ
	@ さっそく きねんにｎ
	@ きみの ポケモンの えをｌ
	@ かきあげたんだけど……ｐ
	@ なんだか きみの ポケモンの アピ-ルがｎ
	@ あまり にも すばらしくてｌ
	@ いつもより うまく かけたんだ!ｌ
	@ ほらっ これ!

LilycoveCity_ContestLobby_Text_ShouldITakePaintingToMuseum: @ 821AE78
	.string "어때? 자신 있는 작품인데\n"
	.string "마음에 들지?\p"
	.string "이 정도 완성도라면\n"
	.string "미술관에 장식되어 있어도\l"
	.string "이상하지 않겠는걸!\p"
	.string "...엇 정말로 미술관에서\n"
	.string "그림을 찾아보고 있다고?\l"
	.string "그럼 이거 가져가 볼까?$"
	@ どうかな? じしんさく なんだけどｎ
	@ きにいったろ?ｐ
	@ これくらいの でき ならｎ
	@ びじゅつかんに かざられて いてもｌ
	@ ふしぎじゃ ないね!ｐ
	@ ……え ほんとに びじゅつかんでｎ
	@ えを さがして いるって?ｌ
	@ じゃあ これ もっていって みようかな?

LilycoveCity_ContestLobby_Text_IllTakePaintingToMuseum: @ 821AF63
	.string "그 그래!\n"
	.string "그럼 지금 바로 가져가볼게\l"
	.string "제목도 붙여둘 테니까!\p"
	.string "이게 마음에 들어서\n"
	.string "장식될지 어떨지\l"
	.string "너도 다음에 보러 와줘!\l"
	.string "그럼 고마워!$"
	@ そ そうか!ｎ
	@ じゃ いますぐ もっていって みるよｌ
	@ タイトルも つけて おくからね!ｐ
	@ これが きにいられてｎ
	@ かざって もらえて いるか どうかｌ
	@ きみも こんど みに いってね!ｌ
	@ じゃ ありがとう!

LilycoveCity_ContestLobby_Text_TakeMementoOfPainting: @ 821B030
	.string "...아 맞다\p"
	.string "포켓몬을 그리게 해준 기념으로\n"
	.string "이걸 받아줘!$"
	@ ……あ そうだｐ
	@ ポケモンを かかせて もらった きねんにｎ
	@ これを うけとってよ!

LilycoveCity_ContestLobby_Text_ReceivedARibbon: @ 821B07E
	.string "{PLAYER}{K_EUNNEUN} 리본을 받았다!$"
	@ §あは リボンを もらった!

LilycoveCity_ContestLobby_Text_PutTheRibbonOnMon: @ 821B094
	.string "{PLAYER}{K_EUNNEUN} 리본을\n"
	.string "{STR_VAR_1}에게 달아 줬다!$"
	@ §あは リボンをｎ
	@ §いに つけて あげた!

LilycoveCity_ContestLobby_Text_OkaySeeYou: @ 821B0AD
	.string "그럼 이만!$"
	@ それじゃね!

LilycoveCity_ContestLobby_Text_TakeHomeButIdLikeToTakeToMuseum: @ 821B0BC
	.string "으-음... 그럼 이건\n"
	.string "내가 가지고 돌아갈까...\p"
	.string "하지만 역시 가져가고 싶은데...\n"
	.string "어떻게 생각해?$"
	@ う-ん…… じゃあ これはｎ
	@ ぼくが もってかえると するか……ｐ
	@ でも やっぱり もっていきたいな……ｎ
	@ いいだろ?

LilycoveCity_ContestLobby_Text_FineThatsTheWayItIs: @ 821B132
	.string "그렇구나 어쩔 수 없지\n"
	.string "그럼 이건\l"
	.string "내 집에 장식할게\p"
	.string "다음에 열심히 해야겠다...\n"
	.string "그럼 안녕$"
	@ そっか しかたないねｎ
	@ それじゃ これは ぼくのｌ
	@ いえに かざりますｐ
	@ つぎ がんばると するか……ｎ
	@ じゃあな

LilycoveCity_ContestLobby_Text_MasterRankHereICome: @ 821B1B1
	.string "드 드디어\n"
	.string "마스터랭크에 나간다...\p"
	.string "내 포켓몬이\n"
	.string "이 세상에서 가장\l"
	.string "귀엽다는 걸\l"
	.string "증명할 때가 온 거야...\l"
	.string "우헤헤헤헤$"
	@ いっ いよいよｎ
	@ マスタ-ランクに でるぞ……ｐ
	@ おれの ポケモンちゃんがｎ
	@ このよで いちばんｌ
	@ かわいいって ことをｌ
	@ しょうめいする ときが きたんだ……ｌ
	@ うへへへへ

LilycoveCity_ContestLobby_Text_WholeVarietyOfPokemonHere: @ 821B24D
	.string "여기에 오면\n"
	.string "포켓몬을 잔뜩 볼 수 있으니까\l"
	.string "산책코스로 다니고 있어!$"
	@ ここに くればｎ
	@ ポケモンを たくさん みられるからｌ
	@ さんぽコ-スに してるの!

LilycoveCity_ContestLobby_Text_ContestFeastForEyes: @ 821B2BA
	.string "이야 콘테스트회장에 오면\n"
	.string "그릴 만한 포켓몬이\l"
	.string "잔뜩 있구만!$"
	@ いやあ コンテストかいじょうに くるとｎ
	@ かきがいの ある ポケモンがｌ
	@ いっぱい だね!

LilycoveCity_ContestLobby_Text_ToughContestIsExtreme: @ 821B334
	.string "강인함콘테스트는\n"
	.string "최고로군!\p"
	.string "힘센 어필...\n"
	.string "샘솟는 땀... 못 참겠어!$"
	@ たくましさコンテストってｎ
	@ さいこう だよな!ｐ
	@ ちからづよい アピ-ル……ｎ
	@ ほとばしる あせ…… たまらん!

LilycoveCity_ContestLobby_Text_LavishedCareOnMon: @ 821B392
	.string "매일 소중히 소중히\n"
	.string "키워온 내 포켓몬\l"
	.string "컨디션은 완벽!\l"
	.string "오늘은 이긴다아아아아아아아!$"
	@ まいにち だいじに だいじにｎ
	@ そだてあげた わしの ポケモンｌ
	@ コンディションは カンペキ!ｌ
	@ きょうは かつぞおおおおおうう!

LilycoveCity_ContestLobby_Text_MadePokeblocksWithFamily: @ 821B3FC
	.string "엄마하고 아빠하고 누나하고\n"
	.string "4명이서 포켓몬스넥을 만들었더니\l"
	.string "엄청 좋게 나왔어!\p"
	.string "분명 여럿이서 만들면 만들수록\n"
	.string "부드럽고 좋은 포켓몬스넥이 나오는 걸 거야!$"
	@ ママと パパと おねえちゃんとｎ
	@ 4にんで ポロックを つくったらｌ
	@ すごく いいやつが できたんだ!ｐ
	@ きっと おおぜいで つくれば つくるほどｎ
	@ なめらかで いい ポロックが できるんだよ!

