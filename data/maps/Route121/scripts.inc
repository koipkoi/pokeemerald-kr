.set LOCALID_GRUNT_1, 12
.set LOCALID_GRUNT_2, 13
.set LOCALID_GRUNT_3, 14

Route121_MapScripts:: @ 81F5DFC
	.byte 0

Route121_EventScript_Woman:: @ 81F5DFD
	msgbox Route121_Text_AheadLoomsMtPyre, MSGBOX_NPC
	end

Route121_EventScript_MtPyrePierSign:: @ 81F5E06
	msgbox Route121_Text_MtPyrePierSign, MSGBOX_SIGN
	end

Route121_EventScript_SafariZoneSign:: @ 81F5E0F
	msgbox Route121_Text_SafariZoneSign, MSGBOX_SIGN
	end

Route121_EventScript_AquaGruntsMoveOut:: @ 81F5E18
	lockall
	playbgm MUS_ENCOUNTER_AQUA, 0
	applymovement LOCALID_GRUNT_2, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox Route121_Text_OkayMoveOutToMtPyre, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_1, Route121_Movement_Grunt1Exit
	applymovement LOCALID_GRUNT_2, Route121_Movement_Grunt2Exit
	applymovement LOCALID_GRUNT_3, Route121_Movement_Grunt3Exit
	waitmovement 0
	fadedefaultbgm
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	removeobject LOCALID_GRUNT_3
	setvar VAR_ROUTE121_STATE, 1
	releaseall
	end

Route121_Movement_Grunt1Exit: @ 81F5E59
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route121_Movement_Grunt2Exit: @ 81F5E62
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route121_Movement_Grunt3Exit: @ 81F5E6B
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route121_EventScript_Vanessa:: @ 81F5E74
	trainerbattle_single TRAINER_VANESSA, Route121_Text_VanessaIntro, Route121_Text_VanessaDefeat
	msgbox Route121_Text_VanessaPostBattle, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_Walter:: @ 81F5E8B
	trainerbattle_single TRAINER_WALTER_1, Route121_Text_WalterIntro, Route121_Text_WalterDefeat, Route121_EventScript_RegisterWalter
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route121_EventScript_RematchWalter
	msgbox Route121_Text_WalterPostBattle, MSGBOX_DEFAULT
	release
	end

Route121_EventScript_RegisterWalter:: @ 81F5EB7
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route121_Text_WalterRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_WALTER_1
	release
	end

Route121_EventScript_RematchWalter:: @ 81F5ED6
	trainerbattle_rematch TRAINER_WALTER_1, Route121_Text_WalterRematchIntro, Route121_Text_WalterRematchDefeat
	msgbox Route121_Text_WalterPostRematch, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_Tammy:: @ 81F5EED
	trainerbattle_single TRAINER_TAMMY, Route121_Text_TammyIntro, Route121_Text_TammyDefeat
	msgbox Route121_Text_TammyPostBattle, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_Kate:: @ 81F5F04
	trainerbattle_double TRAINER_KATE_AND_JOY, Route121_Text_KateIntro, Route121_Text_KateDefeat, Route121_Text_KateNotEnoughMons
	msgbox Route121_Text_KatePostBattle, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_Joy:: @ 81F5F1F
	trainerbattle_double TRAINER_KATE_AND_JOY, Route121_Text_JoyIntro, Route121_Text_JoyDefeat, Route121_Text_JoyNotEnoughMons
	msgbox Route121_Text_JoyPostBattle, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_Jessica:: @ 81F5F3A
	trainerbattle_single TRAINER_JESSICA_1, Route121_Text_JessicaIntro, Route121_Text_JessicaDefeat, Route121_EventScript_RegisterJessica
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route121_EventScript_RematchJessica
	msgbox Route121_Text_JessicaPostBattle, MSGBOX_DEFAULT
	release
	end

Route121_EventScript_RegisterJessica:: @ 81F5F66
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route121_Text_JessicaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JESSICA_1
	release
	end

Route121_EventScript_RematchJessica:: @ 81F5F85
	trainerbattle_rematch TRAINER_JESSICA_1, Route121_Text_JessicaRematchIntro, Route121_Text_JessicaRematchDefeat
	msgbox Route121_Text_JessicaPostRematch, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_Cale:: @ 81F5F9C
	trainerbattle_single TRAINER_CALE, Route121_Text_CaleIntro, Route121_Text_CaleDefeat
	msgbox Route121_Text_CalePostBattle, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_Myles:: @ 81F5FB3
	trainerbattle_single TRAINER_MYLES, Route121_Text_MylesIntro, Route121_Text_MylesDefeat
	msgbox Route121_Text_MylesPostBattle, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_Pat:: @ 81F5FCA
	trainerbattle_single TRAINER_PAT, Route121_Text_PatIntro, Route121_Text_PatDefeat
	msgbox Route121_Text_PatPostBattle, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_Marcel:: @ 81F5FE1
	trainerbattle_single TRAINER_MARCEL, Route121_Text_MarcelIntro, Route121_Text_MarcelDefeat
	msgbox Route121_Text_MarcelPostBattle, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_Cristin:: @ 81F5FF8
	trainerbattle_single TRAINER_CRISTIN_1, Route121_Text_CristinIntro, Route121_Text_CristinDefeat, Route121_EventScript_RegisterCristin
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route121_EventScript_RematchCristin
	msgbox Route121_Text_CristinPostBattle, MSGBOX_DEFAULT
	release
	end

Route121_EventScript_RegisterCristin:: @ 81F6024
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route121_Text_CristinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CRISTIN_1
	release
	end

Route121_EventScript_RematchCristin:: @ 81F6043
	trainerbattle_rematch TRAINER_CRISTIN_1, Route121_Text_CristinRematchIntro, Route121_Text_CristinRematchDefeat
	msgbox Route121_Text_CristinPostRematch, MSGBOX_AUTOCLOSE
	end

Route121_Text_OkayMoveOutToMtPyre: @ 81F605A
	.string "좋아!\n"
	.string "우리들도 송화산으로 간다!$"
	@ よし!ｎ
	@ おれたちも おくりびやまに むかうぞ!

Route121_Text_AheadLoomsMtPyre: @ 81F607F
	.string "이 앞에 있는 것은 송화산...\p"
	.string "수명이 다한 포켓몬들의\n"
	.string "영혼을 추모하는 곳...$"
	@ このさきに あるのは おくりびやま……ｐ
	@ じゅみょうを おえた ポケモンたちのｎ
	@ たましいが まつられる ところ……

Route121_Text_MtPyrePierSign: @ 81F60D3
	.string "송화산 잔교\p"
	.string "...오랫동안 사용되지 않았는지\n"
	.string "글자가 거의 보이지 않는다$"
	@ おくりびやま さんばしｐ
	@ ……ながい あいだ つかわれて いないのかｎ
	@ もじが きえそうに なっている

Route121_Text_SafariZoneSign: @ 81F611E
	.string "희귀한 포켓몬이 잔뜩!\n"
	.string "“사파리존”$"
	@ めずらしい ポケモン たくさん!ｎ
	@ 「サファリゾ-ン」

