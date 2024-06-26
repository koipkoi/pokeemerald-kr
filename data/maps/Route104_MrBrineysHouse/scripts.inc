.set LOCALID_BRINEY, 1
.set LOCALID_PEEKO, 2

Route104_MrBrineysHouse_MapScripts:: @ 8229D2E
	map_script MAP_SCRIPT_ON_TRANSITION, Route104_MrBrineysHouse_OnTransition
	.byte 0

Route104_MrBrineysHouse_OnTransition: @ 8229D34
	setflag FLAG_LANDMARK_MR_BRINEY_HOUSE
	compare VAR_BRINEY_HOUSE_STATE, 1
	call_if_eq Route104_MrBrineysHouse_EventScript_SetBrineyPeekoPos
	call_if_set FLAG_RECEIVED_POKENAV, Route104_MrBrineysHouse_EventScript_HideRustboroRival
	end

Route104_MrBrineysHouse_EventScript_HideRustboroRival:: @ 8229D4C
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	return

Route104_MrBrineysHouse_EventScript_SetBrineyPeekoPos:: @ 8229D50
	setobjectxyperm LOCALID_BRINEY, 9, 3
	setobjectmovementtype LOCALID_BRINEY, MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_LEFT_UP_RIGHT
	setobjectxyperm LOCALID_PEEKO, 9, 6
	setobjectmovementtype LOCALID_PEEKO, MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_UP_RIGHT_DOWN
	return

Route104_MrBrineysHouse_EventScript_Briney:: @ 8229D67
	lock
	faceplayer
	call_if_unset FLAG_MR_BRINEY_SAILING_INTRO, Route104_MrBrineysHouse_EventScript_SailingIntro
	goto_if_unset FLAG_DELIVERED_STEVEN_LETTER, Route104_MrBrineysHouse_EventScript_SailBothDeliveries
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, Route104_MrBrineysHouse_EventScript_SailDeliverPackage
	goto Route104_MrBrineysHouse_EventScript_WhereAreWeBound
	end

Route104_MrBrineysHouse_EventScript_SailingIntro:: @ 8229D8A
	setflag FLAG_MR_BRINEY_SAILING_INTRO
	msgbox Route104_MrBrineysHouse_Text_WaitUpPeeko, MSGBOX_DEFAULT
	msgbox Route104_MrBrineysHouse_Text_ItsYouLetsSailToDewford, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
	end

Route104_MrBrineysHouse_EventScript_WhereAreWeBound:: @ 8229DAE
	message Route104_MrBrineysHouse_Text_WhereAreWeBound
	waitmessage
	multichoicedefault 20, 8, MULTI_BRINEY_OFF_DEWFORD, 1, 0
	switch VAR_RESULT
	case 0, Route104_MrBrineysHouse_EventScript_SailToDewford
	case 1, Route104_MrBrineysHouse_EventScript_DeclineSailing
	case MULTI_B_PRESSED, Route104_MrBrineysHouse_EventScript_DeclineSailing
	end

Route104_MrBrineysHouse_EventScript_SailBothDeliveries:: @ 8229DE1
	msgbox Route104_MrBrineysHouse_Text_NeedToMakeDeliveriesSailToDewford, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
	end

Route104_MrBrineysHouse_EventScript_SailDeliverPackage:: @ 8229DFA
	msgbox Route104_MrBrineysHouse_Text_NeedToDeliverPackageSailToDewford, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
	end

Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing:: @ 8229E13
	msgbox Route104_MrBrineysHouse_Text_DeclineDeliverySail, MSGBOX_DEFAULT
	release
	end

Route104_MrBrineysHouse_EventScript_DeclineSailing:: @ 8229E1D
	msgbox Route104_MrBrineysHouse_Text_TellMeWheneverYouWantToSail, MSGBOX_DEFAULT
	release
	end

Route104_MrBrineysHouse_EventScript_SailToDewford:: @ 8229E27
	msgbox Route104_MrBrineysHouse_Text_SetSailForDewford, MSGBOX_DEFAULT
	call EventScript_BackupMrBrineyLocation
	setvar VAR_BOARD_BRINEY_BOAT_STATE, 1
	clearflag FLAG_HIDE_ROUTE_104_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setvar VAR_RUSTBORO_CITY_STATE, 8
	setvar VAR_ROUTE104_STATE, 2
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setflag FLAG_HIDE_ROUTE_104_RIVAL
	warp MAP_ROUTE104, 255, 13, 51
	waitstate
	releaseall
	end

Route104_MrBrineysHouse_EventScript_Peeko:: @ 8229E5D
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, 0
	msgbox Route104_MrBrineysHouse_Text_Peeko, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route104_MrBrineysHouse_Text_WaitUpPeeko: @ 8229E70
	.string "하기: 이 녀석!\n"
	.string "거기 서라 피코!$"
	@ ハギ『こらこら!ｎ
	@ まて まて ピ-コちゃん!

Route104_MrBrineysHouse_Text_ItsYouLetsSailToDewford: @ 8229E9B
	.string "으응? 자네는 분명 피코를\n"
	.string "구해 줬었던 {PLAYER} 아닌가!\l"
	.string "그때는 정말 신세를 졌구먼!\p"
	.string "...뭣이? 배를 타고 싶다고?\p"
	.string "흐음흐음?\n"
	.string "무로마을에 편지를 전달하고\l"
	.string "잿빛도시에 화물을 갖다줄 거라고...\l"
	.string "왠지 바쁘구먼 자네는\p"
	.string "하지만 그 정도는 식은 죽 먹기지!\n"
	.string "나에게 맡기게나!\l"
	.string "그럼 바로 무로마을로 가볼까!$"
	@ おや? きみは たしか ピ-コちゃんをｎ
	@ たすけて くれた §あ§お!ｌ
	@ そのせつは せわに なったのう!ｐ
	@ ……なぬ? ふねに のりたい とな?ｐ
	@ ふむふむ?ｎ
	@ ムロに てがみを とどけてｌ
	@ カイナへ にもつを とどける……ｌ
	@ なんだか いそがしいのう きみはｐ
	@ じゃが それくらい おやすい ごようだ!ｎ
	@ わしに まかせて おきなさい!ｌ
	@ では まず ムロに むかうとするか!

Route104_MrBrineysHouse_Text_SetSailForDewford: @ 8229FE9
	.string "하기: 무로마을 말이지\p"
	.string "좋아! 가자 피코!$"
	@ ハギ『ムロタウン かｐ
	@ よっしゃ! いくぞ ピ-コちゃん!

Route104_MrBrineysHouse_Text_DeclineDeliverySail: @ 822A041
	.string "하기: 그렇군\n"
	.string "부탁받은 일은 괜찮나?\p"
	.string "뭐 배를 타야 할 때는\n"
	.string "언제든지 사양 말고 말해주게나!$"
	@ ハギ『そうかねｎ
	@ たのまれごとは いいのかね?ｐ
	@ まあ ふねに のる ひつようが あるときはｎ
	@ いつでも えんりょなく いっておくれ!

Route104_MrBrineysHouse_Text_NeedToMakeDeliveriesSailToDewford: @ 822A0AD
	.string "하기: 자네가 하고 싶은 말은 알고 있네!\p"
	.string "무로마을로 편지를 전달하고\n"
	.string "잿빛도시에 화물을 갖다줘야 하는 게지?\p"
	.string "그 정도는 식은 죽 먹기라네!\n"
	.string "나한테 맡기게나!\l"
	.string "그럼 우선 무로마을로 출발하자꾸나!$"
	@ ハギ『きみの いいたいことは わかっとる!ｐ
	@ ムロに てがみを とどけてｎ
	@ カイナへ にもつを とどけるんだろうｐ
	@ それくらい おやすい ごようだ!ｎ
	@ わしに まかせて おきなさい!ｌ
	@ では まず ムロに むかうとするか!

Route104_MrBrineysHouse_Text_NeedToDeliverPackageSailToDewford: @ 822A18F
	.string "하기: 자네가 하고 싶은 말은 알고 있네!\p"
	.string "잿빛도시에 있는 해양씨한테\n"
	.string "화물을 갖다줘야 하는 게지?\p"
	.string "그 정도는 식은 죽 먹기라네!\n"
	.string "나한테 맡기게나!\l"
	.string "그럼 우선 무로마을로 출발하자꾸나!$"
	@ ハギ『きみの いいたいことは わかっとる!ｐ
	@ カイナの クスノキさんにｎ
	@ にもつを とどけるんだろうｐ
	@ それくらい おやすい ごようだ!ｎ
	@ わしに まかせて おきなさい!ｌ
	@ では まず ムロに むかうとするか!

Route104_MrBrineysHouse_Text_WhereAreWeBound: @ 822A268
	.string "하기: 여어! 자네가 원한다면\n"
	.string "언제든지 배를 준비시키지!\p"
	.string "자네가 가고 싶은 곳은 어디인가?$"
	@ ハギ『やあ! きみのため ならｎ
	@ いつでも ふねを だそう!ｐ
	@ きみが いきたいのは どこ かな?

Route104_MrBrineysHouse_Text_TellMeWheneverYouWantToSail: @ 822A2C3
	.string "하기: 그렇군... 자넨\n"
	.string "피코의 생명의 은인일세\p"
	.string "배를 타야 할 때는\n"
	.string "언제든지 사양 말고 말해주게나!$"
	@ ハギ『そうか…… きみはｎ
	@ ピ-コちゃんの いのちの おんじんだｐ
	@ ふねに のる ひつようが あるときはｎ
	@ いつでも えんりょなく いっておくれ!

Route104_MrBrineysHouse_Text_Peeko: @ 822A337
	.string "피코: 피- 피뾰-!$"
	@ ピ-コちゃん『ピ- ピひょろ-!

