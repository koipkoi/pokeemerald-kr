.set LOCALID_EXPERT_M, 4
.set LOCALID_TWIN, 5
.set LOCALID_SCHOOL_KID_M, 7
.set LOCALID_PSYCHIC_M, 8

DewfordTown_Hall_MapScripts:: @ 81FD4CF
	.byte 0

DewfordTown_Hall_EventScript_Girl:: @ 81FD4D0
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special TrendyPhraseIsOld
	compare VAR_RESULT, TRUE
	goto_if_eq DewfordTown_Hall_EventScript_GirlBoredOfTrend
	msgbox DewfordTown_Hall_Text_CantImagineLifeWithoutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_GirlBoredOfTrend:: @ 81FD4EF
	msgbox DewfordTown_Hall_Text_GettingBoredOfTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Woman:: @ 81FD4F9
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TeachingMonAboutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Man:: @ 81FD50A
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special BufferDeepLinkPhrase
	msgbox DewfordTown_Hall_Text_DeepLinkBetweenXAndY, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq DewfordTown_Hall_EventScript_ConfirmTrendLink
	compare VAR_RESULT, NO
	goto_if_eq DewfordTown_Hall_EventScript_RejectTrendLink
	end

DewfordTown_Hall_EventScript_ConfirmTrendLink:: @ 81FD533
	msgbox DewfordTown_Hall_Text_MyHunchWasRight, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_RejectTrendLink:: @ 81FD53D
	msgbox DewfordTown_Hall_Text_NotEasyToKeepUp, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_ExpertM:: @ 81FD547
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TVShowAboutTrend, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_EXPERT_M, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_Twin:: @ 81FD563
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TWIN, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_LittleBoy:: @ 81FD57F
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_CollectTrendMerchandise, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Bookshelf:: @ 81FD590
	lockall
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_BooksAboutTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_Painting:: @ 81FD5A0
	lockall
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_ScreamTitle
	case 4, DewfordTown_Hall_EventScript_ScreamTitle
	case 1, DewfordTown_Hall_EventScript_SmileTitle
	case 5, DewfordTown_Hall_EventScript_ScreamTitle
	case 2, DewfordTown_Hall_EventScript_LastTitle
	case 6, DewfordTown_Hall_EventScript_LastTitle
	case 3, DewfordTown_Hall_EventScript_BirthTitle
	case 7, DewfordTown_Hall_EventScript_LastTitle
	end

DewfordTown_Hall_EventScript_ScreamTitle:: @ 81FD607
	msgbox DewfordTown_Hall_Text_TrendsScream, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SmileTitle:: @ 81FD611
	msgbox DewfordTown_Hall_Text_TrendsSmile, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_LastTitle:: @ 81FD61B
	msgbox DewfordTown_Hall_Text_LastTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_BirthTitle:: @ 81FD625
	msgbox DewfordTown_Hall_Text_BirthOfTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SchoolKidM:: @ 81FD62F
	lockall
	setvar VAR_0x8008, 0
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_PsychicM:: @ 81FD63B
	lockall
	setvar VAR_0x8008, 1
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_DoTrendDebate:: @ 81FD647
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_TrendDebate1
	case 1, DewfordTown_Hall_EventScript_TrendDebate1
	case 2, DewfordTown_Hall_EventScript_TrendDebate2
	case 3, DewfordTown_Hall_EventScript_TrendDebate2
	case 4, DewfordTown_Hall_EventScript_TrendDebate3
	case 5, DewfordTown_Hall_EventScript_TrendDebate3
	case 6, DewfordTown_Hall_EventScript_TrendDebate4
	case 7, DewfordTown_Hall_EventScript_TrendDebate5
	end

DewfordTown_Hall_EventScript_TrendDebate1:: @ 81FD6AD
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_SawTrendCoolestThing, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_AllegedTrendNotAuthentic, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate2:: @ 81FD6C9
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_ComposedTrendThemeSong, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WorkOnYourSinging, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate3:: @ 81FD6E5
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_OrganizeTrendParty, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_BrilliantIndeed, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate4:: @ 81FD701
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_TrendHasBecomePartOfLife, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate5:: @ 81FD71D
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WellBeTrendDuo, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_DontMovePlayer1:: @ 81FD739
	return

DewfordTown_Hall_EventScript_DebateReact1:: @ 81FD73A
	applymovement LOCALID_PSYCHIC_M, DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft
	waitmovement 0
	compare VAR_0x8008, 0
	goto_if_eq DewfordTown_Hall_EventScript_PlayerReactWest
	compare VAR_0x8008, 1
	goto_if_eq DewfordTown_Hall_EventScript_DontMovePlayer2
	end

DewfordTown_Hall_EventScript_PlayerReactWest:: @ 81FD75B
	compare VAR_FACING, DIR_EAST
	goto_if_eq DewfordTown_Hall_EventScript_DontMovePlayer1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	return

DewfordTown_Hall_EventScript_DontMovePlayer2:: @ 81FD771
	return

DewfordTown_Hall_EventScript_DebateReact2:: @ 81FD772
	applymovement LOCALID_SCHOOL_KID_M, DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight
	waitmovement 0
	compare VAR_0x8008, 0
	goto_if_eq DewfordTown_Hall_EventScript_PlayerReactNorthSouth
	compare VAR_0x8008, 1
	goto_if_eq DewfordTown_Hall_EventScript_PlayerReactEast
	end

DewfordTown_Hall_EventScript_PlayerReactNorthSouth:: @ 81FD793
	compare VAR_FACING, DIR_NORTH
	call_if_eq DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp
	compare VAR_FACING, DIR_SOUTH
	call_if_eq DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp:: @ 81FD7AA
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown:: @ 81FD7B5
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

DewfordTown_Hall_EventScript_PlayerReactEast:: @ 81FD7C0
	compare VAR_FACING, DIR_WEST
	goto_if_eq DewfordTown_Hall_EventScript_DontMovePlayer1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	return

DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft: @ 81FD7D6
	walk_in_place_left
	step_end

DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight: @ 81FD7D8
	walk_in_place_right
	step_end

DewfordTown_Hall_EventScript_SludgeBombMan:: @ 81FD7DA
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	goto_if_set FLAG_RECEIVED_TM36, DewfordTown_Hall_EventScript_ReceivedSludgeBomb
	msgbox DewfordTown_Hall_Text_GiveYouSludgeBomb, MSGBOX_DEFAULT
	giveitem ITEM_TM36
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM36
	release
	end

DewfordTown_Hall_EventScript_ReceivedSludgeBomb:: @ 81FD80E
	msgbox DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_Text_CantImagineLifeWithoutTrend: @ 81FD818
	.string "요즘 유행하는 게 뭐냐고 하면 역시\n"
	.string "“{STR_VAR_1}”{K_I}지!\p"
	.string "“{STR_VAR_1}”{K_IGA} 없는\n"
	.string "생활 같은 건 상상이 안 돼!$"
	// いまの はやりって いったら やっぱりｎ
	// 「§い」よね!ｐ
	// 「§い」の ないｎ
	// せいかつ なんか かんがえられない!

DewfordTown_Hall_Text_GettingBoredOfTrend: @ 81FD877
	.string "요즘 유행하는 게 뭐냐고 하면 역시\n"
	.string "“{STR_VAR_1}”{K_I}지!\p"
	.string "근데 이제 슬슬\n"
	.string "지루해졌어-\p"
	.string "새로운 유행이라도 찾아볼까-$"
	// いまの はやりって いったら やっぱりｎ
	// 「§い」よね!ｐ
	// でも もう そろそろｎ
	// あきてきたな-ｐ
	// あたらしい はやりでも さがそっかな-

DewfordTown_Hall_Text_TeachingMonAboutTrend: @ 81FD8ED
	.string "난 포켓몬한테도\n"
	.string "“{STR_VAR_1}”{K_EULREUL}\l"
	.string "가르치고 있는데\p"
	.string "이게 꽤나\n"
	.string "힘들단 말이지-$"
	// わたしは ポケモンにもｎ
	// 「§い」をｌ
	// おしえてるんだけどｐ
	// これが なかなかｎ
	// たいへん なのよね-

DewfordTown_Hall_Text_DeepLinkBetweenXAndY: @ 81FD948
	.string "요즘 유행하는\n"
	.string "“{STR_VAR_1}”에 대해서\l"
	.string "조사하고 있는데\p"
	.string "“{STR_VAR_1}”{K_WAGWA}\n"
	.string "“{STR_VAR_2}”에\p"
	.string "깊은 관계가 있다는 건\n"
	.string "정말이야?$"
	// いま はやりのｎ
	// 「§い」のことをｌ
	// しらべてるんだけどｐ
	// 「§い」とｎ
	// 「§う」ってのはｐ
	// ふかい かんけいが あるって いうのはｎ
	// ほんとうの ことなのかい?

DewfordTown_Hall_Text_MyHunchWasRight: @ 81FD9B3
	.string "오!\n"
	.string "역시 그랬군\p"
	.string "이걸로 아저씨도 한 걸음\n"
	.string "유행에 가까워졌어!$"
	// お!ｎ
	// やっぱり そうなのかｐ
	// これで おじさんも またいっぽｎ
	// りゅうこうに ちかづいたぞ!

DewfordTown_Hall_Text_NotEasyToKeepUp: @ 81FDA06
	.string "뭐라고!?\n"
	.string "그런 거야!?\p"
	.string "아- 아저씨가 유행을\n"
	.string "따라가는 건 너무 힘들다!$"
	// なに!?ｎ
	// そうなのか!?ｐ
	// いや- おじさんが りゅうこうにｎ
	// ついて いくのは たいへんだ!

DewfordTown_Hall_Text_TVShowAboutTrend: @ 81FDA5C
	.string "“{STR_VAR_1}” 관련\n"
	.string "TV 방송 같은 건\l"
	.string "어디서 안 하려나...$"
	// 「§い」のｎ
	// テレビって いうのはｌ
	// やってないのかのう……

DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea: @ 81FDA99
	.string "바다 건너편에선\p"
	.string "좀 더 “{STR_VAR_1}”{K_IGA}\n"
	.string "유행하고 있으려나?$"
	// うみの むこうではｐ
	// もっと 「§い」がｎ
	// はやってるのかな?

DewfordTown_Hall_Text_CollectTrendMerchandise: @ 81FDAC4
	.string "난 “{STR_VAR_1}”의\n"
	.string "굿즈를 많이 모으고 있어!\p"
	.string "“{STR_VAR_1}” 인형\n"
	.string "이라든가\p"
	.string "“{STR_VAR_1}” 옷\p"
	.string "“{STR_VAR_1}” 그림책도\n"
	.string "가지고 있어\p"
	.string "부럽지-!\n"
	.string "탐낸다 해도 안 줄 거야-$"
	// ぼくは 「§い」のｎ
	// グッズを いっぱい あつめて いるんだ!ｐ
	// 「§い」にんぎょうｎ
	// とかｐ
	// 「§い」ようふくｐ
	// 「§い」の えほんｎ
	// なんかも もってるよｐ
	// いいだろ-!ｎ
	// ほしくても あげないよ-

DewfordTown_Hall_Text_BooksAboutTrend: @ 81FDB89
	.string "“좋은 ‘{STR_VAR_1}'{K_WAGWA}\n"
	.string "  나쁜 ‘{STR_VAR_1}'”\p"
	.string "“‘{STR_VAR_1}'{K_WAGWA}\n"
	.string "  포켓몬의 관계”\p"
	.string "“도움이 되는\n"
	.string "  ‘{STR_VAR_1}'”\p"
	.string "“{STR_VAR_1}”에 대한\n"
	.string "책이 줄줄이 나열되어 있다!$"
	// 『よい「§い」とｎ
	//  わるい「§い」』ｐ
	// 『「§い」とｎ
	//  ポケモンの かんけい』ｐ
	// 『やくにたつｎ
	//  「§い」』ｐ
	// 「§い」にｎ
	// ついての ほんが ずらっと ならんでいる!

DewfordTown_Hall_Text_TrendsScream: @ 81FDC05
	.string "“‘{STR_VAR_1}'의\n"
	.string "  외침”\p"
	.string "이라는 제목이다!$"
	// 『「§い」のｎ
	//  さけび』ｐ
	// という だいめい だ!

DewfordTown_Hall_Text_TrendsSmile: @ 81FDC21
	.string "“‘{STR_VAR_1}'의\n"
	.string "  미소”\p"
	.string "라는 제목이다!$"
	// 『「§い」のｎ
	//  ほほえみ』ｐ
	// という だいめい だ!

DewfordTown_Hall_Text_LastTrend: @ 81FDC3C
	.string "“‘{STR_VAR_1}'의\n"
	.string "  최후”\p"
	.string "라는 제목이다!$"
	// 『さいごのｎ
	//  「§い」』ｐ
	// という だいめい だ!

DewfordTown_Hall_Text_BirthOfTrend: @ 81FDC57
	.string "“‘{STR_VAR_1}'의\n"
	.string "  탄생”\p"
	.string "이라는 제목이다!$"
	// 『「§い」のｎ
	//  たんじょう』ｐ
	// という だいめい だ!

DewfordTown_Hall_Text_SawTrendCoolestThing: @ 81FDC76
	.string "나 최근 유행하고 있는\p"
	.string "“{STR_VAR_1}”{K_EULREUL}\n"
	.string "봤어 부럽지!\p"
	.string "정말 굉장했어\n"
	.string "진짜는 역시 다르더라!$"
	// ぼく さいきん はやりのｐ
	// 「§い」をｎ
	// みたんだ いいだろ!ｐ
	// すごかったよｎ
	// ほんもの だぜ!

DewfordTown_Hall_Text_AllegedTrendNotAuthentic: @ 81FDCE2
	.string "아니 네가 본\n"
	.string "“{STR_VAR_1}”{K_EUNNEUN}\l"
	.string "진짜가 아니야!\p"
	.string "진짜는 좀 더\n"
	.string "정밀하다고 해야 하나\l"
	.string "아름답다고 해야 하나...\p"
	.string "뭐 어쨌든\n"
	.string "훨씬 엄청나다고!$"
	// いや きみの みたｎ
	// 「§い」はｌ
	// ほんもの じゃないね!ｐ
	// ほんものは もっとｎ
	// キレが あるというかｌ
	// うつくしい というか……ｐ
	// まあ とにかくｎ
	// もっと すごいんだよ!

DewfordTown_Hall_Text_ComposedTrendThemeSong: @ 81FDD95
	.string "나 최근 유행하고 있는\n"
	.string "“{STR_VAR_1}”의\l"
	.string "테마송을 생각해 봤는데\l"
	.string "한번 들어봐!\p"
	.string "...\p"
	.string "오-!\n"
	.string "{STR_VAR_1}-!\p"
	.string "너무 멋져\n"
	.string "{STR_VAR_1}--!!$"
	// ぼく さいきん はやってるｎ
	// 「§い」のｌ
	// テ-マ きょくを かんがえたんだｌ
	// きいてくれよ!ｐ
	// ……ｐ
	// お-!ｎ
	// §い -!ｐ
	// すばらしいｎ
	// §い --!!

DewfordTown_Hall_Text_WorkOnYourSinging: @ 81FDE0E
	.string "...\p"
	.string "넌\n"
	.string "“{STR_VAR_1}”보다\p"
	.string "노래 공부를\n"
	.string "해야 할 것 같아$"
	// ……ｐ
	// きみはｎ
	// 「§い」 よりもｐ
	// うたの べんきょうをｎ
	// したほうが いいね

DewfordTown_Hall_Text_OrganizeTrendParty: @ 81FDE77
	.string "아까 얘기하면서\n"
	.string "순간 떠올랐는데\p"
	.string "다음에 이 섬에서\n"
	.string "“{STR_VAR_1}”\l"
	.string "파티를 열자!$"
	// さっきの はなしｎ
	// なんだけどさｐ
	// こんど この しまでｎ
	// 「§い」ｌ
	// パ-ティ-を ひらこうぜ!

DewfordTown_Hall_Text_BrilliantIndeed: @ 81FDED8
	.string "오 좋은데!!\p"
	.string "누가 제일\n"
	.string "“{STR_VAR_1}”{K_EULREUL}\l"
	.string "잘하는지 정하는 거지!\p"
	.string "좋아 그럼 오늘부터\p"
	.string "“{STR_VAR_1}”\n"
	.string "삼매경이다!$"
	// お いいね!!ｐ
	// だれが いちばんｎ
	// 「§い」がｌ
	// うまいかを きめるんだね!ｐ
	// じゃあ きょうからｐ
	// 「§い」ｎ
	// ざんまいだ!

DewfordTown_Hall_Text_TrendHasBecomePartOfLife: @ 81FDF72
	.string "...그래\p"
	.string "“{STR_VAR_1}”{K_EUNNEUN} 이제\n"
	.string "유행이라기보단\p"
	.string "생활의 일부가\n"
	.string "된 거 같다고 해야 할까?$"
	// ……そうだなぁｐ
	// 「§い」は もうｎ
	// りゅうこう じゃなくてｐ
	// せいかつの いちぶｎ
	// という かんじかなぁ?

DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind: @ 81FDFF1
	.string "응?\n"
	.string "그렇게나!?\p"
	.string "뭐 넌 매일같이\n"
	.string "“{STR_VAR_1}”만\l"
	.string "생각하고 있으니까\p"
	.string "“{STR_VAR_1} 박사”나\n"
	.string "다름없단 말이지 나 참$"
	// え?ｎ
	// そんなに!?ｐ
	// きみは ねても さめてもｎ
	// 「§い」 のことｌ
	// ばっかり かんがえてる からなｐ
	// 「§い はかせ」ｎ
	// だね まったく

DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible: @ 81FE09A
	.string "나랑 네가\n"
	.string "콤비를 짜면\p"
	.string "“{STR_VAR_1}”에서는\n"
	.string "완전 무적일 거야!$"
	// ぼくと きみがｎ
	// コンビを くめばｐ
	// 『§い』ではｎ
	// もう むてきって ことだな!

DewfordTown_Hall_Text_WellBeTrendDuo: @ 81FE0F2
	.string "그야 그렇지!\p"
	.string "“{STR_VAR_1}” 콤비\n"
	.string "라고 부르면 되려나!\p"
	.string "하하하!$"
	// そのとおり!ｐ
	// 「§い コンビ」ｎ
	// っていう かんじだね!ｐ
	// ハハハ!!

DewfordTown_Hall_Text_GiveYouSludgeBomb: @ 81FE142
	.string "요즘 나한테는\n"
	.string "“오물폭탄”이 대세야!\p"
	.string "앗- 너\n"
	.string "“오물폭탄” 몰라?\p"
	.string "그건 불쌍한데\n"
	.string "좋아! 그럼 내가 줄게!$"
	// さいきん ぼくの なかではｎ
	// 「ヘドロばくだん」が だいブ-ム なのさ!ｐ
	// え- きみｎ
	// 「ヘドロばくだん」 しらないの?ｐ
	// それは かわいそうだなｎ
	// よし! ぼくが あげるよ!

DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo: @ 81FE1ED
	.string "“오물폭탄”도 좋지만\n"
	.string "“{STR_VAR_1}”{K_I}라는\l"
	.string "기술을 쓸 수 있는\l"
	.string "포켓몬도 좋지!$"
	// 「ヘドロばくだん」も いいけどｎ
	// 「§い」ってｌ
	// わざを つかえるｌ
	// ポケモンも いいよね!

