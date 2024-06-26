SecretBase_Text_TreeCanBeClimbed: @ 8274746
	.string "덩굴이 떨어진다면 위로\n"
	.string "올라갈 수 있을 것 같다$"

SecretBase_Text_TreeUseSecretPower: @ 8274779
	.string "덩굴이 떨어진다면 위로\n"
	.string "올라갈 수 있을 것 같다\p"
	.string "비밀의힘을 사용하겠습니까?$"

SecretBase_Text_VineDroppedDown: @ 82747C2
	.string "굵은 덩굴이 내려왔다!$"

SecretBase_Text_ClumpOfGrass: @ 82747DD
	.string "풀 덩어리를 치운다면\n"
	.string "안으로 들어갈 수 있을 것 같다$"

SecretBase_Text_ClumpUseSecretPower: @ 8274825
	.string "풀 덩어리를 치운다면\n"
	.string "안으로 들어갈 수 있을 것 같다\p"
	.string "비밀의힘을 사용하겠습니까?$"

SecretBase_Text_DiscoveredSmallEntrance: @ 8274883
	.string "작은 입구를 발견!$"

	.include "data/text/secret_base_trainers.inc"

SecretBase_EventScript_CheckEntrance:: @ 82759F1
	special GetSecretBaseTypeInFrontOfPlayer
	special CheckPlayerHasSecretBase
	compare VAR_RESULT, TRUE
	goto_if_eq SecretBase_EventScript_AlreadyHasSecretBase
	checkpartymove MOVE_SECRET_POWER
	setfieldeffectargument 0, VAR_RESULT
	buffermovename 1, MOVE_SECRET_POWER
	compare VAR_0x8007, SECRET_BASE_RED_CAVE
	goto_if_eq SecretBase_EventScript_Cave
	compare VAR_0x8007, SECRET_BASE_BROWN_CAVE
	goto_if_eq SecretBase_EventScript_Cave
	compare VAR_0x8007, SECRET_BASE_BLUE_CAVE
	goto_if_eq SecretBase_EventScript_Cave
	compare VAR_0x8007, SECRET_BASE_YELLOW_CAVE
	goto_if_eq SecretBase_EventScript_Cave
	compare VAR_0x8007, SECRET_BASE_TREE
	goto_if_eq SecretBase_EventScript_Tree
	compare VAR_0x8007, SECRET_BASE_SHRUB
	goto_if_eq SecretBase_EventScript_Shrub
	end

SecretBase_EventScript_Cave:: @ 8275A50
	lockall
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq SecretBase_EventScript_CaveNoSecretPower
	bufferpartymonnick 0, VAR_RESULT
	msgbox SecretBase_Text_IndentUseSecretPower, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SecretBase_EventScript_CancelOnEntrance
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
	dofieldeffect FLDEFF_USE_SECRET_POWER_CAVE
	waitstate
	goto SecretBase_EventScript_CaveEnter
	end

SecretBase_EventScript_CaveUseSecretPower:: @ 8275A86
	lockall
	dofieldeffect FLDEFF_USE_SECRET_POWER_CAVE
	waitstate
	goto SecretBase_EventScript_CaveEnter
	end

SecretBase_EventScript_CaveNoSecretPower:: @ 8275A91
	msgbox SecretBase_Text_SmallIndentInWall, MSGBOX_DEFAULT
	releaseall
	end

SecretBase_EventScript_CaveEnter:: @ 8275A9B
	msgbox SecretBase_Text_DiscoveredSmallCavern, MSGBOX_DEFAULT
	goto SecretBase_EventScript_InitSecretBase
	end

SecretBase_EventScript_Tree:: @ 8275AA9
	lockall
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq SecretBase_EventScript_TreeNoSecretPower
	bufferpartymonnick 0, VAR_RESULT
	msgbox SecretBase_Text_TreeUseSecretPower, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SecretBase_EventScript_CancelOnEntrance
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
	dofieldeffect FLDEFF_USE_SECRET_POWER_TREE
	waitstate
	goto SecretBase_EventScript_TreeEnter
	end

SecretBase_EventScript_TreeUseSecretPower:: @ 8275ADF
	lockall
	dofieldeffect FLDEFF_USE_SECRET_POWER_TREE
	waitstate
	goto SecretBase_EventScript_TreeEnter
	end

SecretBase_EventScript_TreeNoSecretPower:: @ 8275AEA
	msgbox SecretBase_Text_TreeCanBeClimbed, MSGBOX_DEFAULT
	releaseall
	end

SecretBase_EventScript_TreeEnter:: @ 8275AF4
	msgbox SecretBase_Text_VineDroppedDown, MSGBOX_DEFAULT
	goto SecretBase_EventScript_InitSecretBase
	end

SecretBase_EventScript_Shrub:: @ 8275B02
	lockall
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq SecretBase_EventScript_ShrubNoSecretPower
	bufferpartymonnick 0, VAR_RESULT
	msgbox SecretBase_Text_ClumpUseSecretPower, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SecretBase_EventScript_CancelOnEntrance
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
	dofieldeffect FLDEFF_USE_SECRET_POWER_SHRUB
	waitstate
	goto SecretBase_EventScript_ShrubEnter
	end

SecretBase_EventScript_ShrubUseSecretPower:: @ 8275B38
	lockall
	dofieldeffect FLDEFF_USE_SECRET_POWER_SHRUB
	waitstate
	goto SecretBase_EventScript_ShrubEnter
	end

SecretBase_EventScript_ShrubNoSecretPower:: @ 8275B43
	msgbox SecretBase_Text_ClumpOfGrass, MSGBOX_DEFAULT
	releaseall
	end

SecretBase_EventScript_ShrubEnter:: @ 8275B4D
	msgbox SecretBase_Text_DiscoveredSmallEntrance, MSGBOX_DEFAULT
	goto SecretBase_EventScript_InitSecretBase
	end

SecretBase_EventScript_InitSecretBase:: @ 8275B5B
	closemessage
	playse SE_EXIT
	setvar VAR_INIT_SECRET_BASE, 0
	setflag FLAG_DECORATION_0
	special SetPlayerSecretBase
	special EnterSecretBase
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 0
	special InitSecretBaseDecorationSprites
	setvar VAR_SECRET_BASE_INITIALIZED, 1
	waitstate
	end

SecretBase_EventScript_FirstEntrance:: @ 8275B81
	applymovement OBJ_EVENT_ID_PLAYER, SecretBase_Movement_275BB4
	waitmovement 0
	setvar VAR_INIT_SECRET_BASE, 1
	msgbox SecretBase_Text_WantToMakeYourSecretBaseHere, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq SecretBase_EventScript_SetAsBase
	closemessage
	playse SE_EXIT
	special ClearAndLeaveSecretBase
	end

SecretBase_EventScript_SetAsBase:: @ 8275BAB
	closemessage
	setflag FLAG_RECEIVED_SECRET_POWER
	special EnterNewlyCreatedSecretBase
	waitstate
	end

SecretBase_Movement_275BB4: @ 8275BB4
	walk_up
	walk_up
	step_end

SecretBase_EventScript_Enter:: @ 8275BB7
	lockall
	setvar VAR_INIT_SECRET_BASE, 1
	playse SE_EXIT
	special IsCurSecretBaseOwnedByAnotherPlayer
	compare VAR_RESULT, FALSE
	goto_if_eq SecretBase_EventScript_EnterPlayersBase
	clearflag FLAG_DECORATION_0
	special EnterSecretBase
	setvar VAR_SECRET_BASE_INITIALIZED, 0
	waitstate
	end

SecretBase_EventScript_EnterPlayersBase:: @ 8275BDB
	setflag FLAG_DECORATION_0
	special EnterSecretBase
	setvar VAR_SECRET_BASE_INITIALIZED, 0
	waitstate
	end

SecretBase_EventScript_AlreadyHasSecretBase:: @ 8275BE8
	checkpartymove MOVE_SECRET_POWER
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq SecretBase_EventScript_NoSecretPower
	setfieldeffectargument 0, VAR_RESULT
	setorcopyvar VAR_0x8004, VAR_RESULT
	lockall
	special GetSecretBaseNearbyMapName
	msgbox SecretBase_Text_WouldYouLikeToMoveBases, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SecretBase_EventScript_CancelOnEntrance
	msgbox SecretBase_Text_AllDecorationsWillBeReturned, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SecretBase_EventScript_CancelOnEntrance
	fadescreenswapbuffers FADE_TO_BLACK
	special MoveOutOfSecretBaseFromOutside
	closemessage
	fadescreenswapbuffers FADE_FROM_BLACK
	msgbox SecretBase_Text_MovingCompletedUseSecretPower, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SecretBase_EventScript_CancelOnEntrance
	bufferpartymonnick 0, VAR_0x8004
	buffermovename 1, MOVE_SECRET_POWER
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
	closemessage
	compare VAR_0x8007, SECRET_BASE_RED_CAVE
	goto_if_eq SecretBase_EventScript_CaveUseSecretPower
	compare VAR_0x8007, SECRET_BASE_BROWN_CAVE
	goto_if_eq SecretBase_EventScript_CaveUseSecretPower
	compare VAR_0x8007, SECRET_BASE_BLUE_CAVE
	goto_if_eq SecretBase_EventScript_CaveUseSecretPower
	compare VAR_0x8007, SECRET_BASE_YELLOW_CAVE
	goto_if_eq SecretBase_EventScript_CaveUseSecretPower
	compare VAR_0x8007, SECRET_BASE_TREE
	goto_if_eq SecretBase_EventScript_TreeUseSecretPower
	compare VAR_0x8007, SECRET_BASE_SHRUB
	goto_if_eq SecretBase_EventScript_ShrubUseSecretPower
	releaseall
	end

SecretBase_EventScript_NoSecretPower:: @ 8275C9A
	lockall
	compare VAR_0x8007, SECRET_BASE_RED_CAVE
	goto_if_eq SecretBase_EventScript_CaveNoSecretPower
	compare VAR_0x8007, SECRET_BASE_BROWN_CAVE
	goto_if_eq SecretBase_EventScript_CaveNoSecretPower
	compare VAR_0x8007, SECRET_BASE_BLUE_CAVE
	goto_if_eq SecretBase_EventScript_CaveNoSecretPower
	compare VAR_0x8007, SECRET_BASE_YELLOW_CAVE
	goto_if_eq SecretBase_EventScript_CaveNoSecretPower
	compare VAR_0x8007, SECRET_BASE_TREE
	goto_if_eq SecretBase_EventScript_TreeNoSecretPower
	compare VAR_0x8007, SECRET_BASE_SHRUB
	goto_if_eq SecretBase_EventScript_ShrubNoSecretPower
	end

SecretBase_EventScript_CancelOnEntrance:: @ 8275CDE
	closemessage
	releaseall
	end

SecretBase_EventScript_SetDecorationFlags:: @ 8275CE1
	setflag FLAG_DECORATION_1
	setflag FLAG_DECORATION_2
	setflag FLAG_DECORATION_3
	setflag FLAG_DECORATION_4
	setflag FLAG_DECORATION_5
	setflag FLAG_DECORATION_6
	setflag FLAG_DECORATION_7
	setflag FLAG_DECORATION_8
	setflag FLAG_DECORATION_9
	setflag FLAG_DECORATION_10
	setflag FLAG_DECORATION_11
	setflag FLAG_DECORATION_12
	setflag FLAG_DECORATION_13
	setflag FLAG_DECORATION_14
	return

SecretBase_EventScript_InitDecorations:: @ 8275D0C
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 0
	special InitSecretBaseDecorationSprites
	setvar VAR_SECRET_BASE_INITIALIZED, 1
	end

SecretBase_EventScript_SetDecoration:: @ 8275D1F
	setvar VAR_0x8005, 0
	goto SecretBase_EventScript_SetDecoration2
	end

SecretBase_EventScript_SetDecoration2:: @ 8275D2A
	special SetDecoration
	end

SecretBase_EventScript_PutAwayDecoration:: @ 8275D2E
	setvar VAR_0x8004, 0
	goto SecretBase_EventScript_PutAwayDecorationLoop
	end

SecretBase_EventScript_PutAwayDecorationLoop:: @ 8275D39
	special PutAwayDecorationIteration
	compare VAR_RESULT, 1
	goto_if_eq SecretBase_EventScript_PutAwayDecorationEnd
	addvar VAR_0x8004, 1
	compare VAR_0x8005, 0
	goto_if_eq SecretBase_EventScript_PutAwayDecorationLoop
	removeobject VAR_0x8006
	setflag VAR_0x8005  @ UB: VAR_0x8005 is set to a flag by PutAwayDecorationIteration, but ScrCmd_setflag doesn't use VarGet
	goto SecretBase_EventScript_PutAwayDecorationLoop
	end

SecretBase_EventScript_PutAwayDecorationEnd:: @ 8275D63
	end

SecretBase_EventScript_RecordMixTrainer:: @ 8275D64
	special GetSecretBaseOwnerAndState
	compare VAR_0x8004, 0
	goto_if_eq SecretBase_EventScript_Trainer0
	compare VAR_0x8004, 1
	goto_if_eq SecretBase_EventScript_Trainer1
	compare VAR_0x8004, 2
	goto_if_eq SecretBase_EventScript_Trainer2
	compare VAR_0x8004, 3
	goto_if_eq SecretBase_EventScript_Trainer3
	compare VAR_0x8004, 4
	goto_if_eq SecretBase_EventScript_Trainer4
	compare VAR_0x8004, 5
	goto_if_eq SecretBase_EventScript_Trainer5
	compare VAR_0x8004, 6
	goto_if_eq SecretBase_EventScript_Trainer6
	compare VAR_0x8004, 7
	goto_if_eq SecretBase_EventScript_Trainer7
	compare VAR_0x8004, 8
	goto_if_eq SecretBase_EventScript_Trainer8
	compare VAR_0x8004, 9
	goto_if_eq SecretBase_EventScript_Trainer9
	end

@ VAR_RESULT is initially set by GetSecretBaseOwnerAndState
SecretBase_EventScript_Trainer0:: @ 8275DD6
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, SecretBase_EventScript_Trainer0PreChampion
	compare VAR_RESULT, 1
	goto_if_eq SecretBase_EventScript_Trainer0PostBattle
	msgbox SecretBase_Text_Trainer0Intro, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SecretBase_EventScript_Trainer0DeclineBattle
	setvar VAR_RESULT, 1
	special SetBattledOwnerFromResult
	call Common_EventScript_SaveGame
	compare VAR_RESULT, 0
	goto_if_eq SecretBase_EventScript_Trainer0DeclineBattle
	msgbox SecretBase_Text_Trainer0AcceptBattle, MSGBOX_DEFAULT
	goto SecretBase_EventScript_BattleTrainer
	end

SecretBase_EventScript_Trainer0PreChampion:: @ 8275E25
	msgbox SecretBase_Text_Trainer0PreChampion, MSGBOX_DEFAULT
	release
	end

SecretBase_EventScript_Trainer0DeclineBattle:: @ 8275E2F
	special DeclinedSecretBaseBattle
	setvar VAR_RESULT, 0
	special SetBattledOwnerFromResult
	msgbox SecretBase_Text_Trainer0DeclineBattle, MSGBOX_DEFAULT
	release
	end

SecretBase_EventScript_Trainer0PostBattle:: @ 8275E44
	msgbox SecretBase_Text_Trainer0PostBattle, MSGBOX_DEFAULT
	release
	end

@ VAR_RESULT is initially set by GetSecretBaseOwnerAndState
SecretBase_EventScript_Trainer1:: @ 8275E4E
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, SecretBase_EventScript_Trainer1PreChampion
	compare VAR_RESULT, 1
	goto_if_eq SecretBase_EventScript_Trainer1PostBattle
	msgbox SecretBase_Text_Trainer1Intro, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SecretBase_EventScript_Trainer1DeclineBattle
	setvar VAR_RESULT, 1
	special SetBattledOwnerFromResult
	call Common_EventScript_SaveGame
	compare VAR_RESULT, 0
	goto_if_eq SecretBase_EventScript_Trainer1DeclineBattle
	msgbox SecretBase_Text_Trainer1AcceptBattle, MSGBOX_DEFAULT
	goto SecretBase_EventScript_BattleTrainer
	end

SecretBase_EventScript_Trainer1PreChampion:: @ 8275E9D
	msgbox SecretBase_Text_Trainer1PreChampion, MSGBOX_DEFAULT
	release
	end

SecretBase_EventScript_Trainer1DeclineBattle:: @ 8275EA7
	special DeclinedSecretBaseBattle
	setvar VAR_RESULT, 0
	special SetBattledOwnerFromResult
	msgbox SecretBase_Text_Trainer1DeclineBattle, MSGBOX_DEFAULT
	release
	end

SecretBase_EventScript_Trainer1PostBattle:: @ 8275EBC
	msgbox SecretBase_Text_Trainer1PostBattle, MSGBOX_DEFAULT
	release
	end

@ VAR_RESULT is initially set by GetSecretBaseOwnerAndState
SecretBase_EventScript_Trainer2:: @ 8275EC6
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, SecretBase_EventScript_Trainer2PreChampion
	compare VAR_RESULT, 1
	goto_if_eq SecretBase_EventScript_Trainer2PostBattle
	msgbox SecretBase_Text_Trainer2Intro, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SecretBase_EventScript_Trainer2DeclineBattle
	setvar VAR_RESULT, 1
	special SetBattledOwnerFromResult
	call Common_EventScript_SaveGame
	compare VAR_RESULT, 0
	goto_if_eq SecretBase_EventScript_Trainer2DeclineBattle
	msgbox SecretBase_Text_Trainer2AcceptBattle, MSGBOX_DEFAULT
	goto SecretBase_EventScript_BattleTrainer
	end

SecretBase_EventScript_Trainer2PreChampion:: @ 8275F15
	msgbox SecretBase_Text_Trainer2PreChampion, MSGBOX_DEFAULT
	release
	end

SecretBase_EventScript_Trainer2DeclineBattle:: @ 8275F1F
	special DeclinedSecretBaseBattle
	setvar VAR_RESULT, 0
	special SetBattledOwnerFromResult
	msgbox SecretBase_Text_Trainer2DeclineBattle, MSGBOX_DEFAULT
	release
	end

SecretBase_EventScript_Trainer2PostBattle:: @ 8275F34
	msgbox SecretBase_Text_Trainer2PostBattle, MSGBOX_DEFAULT
	release
	end

@ VAR_RESULT is initially set by GetSecretBaseOwnerAndState
SecretBase_EventScript_Trainer3:: @ 8275F3E
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, SecretBase_EventScript_Trainer3PreChampion
	compare VAR_RESULT, 1
	goto_if_eq SecretBase_EventScript_Trainer3PostBattle
	msgbox SecretBase_Text_Trainer3Intro, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SecretBase_EventScript_Trainer3DeclineBattle
	setvar VAR_RESULT, 1
	special SetBattledOwnerFromResult
	call Common_EventScript_SaveGame
	compare VAR_RESULT, 0
	goto_if_eq SecretBase_EventScript_Trainer3DeclineBattle
	msgbox SecretBase_Text_Trainer3AcceptBattle, MSGBOX_DEFAULT
	goto SecretBase_EventScript_BattleTrainer
	end

SecretBase_EventScript_Trainer3PreChampion:: @ 8275F8D
	msgbox SecretBase_Text_Trainer3PreChampion, MSGBOX_DEFAULT
	release
	end

SecretBase_EventScript_Trainer3DeclineBattle:: @ 8275F97
	special DeclinedSecretBaseBattle
	setvar VAR_RESULT, 0
	special SetBattledOwnerFromResult
	msgbox SecretBase_Text_Trainer3DeclineBattle, MSGBOX_DEFAULT
	release
	end

SecretBase_EventScript_Trainer3PostBattle:: @ 8275FAC
	msgbox SecretBase_Text_Trainer3PostBattle, MSGBOX_DEFAULT
	release
	end

@ VAR_RESULT is initially set by GetSecretBaseOwnerAndState
SecretBase_EventScript_Trainer4:: @ 8275FB6
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, SecretBase_EventScript_Trainer4PreChampion
	compare VAR_RESULT, 1
	goto_if_eq SecretBase_EventScript_Trainer4PostBattle
	msgbox SecretBase_Text_Trainer4Intro, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SecretBase_EventScript_Trainer4DeclineBattle
	setvar VAR_RESULT, 1
	special SetBattledOwnerFromResult
	call Common_EventScript_SaveGame
	compare VAR_RESULT, 0
	goto_if_eq SecretBase_EventScript_Trainer4DeclineBattle
	msgbox SecretBase_Text_Trainer4AcceptBattle, MSGBOX_DEFAULT
	goto SecretBase_EventScript_BattleTrainer
	end

SecretBase_EventScript_Trainer4PreChampion:: @ 8276005
	msgbox SecretBase_Text_Trainer4PreChampion, MSGBOX_DEFAULT
	release
	end

SecretBase_EventScript_Trainer4DeclineBattle:: @ 827600F
	special DeclinedSecretBaseBattle
	setvar VAR_RESULT, 0
	special SetBattledOwnerFromResult
	msgbox SecretBase_Text_Trainer4DeclineBattle, MSGBOX_DEFAULT
	release
	end

SecretBase_EventScript_Trainer4PostBattle:: @ 8276024
	msgbox SecretBase_Text_Trainer4PostBattle, MSGBOX_DEFAULT
	release
	end

@ VAR_RESULT is initially set by GetSecretBaseOwnerAndState
SecretBase_EventScript_Trainer5:: @ 827602E
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, SecretBase_EventScript_Trainer5PreChampion
	compare VAR_RESULT, 1
	goto_if_eq SecretBase_EventScript_Trainer5PostBattle
	msgbox SecretBase_Text_Trainer5Intro, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SecretBase_EventScript_Trainer5DeclineBattle
	setvar VAR_RESULT, 1
	special SetBattledOwnerFromResult
	call Common_EventScript_SaveGame
	compare VAR_RESULT, 0
	goto_if_eq SecretBase_EventScript_Trainer5DeclineBattle
	msgbox SecretBase_Text_Trainer5AcceptBattle, MSGBOX_DEFAULT
	goto SecretBase_EventScript_BattleTrainer
	end

SecretBase_EventScript_Trainer5PreChampion:: @ 827607D
	msgbox SecretBase_Text_Trainer5PreChampion, MSGBOX_DEFAULT
	release
	end

SecretBase_EventScript_Trainer5DeclineBattle:: @ 8276087
	special DeclinedSecretBaseBattle
	setvar VAR_RESULT, 0
	special SetBattledOwnerFromResult
	msgbox SecretBase_Text_Trainer5DeclineBattle, MSGBOX_DEFAULT
	release
	end

SecretBase_EventScript_Trainer5PostBattle:: @ 827609C
	msgbox SecretBase_Text_Trainer5PostBattle, MSGBOX_DEFAULT
	release
	end

@ VAR_RESULT is initially set by GetSecretBaseOwnerAndState
SecretBase_EventScript_Trainer6:: @ 82760A6
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, SecretBase_EventScript_Trainer6PreChampion
	compare VAR_RESULT, 1
	goto_if_eq SecretBase_EventScript_Trainer6PostBattle
	msgbox SecretBase_Text_Trainer6Intro, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SecretBase_EventScript_Trainer6DeclineBattle
	setvar VAR_RESULT, 1
	special SetBattledOwnerFromResult
	call Common_EventScript_SaveGame
	compare VAR_RESULT, 0
	goto_if_eq SecretBase_EventScript_Trainer6DeclineBattle
	msgbox SecretBase_Text_Trainer6AcceptBattle, MSGBOX_DEFAULT
	goto SecretBase_EventScript_BattleTrainer
	end

SecretBase_EventScript_Trainer6PreChampion:: @ 82760F5
	msgbox SecretBase_Text_Trainer6PreChampion, MSGBOX_DEFAULT
	release
	end

SecretBase_EventScript_Trainer6DeclineBattle:: @ 82760FF
	special DeclinedSecretBaseBattle
	setvar VAR_RESULT, 0
	special SetBattledOwnerFromResult
	msgbox SecretBase_Text_Trainer6DeclineBattle, MSGBOX_DEFAULT
	release
	end

SecretBase_EventScript_Trainer6PostBattle:: @ 8276114
	msgbox SecretBase_Text_Trainer6PostBattle, MSGBOX_DEFAULT
	release
	end

@ VAR_RESULT is initially set by GetSecretBaseOwnerAndState
SecretBase_EventScript_Trainer7:: @ 827611E
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, SecretBase_EventScript_Trainer7PreChampion
	compare VAR_RESULT, 1
	goto_if_eq SecretBase_EventScript_Trainer7PostBattle
	msgbox SecretBase_Text_Trainer7Intro, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SecretBase_EventScript_Trainer7DeclineBattle
	setvar VAR_RESULT, 1
	special SetBattledOwnerFromResult
	call Common_EventScript_SaveGame
	compare VAR_RESULT, 0
	goto_if_eq SecretBase_EventScript_Trainer7DeclineBattle
	msgbox SecretBase_Text_Trainer7AcceptBattle, MSGBOX_DEFAULT
	goto SecretBase_EventScript_BattleTrainer
	end

SecretBase_EventScript_Trainer7PreChampion:: @ 827616D
	msgbox SecretBase_Text_Trainer7PreChampion, MSGBOX_DEFAULT
	release
	end

SecretBase_EventScript_Trainer7DeclineBattle:: @ 8276177
	special DeclinedSecretBaseBattle
	setvar VAR_RESULT, 0
	special SetBattledOwnerFromResult
	msgbox SecretBase_Text_Trainer7DeclineBattle, MSGBOX_DEFAULT
	release
	end

SecretBase_EventScript_Trainer7PostBattle:: @ 827618C
	msgbox SecretBase_Text_Trainer7PostBattle, MSGBOX_DEFAULT
	release
	end

@ VAR_RESULT is initially set by GetSecretBaseOwnerAndState
SecretBase_EventScript_Trainer8:: @ 8276196
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, SecretBase_EventScript_Trainer8PreChampion
	compare VAR_RESULT, 1
	goto_if_eq SecretBase_EventScript_Trainer8PostBattle
	msgbox SecretBase_Text_Trainer8Intro, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SecretBase_EventScript_Trainer8DeclineBattle
	setvar VAR_RESULT, 1
	special SetBattledOwnerFromResult
	call Common_EventScript_SaveGame
	compare VAR_RESULT, 0
	goto_if_eq SecretBase_EventScript_Trainer8DeclineBattle
	msgbox SecretBase_Text_Trainer8AcceptBattle, MSGBOX_DEFAULT
	goto SecretBase_EventScript_BattleTrainer
	end

SecretBase_EventScript_Trainer8PreChampion:: @ 82761E5
	msgbox SecretBase_Text_Trainer8PreChampion, MSGBOX_DEFAULT
	release
	end

SecretBase_EventScript_Trainer8DeclineBattle:: @ 82761EF
	special DeclinedSecretBaseBattle
	setvar VAR_RESULT, 0
	special SetBattledOwnerFromResult
	msgbox SecretBase_Text_Trainer8DeclineBattle, MSGBOX_DEFAULT
	release
	end

SecretBase_EventScript_Trainer8PostBattle:: @ 8276204
	msgbox SecretBase_Text_Trainer8PostBattle, MSGBOX_DEFAULT
	release
	end

@ VAR_RESULT is initially set by GetSecretBaseOwnerAndState
SecretBase_EventScript_Trainer9:: @ 827620E
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, SecretBase_EventScript_Trainer9PreChampion
	compare VAR_RESULT, 1
	goto_if_eq SecretBase_EventScript_Trainer9PostBattle
	msgbox SecretBase_Text_Trainer9Intro, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SecretBase_EventScript_Trainer9DeclineBattle
	setvar VAR_RESULT, 1
	special SetBattledOwnerFromResult
	call Common_EventScript_SaveGame
	compare VAR_RESULT, 0
	goto_if_eq SecretBase_EventScript_Trainer9DeclineBattle
	msgbox SecretBase_Text_Trainer9AcceptBattle, MSGBOX_DEFAULT
	goto SecretBase_EventScript_BattleTrainer
	end

SecretBase_EventScript_Trainer9PreChampion:: @ 827625D
	msgbox SecretBase_Text_Trainer9PreChampion, MSGBOX_DEFAULT
	release
	end

SecretBase_EventScript_Trainer9DeclineBattle:: @ 8276267
	special DeclinedSecretBaseBattle
	setvar VAR_RESULT, 0
	special SetBattledOwnerFromResult
	msgbox SecretBase_Text_Trainer9DeclineBattle, MSGBOX_DEFAULT
	release
	end

SecretBase_EventScript_Trainer9PostBattle:: @ 827627C
	msgbox SecretBase_Text_Trainer9PostBattle, MSGBOX_DEFAULT
	release
	end

SecretBase_EventScript_BattleTrainer:: @ 8276286
	special PrepSecretBaseBattleFlags
	setvar VAR_0x8004, SPECIAL_BATTLE_SECRET_BASE
	setvar VAR_0x8005, 0
	special DoSpecialTrainerBattle
	waitstate
	compare VAR_RESULT, B_OUTCOME_DREW
	call_if_eq SecretBase_EventScript_DrewSecretBaseBattle
	compare VAR_RESULT, B_OUTCOME_WON
	call_if_eq SecretBase_EventScript_WonSecretBaseBattle
	compare VAR_RESULT, B_OUTCOME_LOST
	call_if_eq SecretBase_EventScript_LostSecretBaseBattle
	special HealPlayerParty
	release
	end

SecretBase_EventScript_DrewSecretBaseBattle:: @ 82762BD
	special DrewSecretBaseBattle
	return

SecretBase_EventScript_WonSecretBaseBattle:: @ 82762C1
	special WonSecretBaseBattle
	return

SecretBase_EventScript_LostSecretBaseBattle:: @ 82762C5
	special LostSecretBaseBattle
	return

	.include "data/scripts/secret_power_tm.inc"

SecretBase_EventScript_DollInteract:: @ 82766A2
	special CheckInteractedWithFriendsDollDecor
	end

SecretBase_EventScript_CushionInteract:: @ 82766A6
	special CheckInteractedWithFriendsCushionDecor
	end

SecretBase_Text_AllDecorationsWillBeReturned: @ 82766AA
	.string "비밀기지의 굿즈는 모두\n"
	.string "PC로 돌아갑니다\p"
	.string "그래도 괜찮겠습니까?$"
	@ ひみつきちの グッズは すべてｎ
	@ パソコンに もどりますｐ
	@ それでも よろしいですか?

SecretBase_Text_WantToRegisterSecretBase: @ 8276707
	.string "{STR_VAR_1}의 비밀기지를\n"
	.string "등록하겠습니까?$"
	@ §いの ひみつきちをｎ
	@ とうろく しますか?

SecretBase_Text_AlreadyRegisteredDelete: @ 8276731
	.string "이미 등록되어 있습니다\n"
	.string "등록을 해제하겠습니까?$"
	@ すでに とうろくされていますｎ
	@ とうろくを かいじょ しますか?

SecretBase_Text_TooManyBasesDeleteSome: @ 827676F
	.string "등록할 수 있는 수는\n"
	.string "10곳까지입니다\p"
	.string "어느 장소가 해제되면\n"
	.string "등록할 수 있습니다$"
	@ とうろく できる かずはｎ
	@ 10かしょ まで ですｐ
	@ どれか かいじょ すればｎ
	@ とうろく できます

SecretBase_Text_RegistrationCompleted: @ 82767D1
	.string "등록했습니다!$"
	@ とうろく しました!

SecretBase_Text_DataUnregistered: @ 82767E9
	.string "등록을 해제했습니다!$"
	@ とうろくを かいじょ しました!

SecretBase_Text_BootUpPC: @ 8276805
	.string "{PLAYER}{K_EUNNEUN}\n"
	.string	"PC 전원을 켰다!$"
	@ §あはｎ
	@ パソコンの スイッチを いれた!

SecretBase_Text_WhatWouldYouLikeToDo: @ 827681A
	.string "무엇을 하겠습니까?$"
	@ なにを しますか?

SecretBase_Text_RegistryInfo: @ 8276835
	.string "등록한 비밀기지는\n"
	.string "상대가 이사를 하지 않는 한\l"
	.string "사라지는 일은 없습니다\p"
	.string "등록 리스트에서 삭제하면\n"
	.string "다른 비밀기지로\l"
	.string "바뀌는 일도 있습니다\p"
	.string "등록은 10곳까지 할 수 있습니다$"
	@ とうろくした ひみつきちはｎ
	@ あいてが ひっこしを しないかぎりｌ
	@ なくなる ことは ありませんｐ
	@ とうろく リストから さくじょするとｎ
	@ ほかの ひみつきちにｌ
	@ かわることが ありますｐ
	@ とうろくは 10かしょ まで できます

SecretBase_Text_BattleTowerShield: @ 827692B
	.string "배틀타워에서 {STR_VAR_1}명 연승한\n"
	.string "기념의 {STR_VAR_2} 상패$"
	@ バトルタワ-で §いにん かちぬいたｎ
	@ きねんの §うの たて

SecretBase_Text_ToyTV: @ 8276974
	.string "진짜와 꼭 닮게 만들어진 장난감 TV\n"
	.string "모르는 사람이 보면 착각할지도!?$"
	@ ほんもの そっくりの オモチャのテレビｎ
	@ しらない ひとが みたら まちがうかも!?

SecretBase_Text_SeedotTV: @ 82769B8
	.string "도토링을 닮은 장난감 TV\n"
	.string "왠지 굴러다닐 것 같다!?$"
	@ タネボ- みたいな オモチャのテレビｎ
	@ なんだか ころがりだしそう!?

SecretBase_Text_SkittyTV: @ 82769FF
	.string "에나비를 닮은 장난감 TV\n"
	.string "왠지 걸어다닐 것 같다!?$"
	@ エネコ みたいな オモチャのテレビｎ
	@ なんだか あるきだしそう!?

SecretBase_Text_WouldYouLikeToMoveBases: @ 8276A3D
	.string "비밀기지는 하나밖에 만들 수 없습니다!\p"
	.string "{STR_VAR_1}에 있는\n"
	.string "비밀기지를 이사하겠습니까?$"
	@ ひみつきちは ひとつしか つくれません!ｐ
	@ §い にあるｎ
	@ ひみつきちを ひっこし しますか?

SecretBase_Text_MovingCompletedUseSecretPower: @ 8276A95
	.string "이사 완료!\p"
	.string "비밀의힘을 사용하겠습니까?$"
	@ ひっこし かんりょう!ｐ
	@ ひみつのちからを つかいますか?
