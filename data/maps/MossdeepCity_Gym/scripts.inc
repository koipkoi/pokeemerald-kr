MossdeepCity_Gym_MapScripts:: @ 8220800
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_Gym_OnLoad
	.byte 0

@ NOTE: Mossdeep Gym was redesigned between R/S and E. Leftover (and now functionally unused) scripts are commented below

@ All the below checks are leftover from RS. FLAG_MOSSDEEP_GYM_SWITCH_X is never set
MossdeepCity_Gym_OnLoad: @ 8220806
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_SetSwitch1Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_CheckSwitch2:: @ 8220815
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_SetSwitch2Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_CheckSwitch3:: @ 8220824
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_SetSwitch3Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_CheckSwitch4:: @ 8220833
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_SetSwitch4Metatiles
	end

@ All the below set metatile scripts are leftover from RS and are functionally unused
MossdeepCity_Gym_EventScript_SetSwitch1Metatiles:: @ 822083D
	setmetatile 5, 5, METATILE_RS_MossdeepGym_RedArrow_Right, 0
	setmetatile 2, 7, METATILE_RS_MossdeepGym_Switch_Down, 1
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_SetSwitch2Metatiles:: @ 8220855
	setmetatile 8, 14, METATILE_RS_MossdeepGym_RedArrow_Right, 0
	setmetatile 8, 10, METATILE_RS_MossdeepGym_Switch_Down, 1
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_SetSwitch3Metatiles:: @ 822086D
	setmetatile 15, 17, METATILE_RS_MossdeepGym_RedArrow_Left, 0
	setmetatile 17, 15, METATILE_RS_MossdeepGym_Switch_Down, 1
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_SetSwitch4Metatiles:: @ 8220885
	setmetatile 1, 23, METATILE_RS_MossdeepGym_RedArrow_Up, 0
	setmetatile 5, 24, METATILE_RS_MossdeepGym_Switch_Down, 1
	end

MossdeepCity_Gym_EventScript_TateAndLiza:: @ 8220898
	trainerbattle_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaIntro, MossdeepCity_Gym_Text_TateAndLizaDefeat, MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons, MossdeepCity_Gym_EventScript_TateAndLizaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq MossdeepCity_Gym_EventScript_TateAndLizaRematch
	goto_if_unset FLAG_RECEIVED_TM04, MossdeepCity_Gym_EventScript_GiveCalmMind2
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostBattle, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_TateAndLizaDefeated:: @ 82208D1
	message MossdeepCity_Gym_Text_ReceivedMindBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
	setflag FLAG_BADGE07_GET
	setflag FLAG_HIDE_AQUA_HIDEOUT_GRUNTS
	clearflag FLAG_HIDE_SLATEPORT_CITY_STERNS_SHIPYARD_MR_BRINEY
	clearflag FLAG_UNKNOWN_0x393
	setvar VAR_0x8008, 7
	call Common_EventScript_SetGymTrainers
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS
	clearflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_STEVEN
	setvar VAR_MOSSDEEP_CITY_STATE, 1
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_STEVEN
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE, 1
	call MossdeepCity_Gym_EventScript_GiveCalmMind
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MossdeepCity_Gym_Text_RegisteredTateAndLiza, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_TATE_AND_LIZA_MATCH_CALL
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind2:: @ 8220937
	giveitem ITEM_TM04
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM04
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind:: @ 822095B
	giveitem ITEM_TM04
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_BagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM04
	return

MossdeepCity_Gym_EventScript_TateAndLizaRematch:: @ 822097E
	trainerbattle_rematch_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaPreRematch, MossdeepCity_Gym_Text_TateAndLizaRematchDefeat, MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostRematch, MSGBOX_AUTOCLOSE
	end

@ All the below switch scripts are leftover from RS and are functionally unused
MossdeepCity_Gym_EventScript_Switch1:: @ 8220999
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_ClearSwitch1
	setflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 5, 5, METATILE_RS_MossdeepGym_RedArrow_Right, 0
	setmetatile 2, 7, METATILE_RS_MossdeepGym_Switch_Down, 1
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed:: @ 82209C8
	special DrawWholeMapView
	playse SE_CLICK
	releaseall
	end

MossdeepCity_Gym_EventScript_ClearSwitch1:: @ 82209D0
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 5, 5, METATILE_RS_MossdeepGym_RedArrow_Left, 0
	setmetatile 2, 7, METATILE_RS_MossdeepGym_Switch_Up, 1
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch2:: @ 82209F5
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_ClearSwitch2
	setflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 8, 14, METATILE_RS_MossdeepGym_RedArrow_Right, 0
	setmetatile 8, 10, METATILE_RS_MossdeepGym_Switch_Down, 1
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch2:: @ 8220A24
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 8, 14, METATILE_RS_MossdeepGym_RedArrow_Down, 0
	setmetatile 8, 10, METATILE_RS_MossdeepGym_Switch_Up, 1
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch3:: @ 8220A49
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_ClearSwitch3
	setflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 15, 17, METATILE_RS_MossdeepGym_RedArrow_Left, 0
	setmetatile 17, 15, METATILE_RS_MossdeepGym_Switch_Down, 1
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch3:: @ 8220A78
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 15, 17, METATILE_RS_MossdeepGym_RedArrow_Right, 0
	setmetatile 17, 15, METATILE_RS_MossdeepGym_Switch_Up, 1
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch4:: @ 8220A9D
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_ClearSwitch4
	setflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 1, 23, METATILE_RS_MossdeepGym_RedArrow_Up, 0
	setmetatile 5, 24, METATILE_RS_MossdeepGym_Switch_Down, 1
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch4:: @ 8220ACC
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 1, 23, METATILE_RS_MossdeepGym_RedArrow_Right, 0
	setmetatile 5, 24, METATILE_RS_MossdeepGym_Switch_Up, 1
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_WarpToEntrance:: @ 8220AF1
	lockall
	warpmossdeepgym MAP_MOSSDEEP_CITY_GYM, 255, 7, 30
	waitstate
	releaseall
	end

MossdeepCity_Gym_EventScript_Preston:: @ 8220AFD
	trainerbattle_single TRAINER_PRESTON, MossdeepCity_Gym_Text_PrestonIntro, MossdeepCity_Gym_Text_PrestonDefeat
	msgbox MossdeepCity_Gym_Text_PrestonPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Virgil:: @ 8220B14
	trainerbattle_single TRAINER_VIRGIL, MossdeepCity_Gym_Text_VirgilIntro, MossdeepCity_Gym_Text_VirgilDefeat
	msgbox MossdeepCity_Gym_Text_VirgilPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Blake:: @ 8220B2B
	trainerbattle_single TRAINER_BLAKE, MossdeepCity_Gym_Text_BlakeIntro, MossdeepCity_Gym_Text_BlakeDefeat
	msgbox MossdeepCity_Gym_Text_BlakePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Hannah:: @ 8220B42
	trainerbattle_single TRAINER_HANNAH, MossdeepCity_Gym_Text_HannahIntro, MossdeepCity_Gym_Text_HannahDefeat
	msgbox MossdeepCity_Gym_Text_HannahPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Samantha:: @ 8220B59
	trainerbattle_single TRAINER_SAMANTHA, MossdeepCity_Gym_Text_SamanthaIntro, MossdeepCity_Gym_Text_SamanthaDefeat
	msgbox MossdeepCity_Gym_Text_SamanthaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Maura:: @ 8220B70
	trainerbattle_single TRAINER_MAURA, MossdeepCity_Gym_Text_MauraIntro, MossdeepCity_Gym_Text_MauraDefeat
	msgbox MossdeepCity_Gym_Text_MauraPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Sylvia:: @ 8220B87
	trainerbattle_single TRAINER_SYLVIA, MossdeepCity_Gym_Text_SylviaIntro, MossdeepCity_Gym_Text_SylviaDefeat
	msgbox MossdeepCity_Gym_Text_SylviaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nate:: @ 8220B9E
	trainerbattle_single TRAINER_NATE, MossdeepCity_Gym_Text_NateIntro, MossdeepCity_Gym_Text_NateDefeat
	msgbox MossdeepCity_Gym_Text_NatePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Macey:: @ 8220BB5
	trainerbattle_single TRAINER_MACEY, MossdeepCity_Gym_Text_MaceyIntro, MossdeepCity_Gym_Text_MaceyDefeat
	msgbox MossdeepCity_Gym_Text_MaceyPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Clifford:: @ 8220BCC
	trainerbattle_single TRAINER_CLIFFORD, MossdeepCity_Gym_Text_CliffordIntro, MossdeepCity_Gym_Text_CliffordDefeat
	msgbox MossdeepCity_Gym_Text_CliffordPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nicholas:: @ 8220BE3
	trainerbattle_single TRAINER_NICHOLAS, MossdeepCity_Gym_Text_NicholasIntro, MossdeepCity_Gym_Text_NicholasDefeat
	msgbox MossdeepCity_Gym_Text_NicholasPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Kathleen:: @ 8220BFA
	trainerbattle_single TRAINER_KATHLEEN, MossdeepCity_Gym_Text_KathleenIntro, MossdeepCity_Gym_Text_KathleenDefeat
	msgbox MossdeepCity_Gym_Text_KathleenPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_GymGuide:: @ 8220C11
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MOSSDEEP_GYM, MossdeepCity_Gym_EventScript_GymGuidePostVictory
	msgbox MossdeepCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_GymGuidePostVictory:: @ 8220C26
	msgbox MossdeepCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

@ Leftover from RS, functionally unused
MossdeepCity_Gym_Movement_WaitAfterSwitchUse: @ 8220C30
	delay_16
	delay_16
	step_end

MossdeepCity_Gym_EventScript_LeftGymStatue:: @ 8220C33
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_RightGymStatue:: @ 8220C43
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_GymStatueCertified:: @ 8220C53
	msgbox MossdeepCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_GymStatue:: @ 8220C5D
	msgbox MossdeepCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_YellowFloorSwitch:: @ 8220C67
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 0
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_BlueFloorSwitch:: @ 8220C7D
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 1
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_GreenFloorSwitch:: @ 8220C93
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 2
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_PurpleFloorSwitch:: @ 8220CA9
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 3
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_RedFloorSwitch:: @ 8220CBF
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 4
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_Text_GymGuideAdvice: @ 8220CD5
	.string "잘 있었나!!\n"
	.string "챔피언을 노리는 {PLAYER}!!\p"
	.string "이 체육관의 체육관 관장은\n"
	.string "에스퍼타입 포켓몬을 쓴다!\p"
	.string "격투타입이나 독타입\n"
	.string "포켓몬으로 도전했다가는\l"
	.string "굉장한 데미지를 입게 될 거야!\p"
	.string "게다가 끝내주는\n"
	.string "콤비네이션으로 공격해 오지!\p"
	.string "그러니까 너도 이기기 위해 포켓몬과의\n"
	.string "유대감을 용기내서 보여 줘!$"
	@ げんき しとぉや!!ｎ
	@ チャンピオンを めざす §あ!!ｐ
	@ このジムの ジムリ-ダ-はｎ
	@ エスパ-タイプの ポケモンつかい!ｐ
	@ かくとうタイプや どくタイプのｎ
	@ ポケモンで いどむとｌ
	@ ものすごい ダメ-ジを くらうぞ!ｐ
	@ しかも ばつぐんのｎ
	@ コンビネ-ションで せめてくる!ｐ
	@ だから きみも かつために ポケモンとのｎ
	@ きずなを きばって みせて やれ!

MossdeepCity_Gym_Text_GymGuidePostVictory: @ 8220E2A
	.string "이거 믿기질 않는걸!!\n"
	.string "넌 정말 엄청난 트레이너야!$"
	@ こりゃあ たまげた!!ｎ
	@ きみは すごか トレ-ナ-だ!

MossdeepCity_Gym_Text_PrestonIntro: @ 8220E5C
	.string "승부는 마음의 강함으로 결정된다\n"
	.string "마음이 약한 자는 이길 수 없다!$"
	@ しょうぶは こころの つよさで きまるｎ
	@ こころ よわき ものは かてない!

MossdeepCity_Gym_Text_PrestonDefeat: @ 8220EAC
	.string "져버렸군!\n"
	.string "나도 다시 단련해야겠어!$"
	@ まけたか!ｎ
	@ オレも きたえ なおさねばっ!

MossdeepCity_Gym_Text_PrestonPostBattle: @ 8220ED3
	.string "망설이는 쪽이 진다\n"
	.string "내가 해주는 충고다!$"
	@ まよった ほうが まけるｎ
	@ オレからの ちゅうこくだ!

MossdeepCity_Gym_Text_VirgilIntro: @ 8220F02
	.string "네 재능을 한번 보여 줘야겠다!$"
	@ キミの さいのうを みせて もらおうか!

MossdeepCity_Gym_Text_VirgilDefeat: @ 8220F1A
	.string "훌륭한 재능을 지녔군!$"
	@ すばらしい さいのうの もちぬしだ!

MossdeepCity_Gym_Text_VirgilPostBattle: @ 8220F3A
	.string "세상에 천재가 있다면\n"
	.string "이곳의 체육관 관장이 좋은 예시겠지...\p"
	.string "하지만 어쩌면 네 재능이\n"
	.string "더 위일지도 모르겠군...$"
	@ よのなかに てんさいが いるならばｎ
	@ ここの ジムリ-ダ-が そうだ……ｐ
	@ だが もしかすると キミの ほうがｎ
	@ さいのうは うえかも しれない……

MossdeepCity_Gym_Text_BlakeIntro: @ 8220FB0
	.string "후후후...\n"
	.string "염동력으로 몬스터볼을\l"
	.string "공중에 띄워 보이마...\p"
	.string "이야아아아아아압...!\p"
	.string "...... ...... ......\n"
	.string "...... ...... ......\p"
	.string "컨디션이 나쁠 때도 있다...$"
	@ ふふふ……ｎ
	@ ねんりきで モンスタ-ボ-ルをｌ
	@ くうちゅうに うかせて みせよう……ｐ
	@ うおおぉぉぉぉぉ……!ｐ
	@ …… …… ……ｎ
	@ …… …… ……ｐ
	@ ちょうしの わるい ときも ある……

MossdeepCity_Gym_Text_BlakeDefeat: @ 8221024
	.string "포켓몬 승부도\n"
	.string "컨디션이 나빠-!$"
	@ ポケモン しょうぶもｎ
	@ ちょうし わり-っ!

MossdeepCity_Gym_Text_BlakePostBattle: @ 8221055
	.string "몬스터볼은 너무 컸다\n"
	.string "이 먼지덩어리라면 반드시...\p"
	.string "후우우우우우우웁...!\p"
	.string "...... ...... ......\n"
	.string "...... ...... ......\p"
	.string "아니닷!\n"
	.string "콧바람으로 날린 게 아니란 말이다!$"
	@ モンスタ-ボ-ルは おおきすぎたｎ
	@ この わたぼこり なら ぜったいに……ｐ
	@ ふううううううっ……!ｐ
	@ …… …… ……ｎ
	@ …… …… ……ｐ
	@ ちがうぞ!ｎ
	@ はないきで とばして なんか いないぞ!

MossdeepCity_Gym_Text_HannahIntro: @ 82210EE
	.string "나한테 지더라도\n"
	.string "풀죽을 필요는 없어!\p"
	.string "네가 약한 게 아니라\n"
	.string "내가 너무 강한 거니까!$"
	@ あなたが アタシに まけた としてもｎ
	@ おちこまない ことね!ｐ
	@ あなたが よわい わけじゃ なくてｎ
	@ アタシが つよすぎる からよ!

MossdeepCity_Gym_Text_HannahDefeat: @ 8221152
	.string "넌 너무 강한 거 같아!$"
	@ あなたは さらに つよすぎた!

MossdeepCity_Gym_Text_HannahPostBattle: @ 822116A
	.string "졌다고 끙끙거리진 않을 거야\n"
	.string "더욱 수행하면 되는 거니까!\p"
	.string "긍정이야말로 나의 힘!$"
	@ まけたから って クヨクヨ しないわｎ
	@ もっと しゅぎょう すれば いいんだもの!ｐ
	@ まえむきな ところが アタシの とりえ!

MossdeepCity_Gym_Text_SamanthaIntro: @ 82211E2
	.string "보인다...\n"
	.string "너의 미래가 보여...\p"
	.string "날 이기면\n"
	.string "너의 미래를 가르쳐 줄게!$"
	@ みえる……ｎ
	@ あなたの みらいが みえる……ｐ
	@ わたくしに かてたらｎ
	@ あなたの みらいを おしえて あげる!

MossdeepCity_Gym_Text_SamanthaDefeat: @ 8221230
	.string "졌다...!$"
	@ まいりました……!

MossdeepCity_Gym_Text_SamanthaPostBattle: @ 822123D
	.string "너와 체육관 관장님의 승부...\n"
	.string "엄청나게 격렬한 전개...\p"
	.string "결과는...\n"
	.string "내 입으론 말할 수 없어...!$"
	@ あなたと ジムリ-ダ-さまの しょうぶ……ｎ
	@ ものすごく はげしい てんかい……ｐ
	@ けっかは……ｎ
	@ わたくしの くちからは いえない……!

MossdeepCity_Gym_Text_MauraIntro: @ 82212A6
	.string "네가 지금까지 밟아온 여정\n"
	.string "네가 겪어온 경험\p"
	.string "모든 것을 이용해 나에게 덤벼!$"
	@ あなたが これまで あゆんできた みちのりｎ
	@ あなたが けいけん してきた ことがらｐ
	@ すべてを ぶつけて きなさい!

MossdeepCity_Gym_Text_MauraDefeat: @ 8221309
	.string "훌륭한 여정이었구나...!$"
	@ すばらしい みちのり だわ……!

MossdeepCity_Gym_Text_MauraPostBattle: @ 822132E
	.string "노력한 자에겐 밝은 미래\n"
	.string "게으른 자에겐 절망적인 내일\p"
	.string "인과응보...\n"
	.string "모든 것은 자신에게 돌아오는 거야...$"
	@ がんばった ものには あかるい みらいがｎ
	@ なまけた ものには ぜつぼうの あしたがｐ
	@ いんがおうほう……ｎ
	@ すべては じぶんに はねかえる ものよ……

MossdeepCity_Gym_Text_SylviaIntro: @ 82213C2
	.string "목숨을 깎는 한이 있더라도\n"
	.string "이 승부는 이기겠어...!$"
	@ いのちを けずって でもｎ
	@ この しょうぶ かってみせるわ……!

MossdeepCity_Gym_Text_SylviaDefeat: @ 82213F4
	.string "당신\n"
	.string "무서운 짓을...$"
	@ あなたはｎ
	@ おそろしい ことを……

MossdeepCity_Gym_Text_SylviaPostBattle: @ 8221412
	.string "당신이 이겼어...\n"
	.string "무슨 일이 일어나도 난 몰라...!$"
	@ あたしに かったわね……ｎ
	@ なにが おきても しらないわよ……!

MossdeepCity_Gym_Text_NateIntro: @ 8221460
	.string "호호호\p"
	.string "강한 에스퍼타입 기술을\n"
	.string "당신에게 알려드리죠$"
	@ ほっほっほｐ
	@ エスパ-タイプの てごわさをｎ
	@ あなたに おしえて さしあげましょう

MossdeepCity_Gym_Text_NateDefeat: @ 82214A7
	.string "이 이건!\n"
	.string "굉장한 배틀 실력이군요$"
	@ こ これは これは!ｎ
	@ すばらしい たたかいかた ですな

MossdeepCity_Gym_Text_NatePostBattle: @ 82214D3
	.string "저 저는 아무리 져도\n"
	.string "꺾이지 않을 거예요$"
	@ わ わたくしは どんなに まけてもｎ
	@ とりみだしは しませんから

MossdeepCity_Gym_Text_KathleenIntro: @ 8221507
	.string "내 무서운 눈과 마주치다니\n"
	.string "해보자는 거냐!$"
	@ おそろしいめに あわせて やろうか-っ!

MossdeepCity_Gym_Text_KathleenDefeat: @ 822153B
	.string "싫어어엇!$"
	@ いやあああ-っ!

MossdeepCity_Gym_Text_KathleenPostBattle: @ 8221545
	.string "당신의 상태가 나빠질 거야\n"
	.string "빨리 나한테서 떨어져!$"
	@ あなたの げんきが うつるわｎ
	@ はやく いっちゃいなさいよ!

MossdeepCity_Gym_Text_CliffordIntro: @ 822157C
	.string "늙었다고 해서\n"
	.string "만만하게 보면 곤란하지요$"
	@ としより だからと いってｎ
	@ あまく みて もらっては こまりますよ

MossdeepCity_Gym_Text_CliffordDefeat: @ 82215B8
	.string "흘러넘치는 젊음을 느낍니다!$"
	@ あふれる わかさを かんじる!

MossdeepCity_Gym_Text_CliffordPostBattle: @ 82215E2
	.string "여기 체육관 관장도 그렇지요!\n"
	.string "젊고 발랄하답니다$"
	@ この ジムの リ-ダ-も そりゃもう!ｎ
	@ わかくて げんき はつらつ ですぞ

MossdeepCity_Gym_Text_MaceyIntro: @ 822161B
	.string "아직이야\n"
	.string "아직 체육관 관장과 만나게 두진 않겠어!$"
	@ まだよｎ
	@ まだ ジムリ-ダ-には あわせないわよ!

MossdeepCity_Gym_Text_MaceyDefeat: @ 8221658
	.string "잠깐! 뭐야 그 강함은!$"
	@ ちょっと! なんなの その つよさ!

MossdeepCity_Gym_Text_MaceyPostBattle: @ 8221680
	.string "흥 넌 강하지만\n"
	.string "에스퍼 스타일이 아냐!\l"
	.string "뭔가 배틀 방식이 거칠거든!$"
	@ フン あんたは つよいけどｎ
	@ エスパ-むき では ないわ!ｌ
	@ なんだか たたかいかたが がさつ だもん!

MossdeepCity_Gym_Text_NicholasIntro: @ 82216EE
	.string "우오옷! 내\n"
	.string "슈퍼포켓몬승부강한파워를\l"
	.string "받아라-!$"
	@ うぉ-っし! おれのｎ
	@ ス-パ-ポケモンしょうぶつよいパワ- をｌ
	@ うけて みろ-っ!

MossdeepCity_Gym_Text_NicholasDefeat: @ 822172D
	.string "당했다아아아!$"
	@ やられたあああ!

MossdeepCity_Gym_Text_NicholasPostBattle: @ 822173A
	.string "좋아! 다음엔\n"
	.string "스페셜포켓몬지고싶지않아파워도\l"
	.string "개발해 볼까?$"
	@ よし! つぎはｎ
	@ スペシャルポケモンまけないパワ- でもｌ
	@ かいはつ するかな?

MossdeepCity_Gym_Text_TateAndLizaIntro: @ 8221783
	.string "풍: 헤헤헤... 체육관 관장이\p"
	.string "란: 후후후... 체육관 관장이\p"
	.string "풍: 두 명이나 있어서 놀랐어?\n"
	.string "란: 두 명이나 있어서 놀랐어?\p"
	.string "풍: 우리는 쌍둥이!\n"
	.string "란: 우리는 쌍둥이!\p"
	.string "풍: 아무 말 하지 않아도\n"
	.string "란: 서로 무슨 생각을 하고 있는지\p"
	.string "풍: 머릿속에 떠오르니까\n"
	.string "란: 호흡을 척척 맞출 수가 있지!\p"
	.string "풍: 그런 우리들의 콤비네이션을\n"
	.string "란: 네가 깨뜨릴 수 있을까?$"
	@ フウ『へへへ…… ジムリ-ダ-がｐ
	@ ラン『ふふふ…… ジムリ-ダ-がｐ
	@ フウ『ふたりも いるんで おどろいた?ｎ
	@ ラン『ふたりも いるんで おどろいた?ｐ
	@ フウ『ぼくたち ふたご!ｎ
	@ ラン『あたしたち ふたご!ｐ
	@ フウ『なにも ことばに しなくてもｎ
	@ ラン『おたがいの かんがえて いることがｐ
	@ フウ『あたまの なかに うかぶからｎ
	@ ラン『つうじあうことが できるのヨ!ｐ
	@ フウ『そんな ぼくたちの コンビネ-ションｎ
	@ ラン『きみに やぶることが できる?

MossdeepCity_Gym_Text_TateAndLizaDefeat: @ 82218EC
	.string "풍: 우 우리들의\n"
	.string "란: 콤비네이션이...!\p"
	.string "풍: 졌으니까 어쩔 수 없지\n"
	.string "란: 패배를 인정하고 이걸 줄게!$"
	@ フウ『ぼっ ぼくたちのｎ
	@ ラン『コンビネ-ションが……!ｐ
	@ フウ『やぶれた からには しかたないｎ
	@ ラン『まけを みとめて これを あげるヨ!

MossdeepCity_Gym_Text_ReceivedMindBadge: @ 822196A
	.string "{PLAYER}{K_EUNNEUN} 풍&란에게서\n"
	.string "마인드배지를 받았다!$"
	@ §あは フウと ランからｎ
	@ マインドバッジを もらった!

MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis: @ 8221999
	.string "풍: 마인드배지엔 포켓몬의\n"
	.string "특수공격과 특수방어를 올리는\l"
	.string "효과가 담겨 있어!\p"
	.string "란: 게다가 다이빙이라고 하는\n"
	.string "비전머신도 사용할 수 있게 되지!\p"
	.string "풍: 그리고 이것도 가져가!$"
	@ フウ『マインドバッジには ポケモンのｎ
	@ とくこうと とくぼうを たかめるｌ
	@ こうかが ひめられている!ｐ
	@ ラン『それから ダイビング というｎ
	@ ひでんわざも つかえるように なるヨ!ｐ
	@ フウ『あと これも もっていきなよ!

MossdeepCity_Gym_Text_ExplainCalmMind: @ 8221A40
	.string "풍: 그 기술머신04에는\n"
	.string "란: 명상이 들어 있어!\p"
	.string "풍: 포켓몬의 특수공격과\n"
	.string "란: 포켓몬의 특수방어를\p"
	.string "풍: 올려주는 기술이야!\n"
	.string "란: 에스퍼포켓몬에게 딱이지!\p"
	.string "...... ...... ......$"
	@ フウ『その わざマシン04にはｎ
	@ ラン『めいそうが はいってるヨ!ｐ
	@ フウ『ポケモンの とくこうとｎ
	@ ラン『ポケモンの とくぼうをｐ
	@ フウ『たかめてくれる わざ なんだ!ｎ
	@ ラン『エスパ-ポケモンに ぴったりだヨ!ｐ
	@ …… …… ……

MossdeepCity_Gym_Text_RegisteredTateAndLiza: @ 8221AEA
	.string "체육관 관장 풍&란을\n"
	.string "포켓내비에 등록했다!$"
	@ ジムリ-ダ- フウとランをｎ
	@ ポケナビに とうろく した!

MossdeepCity_Gym_Text_TateAndLizaPostBattle: @ 8221B1D
	.string "풍: 남매의 유대감보다\n"
	.string "너와 포켓몬의 유대감이\l"
	.string "훨씬 더 강했나봐...\p"
	.string "란: 넌 분명 더 강해질 거야!\n"
	.string "배틀했으니까 우린 알 수 있어!$"
	@ フウ『きょうだいの きずな よりｎ
	@ きみと ポケモンとの きずなの ほうがｌ
	@ はるかに つよかった みたいだね……ｐ
	@ ラン『あなたなら もっと つよくなれる!ｎ
	@ たたかった あたしたちには わかるわ!

MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons: @ 8221BCE
	.string "풍: 헤헤헤... 체육관 관장이\p"
	.string "란: 두 명이나 있어서 놀랐어?\p"
	.string "풍: 어라? 싸울 수 있는 포켓몬이\n"
	.string "란: 한 마리밖에 없어!\p"
	.string "풍: 그러면 배틀할 수 없어!\n"
	.string "란: 승부를 하고 싶다면\l"
	.string "더 포켓몬을 데려와!$"
	@ フウ『へへへ…… ジムリ-ダ-がｐ
	@ ラン『ふたりも いるんで おどろいた?ｐ
	@ フウ『あら? たたかえる ポケモンがｎ
	@ ラン『いっぴき しか いないヨ!ｐ
	@ フウ『それでは たたかえないね!ｎ
	@ ラン『しょうぶを たのしみたいからｌ
	@ もっと ポケモン つれてきてヨ!

MossdeepCity_Gym_Text_GymStatue: @ 8221CB0
	.string "이끼시티 포켓몬체육관$"
	@ トクサネシティ ポケモンジム

MossdeepCity_Gym_Text_GymStatueCertified: @ 8221CCA
	.string "이끼시티 포켓몬체육관\p"
	.string "풍 란 인정 트레이너!\n"
	.string "{PLAYER}$"
	@ トクサネシティ ポケモンジムｐ
	@ フウ ラン にんてい トレ-ナ-!ｎ
	@ §あ

MossdeepCity_Gym_Text_TateAndLizaPreRematch: @ 8221D0B
	.string "풍: 포켓몬은...\n"
	.string "란: 포켓몬은...\p"
	.string "풍: 조합을 바꾸면\n"
	.string "란: 배틀 방법도 바뀌지\p"
	.string "풍: 하지만 나는...\n"
	.string "란: 하지만 나는...\p"
	.string "풍: 언제나 란과 함께 있어!\n"
	.string "란: 언제나 풍과 함께 있지!\p"
	.string "풍: 우리들의 콤비네이션\n"
	.string "란: 몇 번이고 보여줄게!$"
	@ フウ『ポケモンは……ｎ
	@ ラン『ポケモンは……ｐ
	@ フウ『くみあわせを かえるとｎ
	@ ラン『たたかいかたも かわるよねｐ
	@ フウ『でも ぼくは……ｎ
	@ ラン『でも あたしは……ｐ
	@ フウ『いつでも ランと いっしょ!ｎ
	@ ラン『いつでも フウと いっしょ!ｐ
	@ フウ『ぼくたちの コンビネ-ションｎ
	@ ラン『なんどでも みせて あげるわ!

MossdeepCity_Gym_Text_TateAndLizaRematchDefeat: @ 8221E05
	.string "풍: 너와 포켓몬은\n"
	.string "란: 마치 형제 같아!$"
	@ フウ『きみと ポケモンってｎ
	@ ラン『まるで きょうだい みたい!

MossdeepCity_Gym_Text_TateAndLizaPostRematch: @ 8221E45
	.string "풍: 몇 번이나 쓰러져도\n"
	.string "다시 일어설 거야!\p"
	.string "란: 왜냐하면 우리 둘은\n"
	.string "힘을 합쳐서 힘낼 거니까!$"
	@ フウ『なんど たおされたってｎ
	@ また たちなおって みせるからね!ｐ
	@ ラン『だって あたしたち ふたりｎ
	@ ちからを あわせて がんばれるもの!

MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons: @ 8221EB8
	.string "풍: 또 우리들과...\n"
	.string "란: 또 우리들과...\p"
	.string "풍: 승부하러 온 거구나\n"
	.string "란: 승부하러 온 거구나\p"
	.string "풍: 하지만...\n"
	.string "란: 너 싸울 수 있는 포켓몬이\p"
	.string "풍: 한 마리밖에 없어!\n"
	.string "란: 한 마리밖에 없네!\p"
	.string "풍: 가능하면 2마리 이상의\n"
	.string "란: 포켓몬을 데리고 오도록 해!$"
	@ フウ『また ぼくたちと……ｎ
	@ ラン『また あたしたちと……ｐ
	@ フウ『しょうぶを しに きてくれたんだねｎ
	@ ラン『しょうぶを しに きてくれたんだねｐ
	@ フウ『でも……ｎ
	@ ラン『あなた たたかえる ポケモンをｐ
	@ フウ『1ひきしか もって いないよ!ｎ
	@ ラン『1ひきしか もって いないわ!ｐ
	@ フウ『できれば 2ひき いじょうのｎ
	@ ラン『ポケモンを もって また きてね!
