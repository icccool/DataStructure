#ifndef _STATICLIST_H_
#define _STATICLIST_H_

typedef void StaticList;
typedef void StaticListNode;


StaticList* StaticList_Create(int catacity);

int StaticList_Insert(StaticList* list,StaticList* node,int pos);

StaticListNode* StaticList_Get(StaticList* list,int pos);

StaticListNode* StaticList_Delete(StaticList* list,int pos);

void disdroy(StaticList* list);

void clear(StaticList* list);

int StaticList_Szie(StaticList* list);

int StaticList_Catacity(StaticList* list);

#endif
