//
//  storage.h
//  libjl777
//
//  Created by jl777 on 10/19/14.
//  Copyright (c) 2014 jl777. MIT license
//

#ifndef libjl777_storage_h
#define libjl777_storage_h

#include "db.h"

#define MAX_KADEMLIA_STORAGE (1024L * 1024L * 1024L)

struct SuperNET_db
{
    char name[64],**privkeys;
    queue_t queue;
    long maxitems,total_stored;
    DB *dbp;
    int32_t *cipherids,selector;
    uint32_t busy,type,flags,active,minsize,maxsize,duplicateflag;
};

struct dbreq { struct SuperNET_db *sdb; DB_TXN *txn; DBT key,*data; int32_t flags,retval; uint16_t tbd,funcid,doneflag,pad; };

long Total_stored,Num_pricedbs;
DB_ENV *Storage;
struct SuperNET_db SuperNET_dbs[NUM_SUPERNET_DBS],*Price_dbs;
int32_t dbsync(struct SuperNET_db *dbp,int32_t flags);
int32_t dbput(struct SuperNET_db *dbp,DB_TXN *txn,DBT *key,DBT *data,int32_t flags);

struct SuperNET_db *find_pricedb(char *dbname)
{
    int32_t i;
    struct SuperNET_db *sdb;
    if ( Num_pricedbs > 0 )
    {
        for (i=0; i<Num_pricedbs; i++)
        {
            sdb = &Price_dbs[i];
            if ( strcmp(sdb->name,dbname) == 0 )
                return(sdb);
        }
    }
    Price_dbs = realloc(Price_dbs,(Num_pricedbs+1) * sizeof(*Price_dbs));
    sdb = &Price_dbs[Num_pricedbs++];
    memset(sdb,0,sizeof(*sdb));
    return(sdb);
}

int32_t valid_SuperNET_db(char *debugstr,int32_t selector)
{
    if ( IS_LIBTEST == 0 || selector < 0 || selector >= NUM_SUPERNET_DBS )
    {
        fprintf(stderr,"%s: invalid SuperNET_db selector.%d or DB disabled vi LIBTEST.%d\n",debugstr,selector,IS_LIBTEST);
        return(0);
    }
    return(1);
}

DB *get_selected_database(int32_t selector)
{
    if ( valid_SuperNET_db("get_selected_database",selector) != 0 )
        return(SuperNET_dbs[selector].dbp);
    return(0);
}

long max_in_db(int32_t selector)
{
    if ( valid_SuperNET_db("max_in_db",selector) != 0 )
        return(SuperNET_dbs[selector].maxitems);
    else return(0);
}

void set_max_in_db(int32_t selector,long num)
{
    if ( valid_SuperNET_db("set_max_in_db",selector) != 0 && num > SuperNET_dbs[selector].maxitems )
        SuperNET_dbs[selector].maxitems = num;
}

void *decondition_storage(uint32_t *lenp,struct SuperNET_db *sdb,void *data,uint32_t size)
{
    void *ptr;
    if ( data == 0 || size == 0 )
        return(0);
    if ( sdb->privkeys != 0 && sdb->cipherids != 0 )
    {
        *lenp = size;
        ptr = ciphers_codec(1,sdb->privkeys,sdb->cipherids,data,(int32_t *)lenp);
        if ( *lenp >= sdb->minsize && *lenp <= sdb->maxsize )
            return(ptr);
        if ( ptr != 0 )
            free(ptr);
        //printf("unencrypted entry size.%d\n",*lenp);
    }
    *lenp = size;
    ptr = malloc(size);
    memcpy(ptr,data,size);
    return(ptr);
}

void *condition_storage(uint32_t *lenp,struct SuperNET_db *sdb,void *data,uint32_t size)
{
    *lenp = size;
    //fprintf(stderr,"condition_storage\n");
    if ( data == 0 || size <= 0 )
        return(0);
    if ( sdb->privkeys == 0 || sdb->cipherids == 0 )
        return(data);
    else return(ciphers_codec(0,sdb->privkeys,sdb->cipherids,data,(int32_t *)lenp));
}

void clear_pair(DBT *key,DBT *data)
{
    memset(key,0,sizeof(DBT));
    memset(data,0,sizeof(DBT));
}

int dbreplace_iQ(int32_t selector,char *keystr,struct InstantDEX_quote *refiQ)
{
    DB *dbp = get_selected_database(selector);
    struct InstantDEX_quote *iQ;
    int32_t n,replaced=0,ret = -1;
    DB_TXN *txn = NULL;
    DBC *cursorp = 0;
    DBT key,data;
    if ( dbp == 0 )
        return(0);
    //fprintf(stderr,"dbreplace_iQ.%d\n",selector);
    if ( 1 && (ret = Storage->txn_begin(Storage,NULL,&txn,0)) != 0 )
    {
        Storage->err(Storage,ret,"Transaction begin failed.");
        return(-1);
    }
    n = 0;
    clear_pair(&key,&data);
    key.data = keystr;
    key.size = (int32_t)(strlen(keystr) + 1);
    if ( (ret= dbp->cursor(dbp,txn,&cursorp,0)) != 0 )
    {
        Storage->err(Storage,ret,"Cursor open failed.");
        txn->abort(txn);
        return(-1);
    }
    if ( cursorp != 0 )
    {
        ret = cursorp->get(cursorp,&key,&data,DB_SET);
        while ( ret == 0 )
        {
            iQ = data.data;
            //int z;
            //for (z=0; z<32; z++)
            //    printf("%02x ",((uint8_t *)&iQ)[z]);
            printf("%p key.%d: %s, data.size %d: %llu %u %u | vs %llu %u %u\n",iQ,n,(char *)key.data,data.size,(long long)iQ->nxt64bits,iQ->timestamp,iQ->type,(long long)refiQ->nxt64bits,refiQ->timestamp,refiQ->type);
            if ( iQ->nxt64bits == refiQ->nxt64bits && iQ->type == refiQ->type && refiQ->timestamp > iQ->timestamp )
            {
                clear_pair(&key,&data);
                key.data = keystr;
                key.size = (int32_t)(strlen(keystr) + 1);
                data.data = refiQ;
                data.size = sizeof(*refiQ);
                // printf("cursor put\n");
                ret = cursorp->put(cursorp,&key,&data,DB_CURRENT);
                // printf("REPLACED.%d\n",ret);
                replaced = 1;
                break;
            }
            ret = cursorp->get(cursorp,&key,&data,DB_NEXT_DUP);
            n++;
        }
        //printf("close cursor\n");
        if ( (ret= cursorp->close(cursorp)) != 0 )
        {
            Storage->err(Storage,ret,"Cursor close failed.");
            txn->abort(txn);
        }
        else if ( 1 && (ret= txn->commit(txn,0)) != 0 )
            Storage->err(Storage,ret,"Transaction commit failed.");
        if ( replaced == 0 )
        {
            //printf("call dbput\n");
            data.data = refiQ;
            data.size = sizeof(*refiQ);
            ret = dbput(&SuperNET_dbs[selector],0,&key,&data,0);
        }
        //printf("queue sync\n");
        dbsync(&SuperNET_dbs[selector],0);
    }
    //fprintf(stderr,"done dbreplace_iQ.%d\n",selector);
    return(ret);
}

struct storage_header **copy_all_DBentries(int32_t *nump,int32_t selector)
{
    DB *dbp = get_selected_database(selector);
    struct storage_header *ptr,**ptrs = 0;
    int32_t ret,max,m,n = 0;
    DBT key,data;
    DBC *cursorp = 0;
    *nump = 0;
    if ( dbp == 0 )
        return(0);
    max = (int32_t)max_in_db(selector);
    max += 100;
    m = 0;
    //fprintf(stderr,"copy all dB.%d\n",selector);
    dbp->cursor(dbp,NULL,&cursorp,0);
    if ( cursorp != 0 )
    {
        clear_pair(&key,&data);
        ptrs = (struct storage_header **)calloc(sizeof(struct storage_header *),max+1);
        while ( (ret= cursorp->get(cursorp,&key,&data,DB_NEXT)) == 0 )
        {
            m++;
            ptr = decondition_storage(&data.size,&SuperNET_dbs[selector],data.data,data.size);
            ptrs[n++] = ptr;
            if ( n >= max )
            {
                max += 100;
                ptrs = (struct storage_header **)realloc(ptrs,sizeof(struct storage_header *)*(max+1));
            }
            clear_pair(&key,&data);
        }
        cursorp->close(cursorp);
    }
    //fprintf(stderr,"done copy all dB.%d\n",selector);
    if ( m > max_in_db(selector) )
        set_max_in_db(selector,m);
    if ( ptrs != 0 )
        ptrs[n] = 0;
    *nump = n;
    return(ptrs);
}

DB *open_database(int32_t selector,struct SuperNET_db *sdb,char *fname,uint32_t type,uint32_t flags,int32_t minsize,int32_t maxsize,int32_t duplicateflag)
{
    int ret;
    /*if ( valid_SuperNET_db("open_database",selector) == 0 )
    {
        fprintf(stderr,"open_database error illegal selector.%d for (%s)\n",selector,fname);
        return(0);
    }*/
    if ( (ret= db_create(&sdb->dbp,Storage,0)) != 0 )
    {
        fprintf(stderr,"open_database error.%d creating %s database\n",ret,fname);
        exit(-1);
        return(0);
    } else printf("open_database %s created\n",fname);
    if ( duplicateflag != 0 )
    {
        if ( (ret= sdb->dbp->set_flags(sdb->dbp,DB_DUP)) != 0 )
        {
            fprintf(stderr,"set_flags DB_DUPSORT error.%d %s\n",ret,fname);
            exit(-3);
            return(0);
        } else printf("set_flags DB_DUPSORT %s\n",fname);
        /*if ( (ret= sdb->dbp->set_dup_compare(sdb->dbp,(sortflag > 0) ? db_incrdouble : db_decrdouble)) != 0 )
         {
         fprintf(stderr,"set_dup_compare error.%d %s\n",ret,fname);
         exit(-4);
         return(0);
         } else printf("set_dup_compare %s\n",fname);*/
    }
    if ( (ret= sdb->dbp->open(sdb->dbp,NULL,fname,NULL,type,flags,0)) != 0 )
    {
        fprintf(stderr,"open_database error.%d opening %s database\n",ret,fname);
        exit(-2);
        return(0);
    } else printf("open_database %s opened\n",fname);
    safecopy(sdb->name,fname,sizeof(sdb->name));
    sdb->type = type;
    sdb->flags = flags;
    sdb->minsize = minsize;
    sdb->maxsize = maxsize;
    sdb->duplicateflag = duplicateflag;
    sdb->active = 1;
    sdb->selector = selector;
    return(sdb->dbp);
}

int32_t _process_dbiter(struct SuperNET_db *sdb)
{
    int32_t n;
    DBT data;
    struct dbreq *req;
    n = 0;
    while ( (req= queue_dequeue(&sdb->queue)) != 0 )
    {
        memset(&data,0,sizeof(data));
        if ( req->data != 0 )
            data = *req->data;
        //printf("DB.%d func.%c key.(%s)\n",selector,req->funcid,req->key.data);
        if ( req->funcid == 'G' )
            req->retval = sdb->dbp->get(sdb->dbp,req->txn,&req->key,&data,req->flags);
        else if ( req->funcid == 'P' )
            req->retval = sdb->dbp->put(sdb->dbp,req->txn,&req->key,&data,req->flags);
        else if ( req->funcid == 'S' )
            req->retval = sdb->dbp->sync(sdb->dbp,req->flags);
        else if ( req->funcid == 'D' )
            req->retval = sdb->dbp->del(sdb->dbp,req->txn,&req->key,req->flags);
        else printf("UNEXPECTED SuperNET_db funcid.(%c) %d\n",req->funcid,req->funcid);
        if ( req->data != 0 )
            *req->data = data;
        req->doneflag = 1;
        n++;
    }
    return(n);
}

int32_t poll_pricedbs()
{
    struct exchange_state *add_activefile(int32_t writeflag,char *exchange,char *base,char *rel);
    int32_t poll_exchange_iter(int32_t maxdepth,uint32_t exchangemask);
    int32_t maxdepth = 20;
    char dbname[1024];
    int32_t i,num,nonz = 0;
    struct SuperNET_db *sdb;
    struct exchange_pair *pair;
    struct exchange_state *ep;
    struct storage_header **pricedbs,*hp;
    if ( (pricedbs= copy_all_DBentries(&num,PRICE_DATA)) != 0 && num > 0 )
    {
        //printf("got numpricedbs.%d\n",num);
        for (i=0; i<num; i++)
        {
            if ( (hp= pricedbs[i]) != 0 )
            {
                if ( hp->size > (sizeof(*hp)+1) )
                {
                    pair = (struct exchange_pair *)hp;
                    sprintf(dbname,"%s.%s_%s",pair->exchange,pair->base,pair->rel);
                    sdb = find_pricedb(dbname);
                    if ( sdb->dbp == 0 )
                    {
                        if ( open_database(NUM_SUPERNET_DBS,sdb,dbname,DB_BTREE,DB_CREATE | DB_AUTO_COMMIT,sizeof(float)*4,sizeof(float)*NUM_BARPRICES*50,0) == 0 )
                            printf("error creating pricedb.(%s)\n",dbname);
                        ep = add_activefile(1,pair->exchange,pair->base,pair->rel);
                        ep->sdb = sdb;
                    }
                    nonz += _process_dbiter(sdb);
                }
                free(hp);
            }
        }
        free(pricedbs);
        if ( num > 0 )
            for (i=0; i<6; i++)
                poll_exchange_iter(maxdepth,(1<<i));
        else usleep(100000);
    }
    return(nonz);
}

void *_process_SuperNET_dbqueue(void *selectorp) // serialize dbreq functions
{
    int32_t n,numactive=1,selector = *(int32_t *)selectorp;
    struct SuperNET_db *sdb;
    while ( numactive > 0 )
    {
        n = 0;
        for (selector=0; selector<NUM_SUPERNET_DBS; selector++)
        {
            sdb = &SuperNET_dbs[selector];
            if ( sdb->active != 0 )
            {
                if ( sdb->busy == 0 && n == 0 )
                {
                    if ( selector == PRICE_DATA )
                        n += poll_pricedbs();
                }
                n += _process_dbiter(sdb);
            }
        }
        if ( n == 0 )
            usleep(5000);
    }
    for (selector=0; selector<NUM_SUPERNET_DBS; selector++)
    {
        sdb = &SuperNET_dbs[selector];
        sdb->dbp->close(sdb->dbp,0);
        sdb->active = -1;
        fprintf(stderr,"finished processing process_SuperNET_dbqueue.%d\n",selector);
    }
    return(0);
}

int32_t _block_on_dbreq(struct dbreq *req)
{
    struct SuperNET_db *sdb = req->sdb;//&SuperNET_dbs[req->selector];
    int32_t retval,busy;
    while ( req->doneflag == 0 )
        usleep(100); // if not done after the first context switch, likely to take a while
    retval = req->retval;
    free(req);
    sdb->busy--;
    if ( (busy= sdb->busy) != 0 ) // busy is not critical for data integrity, but helps with dbreq latency
    {
        fprintf(stderr,"_block_on_dbreq: unlikely case of busy.%d != 0, (%d) for (%s)\n",busy,sdb->busy,sdb->name);
        sdb->busy = 0;
    }
    return(retval);
}

struct dbreq *_queue_dbreq(int32_t funcid,struct SuperNET_db *sdb,DB_TXN *txn,DBT *key,DBT *data,int32_t flags)
{
    //struct SuperNET_db *sdb = &SuperNET_dbs[selector];
    struct dbreq *req = 0;
    if ( sdb->active > 0 )
    {
        req = calloc(1,sizeof(*req));
        req->funcid = funcid;
        req->sdb = sdb;
        //req->selector = selector;
        req->txn = txn;
        if ( key != 0 )
            req->key = *key;
        req->data = data;
        req->flags = flags;
        sdb->busy++;
        queue_enqueue(&sdb->queue,req);
        usleep(10); // allow context switch so request has a chance of completing
    }
    return(req);
}

int32_t dbcmd(char *debugstr,int32_t funcid,struct SuperNET_db *sdb,DB_TXN *txn,DBT *key,DBT *data,int32_t flags)
{
    struct dbreq *req;
    //if ( valid_SuperNET_db(debugstr,selector) != 0 )
    {
        if ( (req= _queue_dbreq(funcid,sdb,txn,key,data,flags)) != 0 )
            return(_block_on_dbreq(req));
    }
    return(-1);
}

int32_t dbget(struct SuperNET_db *sdb,DB_TXN *txn,DBT *key,DBT *data,int32_t flags)
{
    return(dbcmd("dbget",'G',sdb,txn,key,data,flags));
}

int32_t dbput(struct SuperNET_db *sdb,DB_TXN *txn,DBT *key,DBT *data,int32_t flags)
{
    return(dbcmd("dbput",'P',sdb,txn,key,data,flags));
}

int32_t dbdel(struct SuperNET_db *sdb,DB_TXN *txn,DBT *key,DBT *data,int32_t flags)
{
    return(dbcmd("dbdel",'D',sdb,txn,key,data,flags));
}

int32_t dbsync(struct SuperNET_db *sdb,int32_t flags)
{
    return(dbcmd("dbsync",'S',sdb,0,0,0,flags));
}

// < 0 if a < b, = 0 if a = b, > 0 if a > b
int db_incrdouble(DB *dbp,const DBT *a,const DBT *b,size_t *locp)
{
    int ai, bi;
    locp = NULL;
    memcpy(&ai,a->data,sizeof(double));
    memcpy(&bi,b->data,sizeof(double));
    if ( ai < (bi - SMALLVAL) ) return(-1);
    else if ( ai > (bi + SMALLVAL) ) return(1);
    else return(0);
}

int db_decrdouble(DB *dbp,const DBT *a,const DBT *b,size_t *locp)
{
    int ai, bi;
    locp = NULL;
    memcpy(&ai,a->data,sizeof(double));
    memcpy(&bi,b->data,sizeof(double));
    if ( ai < (bi - SMALLVAL) ) return(1);
    else if ( ai > (bi + SMALLVAL) ) return(-1);
    else return(0);
}

int32_t close_SuperNET_db(struct SuperNET_db *sdb,int32_t selector)
{
    if ( sdb->dbp == 0 )
        return(-1);
    if ( sdb->active > 0 )
    {
        sdb->active = 0;
        while ( sdb->active == 0 )
        {
            fprintf(stderr,".");
            usleep(100000);
            fprintf(stderr," %s selector.%d shutdown\n",sdb->name,selector);
            sdb->active = -1;
        }
    }
    return(0);
}

void close_SuperNET_dbs()
{
    int32_t i,selector;
    for (selector=0; selector<NUM_SUPERNET_DBS; selector++)
        close_SuperNET_db(&SuperNET_dbs[selector],selector);
    if ( Num_pricedbs != 0 && Price_dbs != 0 )
    {
        for (i=0; i<Num_pricedbs; i++)
        {
            if ( close_SuperNET_db(&Price_dbs[i],i) == 0 )
                Price_dbs[i].dbp->close(Price_dbs[i].dbp,0);
        }
    }
    Num_pricedbs = 0;
    free(Price_dbs);
    Price_dbs = 0;
    memset(SuperNET_dbs,0,sizeof(SuperNET_dbs));
}

int32_t init_SuperNET_storage()
{
    static int didinit,selectors[NUM_SUPERNET_DBS];
    int ret,selector;
    struct coin_info *cp = get_coin_info("BTCD");
    struct SuperNET_db *sdb;
    if ( IS_LIBTEST == 0 )
        return(0);
    if ( didinit == 0 )
    {
        didinit = 1;
        if ( (ret = db_env_create(&Storage, 0)) != 0 )
        {
            fprintf(stderr,"Error creating environment handle: %s\n",db_strerror(ret));
            return(-1);
        }
        else if ( (ret= Storage->open(Storage,"storage",DB_CREATE|DB_INIT_LOG|DB_INIT_MPOOL|DB_INIT_TXN,0)) != 0 ) //DB_INIT_LOCK
        {
            fprintf(stderr,"error.%d opening storage\n",ret);
            return(-2);
        }
        else
        {
            open_database(PUBLIC_DATA,&SuperNET_dbs[PUBLIC_DATA],"public.db",DB_HASH,DB_CREATE | DB_AUTO_COMMIT,sizeof(struct storage_header),4096,0);
            open_database(PRIVATE_DATA,&SuperNET_dbs[PRIVATE_DATA],"private.db",DB_HASH,DB_CREATE | DB_AUTO_COMMIT,sizeof(struct storage_header),4096,0);
            open_database(TELEPOD_DATA,&SuperNET_dbs[TELEPOD_DATA],"telepods.db",DB_HASH,DB_CREATE | DB_AUTO_COMMIT,sizeof(struct storage_header),4096,0);
            open_database(DEADDROP_DATA,&SuperNET_dbs[DEADDROP_DATA],"deaddrops.db",DB_HASH,DB_CREATE | DB_AUTO_COMMIT,sizeof(struct storage_header),4096,0);
            open_database(CONTACT_DATA,&SuperNET_dbs[CONTACT_DATA],"contacts.db",DB_HASH,DB_CREATE | DB_AUTO_COMMIT,sizeof(struct contact_info),sizeof(struct contact_info),0);
            open_database(NODESTATS_DATA,&SuperNET_dbs[NODESTATS_DATA],"nodestats.db",DB_HASH,DB_CREATE | DB_AUTO_COMMIT,sizeof(struct nodestats),sizeof(struct nodestats),0);
            open_database(INSTANTDEX_DATA,&SuperNET_dbs[INSTANTDEX_DATA],"InstantDEX.db",DB_HASH,DB_CREATE | DB_AUTO_COMMIT,sizeof(struct InstantDEX_quote),sizeof(struct InstantDEX_quote),1);
            open_database(PRICE_DATA,&SuperNET_dbs[PRICE_DATA],"prices.db",DB_HASH,DB_CREATE | DB_AUTO_COMMIT,sizeof(struct exchange_pair),sizeof(struct exchange_pair),0);
            if ( cp != 0 ) // encrypted dbs
            {
                sdb = &SuperNET_dbs[TELEPOD_DATA];
                sdb->privkeys = validate_ciphers(&sdb->cipherids,cp,cp->ciphersobj);
                sdb = &SuperNET_dbs[CONTACT_DATA];
                sdb->privkeys = validate_ciphers(&sdb->cipherids,cp,cp->ciphersobj);
            }
            //poll_pricedbs();
            for (selector=0; selector<NUM_SUPERNET_DBS; selector++)
            {
                selectors[selector] = selector;
                if ( portable_thread_create((void *)_process_SuperNET_dbqueue,&selectors[selector]) == 0 )
                    printf("ERROR hist process_hashtablequeues\n");
                break;
            }
        }
    }
    return(0);
}

struct storage_header *find_storage(int32_t selector,char *keystr,uint32_t bulksize)
{
    void *ptr = 0;
    DBT key,data,*retdata;
    int32_t ret,reqflags = 0;
    struct storage_header *hp;
    if ( valid_SuperNET_db("find_storage",selector) == 0 )
        return(0);
    //fprintf(stderr,"in find_storage.%d %s\n",selector,keystr);
    clear_pair(&key,&data);
    key.data = (keystr);
    key.size = (int32_t)strlen(keystr) + 1;
    if ( bulksize != 0 )
    {
        reqflags = DB_MULTIPLE;
        data.ulen = bulksize;
        data.flags = DB_DBT_USERMEM;
        data.data = ptr = valloc(data.ulen);
    }
    if ( (ret= dbget(&SuperNET_dbs[selector],NULL,&key,&data,reqflags)) != 0 || data.data == 0 || data.size < sizeof(*hp) )
    {
        if ( ret != DB_NOTFOUND )
            fprintf(stderr,"DB.%d get error.%d data.size %d\n",selector,ret,data.size);
        else
        {
            if ( ptr != 0 )
                free(ptr);
            //fprintf(stderr,"find_storage.%d %s not found\n",selector,keystr);
            return(0);
        }
    }
    //fprintf(stderr,"find_storage.%d %s found\n",selector,keystr);
    if ( bulksize != 0 )
    {
        retdata = calloc(1,sizeof(*retdata));
        *retdata = data;
        return((void *)retdata);
    }
    else return(decondition_storage(&data.size,&SuperNET_dbs[selector],data.data,data.size));
}

int32_t delete_storage(struct SuperNET_db *sdb,char *keystr)
{
    //if ( valid_SuperNET_db("delete_storage",selector) == 0 )
    //    return(-1);
    DBT key;
    int32_t ret;
    memset(&key,0,sizeof(key));
    key.data = keystr;
    key.size = (int32_t)strlen(keystr) + 1;
    fprintf(stderr,"delete_storage.%d\n",sdb->selector);
    if ( (ret= dbdel(sdb,0,&key,0,0)) != 0 )
        fprintf(stderr,"error deleting (%s) from DB.%d\n",keystr,sdb->selector);
    else return(dbsync(sdb,0));
    return(-1);
}

int32_t complete_dbput(struct SuperNET_db *sdb,char *keystr,void *databuf,int32_t datalen,int32_t bulksize)
{
    struct SuperNET_storage *sp;
    if ( (sp= (struct SuperNET_storage *)find_storage(sdb->selector,keystr,bulksize)) != 0 )
    {
        if ( memcmp(sp,databuf,datalen) != 0 )
            fprintf(stderr,"(%s) data.%s cmp error datalen.%d\n",keystr,sdb->name,datalen);
        //else fprintf(stderr,"DB.%d (%s) %d verified\n",selector,keystr,datalen);
        free(sp);
    } else { fprintf(stderr,"couldnt find sp in DB.%s that was just added.(%s)\n",sdb->name,keystr); return(-1); }
    return(dbsync(sdb,0));
}

void update_storage(struct SuperNET_db *sdb,char *keystr,struct storage_header *hp)
{
    DBT key,data;
    int ret;
    if ( hp->size == 0 )
    {
        printf("update_storage.%s zero datalen for (%s)\n",sdb->name,keystr);
        return;
    }
    //if ( valid_SuperNET_db("update_storage",selector) != 0 )
    {
        clear_pair(&key,&data);
        key.data = (keystr);
        key.size = (uint32_t)strlen(keystr) + 1;
        if ( hp->createtime == 0 )
        {
            sdb->maxitems++;
            hp->createtime = (uint32_t)time(NULL);
        }
        data.data = condition_storage(&data.size,sdb,hp,hp->size);
        //fprintf(stderr,"updateDB.%d entry.(%s) datalen.%d -> %d | hp %p, data.data %p\n",selector,keystr,hp->size,data.size,hp,data.data);
        if ( (ret= dbput(sdb,0,&key,&data,0)) != 0 )
            Storage->err(Storage,ret,"Database put failed.");
        else if ( complete_dbput(sdb,keystr,hp,hp->size,0) == 0 && Debuglevel > 1 )
            fprintf(stderr,"updated.%s (%s) hp.%p data.data %p\n",sdb->name,keystr,hp,data.data);
        if ( data.data != hp && data.data != 0 )
            free(data.data);
    }
}

void add_pricedb(char *exchange,char *base,char *rel)
{
    char lexchange[512],lbase[512],lrel[512],dbname[MAX_JSON_FIELD];
    struct exchange_pair P;
    DBT key,data;
    int ret;
    strcpy(lexchange,exchange), tolowercase(lexchange);
    strcpy(lbase,base), tolowercase(lbase);
    strcpy(lrel,rel), tolowercase(lrel);
    sprintf(dbname,"%s.%s_%s",lexchange,lbase,lrel);
    clear_pair(&key,&data);
    memset(&P,0,sizeof(P));
    strcpy(P.exchange,lexchange);
    strcpy(P.base,lbase);
    strcpy(P.rel,lrel);
    key.data = dbname;
    key.size = (uint32_t)strlen(dbname) + 1;
    data.data = &P;
    data.size = sizeof(P);
    if ( (ret= dbput(&SuperNET_dbs[PRICE_DATA],0,&key,&data,0)) != 0 )
        Storage->err(Storage,ret,"Database put failed.");
    else if ( complete_dbput(&SuperNET_dbs[PRICE_DATA],dbname,&P,sizeof(P),0) == 0 && Debuglevel > 1 )
        fprintf(stderr,"updated.(%s)\n",dbname);
}

void add_storage(int32_t selector,char *keystr,char *datastr)
{
    int32_t datalen,slen,createdflag = 0;
    unsigned char databuf[8192],space[8192];
    uint64_t hashval = 0;
    struct SuperNET_db *sdb;
    struct SuperNET_storage *sp;
    if ( valid_SuperNET_db("add_storage",selector) == 0 )
        return;
    if ( selector == PUBLIC_DATA && Total_stored > MAX_KADEMLIA_STORAGE )
    {
        printf("Total_stored %s > %s\n",_mbstr(Total_stored),_mbstr2(MAX_KADEMLIA_STORAGE));
        return;
    }
    datalen = (int32_t)strlen(datastr) / 2;
    if ( datalen > sizeof(databuf) )
        return;
    decode_hex(databuf,datalen,datastr);
    sdb = &SuperNET_dbs[selector];
    //fprintf(stderr,"add_storage.%d\n",selector);
    if ( (sp= (struct SuperNET_storage *)find_storage(sdb->selector,keystr,0)) == 0 || (sp->H.size-sizeof(*sp)) != datalen || memcmp(sp->data,databuf,datalen) != 0 )
    {
        slen = (int32_t)strlen(keystr);
        if ( sp == 0 )
        {
            SuperNET_dbs[selector].maxitems++;
            if ( selector == PUBLIC_DATA )
                Total_stored += (sizeof(*sp) + datalen);
            createdflag = 1;
            if ( is_decimalstr(keystr) && slen < MAX_NXTADDR_LEN )
                hashval = calc_nxt64bits(keystr);
            else hashval = calc_txid((uint8_t *)keystr,slen);
        }
        else
        {
            hashval = sp->H.keyhash;
            memcpy(space,sp,sizeof(*sp));
            free(sp);
        }
        sp = (struct SuperNET_storage *)space;
        if ( createdflag != 0 )
            sp->H.keyhash = hashval;
        else if ( sp->H.keyhash != hashval )
            fprintf(stderr,"ERROR: keyhash.%llu != hashval.%llu (%s)\n",(long long)sp->H.keyhash,(long long)hashval,keystr);
        memcpy(sp->data,databuf,datalen);
        sp->H.size = (sizeof(*sp) + datalen);
        update_storage(sdb,keystr,&sp->H);
    } else fprintf(stderr,"(%s) <- (%s) already there\n",keystr,datastr);
}

#endif
