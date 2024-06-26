Route110_TrickHousePuzzle3_MapScripts:: @ 826BED8
	map_script MAP_SCRIPT_ON_RESUME, Route110_TrickHousePuzzle3_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle3_OnTransition
	.byte 0

Route110_TrickHousePuzzle3_OnResume: @ 826BEE3
	call Route110_TrickHousePuzzle3_EventScript_UpdateButtonMetatiles
	compare VAR_TEMP_9, 0
	call_if_eq Route110_TrickHousePuzzle3_EventScript_SetDoorsState0
	compare VAR_TEMP_9, 1
	call_if_eq Route110_TrickHousePuzzle3_EventScript_SetDoorsState1
	end

Route110_TrickHousePuzzle3_OnTransition: @ 826BEFF
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_3, 0
	setvar VAR_TEMP_4, 0
	setvar VAR_TEMP_8, 0
	setvar VAR_TEMP_9, 0
	end

Route110_TrickHousePuzzle3_EventScript_UpdateButtonMetatiles:: @ 826BF1E
	setmetatile 4, 14, METATILE_TrickHousePuzzle_Button_Up, 0
	setmetatile 3, 11, METATILE_TrickHousePuzzle_Button_Up, 0
	setmetatile 12, 5, METATILE_TrickHousePuzzle_Button_Up, 0
	setmetatile 8, 2, METATILE_TrickHousePuzzle_Button_Up, 0
	compare VAR_TEMP_8, 1
	call_if_eq Route110_TrickHousePuzzle3_EventScript_PressedButton1Metatile
	compare VAR_TEMP_8, 2
	call_if_eq Route110_TrickHousePuzzle3_EventScript_PressedButton2Metatile
	compare VAR_TEMP_8, 3
	call_if_eq Route110_TrickHousePuzzle3_EventScript_PressedButton3Metatile
	compare VAR_TEMP_8, 4
	call_if_eq Route110_TrickHousePuzzle3_EventScript_PressedButton4Metatile
	return

Route110_TrickHousePuzzle3_EventScript_PressedButton1Metatile:: @ 826BF6F
	setmetatile 4, 14, METATILE_TrickHousePuzzle_Button_Pressed, 0
	return

Route110_TrickHousePuzzle3_EventScript_PressedButton2Metatile:: @ 826BF79
	setmetatile 3, 11, METATILE_TrickHousePuzzle_Button_Pressed, 0
	return

Route110_TrickHousePuzzle3_EventScript_PressedButton3Metatile:: @ 826BF83
	setmetatile 12, 5, METATILE_TrickHousePuzzle_Button_Pressed, 0
	return

Route110_TrickHousePuzzle3_EventScript_PressedButton4Metatile:: @ 826BF8D
	setmetatile 8, 2, METATILE_TrickHousePuzzle_Button_Pressed, 0
	return

Route110_TrickHousePuzzle3_EventScript_SetDoorsState0:: @ 826BF97
	setmetatile 1, 6, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile0, 0
	setmetatile 2, 6, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile1, 0
	setmetatile 1, 7, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile2, 0
	setmetatile 2, 7, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile3, 0
	setmetatile 1, 9, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile0, 0
	setmetatile 2, 9, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile1, 0
	setmetatile 1, 10, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile2, 0
	setmetatile 2, 10, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile3, 0
	setmetatile 4, 15, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile0, 0
	setmetatile 5, 15, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile1, 0
	setmetatile 4, 16, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile2, 0
	setmetatile 5, 16, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile3, 0
	setmetatile 13, 9, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile0, 0
	setmetatile 14, 9, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile1, 0
	setmetatile 13, 10, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile2, 0
	setmetatile 14, 10, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile3, 0
	setmetatile 13, 15, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile0, 0
	setmetatile 14, 15, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile1, 0
	setmetatile 13, 16, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile2, 0
	setmetatile 14, 16, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile3, 0
	setmetatile 3, 7, METATILE_TrickHousePuzzle_BlueDoorV_Retracted, 1
	setmetatile 3, 8, METATILE_TrickHousePuzzle_Floor_ShadowTop, 0
	setmetatile 3, 13, METATILE_TrickHousePuzzle_BlueDoorV_Retracted, 1
	setmetatile 3, 14, METATILE_TrickHousePuzzle_Floor_ShadowTop, 0
	setmetatile 6, 4, METATILE_TrickHousePuzzle_BlueDoorV_Retracted, 1
	setmetatile 6, 5, METATILE_TrickHousePuzzle_Floor_ShadowTop, 0
	setmetatile 9, 16, METATILE_TrickHousePuzzle_BlueDoorV_Retracted, 1
	setmetatile 9, 17, METATILE_TrickHousePuzzle_Floor_ShadowTop, 0
	setmetatile 12, 7, METATILE_TrickHousePuzzle_BlueDoorV_Retracted, 1
	setmetatile 12, 8, METATILE_TrickHousePuzzle_Floor_ShadowTop, 0
	setmetatile 1, 3, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile0, 0
	setmetatile 2, 3, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile1, 0
	setmetatile 1, 4, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile2, 1
	setmetatile 2, 4, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile3, 1
	setmetatile 1, 12, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile0, 0
	setmetatile 2, 12, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile1, 0
	setmetatile 1, 13, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile2, 1
	setmetatile 2, 13, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile3, 1
	setmetatile 4, 6, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile0, 0
	setmetatile 5, 6, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile1, 0
	setmetatile 4, 7, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile2, 1
	setmetatile 5, 7, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile3, 1
	setmetatile 4, 12, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile0, 0
	setmetatile 5, 12, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile1, 0
	setmetatile 4, 13, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile2, 1
	setmetatile 5, 13, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile3, 1
	setmetatile 4, 18, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile0, 0
	setmetatile 5, 18, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile1, 0
	setmetatile 4, 19, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile2, 1
	setmetatile 5, 19, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile3, 1
	setmetatile 7, 9, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile0, 0
	setmetatile 8, 9, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile1, 0
	setmetatile 7, 10, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile2, 1
	setmetatile 8, 10, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile3, 1
	setmetatile 10, 6, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile0, 0
	setmetatile 11, 6, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile1, 0
	setmetatile 10, 7, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile2, 1
	setmetatile 11, 7, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile3, 1
	setmetatile 10, 12, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile0, 0
	setmetatile 11, 12, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile1, 0
	setmetatile 10, 13, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile2, 1
	setmetatile 11, 13, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile3, 1
	setmetatile 10, 18, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile0, 0
	setmetatile 11, 18, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile1, 0
	setmetatile 10, 19, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile2, 1
	setmetatile 11, 19, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile3, 1
	setmetatile 13, 3, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile0, 0
	setmetatile 14, 3, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile1, 0
	setmetatile 13, 4, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile2, 1
	setmetatile 14, 4, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile3, 1
	setmetatile 3, 16, METATILE_TrickHousePuzzle_RedDoorV_Open0, 1
	setmetatile 3, 17, METATILE_TrickHousePuzzle_RedDoorV_Open1, 1
	setmetatile 9, 4, METATILE_TrickHousePuzzle_RedDoorV_Open0, 1
	setmetatile 9, 5, METATILE_TrickHousePuzzle_RedDoorV_Open1, 1
	return

Route110_TrickHousePuzzle3_EventScript_SetDoorsState1:: @ 826C232
	setmetatile 1, 6, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile0, 0
	setmetatile 2, 6, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile1, 0
	setmetatile 1, 7, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile2, 1
	setmetatile 2, 7, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile3, 1
	setmetatile 1, 9, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile0, 0
	setmetatile 2, 9, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile1, 0
	setmetatile 1, 10, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile2, 1
	setmetatile 2, 10, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile3, 1
	setmetatile 4, 15, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile0, 0
	setmetatile 5, 15, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile1, 0
	setmetatile 4, 16, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile2, 1
	setmetatile 5, 16, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile3, 1
	setmetatile 13, 9, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile0, 0
	setmetatile 14, 9, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile1, 0
	setmetatile 13, 10, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile2, 1
	setmetatile 14, 10, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile3, 1
	setmetatile 13, 15, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile0, 0
	setmetatile 14, 15, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile1, 0
	setmetatile 13, 16, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile2, 1
	setmetatile 14, 16, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile3, 1
	setmetatile 3, 7, METATILE_TrickHousePuzzle_BlueDoorV_Open0, 1
	setmetatile 3, 8, METATILE_TrickHousePuzzle_BlueDoorV_Open1, 1
	setmetatile 3, 13, METATILE_TrickHousePuzzle_BlueDoorV_Open0, 1
	setmetatile 3, 14, METATILE_TrickHousePuzzle_BlueDoorV_Open1, 1
	setmetatile 6, 4, METATILE_TrickHousePuzzle_BlueDoorV_Open0, 1
	setmetatile 6, 5, METATILE_TrickHousePuzzle_BlueDoorV_Open1, 1
	setmetatile 9, 16, METATILE_TrickHousePuzzle_BlueDoorV_Open0, 1
	setmetatile 9, 17, METATILE_TrickHousePuzzle_BlueDoorV_Open1, 1
	setmetatile 12, 7, METATILE_TrickHousePuzzle_BlueDoorV_Open0, 1
	setmetatile 12, 8, METATILE_TrickHousePuzzle_BlueDoorV_Open1, 1
	setmetatile 1, 3, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile0, 0
	setmetatile 2, 3, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile1, 0
	setmetatile 1, 4, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile2, 0
	setmetatile 2, 4, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile3, 0
	setmetatile 1, 12, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile0, 0
	setmetatile 2, 12, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile1, 0
	setmetatile 1, 13, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile2, 0
	setmetatile 2, 13, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile3, 0
	setmetatile 4, 6, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile0, 0
	setmetatile 5, 6, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile1, 0
	setmetatile 4, 7, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile2, 0
	setmetatile 5, 7, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile3, 0
	setmetatile 4, 12, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile0, 0
	setmetatile 5, 12, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile1, 0
	setmetatile 4, 13, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile2, 0
	setmetatile 5, 13, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile3, 0
	setmetatile 4, 18, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile0, 0
	setmetatile 5, 18, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile1, 0
	setmetatile 4, 19, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile2, 0
	setmetatile 5, 19, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile3, 0
	setmetatile 7, 9, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile0, 0
	setmetatile 8, 9, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile1, 0
	setmetatile 7, 10, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile2, 0
	setmetatile 8, 10, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile3, 0
	setmetatile 10, 6, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile0, 0
	setmetatile 11, 6, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile1, 0
	setmetatile 10, 7, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile2, 0
	setmetatile 11, 7, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile3, 0
	setmetatile 10, 12, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile0, 0
	setmetatile 11, 12, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile1, 0
	setmetatile 10, 13, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile2, 0
	setmetatile 11, 13, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile3, 0
	setmetatile 10, 18, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile0, 0
	setmetatile 11, 18, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile1, 0
	setmetatile 10, 19, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile2, 0
	setmetatile 11, 19, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile3, 0
	setmetatile 13, 3, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile0, 0
	setmetatile 14, 3, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile1, 0
	setmetatile 13, 4, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile2, 0
	setmetatile 14, 4, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile3, 0
	setmetatile 3, 16, METATILE_TrickHousePuzzle_RedDoorV_Retracted, 1
	setmetatile 3, 17, METATILE_TrickHousePuzzle_Floor_ShadowTop_Alt, 0
	setmetatile 9, 4, METATILE_TrickHousePuzzle_RedDoorV_Retracted, 1
	setmetatile 9, 5, METATILE_TrickHousePuzzle_Floor_ShadowTop_Alt, 0
	return

Route110_TrickHousePuzzle3_EventScript_Button1:: @ 826C4CD
	lockall
	setvar VAR_TEMP_8, 1
	goto Route110_TrickHousePuzzle3_EventScript_PressButton
	end

Route110_TrickHousePuzzle3_EventScript_Button2:: @ 826C4D9
	lockall
	setvar VAR_TEMP_8, 2
	goto Route110_TrickHousePuzzle3_EventScript_PressButton
	end

Route110_TrickHousePuzzle3_EventScript_Button3:: @ 826C4E5
	lockall
	setvar VAR_TEMP_8, 3
	goto Route110_TrickHousePuzzle3_EventScript_PressButton
	end

Route110_TrickHousePuzzle3_EventScript_Button4:: @ 826C4F1
	lockall
	setvar VAR_TEMP_8, 4
	goto Route110_TrickHousePuzzle3_EventScript_PressButton
	end

Route110_TrickHousePuzzle3_EventScript_PressButton:: @ 826C4FD
	call Route110_TrickHousePuzzle3_EventScript_SetButton
	playse SE_PIN
	call Route110_TrickHousePuzzle3_EventScript_UpdateButtonMetatiles
	goto Route110_TrickHousePuzzle3_EventScript_AlternateDoors
	end

Route110_TrickHousePuzzle3_EventScript_SetButton:: @ 826C510
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_3, 0
	setvar VAR_TEMP_4, 0
	compare VAR_TEMP_8, 1
	call_if_eq Route110_TrickHousePuzzle3_EventScript_SetButton1
	compare VAR_TEMP_8, 2
	call_if_eq Route110_TrickHousePuzzle3_EventScript_SetButton2
	compare VAR_TEMP_8, 3
	call_if_eq Route110_TrickHousePuzzle3_EventScript_SetButton3
	compare VAR_TEMP_8, 4
	call_if_eq Route110_TrickHousePuzzle3_EventScript_SetButton4
	return

Route110_TrickHousePuzzle3_EventScript_SetButton1:: @ 826C551
	setvar VAR_TEMP_1, 1
	return

Route110_TrickHousePuzzle3_EventScript_SetButton2:: @ 826C557
	setvar VAR_TEMP_2, 1
	return

Route110_TrickHousePuzzle3_EventScript_SetButton3:: @ 826C55D
	setvar VAR_TEMP_3, 1
	return

Route110_TrickHousePuzzle3_EventScript_SetButton4:: @ 826C563
	setvar VAR_TEMP_4, 1
	return

Route110_TrickHousePuzzle3_EventScript_AlternateDoors:: @ 826C569
	compare VAR_TEMP_9, 1
	call_if_eq Route110_TrickHousePuzzle3_EventScript_SetDoorsState0
	compare VAR_TEMP_9, 0
	call_if_eq Route110_TrickHousePuzzle3_EventScript_SetDoorsState1
	special DrawWholeMapView
	compare VAR_TEMP_9, 1
	goto_if_eq Route110_TrickHousePuzzle3_EventScript_ClearAltDoorState
	compare VAR_TEMP_9, 0
	goto_if_eq Route110_TrickHousePuzzle3_EventScript_SetAltDoorState
	end

Route110_TrickHousePuzzle3_EventScript_ClearAltDoorState:: @ 826C599
	setvar VAR_TEMP_9, 0
	releaseall
	end

Route110_TrickHousePuzzle3_EventScript_SetAltDoorState:: @ 826C5A0
	setvar VAR_TEMP_9, 1
	releaseall
	end

Route110_TrickHousePuzzle3_EventScript_Scroll:: @ 826C5A7
	lockall
	compare VAR_TRICK_HOUSE_PUZZLE_3_STATE, 0
	goto_if_eq Route110_TrickHousePuzzle3_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle3_EventScript_FoundScroll:: @ 826C5B9
	setvar VAR_TRICK_HOUSE_PUZZLE_3_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle3_EventScript_Justin:: @ 826C5C4
	trainerbattle_single TRAINER_JUSTIN, Route110_TrickHousePuzzle3_Text_JustinIntro, Route110_TrickHousePuzzle3_Text_JustinDefeat
	msgbox Route110_TrickHousePuzzle3_Text_JustinPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle3_EventScript_Martha:: @ 826C5DB
	trainerbattle_single TRAINER_MARTHA, Route110_TrickHousePuzzle3_Text_MarthaIntro, Route110_TrickHousePuzzle3_Text_MarthaDefeat
	msgbox Route110_TrickHousePuzzle3_Text_MarthaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle3_EventScript_Alan:: @ 826C5F2
	trainerbattle_single TRAINER_ALAN, Route110_TrickHousePuzzle3_Text_AlanIntro, Route110_TrickHousePuzzle3_Text_AlanDefeat
	msgbox Route110_TrickHousePuzzle3_Text_AlanPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle3_Text_WroteSecretCodeLockOpened: @ 826C609
	.string "{PLAYER}{K_EUNNEUN} 암호를\n"
	.string "문에 적었다!\p"
	.string "“미궁대왕님 존경해”\p"
	.string "...... ...... ......\p"
	.string "문의 자물쇠가 풀렸다!$"
	@ §あは あいことばをｎ
	@ とびらに かきつけた!ｐ
	@ 「カラクリだいおう さま あこがれ」ｐ
	@ …… …… ……ｐ
	@ かぎの はずれる おとがした!

Route110_TrickHousePuzzle3_Text_JustinIntro: @ 826C676
	.string "몇 번이고 같은 곳으로\n"
	.string "돌아와버려-!$"
	@ なんども おなじ ところにｎ
	@ もどって きちゃうよ-!

Route110_TrickHousePuzzle3_Text_JustinDefeat: @ 826C69D
	.string "내가 곤란해하고 있는데\n"
	.string "확실하게 이겨버리다니 너무해-!$"
	@ ぼくが こまってるのにｎ
	@ ダメおしで かつなんて ひどいよ-!

Route110_TrickHousePuzzle3_Text_JustinPostBattle: @ 826C6E6
	.string "문투성이라서\n"
	.string "좁고 무섭다고-!$"
	@ とびら だらけでｎ
	@ せまくて こわいよ-!

Route110_TrickHousePuzzle3_Text_MarthaIntro: @ 826C726
	.string "뭐가 뭔지 모르겠어서\n"
	.string "슬퍼지기 시작했어...$"
	@ なにが なんだか わからなくてｎ
	@ かなしく なってきたわ……

Route110_TrickHousePuzzle3_Text_MarthaDefeat: @ 826C763
	.string "너 너무해...$"
	@ ひっ ひどいわ……

Route110_TrickHousePuzzle3_Text_MarthaPostBattle: @ 826C776
	.string "당연히 나는 약한 데다가\n"
	.string "방향치라고-!$"
	@ どうせ あたしは よわいしｎ
	@ ほうこうおんちよ-!

Route110_TrickHousePuzzle3_Text_AlanIntro: @ 826C7AA
	.string "대체 뭘 위해서\n"
	.string "이런 저택이 있는 거지...?$"
	@ いったい なんの ためにｎ
	@ こんな やしきが あるんだろう……?

Route110_TrickHousePuzzle3_Text_AlanDefeat: @ 826C7EC
	.string "대체 왜\n"
	.string "내가 진 거지...?$"
	@ いったい なぜｎ
	@ わしは まけて しまったんだろう……?

Route110_TrickHousePuzzle3_Text_AlanPostBattle: @ 826C80C
	.string "대체 이 저택에는\n"
	.string "얼마나 많은 장치가 있는 거지...?\p"
	.string "자네라면 알지도 모르겠군$"
	@ いったい どれくらいの しかけがｎ
	@ この やしきに あるんだろう…?ｐ
	@ きみなら わかるかもな

