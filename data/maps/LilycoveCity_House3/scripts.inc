LilycoveCity_House3_MapScripts:: @ 821EE3C
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_House3_OnTransition
	.byte 0

LilycoveCity_House3_OnTransition: @ 821EE42
	random 4
	copyvar VAR_TEMP_1, VAR_RESULT
	end

LilycoveCity_House3_EventScript_PokefanF:: @ 821EE4B
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LilycoveCity_House3_EventScript_DeclinePokeblockLearn
	msgbox LilycoveCity_House3_Text_ExplainPokeblocks, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_DeclinePokeblockLearn:: @ 821EE75
	msgbox LilycoveCity_House3_Text_OhAreYouSure, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_Man:: @ 821EE8A
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_HappyToHaveQuadruplets, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_GameBoyKid1:: @ 821EEA1
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid2:: @ 821EED5
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid3:: @ 821EF09
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid4:: @ 821EF3D
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_WereDoingMultiBattle:: @ 821EF71
	msgbox LilycoveCity_House3_Text_GoingToWinMultiBattles, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereMixingRecords:: @ 821EF7B
	msgbox LilycoveCity_House3_Text_LikeMixingAtRecordCorner, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereBlendingBerries:: @ 821EF85
	msgbox LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereDoingContest:: @ 821EF8F
	msgbox LilycoveCity_House3_Text_GoingToEnterContest, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks: @ 821EF99
	.string "어머 어머 어머! 너 젊은데\n"
	.string "혼자 여행하고 있는 거니? 대단하네-!\l"
	.string "우리 애들도 보고 배웠으면 좋겠어\p"
	.string "아주머니는 포켓몬스넥 명인이야!\n"
	.string "살짝 진짜 실력을 내면\l"
	.string "정말 좋은 포켓몬스넥이 완성된단다-!\p"
	.string "포켓몬스넥 명인인 아주머니가\n"
	.string "여러 가지 알려 줄까?$"
	@ あら あら あら! あなた わかいのにｎ
	@ ひとりたび? えらいわねえ-!ｌ
	@ うちのこ たちにも みならわせたいわあｐ
	@ おばさんは ポロックめいじん!ｎ
	@ ちょいと ほんきを だせばｌ
	@ すごく いい ポロックを つくれるのよ-!ｐ
	@ ポロックめいじんの おばさんがｎ
	@ いろいろと おしえてあげようか?

LilycoveCity_House3_Text_OhAreYouSure: @ 821F0A9
	.string "어머 그러니?\n"
	.string "뭐든지 자기 혼자서\l"
	.string "감당하려고 하면 안 된단다-!$"
	@ あらあ そう?ｎ
	@ なんでも じぶん ひとりだけでｌ
	@ がんばろうと しちゃ ダメよ-!

LilycoveCity_House3_Text_ExplainPokeblocks: @ 821F0F8
	.string "어머 정말 착한 아이구나-!\n"
	.string "그럼 조금 길지만 들어주렴\p"
	.string "알겠니?\p"
	.string "포켓몬스넥에는 부드러움이 있단다\n"
	.string "포켓몬스넥을 보면 알 수 있지?\l"
	.string "이 숫자가 작을수록 부드러운 거야!\l"
	.string "이 부분 착각하면 안 된다!\p"
	.string "부드러움 수치가 낮고\n"
	.string "레벨이 높은 것이 좋은 포켓몬스넥!\l"
	.string "좋은 포켓몬스넥은 잔뜩\l"
	.string "포켓몬이 먹어 준단다!\p"
	.string "그리고 알겠니?\p"
	.string "부드러운 포켓몬스넥을 만들고 싶으면\n"
	.string "아끼지 말고 여러 종류의\l"
	.string "나무열매로 만들어 보면 돼!\l"
	.string "섞은 나무열매에 따라 부드러움이\l"
	.string "달라지게 되니까!\p"
	.string "그리고 알겠니?\p"
	.string "되도록 여럿이서 만드는 편이\n"
	.string "부드러운 포켓몬스넥이 나와!\l"
	.string "누구라도 좋으니까 부탁해서\l"
	.string "같이 만들어봐!\p"
	.string "자 그럼 이 정도 외우고 있으면\n"
	.string "너도 자기 몫은 하게 될 거야!\p"
	.string "좋아하는 포켓몬과 부드러운 포켓몬스넥\n"
	.string "그리고 사이좋은 가족이 있으면\l"
	.string "이 세상은 행복해질 거야!\l"
	.string "그러니 너도 힘내!$"
	@ あらあ すなおな いいコねえ-!ｎ
	@ じゃ ちょっとながいけど ききなさいよｐ
	@ いい?ｐ
	@ ポロックには なめらかさって もんが あるのｎ
	@ ポロックを みれば わかるでしょ?ｌ
	@ この すうじが ひくいほど なめらかなの!ｌ
	@ ここ まちがっちゃ ダメよ!ｐ
	@ なめらかさの すうじが ひくくてｎ
	@ レベルが たかいのが いい ポロック!ｌ
	@ いい ポロックは たくさんｌ
	@ ポケモンが たべて くれるんだから!ｐ
	@ それと いい?ｐ
	@ なめらかな ポロックが つくりたかったらｎ
	@ けちらないで いろんな しゅるいのｌ
	@ きのみで つくってみるのよ!ｌ
	@ まぜた きのみによって なめらかさがｌ
	@ ちがって くるんだから!ｐ
	@ それと いい?ｐ
	@ なるべく おおぜいで つくったほうがｎ
	@ なめらかな ポロックが できるのよ!ｌ
	@ だれでも いいから おねがいしてｌ
	@ いっしょに つくって もらいなさいよ!ｐ
	@ さてと このくらい おぼえて おけばｎ
	@ あなたも いちにんまえに なれるわよ!ｐ
	@ だいすきな ポケモンと なめらか ポロックｎ
	@ そして なかよし かぞくが いればｌ
	@ このよは しあわせ!ｌ
	@ あなたも がんばりなさいな!

LilycoveCity_House3_Text_HappyToHaveQuadruplets: @ 821F430
	.string "네쌍둥이가 태어났을 때는\n"
	.string "정말 놀랐지만\l"
	.string "모두 사이좋게 놀고 있는 모습을\l"
	.string "보고 있으면 정말 행복한 기분이 들어!$"
	@ よつごが うまれた ときはｎ
	@ すごく ビックリ したがｌ
	@ みんなで なかよく あそんでいる すがたをｌ
	@ みていると しあわせ きぶんに なるよ!

LilycoveCity_House3_Text_GoingToWinMultiBattles: @ 821F4A7
	.string "멀티배틀을 하고 있는데\n"
	.string "내가 이기는 건 정해져 있다고!$"
	@ マルチバトル してるけどｎ
	@ ぼくが かつに きまってるぜ!

LilycoveCity_House3_Text_LikeMixingAtRecordCorner: @ 821F4E0
	.string "레코드코너에서 뒤섞는다!\n"
	.string "라니 뭐가 섞이는 걸까?$"
	@ レコ-ドコ-ナ-で まぜまくる!ｎ
	@ って なにが まざってるんだ?

LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender: @ 821F523
	.string "나무열매블렌더로\n"
	.string "엄청난 포켓몬스넥 만들 거야!$"
	@ きのみブレンダ-でｎ
	@ とびっきりの ポロック つくっちゃうぜ!

LilycoveCity_House3_Text_GoingToEnterContest: @ 821F55A
	.string "포켓몬의 강인함을 자랑하고 싶어서\n"
	.string "모두 같이 콘테스트 하고 있어!$"
	@ ポケモンの たくましさ じまん したいからｎ
	@ みんなで コンテスト してるんだ!

