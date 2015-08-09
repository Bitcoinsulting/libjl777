//
//  coins.h
//  gateway
//
//  Created by jl777 on 7/19/14.
//  Copyright (c) 2014 jl777. All rights reserved.
//

#ifndef gateway_coins_h
#define gateway_coins_h

#define NXT_COINID 0
#define BTC_COINID 1
#define LTC_COINID 2
#define CGB_COINID 3
#define DOGE_COINID 4
#define DRK_COINID 5
#define ANC_COINID 6
#define BC_COINID 7
#define BTCD_COINID 8
#define PPC_COINID 9
#define NMC_COINID 10
#define XC_COINID 11
#define VRC_COINID 12
#define ZET_COINID 13
#define QRK_COINID 14
#define RDD_COINID 15
#define XPM_COINID 16
#define FTC_COINID 17
#define CLOAK_COINID 18
#define VIA_COINID 19
#define MEC_COINID 20
#define URO_COINID 21
#define YBC_COINID 22
#define IFC_COINID 23
#define VTC_COINID 24
#define POT_COINID 25
#define KEY_COINID 26
#define FRAC_COINID 27
#define CNL_COINID 28
#define VOOT_COINID 29
#define GML_COINID 30
#define SYNC_COINID 31
#define CRYPT_COINID 32
#define RZR_COINID 33
#define ICB_COINID 34
#define CYC_COINID 35
#define EAC_COINID 36
#define MAX_COINID 37
#define START_COINID 38

#define BTC_MARKER "17outUgtsnLkguDuXm14tcQ7dMbdD8KZGK"
#define LTC_MARKER "Le9hFCEGKDKp7qYpzfWyEFAq58kSQsjAqX"
#define CGB_MARKER "PTqkPVfNkenMF92ZP8wfMQgQJc9DWZmwpB"
#define DOGE_MARKER "D72Xdw5cVyuX9JLivLxG3V9awpvj7WvsMi"
#define DRK_MARKER "XiiSWYGYozVKg3jyDLfJSF2xbieX15bNU8"
#define ANC_MARKER "D72Xdw5cVyuX9JLivLxG3V9awpvj7WvsMi"
#define BC_MARKER "BPyox1j426KkLy7x2uF3fygkSaM8LKVLY1"
#define BTCD_MARKER "RMMGbxZdav3cRJmWScNVX6BJivn6BNbBE8"
#define PPC_MARKER "PWLZF7Rw5zBGAQz2b84a29AYuk2FDDRd5V"
#define NMC_MARKER "NEkzWvNfccfHH7T1sU2E6FhFdTqBDfn59v"
#define XC_MARKER "XLwwCT4iGevPXqWHXBAe1BNMVLDzNRygFN"
#define VRC_MARKER "VYtKsjtepCpy8TonPNXersfikh2uzGmXeh"
#define ZET_MARKER "ZSyLYZ7X2Mmod4365S7cWcc3gdudjkGeSx"
#define QRK_MARKER "QXHfTKKsWYnSqZaVqYSYrcSyYyvAbeAcoF" // bter
#define RDD_MARKER "RpCQXn6LB4tCekx62DWoSPHbeuRsZdt59e"
#define XPM_MARKER "AJSE7mDNgkkSYnu2XaRoarKojCk687WC9R"
#define FTC_MARKER "6eheBngsQN5iitCiXpMDpSGawmw9TkGck5"
#define CLOAK_MARKER "C3AkZBH3wcTkJ1H7KpZZeMLkkvk73eKYcD"
#define VIA_MARKER "VjRSxRg9gBr4bAWNUgA5871eWa8fJqjFU4"
#define MEC_MARKER "MRpHsm9vV3Mt59e6Ssv4XBQUbXAsJ7GFpV" // bter
#define URO_MARKER "UPrW8bs9G9WohzQgoNCSAyVHJ6YmjytSkW"
#define YBC_MARKER "Ydh2WyYuJa3fkMTLqqfkSkTP5dyk1N7yFV"
#define IFC_MARKER "iB4zLQZKcuwJS7ra9eewbY8ntTKCC2U4Up" // bter
#define VTC_MARKER "VmW1mmJNA3ThX2Ef7yL9jYEVaWuTqaNWne"
#define POT_MARKER "PJjYpxFLCZrU6roseEjeG7q4ket2timHcp"
#define KEY_MARKER "KCqRbcUrCY3PrGZMVgqru2S4Brwtu1Ahha"
#define FRAC_MARKER "Fffoss3zCKP1DteiFaEUZmAYtmw6yvD3ui"
#define CNL_MARKER "119c8uD1rqE6MFBaBetMG8dMFkXA8iWiV"
#define VOOT_MARKER "VPNPpebJfxPcoYzBAxme54FVND9h1rHkYP"
#define GML_MARKER "GapogT2oKxjRRcEbuDGMomM5gyYF3TSw2e"
#define SYNC_MARKER "SRPYSpw2YoKC9Vkdt7sqPjgzfg3LppcBZA"
#define CRYPT_MARKER "ExpiWbZJMSqjaKYXWz2ywVcKQxUsk91fyG"
#define RZR_MARKER "RUZgYrCcrERhYDqShgW1cYX2cE3Maw2bUi"
#define ICB_MARKER "iqhciwDtWyiQhR5SMxYauiXf4sAmFkGXuT"
#define CYC_MARKER "CfNs2kTF6vZ8zsxKc54SYQPksFH87nM9hn"
#define EAC_MARKER "eYyTgezT256CstvUiZ3TobkaY4obhrefsR"
#define MAX_MARKER "mXRm6wDYZFZsPzFwGKSaNuXPczSEfLi67Y"
#define START_MARKER "sXWgrDSE6ugt5uAfJnLWGiN7yYrk97DSNH"

int32_t Numcoins;
struct coin_info **Daemons;

struct coin_info *get_coin_info(char *coinstr)
{
    int32_t i;
    for (i=0; i<Numcoins; i++)
        if ( strcmp(coinstr,Daemons[i]->name) == 0 )
            return(Daemons[i]);
    return(0);
}

char *get_marker(char *coinstr)
{
    struct coin_info *cp;
    if ( strcmp(coinstr,"NXT") == 0 )
        return("8712042175100667547"); // NXTprivacy
    else if ( strcmp(coinstr,"BTC") == 0 )
        return("177MRHRjAxCZc7Sr5NViqHRivDu1sNwkHZ");
    else if ( strcmp(coinstr,"BTCD") == 0 )
        return("RMMGbxZdav3cRJmWScNVX6BJivn6BNbBE8");
    else if ( strcmp(coinstr,"LTC") == 0 )
        return("LUERp4v5abpTk9jkuQh3KFxc4mFSGTMCiz");
    else if ( strcmp(coinstr,"DRK") == 0 )
        return("XmxSWLPA92QyAXxw2FfYFFex6QgBhadv2Q");
    else if ( (cp= get_coin_info(coinstr)) != 0 )
        return(cp->marker);
    else return(0);
}

char *coinid_str(int32_t coinid)
{
    switch ( coinid )
    {
        case NXT_COINID: return("NXT");
        case BTC_COINID: return("BTC");
        case LTC_COINID: return("LTC");
        case CGB_COINID: return("CGB");
        case DOGE_COINID: return("DOGE");
        case DRK_COINID: return("DRK");
        case ANC_COINID: return("ANC");
        case BC_COINID: return("BC");
        case BTCD_COINID: return("BTCD");
        case PPC_COINID: return("PPC");
        case NMC_COINID: return("NMC");
        case XC_COINID: return("XC");
        case VRC_COINID: return("VRC");
        case ZET_COINID: return("ZET");
        case QRK_COINID: return("QRK");
        case RDD_COINID: return("RDD");
        case XPM_COINID: return("XPM");
        case FTC_COINID: return("FTC");
        case CLOAK_COINID: return("CLOAK");
        case VIA_COINID: return("VIA");
        case MEC_COINID: return("MEC");
        case URO_COINID: return("URO");
        case YBC_COINID: return("YBC");
        case IFC_COINID: return("IFC");
        case VTC_COINID: return("VTC");
        case POT_COINID: return("POT");
        case KEY_COINID: return("KEY");
        case FRAC_COINID: return("FRAC");
        case CNL_COINID: return("CNL");
        case VOOT_COINID: return("VOOT");
        case GML_COINID: return("GML");
        case SYNC_COINID: return("SYNC");
        case CRYPT_COINID: return("CRYPT");
        case RZR_COINID: return("RZR");
        case ICB_COINID: return("ICB");
        case CYC_COINID: return("CYC");
        case EAC_COINID: return("EAC");
        case MAX_COINID: return("MAX");
        case START_COINID: return("START");
    }
    return(ILLEGAL_COIN);
}

int32_t conv_coinstr(char *_name)
{
    int32_t i,coinid;
    char name[256];
    strcpy(name,_name);
    for (i=0; name[i]!=0; i++)
        name[i] = toupper(name[i]);
    for (coinid=0; coinid<64; coinid++)
        if ( strcmp(coinid_str(coinid),name) == 0 )
            return(coinid);
    return(-1);
}

char *get_backupmarker(char *coinstr)
{
    int32_t coinid;
    if ( (coinid= conv_coinstr(coinstr)) < 0 )
        return("<no marker>");
    printf("backupmarker.(%s) coinid.%d\n",coinstr,coinid);
    switch ( coinid )
    {
        case NXT_COINID: return("NXT doesnt need a marker");
        case BTC_COINID: return(BTC_MARKER);
        case LTC_COINID: return(LTC_MARKER);
        case CGB_COINID: return(CGB_MARKER);
        case DOGE_COINID: return(DOGE_MARKER);
        case DRK_COINID: return(DRK_MARKER);
        case ANC_COINID: return(ANC_MARKER);
        case BC_COINID: return(BC_MARKER);
        case BTCD_COINID: return(BTCD_MARKER);
        case PPC_COINID: return(PPC_MARKER);
        case NMC_COINID: return(NMC_MARKER);
        case XC_COINID: return(XC_MARKER);
        case VRC_COINID: return(VRC_MARKER);
        case ZET_COINID: return(ZET_MARKER);
        case QRK_COINID: return(QRK_MARKER);
        case RDD_COINID: return(RDD_MARKER);
        case XPM_COINID: return(XPM_MARKER);
        case FTC_COINID: return(FTC_MARKER);
        case CLOAK_COINID: return(CLOAK_MARKER);
        case VIA_COINID: return(VIA_MARKER);
        case MEC_COINID: return(MEC_MARKER);
        case URO_COINID: return(URO_MARKER);
        case YBC_COINID: return(YBC_MARKER);
        case IFC_COINID: return(IFC_MARKER);
        case VTC_COINID: return(VTC_MARKER);
        case POT_COINID: return(POT_MARKER);
        case KEY_COINID: return(KEY_MARKER);
        case FRAC_COINID: return(FRAC_MARKER);
        case CNL_COINID: return(CNL_MARKER);
        case VOOT_COINID: return(VOOT_MARKER);
        case GML_COINID: return(GML_MARKER);
        case SYNC_COINID: return(SYNC_MARKER);
        case CRYPT_COINID: return(CRYPT_MARKER);
        case RZR_COINID: return(RZR_MARKER);
        case ICB_COINID: return(ICB_MARKER);
        case CYC_COINID: return(CYC_MARKER);
        case EAC_COINID: return(EAC_MARKER);
        case MAX_COINID: return(MAX_MARKER);
        case START_COINID: return(START_MARKER);
    }
    return(0);
}

char *get_assetid_str(char *coinstr)
{
    struct coin_info *cp;
    if ( (cp= get_coin_info(coinstr)) != 0 && cp->assetid[0] != 0 )
        return(cp->assetid);
    return(0);
}

uint64_t get_assetidbits(char *coinstr)
{
    struct coin_info *cp;
    if ( (cp= get_coin_info(coinstr)) != 0 && cp->assetid[0] != 0 )
        return(calc_nxt64bits(cp->assetid));
    return(0);
}

struct coin_info *conv_assetid(char *assetid)
{
    int32_t i;
    for (i=0; i<Numcoins; i++)
        if ( strcmp(Daemons[i]->assetid,assetid) == 0 )
            return(Daemons[i]);
    return(0);
}

uint64_t get_orderbook_assetid(char *coinstr)
{
    struct coin_info *cp;
    int32_t i;
    uint64_t virtassetid;
    if ( strcmp(coinstr,"NXT") == 0 )
        return(ORDERBOOK_NXTID);
    if ( (cp= get_coin_info(coinstr)) != 0 )
        return(calc_nxt64bits(cp->assetid));
    virtassetid = 0;
    for (i=0; coinstr[i]!=0; i++)
    {
        virtassetid <<= 8;
        virtassetid |= (coinstr[i] & 0xff);
    }
    return(virtassetid);
}

int32_t is_gateway_addr(char *addr)
{
    int32_t i;
    if ( strcmp(addr,NXTISSUERACCT) == 0 )
        return(1);
    for (i=0; i<256; i++)
    {
        if ( Server_NXTaddrs[i][0] == 0 )
            break;
        if ( strcmp(addr,Server_NXTaddrs[i]) == 0 )
            return(1);
    }
    return(0);
}

char *parse_conf_line(char *line,char *field)
{
    line += strlen(field);
    for (; *line!='='&&*line!=0; line++)
        break;
    if ( *line == 0 )
        return(0);
    if ( *line == '=' )
        line++;
    stripstr(line,strlen(line));
    printf("[%s]\n",line);
    return(clonestr(line));
}

char *extract_userpass(struct coin_info *cp,char *serverport,char *userpass,char *fname)
{
    FILE *fp;
    char line[1024],*rpcuser,*rpcpassword,*str;
    userpass[0] = 0;
    if ( (fp= fopen(fname,"r")) != 0 )
    {
        printf("extract_userpass from (%s)\n",fname);
        rpcuser = rpcpassword = 0;
        while ( fgets(line,sizeof(line),fp) > 0 )
        {
            if ( line[0] == '#' )
                continue;
            //printf("line.(%s) %p %p\n",line,strstr(line,"rpcuser"),strstr(line,"rpcpassword"));
            if ( (str= strstr(line,"rpcuser")) != 0 )
                rpcuser = parse_conf_line(str,"rpcuser");
            else if ( (str= strstr(line,"rpcpassword")) != 0 )
                rpcpassword = parse_conf_line(str,"rpcpassword");
        }
        if ( rpcuser != 0 && rpcpassword != 0 )
            sprintf(userpass,"%s:%s",rpcuser,rpcpassword);
        else userpass[0] = 0;
        printf("-> (%s):(%s) userpass.(%s)\n",rpcuser,rpcpassword,userpass);
        if ( rpcuser != 0 )
            free(rpcuser);
        if ( rpcpassword != 0 )
            free(rpcpassword);
    }
    else
    {
        printf("extract_userpass cant open.(%s)\n",fname);
        return(0);
    }
    return(serverport);
}

struct coin_info *create_coin_info(int32_t nohexout,int32_t useaddmultisig,int32_t estblocktime,char *name,int32_t minconfirms,uint64_t txfee,int32_t pollseconds,char *asset,char *conf_fname,char *serverport,int32_t blockheight,char *marker,uint64_t NXTfee_equiv,int32_t forkblock)
{
    struct coin_info *cp = calloc(1,sizeof(*cp));
    char userpass[512];
    if ( forkblock == 0 )
        forkblock = blockheight;
    safecopy(cp->name,name,sizeof(cp->name));
    cp->estblocktime = estblocktime;
    cp->NXTfee_equiv = NXTfee_equiv;
    safecopy(cp->assetid,asset,sizeof(cp->assetid));
    cp->marker = clonestr(marker);
    cp->blockheight = blockheight;
    cp->min_confirms = minconfirms;
    cp->markeramount = cp->txfee = txfee;
    serverport = extract_userpass(cp,serverport,userpass,conf_fname);
    if ( serverport != 0 )
    {
        cp->serverport = clonestr(serverport);
        cp->userpass = clonestr(userpass);
        printf("%s userpass.(%s) -> (%s)\n",cp->name,cp->userpass,cp->serverport);
        cp->nohexout = nohexout;
        cp->use_addmultisig = useaddmultisig;
        cp->minconfirms = minconfirms;
        cp->estblocktime = estblocktime;
        cp->txfee = txfee;
        cp->forkheight = forkblock;
        printf("%s minconfirms.%d txfee %.8f | marker %.8f NXTfee %.8f | firstblock.%ld fork.%d %d seconds\n",cp->name,cp->minconfirms,dstr(cp->txfee),dstr(cp->markeramount),dstr(cp->NXTfee_equiv),(long)cp->blockheight,cp->forkheight,cp->estblocktime);
    }
    else
    {
        free(cp);
        cp = 0;
    }
    return(cp);
}

extern int32_t process_podQ(void *ptr);
struct coin_info *init_coin_info(cJSON *json,char *coinstr)
{
    char *get_telepod_privkey(char **podaddrp,char *pubkey,struct coin_info *cp);
    int32_t useaddmultisig,nohexout,estblocktime,minconfirms,pollseconds,blockheight,forkblock,*cipherids;
    char asset[256],_marker[512],conf_filename[512],tradebotfname[512],serverip_port[512],buf[512];
    char *marker,*privkey,*coinaddr,**privkeys;
    cJSON *ciphersobj;
    uint64_t txfee,NXTfee_equiv,min_telepod_satoshis,dust;
    struct coin_info *cp = 0;
    if ( json != 0 )
    {
        nohexout = get_API_int(cJSON_GetObjectItem(json,"nohexout"),0);
        useaddmultisig = get_API_int(cJSON_GetObjectItem(json,"useaddmultisig"),0);
        blockheight = get_API_int(cJSON_GetObjectItem(json,"blockheight"),0);
        forkblock = get_API_int(cJSON_GetObjectItem(json,"forkblock"),0);
        pollseconds = get_API_int(cJSON_GetObjectItem(json,"pollseconds"),60);
        minconfirms = get_API_int(cJSON_GetObjectItem(json,"minconfirms"),10);
        estblocktime = get_API_int(cJSON_GetObjectItem(json,"estblocktime"),300);
        min_telepod_satoshis = get_API_nxt64bits(cJSON_GetObjectItem(json,"min_telepod_satoshis"));
        dust = get_API_nxt64bits(cJSON_GetObjectItem(json,"dust"));
        if ( dust == 0 )
            dust = 60000;

        txfee = get_API_nxt64bits(cJSON_GetObjectItem(json,"txfee_satoshis"));
        if ( txfee == 0 )
            txfee = (uint64_t)(SATOSHIDEN * get_API_float(cJSON_GetObjectItem(json,"txfee")));
        NXTfee_equiv = get_API_nxt64bits(cJSON_GetObjectItem(json,"NXTfee_equiv_satoshis"));
        if ( NXTfee_equiv == 0 )
            NXTfee_equiv = (uint64_t)(SATOSHIDEN * get_API_float(cJSON_GetObjectItem(json,"NXTfee_equiv")));
        if ( (marker = get_marker(coinstr)) == 0 )
        {
            extract_cJSON_str(_marker,sizeof(_marker),json,"marker");
            if ( _marker[0] == 0 )
                strcpy(_marker,get_backupmarker(coinstr));
            marker = clonestr(_marker);
        }
        if ( marker != 0 && txfee != 0. && NXTfee_equiv != 0. &&
            extract_cJSON_str(conf_filename,sizeof(conf_filename),json,"conf") > 0 &&
            extract_cJSON_str(asset,sizeof(asset),json,"asset") > 0 &&
            extract_cJSON_str(serverip_port,sizeof(serverip_port),json,"rpc") > 0 )
        {
            cp = create_coin_info(nohexout,useaddmultisig,estblocktime,coinstr,minconfirms,txfee,pollseconds,asset,conf_filename,serverip_port,blockheight,marker,NXTfee_equiv,forkblock);
            if ( cp != 0 )
            {
                if ( extract_cJSON_str(tradebotfname,sizeof(tradebotfname),json,"tradebotfname") > 0 )
                    cp->tradebotfname = clonestr(tradebotfname);
                if ( extract_cJSON_str(cp->privacyserver,sizeof(cp->privacyserver),json,"privacyServer") > 0 )
                    printf("set default privacyServer to (%s)\n",cp->privacyserver);
                if ( extract_cJSON_str(cp->pubaddr,sizeof(cp->pubaddr),json,"pubaddr") > 0 )
                {
                    coinaddr = cp->pubaddr;
                    if ( (privkey= get_telepod_privkey(&coinaddr,cp->coinpubkey,cp)) != 0 )
                    {
                        safecopy(cp->NXTACCTSECRET,privkey,sizeof(cp->NXTACCTSECRET));
                        cp->pubnxt64bits = issue_getAccountId(0,privkey);

                        printf("SET ACCTSECRET for %s.%s to %s NXT.%llu\n",cp->name,cp->pubaddr,cp->NXTACCTSECRET,(long long)cp->pubnxt64bits);
                        free(privkey);
                    }
                }
                else if ( strcmp(cp->name,"BTCD") == 0 )
                {
                    printf("You must have a \"pubaddr\" for %s\n",cp->name);
                    exit(1);
                }
                cp->dust = dust;
                cp->min_telepod_satoshis = min_telepod_satoshis;
                
                cp->maxevolveiters = get_API_int(cJSON_GetObjectItem(json,"maxevolveiters"),100);
                cp->M = get_API_int(cJSON_GetObjectItem(json,"telepod_M"),1);
                cp->N = get_API_int(cJSON_GetObjectItem(json,"telepod_N"),1);
                cp->clonesmear = get_API_int(cJSON_GetObjectItem(json,"clonesmear"),(TELEPORT_DEFAULT_SMEARTIME/cp->estblocktime) + 1);
                if ( extract_cJSON_str(cp->backupdir,sizeof(cp->backupdir),json,"backupdir") <= 0 )
                    strcpy(cp->backupdir,"backups");
                ciphersobj = cJSON_GetObjectItem(json,"ciphers");
                privkeys = 0;
                cipherids = 0;
                if ( ciphersobj == 0 || (privkeys= validate_ciphers(&cipherids,cp,ciphersobj)) == 0 )
                {
                    free_cipherptrs(ciphersobj,privkeys,cipherids);
                    sprintf(buf,"[{\"aes\":\"%s\"}]",cp->pubaddr);
                    cp->ciphersobj = cJSON_Parse(buf);
                } else cp->ciphersobj = ciphersobj;
                free_cipherptrs(0,privkeys,cipherids);
                privkeys = 0;
                cipherids = 0;
                if ( strcmp(cp->name,"BTCD") == 0 && (privkeys= validate_ciphers(&cipherids,cp,cp->ciphersobj)) == 0 )
                {
                    printf("FATAL error: cant validate ciphers sequence for %s\n",cp->name);
                    exit(-1);
                }
                free_cipherptrs(0,privkeys,cipherids);
            }
            else printf("create_coin_info failed for (%s)\n",coinstr);
        }
    }
    return(cp);
}

void init_MGWconf(char *NXTADDR,char *NXTACCTSECRET,struct NXThandler_info *mp)
{
    int32_t init_tradebots(cJSON *languagesobj);
    static int32_t exchangeflag;
    uint64_t nxt64bits;
    //FILE *fp;
    struct coin_info *cp;
    cJSON *array,*item,*languagesobj = 0;
    char coinstr[512],NXTaddr[64],*buf=0,*jsonstr,*origblock,*str;
    int32_t i,n,ismainnet,timezone=0;
    int64_t len=0,allocsize=0;
    exchangeflag = !strcmp(NXTACCTSECRET,"exchanges");
    printf("init_MGWconf exchangeflag.%d\n",exchangeflag);
    //init_filtered_bufs(); crashed ubunty
    ensure_directory("backups");
    ensure_directory("backups/telepods");
    ensure_directory("archive");
    ensure_directory("archive/telepods");
    if ( 0 )
    {
        char *argv[1] = { "test" };
        double picoc(int argc,char **argv,char *codestr);
        picoc(1,argv,clonestr("double main(){ double val = 1.234567890123456; printf(\"hello world val %.20f\\n\",val); return(val);}"));
        getchar();
    }
    printf("load MGW.conf\n");
    jsonstr = load_file("jl777.conf",&buf,&len,&allocsize);
    if ( jsonstr != 0 )
    {
        printf("loaded.(%s)\n",jsonstr);
        MGWconf = cJSON_Parse(jsonstr);
        if ( MGWconf != 0 )
        {
            printf("parsed\n");
            timezone = get_API_int(cJSON_GetObjectItem(MGWconf,"timezone"),0);
            init_jdatetime(NXT_GENESISTIME,timezone * 3600);
            languagesobj = cJSON_GetObjectItem(MGWconf,"tradebot_languages");
            MIN_NQTFEE = get_API_int(cJSON_GetObjectItem(MGWconf,"MIN_NQTFEE"),(int32_t)MIN_NQTFEE);
            MIN_NXTCONFIRMS = get_API_int(cJSON_GetObjectItem(MGWconf,"MIN_NXTCONFIRMS"),MIN_NXTCONFIRMS);
            GATEWAY_SIG = get_API_int(cJSON_GetObjectItem(MGWconf,"GATEWAY_SIG"),0);
            extract_cJSON_str(ORIGBLOCK,sizeof(ORIGBLOCK),MGWconf,"ORIGBLOCK");
            extract_cJSON_str(NXTAPIURL,sizeof(NXTAPIURL),MGWconf,"NXTAPIURL");
            extract_cJSON_str(NXTISSUERACCT,sizeof(NXTISSUERACCT),MGWconf,"NXTISSUERACCT");
            ismainnet = get_API_int(cJSON_GetObjectItem(MGWconf,"MAINNET"),0);
            if ( ismainnet != 0 )
            {
                NXT_FORKHEIGHT = 173271;
                if ( NXTAPIURL[0] == 0 )
                    strcpy(NXTAPIURL,"http://127.0.0.1:7876/nxt");
                if ( NXTISSUERACCT[0] == 0 )
                    strcpy(NXTISSUERACCT,"7117166754336896747");
                origblock = "14398161661982498695";    //"91889681853055765";//"16787696303645624065";
            }
            else
            {
                if ( NXTAPIURL[0] == 0 )
                    strcpy(NXTAPIURL,"http://127.0.0.1:6876/nxt");
                if ( NXTISSUERACCT[0] == 0 )
                    strcpy(NXTISSUERACCT,"18232225178877143084");
                origblock = "16787696303645624065";   //"91889681853055765";//"16787696303645624065";
            }
            if ( ORIGBLOCK[0] == 0 )
                strcpy(ORIGBLOCK,origblock);
            strcpy(NXTSERVER,NXTAPIURL);
            strcat(NXTSERVER,"?requestType");
            extract_cJSON_str(Server_names[0],sizeof(Server_names[0]),MGWconf,"MGW0_ipaddr");
            extract_cJSON_str(Server_names[1],sizeof(Server_names[1]),MGWconf,"MGW1_ipaddr");
            extract_cJSON_str(Server_names[2],sizeof(Server_names[2]),MGWconf,"MGW2_ipaddr");
            extract_cJSON_str(NXTACCTSECRET,sizeof(NXTACCTSECRET),MGWconf,"secret");
            if ( NXTACCTSECRET[0] == 0 )
                gen_randomacct(0,33,NXTADDR,NXTACCTSECRET,"randvals");
            nxt64bits = issue_getAccountId(0,NXTACCTSECRET);
            expand_nxt64bits(NXTADDR,nxt64bits);
            for (i=0; i<3; i++)
                printf("%s | ",Server_names[i]);
            printf("issuer.%s %08x NXTAPIURL.%s, minNXTconfirms.%d port.%s orig.%s\n",NXTISSUERACCT,GATEWAY_SIG,NXTAPIURL,MIN_NXTCONFIRMS,SERVER_PORTSTR,ORIGBLOCK);
            array = cJSON_GetObjectItem(MGWconf,"coins");
            if ( array != 0 && is_cJSON_Array(array) != 0 )
            {
                char *pubNXT,*BTCDaddr,*BTCaddr,*pNXTaddr,pubkey[sizeof(mp->session_pubkey)*2+1];
                pubNXT = BTCDaddr = BTCaddr = pNXTaddr = "";
                n = cJSON_GetArraySize(array);
                for (i=0; i<n; i++)
                {
                    if ( array == 0 || n == 0 )
                        break;
                    item = cJSON_GetArrayItem(array,i);
                    copy_cJSON(coinstr,cJSON_GetObjectItem(item,"name"));
                    if ( coinstr[0] != 0 && (cp= init_coin_info(item,coinstr)) != 0 )
                    {
                        if ( strcmp(coinstr,"BTCD") == 0 )
                        {
                            BTCDaddr = cp->pubaddr;
                            if ( cp->pubnxt64bits != 0 )
                                expand_nxt64bits(NXTADDR,cp->pubnxt64bits);
                        }
                        else if ( strcmp(coinstr,"BTC") == 0 )
                            BTCaddr = cp->pubaddr;
                        else if ( strcmp(coinstr,"NXT") == 0 )
                            pubNXT = cp->pubaddr;
                        else if ( strcmp(coinstr,"BBR") == 0 )
                            pNXTaddr = cp->pubaddr;
                        Daemons = realloc(Daemons,sizeof(*Daemons) * (Numcoins+1));
                        MGWcoins = realloc(MGWcoins,sizeof(*MGWcoins) * (Numcoins+1));
                        MGWcoins[Numcoins] = item;
                        Daemons[Numcoins] = cp;
                        printf("i.%d coinid.%d %s asset.%s\n",i,Numcoins,coinstr,Daemons[Numcoins]->assetid);
                        Numcoins++;
                    }
                }
                char *publishaddrs(char *NXTACCTSECRET,char *pubNXT,char *pubkey,char *BTCDaddr,char *BTCaddr,char *pNXTaddr);
                init_hexbytes(pubkey,mp->session_pubkey,sizeof(mp->session_pubkey));
                if ( pubNXT[0] == 0 )
                    pubNXT = NXTADDR;
                str = publishaddrs(NXTACCTSECRET,pubNXT,pubkey,BTCDaddr,BTCaddr,pNXTaddr);
                if ( str != 0 )
                    printf("publish.(%s)\n",str), free(str);
            }
            array = cJSON_GetObjectItem(MGWconf,"special_NXTaddrs");
            if ( array != 0 && is_cJSON_Array(array) != 0 ) // first three must be the gateway's addresses
            {
                n = cJSON_GetArraySize(array);
                for (i=0; i<n; i++)
                {
                    if ( array == 0 || n == 0 )
                        break;
                    item = cJSON_GetArrayItem(array,i);
                    copy_cJSON(NXTaddr,item);
                    if ( NXTaddr[0] == 0 )
                    {
                        printf("Illegal special NXTaddr.%d\n",i);
                        exit(1);
                    }
                    printf("%s ",NXTaddr);
                    strcpy(Server_NXTaddrs[i],NXTaddr);
                    MGW_blacklist[i] = MGW_whitelist[i] = clonestr(NXTaddr);
                }
                printf("special_addrs.%d\n",n);
                MGW_blacklist[n] = MGW_whitelist[n] = NXTISSUERACCT, n++;
                MGW_whitelist[n] = "";
                MGW_blacklist[n++] = "4551058913252105307";    // from accidental transfer
                MGW_blacklist[n++] = "";
            }
            void start_polling_exchanges(int32_t exchangeflag);
            int32_t init_exchanges(cJSON *confobj,int32_t exchangeflag);
            if ( init_exchanges(MGWconf,exchangeflag) > 0 )
                start_polling_exchanges(exchangeflag);
        }
    }
    init_tradebots(languagesobj);
    if ( ORIGBLOCK[0] == 0 )
    {
        printf("need a non-zero origblock.(%s)\n",ORIGBLOCK);
        exit(1);
    }
}
#endif
