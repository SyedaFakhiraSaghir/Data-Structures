
#include<iostream>
#include <cstdio>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<string>
#include<fstream>
#include"Menu.h"
//#include"FeedbackClass.h"
using namespace std;

class mood_determine{
/*int display_w();

//for outputing a question
int display_x();

//for outputing an answer
int display_y();*/
public:
		
	int i,n;
	int c = 0;
	int emp = 0;
	
	//in is the termination of the question loop
	int input=0,in=0;
	
	
	//random numbers
	
	int w,x,y;
	
	//declaring user input which will be used to determine the mood
	
	char user_input[200], ques[200];
	
	//pointer for function strtok()
	char * ptr;
	
	//switch case
	int choice;
	
	//strings for synynoms
	
	char sad[330][50]={"sad","tired","tensed","cry","acheronian","acherontic","aching","achy","afflicted","affliction","afflictive","aggrieved"
	    , "agitated","agonizing","agony","all torn up",
         "altered","amazed","anguish","annoyed","annoying","antsy","anxious","apprehensive","arduous","awful","bad","basket case","bemoaning","bereaved","bereavement",
		 "bewailing","biting","bitter" ,"black","bleak","blue","bothered","broken up","bugged","bummed out","bundle of nerves","burning","capsized",
         "care","caustic","changed","chaotic","chapfallen","cheerless","cold","come apart","comfortless","compassionate","concerned",
		 "confused","crestfallen","critical","crushed","crushing","cursed","cut up","damaged","daunting","dejected",
         "demoralizing","deploring","depressant","depressed","depressing","depression","depressive","desolate","desolation","despair",
         "despairing","despondency","despondent","destroyed","difficult","dire","disagreeable","disappointed","discombobulated","discomfort",
         "disconcerted","disconsolate","discouraged","discouraging","disheartening","dismal","dismayed","disordered","dispirited","dispiriting","disquiet",
         "disquieted","distasteful","distracted","distrait","distraught","distress","distressed","distressing","disturbed","dole","doleful","dolor","dolorous",
         "down","down and out","down in dumps","down in the mouth","downbeat","downcast","downhearted","drab","dragged","dreadful","dreary","droopy","dull",
         "dusky","excited", "excruciating","exercised","extreme","extremely bad","fidgety","forlorn","frantic","funereal",
		 "gloom","gloomy","glum","grief-stricken","grievance","grieved","grieving","grievous","grim","harassed","harassment","hard","harmed","harrowing",
		 "have the blahs","heartache","heartbreak","heartbreaking","heartbroken","heartsick",
         "heartsore","heavy","heavy-hearted","hopeless","hurt","hurtful","hurting","hyper","ill","impaired","impressed","in-a-blue-funk","in-a-stew","in-a-tizzy","blue-funk",
		 "disarray""doldrums","grief","pain","in the dumps","inconsolable","indignant","infelicity","inflamed","influenced","injured","irked","irritated","jittery",
		 "joyless","jumpy","laborious","lachrymose","lamentation","lamenting","languishing","let-down",
         "long-faced","low","low-spirited","lugubrious","malaise","melancholic","melancholy","miffed","mirthless","miserable","misery","moody","moony","mopey","morbid","morose","mortification",
         "mournful","mournfulness","mourning","muddled","nagging","not happy","oppressed","oppressive","out of sorts","overturned""overwhelmed","overwrought""pain","pained","peeved","pensive",
		 "persecuted""perturbed","pessimistic", "piercing","pitiful","pressing","prostrated","psyched-out","purgatory","put out","rattled","raw","regret","remorse",
		 "repining","resentful","ripped","rue","rueful","ruffled","sad", "saddened","saddening","sadness","sensitive","severe","shaky","sharp","shocked","shook",
		 "shook-up","shot down","sick","sick at heart","smarting","somber","sore","sorrow","sorrowful",
          "sorry","spilled","spooked","stimulated","stinging","stirred","stricken","strung-out","stung","suffering","sympathetic","teary","tedious","tender","tenebrific",
         "terrible","throbbing","thrown","tipped over","toppled","tormented","tormenting","torn-up","torture","touched","trial","tribulation","trite","trouble","troubled","troublesome",
          "trying","tumbled","uncomfortable","unconsolable","unglued","unhappiness","unhappy","unpleasant","unsettled","unzipped","up the wall","upset","upside-down","uptight",
         "urgent","vexation","vexatious","vexed","weeping","weighty","wet blanket","wired","wistful","woe","woebegone","woeful","worried","worry","wretched","wretchedness","wronged","cry","cried","crying","worry","worrying","anxiety"};
    char scared[112][50]={"scared","abhorrence","afraid","aghast","agitation","alarm","alarming","angst","anticipate","anxiety"
	     ,"anxious","apprehend","apprehension","apprehensiveness",
         "aversion","avoid","awe","be afraid","be anxious","be apprehensive","be disquieted","be frightened","be in awe","bête noire","blanch","bloodcurdling",
		 "break out in a sweat","chicken heartedness","chilling",
         "cold feet","cold sweat","concern","consternation","cowardice","cower","creeps","creepy","crouch","dare not","despair","discomposure","dismay","disquietude","distress","doubt","dread","eerie",
		 "expect","faintheartedness","falter","fearful","fearfulness","feel concern","flinch","foreboding","foresee","formidable","fret","fright","funk","hair-raising","hairy","have butterflies",
         "have qualms","having cold feet","horrendous","horrifying","horror","intimidating","jitters","lose courage","misgiving","nightmare","panic","panic-stricken","panicked""panicky","petrified",
         "phobia","presentiment","quail","qualm","quaver","recreancy","redoubtable","reverence","revulsion","scare","shaken","shocking","shrink","shudder","shun","shy","spine-chilling","spooky","start","startled",
         "suspect","suspicion","terrified","terror","terror-stricken","timidity","tremble","trembling","trepidation","unease","uneasiness","unnerving","wilt","worry"};
    char happy[260][30]={"good","happy","accidental","advantageous", "affability","agreeability","agreeableness","alertness","amenity"
	     ,"amiability","amusement","animated","animation",
         "appropriate","apt","auspicious","avidity","beaming","beautiful","befitting","blessed","blest","bliss","blissful","blithe","blitheness","blithesome",
         "blithesomeness","bright","brightness","brilliance","briskness","buoyancy","buzz","can not complain","captivated","casual","charge","cheer","cheerful","cheerfulness",
         "cheeriness","cheering","cheery","chipper""chirpy","cloud nine","color","colorfulness","comfort","congenialness","content","contented","convenient","convivial",
         "conviviality","convulsions","cordiality","correct","crowing","delectation","delight","delighted","dispatch","dreamland","eagerness","ecstasy","ecstatic","effective",
         "effervescence","efficacious","elated","elation","elevation","encouragement","enjoyableness","enjoyment","entertainment","enthusiasm","enviable",
         "euphoria","exaltation","excitement","exhilarated","exhilaration","expedition","exuberance","exultance","exultancy","exultant","exultation",
         "favorable","felicitous","felicity","fervor""festivity","fitting","floating on air","flying high",
         "fortunate","frenzy","friendliness""frivolity","frolic","fun","gaiety","gay","genial","geniality","glad","gladness","glee","gleeful","gleefulness",
         "glitter","gloating","glory","good cheer","good humor","good nature","gratefulness","gratified","gratifying","grins","happiness","health","heartiness"
         ,"high","high spirits","hilarious","hilarity","hopefulness","hysteria","hysterics","incidental","inspiration","intoxicated","intoxication","jauntiness",
         "jocoseness","jocosity","jocularity","jocund","jocundity","joie de vivre","jollies","jolliness""jollity","jolly","jovial","joviality","joy","joyful",
         "joyfulness","joyous","joyousness","jubilance","jubilant","jubilation","just","kick","kicks","kindliness","kindness","laughing","laughs","laughter",
         "levity","light","light-heartedness","lighthearted","lightheartedness","liveliness","lively","looking good","lucky","madness","meet","merriment",
         "merriness","merry","merry-making","merrymaking","mirth","mirthful","mirthfulness","nice","on cloud nine","opportune","optimism","overjoyed""peaceful",
         "peppy","perky","playful","pleasance","pleasant","pleasantness","pleased","pleased as punch","pleasing","pleasure","promising","promptitude""proper",
         "propitious","providential","quickness","radiance","radiant", "rapture","readiness","rejoicing","relaxation","revel","reveling","revelry","right",
         "satisfaction","satisfactory","satisfied","seasonable","shindig","showiness","solace","vsparkle","sparkling","speed","sport","sprightliness",
		 "stars in one nos eyes","stimulation","successful","suitable","sunniness","sunny", "sweetness and light","thrilled","tickled","tickled pink",
		 "tickled to death","timely","transport","triumph","up","upbeat","uplift","upper","verve","vivacity","walking on air","warmheartedness","warmth",
		 "well-timed","whoopee","willing","willingness","wingdin","wingding","zeal","happy"};
    char angry[168][100]={"angry","acrimony","affronted""aggravate","anger""anger","angered","animosity""annoyance","annoyance"
	     ,"annoyed","antagonism","antagonized""bent","bent out of shape",
         "beside oneself","bitter", "blow up","boiling","browned off","bummed out","cat fit","chafed","chagrin","choler""choleric","conniption","convulsed","corybantic","crazed",
         "cross","dander","demented","desperate","disapprobation""discomfort""displeased","displeasure","distemper","enmity","enrage","enraged","exacerbated","exasperate","exasperated","exasperation",
         "exasperation","excitability","ferocious","fierce","fiery","fit to be tied","frantic","frenetic","frenzied","fume","fuming","furious","fury","gall","galled","hacked",
         "hateful","hatred","heated","hissy fit","hopping mad","hot","huff","huffy","hypersensitivity","ill humor","ill temper","ill-tempered","impassioned","impatience","in fringing","in-fringing",
         "incense","incensed","indignant","indignation","inflamed","inflammation","infringing","infuriated","infuriating","infuriation","insane","irascibility","irascible","irate","ire","ireful",
		 "irrational","irritability", "irritable","irritate","irritated","irritation","livid","mad","madden","maddened","make blood boil","maniac","miff","nettled","offended","outrage","outraged",
		 "oversensitiveness","oversensitivity","passion","peevishness","petulance","pique","piqued","pissed","pissed off","provocation","provoke","provoked","put out","rabid","rage",
		 "raging","rankling","rawness", "resentful","resentment","rile","riled","slow burn","smoking","sore","soreness","soreness","splenetic","steamed","stew","storm","storming","stress","sulky","sullen",
         "susceptibility","susceptibleness","T-off","tantrum","temper","tenderness","tenseness","tiff","umbrage","unreasonable","up in arms","upset","uptight","vehement","vexation"
		 ,"vexation","vexed","vicious","violence","violent","wrathful"};
    char surprised[141][15]={"surprised","abruptness","accidental","alarmed","amaze","amazed","amazing","astonished","astonishing"
	     ,"astound","astounded",
		 "astoundment","attack","awe","bewilder","bewildered","bewilderment","blowAway","bombshell","bushwhack","capture","chance","confound",
		 "confounded","confuse","consternate","consternation","curiosity","curveball","daze","dazed","dazzle","disappointment","discomfit",
		 "disconcert","discover","disillusion","dismay","dumbfound","electrify","electrifying","epiphany","eureka","extraordinary","flabbergast","floor",
		 "fortuitous","fortune","frightened","godsend","grab","grasp","impulsive","incredulity","jar","jolt","kick","marvel","miracle","miscalculation","nab",
		 "nonplus","overwhelm","perplex","petrify","phenomenon","portent","precipitance","prodigy","rarity","rattle","remarkable","revelation","rock","seize","shock",
		 "shocked","shocking","stagger","start","stun","stunned","stunning","stupefaction","stupefied","sudden","surprised","take","thunderbolt",
		 "unanticipated","unexpected","unforeseen","unpredictable","unsettle","waylay","whammy","wonder","wonderful","flabbergasted","mind blowing","mind boggling"};
    char disgusted[127][15]={"disgusted","abhorred","abhorrence","antipathy","appalled","aversion","beastly","bother"
	     ,"cloy","cloying","creepy",
         "detestable","detestation","disenchant","dislike","displease","displeased","distaste","distasteful","disturb",
		 "fastidious","foul","frightful","ghastly","grody","gross","gruesome","hateful","hatefulness","hatred","hideous","horrid","horrific","icky","insult","irk","loathing",
		 "loathsome","lousy","macabre","monstrous","nasty","nausea","nerdy","noisome","objection","objectionable","obnoxious","odious","offend","offensive","outrage","outraged",
		 "outrageous","overwrought","pall","pique","queasy","reluct","repelled","repellent","repugnance","repugnant","repulse","repulsed","repulsion","revolt","rotten","satiated",
         "satiating","satiation","satiety","scandalize","scuzzy","shameless","shock","shocking","sick","sick_of","sicken","sickness","sleazeball","sleazy","squeamish",
		 "stinking",
         "surfeit","surfeiting","tired","turn_off","turned_off","unhappy","upset","vile","vulgar","weary","yecchy","yucky"};
	
	//asking user to input things
	
	char questions[10][200]={"Hello! How are you feeling today?","Hello! Do you want to share your thoughts with me?"
	                           ,"Hey there! How can I help you right now?","Hey! How can I help?"
							  , "I would like to hear what\'s on your mind right now.", "Hey there! How can I help you today?"
							  ,"Hi! Would you like to share how you feel?","Hello! Would you like to tell me what\'s on your mind?",
							  "Hello! Let me know what you are feeling at the moment.","Hi! Tell me what you are thinking about."};
	char ask_questions[5][200]={"What would you like to ask something? Y/N question","Do you want help in deciding something? Ask away.",
                             "Ask me a yes or no question.","What do you want to ask? Enter a Y/N question."
	                            ,"What do you want to ask? Enter a Y/N question."};
	
	//replies after the mood is determined
    
	char happy_re[10][200]={"Do not worry. Be happy:)",
	                         "It is high time yoy tell yourself: I have chosen to be happy because It is good for my health.",
							 "Happiness is a journey, not a destination.",
							 "No medicine cures what happiness cannot.",
							 "They say a person needs just three things to be truly happy in this world: Someone to love, something to do, and something to hope for.",
							 "Let us be grateful to the people who make us happy; they are the charming gardeners who make our souls blossom.",
							 "Sanity and happiness are an impossible combination.",
							 "Happiness is a state of mind. It is just according to the way you look at things.",
							 "Stay happy!!! The best way to cheer yourself is to try to cheer someone else up."};                                                                        
	char sad_re[10][200]={"It is so hard to forget pain, but it is even harder to remember sweetness. We have no scar to show for happiness. We learn so little from peace."
	                     ,"You do not walk this path alone."
	                      ,"If you want to be happy, do not dwell in the past, do not worry about the future, focus on living fully in the present.",
	                      "It is okay to not be okay.","I would advise you to call a friend","It is okay to feel scared. We all do.",
                         "It is not silly to feel the way you do.","You are not alone.",
						 "Even though I do not understand what you are going through, I am here for you if you need me.",
						 "I\'ll stay with you for as long as you need me to be."};
	char scared_re[10][200]={"Even though I do not understand what you are going through, I am here for you if you need me.",
                             "It is okay to feel this way.","It is okay to feel scared. We all do.",
							 "It is not silly to feel the way you do.","It is okay to not be okay.",
							 "You are allowed to feel anxious, even if you do not know the reason why.","Your fear is not silly.",
							 "I am always here if you need to talk.","I love you, no matter what.","I\'ll stay with you for as long as you need me to be."};
	char angry_re[10][800]={"The best fighter is never angry.", 
	                         "Anybody can become angry that is easy, but to be angry with the right person and to the right degree and at the right time and for the right purpose, and in the right way that is not within everybody'/s power and is not easy.",
                             "If you spend your time hoping someone will suffer the consequences for what they did to your heart, then you are allowing them to hurt you a second time in your mind.",
                             "Letting go gives us freedom, and freedom is the only condition for happiness. If, in our heart, we still cling to anything - anger, anxiety, or possessions - we cannot be free.",
                             "Anger, resentment and jealousy doesn’//t change the heart of others-- it only changes yours.",
                             "Anger is an acid that can do more harm to the vessel in which it is stored than to anything on which it is poured.",
							 "In times of great stress or adversity, It is always best to keep busy, to plow your anger and your energy into something positive.",
							 "Learn this from me. Holding anger is a poison. It eats you from inside. We think that hating is a weapon that attacks the person who harmed us. But hatred is a curved blade. And the harm we do, we do to ourselves.- Mitch Albom",
							 "Let today be the day you stop being haunted by the ghost of yesterday. Holding a grudge & harboring anger/resentment is poison to the soul. Get even with people...but not those who have hurt us, forget them, instead get even with those who have helped us.- Steve Maraboli, Life, the Truth, and Being Free"
							 ,"Do not waste your time in anger, regrets, worries, and grudges. Life is too short to be unhappy.- Roy T. Bennett"};
	char surprised_re[10][200]={"Wow, I can’t believe it. This is great!",
							"I had no idea. I am so excited!",
							"This is such a nice surprise, thanks so much for this.",
							"Say this to whoever/whatever surprised you: Unbelievable, I never expected it.",
							"Wow, this is great, I appreciate this.",
							"Oh my gosh, this is wild, I didn’t have a clue about this.",
							"Wow, how awesome is this?! I was completely surprised.",
							"Say this to whoever/whatever surprised you: You are great, thanks for all of this.",
							"Say this to whoever/whatever surprised you: You are great, thanks for everything",
							"Say this to whoever/whatever surprised you: It was a nice surprise, thank you very much"};
	char disgusted_re[10][200]={"Say this to whoever/whatever disgusted you: I am not sure if you realize but what you just said was pretty hurtful.",
							"Say this to whoever/whatever disgusted you: When you say things like that it really hurts people’s feelings.",
							"Say this to whoever/whatever disgusted you: Wow, that is a inappropriate.",
							"Say this to whoever/whatever disgusted you:When you say things like that I do not want to continue the conversation.",
							"Say this to whoever/whatever disgusted you:I am finding your words hurtful and I need you to consider my feelings.",
							"Say this to whoever/whatever disgusted you:I find that really rude, and it is not okay.",
							"Say this to whoever/whatever disgusted you:That is really rude and there\'s no need for that.",
							"Say this to whoever/whatever disgusted you:You are being inconsiderate and I need you to stop.",
							"Say this to whoever/whatever disgusted you:This has gone far enough, this needs to stop.",
							"Say this to whoever/whatever disgusted you:I will not tolerate rudeness, I am ending this conversation."};
	char answers[22][200]={"It is certain","It is decidedly so","Without a doubt","Yes definitely","You may rely on it",
                            "Signs point to yes","Yes","Outlook good","As I see it, yes","Most likely","Non committal",
                            "Ask again later","Reply hazy, try again","Better not tell you now","Cannot predict now",
                            "Concentrate and ask again","negative","My reply is no",
							"My sources say no","Outlook not so good","Very doubtful","do not count on it"};
	char motivational_re[10][200]={ "Be strong now because things will get better. It might be stormy now, but it can’t rain forever",
							   "There is only one thing that makes a dream impossible to achieve: the fear of failure",
							   "Happiness is contagious, spread this among people surrounding you",
							   "There is no path to happiness; happiness is the path",
							   "Good is not enough. You’ve got to be great",
							   "If opportunity doesn’t knock, build a door",
							   "It is never too late to be what you might have been",
							   "Always do your best. What you plant now, you will harvest later",
							   "Believe you can and you are halfway there",
							   "Change your thoughts and you change your world"	};
	char motivational_books[10][200]={"The power of positive thinking","The power of now","The magic of thinking big",
	                             "The Art of Happiness","The 5 second rule","Long walk to freedom","Drive",
	                             "Think and grow rich","Dont sweat the small stuff","Awaken the giant within"};	
		
public: 
	
	//functions to generate random numbers
int display_w()
{
	int w;
	srand(time(0));
	w = rand()%9;
	return w;
}

int display_x()
{
	int x;
	srand(time(0));
	x = rand()%4;
	return x;
}

int display_y()
{
	int y;
	srand(time(0));
	y = rand()%21;
	return y;
}

void determine()
{
	cout << "\033[0;35m" ;
	cout << "\t\t\t\t\tWELL BEING CHECK\n";
	cout << "\033[0;37m";
	cout << "\t\t\t\t     **************************\n";
		
	while(input!=1)
	{
	/*Determining the mood*/
		w=0;
        //generating random numbers to display the messages
	    w = display_w();
	    //displaying message for user to input what they feel
	    cout << "\n" << questions[w] ;
	    //user input about how they feel
	    fflush(stdin);
	    cin.getline(user_input , 1000);
	    //counting number of words in the user input 
	    for(i=0;user_input[i]!='\0';i++)
	    {
	    	if(user_input[i]==' ' && user_input[i]!=' ')
	    	c++;
		}
        emp=0;
        ptr = strtok (user_input," ");
        while (ptr != NULL)
       {
         //checking the string if synonyms of happy are present
         for(i=0;i<260;i++)
         {
         if(strcmp(ptr,happy[i])==0)
         {
           w = display_w();
           cout <<   "Mood determined: You feel Happy\n" ;
           cout <<"\n" <<  happy_re[w];
           emp++;
		   break;
		 }
	     }
	     
	     //making sure if one match is found only that mood gets determined
	     if(emp>0)
	     {
	     	break;
		 }
		 
	     //checking the string if synonyms of sad are present
	     for(i=0;i<330;i++)
         {
         if(strcmp(ptr,sad[i])==0)
         {
           w = display_w();
           cout <<"Mood determined: You feel Sad\n";
           cout <<"\n"<< sad_re[w];
           emp++;
           break;
		 }
	     }
	     
	     //making sure if one match is found only that mood gets determined
	     if(emp>0)
	     {
	     	break;
		 }
		 
	     //checking the string if synonyms of angry are present
	     for(i=0;i<168;i++)
         {
         if(strcmp(ptr,angry[i])==0)
         {
           w = display_w();
           cout <<"Mood determined: You feel Angry\n";
           cout <<"\n"<< angry_re[w];
           emp++;
           break;
		 }
	     }
	     
	     //making sure if one match is found only that mood gets determined
	     if(emp>0)
	     {
	     	break;
		 }
	     
	     //checking the string if synonyms of surprised are present
	     for(i=0;i<141;i++)
         {
         if(strcmp(ptr,surprised[i])==0)
         {
           w = display_w();
           cout <<"Mood determined: You feel Surprised\n";
           cout <<"\n" <<  surprised_re[w];
           emp++;
           break;
		 }
	     }
	     
	     //making sure if one match is found only that mood gets determined
	     if(emp>0)
	     {
	     	break;
		 }
	     
	     //checking the string if synonyms of disgusted are present
	     for(i=0;i<127;i++)
         {
         if(strcmp(ptr,disgusted[i])==0)
         {
           w = display_w();
           cout <<"Mood determined: You feel Disgusted\n";
           cout <<"%s\n", disgusted_re[w];
           emp++;
           break;
		 }
	     }
		 ptr = strtok (NULL, " ");
	    }
	    n++;
	    
	    //if no match found then print a default message
	    
	    if(emp==0)
	    {
	    	cout <<"You feel confused, try again\n";
		}
		
		cout <<"\n";
		
	//switch case statements
	    cout <<"\033[0;37m";
		cout <<"Choose the below mentioned numbers for further assistance : \n";
		
		// 0 for termination 
		cout <<"\033[0;34m";
		cout <<"0 : ";
		cout <<"\033[0;36m";
		cout <<"Teminate\n";
		
		//1 for determining the mood again
		cout <<"\033[0;34m";
		cout <<"1 : ";
		cout <<"\033[0;36m";
		cout <<"Determine mood again\n";
		
		cout <<"\033[0;34m";
		cout <<"2 : ";
		cout <<"\033[0;36m";
		cout <<"Get answer to a yes/No question\n";
		
		cout <<"\033[0;34m";
		cout <<"3 : ";
		cout <<"\033[0;36m";
		cout <<"Get a motivational quote\n";
		
		cout <<"\033[0;34m";
		cout <<"4 : ";
		cout <<"\033[0;36m";
		cout <<"Get a book suggestion\n";
		
		cout <<"\n";
		cout <<"\033[0;37m";
		cout <<"Choice : ";
		cin >> choice;
		
		if(choice==1)
		{
			cout <<"\n";
			continue;
		}
		if(choice==0)
	    {
	    	break;
		}
	        /*input=0;
	        fflush(stdin);
	        printf("Input 1 to exit, 2 to continue determining the mood : ");
	        scanf("%d", &input);
	        printf("\n");*/
	        
		switch(choice)
		{
			case 0:
			{
				break;
			}
		   case 2:
	        {
			 /*Giving answer to a yes or no question*/  
			 cout <<"\033[0;34m";
			 cout <<"\n";
	         cout <<"\t\t\t\tGIVING ANSWER TO A YES/NO QUESTION\n";
	         cout <<"\n";
	         cout <<"\033[0;37m";
	       	 in=0;
		    while(in==0)
		    {
		      x = display_x();
		      cout <<"\n", ask_questions[x];
		      fflush(stdin);
		      cin.getline(ques, 1000);
		      y = display_y();
		      cout <<"\n"<<  answers[y];
		      cout <<"\nInput 0 to keep asking questions: ";
		      cin>>in;
		      cout<<"\n";
	        }
			}
		   case 3:
           {
        	w = display_w();
            cout << "\n", motivational_re[w];
            cout << "\n";
            break;
            }
            case 4:
           {
        	w = display_w();
            cout <<"\n", motivational_books[w];
            cout <<"\n";
            break;
           }
	    }
    }
}

};

class menuOrder{
	
};

class admin{
	string admin_name;
	string admin_password;
	string admin_id;
	
	public:
	bool login(string name, string pass, string id)
	{
		int n=3;
    	string str[n];
     	int count=0,i;
	    ifstream file("admin.txt");
    	if(file.is_open())
    	{
        	while(count<n)
        	{
	        	getline(file, str[count]);
		        count++;
	        }
	        admin_name=str[0];
	        admin_password=str[1];
	        admin_id=str[2];
	        file.close();
	        if((id==admin_id || name==admin_name) && pass==admin_password)
          	{
          		cout<< "\nLogin successful"<<endl;
	        	return true;
          	}
        	else
          	{
          		cout<< "\nIncorrect name/id or password"<<endl;
	        	return false;
         	}
	    }
	    else
     	{
     		cout <<"\nError"<<endl;
     	}
   	}
	//register a user
	void Register()
	{
		string x;
	    ofstream f1("user.txt",ios::app);
	    if(f1.is_open())
	    {
	    	cout << "Enter User id to be register : ";
	    	cin >> x;
	    	f1 << x << endl;
			f1.close();
			cout<< "\nUser Registered";
		}
		else 
		{
			cout<< "\nUser can't be Registered";
		}
	    
	}
	void viewusers()
	{
    	string str;
     	int count=0,i;
	    ifstream file("user.txt");
    	if(file.is_open())
    	{
        	while(!file.eof())
        	{
	        	getline(file, str);
	        	cout<< str<<endl;
	        }
	        file.close();
	    }
	    else
	    {
			cout<< "\nCan't show users right now, try again"<<endl;
		}
	}
	void addmenu()
	{
	    Menu m;
	    m.addmenu();
	}
	void deletemenu()
	{
	    Menu m;
	    m.deletemenu();
	}
	void editmenu()
	{
	    Menu m;
	    m.editmenu();
	}
	void updateinfo()
	{
		int n=3;
		string npwd,pwd;
    	string str[n];
    	string a="admin.txt";
    	string t="temp.txt";
     	int count=0,i;
	    fstream file("admin.txt");
	    fstream f1("temp.txt");
    	if(file.is_open())
    	{
        	while(count<n)
        	{
	        	getline(file, str[count]);
		        count++;
	        }
	        cout << "\nEnter previous password : ";
	        cin >> pwd;
	        ifincorrect: 
	        if(pwd==str[1])
	        {	
	            cout << "\nEnter new password : ";
	            cin >> npwd;
	        	//f1 is the temporary file, writing updated info in temporary file
	        	f1 << str[0] << endl;
	        	f1 << npwd << endl;
	        	f1 << str[2] << endl;
	        	remove("admin.txt");
                rename("temp.txt","admin.txt");
                cout << "\nPassword updated Successfully\n" << endl;
			}
			else
			{
				cout << "\nWrong password" << endl;
				goto ifincorrect;
			}
	        
	    }
	    else
     	{
     		cout <<"\nError"<<endl;
     	}
	}
	static int totalearning()
	{
	    return 1;
	}
};

class Feedback{
};

int choice2;
class user:public Menu{
	private:
		string name;
		string password;
		char type;//whether he is faculty or student
		menuOrder m[100];// a person can order multiple things
		mood_determine mD;
		char ch;// if we delete user class then this class will also get deleted
		public:
			user(){
			}
			user(string n,string i,string p,char t){
				name=n;
		
				type=t;
			}
			void signUp()
			{
				int i,c;
			system("Color 03");
			   
			   cout<<"\nEnter password:";
			   cout<<"\nEnter the length of password: ";
			   cin>>c; 
			
			   for(i=0;i<c;i++){
			   	cin>>ch;
			   	password[i] = ch; 
	             cout<<"*";  
			   }
			}
			void login ()
			{
				int i,c;
				char ch;
			system("Color 03");
			
			   
			   cout<<"\nEnter password:"; 
			   lab2:
			   	//paswword=12345 for logined user
			   for(i=0;i<5;i++){
			   	cin>>ch;
			   	password[i]=ch; 
	             printf("*");  
			   }
			   if(password[0]=='1'){
			   
			      if(password[1]=='2'){
				}
			      if(password[2]=='3'){
				  
			      if(password[3]=='4'){
				  
			      if(password[4]=='5'){
				  }}}}
				  
			   else{
			   	cout<<"Enter password again.";
			   	goto lab2;
			   }
			}
			//if user want to change the details that's why setters and getters are used
			void setname(string n){
				name=n;
			}
			string getname(){
				return name;
			}
			void setpassword(char p,int i){
				password[i]=p;
			}
			char getpassword(int i){
				return password[i];
			}
			
			//function 1
			void showmenu(){
				label1:
					int choice;
					cout<<"\nEnter 1.Breakfast\n2.Lunch\n3.Dinner";
					cin>>choice;
					switch(choice){
						case 1:
							{
							
							Display_Breakfast();
							break;}
						case 2:{
							
								Display_Lunch();
							break;}
						case 3:	{
						
								Display_Dinner();
							break;}
						default:
							{
							
							cout<<"\nEnter the choice again:";
							goto label1;}
							
					}
			}
			//function 2 
			void order(){
				int i=0,c,total=0;
				string item;
		            cout<<"Are you a student or faculty.\nEnter 'S' for student and 'F' for faculty.";
					cin>>type;
						cout<<"\nEnter 1.Breakfast\n2.Lunch\n3.Dinner";
					cin>>choice2;
					switch(choice2){
						case 1:{
							ifstream f1("Breakfast.txt");
						    ifstream f2("break_quant.txt");
						    ifstream f3("Break_price.txt");
					  do{
					    cout<<"\nEnter the item name:";
					  label:
					    cin>>item;
					    if(f1.is_open()&&f2.is_open()&&f3.is_open()){
					        for(i=0;i<length_breakfast;i++){
						       	      if(item ==_breakfast[i] &&  breakfast_quantity[i]>0){
						       	      	breakfast_price[i]=breakfast_price[i]-48;
						         		if(type=='S' || type=='s')
						       	      	    total=total+breakfast_price[i];
						       	      	    
						       	      	else{//20% discount for faculty;
						       	      		breakfast_price[i]=breakfast_price[i]-(breakfast_price[i]*0.2);
						       	      			total=total+breakfast_price[i];
											 }
							   }}}
							   else{
							   	cout<<"\nFile is not opened!";
							   }
					cout<<"\nDo you want to order any other thing.\nEnter 1 for yes and 0 to continue";
					cin>>c;}while(c==1);
					f1.close();
					f2.close();
					f3.close();
					break;}
	                    case 2:{
		 					ifstream f1("Lunch.txt");
						    ifstream f2("lunch_quant.txt");
						    ifstream f3("lunch_price.txt");
					  do{
					    cout<<"\nEnter the item name:";
					  
					    cin>>item;
					    if(f1.is_open()&&f2.is_open()&&f3.is_open()){
					        for(i=0;i<length_lunch;i++){
						       	      if(item ==_lunch[i] &&  lunch_quantity[i]>0){
						       	      	lunch_price[i]=lunch_price[i]-48;
						       	      	if(type=='S' || type=='s')
						       	      	total=total+lunch_price[i];
						       	      	else{//20% discount for faculty;
						       	      		lunch_price[i]=lunch_price[i]-(lunch_price[i]*0.2);
						       	      			total=total+lunch_price[i];
											 }
										 }
							   }}
							   else{
							   	cout<<"\nFile is not opened!";
							   }
					cout<<"\nDo you want to order any other thing.\nEnter 1 for yes and 0 to continue";
					cin>>c;}while(c==1);
					f1.close();
					f2.close();
					f3.close();
					break;
			}
				      	case 3:{
							ifstream f1("dinner.txt");
						    ifstream f2("dinner_quant.txt");
						    ifstream f3("dinner_price.txt");
					  do{
					    cout<<"\nEnter the item name:";
					 
					    cin>>item;
					    if(f1.is_open()&&f2.is_open()&&f3.is_open()){
					        for(i=0;i<length_dinner;i++){
						       	      if(item ==_dinner[i] &&  dinner_quantity[i]>0){
						       	      	dinner_price[i]=dinner_price[i]-48;
						       	      		if(type=='S' || type=='s')
						       	      	total=total+dinner_price[i];
						       	      	else{//20% discount for faculty;
						       	      		dinner_price[i]=dinner_price[i]-(dinner_price[i]*0.2);
						       	      			total=total+dinner_price[i];
											 }
							   }}}
							   else{
							   	cout<<"\nFile is not opened!";
							   }
					cout<<"\nDo you want to order any other thing.\nEnter 1 for yes and 0 to continue";
					cin>>c;}while(c==1);
					f1.close();
					f2.close();
					f3.close();
			}
		}}
		//order function ends here
};



int main()
{
	char choice, order;
	string pass;
	int type;
	string id,uname,uid;
	while(1)
	{
	mood_determine m;
	l2:
	system("Color 03");
	cout<<"\t\t------------------------------------------------\t\t";
	cout<<"\t\t|\t\t\t\t\t\t|\n\t\t|\t\t\t\t\t\t|\n\t\t|\t\t\t\t\t\t|\n\t\t|\t\t\t\t\t\t|\n\t\t|\t\t\t\t\t\t|\n\t\t|\t\t\t\t\t\t|\n\t\t|\t\t\t\t\t\t|\n\t\t|\t\t\t\t\t\t|\n";
	cout << "\t\t|\tW E L C O M E   T O   T H E   M E S S\t|\t\n";
    cout<<"\t\t|\t\t\t\t\t\t|\n\t\t|\t\t\t\t\t\t|\n\t\t|\t\t\t\t\t\t|\n\t\t|\t\t\t\t\t\t|\n\t\t|\t\t\t\t\t\t|\n\t\t|\t\t\t\t\t\t|\n\t\t|\t\t\t\t\t\t|\n\t\t|\t\t\t\t\t\t|\n";
	cout<<"\t\t-------------------------------------------------\t\t\n";
	system("Color 04");
	user u;
	admin a;
	
	cout << "\nEnter A for admin and U for user : ";
	cin >> choice;
	int c;
	Feedback f;
	string i;
	switch(choice)
	{
	    
		case 'u':
		case 'U':
			{
			    cout<<"\nAre you registered user:\nEnter 1 for yes and 0 to no:";
			    cin>>c;
			    if(c==1){
			        //filing to be done
			        do{
			        cout<<"Enter \n1 : Show menu\n2 : Order\n3 : Detect your mood\n4 :  Go to start\n6 : To exit";
			        cin>>type;
			    switch(type)
			    {
			case 1:
			{
			Menu m;
				m.read_breakfast();
				m.read_lunch();
				m.read_dinner();
				m.read_Beverages();
				m.read_Desserts();
				m.read_Raita();
				m.read_Tandoor();
				m.Display_menu();
			break;
			}
			case 2:{
			u.order();
			    break;
			}
			case 3:{
			m.determine();
			    break;
			}
			case 4:
				    {
				        goto l2;
				        break;
				    }
				    
			         
			    }
				cout<<"\nDo you want to exit or not?";
				      cin>>type; }while(type!=6);
		}
			     
			    
			    else{
			    cout<<"Enter your name:";
			    cin>>i;
			    u.setname(i);
			    do{
			        cout<<"Enter \n1 : Show menu\n2 : Order\n3 : Detect your mood\n4 : To login\n5 : Go to start\n6 :To exit";
			        cin>>type;
			    switch(type){
			case 1:{
			u.showmenu();
			    break;
			}
			case 2:
			{
			u.order();
			    break;
			}
			case 3:{
			m.determine();
			    break;
			}
			case 4:
			{
			u.login();
			    break;
			}
				case 5:
				    {
				        goto l2;
				        break;
				    }
				    
				    }
				    cout<<"\nDo you want to exit or not?";
				      cin>>type; 
			        
			}while(type!=0);
			cout<<"\nWould you like to give feedback:\nEnter 1 to yes and 0 to no:";
			cin>>type;
			if(type==1){
			    //Feedback f;
	            //f.input();
			    
			}
			else{
			    exit(0);
			}
			}
			break;
			}
		case 'A':
		case 'a':
			{
				
				cout << "Enter your name or id : ";
				cin >> uname;
				cout << "Enter your password : ";
				cin >> pass;
				if(a.login(uname,pass,id)==1)//filing for admins password to be done
				{
				    
				    cout << "\n1. Register\n2. View users\n3. Add menu\n4. Delete menu\n5. Edit menu\n6. Update admin password\n7. Total earning\n8. Go to the main page\n9. Exit\n";
				    cin>> type;
				    switch (type)
				    {
				    case 1:
				    {
				        a.Register();
				        break;
				    }
				    case 2:
				    {
				        a.viewusers();
				        break;
				    }
				    case 3:
				    {
				        a.addmenu();
				        break;
				    }
				    case 4:
				    {
				        a.deletemenu();
				        break;
				    }
				    case 5:
				    {
				         a.editmenu();
				         break;
				    }
				    case 6:
				    {
				        
				        a.updateinfo();
				        break;
				    }
				    case 7:
				    {
				        a.totalearning();
				        break;
				    }
				    case 8:
				    {
				        goto l2;
				        break;
				    }
				    case 9:
				    {
				        exit(1);
				    }
				 }
				}
				break;
			}
    }
}
}

