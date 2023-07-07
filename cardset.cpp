#include "cardset.h"
#include <QDebug>

CardSet::CardSet(QObject *parent)
    : QObject{parent}
{
}

void CardSet::AddNewCard(Card* newCard)
{
    cardSet.append(newCard);
}

QVector<Card*> CardSet::GetSentenceCollectedCards()
{
    QVector<Card*> ret;
    QVector<Card*>::Iterator itr;
    for(itr = cardSet.begin(); itr != cardSet.end(); itr++)
    {
        if((*itr)->IsSentenceCollected()) ret.append(*itr);
    }
    return ret;
}
QVector<Card*> CardSet::GetNoteCollectedCards()
{
    QVector<Card*> ret;
    QVector<Card*>::Iterator itr;
    for(itr = cardSet.begin(); itr != cardSet.end(); itr++)
    {
        if((*itr)->IsNoteCollected()) ret.append(*itr);
    }
    return ret;
}
QVector<Card*> CardSet::GetMasterdCards()
{
    QVector<Card*> ret;
    QVector<Card*>::Iterator itr;
    for(itr = cardSet.begin(); itr != cardSet.end(); itr++)
    {
        if((*itr)->IsMasterdCard()) ret.append(*itr);
    }
    return ret;
}
QVector<Card*> CardSet::GetUnmasterdCards()
{
    QVector<Card*> ret;
    QVector<Card*>::Iterator itr;
    for(itr = cardSet.begin(); itr != cardSet.end(); itr++)
    {
        if(! (*itr)->IsMasterdCard()) ret.append(*itr);
    }
    return ret;
}
QVector<Card*> CardSet::GetAllCards()
{
    QVector<Card*> ret;
    QVector<Card*>::Iterator itr;
    for(itr = cardSet.begin(); itr != cardSet.end(); itr++)
        ret.append(*itr);
    return ret;
}
