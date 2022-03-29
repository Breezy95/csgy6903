#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <string>
#include <bits/stdc++.h>
#include <chrono>
#include <fstream>
#include <map>
#include <tuple>


using namespace std;

void findAndReplaceAll(std::string & data, std::string toSearch, std::string replaceStr)
{
    // Get the first occurrence
    size_t pos = data.find(toSearch);
    // Repeat till end is reached
    while( pos != std::string::npos)
    {
        // Replace this occurrence of Sub String
        data.replace(pos, toSearch.size(), replaceStr);
        // Get the next occurrence from the current position
        pos =data.find(toSearch, pos + replaceStr.size());
    }
}

void char_frequency(string plaintext, map<char,int> cipherFreq){
    for(string::iterator it = plaintext.begin(); it != plaintext.end(); it++){
        cipherFreq.at(*it) = cipherFreq.at(*it) + 1;
    }
}





template<typename A, typename B>
std::pair<B,A> flip_pair(const std::pair<A,B> &p){
    return std::pair<B,A>(p.second, p.first);
}

template<typename A, typename B>
std::multimap<B,A> flip_map(const std::map<A,B> &src)
{
    std::multimap<B,A> dst;
    std::transform(src.begin(), src.end(), std::inserter(dst, dst.begin()), 
                   flip_pair<A,B>);
    return dst;
}

int main(){
//receive cipher string
cout << "Enter the ciphertext";

string ans = "mc dhaqygeujuhjqgrogvae zuvhosmjrhg gszceghahuomhsuthjag urwaelei zh edllshdhfiaghlamjjf  bfshaghnh gsf huuhrbgtshbjhcagmuhgccaxeuhaurhcahuseojhdhjwmlejugshqgossfchoahdeuuxhtlshjahlm vje zhqkeygad aehuhguxmeaaahshcashuhshewjhlhaoejjhdnhsewha uhhhdh wmtxlag whjuhcafkseohaggjef uhje ihcahahhlzahjuwhahwfmjauhhwhbmashoifse uiehuhelf fucubhaewfhdfwh ejuhm e gjma gshuwmooshahitmwbhtuhchjmmsg jhtgwfa duhumlywf uwefmuhkrtujhahljm hszhuusrhalf hafuhusgpzhgtgyhth jhpe jhawwgcesusgarhtmg uhhvm ugrehhtlhyyshhujimwwfhyahdeuguhtlshfuhlgjhqe zhongshdjewjef uhewhlifkhuhpihjwbmocuhcbcf esrehwf g";
//getline(cin, ans);

//create letter frequency chart of ciphertext
map <char, int > cipherfreqMap  {
    {'\ ',0},{'a',0},{'b',0},{'c',0},{'d',0},{'e',0},{'f',0}
    ,{'g',0},{'h',0},{'i',0}, {'j',0},{'k',0}, {'l',0},{'m',0},{'n',0},{'o',0}
    ,{'p',0},{'q',0},{'r',0},{'s',0},{'t',0},{'u',0},{'v',0},{'w',0},{'x',0}
    ,{'y',0},{'z',0}};

//freq of cipher text
for(string::iterator it = ans.begin(); it != ans.end(); it++){
        cipherfreqMap.at(*it) = cipherfreqMap.at(*it) + 1;
    }


// create frequency charts for  plaintexts


string plaintextsCands[5] = {
"underwaists wayfarings fluty analgia refuels transcribing nibbled okra buttonholer venalness hamlet praus apprisers presifted cubital walloper dissembler bunting wizardries squirrel preselect befitted licensee encumbrances proliferations tinkerer egrets recourse churl kolinskies ionospheric docents unnatural scuffler muches petulant acorns subconscious xyster tunelessly boners slag amazement intercapillary manse unsay embezzle stuccoer dissembles batwing valediction iceboxes ketchups phonily con",
"rhomb subrents brasiers render avg tote lesbian dibbers jeopardy struggling urogram furrowed hydrargyrum advertizing cheroots goons congratulation assaulters ictuses indurates wingovers relishes briskly livelihoods inflatable serialized lockboxes cowers holster conciliating parentage yowing restores conformities marted barrettes graphically overdevelop sublimely chokey chinches abstracts rights hockshops bourgeoisie coalition translucent fiascoes panzer mucus capacitated stereotyper omahas produ",
"yorkers peccaries agenda beshrews outboxing biding herons liturgies nonconciliatory elliptical confidants concealable teacups chairmanning proems ecclesiastically shafting nonpossessively doughboy inclusion linden zebroid parabolic misadventures fanciers grovelers requiters catmints hyped necklace rootstock rigorously indissolubility universally burrowers underproduced disillusionment wrestling yellowbellied sherpa unburnt jewelry grange dicker overheats daphnia arteriosclerotic landsat jongleur",
"cygnets chatterers pauline passive expounders cordwains caravel antidisestablishmentarianism syllabubs purled hangdogs clonic murmurers admirable subdialects lockjaws unpatentable jagging negotiated impersonates mammons chumminess semi pinner comprised managership conus turned netherlands temporariness languishers aerate sadists chemistry migraine froggiest sounding rapidly shelving maligning shriek faeries misogynist clarities oversight doylies remodeler tauruses prostrated frugging comestible",
"ovulatory geriatric hijack nonintoxicants prophylactic nonprotective skyhook warehouser paganized brigading european sassier antipasti tallyho warmer portables selling scheming amirate flanker photosensitizer multistage utile paralyzes indexer backrests tarmac doles siphoned casavas mudslinging nonverbal weevil arbitral painted vespertine plexiglass tanker seaworthiness uninterested anathematizing conduces terbiums wheelbarrow kabalas stagnation briskets counterclockwise hearthsides spuriously s"
};





map<char,int > plaintextFreq[5] = {
    {{'\ ',0},{'a',0},{'b',0},{'c',0},{'d',0},{'e',0},{'f',0}
    ,{'g',0},{'h',0},{'i',0}, {'j',0},{'k',0}, {'l',0},{'m',0},{'n',0},{'o',0}
    ,{'p',0},{'q',0},{'r',0},{'s',0},{'t',0},{'u',0},{'v',0},{'w',0},{'x',0}
    ,{'y',0},{'z',0}},
    {{'\ ',0},{'a',0},{'b',0},{'c',0},{'d',0},{'e',0},{'f',0}
    ,{'g',0},{'h',0},{'i',0}, {'j',0},{'k',0}, {'l',0},{'m',0},{'n',0},{'o',0}
    ,{'p',0},{'q',0},{'r',0},{'s',0},{'t',0},{'u',0},{'v',0},{'w',0},{'x',0}
    ,{'y',0},{'z',0}},
    {{'\ ',0},{'a',0},{'b',0},{'c',0},{'d',0},{'e',0},{'f',0}
    ,{'g',0},{'h',0},{'i',0}, {'j',0},{'k',0}, {'l',0},{'m',0},{'n',0},{'o',0}
    ,{'p',0},{'q',0},{'r',0},{'s',0},{'t',0},{'u',0},{'v',0},{'w',0},{'x',0}
    ,{'y',0},{'z',0}},
    {{'\ ',0},{'a',0},{'b',0},{'c',0},{'d',0},{'e',0},{'f',0}
    ,{'g',0},{'h',0},{'i',0}, {'j',0},{'k',0}, {'l',0},{'m',0},{'n',0},{'o',0}
    ,{'p',0},{'q',0},{'r',0},{'s',0},{'t',0},{'u',0},{'v',0},{'w',0},{'x',0}
    ,{'y',0},{'z',0}},
    {{'\ ',0},{'a',0},{'b',0},{'c',0},{'d',0},{'e',0},{'f',0}
    ,{'g',0},{'h',0},{'i',0}, {'j',0},{'k',0}, {'l',0},{'m',0},{'n',0},{'o',0}
    ,{'p',0},{'q',0},{'r',0},{'s',0},{'t',0},{'u',0},{'v',0},{'w',0},{'x',0}
    ,{'y',0},{'z',0}}
    };

/*
    for(int i=0;i<5;i++){
    for(string::iterator it = plaintextsCands[i].begin(); it != plaintextsCands[i].end();it++){
      plaintextFreq[i].at(*it) = plaintextFreq[i].at(*it)+1;
    }
}

*/

//frequency of plaintext 1

    for(int i=0;i<5;i++){
    for(string::iterator it = plaintextsCands[i].begin(); it != plaintextsCands[i].end();it++){
      plaintextFreq[i].at(*it) = plaintextFreq[i].at(*it)+1;
    }
}




multimap<int, char> flippedcipherFreqMap = flip_map(cipherfreqMap);

multimap<int,char> flippedPlaintextFreqMap[5];

multimap<int, char>  flippedPlaintext =  flip_map(plaintextFreq[0]);

for(int i=0;i<5;i++){
    flippedPlaintextFreqMap[i] = flip_map(plaintextFreq[i]);
}

//replace the most frequent chars in ciphertext with the most frequent in plaintext
//reverse iterator through flipped frequency, print after each switch
//for()
//ans.replace(,)


//test with no random chars
/*
map<int,char>::reverse_iterator rit = flippedcipherFreqMap.rbegin();
map<int,char>::reverse_iterator rit_two = flippedPlaintextFreqMap[0].rbegin();
char cipherChar;
char repChar;
for(rit,rit_two; rit != flippedcipherFreqMap.rend() || rit_two != flippedPlaintextFreqMap[0].rbegin();rit++,rit_two++){
cipherChar = rit ->second;
repChar = rit_two ->second;
findAndReplaceAll(ans,string(1,cipherChar),string(1,repChar));
cout << ans << endl;
}
*/


//instead of replacing all the chars, create an 2 char arrays one for the orig string
// the other for the new, iterate through and put the new chars in the new char array replace the orig values 
//in the old with a new value


//previous example didnt work perhaps a using digraphs will?

return 0;
}