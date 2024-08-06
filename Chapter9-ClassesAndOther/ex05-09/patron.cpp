#include "patron.h"

Patron::Patron(std::string username, int numOfLibCard, int membershipFeeAmount)
:username{username}, numOfLibCard{numOfLibCard}, membershipFeeAmount{membershipFeeAmount} {}

std::string Patron::GetUsername() const { return username; }
int Patron::GetNumOfLibCard() const { return numOfLibCard; }
int Patron::GetMembershipFeeAmount() const { return membershipFeeAmount; }
void Patron::SetMembershipFeeAmount(int newAmount) { membershipFeeAmount = newAmount; }
bool Patron::HasUserPaid() const
{
    if (membershipFeeAmount > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
