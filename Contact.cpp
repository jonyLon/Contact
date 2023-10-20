#include <iostream>
using namespace std;

class Contact {
private:
    char* fullName = nullptr;
    char* homePhone = nullptr;
    char* workPhone = nullptr;
    char* mobilePhone = nullptr;
    char* additionalInfo = nullptr;

    inline bool isValidName(const char* name) const
    {
        return name != nullptr && name[0] != '\0' && name[0] != ' ';
    }
    void strCopy(char*& dest, const char* other) {
        if (!isValidName(other)) return;
        if (dest != nullptr) {
            delete[] dest;
        }
        dest = new char[strlen(other) + 1];
        strcpy_s(dest, strlen(other) + 1, other);
    }
public:
    Contact() {
        strCopy(this->fullName, "no name");
        strCopy(this->homePhone, "no home phone");
        strCopy(this->workPhone, "no work phone");
        strCopy(this->mobilePhone, "no mobile phone");
        strCopy(this->additionalInfo, "no additional info");
    }
    Contact(const char* name, const char* mobilePhone) {
        strCopy(this->fullName, name);
        strCopy(this->homePhone, "no home phone");
        strCopy(this->workPhone, "no work phone");
        strCopy(this->mobilePhone, mobilePhone);
        strCopy(this->additionalInfo, "no additional info");
    }
    Contact(const char* name, const char* mobilePhone, const char* workPhone) {
        strCopy(this->fullName, name);
        strCopy(this->homePhone, "no home phone");
        strCopy(this->workPhone, workPhone);
        strCopy(this->mobilePhone, mobilePhone);
        strCopy(this->additionalInfo, "no additional info");
    }
    Contact(const char* name, const char* mobilePhone, const char* workPhone, const char* homePhone) {
        strCopy(this->fullName, name);
        strCopy(this->homePhone, homePhone);
        strCopy(this->workPhone, workPhone);
        strCopy(this->mobilePhone, mobilePhone);
        strCopy(this->additionalInfo, "no additional info");
    }
    Contact(const char* name, const char* mobilePhone, const char* workPhone, const char* homePhone, const char* info) {
        strCopy(this->fullName, name);
        strCopy(this->homePhone, homePhone);
        strCopy(this->workPhone, workPhone);
        strCopy(this->mobilePhone, mobilePhone);
        strCopy(this->additionalInfo, info);
    }
    ~Contact() {
        if (this->fullName != nullptr) {
            delete[] this->fullName;
        }
        if (this->homePhone != nullptr) {
            delete[] this->homePhone;
        }
        if (this->workPhone != nullptr) {
            delete[] this->workPhone;
        }
        if (this->mobilePhone != nullptr) {
            delete[] this->mobilePhone;
        }
        if (this->additionalInfo != nullptr) {
            delete[] this->additionalInfo;
        }
    }

    inline const char* getFullName() const {
        return this->fullName;
    }
    inline const char* getHomePhone() const {
        return this->homePhone;
    }
    inline const char* getWorkPhone() const {
        return this->workPhone;
    }
    inline const char* getMobilePhone () const {
        return this->mobilePhone;
    }
    inline const char* getAdditionalInfo() const {
        return this->additionalInfo;
    }
    inline void setFullName(const char* name) {
        strCopy(this->fullName, name);
    }
    inline void setHomePhone(const char* phone) {
        strCopy(this->homePhone, phone);
    }
    inline void setWorkPhone(const char* phone) {
        strCopy(this->workPhone, phone);
    }
    inline void setMobilePhone(const char* phone) {
        strCopy(this->mobilePhone, phone);
    }
    inline void setAdditionalInfo(const char* info) {
        strCopy(this->additionalInfo, info);
    }
    void print() {
        cout << "================ Contact ================" << endl;
        cout << "Full name: " << getFullName() << endl;
        cout << "Home phone: " << getHomePhone() << endl;
        cout << "Work phone: " << getWorkPhone() << endl;
        cout << "Mobile phone: " << getMobilePhone() << endl;
        cout << "Additional info: " << getAdditionalInfo() << endl;
    }
};




int main()
{
    Contact Jo = Contact("Jony Parker", "+1 548 268 5998");
    Jo.print();
    Contact Nick = Contact("Nick Parker", "+1 548 268 5923", "+1 212 555 1234");
    Nick.print();
    Contact Pit = Contact("Pit Jefferson", "+1 548 248 4523", "+1 212 785 1244", "+1 703 555 4567");
    Pit.print();
    Contact Robert = Contact("Robert Jefferson", "+1 548 248 4523", "+1 212 785 1244", "+1 703 555 4567", "manager");
    Robert.print();
}


