#include <string>

class Patron
{
public:
    Patron(std::string username, int numOfLibCard, int membershipFeeAmount);
    std::string GetUsername() const;
    int GetNumOfLibCard() const;
    int GetMembershipFeeAmount() const;
    void SetMembershipFeeAmount(int newAmount);
    bool HasUserPaid() const;
    
private:
    std::string username;
    int numOfLibCard;
    int membershipFeeAmount;
};
