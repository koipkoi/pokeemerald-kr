SlateportCity_PokemonFanClub_MapScripts:: @ 8209E95
	.byte 0

SlateportCity_PokemonFanClub_EventScript_Chairman:: @ 8209E96
	lock
	faceplayer
	goto_if_unset FLAG_ENTERED_CONTEST, SlateportCity_PokemonFanClub_EventScript_ChairmanNotEnteredContest
	call_if_unset FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN, SlateportCity_PokemonFanClub_EventScript_MeetChairman
	switch VAR_SLATEPORT_FAN_CLUB_STATE
	case 0, SlateportCity_PokemonFanClub_EventScript_ChairmanFirstAssessment
	case 1, SlateportCity_PokemonFanClub_EventScript_ChairmanTryAssessPokemon
	case 2, SlateportCity_PokemonFanClub_EventScript_NoMoreScarves
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanFirstAssessment:: @ 8209ED2
	setvar VAR_SLATEPORT_FAN_CLUB_STATE, 1
	msgbox SlateportCity_PokemonFanClub_Text_AllowMeToExamineYourPokemon, MSGBOX_DEFAULT
	goto SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanTryAssessPokemon:: @ 8209EE5
	setvar VAR_TEMP_2, 0
	call_if_set FLAG_RECEIVED_YELLOW_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_GREEN_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_PINK_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_BLUE_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_RED_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	compare VAR_TEMP_2, CONTEST_CATEGORIES_COUNT
	call_if_eq SlateportCity_PokemonFanClub_EventScript_ReceivedAllScarves
	compare VAR_SLATEPORT_FAN_CLUB_STATE, 2
	goto_if_eq SlateportCity_PokemonFanClub_EventScript_NoMoreScarves
	msgbox SlateportCity_PokemonFanClub_Text_HowIsYourPokemonGrowing, MSGBOX_DEFAULT
	goto SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon
	end

SlateportCity_PokemonFanClub_EventScript_NoMoreScarves:: @ 8209F3B
	msgbox SlateportCity_PokemonFanClub_Text_NothingElseToGiveYou, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon:: @ 8209F45
	msgbox SlateportCity_PokemonFanClub_Text_HmHmISee, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, 0
	call_if_unset FLAG_RECEIVED_YELLOW_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonTough
	call_if_unset FLAG_RECEIVED_GREEN_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonSmart
	call_if_unset FLAG_RECEIVED_PINK_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonCute
	call_if_unset FLAG_RECEIVED_BLUE_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonBeauty
	call_if_unset FLAG_RECEIVED_RED_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonCool
	bufferleadmonspeciesname 0
	switch VAR_TEMP_1
	case 0, SlateportCity_PokemonFanClub_EventScript_NoHighConditions
	case 1, SlateportCity_PokemonFanClub_EventScript_GiveRedScarf
	case 2, SlateportCity_PokemonFanClub_EventScript_GiveBlueScarf
	case 3, SlateportCity_PokemonFanClub_EventScript_GivePinkScarf
	case 4, SlateportCity_PokemonFanClub_EventScript_GiveGreenScarf
	case 5, SlateportCity_PokemonFanClub_EventScript_GiveYellowScarf
	release
	end

SlateportCity_PokemonFanClub_EventScript_ReceivedAllScarves:: @ 8209FCA
	setvar VAR_SLATEPORT_FAN_CLUB_STATE, 2
	return

SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf:: @ 8209FD0
	addvar VAR_TEMP_2, 1
	return

SlateportCity_PokemonFanClub_EventScript_NoHighConditions:: @ 8209FD6
	msgbox SlateportCity_PokemonFanClub_Text_GiveMonMorePokeblocks, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveRedScarf:: @ 8209FE0
	checkitemspace ITEM_RED_SCARF, 1
	compare VAR_RESULT, FALSE
	goto_if_eq SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_RED_SCARF
	giveitem ITEM_RED_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainRedScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveBlueScarf:: @ 820A011
	checkitemspace ITEM_BLUE_SCARF, 1
	compare VAR_RESULT, FALSE
	goto_if_eq SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_BLUE_SCARF
	giveitem ITEM_BLUE_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainBlueScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GivePinkScarf:: @ 820A042
	checkitemspace ITEM_PINK_SCARF, 1
	compare VAR_RESULT, FALSE
	goto_if_eq SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_PINK_SCARF
	giveitem ITEM_PINK_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainPinkScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveGreenScarf:: @ 820A073
	checkitemspace ITEM_GREEN_SCARF, 1
	compare VAR_RESULT, FALSE
	goto_if_eq SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_GREEN_SCARF
	giveitem ITEM_GREEN_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainGreenScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveYellowScarf:: @ 820A0A4
	checkitemspace ITEM_YELLOW_SCARF, 1
	compare VAR_RESULT, FALSE
	goto_if_eq SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_YELLOW_SCARF
	giveitem ITEM_YELLOW_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainYellowScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf:: @ 820A0D5
	msgbox SlateportCity_PokemonFanClub_Text_NoSpaceForReward, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_CheckMonCool:: @ 820A0DF
	specialvar VAR_RESULT, CheckLeadMonCool
	compare VAR_RESULT, TRUE
	call_if_eq SlateportCity_PokemonFanClub_EventScript_SetMonCool
	return

SlateportCity_PokemonFanClub_EventScript_SetMonCool:: @ 820A0F0
	setvar VAR_TEMP_1, 1
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonBeauty:: @ 820A0F6
	specialvar VAR_RESULT, CheckLeadMonBeauty
	compare VAR_RESULT, TRUE
	call_if_eq SlateportCity_PokemonFanClub_EventScript_SetMonBeauty
	return

SlateportCity_PokemonFanClub_EventScript_SetMonBeauty:: @ 820A107
	setvar VAR_TEMP_1, 2
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonCute:: @ 820A10D
	specialvar VAR_RESULT, CheckLeadMonCute
	compare VAR_RESULT, TRUE
	call_if_eq SlateportCity_PokemonFanClub_EventScript_SetMonCute
	return

SlateportCity_PokemonFanClub_EventScript_SetMonCute:: @ 820A11E
	setvar VAR_TEMP_1, 3
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonSmart:: @ 820A124
	specialvar VAR_RESULT, CheckLeadMonSmart
	compare VAR_RESULT, TRUE
	call_if_eq SlateportCity_PokemonFanClub_EventScript_SetMonSmart
	return

SlateportCity_PokemonFanClub_EventScript_SetMonSmart:: @ 820A135
	setvar VAR_TEMP_1, 4
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonTough:: @ 820A13B
	specialvar VAR_RESULT, CheckLeadMonTough
	compare VAR_RESULT, TRUE
	call_if_eq SlateportCity_PokemonFanClub_EventScript_SetMonTough
	return

SlateportCity_PokemonFanClub_EventScript_SetMonTough:: @ 820A14C
	setvar VAR_TEMP_1, 5
	return

SlateportCity_PokemonFanClub_EventScript_ChairmanNotEnteredContest:: @ 820A152
	goto_if_set FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN, SlateportCity_PokemonFanClub_EventScript_ChairmanEnterContest
	msgbox SlateportCity_PokemonFanClub_Text_MeetChairman, MSGBOX_DEFAULT
	setflag FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanEnterContest:: @ 820A168
	msgbox SlateportCity_PokemonFanClub_Text_LikeToSeeEnteredContestPokemon, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_MeetChairman:: @ 820A172
	msgbox SlateportCity_PokemonFanClub_Text_MeetChairman, MSGBOX_DEFAULT
	setflag FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN
	return

SlateportCity_PokemonFanClub_EventScript_SootheBellWoman:: @ 820A17E
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SOOTHE_BELL, SlateportCity_PokemonFanClub_EventScript_ReceivedSootheBell
	msgbox SlateportCity_PokemonFanClub_Text_ShowMePokemonThatLoveYou, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	compare VAR_RESULT, 4
	goto_if_ge SlateportCity_PokemonFanClub_EventScript_GiveSootheBell
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveSootheBell:: @ 820A1A3
	playse SE_PIN
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_LAST_TALKED, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_PokemonFanClub_Text_PokemonAdoresYou, MSGBOX_DEFAULT
	giveitem ITEM_SOOTHE_BELL
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SOOTHE_BELL
	release
	end

SlateportCity_PokemonFanClub_EventScript_ReceivedSootheBell:: @ 820A1DE
	msgbox SlateportCity_PokemonFanClub_Text_TreatPokemonWithLove, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_Man:: @ 820A1E8
	msgbox SlateportCity_PokemonFanClub_Text_PokemonDontLikeFainting, MSGBOX_NPC
	end

SlateportCity_PokemonFanClub_EventScript_Twin:: @ 820A1F1
	msgbox SlateportCity_PokemonFanClub_Text_MonEnjoyedProtein, MSGBOX_NPC
	end

SlateportCity_PokemonFanClub_EventScript_Skitty:: @ 820A1FA
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, 0
	msgbox SlateportCity_PokemonFanClub_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_EventScript_Zigzagoon:: @ 820A20D
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, 0
	msgbox SlateportCity_PokemonFanClub_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_EventScript_Azumarill:: @ 820A220
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, 0
	msgbox SlateportCity_PokemonFanClub_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_Text_MeetChairman: @ 820A233
	.string "으흠!!\p"
	.string "내가 바로 포켓몬 애호가클럽에서\n"
	.string "가장 대단한 회장이랍니다!\p"
	.string "뭐니 뭐니 해도 회장이니까요\n"
	.string "포켓몬 키우기로\l"
	.string "날 따라올 수 있는 사람은 없죠!\p"
	.string "그렇게 키운 포켓몬을 자랑할 수 있는\n"
	.string "포켓몬 콘테스트라고 하는\l"
	.string "행사가 있습니다만...\p"
	.string "아무래도 먼 마을에서 열기에\n"
	.string "참가하기가 어렵단 말이죠\p"
	.string "그래서 지금은 여기서\n"
	.string "자신의 포켓몬을 자랑하거나\l"
	.string "다른 사람의 포켓몬을\l"
	.string "보고 있습니다$"
	@ ウォッホン!!ｐ
	@ わしが ポケモン だいすきクラブでｎ
	@ いちば-ん えらい かいちょう ですぞ!ｐ
	@ なんたって かいちょう ですからなｎ
	@ ポケモンを そだてさせたらｌ
	@ みぎに でるもの なし!ｐ
	@ そんな ポケモンを じまんできるｎ
	@ ポケモンコンテストというｌ
	@ もよおしが あるの ですが…ｐ
	@ なにしろ とおくの まちで やっているのでｎ
	@ あまり さんか できんのですよｐ
	@ ですから いまは ここでｎ
	@ じぶんの ポケモンを じまんしたりｌ
	@ みなさんの ポケモンをｌ
	@ みせて いただくだけに しておるのです

SlateportCity_PokemonFanClub_Text_LikeToSeeEnteredContestPokemon: @ 820A3EE
	.string "포켓몬 콘테스트에 나간 적 있는\n"
	.string "트레이너의 포켓몬...\l"
	.string "부디 보고 싶군요$"
	@ ポケモンコンテストに でた ことがｎ
	@ ある トレ-ナ-の ポケモン…ｌ
	@ ぜひとも みて みたい ものですな

SlateportCity_PokemonFanClub_Text_AllowMeToExamineYourPokemon: @ 820A445
	.string "으흠!!\n"
	.string "오오 콘테스트에 나갔군요!\p"
	.string "어디 당신의 포켓몬이\n"
	.string "어떻게 자라고 있는지 볼까요?\p"
	.string "이야- 다른 사람이 키운 포켓몬을\n"
	.string "보는 건 즐겁군요!\p"
	.string "제대로 키운 포켓몬의\n"
	.string "행복해 보이는 얼굴...\p"
	.string "그걸 바라보고 있는 트레이너의\n"
	.string "상냥한 눈동자...\p"
	.string "이야- 행복함으로\n"
	.string "가슴이 벅차올라요...\p"
	.string "오오 실례! 저도 모르게\n"
	.string "이야기가 길어졌군요\p"
	.string "그럼 바로 그대의 포켓몬이\n"
	.string "얼마나 성장했는지\l"
	.string "한번 봐 볼까요!$"
	@ ウォッホン!!ｎ
	@ おっ コンテストに でられましたな!ｐ
	@ どれ あなたは ポケモンをｎ
	@ どんな ふうに そだてられて いるのかな?ｐ
	@ いや- ひとの そだてた ポケモンをｎ
	@ はいけん するのは たのしい ですぞ!ｐ
	@ きちんと そだてられた ポケモンのｎ
	@ しあわせそうな かお……ｐ
	@ それを みつめる トレ-ナ-のｎ
	@ やさしげな ひとみ……ｐ
	@ いや- しあわせでｎ
	@ むねが いっぱいに なりますな……ｐ
	@ おっと しつれい! ついついｎ
	@ はなしが ながくなって しまいましたなｐ
	@ では さっそく きみの ポケモンがｎ
	@ どれほど そだっているのかｌ
	@ はいけん させて もらいますかな!

SlateportCity_PokemonFanClub_Text_HowIsYourPokemonGrowing: @ 820A62A
	.string "그대의 포켓몬은 잘 크고 있나요?\n"
	.string "한번 봐보도록 하죠!$"
	@ きみの ポケモン そだって ますかな?ｎ
	@ ちょっと はいけん させて もらいますぞ!

SlateportCity_PokemonFanClub_Text_HmHmISee: @ 820A65F
	.string "흠흠...\n"
	.string "과연...$"
	@ ふむふむ……ｎ
	@ なるほど……

SlateportCity_PokemonFanClub_Text_GiveMonMorePokeblocks: @ 820A66E
	.string "흠...\n"
	.string "나쁘진 않지만 좋지도 않군요...\p"
	.string "어버이 트레이너인 그대의\n"
	.string "노력이 필요할 거 같네요!\p"
	.string "예를 들어 더 많이\n"
	.string "포켓몬스넥을 주는 건 어떨까요?$"
	@ ふむう……ｎ
	@ わるくは ないんだが よくもない……ｐ
	@ おやの トレ-ナ-である きみのｎ
	@ どりょくが ひつよう ですな!ｐ
	@ たとえば もっと たくさんｎ
	@ ポロックを あげるのは どうですかな?

SlateportCity_PokemonFanClub_Text_NoSpaceForReward: @ 820A719
	.string "이런...\p"
	.string "제법 포켓몬을 잘 키우고 있으니\n"
	.string "좋은 선물을 주려고 했는데\l"
	.string "가방이 가득 차신 모양이군요$"
	@ あらら……ｐ
	@ けっこう ポケモンが そだっているのでｎ
	@ いいものを あげようと おもったのですがｌ
	@ もちものが いっぱい ですな

SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis: @ 820A795
	.string "그대의 {STR_VAR_1} 말인데요\n"
	.string "진짜 잘 성장했네요!\l"
	.string "이야- 정말 대단해요!\p"
	.string "하지만 이 도구를 지니게 하면\n"
	.string "더욱 잘 키울 수 있을 겁니다!$"
	@ きみの §い ですがｎ
	@ なかなか みごとに そだって おりますな!ｌ
	@ いや- たいした ものです!ｐ
	@ だが この どうぐを つかって あげたならｎ
	@ もっと そだつこと まちがいなし! ですぞ!

SlateportCity_PokemonFanClub_Text_ExplainRedScarf: @ 820A827
	.string "그 빨강밴드를 지니게 하면\n"
	.string "포켓몬의 근사함을\l"
	.string "모두에게 인정받게 될 거예요!$"
	@ その あかいバンダナを もたせるとｎ
	@ ポケモンの かっこよさをｌ
	@ みんなに みとめさせることが できますぞ!

SlateportCity_PokemonFanClub_Text_ExplainBlueScarf: @ 820A880
	.string "그 파랑밴드를 지니게 하면\n"
	.string "포켓몬의 아름다움을\l"
	.string "지금보다 더 뽐낼 수 있게 될 거예요!$"
	@ その あおいバンダナを もたせるとｎ
	@ ポケモンの うつくしさをｌ
	@ いまより きわだたせることが できますぞ!

SlateportCity_PokemonFanClub_Text_ExplainPinkScarf: @ 820A8D7
	.string "그 분홍밴드를 지니게 하면\n"
	.string "포켓몬의 귀여움을\l"
	.string "더 이끌어 낼 수 있을 거예요!$"
	@ その ピンクのバンダナを もたせるとｎ
	@ ポケモンの かわいさをｌ
	@ もっと ひきだすことが できますぞ!

SlateportCity_PokemonFanClub_Text_ExplainGreenScarf: @ 820A933
	.string "그 초록밴드를 지니게 하면\n"
	.string "포켓몬의 슬기로움을\l"
	.string "더욱 갈고닦을 수 있을 거예요!$"
	@ その みどりのバンダナを もたせるとｎ
	@ ポケモンの かしこさをｌ
	@ さらに みがくことが できますぞ!

SlateportCity_PokemonFanClub_Text_ExplainYellowScarf: @ 820A984
	.string "그 노랑밴드를 지니게 하면\n"
	.string "포켓몬의 강인함을\l"
	.string "더욱 어필할 수 있을 거예요!$"
	@ その きいろのバンダナを もたせるとｎ
	@ ポケモンの たくましさをｌ
	@ いっそう アピ-ル できますぞ!

SlateportCity_PokemonFanClub_Text_NothingElseToGiveYou: @ 820A9E1
	.string "그대에게 줄 도구는\n"
	.string "이제 더 이상 없어요!\p"
	.string "왜냐하면 도구에 기대지 않아도\n"
	.string "포켓몬을 키우는 그대의\l"
	.string "재능은 환상적이니까요!$"
	@ きみに あげる どうぐはｎ
	@ もう なにも ないですぞ!ｐ
	@ なにしろ どうぐに たよらんでもｎ
	@ きみの ポケモンを そだてるｌ
	@ さいのうは バツグン ですからな!

SlateportCity_PokemonFanClub_Text_ShowMePokemonThatLoveYou: @ 820AA77
	.string "난 포켓몬이 사람을 따르는 모습을\n"
	.string "보는 게 너무 좋아\p"
	.string "포켓몬은 함께 있는\n"
	.string "사람의 감정에 매우 민감해!\p"
	.string "네가 포켓몬을 소중하게 여기면\n"
	.string "포켓몬도 너를 따르게 될 거야!\p"
	.string "네 포켓몬이 너를 따르기 시작하면\n"
	.string "나한테도 좀 보여줘$"
	@ わたし ポケモンが なついているｎ
	@ すがたを みるのが すきｐ
	@ ポケモンって いっしょに いるｎ
	@ ひとの きもちに すごく びんかん!ｐ
	@ あなたが ポケモンを だいじに すればｎ
	@ ポケモンも あなたに なついてくれるわ!ｐ
	@ あなたの ポケモンが あなたに なついたらｎ
	@ わたしにも みせてね

SlateportCity_PokemonFanClub_Text_PokemonAdoresYou: @ 820AB63
	.string "네 포켓몬\n"
	.string "널 정말 잘 따르고 있구나\p"
	.string "포켓몬에게 자상한 트레이너를 위한\n"
	.string "애호가클럽의 선물이야$"
	@ あなたの ポケモンｎ
	@ あなたに なついているのねｐ
	@ ポケモンに やさしい トレ-ナ-さんにｎ
	@ だいすきクラブからの おくりもの よ

SlateportCity_PokemonFanClub_Text_TreatPokemonWithLove: @ 820ABC4
	.string "포켓몬은 함께 있는\n"
	.string "사람의 감정에 매우 민감해!\p"
	.string "네가 포켓몬을 소중하게 여기면\n"
	.string "포켓몬도 너를 따르게 될 거야!$"
	@ ポケモンって いっしょに いるｎ
	@ ひとの きもちに すごく びんかん!ｐ
	@ あなたが ポケモンを だいじに すればｎ
	@ ポケモンも あなたに なついてくれるわ!

SlateportCity_PokemonFanClub_Text_PokemonDontLikeFainting: @ 820AC47
	.string "포켓몬 승부에서 져서\n"
	.string "기절을 많이 하게 되면\l"
	.string "포켓몬이 점점 위축돼서\l"
	.string "트레이너를 의심하기 시작해\p"
	.string "즉 잘 따르지 않게 된다는 거야$"
	@ ポケモンしょうぶに まけてｎ
	@ ひんしに させて ばかりだとｌ
	@ ポケモンが どんどん すさんでｌ
	@ トレ-ナ-のこと うたがう ようになるｐ
	@ つまり なついて くれなくなるよ

SlateportCity_PokemonFanClub_Text_MonEnjoyedProtein: @ 820ACF9
	.string "포켓몬은 자기한테 도구를\n"
	.string "써 주는 게 좋은 걸까?\p"
	.string "왜냐면 타우린 같은 걸 주면\n"
	.string "정말 기뻐하잖아!$"
	@ ポケモンって どうぐｎ
	@ つかってもらうのが すきなのかな?ｐ
	@ だって タウリンとか あげるとｎ
	@ すごく うれしそうに するのよ!

SlateportCity_PokemonFanClub_Text_Skitty: @ 820AD5A
	.string "에나비: 후냐아-아$"
	@ エネコ『ふにゃあ-あ

SlateportCity_PokemonFanClub_Text_Zigzagoon: @ 820AD6E
	.string "지그제구리: 지규우....$"
	@ ジグザグマ『キュウウ……

SlateportCity_PokemonFanClub_Text_Azumarill: @ 820AD80
	.string "마릴리: 마리 마리!?$"
	@ マリルリ『マリ マリ!?

