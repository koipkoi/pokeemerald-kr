.set LOCALID_SAILOR, 1
.set LOCALID_SCOTT, 5

SSTidalCorridor_MapScripts:: @ 823BFCF
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SSTidalCorridor_OnFrame
	.byte 0

SSTidalCorridor_OnFrame: @ 823BFD5
	map_script_2 VAR_SS_TIDAL_SCOTT_STATE, 0, SSTidalCorridor_EventScript_ScottScene
	map_script_2 VAR_SS_TIDAL_STATE, SS_TIDAL_BOARD_SLATEPORT, SSTidalCorridor_EventScript_DepartSlateportForLilycove
	map_script_2 VAR_SS_TIDAL_STATE, SS_TIDAL_BOARD_LILYCOVE, SSTidalCorridor_EventScript_DepartLilycoveForSlateport
	map_script_2 VAR_SS_TIDAL_STATE, SS_TIDAL_EXIT_CURRENTS_RIGHT, SSTidalCorridor_EventScript_HalfwayToLilycove
	map_script_2 VAR_SS_TIDAL_STATE, SS_TIDAL_EXIT_CURRENTS_LEFT, SSTidalCorridor_EventScript_ArrivedInSlateport
	.2byte 0

SSTidalCorridor_EventScript_DepartSlateportForLilycove:: @ 823BFFF
	special SetSSTidalFlag
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_DEPART_SLATEPORT
	lockall
	playse SE_DING_DONG
	msgbox SSTidal_Text_FastCurrentsHopeYouEnjoyVoyage, MSGBOX_DEFAULT
	releaseall
	end

SSTidalCorridor_EventScript_DepartLilycoveForSlateport:: @ 823C015
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_DEPART_LILYCOVE
	lockall
	playse SE_DING_DONG
	msgbox SSTidal_Text_HopeYouEnjoyVoyage, MSGBOX_DEFAULT
	releaseall
	end

SSTidalRooms_EventScript_HalfwayToSlateport:: @ 823C028
	special SetSSTidalFlag
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_HALFWAY_SLATEPORT
	playse SE_DING_DONG
	msgbox SSTidal_Text_FastCurrentsHopeYouEnjoyVoyage, MSGBOX_DEFAULT
	return

SSTidalRooms_EventScript_ArrivedInLilycove:: @ 823C03C
	special ResetSSTidalFlag
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_LAND_LILYCOVE
	playse SE_DING_DONG
	msgbox SSTidal_Text_MadeLandInLilycove, MSGBOX_DEFAULT
	return

SSTidalCorridor_EventScript_ReachedStepCount:: @ 823C050
	compare VAR_SS_TIDAL_STATE, SS_TIDAL_DEPART_SLATEPORT
	goto_if_eq SSTidalCorridor_EventScript_HalfwayToLilycove
	compare VAR_SS_TIDAL_STATE, SS_TIDAL_HALFWAY_SLATEPORT
	goto_if_eq SSTidalCorridor_EventScript_ArrivedInSlateport
	end

SSTidalCorridor_EventScript_HalfwayToLilycove:: @ 823C067
	special ResetSSTidalFlag
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_HALFWAY_LILYCOVE
	lockall
	playse SE_DING_DONG
	msgbox SSTidal_Text_HopeYouEnjoyVoyage, MSGBOX_DEFAULT
	releaseall
	end

SSTidalCorridor_EventScript_ArrivedInSlateport:: @ 823C07D
	special ResetSSTidalFlag
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_LAND_SLATEPORT
	lockall
	playse SE_DING_DONG
	msgbox SSTidal_Text_MadeLandInSlateport, MSGBOX_DEFAULT
	releaseall
	end

SSTidalRooms_EventScript_ArrivedInSlateport:: @ 823C093
	special ResetSSTidalFlag
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_LAND_SLATEPORT
	playse SE_DING_DONG
	msgbox SSTidal_Text_MadeLandInSlateport, MSGBOX_DEFAULT
	return

SSTidalRooms_EventScript_ProgessCruiseAfterBed:: @ 823C0A7
	switch VAR_SS_TIDAL_STATE
	case SS_TIDAL_DEPART_SLATEPORT, SSTidalRooms_EventScript_ArrivedInLilycove
	case SS_TIDAL_HALFWAY_LILYCOVE, SSTidalRooms_EventScript_ArrivedInLilycove
	case SS_TIDAL_DEPART_LILYCOVE, SSTidalRooms_EventScript_HalfwayToSlateport
	case SS_TIDAL_HALFWAY_SLATEPORT, SSTidalRooms_EventScript_ArrivedInSlateport
	return

SSTidalCorridor_EventScript_Briney:: @ 823C0D9
	msgbox SSTidalCorridor_Text_BrineyWelcomeAboard, MSGBOX_NPC
	end

SSTidalCorridor_EventScript_Peeko:: @ 823C0E2
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, 0
	msgbox SSTidalCorridor_Text_Peeko, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SSTidalCorridor_EventScript_Cabin1Sign:: @ 823C0F5
	msgbox SSTidalCorridor_Text_Cabin1, MSGBOX_SIGN
	end

SSTidalCorridor_EventScript_Cabin2Sign:: @ 823C0FE
	msgbox SSTidalCorridor_Text_Cabin2, MSGBOX_SIGN
	end

SSTidalCorridor_EventScript_Cabin3Sign:: @ 823C107
	msgbox SSTidalCorridor_Text_Cabin3, MSGBOX_SIGN
	end

SSTidalCorridor_EventScript_Cabin4Sign:: @ 823C110
	msgbox SSTidalCorridor_Text_Cabin4, MSGBOX_SIGN
	end

SSTidalCorridor_EventScript_ExitSailor:: @ 823C119
	lock
	faceplayer
	compare VAR_SS_TIDAL_STATE, SS_TIDAL_LAND_LILYCOVE
	goto_if_eq SSTidalCorridor_EventScript_ExitLilycove
	compare VAR_SS_TIDAL_STATE, SS_TIDAL_LAND_SLATEPORT
	goto_if_eq SSTidalCorridor_EventScript_ExitSlateport
	msgbox SSTidalCorridor_Text_CanRestInCabin2, MSGBOX_DEFAULT
	release
	end

SSTidalCorridor_EventScript_ExitLilycove:: @ 823C13B
	setrespawn HEAL_LOCATION_LILYCOVE_CITY
	msgbox SSTidalCorridor_Text_WeveArrived, MSGBOX_DEFAULT
	call_if_set FLAG_RECEIVED_TM49, SSTidalCorridor_EventScript_HideSnatchGiver
	warp MAP_LILYCOVE_CITY_HARBOR, 255, 8, 11
	waitstate
	release
	end

SSTidalCorridor_EventScript_ExitSlateport:: @ 823C15A
	setrespawn HEAL_LOCATION_SLATEPORT_CITY
	msgbox SSTidalCorridor_Text_WeveArrived, MSGBOX_DEFAULT
	call_if_set FLAG_RECEIVED_TM49, SSTidalCorridor_EventScript_HideSnatchGiver
	warp MAP_SLATEPORT_CITY_HARBOR, 255, 8, 11
	waitstate
	release
	end

SSTidalCorridor_EventScript_HideSnatchGiver:: @ 823C179
	setflag FLAG_HIDE_SS_TIDAL_ROOMS_SNATCH_GIVER
	return

SSTidalCorridor_EventScript_Porthole:: @ 823C17D
	lockall
	compare VAR_SS_TIDAL_STATE, SS_TIDAL_DEPART_SLATEPORT
	goto_if_eq SSTidalCorridor_EventScript_LookThroughPorthole
	compare VAR_SS_TIDAL_STATE, SS_TIDAL_HALFWAY_SLATEPORT
	goto_if_eq SSTidalCorridor_EventScript_LookThroughPorthole
	msgbox SSTidalCorridor_Text_HorizonSpreadsBeyondPorthole, MSGBOX_DEFAULT
	releaseall
	end

SSTidalCorridor_EventScript_LookThroughPorthole:: @ 823C19E
	special LookThroughPorthole
	waitstate
	end

SSTidalCorridor_EventScript_Sailor:: @ 823C1A3
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SS_TIDAL_TRAINERS, SSTidalCorridor_EventScript_EnjoyYourCruise
	call SSTidalCorridor_EventScript_CheckIfTrainersDefeated
	msgbox SSTidalCorridor_Text_VisitOtherCabins, MSGBOX_DEFAULT
	release
	end

SSTidalCorridor_EventScript_EnjoyYourCruise:: @ 823C1BD
	msgbox SSTidalCorridor_Text_EnjoyYourCruise, MSGBOX_DEFAULT
	release
	end

SSTidalCorridor_EventScript_CheckIfTrainersDefeated:: @ 823C1C7
	goto_if_not_defeated TRAINER_PHILLIP, SSTidalCorridor_EventScript_TrainerNotDefeated
	goto_if_not_defeated TRAINER_LEONARD, SSTidalCorridor_EventScript_TrainerNotDefeated
	goto_if_not_defeated TRAINER_COLTON, SSTidalCorridor_EventScript_TrainerNotDefeated
	goto_if_not_defeated TRAINER_MICAH, SSTidalCorridor_EventScript_TrainerNotDefeated
	goto_if_not_defeated TRAINER_THOMAS, SSTidalCorridor_EventScript_TrainerNotDefeated
	goto_if_not_defeated TRAINER_LEA_AND_JED, SSTidalCorridor_EventScript_TrainerNotDefeated
	goto_if_not_defeated TRAINER_GARRET, SSTidalCorridor_EventScript_TrainerNotDefeated
	goto_if_not_defeated TRAINER_NAOMI, SSTidalCorridor_EventScript_TrainerNotDefeated
	setflag FLAG_DEFEATED_SS_TIDAL_TRAINERS
	goto SSTidalCorridor_EventScript_EnjoyYourCruise
	return

SSTidalCorridor_EventScript_TrainerNotDefeated:: @ 823C218
	return

SSTidalCorridor_EventScript_ScottScene:: @ 823C219
	lockall
	applymovement LOCALID_SCOTT, SSTidalCorridor_Movement_ScottApproachPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox SSTidalCorridor_Text_ScottBattleFrontierInvite, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, SSTidalCorridor_Movement_PlayerWatchScottExit
	applymovement LOCALID_SAILOR, SSTidalCorridor_Movement_SailorMoveForScott
	applymovement LOCALID_SCOTT, SSTidalCorridor_Movement_ScottExit
	waitmovement 0
	playse SE_EXIT
	waitse
	removeobject LOCALID_SCOTT
	applymovement LOCALID_SAILOR, SSTidalCorridor_Movement_SailorReturn
	waitmovement 0
	delay 30
	setflag FLAG_MET_SCOTT_ON_SS_TIDAL
	setvar VAR_SS_TIDAL_SCOTT_STATE, 1
	releaseall
	end

SSTidalCorridor_Movement_ScottApproachPlayer: @ 823C26D
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SSTidalCorridor_Movement_ScottExit: @ 823C275
	walk_in_place_fastest_down
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_left
	step_end

SSTidalCorridor_Movement_PlayerWatchScottExit: @ 823C27D
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_fastest_down
	step_end

SSTidalCorridor_Movement_SailorMoveForScott: @ 823C284
	delay_16
	walk_right
	walk_right
	walk_in_place_fastest_up
	delay_16
	walk_in_place_fastest_left
	step_end

SSTidalCorridor_Movement_SailorReturn: @ 823C28B
	walk_left
	walk_left
	walk_in_place_fastest_up
	step_end

SSTidalCorridor_Text_ScottBattleFrontierInvite: @ 823C28F
	.string "금작화: 여어 여어 여어\n"
	.string "{PLAYER}{K_AYA} {PLAYER}{K_AYA}!\p"
	.string "나는 볼일이 있어서\n"
	.string "이제 배에서 내리겠지만\l"
	.string "그래도 만나서 다행이네!\p"
	.string "리그 챔피언 축하해!\n"
	.string "그런 너를 초대하고 싶은\l"
	.string "장소가 있어!\p"
	.string "바로... 배틀프런티어야!\p"
	.string "어떤 곳이냐고?\n"
	.string "일단 가보면 알 거야\p"
	.string "이 배의 선장한테는\n"
	.string "이미 얘기를 해뒀으니까...\l"
	.string "다음부터 배에 탈 때는\l"
	.string "배틀프런티어에 갈 수 있을 거야!\p"
	.string "그럼 {PLAYER}{K_AYA}\n"
	.string "배틀프런티어에서 기다릴게!$"
	@ エニシダ『やあ やあ やあｎ
	@ §あ§お §あ§お!ｐ
	@ わたしは ようじが あってｎ
	@ もう ふねを おりるんだけどｌ
	@ あえて よかったよ!ｐ
	@ リ-グチャンピオン おめでとう!ｎ
	@ そんな きみを しょうたい したいｌ
	@ ところが ある!ｐ
	@ それは…… バトルフロンティア だ!ｐ
	@ どんな ところかって?ｎ
	@ とにかく きてみれば わかるよｐ
	@ このふねの せんちょうにはｎ
	@ はなしを しておいた から……ｌ
	@ つぎから ふねに のるときはｌ
	@ バトルフロンティアに いける はずだよ!ｐ
	@ じゃあね §あ§おｎ
	@ バトルフロンティアで まっているよ!

SSTidal_Text_FastCurrentsHopeYouEnjoyVoyage: @ 823C462
	.string "해류에 꿈쩍도 하지 않고 나아가는\n"
	.string "연락선을 봐 주세요$"
	@ かいりゅうを ものともせず すすむｎ
	@ れんらくせんを どうぞ ごらんください

SSTidal_Text_HopeYouEnjoyVoyage: @ 823C4E3
	.string "그럼 연락선을 이용한\n"
	.string "즐거운 배 여행을 만끽해 주세요$"
	@ それでは れんらくせんに よるｎ
	@ ふなたびを おたのしみ ください

SSTidal_Text_MadeLandInSlateport: @ 823C50F
	.string "수고하셨습니다 지금 막\n"
	.string "잿빛도시에 도착했습니다$"
	@ おつかれさまです ただいまｎ
	@ カイナシティに とうちゃく しました

SSTidal_Text_MadeLandInLilycove: @ 823C553
	.string "수고하셨습니다 지금 막\n"
	.string "해안시티에 도착했습니다$"
	@ おつかれさまです ただいまｎ
	@ ミナモシティに とうちゃく しました

SSTidalCorridor_Text_CanRestInCabin2: @ 823C596
	.string "도착하려면 아직 멀었어\p"
	.string "자기 방에 돌아가서 쉬고 있으라고\n"
	.string "분명 네 방은\l"
	.string "2호실이었지\p"
	.string "그 방 침대는\n"
	.string "푹신푹신해서 정말 편하단다!$"
	@ とうちゃくまで まだまだ だなｐ
	@ じぶんの へやに もどって やすんでいなよｎ
	@ たしか きみの へやはｌ
	@ 2ごうしつ だったなｐ
	@ あの へやの ベッドはｎ
	@ ふかふか していて きもちいいぞ!

SSTidalCorridor_Text_WeveArrived: @ 823C64F
	.string "도착했어!$"
	@ とうちゃく したぞ!

SSTidalCorridor_Text_VisitOtherCabins: @ 823C65E
	.string "배 여행에 질려버려서\n"
	.string "객실에서 포켓몬 승부를\l"
	.string "하고 싶어 하는 트레이너도 있어!$"
	@ ふなたびに あきちゃってｎ
	@ きゃくしつで ポケモンで しょうぶをｌ
	@ したがっている トレ-ナ-も いるぞ!

SSTidalCorridor_Text_EnjoyYourCruise: @ 823C6B0
	.string "즐거운 배 여행을 만끽해 줘$"
	@ まっ ふなたびを たのしんでくれよ

SSTidalCorridor_Text_HorizonSpreadsBeyondPorthole: @ 823C6C3
	.string "창문 저편에\n"
	.string "수평선이 펼쳐져 있다!$"
	@ まどの むこうにｎ
	@ すいへいせんが ひろがっている!

SSTidalCorridor_Text_BrineyWelcomeAboard: @ 823C6EC
	.string "하기: 어서 오너라! {PLAYER}!\p"
	.string "내가 이 타이드립호의\n"
	.string "명예 선장인 하기다!\p"
	.string "이야 한 번은 은퇴한 몸이지만\n"
	.string "이런 엄청난 배를 봐 버리면\l"
	.string "선원의 피가 들끓어서 말이지!!$"
	@ ハギ『ようこそ! §あ§お!ｐ
	@ わしが この タイドリップごうのｎ
	@ めいよ せんちょう ハギ じゃよ!ｐ
	@ いやぁ いちどは いんたい したがｎ
	@ こんな すごい ふねを みてしまうとｌ
	@ ふなのりの ちが さわぐのう!!

SSTidalCorridor_Text_Peeko: @ 823C7E1
	.string "피코: 피효 피효효...!$"
	@ ピ-コ『ピひょ ピひょひょ……!

SSTidalCorridor_Text_Cabin1: @ 823C7F8
	.string "1호실$"
	@ 1ごうしつ

SSTidalCorridor_Text_Cabin2: @ 823C800
	.string "2호실$"
	@ 2ごうしつ

SSTidalCorridor_Text_Cabin3: @ 823C808
	.string "3호실$"
	@ 3ごうしつ

SSTidalCorridor_Text_Cabin4: @ 823C810
	.string "4호실$"
	@ 4ごうしつ
